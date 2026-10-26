#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "COMMON/ARG.H"
#include "COMMON/OBJECTSTATE96.H"
#include "TYPES.H"
#include "sdk/OSCONTREQUESFORMATSHORT.H"
#include "sdk/PFS/80447BB0_19.H"
#include "sdk/PFS/80447BB0_20.H"
#include "sdk/PFS/80447BB0_21.H"
#include "sdk/PFS/80447BB0_9.H"

/* osPfsInitPak, drafted from ultralib src/io/pfsinitpak.c (2.0I branch): confirm a controller pak is
   present, read and if needed repair its id block, derive the file system layout from it, read the
   label and run the checker. The id checksums are read through the block itself and the repaired
   device id through the new id rather than through the id pointer. */












extern s32 func_80446D80_de(void *queue, int channel);
extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_80448548_de(OSPfs *pfs, __OSPackId *temp);
extern s32 func_80448260_de(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);

s32 func_80446F60_de(void *queue, OSPfs *pfs, int channel)
{
    int k;
    s32 ret = 0;
    u16 sum;
    u16 isum;
    u8 temp[32];
    __OSPackId *id;
    __OSPackId newid;

    func_802B9C14_de();

    ret = func_80446D80_de(queue, channel);

    func_802B9C80_de();

    if (ret != 0) {
        return ret;
    }

    pfs->queue = queue;
    pfs->channel = channel;
    pfs->status = 0;

    pfs->activebank = 0;
    ret = Pfs_SelectActiveBank(pfs);
    if (ret != 0)
        return ret;
    ret = func_802B84C0_de(pfs->queue, pfs->channel, 1, temp);
    if (ret != 0)
        return ret;

    Pfs_ComputeIdChecksums((u16 *)temp, &sum, &isum);
    id = (__OSPackId *)temp;

    if ((((__OSPackId *)temp)->checksum != sum) || (((__OSPackId *)temp)->inverted_checksum != isum)) {
        ret = func_80448548_de(pfs, id);

        if (ret != 0) {
            return ret;
        } else if (ret != 0) {
            return ret;
        }
    }

    if (!(id->deviceid & 1)) {
        ret = func_80448260_de(pfs, id, &newid);

        if (ret != 0) {
            return ret;
        }

        id = &newid;

        if (!(newid.deviceid & 1)) {
            return 11;
        }
    }

    for (k = 0; k < 32; k++) {
        pfs->id[k] = ((u8 *)id)[k];
    }

    pfs->version = id->version;
    pfs->banks = id->banks;
    pfs->inode_start_page = 1 + 2 + (2 * pfs->banks);
    pfs->dir_size = 2 * 8;
    pfs->inode_table = 1 * 8;
    pfs->minode_table = (1 + pfs->banks) * 8;
    pfs->dir_table = pfs->minode_table + (pfs->banks * 8);

    ret = func_802B84C0_de(pfs->queue, pfs->channel, 7, pfs->label);
    if (ret != 0)
        return ret;

    ret = func_80447130_de(pfs);
    pfs->status |= 1;

    return ret;
}

/* osPfsChecker, drafted from ultralib src/io/pfschecker.c (2.0I branch): clear directory entries whose
   page chains are broken or shared, rebuild every bank's inode table from the surviving chains, and
   flag the pak corrupted when anything was fixed. */










extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);
extern s32 func_802B8880_de(void *queue, int channel, u16 address, u8 *buffer, int force);
extern s32 func_8044756C_de(OSPfs *pfs, __OSInodeCache *cache);
extern s32 Pfs_CountPageReferences(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache);

