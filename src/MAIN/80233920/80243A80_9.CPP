#include "span_1000/code_80243A80.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/func_804235A8_eu_layout.h"
#include "span_1000/code_80245980.h"
#include "TYPES.H"

/* Calls func_80401980_de when the globally selected record's word at 0x38 is non-zero. */


extern void func_80401980_de(void);

/* Calls func_80402BA0_de when the globally selected record's word at 0x38 is non-zero. */


extern void func_80402BA0_de(void);

/** Clear the global word at VRAM 0x800E2838. */


/* Reports whether func_80245798_de accepts the globally selected record and bit 2 of its word at 0x74
   is set. */
extern int func_80245798_de(void);

/* Returns the globally selected record's word at 0xAC while its word at 0x38 is non-zero, and 0
   otherwise. */


/* Returns the globally selected record's word at 0xA8 while its word at 0x38 is non-zero, and 0
   otherwise. */


extern f32 func_8040184C_de(f32 arg0);

/** Clear the word at offset 0x100 in the active object. */


extern s32 D_800E28D0;

extern int D_800E28D4;

extern void func_802A025C_de(void *arg0, int arg1);

/* Returns the globally selected record's float at 0xA0 scaled by D_800C88CC. */


/* Returns the state object's word at its measured value field. */




extern void func_80253838_de(void *arg0, void *arg1);

s32 func_80245814_de(void) {
    s32 var_v0;
    var_v0 = 0;
    if (func_80245784_de() == 0) {
        var_v0 = func_8024576C_de() == 0;
    }
    return var_v0;
}

/** Return the word at offset 0x3C of the current global object. */
unsigned int func_80245850_de(void) {
    extern func_802428C0_S1 *D_800E2830;
    return D_800E2830->unk3C;
}

void func_80245864_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    if (record->active != 0) {
        func_80401980_de();
    }
}

void func_80245894_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    if (record->active != 0) {
        func_80402BA0_de();
    }
}

/** Set the global word at VRAM 0x800E2838 to one. */
void func_802458C4_de(void) {
    extern int D_800DE7E8;
    D_800DE7E8 = 1;
}

void func_802458D8_de(void) {
    extern int D_800DE7E8;
    D_800DE7E8 = 0;
}

/** Return the current global object word. */
unsigned int func_802458E8_de(void) {
    extern unsigned int D_800DE7E8;
    return D_800DE7E8;
}

void func_802458F8_de(void) {
    extern func_8023EBEC_S1 *D_800E2830;
    D_800E2830->unk3C = 0;
}

int func_80245908_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record;
    if (func_80245798_de() == 0) {
        return 0;
    }
    record = D_800E2830;
    if ((record->spec.flags & 2) != 0) {
        return 1;
    }
    return 0;
}

int func_80245940_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    int cond = record->active != 0;
    if (cond) {
        if (record) {
            return record->spec.settings[1];
        } else {
            return record->spec.settings[1];
        }
    }
    return 0;
}

int func_80245968_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    int cond = record->active != 0;
    if (cond) {
        if (record) {
            return record->spec.settings[0];
        } else {
            return record->spec.settings[0];
        }
    }
    return 0;
}

void func_80245990_de(void *arg0) {
    D_800DE7F4_de = arg0;
}

f32 func_802459A0_de(void) {
    extern void *D_800E2830;
    void *record = D_800E2830;
    f32 temp_f1;

    if (((Shared_MenuContext *)record)->active == 0) {
        return D_800C37D4_de;
    }
    temp_f1 = ((Shared_MenuContext *)record)->response;
    if (!(D_800C37D8_de < temp_f1)) {
        return func_8040184C_de(((Shared_MenuContext *)record)->time);
    }
    return temp_f1;
}

void func_80245A00_de(float arg0) {
    extern func_802459F0_S1 *D_800E2830;
    D_800E2830->unk100 = arg0;
}

void func_80245A10_de(void) {
    extern char *D_800E2830;
    struct Shared_Actor *base = D_800E2830;
    base->weaponFlags = 0;
}

void func_80245A20_de(int arg0) {
    extern func_80245A10_S1 *D_800E2830;
    D_800E2830->unk104 = arg0;
}

/** Copy a two-word record into the global record and clear two trailing fields. */
void func_80245A30_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    int hi = D_800E28D4;
    int lo = D_800E28D0;
    record->unknown104[2] = hi;
    record->unknown104[1] = lo;
    record->unknown104[3] = 0;
    record->unknown104[4] = 0;
}

/** Store four incoming words into the global record's tail fields. */
void func_80245A5C_de(int arg0, int arg1, int arg2, int arg3) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    record->unknown104[2] = arg1;
    record->unknown104[1] = arg0;
    record->unknown104[3] = arg2;
    record->unknown104[4] = arg3;
}

void func_80245A78_de(int arg0) {
    extern void *D_800E2830;
    void *record = D_800E2830;
    int idx = ((Shared_MenuContext *)record)->messageCount;
    func_802A025C_de((char *)record + ((idx * 0x28) + 0x118), arg0);
    record = D_800E2830;
    ((Shared_MenuContext *)record)->messageCount = ((Shared_MenuContext *)record)->messageCount + 1;
}

void func_80245AC8_de(void) {
    extern func_80245A68_S1 *D_800E2830;
    D_800E2830->unk1E0 = 0;
}

float func_80245AD8_de(void) {
    extern void *D_800E2830;
    Shared_MenuContext *record = D_800E2830;
    return (record->spec.scaleA0) * (D_800C88CC);
}

/** Return the word at offset 0xB0 of the current global object. */
unsigned int func_80245AF8_de(void) {
    extern func_80245AE8_S1 *D_800E2830;
    return D_800E2830->unkB0;
}

s32 func_80245B0C_de(void) {
    extern struct MenuPanelRoot *D_800E2830;
    return D_800E2830->window;
}

/* Returns the word at offset 0xE0 of the object D_800E2830 points to. The interval also holds an
   empty function with no symbol of its own, compiled here as the file-local stub after it. */
struct UnresolvedRec;

static void func_80245B20_de(void) {
}

void func_80245B28_de(void) {
    extern void *D_800E2830;
    int temp_a1 = (s32)((Shared_MenuContext *)D_800E2830)->owner;
    Shared_MenuContext *record;
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
