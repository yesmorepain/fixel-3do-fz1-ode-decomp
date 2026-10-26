/*
 * Button library: up to 5 registered (button, callback, event mask) entries, sampled
 * every 10 ms (buttons_tick from the timer, buttons_process from the main loop).
 */
#include <stdlib.h>
#include <string.h>
#include "piode2.h"

typedef struct {
    uint32_t events;
    button_cb_t cb;
    button_t b;
} btn_entry_t;                          /* 0x38 */

static btn_entry_t g_btn[5];
static uint32_t g_btn_n;
static volatile uint32_t g_btn_sample;

void buttons_init(void)
{
    g_ticks = 0;
    g_btn_n = 0;
    g_btn_sample = 0;
    memset(g_btn, 0, sizeof(g_btn));
}

#define DT(e) ((uint32_t)abs((int)(g_ticks - (e)->b.t_change)))
#define FIRE(e, ev) do { if ((e)->events & (ev)) (e)->cb(&(e)->b); } while (0)

void buttons_process(void)
{
    uint32_t sample = g_btn_sample;
    if (sample) {
        g_btn_sample = 0;
        sample = 1;
    }
    for (uint32_t i = 0; i < g_btn_n; i++) {
        btn_entry_t *e = &g_btn[i];
        if (sample && e->b.read) {
            uint32_t st = e->b.state;
            e->b.history <<= 1;
            e->b.read(&e->b);
            uint32_t h = e->b.history | (e->b.state ? sample : 0);
            e->b.history = h;
            e->b.state = st;
            uint32_t mask = (1u << (e->b.debounce_bits & 0xff)) - 1;
            if ((h & mask) == mask)
                e->b.state = 1;
            else if ((h & mask) == 0)
                e->b.state = 0;
        }
        if (e->b.prev != e->b.state) {
            switch (e->b.fsm) {
            case 0:
                if (e->b.state) {
                    e->b.fsm = 1;
                    FIRE(e, BTN_EV_PRESS);
                }
                break;
            case 1:
                if (!e->b.state) {
                    if (e->b.click_ms == 0 && e->b.long_ms == 0) {
                        FIRE(e, BTN_EV_RELEASE);
                    } else if (DT(e) < e->b.click_ms || e->b.click_ms == 0) {
                        FIRE(e, BTN_EV_CLICK);
                    } else {
                        FIRE(e, BTN_EV_LONG_RELEASE);
                    }
                    e->b.fsm = 0;
                }
                break;
            case 2:
                if (!e->b.state) {
                    FIRE(e, BTN_EV_RELEASE);
                    e->b.fsm = 0;
                }
                break;
            case 3:
                if (e->b.state == 1)
                    e->b.fsm = 4;
                break;
            case 4:
                if (e->b.state == 0)
                    e->b.fsm = 5;
                break;
            case 5:
                if (e->b.state == 1) {
                    if (DT(e) < e->b.dbl_ms)
                        FIRE(e, BTN_EV_DOUBLE);
                    e->b.fsm = 6;
                }
                break;
            case 6:
                if (e->b.state == 0)
                    e->b.fsm = 3;
                break;
            }
            e->b.prev = e->b.state;
            e->b.t_change = g_ticks;
        }
        if (e->b.fsm == 1) {
            if (e->b.state && DT(e) >= e->b.long_ms && e->b.long_ms) {
                FIRE(e, BTN_EV_LONG);
                e->b.fsm = 2;
            }
        } else if (e->b.fsm == 5 && e->b.state == 0 && DT(e) >= e->b.dbl_ms) {
            e->b.fsm = 3;
            FIRE(e, BTN_EV_DOUBLE_TMO);
            e->b.fsm = 3;
        }
    }
}

void buttons_tick(void)
{
    g_btn_sample = 1;
}

int button_register(button_t *desc, button_cb_t cb, uint32_t events)
{
    uint32_t n = g_btn_n;
    if (n >= 5 || !desc || !events || !cb)
        return 0;
    if (!desc->debounce_bits)
        return 0;
    btn_entry_t *e = &g_btn[n];
    e->cb = cb;
    e->events = events;
    e->b = *desc;
    e->b.fsm = 0;
    if (events & BTN_EV_DOUBLE) {
        e->b.fsm = 3;
        if (!desc->dbl_ms)
            return 0;
    }
    if ((events & (BTN_EV_LONG | BTN_EV_LONG_RELEASE)) && !desc->long_ms)
        return 0;
    if ((events & BTN_EV_LONG_RELEASE) && !desc->click_ms)
        return 0;
    if ((events & BTN_EV_CLICK) && !desc->click_ms && !desc->long_ms)
        return 0;
    g_btn_n = n + 1;
    return 1;
}
