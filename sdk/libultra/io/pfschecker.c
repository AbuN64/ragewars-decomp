#include "../../include/libultra/pfs/PFS_COUNTPAGEREFERENCES.H"

#if !(defined(VERSION_EU_X) || defined(VERSION_US_REV1))
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PLAYER_POOL_AND_INODE_CACHE_VIEWS.H"
#include "TYPES.H"
#include "../../include/PFS/PFS_READWRITEINODE.H"
s32 corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache) {
    int j;
    int n;
    int hit;
    u8 bank;
    int offset;
    s32 ret;

    hit = 0;
    ret = 0;
    n = (fpage.inode_t.page / 4) + (fpage.inode_t.bank % 8) * 32;

    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        if (bank == fpage.inode_t.bank || cache->map[n] & (1 << (bank % 8))) {
            if (bank != cache->bank) {
                ret = Pfs_ReadWriteInode(pfs, &cache->inode, 0, bank);

                if (ret != 0 && ret != 3) {
                    return ret;
                }

                cache->bank = bank;
            }

            for (j = offset; hit < 2 && (j < 128); j++) {
                if (cache->inode.inode_page[j].ipage == fpage.ipage) {
                    hit++;
                }
            }

            if (hit >= 2) {
                return 2;
            }
        }
    }
    return hit;
}
#endif


