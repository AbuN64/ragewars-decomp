/* __osCheckId, drafted from ultralib src/io/contpfs.c (2.0I branch): reread the controller pak's id
   block from bank zero and report a new pack when it differs from the id cached at initialisation. */
#include "types.h"

typedef struct {
    int status;
    void *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
} OSPfs;

typedef union {
    struct {
        u8 bank;
        u8 page;
    } inode_t;
    u16 ipage;
} __OSInodeUnit;

typedef struct {
    __OSInodeUnit inode_page[128];
} __OSInode;

typedef struct {
    u32 game_code;
    u16 company_code;
    __OSInodeUnit start_page;
    u8 status;
    s8 reserved;
    u16 data_sum;
    u8 ext_name[4];
    u8 game_name[16];
} __OSDir;
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_80448CC4_de(OSPfs *pfs);

s32 func_80448BFC_de(OSPfs *pfs)
{
    int k;
    u8 temp[32];
    s32 ret;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_80448CC4_de(pfs);
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
