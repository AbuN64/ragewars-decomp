#include "COMMON/INTEGERSTATE1250.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJRECV5.H"
#include "TYPES.H"

extern void func_80271F68_de(CVector3 *, CVector3 *, CVector3 *);

extern void func_80273198_de(Matrix *, CVector3 *);

extern void func_80271F9C_de(CVector3 *out, CVector3 *in, f32 scale);

extern void func_80271F34_de(CVector3 *result, CVector3 *left, CVector3 *right);

extern void func_80273448_de(Matrix *object, f32 x, f32 y, f32 z);

extern void func_80273D6C_de(Matrix *object);

extern void func_8027027C_de(Matrix *src, void *dst);

extern s32 func_8028B21C_de(struct Shared_World *arg0, s32 arg1);

extern s32 func_8028C198_de(void *arg0, s32 arg1);

extern void func_8026DF30_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

void *func_8022B304_de(ForcePlayerList *forcePlayerList, void *arg1) {
    CVector3 sp10;
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
                node->field11FC != 0.0f) {
                func_80271F68_de(&sp10, arg1, &node->targetPosition);
                distSq = sp10.x * sp10.x + sp10.y * sp10.y + sp10.z * sp10.z;
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

void func_8022B3D0_de(char *actorView, s32 unused1, CVector3 *arg2) {
    Shared_ActorView *actor = (Shared_ActorView *)actorView;
    Matrix matrix;
    CVector3 offset;

    func_80273198_de(&matrix, arg2);
    func_80271F9C_de(&offset, arg2, 5.12f);
    func_80271F34_de(&offset, &offset, &actor->targetPosition);
    func_80273448_de(&matrix, offset.x, offset.y, offset.z);
    func_80273D6C_de(&matrix);
    func_8027027C_de(&matrix, actor->transform1600);
}

/** Report whether the floating field at offset 0x11FC is positive. */
int func_8022B460_de(char *object) {
    Shared_ActorView *actor = (void *)object;
    return actor->field11FC > 0.0f;
}

void func_8022B484_de(char *arg0) {
    ObjRecAt120C *object = arg0;
    s32 index;

    if (object->unk120C != 0) {
        index = func_8028B21C_de(&D_8011FE88, 0xC84);
    } else {
        index = func_8028B21C_de(&D_8011FE88, 0xC85);
    }
    if (index != -1) {
        func_8026DF30_de(func_8028C198_de(&D_8011FE88, index),
                      (s32)((Shared_ActorView *)arg0)->transform1600, (s32)&D_800D0EF8, 0, -1);
    }
}

void func_8022B510_de(s32 player) {
    s32 var_v0;
    void *var_a0;
    var_v0 = 4;
    var_a0 = player + 0x60;
    do {
        (((struct IntegerState1250 *) ((s8 *) var_a0))->unk_124C) = 0;
        var_v0 -= 1;
        var_a0 -= 0x18;
    } while (var_v0 >= 0);
}

void func_8022B530_de(s32 arg0) {
    s32 var_v0;
    void *var_a0;
    var_v0 = 4;
    var_a0 = arg0 + 0x60;
    do {
        (((struct IntegerState1250 *) ((s8 *) var_a0))->unk_124C) = 0;
        var_v0 -= 1;
        var_a0 -= 0x18;
    } while (var_v0 >= 0);
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
