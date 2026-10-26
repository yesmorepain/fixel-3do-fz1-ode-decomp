/*
 * Example extension for piode2 v0.1 (3DO FZ-1 internal ODE):
 * adds a new 3DO CD command 0xD2 that replies with "OK" + the first argument byte.
 *
 * Handler contract (recovered from cd_cmd_dispatch @0x10016854):
 *   - called with no arguments from the dispatcher (via a trampoline odepatch.py adds)
 *   - command bytes are in cd_state.cmd[0..6]          (cmd[0] == opcode)
 *   - append reply bytes with reply[reply_len++]; reply[0] already holds the opcode echo
 *   - on return the common tail appends the status byte and sends the reply over SPI1
 *   - set status |= 0x10 (CHECK_ERROR) and error = <code> to report a failure
 *   - total reply is capped at 64 bytes by cd_send_reply
 *
 * Constraints for patch code: no initialised .data and no .bss (crt0 only copies the
 * original .data). Use stack variables, or call firmware functions (see piode2_symbols.ld).
 */
#include <stdint.h>

typedef struct {
    uint8_t status;
    uint8_t error;
    uint8_t reply_len;
    uint8_t _pad3[9];
    uint8_t cmd[7];
    uint8_t reply[64];
} cd_state_t;

#define CD ((volatile cd_state_t *)0x200050cc)

int printf(const char *fmt, ...);          /* resolved to 0x... via piode2_symbols.ld */

__attribute__((section(".entry"), used))
void cmd_d2_ping(void)
{
    CD->reply[CD->reply_len++] = 'O';
    CD->reply[CD->reply_len++] = 'K';
    CD->reply[CD->reply_len++] = CD->cmd[1];
    printf("ping %02x\n", CD->cmd[1]);
}
