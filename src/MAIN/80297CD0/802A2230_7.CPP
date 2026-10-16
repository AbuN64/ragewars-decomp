#include "span_1000/code_802A208C.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80297CD0.h"
#include "span_1000/code_802A1264.h"
#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_804143D8.h"
#include "TYPES.H"
#include "common/unused.h"

/** Set D_800D2C90 to one. */


s32 func_80299958_de();





extern void func_8029AA34_de(s32 *arg0);


/** Return the global word at D_800D2C98. */



extern float D_800CDA30_de;



void func_802A230C_de(void) {
    extern int D_800D2C90;
    D_800D2C90 = 1;
}

void func_802A2320_de(void) {
    if (D_800E28D8 == 1) {
        func_802A2480_de(func_80411DCC_de(func_80299958_de()), 0);
    }
}

void func_802A2360_de(void) {
    s32 *p;

    p = &D_800CDA24;
    if (*p != 1) {
        *p = 1;
        func_8029AA34_de(p);
    }
}

void func_802A2394_de(void) {
    D_800CDA24 = 0;
}

int func_802A23A4_de(void) {
    return D_800CDA24;
}

int func_802A23B4_de(void) {
    return D_800D2C98;
}

void func_802A23C4_de(s32 arg0) {
    if (arg0 == 1) {
        D_800CDA2C = arg0;
        return;
    }
    D_800CDA2C = 0;
}

int func_802A23F0_de(void) {
    return D_800CDA2C;
}

/** Store a scalar and clear its associated global state word. */
void func_802A2400_de(float value) {
    D_800CDA30_de = value;
    D_801427B0 = 0;
}

/** Store the active value and reset its timer to sixty. */
void func_802A2418_de(int arg0) {
    D_800CDA34_de = arg0;
    D_800CBC14 = 60;
}

void func_802A2434_de(void) {
    extern struct Triple D_800D2C90;
    s32 *selected;
    func_80299468_de();
    func_804101BC_de();
    func_802A176C_de();
    func_80414384_de();
    selected = &D_800D2C90.z;
    *selected = 0;
    func_802A2394_de();
    D_800D2C90.x = 0;
}
