#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8042E080.h"
#include "types.h"

/* Returns 0xBC2 plus ten times either the halfword at offset 2 of what func_8028D474_de finds for
   D_8015402C in D_8011FE88, when the option byte D_801462D5 is one, or D_8015402C itself. */


extern u8 D_801462D5;
extern s32 D_8015402C;

extern struct StateFlags *func_8028D474_de(void *, s32);

s32 func_8042EE34_de(void) {
    return (D_801462D5 == 1 ? func_8028D474_de(&D_8011FE88, D_8015402C)->flags : D_8015402C) * 10 + 0xBC2;
}

extern struct Status D_80146398[];

extern s32 func_802744D4_de(void);

/* Draws a random item type from 0 to 10, redrawing types 0 and 5 while any of the eight active players already holds that type, and returns it. */
s32 func_8042EE94_de(void) {
    s32 type;
    s32 free;
    s32 i;
    s32 excl; /* FAKEMATCH: constant-holding local places the li of 5 */
    struct Status *players; /* FAKEMATCH: copy-only local, set inside the draw loop, steers the base register */

    do {
        type = func_802744D4_de() % 11;
        excl = 5;
        players = D_80146398;
        do {
            free = 1;
        } while (0);
        if (type == 0 || type == excl) {
            for (i = 0; i < 8; i++) {
                if (players[i].active != 0 && players[i].kind == type) {
                    free = 0;
                }
            }
        }
    } while (free == 0);
    return type;
}
