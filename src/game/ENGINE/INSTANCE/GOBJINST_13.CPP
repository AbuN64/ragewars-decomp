#include "COMMON/ACTORRESOURCEHEADER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEGACY_COLLISION_ACTOR.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GOBJINST_13.H"
#include "particle/80271B18_3.H"
#include "RENDER_4/8028FD2C_6.H"

extern CQuatern func_8024796C_de(void *actor);

extern void MatrixFromQuaternion(void *arg0, void *arg1);



extern void Barrel_UpdateActorController(void *a, void *b);

extern void **func_8024BFD4_de(void *arg0, s32 arg1);


extern void Cache_UnlockResource(void *arg0, void *arg1);

void *func_8024BC94_de(void *outVector, void *actor, struct IntPair localVector) {
    CQuatern aimOrientation;
    s32 aimMatrix[16];
    Triple transformedVector;

    aimOrientation = func_8024796C_de(actor);
    MatrixFromQuaternion(&aimOrientation, aimMatrix);
    GraphU64_TransformPoint(aimMatrix, &localVector, &transformedVector);
    *(Triple *)outVector = transformedVector;
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
    modelResource = func_8024BFD4_de(typedActor, ((LevelActor *)typedActor)->team);
    if (modelResource != 0) {
        modelMetadata = SetN64_GetPackSection((int *)*modelResource, 5);
        result = ((struct ActorFrameMetadata *)modelMetadata)->renderMode;
        Cache_UnlockResource(0, modelResource);
    }
    return result;
}
