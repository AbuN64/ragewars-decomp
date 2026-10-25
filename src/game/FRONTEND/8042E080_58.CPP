#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_58.H"

/* Counts how many of the four 2920-byte entries D_800E54A4 points to have a non-zero word at
   offset 0x58. */



s32 func_804355B4_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E54A4->players[i].state != 0) {
            count++;
        }
    }
    return count;
}

typedef struct { char pad[12]; s8 unkC, unkD; char rest[0x182]; } MatchProfile58;
extern MatchProfile58 D_80102B00[];
extern void *Resmgr_CopyBytes(void *destination, const void *source, s32 bytes);

void func_804355E8_de(void) {
    s32 i = 0; s32 none = -1;
    do {
        s32 player = D_800E54A4->links[i].player;
        s32 entry = D_800E54A4->links[i].entry;
        MatchProfile58 *dst = &D_80102B00[i];
        if (player != none) { Resmgr_CopyBytes(dst, D_800E54A4->players[player].slots[entry], 0x190); dst->unkC = entry; }
        else { dst->unkD = player; }
        i++;
    } while (i < 4);
}
