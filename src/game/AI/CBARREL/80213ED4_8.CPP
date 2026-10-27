#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"

extern void Barrel_StopActorLoopingSound(void);
extern void Nav_ApplySupportingPlatformMotion(SourceBarrelUpdateActorController *, DestBarrelUpdateActorController *);
extern void Nav_UpdateActorStateAnimation(SourceBarrelUpdateActorController *, DestBarrelUpdateActorController *);

void Barrel_UpdateActorController(SourceBarrelUpdateActorController *src, DestBarrelUpdateActorController *dst) {
    if ((dst->aux != 0) && (dst->aux->unkC == -1)) {
        Barrel_StopActorLoopingSound();
    }
    if (dst->timer != 0) {
        dst->timer--;
        D_800D2988 = 0.0f;
        return;
    }
    if ((src->active != 0) && (src->kind != 0)) {
        if (*src->kind == 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
        dst->position = src->position;
        dst->value += D_800D2988;
        if (src->flags & 0x10000) {
            Nav_ApplySupportingPlatformMotion(src, dst);
        }
        if (dst->callback != 0) {
            dst->callback(src, dst);
        }
        Nav_UpdateActorStateAnimation(src, dst);
        if (*src->kind != 2) {
            dst->old_position = src->position;
            dst->height = src->height;
        }
    }
}
