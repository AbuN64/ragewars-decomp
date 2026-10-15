#include "types.h"
#include "span_1000/code_802B7B80.h"
typedef struct __OSInode { u16 pages[128]; } __OSInode;
typedef struct OSInodeCache { __OSInode inode; u8 bank; u8 references[256]; } OSInodeCache;
s32 func_804488A4_de(OSPfs *, __OSInode *, u8, u8);
s32 func_80448A48_eu_x(OSPfs *pfs, s32 value, OSInodeCache *cache) {
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
