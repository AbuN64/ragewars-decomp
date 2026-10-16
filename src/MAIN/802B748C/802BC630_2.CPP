#include "MAIN/802B748C.H"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_802B7488.h"
#include "span_1000/code_802B9BB4.h"
#include "span_1000/code_802BB15C.h"
#include "TYPES.H"

extern s8 D_8014D46C;

extern void func_802B7A20_de(s32 arg0);

extern void func_802B7AD8_de(s32 *arg0, s32 arg1);

extern void func_802B784C_de(void);

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

void func_802B768C_de(void);

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
        __osSiRawStartDma(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        __osSiRawStartDma(0, data);
        func_802BB2A0_de(arg0, 0, 1);
        func_802B7A20_de(sentinel);
        __osSiRawStartDma(1, data);
        func_802BB2A0_de(arg0, 0, 1);
        *state = sentinel;
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    func_802BB2A0_de(arg0, 0, 1);
    func_802B7AD8_de(&output, arg1);
    func_802B9C80_de();
    return result;
}
