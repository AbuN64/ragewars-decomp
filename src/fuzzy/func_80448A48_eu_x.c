#include "types.h"
typedef struct OSPfs_func_80445F80_de {
    u8 reserved0[0x60]; s32 inode_start_page; u8 banks;
} OSPfs_func_80445F80_de;
typedef struct __OSInode { u16 pages[128]; } __OSInode;
typedef struct OSInodeCache { __OSInode inode; u8 bank; u8 references[256]; } OSInodeCache;
s32 func_804488A4_de(OSPfs_func_80445F80_de *, __OSInode *, u8, u8);
s32 func_80448A48_eu_x(OSPfs_func_80445F80_de *pfs, s32 value, OSInodeCache *cache) {
    u32 key = (value >> 16) & 0xFFFF;
    u32 keyBank = key >> 8;
    u8 bank;
    s32 count = 0, page, result;
    for (bank = 0; bank < pfs->banks; bank++) {
        page = bank == 0 ? pfs->inode_start_page : 1;
        if (bank != keyBank && !(cache->references[((key & 0xFF) >> 2) + (keyBank & 7) * 32] >> (bank & 7) & 1)) continue;
        if (cache->bank != bank) {
            result = func_804488A4_de(pfs, &cache->inode, 0, bank);
            if (result && result != 3) return result;
            cache->bank = bank;
        }
        if (count >= 2) return 2;
        for (; page < 128 && count < 2; page++) if (cache->inode.pages[page] == key) count++;
        if (count >= 2) return 2;
    }
    return count;
}
