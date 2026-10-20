#include "RESMGR/resmgr_string_memory.H"
#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_58.H"

/* Counts how many of the four 2920-byte entries D_800E54A4 points to have a non-zero word at
   offset 0x58. */


extern struct PlayerRecAt58 *D_800E54A4;

s32 func_804355B4_de(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 4; i++) {
        if (D_800E54A4[i].state != 0) {
            count++;
        }
    }
    return count;
}

#ifdef NON_MATCHING
/* Copies four selected player records and marks absent selections; -fno-strength-reduce reproduces the reference pointer induction exactly. */
#include "TYPES.H"
typedef struct { char pad[12]; s8 unkC, unkD; char rest[0x182]; } Record;
extern Record D_80102B00[];
extern void *D_800E54A4;                          /* const */

void func_804355E8_de(void) {
    Record *var_s1;
    s32 temp_s0;
    s32 temp_v1;
    s32 var_s2;
    s32 var_s3;
    void *temp_v0;

    s32 absent;
    var_s3 = 0;
    absent = -1;
    var_s1 = D_80102B00;
    var_s2 = 0;
    do {
        temp_v0 = D_800E54A4 + var_s2;
        temp_v1 = (*(s32 *)(temp_v0+0x2DF8));
        temp_s0 = (*(s32 *)(temp_v0+0x2DFC));
        if (temp_v1 != absent) {
            Resmgr_CopyBytes(var_s1, D_800E54A4 + ((temp_v1 * 0xB68) + 0x58) + ((temp_s0 * 0x190) + 0x18), 0x190);
            var_s1->unkC = (s8) temp_s0;
        } else {
            var_s1->unkD = (s8) temp_v1;
        }
        var_s1++;
        var_s3 += 1;
        var_s2 += 0xC;
    } while (var_s3 < 4);
}
#else
INCLUDE_ASM("ovl_80400000", func_804355E8_de);
#endif
