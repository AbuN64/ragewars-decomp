#include "span_16E000/code_80434F4C.h"
/* Handles a packed message for a player in D_800E54A4: when the player (low half) is in state 12, the
   message type (high half) is 3 and the argument is 4 or 5, moves the player to phase 2 with a zero
   timer; always returns 0. */


extern char *D_800E54A4;

int func_80435A10_de(int unused0, int unused1, unsigned int message, int arg) {
    PlayerRecAtBA4 *p = (PlayerRecAtBA4 *)(D_800E54A4 + (message & 0xFFFF) * 0xB68);

    if (p->state == 12 && (message >> 16) == 3 && arg < 6 && arg >= 4) {
        p->timer = 0;
        p->phase = 2;
    }
    return 0;
}
