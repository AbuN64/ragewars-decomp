#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802B7B80.h"
#include "types.h"
/* osMotorInit, drafted from ultralib src/io/motor.c (the branch before 2.0J) with its static
   _MakeMotorData, which this library inlines: _MotorStartData, _motorstartbuf, _MotorStopData and _motorstopbuf are
   D_8014D4C0, D_8014D5C0, D_8014D5E0 and D_8014D6E0, and __osMotorinitialized is D_800D8380. */
typedef struct OSMesgQueue OSMesgQueue;
extern OSPifRam D_8014D4C0[4];
extern u8 D_8014D5C0[32];
extern OSPifRam D_8014D5E0[4];
extern u8 D_8014D6E0[32];
extern u32 D_800D8380[4];
extern s32 func_802B84C0_de(OSMesgQueue *mq, int channel, u16 address, u8 *buffer);
extern s32 func_802B8880_de(OSMesgQueue *mq, int channel, u16 address, u8 *buffer, int force);
extern u8 func_802B8C40_de(u16 address);
static inline void _MakeMotorData(int channel, u16 address, u8 *buffer, OSPifRam *mdata)
{
    u8 *ptr = (u8 *)mdata->ramarray;
    __OSContRamReadFormat ramreadformat;
    int i;
    for (i = 0; i < ((s32)(sizeof(mdata->ramarray) / sizeof(mdata->ramarray[0]))); i++) {
        mdata->ramarray[i] = 0;
    }
    mdata->pifstatus = 1;
    ramreadformat.dummy = 0xFF;
    ramreadformat.txsize = 35;
    ramreadformat.rxsize = 1;
    ramreadformat.cmd = 3;
    ramreadformat.address = (address << 0x5) | func_802B8C40_de(address);
    ramreadformat.datacrc = 0xFF;
    for (i = 0; i < ((s32)(sizeof(ramreadformat.data) / sizeof(ramreadformat.data[0]))); i++) {
        ramreadformat.data[i] = *buffer++;
    }
    if (channel != 0) {
        for (i = 0; i < channel; i++) {
            *ptr++ = 0;
        }
    }
    *(__OSContRamReadFormat *)ptr = ramreadformat;
    ptr += sizeof(__OSContRamReadFormat);
    ptr[0] = 0xFE;
}
s32 func_802B7FD8_de(OSMesgQueue *mq, OSPfs *pfs, int channel)
{
    int i;
    s32 ret;
    u8 temp[32];
    u8 *startbuf;
    u8 *stopbuf;
    pfs->queue = mq;
    pfs->channel = channel;
    pfs->status = 0;
    pfs->activebank = 128;
    for (i = 0; i < ((s32)(sizeof(temp) / sizeof(temp[0]))); i++) {
        temp[i] = 254;
    }
    ret = func_802B8880_de(mq, channel, 0x400, temp, 0);
    if (ret == 2) {
        ret = func_802B8880_de(mq, channel, 0x400, temp, 0);
    }
    if (ret != 0) {
        return ret;
    }
    ret = func_802B84C0_de(mq, channel, 0x400, temp);
    if (ret == 2) {
        ret = 4;
    }
    if (ret != 0) {
        return ret;
    }
    if (temp[31] == 254) {
        return 11;
    }
    for (i = 0; i < ((s32)(sizeof(temp) / sizeof(temp[0]))); i++) {
        temp[i] = 128;
    }
    ret = func_802B8880_de(mq, channel, 0x400, temp, 0);
    if (ret == 2) {
        ret = func_802B8880_de(mq, channel, 0x400, temp, 0);
    }
    if (ret != 0) {
        return ret;
    }
    ret = func_802B84C0_de(mq, channel, 0x400, temp);
    if (ret == 2) {
        ret = 4;
    }
    if (ret != 0) {
        return ret;
    }
    if (temp[31] != 0x80) {
        return 11;
    }
    if (!D_800D8380[channel]) {
        for (i = 0; i < ((s32)(sizeof(D_8014D5C0) / sizeof(D_8014D5C0[0]))); i++) {
            /* Each buffer address is taken where it is used, as -fforce-addr compiles it, so the
               loop optimiser hoists it into a register in this order. */
            startbuf = D_8014D5C0;
            startbuf[i] = 1;
            stopbuf = D_8014D6E0;
            stopbuf[i] = 0;
        }
        _MakeMotorData(channel, 0x600, D_8014D5C0, &D_8014D4C0[channel]);
        _MakeMotorData(channel, 0x600, D_8014D6E0, &D_8014D5E0[channel]);
        D_800D8380[channel] = 1;
    }
    return 0;
}
