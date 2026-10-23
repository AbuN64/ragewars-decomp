#include "include_asm.h"
#include "COMMON/GROUP.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "TYPES.H"
#include "CAMERA/80243A80_11.H"
#include "CAMERA/80243A80_6.H"

extern int func_80245784_de(void);

extern u32 func_80245850_de(void);

extern f32 D_800D2988;

/** Read the word at offset 0x38 from the globally selected record. */


void func_80245C38_de(void) {
    f32 value;
    f32 limit;
    Shared_MenuContext *record;

    if (func_80245784_de() != 0) {
        if (func_80245850_de() != 0) {
            D_800E2830->time20 = D_800E2830->time;
            return;
        }
        record = D_800E2830;
        record->time20 = *(volatile f32 *)&record->time;
        record->time += D_800D2988 * D_800C37E0_de;
        if (record->start <= record->time) {
            func_80244E58_de();
        }
        value = D_800E2830->time;
        limit = D_800E2830->clipEnd;
        if (limit <= value) {
            if (D_800E2830->unknown104[0] == 1) {
                D_800E2830->time = value - limit;
                return;
            }
            D_800E2830->time = limit;
            if (D_800E2830->fieldB4 != 0) {
                D_800E2830->state3C = 1;
                D_800E2830->fieldB4 = 0;
            }
        }
    }
}

int func_80245D14_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_80245D08[2] = {
    0x00940A00, 0x08001800,
};
#endif
