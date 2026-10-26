#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE96.H"
#include "sdk/OSCONTREQUESFORMATSHORT.H"
#include "sdk/PFS/80447BB0_20.H"
#include "sdk/PFS/80447BB0_21.H"


extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);

s32 __osCheckId(OSPfs *pfs)
{
    int k;
    u8 temp[32];
    s32 ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = Pfs_SelectActiveBank(pfs);
        if (ret != 0)
            return ret;
    }

    ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, temp);

    if (ret != 0) {
        if (ret != 2) {
            return ret;
        }
        ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, temp);
        if (ret != 0)
            return ret;
    }

    for (k = 0; k < 32; k++) {
        if (pfs->id[k] != temp[k])
            return 2;
    }

    return 0;
}
