#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "SDK/OSCONTREQUESFORMATSHORT.H"
#include "SDK/PFS/80447BB0_19.H"
#include "SDK/PFS/80447BB0_21.H"

/* __osGetId, drafted from ultralib src/io/contpfs.c (2.0I branch): reread a controller pak's id block
   from bank zero, restore or rebuild it when damaged, and refresh the file system layout and label
   from it, with __osIdCheckSum as an inline helper the cartridge inlines; the id checksums are read
   through the block itself and the repaired device id through the new id, not the id pointer. */












extern s32 func_802B84C0_de(void *queue, int channel, u16 address, u8 *buffer);

extern s32 func_80448548_de(OSPfs *pfs, __OSPackId *temp);

extern s32 func_80448260_de(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid);

static inline s32 __osIdCheckSum(u16 *ptr, u16 *csum, u16 *icsum)
{
    u16 data = 0;
    u32 j;

    *csum = *icsum = 0;

    for (j = 0; j < 28; j += 2) {
        data = *(u16 *)((u32)ptr + j);
        *csum += data;
        *icsum += ~data;
    }

    return 0;
}

extern s32 func_802B8880_de(void *queue, int channel, u16 address, u8 *buffer, int force);

static inline u16 __osSumcalc(u8 *ptr, int length)
{
    int i;
    u32 sum = 0;
    u8 *tmp = ptr;

    for (i = 0; i < length; i++) {
        sum += *tmp++;
        sum = sum & 0xFFFF;
    }
    return sum;
}

s32 func_804486B8_de(OSPfs *pfs)
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
    __osIdCheckSum((u16 *)&temp, &sum, &isum);
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

s32 func_804488A4_de(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank)
{
    u8 sum;
    int j;
    s32 ret;
    int offset;
    u8 *addr;

    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        ret = func_80448CC4_de(pfs);
        if (ret != 0)
            return ret;
    }

    offset = (bank > 0) ? 1 : pfs->inode_start_page;

    if (flag == 1) {
        inode->inode_page[0].inode_t.page = __osSumcalc((u8 *)&inode->inode_page[offset], (128 - offset) * 2);
    }

    for (j = 0; j < 8; j++) {
        addr = ((u8 *)inode->inode_page + j * 32);

        if (flag == 1) {
            ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, 0);
        } else {
            ret = func_802B84C0_de(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr);
        }

        if (ret != 0) {
            return ret;
        }
    }

    if (flag == 0) {
        sum = __osSumcalc((u8 *)&inode->inode_page[offset], (128 - offset) * 2);
        if (sum != inode->inode_page[0].inode_t.page) {
            for (j = 0; j < 8; j++) {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = func_802B84C0_de(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr);
            }

            if (sum != inode->inode_page[0].inode_t.page) {
                return 3;
            }

            for (j = 0; j < 8; j++) {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->inode_table + bank * 8 + j, addr, 0);
            }
        } else {
            for (j = 0; j < 8; j++) {
                addr = ((u8 *)inode->inode_page + j * 32);
                ret = func_802B8880_de(pfs->queue, pfs->channel, pfs->minode_table + bank * 8 + j, addr, 0);
            }
        }
    }

    return 0;
}

/* Returns the 16-bit sum of the first count bytes of a block. */

u16 func_80448B84_de(u8 *bytes, s32 count)
{
    s32 i;
    s32 sum;

    i = 0;
    sum = i;
    for (; i < count; i++) {
        sum += *bytes++;
        sum &= 0xFFFF;
    }
    return sum;
}

/* Sums the fourteen halfwords of a 0x1C-byte block into two checksums: the plain sum and the sum
   of their complements. Returns zero. */
s32 func_80448BB4_de(u16 *block, u16 *sum, u16 *inverse) {
    u32 offset;

    *inverse = 0;
    *sum = 0;
    for (offset = 0; offset < 0x1C; offset += 2) {
        u16 value = *(u16 *) ((char *) block + offset);

        *sum += value;
        *inverse += (u16) ~value;
    }
    return 0;
}
