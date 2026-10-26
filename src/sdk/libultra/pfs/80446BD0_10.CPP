#include "sdk/OSCONTREQUESFORMATSHORT.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "sdk/PFS/80446BD0_10.H"
#include "sdk/os.h"
#include "sdk/os_pif.h"

/* __osPfsGetStatus, drafted from ultralib src/io/pfsgetstatus.c (2.0I branch): send a status request
   to one controller through the pak PIF RAM block and turn its reply into a pack-present, new-pack
   or failure code. */








/* __osPfsRequestOneChannel, drafted from the ultralib io pfsgetstatus source (2.0I branch): fill the pak
   PIF RAM block with one skip byte per preceding channel, a status request for the given channel and
   the end marker. */






/* Decodes the six-byte short controller status reply found one byte per preceding channel into D_80154110 for the given channel, recording its error bits and, without error, its type and status.
   Adapted from Pfs_DecodeControllerStatusReplies with the per-channel loop over eight-byte replies changed to a single six-byte reply reached by skipping one byte per preceding channel. */







s32 __osPfsGetStatus(void *queue, int channel)
{
    s32 ret = 0;
    void *dummy;
    EntryRecAt3 data;

    __osPfsRequestOneChannel(channel);

    ret = __osSiRawStartDma(1, &D_80154110);
    osRecvMesg(queue, &dummy, 1);

    ret = __osSiRawStartDma(0, &D_80154110);
    osRecvMesg(queue, &dummy, 1);

    Pfs_DecodeChannelStatus(channel, &data);

    if (((data.team & 1) != 0) && ((data.team & 2) != 0)) {
        return 2;
    } else if ((data.slot != 0) || ((data.team & 1) == 0)) {
        return 1;
    } else if ((data.team & 4) != 0) {
        return 4;
    }

    return ret;
}

void __osPfsRequestOneChannel(int channel)
{
    u8 *base;
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    int i;

    D_8014D4B0 = 0;
    base = (u8 *)&D_80154110;
    D_80154110.pifstatus = 1;
    ptr = base;

    requestformat.txsize = 1;
    requestformat.rxsize = 3;
    requestformat.cmd = 0;
    requestformat.typeh = 0xFF;
    requestformat.typel = 0xFF;
    requestformat.status = 0xFF;

    for (i = 0; i < channel; i++) {
        *ptr++ = 0;
    }

    *(__OSContRequesFormatShort *)ptr = requestformat;
    ptr += sizeof(__OSContRequesFormatShort);
    *ptr = 0xFE;
}

void Pfs_DecodeChannelStatus(s32 channel, EntryRecAt3 *data) {
    u8 *ptr;
    __OSContRequesFormatShort requestformat;
    s32 i;

    ptr = (u8 *)&D_80154110;
    for (i = 0; i < channel; i++) {
        ptr++;
    }
    requestformat = *(__OSContRequesFormatShort *)ptr;
    data->slot = (requestformat.rxsize & 0xC0) >> 4;
    if (data->slot == 0) {
        data->id = (requestformat.typel << 8) | requestformat.typeh;
        data->team = requestformat.status;
    }
}
