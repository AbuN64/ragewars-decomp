#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "particle/80271B18_3.H"

/* Draws an actor's attached model: when the actor has one, allocates a matrix from the pool D_8011FFB0,
 * fills it with the given transform multiplied by the camera matrix (func_8026F898_de, Particle_ClampMatrixToFixedRange,
 * func_8026FC9C_de), loads it into the display list, draws the model through Render_DrawResourceModel with the
 * actor's per-frame state for the current frame, then reloads the camera's per-frame matrix. */








extern s32 func_802799C0_de(void *, s32);


extern void Particle_ClampMatrixToFixedRange(f32 *);

extern void func_8026FC9C_de(f32 *, s32);


/* Moves an actor toward a point given relative to it: the offset is turned by the actor's facing and added to its position (or, for a mirrored actor with a parent, negated in x and z and transformed by the parent's matrix at 0x160), then passed to func_8024E79C_de with both final flags set. */




extern void func_8024BC94_de(CVector3 *out, void *actor, CVector3 offset);

extern void Particle_AddVec3(CVector3 *out, CVector3 *a, CVector3 *b);

extern void func_8024E79C_de(void *actor, CVector3 target, void *arg4, s32 *arg5, s32 arg6, s32 arg7);

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
            Particle_ClampMatrixToFixedRange(mf);
            func_8026FC9C_de(mf, mtx);
            gSPMatrix(g_displayListCursor++, mtx, G_MTX_LOAD | G_MTX_PROJECTION);
            Render_DrawResourceModel(layer, camera->style, object->fieldB4, 1,
                          &object->lighting[D_800D297C], 0, object->field3);
            restore = g_displayListCursor++;
            offset = (D_800D297C << 6) + 0x380;
            gSPMatrix(restore, matrices + offset, G_MTX_LOAD | G_MTX_PROJECTION);
        }
    }
}

void func_8024BBB4_de(char *actor, CVector3 offset, void *arg4, s32 *arg5)
{
    CVector3 turned;
    CVector3 target;

    if (((ObjectLinks1DC_3 *)(actor))->unk_100 & 0x300000) {
        char *parent;

        offset.x = -offset.x;
        offset.z = -offset.z;
        parent = ((struct ObjRecAt5DC *) ((ObjectLinks1DC_3 *) actor)->unk_1D8)->unk5DC;
        if (parent != 0) {
            Particle_TransformPoint(parent + 0x160, &offset, &target);
        } else {
            func_8024BC94_de(&turned, actor, offset);
            Particle_AddVec3(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
        }
    } else {
        func_8024BC94_de(&turned, actor, offset);
        Particle_AddVec3(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
    }
    func_8024E79C_de(actor, target, arg4, arg5, 1, 1);
}