s32 func_80447130_de(OSPfs *pfs)
{
    int j;
    s32 ret;
    __OSInodeUnit next_page;
    __OSInode checked_inode;
    __OSInode tmp_inode;
    __OSDir tmp_dir;
    __OSInodeUnit file_next_node[16];
    __OSInodeCache cache;
    int fixed = 0;
    u8 bank;
    s32 cc;
    s32 cl;
    int offset;

    ret = func_80448BFC_de(pfs);

    if (ret == 2) {
        ret = func_804486B8_de(pfs);
    }

    if (ret != 0) {
        return ret;
    }

    ret = func_8044756C_de(pfs, &cache);
    if (ret != 0)
        return ret;

    for (j = 0; j < pfs->dir_size; j++) {
        ret = func_802B84C0_de(pfs->queue, pfs->channel, pfs->dir_table + j, (u8 *)&tmp_dir);
        if (ret != 0)
            return ret;

        if (tmp_dir.company_code != 0 && tmp_dir.game_code != 0) {
            next_page = tmp_dir.start_page;
            cl = cc = 0;
            bank = 255;

            while ((next_page.ipage >= pfs->inode_start_page) && (next_page.inode_t.bank < pfs->banks) &&
                   (next_page.inode_t.page >= 0x01) && (next_page.inode_t.page < 0x80)) {
                if (bank != next_page.inode_t.bank) {
                    bank = next_page.inode_t.bank;
                    ret = Pfs_ReadWriteInode(pfs, &tmp_inode, 0, bank);
                    if (ret != 0 && ret != 3) {
                        return ret;
                    }
                }

                if ((cc = 
Pfs_CountPageReferences
(pfs, next_page, &cache) - cl) != 0) {
                    break;
                }

                cl = 1;
                next_page = tmp_inode.inode_page[next_page.inode_t.page];
            }

            if (cc != 0 || next_page.ipage != 1) {
                tmp_dir.company_code = 0;
                tmp_dir.game_code = 0;
                tmp_dir.start_page.ipage = 0;
                tmp_dir.status = 0;
                tmp_dir.data_sum = 0;

                if (pfs->activebank != 0) {
                    pfs->activebank = 0;
                    ret = Pfs_SelectActiveBank(pfs);
                    if (ret != 0)
                        return ret;
                }
                ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->dir_table + j, (u8 *)&tmp_dir, 0);
                if (ret != 0)
                    return ret;
                fixed++;
            }
        } else {
            if (tmp_dir.company_code != 0 || tmp_dir.game_code != 0) {
                tmp_dir.company_code = 0;
                tmp_dir.game_code = 0;
                tmp_dir.start_page.ipage = 0;
                tmp_dir.status = 0;
                tmp_dir.data_sum = 0;

                if (pfs->activebank != 0) {
                    pfs->activebank = 0;
                    ret = Pfs_SelectActiveBank(pfs);
                    if (ret != 0)
                        return ret;
                }
                ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->dir_table + j, (u8 *)&tmp_dir, 0);
                if (ret != 0)
                    return ret;
                fixed++;
            }
        }
    }
    for (j = 0; j < pfs->dir_size; j++) {
        ret = func_802B84C0_de(pfs->queue, pfs->channel, pfs->dir_table + j, (u8 *)&tmp_dir);
        if (ret != 0)
            return ret;

        if (tmp_dir.company_code != 0 && tmp_dir.game_code != 0 &&
            tmp_dir.start_page.ipage >= (u16)pfs->inode_start_page) {
            file_next_node[j].ipage = tmp_dir.start_page.ipage;
        } else {
            file_next_node[j].ipage = 0;
        }
    }

    for (bank = 0; bank < pfs->banks; bank++) {
        ret = Pfs_ReadWriteInode(pfs, &tmp_inode, 0, bank);

        if (ret != 0 && ret != 3) {
            return ret;
        }

        offset = (bank > 0) ? 1 : pfs->inode_start_page;

        for (j = 0; j < offset; j++) {
            checked_inode.inode_page[j].ipage = tmp_inode.inode_page[j].ipage;
        }

        for (; j < 128; j++) {
            checked_inode.inode_page[j].ipage = 3;
        }

        for (j = 0; j < pfs->dir_size; j++) {
            while (file_next_node[j].inode_t.bank == bank &&
                   file_next_node[j].ipage >= (u16)pfs->inode_start_page) {
                u8 pp = file_next_node[j].inode_t.page;
                file_next_node[j] = checked_inode.inode_page[pp] = tmp_inode.inode_page[pp];
            }
        }
        ret = Pfs_ReadWriteInode(pfs, &checked_inode, 1, bank);
        if (ret != 0)
            return ret;
    }

    if (fixed) {
        pfs->status |= 2;
    } else {
        pfs->status &= ~2;
    }

    return 0;
}

/* corrupted_init, drafted from ultralib src/io/pfschecker.c (2.0I branch): build the checker's map of
   which banks hold inode links into each sector of other banks. */











s32 func_8044756C_de(OSPfs *pfs, __OSInodeCache *cache)
{
    int i;
    int n;
    int offset;
    u8 bank;
    __OSInodeUnit tpage;
    __OSInode tmp_inode;
    s32 ret;

    for (i = 0; i < 256; i++) {
        cache->map[i] = 0;
    }

    cache->bank = -1;
    for (bank = 0; bank < pfs->banks; bank++) {
        offset = bank > 0 ? 1 : pfs->inode_start_page;

        ret = Pfs_ReadWriteInode(pfs, &tmp_inode, 0, bank);

        if (ret != 0 && ret != 3) {
            return ret;
        }

        for (i = offset; i < 128; i++) {
            tpage = tmp_inode.inode_page[i];

            if (tpage.ipage >= pfs->inode_start_page && tpage.inode_t.bank != bank) {
                n = ((tpage.inode_t.page) / 4) + ((tpage.inode_t.bank % 8) * 32);
                cache->map[n] |= 1 << (bank % 8);
            }
        }
    }
    return 0;
}

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* corrupted: counts (up to 2) the inode-table slots of every bank that may hold the page key fpage,
   reading banks through the cache; returns the count, a read error, or PFS_ERR_NEW_PACK (2) once two
   slots hold it (the pak checker's duplicate-page test). The unit is built with -fforce-addr. */
s32 Pfs_CountPageReferences(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache) {
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
