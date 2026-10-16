#include "span_1000/code_8024BA6C.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "gbi.h"
#include "gfx.h"
#include "n64sdk.h"
#include "TYPES.H"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80291054.h"

/* Draws an actor's attached model: when the actor has one, allocates a matrix from the pool D_8011FFB0,
 * fills it with the given transform multiplied by the camera matrix (func_8026F898_de, func_80272828_de,
 * func_8026FC9C_de), loads it into the display list, draws the model through func_8026C6D8_de with the
 * actor's per-frame state for the current frame, then reloads the camera's per-frame matrix. */








extern s32 func_802799C0_de(void *, s32);


extern void func_80272828_de(f32 *);

extern void func_8026FC9C_de(f32 *, s32);


/* Moves an actor toward a point given relative to it: the offset is turned by the actor's facing and added to its position (or, for a mirrored actor with a parent, negated in x and z and transformed by the parent's matrix at 0x160), then passed to func_8024E79C_de with both final flags set. */



extern void func_80272898_de(void *matrix, Vec3 *in, Vec3 *out);

extern void func_8024BC94_de(Vec3 *out, void *actor, Vec3 offset);

extern void func_80271F34_de(Vec3 *out, Vec3 *a, Vec3 *b);

extern void func_8024E79C_de(void *actor, Vec3 target, void *arg4, s32 *arg5, s32 arg6, s32 arg7);

void func_8024BA7C_de(void *actor, Camera *camera, f32 *transform, u8 layer) {
    struct LevelActor *object = actor;
    f32 mf[16];
    s32 mtx;
    s32 matrices;
    Gfx *restore;
    Gfx *load;
    s32 offset;

    if (object->fieldB4 != 0) {
        mtx = func_802799C0_de(&D_8011FFB0, 1);
        if (mtx != 0) {
            matrices = camera->matrices;
            func_8026F898_de(mf, transform, (f32 *)(matrices + 0x1E0));
            func_80272828_de(mf);
            func_8026FC9C_de(mf, mtx);
            gSPMatrix(D_80110634++, mtx, G_MTX_LOAD | G_MTX_PROJECTION);
            func_8026C6D8_de(layer, camera->style, object->fieldB4, 1,
                          &object->lighting[D_800D297C], 0, object->field3);
            restore = D_80110634++;
            offset = (D_800D297C << 6) + 0x380;
            gSPMatrix(restore, matrices + offset, G_MTX_LOAD | G_MTX_PROJECTION);
        }
    }
}

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
