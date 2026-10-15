#include "span_1000/code_802B7488.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802BB15C.h"
#include "types.h"
#include "common/unused.h"
#include "span_1000/code_80291054.h"



extern s8 D_8014D46C;

extern void func_802B7A20_de(s32 arg0);

extern void func_802B7AD8_de(s32 *arg0, s32 arg1);



extern void func_802BB6C0_de(void *arg0, u64 arg1, u64 arg2, void *arg3, void *arg4);




s32 func_802B7560_de(s32 arg0) {
    extern char D_8014D470;
    s32 result;
    u8 *p;

    func_802B9C14_de();
    p = &D_8014D4B0;
    if (*p != 1) {
        func_802B768C_de();
        func_802B9CB0_de(1, &D_8014D470);
        func_802BB2A0_de(arg0, 0, 1);
    }
    result = func_802B9CB0_de(0, &D_8014D470);
    *p = 1;
    func_802B9C80_de();
    return result;
}

void func_802B75F4_de(ContPad *data) {
    extern u8 D_8014D470[];
    u8 *ptr = D_8014D470;
    u8 *count = &D_8014D46C;
    ContReadFormat readformat;
    s32 i;

    for (i = 0; i < *count; i++, ptr += sizeof(ContReadFormat), data++) {
        readformat = *(ContReadFormat *)ptr;
        data->error = (readformat.rxsize & 0xC0) >> 4;
        if (data->error != 0) {
            continue;
        }
        data->button = readformat.button;
        data->stick_x = readformat.stick_x;
        data->stick_y = readformat.stick_y;
    }
}

void func_802B768C_de(void) {
    extern OSPifRam D_8014D470;
    ContReadFormat readformat;
    u8 *ptr;
    u8 *count;
    s32 i;

    ptr = (u8 *)D_8014D470.ramarray;
    for (i = 14; i >= 0; i--) {
        ((s32 *)ptr)[i] = 0;
    }

    D_8014D470.pifstatus = 1;
    readformat.dummy = 0xFF;
    readformat.txsize = 1;
    readformat.rxsize = 4;
    readformat.cmd = 1;
    readformat.button = 0xFFFF;
    readformat.stick_x = -1;
    readformat.stick_y = -1;

    count = &D_8014D46C;
    for (i = 0; i < *count; i++) {
        *(ContReadFormat *)ptr = readformat;
        ptr += sizeof(ContReadFormat);
    }
    *ptr = 0xFE;
}

s32 func_802B7740_de(s32 arg0, s32 arg1) {
    extern char D_8014D470;
    s32 output;
    s32 result;
    u8 *state;
    s32 sentinel;

    func_802B9C14_de();
    state = &D_8014D4B0;
    sentinel = 0xFF;
    if (*state != sentinel) {
        char *data;

        func_802B784C_de();
        data = &D_8014D470;
        func_802B9CB0_de(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        func_802B9CB0_de(0, data);
        func_802BB2A0_de(arg0, 0, 1);
        func_802B7A20_de(sentinel);
        func_802B9CB0_de(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        *state = sentinel;
    }
    result = func_802B9CB0_de(0, &D_8014D470);
    func_802BB2A0_de(arg0, 0, 1);
    func_802B7AD8_de(&output, arg1);
    func_802B9C80_de();
    return result;
}

void func_802B784C_de(void) {
    extern char D_8014D470;
    OSPifRam *ram = (OSPifRam *)&D_8014D470;
    s32 var_v0;
    u8 *var_v1;
    s32 val;

    var_v1 = &D_8014D470;
    ram->pifstatus = 1;
    val = 0xFD;
    var_v0 = 3;
    do {
        *var_v1 = val;
        var_v0 -= 1;
        var_v1 += 1;
    } while (var_v0 >= 0);
    *var_v1 = 0xFE;
}

s32 func_802B7880_de(s32 arg0, s32 *arg1, s32 arg2) {
    extern char D_8014D470;
    s32 sp20[8];
    s32 sp40[6];
    s32 sp58[2];
    u64 value;
    s32 result;
    s32 *initialized = &D_800D4340;

    if (*initialized != 0) {
        return 0;
    }
    *initialized = 1;
    value = func_802BADC0_de();
    if (value <= 0x0165A0BBULL) {
        func_802BAC60_de(sp40, (s32)sp58, 1);
        func_802BB6C0_de(sp20, 0x0165A0BCULL - value, 0, sp40, sp58);
        func_802BB2A0_de(sp40, (s32)sp58, 1);
    }
    D_8014D46C = 4;
    func_802B7A20_de(0);
    func_802B9CB0_de(1, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    result = func_802B9CB0_de(0, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    func_802B7AD8_de(arg1, arg2);
    D_8014D4B0 = 0;
    func_802B9BC0_de();
    func_802BAC60_de(&D_801471C0, (s32)&D_801471D8, 1);
    return result;
}
