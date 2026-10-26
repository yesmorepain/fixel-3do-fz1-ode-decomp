/* Small button library: debounce + press / click / double-click / long-press events. */
#pragma once
#include <stdint.h>

#define BTN_EV_PRESS        0x01
#define BTN_EV_RELEASE      0x02    /* release, when no click/long timing is configured */
#define BTN_EV_DOUBLE       0x04    /* second press within dbl_ms */
#define BTN_EV_CLICK        0x08    /* release before click_ms (or any release if click_ms == 0) */
#define BTN_EV_LONG_RELEASE 0x10    /* release after click_ms */
#define BTN_EV_LONG         0x20    /* held for long_ms */
#define BTN_EV_DOUBLE_TMO   0x40    /* no second press within dbl_ms */

struct button {
    void   (*read)(struct button *b);   /* +0x00 must store the pin level in ->state */
    uint32_t history;                   /* +0x04 one bit per sample */
    uint32_t state;                     /* +0x08 debounced */
    uint32_t prev;                      /* +0x0c */
    uint32_t t_change;                  /* +0x10 g_ticks at the last change */
    uint32_t fsm;                       /* +0x14 */
    uint32_t click_ms;                  /* +0x18 */
    uint32_t long_ms;                   /* +0x1c */
    uint32_t dbl_ms;                    /* +0x20 */
    uint32_t debounce_bits;             /* +0x24 */
    uint32_t enabled;                   /* +0x28 */
    uint32_t _2c;
};
