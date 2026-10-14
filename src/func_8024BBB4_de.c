#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8024BA6C.h"
#include "types.h"

/* Moves an actor toward a point given relative to it: the offset is turned by the actor's facing and added to its position (or, for a mirrored actor with a parent, negated in x and z and transformed by the parent's matrix at 0x160), then passed to func_8024E79C_de with both final flags set. */



extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);
extern void func_8024BC94_de(Vec3 *out, void *actor, Vec3 offset);
extern void func_80271F34_de(Vec3 *out, Vec3 *a, Vec3 *b);
extern void func_8024E79C_de(void *actor, Vec3 target, void *arg4, s32 *arg5, s32 arg6, s32 arg7);




void func_8024BBB4_de(char *actor, Vec3 offset, void *arg4, s32 *arg5)
{
    Vec3 turned;
    Vec3 target;

    if (((ObjectLinks1DC_3 *)(actor))->unk_100 & 0x300000) {
        char *parent;

        offset.x = -offset.x;
        offset.z = -offset.z;
        parent = ((struct ObjRecAt5DC *) ((ObjectLinks1DC_3 *) actor)->unk_1D8)->unk5DC;
        if (parent != 0) {
            func_80272898_de(parent + 0x160, &offset, &target);
        } else {
            func_8024BC94_de(&turned, actor, offset);
            func_80271F34_de(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
        }
    } else {
        func_8024BC94_de(&turned, actor, offset);
        func_80271F34_de(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
    }
    func_8024E79C_de(actor, target, arg4, arg5, 1, 1);
}
