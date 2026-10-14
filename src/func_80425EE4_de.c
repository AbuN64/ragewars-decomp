#include "span_16E000/code_804251F4.h"
#include "types.h"

/* Awards player p flag 0x31: when the player's 150-byte record in D_80146398 has its byte at
   0x78 equal to one and its byte at 0x91 clear, and the flag set at 0x4A of the player's 400-byte
   record in D_80102B00 lacks bit 0x31 while the set at 0x124 has bits 0 to 3, it sets bit 0x31
   through func_80265688_de and stores 0x31 through the second argument. */

extern u8 D_80146398[];
extern u8 D_80102B00[];
extern s32 func_80265650_de(u8 *, s32);
extern void func_80265688_de(u8 *, s32, s32);

void func_80425EE4_de(s32 player, s32 *award) {
    u8 *record;
    s32 all;
    s32 i;

    record = &D_80146398[player * 150];
    all = 1;
    if (record[0x78] == 1 && record[0x91] == 0) {
        if (func_80265650_de(&D_80102B00[player * 400] + 0x4A, 0x31) == 0) {
            for (i = 0; i < 4; i++) {
                if (all != 1) {
                    return;
                }
                if (func_80265650_de(&D_80102B00[player * 400] + 0x124, i) == 0) {
                    all = 0;
                }
            }
            if (all == 1) {
                func_80265688_de(&D_80102B00[player * 400] + 0x4A, 0x31, 1);
                *award = 0x31;
            }
        }
    }
}
