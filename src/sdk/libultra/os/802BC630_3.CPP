#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/OS_2/802BC630_3.H"
#include "sdk/OS_2/802BECB0.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"


extern void func_802B7A20_de(s32 arg0);

extern void func_802B7AD8_de(s32 *arg0, s32 arg1);

extern void func_802BB6C0_de(void *arg0, u64 arg1, u64 arg2, void *arg3, void *arg4);

void func_802B784C_de(void);

void func_802B784C_de(void) {
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
        osCreateMesgQueue(sp40, (s32)sp58, 1);
        func_802BB6C0_de(sp20, 0x0165A0BCULL - value, 0, sp40, sp58);
        func_802BB2A0_de(sp40, (s32)sp58, 1);
    }
    D_8014D46C[0] = 4;
    func_802B7A20_de(0);
    __osSiRawStartDma(1, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    result = __osSiRawStartDma(0, &D_8014D470);
    func_802BB2A0_de(arg0, (s32)sp58, 1);
    func_802B7AD8_de(arg1, arg2);
    D_8014D4B0 = 0;
    func_802B9BC0_de();
    osCreateMesgQueue(&D_801471C0, (s32)&D_801471D8, 1);
    return result;
}
