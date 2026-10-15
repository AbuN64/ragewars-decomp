#include "types.h"
#include "stddef.h"

/* Filters the 0xC0-byte hit records held in table slot 2 of arg1: keeps those whose box
   (six floats at record offset 0xA0) intersects the given bounds, and which either have no
   byte set at record offset 0xBD, are paired with arg4, or list the key that
   func_80250938_de(arg4, arg1) finds inside the id list at slot arg1-table index of the list
   table in slot 3. Writes the accepted record pointers into arg2 (at most 0x40 of them),
   reports their number through arg3, and returns 1 when any accepted record has its byte at
   record offset 0xBA set. With no table (arg1 null) it defers to func_80277C54_de. */

extern s32 func_80277C54_de(void *bounds, void **out, s32 *countOut);
extern s32 func_80250938_de(void *wanted, void *table);
extern void *func_8028FDB4_de(void *table, s32 index);

typedef struct Bounds {
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
} Bounds;

typedef struct HitBox {
    u8 pad0[0xA0];
    f32 minX;
    f32 minY;
    f32 minZ;
    f32 maxX;
    f32 maxY;
    f32 maxZ;
    u8 padB8[2];
    u8 flagBA;
    u8 padBB[2];
    u8 flagBD;
    u8 padBE[2];
} HitBox;

typedef struct HitBoxTable {
    s32 unk0;
    s32 count;
    HitBox boxes[1];
} HitBoxTable;

typedef struct IdList {
    u16 count;
    s16 ids[1];
} IdList;

s32 func_80278020_de(Bounds *bounds, void *table, void **out, s32 *countOut, u8 *wanted) {
    s32 foundCount;
    s32 result;
    s32 idx;
    s32 found;
    s32 n;
    s32 *idTable;
    s32 key;
    s32 id;
    s16 *ids;
    s16 len;
    IdList *list;
    HitBoxTable *boxTable;
    HitBox *box;
    void **outAt;

    foundCount = 0;
    result = 0;
    if (table == NULL) {
        return func_80277C54_de(bounds, out, countOut);
    }
    boxTable = func_8028FDB4_de(table, 2);
    idx = boxTable->count - 1;
    box = boxTable->boxes;
    outAt = out;
    for (; idx != -1; idx--) {
        if (bounds->maxX > box->minX && bounds->minX < box->maxX
            && bounds->maxZ > box->minZ && bounds->minZ < box->maxZ
            && bounds->maxY > box->minY && bounds->minY < box->maxY) {
            if (box->flagBD != 0 && *wanted != 1) {
                found = 0;
                idTable = func_8028FDB4_de(table, 3);
                if (*idTable > 0) {
                    list = func_8028FDB4_de(idTable, idx);
                    len = list->count;
                    ids = list->ids;
                    key = func_80250938_de(wanted, table);
                    n = 0;
                    if (found < len) {
                        do {
                            id = *ids;
                            if (id >= 0x1770) {
                                id -= 0x1770;
                            } else if (id >= 0xFA0) {
                                id -= 0xFA0;
                            } else if (id >= 0x7D0) {
                                id -= 0x7D0;
                            }
                            n++;
                            if (id == key) {
                                found = 1;
                                break;
                            }
                            ids++;
                        } while (n < len);
                    }
                }
            } else {
                found = 1;
            }
            if (found != 0) {
                *outAt = box;
                outAt++;
                foundCount++;
                if (box->flagBA != 0) {
                    result = 1;
                }
                if (foundCount == 0x40) {
                    break;
                }
            }
        }
        box++;
    }
    *countOut = foundCount;
    return result;
}
