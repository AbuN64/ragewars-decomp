#include "COMMON/GROUP.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "TYPES.H"

extern int func_80245784_de(void);

extern void func_80245BC0_de(void);

extern void func_80253838_de(void *arg0, void *arg1);

extern f32 D_800C37D0_de;

/** Read the word at offset 0x38 from the globally selected record. */


/* Reports whether the globally selected record is active (its word at 0x38 is non-zero) and its
   value at 0x1C lies between the bounds at 0x30 and 0x34. */


void func_802456A0_de(void) {
    if (func_80245784_de() != 0) {
        s32 temp_a1;
        Shared_MenuContext *record;

        func_80245B74_de(1);
        func_80245BC0_de();
        temp_a1 = (s32)D_800E2830->owner;
        if (temp_a1 != 0) {
            func_80253838_de(0, temp_a1);
        }
        record = D_800E2830;
        record->owner = 0;
        record->resource = 0;
        record->active = 0;
        record->state3C = 0;
        record->unknown60 = 0;
    }
}

void func_8024570C_de(void) {
    if (func_80245784_de() != 0 && func_80245764_de() != 0 && D_800E2830->unknown60 == 0) {
        f32 temp = D_800C37D0_de;
        D_800E2830->unknown60 = 1;
        D_800E2830->fade = temp;
    }
}

/** Return the constant success result used by callers at VRAM 0x80245754. */
int func_80245764_de(void) {
    return 1;
}

int func_8024576C_de(void) {
    return D_800E2830->resourceDC != -1;
}

int func_80245784_de(void) {
    Shared_MenuContext *record = D_800E2830;
    return record->active;
}

int func_80245798_de(void) {
    Shared_MenuContext *record = D_800E2830;
    float temp_f1;
    int var_a0 = 0;

    if (record->active != 0) {
        temp_f1 = record->time;
        if (record->start <= temp_f1 && temp_f1 <= record->end) {
            var_a0 = 1;
        }
    }
    return var_a0;
}

s32 func_802457E0_de(void) {
    if (D_800E2830->active != 0) {
        if (D_800E2830->time > D_800E2830->end) {
            return 1;
        }
        return 0;
    }
    return 1;
}
