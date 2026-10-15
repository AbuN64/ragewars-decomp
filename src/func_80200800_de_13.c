#include "span_1000/code_80200610.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "shared/gameplay_reactions.h"
#include "shared/world.h"
#include "span_1000/code_802022E0.h"
#include "types.h"

extern s32 func_80285F58_de(void *arg0, void *arg1);

extern void func_80203C40_de(void *arg0, void *arg1, s32 arg2);

extern void func_80202CA0_de(s32 *, f32 *);

extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);

extern void func_80272BCC_de(f32 *, Vec3 *, Vec3 *);

extern void func_80271F34_de(Vec3 *, Vec3 *, Vec3 *);

static inline void build_rotation(struct RotationObject *object, f32 *matrix) {
    extern void func_80274244_de(s32 *, f32 *);
    s32 rotation[4];
    f32 angles[3];

    angles[0] = object->angleX;
    angles[1] = object->angleY;
    angles[2] = object->angleZ;
    func_80202CA0_de(rotation, angles);
    func_80274244_de(rotation, matrix);
}


extern void func_80273C68_de(void *arg0, f32 arg1);

/* Returns whether a player may act on a target: never on its own linked object or an inactive
   target, always when the team rule D_801468C4 is off, otherwise only across different teams. */




extern int D_801468C4;

void func_80203C84_de(void *arg0, WeaponFireState *arg1, s32 arg2) {
    extern void func_80214178_de(void *arg0, void *arg1, s32 arg2);
    if ((func_80285F58_de(&D_8011FE88, arg0) == 0) &&
        (arg1->variant == 0)) {
        func_80203C40_de(arg0, arg1, arg2);
        func_80214178_de(arg0, arg1, 1);
    }
}

void func_80203CFC_de(void *unused0, struct RotationObject *arg1, s32 arg2) {
    extern void func_80274244_de(void *, void *);
    s32 sp10[4];
    f32 sp20[3];

    sp20[0] = arg1->angleX;
    sp20[1] = arg1->angleY;
    sp20[2] = arg1->angleZ;
    func_80202CA0_de(sp10, sp20);
    func_80274244_de(sp10, (void *)arg2);
}

void func_80203D4C_de(void *unused, struct RotationObject *object, Vec3 *pivot, Vec3 *point) {
    f32 matrix[16];
    Vec3 offset;

    build_rotation(object, matrix);
    func_80271F68_de(&offset, point, pivot);
    func_80272BCC_de(matrix, &offset, point);
    func_80271F34_de(point, point, pivot);
}

void func_80203DF0_de(void *arg0, ObjRecAt8V1 *event) {
    ObjRecAt294 *temp_a0;
    SegmentRecAt71 *temp_s1;
    ObjRecAt294 *temp_v0;

    struct NavigationTrack *track;

    temp_a0 = event->unk8;
    track = (void *)temp_a0->unk18;
    temp_s1 = &track->segment;
    if (event->unk4 == temp_s1->yawEvent) {
        func_802738C0_de(arg0, temp_a0->unk294);
    }
    if (event->unk4 == temp_s1->orientationMode) {
        temp_v0 = event->unk8;
        func_80273C68_de(arg0,
                      temp_v0->targetHeading -
                          temp_v0->heading);
    }
}

void func_80203E78_de(void *arg0, void *arg1, void *arg2) {
    extern s32 func_80214178_de(void *, void *, s32);
    s32 var_v1;

    var_v1 = ((Dest *)arg1)->health - ((Shared_DamageEvent *)arg2)->damage;
    if (var_v1 < 0) {
        var_v1 = 0;
    }
    ((Dest *)arg1)->health = var_v1;
    if (var_v1 == 0) {
        func_80214178_de(arg0, arg1, 0x40);
    }
}

int func_80203EB0_de(Actor *self, int unused, Actor *target) {
    Actor *linked = self->linked;
    if (linked == target || target->active == 0) {
        return 0;
    }
    if (D_801468C4 != 0) { if (linked->info->team == target->info->team) { return 0; } } return 1;
}
