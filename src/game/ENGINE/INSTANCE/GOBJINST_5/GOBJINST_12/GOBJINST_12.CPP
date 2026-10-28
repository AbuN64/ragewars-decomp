#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "particle/80271B18_3.H"
#include "ENGINE/INSTANCE/GOBJINST_13.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "RENDER_4/8028FD2C_6.H"

/* GOBJINST_12.CPP */
/* Draws an actor's attached model: when the actor has one, allocates a matrix from the pool D_8011FFB0,
 * fills it with the given transform multiplied by the camera matrix (GraphU64_MultiplyMatrices, GraphU64_ClampMatrixToFixedRange,
 * GraphU64_PackFixedMatrix), loads it into the display list, draws the model through Geometry_DrawResourceModel with the
 * actor's per-frame state for the current frame, then reloads the camera's per-frame matrix. */

extern s32 Map_ReserveEntries(void *, s32);

extern void GraphU64_ClampMatrixToFixedRange(f32 *);

extern void GraphU64_PackFixedMatrix(f32 *, s32);

/* Moves an actor toward a point given relative to it: the offset is turned by the actor's facing and added to its position (or, for a mirrored actor with a parent, negated in x and z and transformed by the parent's matrix at 0x160), then passed to InstHdr_CopyActorPositionAndModel with both final flags set. */

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

void Gobjinst_GetActorOffsetPositionAndModel(char *actor, CVector3 offset, void *arg4, s32 *arg5)
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

/* GOBJINST_13.CPP */
extern CQuatern func_8024796C_de(void *actor);

extern void MatrixFromQuaternion(void *arg0, void *arg1);

extern void Barrel_UpdateActorController(void *a, void *b);

extern void **Gobjinst_RequestAnimatedModelVariant(void *arg0, s32 arg1);

extern void Cache_UnlockResource(void *arg0, void *arg1);

CVector3 *func_8024BC94_de(CVector3 *outVector, void *actor, CVector3 localVector) {
    CQuatern aimOrientation;
    s32 aimMatrix[16];
    CVector3 transformedVector;

    aimOrientation = func_8024796C_de(actor);
    MatrixFromQuaternion(&aimOrientation, aimMatrix);
    GraphU64_TransformPoint(aimMatrix, &localVector, &transformedVector);
    *outVector = transformedVector;
    return outVector;
}

s32 func_8024BD08_de(Shared_Func80243A80Actor *actor) {
    CVector3 direction;
    Node75 *node;
    f32 upper;
    f32 upperNext;
    f32 lower;
    f32 lowerNext;
    f32 sine;
    f32 cosine;

    node = (void *)actor->collision;
    if (node != 0) {
        upper = node->cur->y;
        if (node->prev->y <= upper) {
        } else {
            upper = node->prev->y;
        }
        upperNext = node->next->y;
        if (upper <= upperNext) {
        } else {
            upperNext = upper;
        }
        lower = node->cur->y;
        if (lower <= node->prev->y) {
        } else {
            lower = node->prev->y;
        }
        lowerNext = node->next->y;
        if (lowerNext <= lower) {
        } else {
            lowerNext = lower;
        }
        if (upperNext < actor->y) {
            return 0;
        }
        if (actor->y < lowerNext) {
            return 0;
        }
        sine = Math_Sinf(actor->angle);
        cosine = Math_Cosf(actor->angle);
        Region_GetNodeEdgeCross(&direction, node);
        if (direction.x * -sine + direction.z * -cosine < 0.0f) {
            return 1;
        }
    }
    return 0;
}

/** Return the global float at D_800C8C44. */

float func_8024BE2C_de(void) {
    return D_800C8C44;
}

/** Thin wrapper forwarding arg0 and an offset of it to Barrel_UpdateActorController. */
void func_8024BE3C_de(void *base) {
    Barrel_UpdateActorController(base, (char *)base + 0x170);
}

/** Set or clear status bit two according to the supplied boolean. */
void func_8024BE58_de(void *object, int enabled) {
    ObjRecAt2E0 *object_record = object;
    unsigned int *flags = &object_record->unk2E0;
    if (enabled) {
        *flags |= 2;
    } else {
        *flags &= ~2U;
    }
}

s32 func_8024BE80_de(void *typedActor) {
    void **modelResource;
    char *modelMetadata;
    s32 result;

    result = -1;
    modelResource = Gobjinst_RequestAnimatedModelVariant(typedActor, ((LevelActor *)typedActor)->team);
    if (modelResource != 0) {
        modelMetadata = SetN64_GetPackSection((int *)*modelResource, 5);
        result = ((struct ActorFrameMetadata *)modelMetadata)->renderMode;
        Cache_UnlockResource(0, modelResource);
    }
    return result;
}
