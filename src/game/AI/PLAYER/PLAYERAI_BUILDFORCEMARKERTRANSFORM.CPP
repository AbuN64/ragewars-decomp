#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER/WEAPON_INITIALIZECHARGEANDSTARTUPCUES_DATA.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECV5.H"
#include "TYPES.H"

extern void Graphu64_SubtractVectors(CVector3 *, CVector3 *, CVector3 *);

extern void BuildDirectionMatrix(Matrix *, CVector3 *);

extern void Graphu64_ScaleVector(CVector3 *out, CVector3 *in, f32 scale);

extern void Graphu64_AddVec3(CVector3 *result, CVector3 *left, CVector3 *right);

extern void TranslateMatrix(Matrix *object, f32 x, f32 y, f32 z);

extern void SwapMatrixUpForward(Matrix *object);

extern void Graphu64_ConvertMatrixToFixed(Matrix *src, void *dst);

extern s32 Scene_FindModelIdIndex(struct Shared_World *world, s32 arg1);

extern s32 Scene_GetIndexedModelResource(void *world, s32 type);

extern void Geometry_QueueDirectModel(s32 model, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void *func_8022B304_de(ForcePlayerList *forcePlayerList, void *position) {
    CVector3 markerDelta;
    Shared_ActorView *node;
    void *bestNode;
    f32 bestDist;
    f32 distSq;

    node = (Shared_ActorView *)forcePlayerList->head;
    bestDist = 0.0f;
    bestNode = 0;
    if (node != 0) {
        do {
            if (node->actorState != 0 &&
                node->marker.time != 0.0f) {
                Graphu64_SubtractVectors(&markerDelta, position, &node->targetPosition);
                distSq = markerDelta.x * markerDelta.x + markerDelta.y * markerDelta.y + markerDelta.z * markerDelta.z;
                if (bestNode == 0 || distSq < bestDist) {
                    bestNode = node;
                    bestDist = distSq;
                }
            }
            node = node->next;
        } while (node != 0);
    }
    return bestNode;
}

void Playerai_BuildForceMarkerTransform(char *actorView, s32 unused1, CVector3 *direction) {
    Shared_ActorView *actor = (Shared_ActorView *)actorView;
    Matrix matrix;
    CVector3 offset;

    BuildDirectionMatrix(&matrix, direction);
    Graphu64_ScaleVector(&offset, direction, 5.12f);
    Graphu64_AddVec3(&offset, &offset, &actor->targetPosition);
    TranslateMatrix(&matrix, offset.x, offset.y, offset.z);
    SwapMatrixUpForward(&matrix);
    Graphu64_ConvertMatrixToFixed(&matrix, actor->transform1600);
}

/** Report whether the floating field at offset 0x11FC is positive. */
int func_8022B460_de(char *object) {
    Shared_ActorView *actor = (void *)object;
    return actor->marker.time > 0.0f;
}

void func_8022B484_de(char *player) {
    ObjRecAt120C *object = player;
    s32 index;

    if (object->unk120C != 0) {
        index = Scene_FindModelIdIndex(&g_world, 0xC84);
    } else {
        index = Scene_FindModelIdIndex(&g_world, 0xC85);
    }
    if (index != -1) {
        Geometry_QueueDirectModel(Scene_GetIndexedModelResource(&g_world, index),
                      (s32)((Shared_ActorView *)player)->transform1600, (s32)&D_800D0EF8, 0, -1);
    }
}

void func_8022B510_de(s32 player) {
    s32 effectIndex;
    void *effectBase;
    effectIndex = 4;
    effectBase = player + 0x60;
    do {
        (((struct IntegerState1250 *) ((s8 *) effectBase))->unk_124C) = 0;
        effectIndex -= 1;
        effectBase -= 0x18;
    } while (effectIndex >= 0);
}

void func_8022B530_de(s32 playerAddress) {
    s32 effectIndex;
    void *effectBase;
    effectIndex = 4;
    effectBase = playerAddress + 0x60;
    do {
        (((struct IntegerState1250 *) ((s8 *) effectBase))->unk_124C) = 0;
        effectIndex -= 1;
        effectBase -= 0x18;
    } while (effectIndex >= 0);
}

/* Starts a timer in the first of the object's five 24-byte slots at 0x1248 whose remaining time is not
   positive: records the kind, target, a zero elapsed value and the tag, sets the duration to rate
   times D_800C7E00 and the step to target over duration. */





void func_8022B550_de(Obj_func_8022B550_de *obj, float target, float rate, int kind, int tag) {
    int i;

    for (i = 0; i < 5; i++) {
        Timer *t = &obj->timers[i];
        if (t->m_FramesRemaining <= 0.0f) {
            t->kind = kind;
            t->m_TotalDamage = target;
            t->m_DamageIssued = 0.0f;
            t->m_bIsInflator = tag;
            t->m_FramesRemaining = rate * D_800C7E00;
            do {
                t->m_DamagePerFrame = target / t->m_FramesRemaining;
                return;
            } while (0);
        }
    }
}
