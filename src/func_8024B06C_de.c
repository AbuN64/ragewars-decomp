#include "common/unused.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "types.h"

/* Finds the hit box of an object nearest a point: with the object's bone matrices (0xB4, else 0xB8) and its
 * hit-box resource from func_8024BFD4_de, each box whose mask matches the object's mask 0x17C has the average
 * of its eight corners carried through its bone matrix, and the box whose center lies nearest the point is
 * copied out, taking weight 1 for a controlled actor unless the global option D_801462E5 is set. The
 * resource is released afterwards; returns whether a box was found. */







extern u8 D_801462E5;
extern s32 *func_8024BFD4_de(char *, s8);
extern struct Shape_typemap_13 *func_8028FDB4_de(s32, s32);
extern void func_80253754_de(s32, s32 *);
extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);
extern void func_80271F9C_de(Vec3 *, Vec3 *, f32);
extern void func_80270910_de(f32 *, char *);
extern void func_80272898_de(f32 *, Vec3 *, Vec3 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);

s32 func_8024B06C_de(char *obj, Vec3 point, Box70 *out) {
    Vec3 center;
    Vec3 diff;
    f32 matrix[16];
    s32 *resource;
    s32 count;
    struct Shape_typemap_13 *table;
    Box70 *box;
    Box70 *best;
    char *bones;
    s32 i;
    s32 j;
    f32 dist;
    f32 bestDist;

    bones = ((struct ObjectLinks180_2 *) obj)->unk_B4;
    if (bones == 0) {
        bones = ((struct ObjectLinks180_2 *) obj)->unk_B8;
        if (bones == 0) {
            return 0;
        }
    }
    resource = func_8024BFD4_de(obj, ((struct ObjectLinks180_2 *) obj)->unk_1);
    if (resource == 0) {
        return 0;
    }
    table = func_8028FDB4_de(*resource, 5);
    count = table->field_4;
    bestDist = 3.4028235e38f;
    best = 0;
    for (i = 0; i < count; i++) {
        box = (Box70 *)((char *)table + (i * table->field_0 + 8));
        if (box->mask & ((struct ObjectLinks180_2 *) obj)->unk_17C) {
            center = box->corners[0];
            for (j = 1; j < 8; j++) {
                func_80271F34_de(&center, &center, &box->corners[j]);
            }
            func_80271F9C_de(&center, &center, 0.125f);
            func_80270910_de(matrix, bones + i * 0x40);
            func_80272898_de(matrix, &center, &diff);
            func_80271F68_de(&diff, &diff, &point);
            dist = diff.x * diff.x + diff.y * diff.y + diff.z * diff.z;
            if (dist < bestDist) {
                best = box;
                bestDist = dist;
            }
        }
    }
    if (best != 0) {
        *out = *best;
        if ((((struct ObjectLinks180_2 *) obj)->unk_100 & 0x300000) && D_801462E5 == 0) {
            ((struct Shield *) ((char *) out))->factor = 1.0f;
        }
    }
    func_80253754_de(0, resource);
    return best != 0;
}

extern char D_800CA8C4_de[];
extern TypeEntry *D_800CB440_de[];
extern char *D_80140F84;





void func_8024B2D0_de(char *arg0)
{
    s32 type;
    s32 i;
    s32 count;
    s32 limit;
    char *object;
    TypeEntry *entry;

    type = *((struct Actor_func_8024A7A0_de *)(arg0))->definition;
    if ((u32)type < 15) {
        goto valid_type;
    }
zero_entry:
    entry = 0;
    goto selected;
special_entry:
    entry = (TypeEntry *)D_800CA8C4_de;
    goto selected;
valid_type:
    if (type == 11) {
        count = D_80145048;
        i = 0;
        if (count > 0) {
            limit = count;
            object = D_80140F84;
            do {
                if (object == arg0) {
                    goto zero_entry;
                }
                if (object + 0x2E8 == arg0) {
                    goto special_entry;
                }
                i++;
                object += 0x16E8;
            } while (i < limit);
        }
    }
    entry = D_800CB440_de[type];

selected:
    if (entry != 0 && entry->callback != 0) {
        entry->callback(arg0, (char *)arg0 + 0x170);
    }
    if ((((struct Actor_func_8024A7A0_de *)(arg0))->flags & 0x08000000) != 0) {
        (((struct Actor_func_8024A7A0_de *)(arg0))->updateCount)++;
    }
}


extern f32 D_800C3B48_de[];

extern void *func_8028CF6C_de(void *, s32);

extern s32 func_80285F58_de(void *, void *);
extern void func_802466A0_de(void *, u16, u16, s32, void *, s32, s32, f32,
                          Vec3, u8, Vec3, Vec3, s32);

void func_8024B3A8_de(void *arg0, InputRecAt27 *arg1, s32 mode, s32 index) {
    void *resource0;
    s32 resource1;
    s32 lookup;
    s32 amountRaw;
    f32 fzero;
    f32 amount;
    Vec3 zero;

    resource0 = func_8028CF6C_de(&D_8011FE88, arg1->resource22);
    if (arg1->resource20 == 0xFFFF) {
        resource1 = 0;
    } else {
        resource1 = func_8028B394_de(&D_8011FE88, arg1->resource20);
    }
    amountRaw = arg1->amount24;
    fzero = 0.0f;
    amount = amountRaw * D_800C3B48_de[1];
    zero.x = zero.y = zero.z = fzero;
    lookup = func_80285F58_de(&D_8011FE88, arg0);
    func_802466A0_de(arg0, arg1->unk1C, arg1->unk1E, arg1->unk0,
                  resource0, arg1->unk27 == 0xFF ? -1 : arg1->unk27,
                  resource1, amount, *(Vec3 *)arg1->vec4, arg1->unk26,
                  *(Vec3 *)arg1->vec10, zero, lookup);
}
