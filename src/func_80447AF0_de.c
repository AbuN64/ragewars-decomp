#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"
/* Reads or writes Controller Pak file blocks while validating and following its inode chain, based on the 2.0I public reference. */
extern s32 func_80448CC4_de(OSPfs_func_80445F80_de *pfs);
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_802B8880_de(void *queue, int channel, u16 address, u8 *buffer, int force);
extern s32 func_804488A4_de(OSPfs_func_80445F80_de *,__OSInode *,u8,u8);
extern s32 func_80448BFC_de(OSPfs_func_80445F80_de *);
static inline s32 __osPfsGetNextPage(OSPfs_func_80445F80_de* pfs, u8* bank, __OSInode* inode, __OSInodeUnit* page) {
    s32 ret;
    if (page->inode_t.bank != *bank) {
        *bank = page->inode_t.bank;
        ret=func_804488A4_de(pfs, inode, 0, *bank); if(ret!=0) return ret;
    }
    *page = inode->inode_page[page->inode_t.page];
    if (!(((*page).ipage >= pfs->inode_start_page) && ((*page).inode_t.bank < pfs->banks) && ((*page).inode_t.page >= 0x01) && ((*page).inode_t.page < 0x80))) {
        if (page->ipage == 1) {
            return 5;
        }
        return 3;
    }
    return 0;
}
s32 func_80447AF0_de(OSPfs_func_80445F80_de* pfs, s32 file_no, u8 flag, int offset, int size_in_bytes, u8* data_buffer) {
    s32 ret;
    __OSDir dir;
    __OSInode inode;
    __OSInodeUnit cur_page;
    int cur_block;
    int siz_block;
    u8* buffer;
    u8 bank;
    u16 blockno;
    if ((file_no >= (s32)pfs->dir_size) || (file_no < 0)) {
        return 5;
    }
    if ((size_in_bytes <= 0) || ((size_in_bytes % 32) != 0)) {
        return 5;
    }
    if ((offset < 0) || ((offset % 32) != 0)) {
        return 5;
    }
    if((pfs->status&1)==0) return 5;
    if(func_80448BFC_de(pfs)==2) return 2;
    if(pfs->activebank!=0) {pfs->activebank=0;ret=func_80448CC4_de(pfs); if(ret!=0) return ret;} (void)0;
    ret=func_802B84C0_de(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8*)&dir); if(ret!=0) return ret;
    if (dir.company_code == 0 || dir.game_code == 0) {
        return 5;
    }
    if (!(((dir.start_page).ipage >= pfs->inode_start_page) && ((dir.start_page).inode_t.bank < pfs->banks) && ((dir.start_page).inode_t.page >= 0x01) && ((dir.start_page).inode_t.page < 0x80))) {
        if ((dir.start_page.ipage == 1)) {
            return 5;
        }
        return 3;
    }
    if (flag == 0 && (dir.status & 2) == 0) {
        return 6;
    }
    bank = -1;
    cur_block = offset / 32;
    cur_page = dir.start_page;
    while (cur_block >= 8) {
        ret=__osPfsGetNextPage(pfs, &bank, &inode, &cur_page); if(ret!=0) return ret;
        cur_block -= 8;
    }
    siz_block = size_in_bytes / 32;
    buffer = data_buffer;
    while (siz_block > 0) {
        if (cur_block == 8) {
            ret=__osPfsGetNextPage(pfs, &bank, &inode, &cur_page); if(ret!=0) return ret;
            cur_block = 0;
        }
        if (pfs->activebank != cur_page.inode_t.bank) {
            ret=(pfs->activebank=(cur_page.inode_t.bank),func_80448CC4_de(pfs)); if(ret!=0) return ret;
        }
        blockno = cur_page.inode_t.page * 8 + cur_block;
        if (flag == 0) {
            ret = func_802B84C0_de(pfs->queue, pfs->channel, blockno, buffer);
        } else {
            ret = func_802B8880_de(pfs->queue, pfs->channel, blockno, buffer, 0);
        }
        if (ret != 0) {
            return ret;
        }
        buffer += 32;
        cur_block++;
        siz_block--;
    }
    if (flag == 1 && (dir.status & 2) == 0) {
        dir.status |= 2;
        ret=(pfs->activebank=(0),func_80448CC4_de(pfs)); if(ret!=0) return ret;
        ret=func_802B8880_de(pfs->queue, pfs->channel, pfs->dir_table + file_no, (u8*)&dir, 0); if(ret!=0) return ret;
    }
    return 0;
}
