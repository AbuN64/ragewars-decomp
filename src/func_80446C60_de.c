#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041C67C.h"
#include "types.h"
/* osPfsFreeBlocks, drafted from ultralib src/io/pfsfreeblocks.c (2.0I branch): count the unused pages
   in every bank's inode table and report them as bytes. */








extern s32 func_80448BFC_de(OSPfs_func_80445F80_de *pfs);
extern s32 func_804488A4_de(OSPfs_func_80445F80_de *pfs, __OSInode *inode, u8 flag, u8 bank);

s32 func_80446C60_de(OSPfs_func_80445F80_de *pfs, s32 *bytes_not_used)
{
    int j;
    int pages = 0;
    __OSInode inode;
    s32 ret = 0;
    u8 bank;
    int offset;

    if ((pfs->status & 1) == 0)
        return 5;
    if (func_80448BFC_de(pfs) == 2)
        return 2;
    for (bank = 0; bank < pfs->banks; bank++) {
        ret = func_804488A4_de(pfs, &inode, 0, bank);
        if (ret != 0)
            return ret;
        offset = ((bank > 0) ? 1 : pfs->inode_start_page);

        for (j = offset; j < 128; j++) {
            if (inode.inode_page[j].ipage == 3) {
                pages++;
            }
        }
    }

    *bytes_not_used = pages * 8 * 32;
    return 0;
}
