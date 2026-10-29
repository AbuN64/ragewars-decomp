#include "include_asm.h"
#include "sdk/libultra/pfs/PFS_COUNTPAGEREFERENCES.H"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PLAYER_POOL_AND_INODE_CACHE_VIEWS.H"
#include "TYPES.H"
#include "sdk/PFS/PFS_READWRITEINODE.H"
/* Counts (up to 2) the inode-table slots of every bank holding the page key fpage, reading banks through the cache; returns the count, a read error, or 2 once two slots hold it. 6/88 words: bank value copy register only. */
s32 Pfs_CountPageReferences(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache) {
    s32 j;
    u8 bank;
    s32 ret;
    s32 start;
    s32 sum = 0;
    u32 idx = (fpage.inode_t.page >> 2) + (fpage.inode_t.bank & 7) * 32;

    for (bank = 0; bank < pfs->banks; bank++) {
        start = (bank == 0) ? pfs->inode_start_page : 1;
        if (bank != fpage.inode_t.bank && !((cache->map[idx] >> (bank & 7)) & 1)) {
            continue;
        }
        if (bank != cache->bank) {
            ret = Pfs_ReadWriteInode(pfs, &cache->inode, 0, bank);
            if (ret != 0 && ret != 3) {
                return ret;
            }
            cache->bank = bank;
        }
        for (j = start; sum < 2 && j < 128; j++) {
            if (cache->inode.inode_page[j].ipage == fpage.ipage) {
                sum++;
            }
        }
        if (sum >= 2) {
            return 2;
        }
    }
    return sum;
}
#else
INCLUDE_ASM("ovl_80400000", Pfs_CountPageReferences);
#endif
#endif

#if defined(VERSION_EU)
unsigned char g_PfsCountpagereferencesTrailingBytes[8] = { 0x8C, 0x82, 0x01, 0xCC, 0x14, 0x40, 0x00, 0x03 };
#endif

#if defined(VERSION_DE) || defined(VERSION_US)
#if defined(VERSION_DE)
unsigned int func_80447818_de_padding_1AD818[2] = {
    0xAFB1002C, 0x3C138015,
};
#endif
#if defined(VERSION_US)
char func_80447818_de_padding_1AD818[8] =
    "veDeathA";
#endif
#endif
