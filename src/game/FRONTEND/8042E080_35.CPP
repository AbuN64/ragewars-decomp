#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_35.H"

/* Reorders the four 400-byte player records D_80102B00 by the players' choices: copies all four to
   the buffer at 0x2E28 of the block D_800E54A4 points to and resets each through func_8022EF30_de,
   copies back the record each player chose (index at 0xB28 of its 2920-byte record at 0x58) into
   that player's place, and then places every unchosen buffered record whose owner byte 0xD is not
   negative into the first place whose owner byte is still negative, all through Resmgr_CopyBytes. */







extern struct Record_func_804347CC_de D_80102B00[];
extern void func_8022EF30_de(struct Record_func_804347CC_de *);

void func_804347CC_de(void) {
    s32 used[4];
    s32 size;
    s32 chosen;
    s32 i;
    s32 j;

    size = 400;
    Resmgr_CopyBytes(D_800E54A4->packet.saved, D_80102B00, 0x640);
    for (i = 0; i < 4; i++) {
        func_8022EF30_de(&D_80102B00[i]);
        used[i] = 0;
    }
    for (i = 0; i < 4; i++) {
        chosen = D_800E54A4->players[i].port;
        if (chosen >= 0) {
            Resmgr_CopyBytes(&D_80102B00[i], &D_800E54A4->packet.saved[chosen], size);
            used[chosen] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        if (used[i] != 0 || D_800E54A4->packet.saved[i].player < 0) {
            continue;
        }
        for (j = 0; j < 4; j++) {
            if (D_80102B00[j].owner < 0) {
                Resmgr_CopyBytes(&D_80102B00[j], &D_800E54A4->packet.saved[i], size);
                break;
            }
        }
    }
}
