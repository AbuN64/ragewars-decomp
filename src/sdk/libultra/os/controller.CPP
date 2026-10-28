#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/CONTREADFORMAT.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_18.H"
#include "sdk/OS/802BC630_2.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"
#include "sdk/OS/__OSPACKRESETDATA.H"
#include "sdk/OS/siaccess.H"

void __osPackReadData(void);

s32 osContStartReadData(s32 completionQueue) {
    s32 result;
    u8 *p;

    __osSiGetAccess();
    p = &D_8014D4B0;
    if (*p != 1) {
        __osPackReadData();
        __osSiRawStartDma(1, &D_8014D470);
        osRecvMesg(completionQueue, 0, 1);
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    *p = 1;
    __osSiRelAccess();
    return result;
}

extern void __osPackRequestData(s32 arg0);

extern void __osContGetInitData(s32 *arg0, s32 arg1);

void __osPackResetData(void);

void osContGetReadData(ContPad *data) {
    u8 *ptr = (u8 *)&D_8014D470;
    u8 *count = D_8014D46C;
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


void __osPackReadData(void) {
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

    count = D_8014D46C;
    for (i = 0; i < *count; i++) {
        *(ContReadFormat *)ptr = readformat;
        ptr += sizeof(ContReadFormat);
    }
    *ptr = 0xFE;
}

s32 osContReset(s32 arg0, s32 controllerStatus) {
    s32 output;
    s32 result;
    u8 *state;
    s32 sentinel;

    __osSiGetAccess();
    state = &D_8014D4B0;
    sentinel = 0xFF;
    if (*state != sentinel) {
        char *data;

        __osPackResetData();
        data = &D_8014D470;
        __osSiRawStartDma(1, data);
        osRecvMesg(arg0, 0, 1);
        __osSiRawStartDma(0, data);
        osRecvMesg(arg0, 0, 1);
        __osPackRequestData(sentinel);
        __osSiRawStartDma(1, data);
        osRecvMesg(arg0, 0, 1);
        *state = sentinel;
    }
    result = __osSiRawStartDma(0, &D_8014D470);
    osRecvMesg(arg0, 0, 1);
    __osContGetInitData(&output, controllerStatus);
    __osSiRelAccess();
    return result;
}



extern void osSetTimer(void *arg0, u64 arg1, u64 arg2, void *arg3, void *arg4);


void __osPackResetData(void) {
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

s32 osContInit(s32 arg0, s32 *valid, s32 arg2) {
    s32 node[8];
    s32 sp40[6];
    s32 message[2];
    u64 value;
    s32 result;
    s32 *initialized = &D_800D4340;

    if (*initialized != 0) {
        return 0;
    }
    *initialized = 1;
    value = Audio_ReadSystemTime();
    if (value <= 0x0165A0BBULL) {
        osCreateMesgQueue(sp40, (s32)message, 1);
        osSetTimer(node, 0x0165A0BCULL - value, 0, sp40, message);
        osRecvMesg(sp40, (s32)message, 1);
    }
    D_8014D46C[0] = 4;
    __osPackRequestData(0);
    __osSiRawStartDma(1, &D_8014D470);
    osRecvMesg(arg0, (s32)message, 1);
    result = __osSiRawStartDma(0, &D_8014D470);
    osRecvMesg(arg0, (s32)message, 1);
    __osContGetInitData(valid, arg2);
    D_8014D4B0 = 0;
    __osSiCreateAccessQueue();
    osCreateMesgQueue(&D_801471C0, (s32)&D_801471D8, 1);
    return result;
}
