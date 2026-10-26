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
 * fills it with the given transform multiplied by the camera matrix (GraphU64_MultiplyMatrices, GraphU64_ClampMatrixToFixedRange,
 * GraphU64_PackFixedMatrix), loads it into the display list, draws the model through Geometry_DrawResourceModel with the
 * actor's per-frame state for the current frame, then reloads the camera's per-frame matrix. */








extern s32 Map_ReserveEntries(void *, s32);


extern void GraphU64_ClampMatrixToFixedRange(f32 *);

extern void GraphU64_PackFixedMatrix(f32 *, s32);


/* Moves an actor toward a point given relative to it: the offset is turned by the actor's facing and added to its position (or, for a mirrored actor with a parent, negated in x and z and transformed by the parent's matrix at 0x160), then passed to InstHdr_CopyActorPositionAndModel with both final flags set. */




#include "ENGINE/INSTANCE/GOBJINST_13.H"

extern void GraphU64_AddVec3(CVector3 *out, CVector3 *a, CVector3 *b);

extern void InstHdr_CopyActorPositionAndModel(void *actor, CVector3 target, void *arg4, s32 *arg5, s32 arg6, s32 arg7);

void func_8024BA7C_de(void *actor, Camera *camera, f32 *transform, u8 layer) {
    struct LevelActor *object = actor;
    f32 mf[16];
    s32 mtx;
    s32 matrices;
    Gfx *restore;
    Gfx *load;
    s32 offset;

    if (object->fieldB4 != 0) {
        mtx = Map_ReserveEntries(&D_8011FFB0, 1);
        if (mtx != 0) {
            matrices = camera->matrices;
            GraphU64_MultiplyMatrices(mf, transform, (f32 *)(matrices + 0x1E0));
            GraphU64_ClampMatrixToFixedRange(mf);
            GraphU64_PackFixedMatrix(mf, mtx);
            gSPMatrix(g_displayListCursor++, mtx, G_MTX_LOAD | G_MTX_PROJECTION);
            Geometry_DrawResourceModel(layer, camera->style, object->fieldB4, 1,
                          &object->lighting[D_800D297C], 0, object->field3);
            restore = g_displayListCursor++;
            offset = (D_800D297C << 6) + 0x380;
            gSPMatrix(restore, matrices + offset, G_MTX_LOAD | G_MTX_PROJECTION);
        }
    }
}

void GameObject_GetActorOffsetPositionAndModel(char *actor, CVector3 offset, void *arg4, s32 *arg5)
{
    CVector3 turned;
    CVector3 target;

    if (((ObjectLinks1DC_3 *)(actor))->unk_100 & 0x300000) {
        char *parent;

        offset.x = -offset.x;
        offset.z = -offset.z;
        parent = ((struct ObjRecAt5DC *) ((ObjectLinks1DC_3 *) actor)->unk_1D8)->unk5DC;
        if (parent != 0) {
            GraphU64_TransformPoint(parent + 0x160, &offset, &target);
        } else {
            func_8024BC94_de(&turned, actor, offset);
            GraphU64_AddVec3(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
        }
    } else {
        func_8024BC94_de(&turned, actor, offset);
        GraphU64_AddVec3(&target, &((ObjectLinks1DC_3 *)(actor))->unk_8, &turned);
    }
    InstHdr_CopyActorPositionAndModel(actor, target, arg4, arg5, 1, 1);
}
