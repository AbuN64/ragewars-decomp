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

extern void func_8024796C_de(void *out, void *actor);

extern void func_80274244_de(void *arg0, void *arg1);



extern void func_802164A8_de(void *a, void *b);

extern void **func_8024BFD4_de(void *arg0, s32 arg1);


extern void func_80253754_de(void *arg0, void *arg1);

void *func_8024BC94_de(void *arg0, void *actor, struct IntPair arg2) {
    s32 sp10[4];
    s32 sp20[16];
    Triple sp60;

    func_8024796C_de(sp10, actor);
    func_80274244_de(sp10, sp20);
    func_80272898_de(sp20, &arg2, &sp60);
    *(Triple *)arg0 = sp60;
    return arg0;
}

s32 func_8024BD08_de(Shared_Func80243A80Actor *arg0) {
    CVector3 direction;
    Node75 *node;
    f32 upper;
    f32 upperNext;
    f32 lower;
    f32 lowerNext;
    f32 sine;
    f32 cosine;

    node = (void *)arg0->collision;
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
        if (upperNext < arg0->y) {
            return 0;
        }
        if (arg0->y < lowerNext) {
            return 0;
        }
        sine = func_802B7130_de(arg0->angle);
        cosine = func_802B6560_de(arg0->angle);
        func_80275BC8_de(&direction, node);
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

/** Thin wrapper forwarding arg0 and an offset of it to func_802164A8_de. */
void func_8024BE3C_de(void *base) {
    func_802164A8_de(base, (char *)base + 0x170);
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
    void **temp_s0;
    char *temp_v0;
    s32 result;

    result = -1;
    temp_s0 = func_8024BFD4_de(typedActor, ((LevelActor *)typedActor)->team);
    if (temp_s0 != 0) {
        temp_v0 = func_8028FDB4_de((int *)*temp_s0, 5);
        result = ((struct ActorFrameMetadata *)temp_v0)->renderMode;
        func_80253754_de(0, temp_s0);
    }
    return result;
}
