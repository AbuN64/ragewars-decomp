#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
/* __osCheckPackId, drafted from ultralib src/io/contpfs.c (2.0I branch): find a backup copy of the
   controller pak id whose checksums hold and write it over the other copies, with __osIdCheckSum as
   an inline helper the cartridge inlines. */











extern s32 func_80448CC4_de(OSPfs_func_80445F80_de *pfs);
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_802B8880_de(void *queue, int channel, u16 address, u8 *buffer, int force);

static inline s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
    u16 data = 0;
    u32 j;

    *csum = *icsum = 0;

    for (j = 0; j < 28; j += 2) {
        data = *(u16 *)((u32)ptr + j);
        *csum += data;
        *icsum += ~data;
    }

    return 0;
}

s32 func_80448548_de(OSPfs_func_80445F80_de *pfs, __OSPackId *temp)
{
    u16 index[4];
    s32 ret = 0;
    u16 sum;
    u16 isum;
    int i;
    int j;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_80448CC4_de(pfs);
        if (ret != 0)
            return ret;
    }
    index[0] = 1;
    index[1] = 3;
    index[2] = 4;
    index[3] = 6;
    for (i = 1; i < 4; i++) {
        ret = func_802B84C0_de(pfs->queue, pfs->channel, index[i], (u8 *)temp);
        if (ret != 0)
            return ret;
        __osIdCheckSum((u16 *)temp, &sum, &isum);
        if (temp->checksum == sum && temp->inverted_checksum == isum) {
            break;
        }
    }

    if (i == 4) {
        return 10;
    }

    for (j = 0; j < 4; j++) {
        if (j != i) {
            ret = func_802B8880_de(pfs->queue, pfs->channel, index[j], (u8 *)temp, 1);
            if (ret != 0)
                return ret;
        }
    }

    return 0;
}
