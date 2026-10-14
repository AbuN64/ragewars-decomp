#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80246E34.h"
#include "types.h"
/* Fires the effect events of an object's animation that fall within a frame window: only for the object's
 * own animation at 0x104 or an object flagged 0x4000000; each event whose frame lies in [from, to) is
 * placed from its local point through the object's matrix when it names no bone, otherwise through its
 * bone matrix (or at the object's position when it has none), and for models 0x44E, 0x451 and 0x453 an
 * effect flagged 4 fires only if its bone's hit box shares the object's mask; each fired event spawns its
 * effect through func_80265E10_de and is counted in D_800D06BC. */











extern Entry802AB8DC D_800CC134[];

extern EventRecAt14 *func_80262598_de(void *);
extern s32 func_802625C4_de(void *);
extern s32 *func_8024BFD4_de(char *, s8);
extern struct Shape_typemap_13 *func_8028FDB4_de(s32, s32);
extern void func_80253754_de(s32, s32 *);
extern void func_80270910_de(f32 *, char *);
extern void func_80272898_de(void *, Vec3 *, Vec3 *);
extern void func_80265E10_de(char *, char *, u16, s32, Vec3, struct IntPair);

void func_802476C8_de(char *obj, void *anim, f32 from, f32 to) {
    Vec3 pos;
    Vec3 local;
    f32 matrix[16];
    EventRecAt14 *events;
    s32 count;
    s32 i;
    s32 checkMask;
    s32 fire;
    s32 *resource;
    struct Shape_typemap_13 *table;

    if (!(((struct ObjectLinks180 *) obj)->unk_100 & 0x4000000) && anim != obj + 0x104) {
        return;
    }
    switch (((struct ObjectLinks180 *) obj)->unk_E4) {
    case 0x44E:
    case 0x451:
    case 0x453:
        checkMask = 1;
        break;
    default:
        checkMask = 0;
        break;
    }
    table = 0;
    events = func_80262598_de(anim);
    count = func_802625C4_de(anim);
    resource = 0;
    for (i = 0; i < count; i++) {
        if (from <= (f32)events[i].frame && (f32)events[i].frame < to) {
            fire = 1;
            if (events[i].bone == -1) {
                local.x = events[i].local.x;
                local.y = events[i].local.z;
                local.z = events[i].local.y;
                func_80272898_de(obj + 0x74, &local, &pos);
            } else {
                if (checkMask && (D_800CC134[events[i].effect].offset & 4)) {
                    if (resource == 0) {
                        resource = func_8024BFD4_de(obj, ((struct ObjectLinks180 *) obj)->unk_1);
                        if (resource == 0) {
                            goto masked;
                        }
                        table = func_8028FDB4_de(*resource, 5);
                    }
                    fire = ((struct Shape_typemap_3 *) (((char *) table) + ((events[i].bone * table->field_0) + 0x74)))->field_0 & ((struct ObjectLinks180 *) obj)->unk_17C;
                }
            masked:
                if (fire == 0) {
                    continue;
                }
                if (((struct ObjectLinks180 *) obj)->unk_B8 != 0) {
                    func_80270910_de(matrix, ((struct ObjectLinks180 *) obj)->unk_B8 + (events[i].bone << 6));
                    func_80272898_de(matrix, &events[i].local, &pos);
                } else {
                    pos = ((struct ObjectLinks180 *) obj)->unk_8;
                }
            }
            if (fire != 0) {
                func_80265E10_de(obj, obj, events[i].effect, -1, pos, events[i].params);
                D_800D06BC++;
            }
        }
    }
    if (resource != 0) {
        func_80253754_de(0, resource);
    }
}
