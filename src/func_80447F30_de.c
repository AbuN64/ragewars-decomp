#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80447BB0.h"
#include "types.h"

/* osPfsRepairId, drafted from ultralib src/io/pfsrepairid.c (2.0I branch): reread a controller pak's
   id block from bank zero, restore or rebuild it when damaged, and refresh the file system layout and
   label from it. The id checksums are read through the block itself and the repaired device id
   through the new id rather than through the id pointer. */











extern s32 func_80448CC4_de(OSPfs_func_80445F80_de *pfs);
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_80448BB4_de(u16 *ptr, u16 *csum, u16 *icsum);
extern s32 func_80448548_de(OSPfs_func_80445F80_de *pfs, __OSPackId *temp);
extern s32 func_80448260_de(OSPfs_func_80445F80_de *pfs, __OSPackId *badid, __OSPackId *newid);

s32 func_80447F30_de(OSPfs_func_80445F80_de *pfs)
{
    int k;
    u16 sum;
    u16 isum;
    u8 temp[32];
    __OSPackId newid;
    s32 ret;
    __OSPackId *id;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_80448CC4_de(pfs);
        if (ret != 0)
            return ret;
    }
    ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, (u8 *)&temp);
    if (ret != 0)
        return ret;
    func_80448BB4_de((u16 *)&temp, &sum, &isum);
    id = (__OSPackId *)&temp;

    if (((__OSPackId *)temp)->checksum != sum || ((__OSPackId *)temp)->inverted_checksum != isum) {
        ret = func_80448548_de(pfs, id);

        if (ret == 10) {
            ret = func_80448260_de(pfs, id, &newid);
            if (ret != 0)
                return ret;
            id = &newid;
        } else if (ret != 0) {
            return ret;
        }
    }

    if ((id->deviceid & 1) == 0) {
        ret = func_80448260_de(pfs, id, &newid);
        if (ret != 0)
            return ret;
        id = &newid;

        if ((newid.deviceid & 1) == 0) {
            return 11;
        }
    }

    for (k = 0; k < 32; k++) {
        pfs->id[k] = ((u8 *)id)[k];
    }

    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = pfs->banks * 2 + 3;
    pfs->dir_size = 16;
    pfs->inode_table = 8;
    pfs->minode_table = (pfs->banks + 1) * 8;
    pfs->dir_table = pfs->minode_table + pfs->banks * 8;
    ret = func_802B84C0_de(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0)
        return ret;
    return 0;
}

/* osPfsFindFile, drafted from ultralib src/io/pfssearchfile.c (2.0I branch): scan the controller pak
   directory for the entry with the given company and game codes and, when given, names, returning its
   index. */








extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_80448BFC_de(OSPfs_func_80445F80_de *pfs);

s32 func_804480E0_de(OSPfs_func_80445F80_de *pfs, u16 company_code, u32 game_code, u8 *game_name, u8 *ext_name, s32 *file_no)
{
    s32 j;
    int i;
    __OSDir dir;
    s32 ret = 0;
    int fail;

    if (func_80448BFC_de(pfs) == 2)
        return 2;

    for (j = 0; j < pfs->dir_size; j++) {
        ret = func_802B84C0_de(pfs->queue, pfs->channel, pfs->dir_table + j, (u8 *)&dir);
        if (ret != 0)
            return ret;

        if ((dir.company_code == company_code) && dir.game_code == game_code) {
            fail = 0;

            if (game_name != 0) {
                for (i = 0; i < 16; i++) {
                    if (dir.game_name[i] != game_name[i]) {
                        fail = 1;
                        break;
                    }
                }
            }

            if (ext_name != 0 && !fail) {
                for (i = 0; i < 4; i++) {
                    if (dir.ext_name[i] != ext_name[i]) {
                        fail = 1;
                        break;
                    }
                }
            }

            if (!fail) {
                *file_no = j;
                return ret;
            }
        }
    }

    *file_no = -1;
    return 5;
}
