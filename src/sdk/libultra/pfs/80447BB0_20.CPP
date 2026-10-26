#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJECTSTATE96.H"
#include "sdk/OSCONTREQUESFORMATSHORT.H"
#include "sdk/PFS/80447BB0_20.H"
#include "sdk/PFS/80447BB0_21.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* __osCheckId, drafted from ultralib src/io/contpfs.c (2.0I branch): reread the controller pak's id
   block from bank zero and report a new pack when it differs from the id cached at initialisation. */
#include "TYPES.H"

extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);

s32 func_80448BFC_de(OSPfs *pfs)
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
#else
INCLUDE_ASM("ovl_80400000", func_80448BFC_de);
#endif
#endif

#if !(defined(VERSION_DE))
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);

s32 func_80448BFC_de(OSPfs *pfs)
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
#endif
