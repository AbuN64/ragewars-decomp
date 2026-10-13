#include "common/unused.h"
#include "shared/motion_step.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80243A80.h"
#include "types.h"

extern void func_8023E6D0_de(void *arg0, f32 arg1);
extern void func_8023EBD4_de(void *arg0);
extern void func_8023E838_de(void *arg0);
extern s32 func_8023D158_de(void *arg0);
extern void func_8023E45C_de(void *arg0);
extern s32 func_8023D380_de(void *arg0);






s32 func_802444A4_de(char *arg0, Vec3 arg1, Vec3 arg2, s32 arg3) {
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E6D0_de(work.data, 0.0f);
    out = work.data;
    vectors.first = arg1;
    vectors.second = arg2;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct Actor_func_8024A7A0_de *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = (MotionSurface *)arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

extern void func_8023E6D0_de(void *arg0, f32 arg1);
extern void func_8023EBD4_de(void *arg0);
extern void func_8023E838_de(void *arg0);
extern s32 func_8023D158_de(void *arg0);
extern void func_8023E45C_de(void *arg0);
extern s32 func_8023D380_de(void *arg0);






s32 func_802446E0_de(char *arg0, Vec3 arg1, Vec3 arg2, s32 arg3,
                   f32 arg4) {
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E6D0_de(work.data, arg4);
    out = work.data;
    vectors.first = arg1;
    vectors.second = arg2;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct Actor_func_8024A7A0_de *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = (MotionSurface *)arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

extern void func_8023E690_de(void *arg0, Vec3 arg1, f32 arg2);
extern void func_8023EBD4_de(void *arg0);
extern void func_8023E838_de(void *arg0);
extern s32 func_8023D158_de(void *arg0);
extern void func_8023E45C_de(void *arg0);
extern s32 func_8023D380_de(void *arg0);






s32 func_8024491C_de(char *arg0, Vec3 arg1, Vec3 arg2, s32 arg3,
                  Vec3 arg4, f32 arg5) {
    Work80244494 work;
    VectorPair vectors;
    char *object = arg0;
    char *out;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023E690_de(work.data, arg4, arg5);
    out = work.data;
    vectors.first = arg1;
    vectors.second = arg2;
    func_8023EBD4_de(out);
    if (vectors.first.x == vectors.second.x &&
        vectors.first.y == vectors.second.y &&
        vectors.first.z == vectors.second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct Actor_func_8024A7A0_de *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = vectors.first;
    ((struct ActorMotion *)(out))->end = vectors.second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = (MotionSurface *)arg3;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}

extern void func_8023EBD4_de(void *arg0);
extern void func_8023E838_de(void *arg0);
extern s32 func_8023D158_de(void *arg0);
extern void func_8023E45C_de(void *arg0);
extern s32 func_8023D380_de(void *arg0);






s32 func_80244B68_de(char *arg0, char *arg1, Vec3 first, Vec3 second,
                   s32 arg4) {
    char *object = arg0;
    char *out = arg1;
    s32 count;
    s32 active;
    s32 result;
    s32 next;
    s32 maximum;
    s32 flags;

    func_8023EBD4_de(out);
    if (first.x == second.x && first.y == second.y && first.z == second.z) {
        return 0;
    }

    D_800CB418_de += 1;
    maximum = D_800CB41C_de;
    next = D_800CB418_de;
    if (next < maximum) {
        next = maximum;
    }
    D_800CB41C_de = next;

    ((struct ActorMotion *)(out))->actor = object;
    if (object != 0) {
        s32 value = 0;
        if (*(u8 *)object == 1) {
            flags = ((struct Actor_func_8024A7A0_de *)(object))->flags;
            flags &= 0x300000;
            value = flags != 0;
        }
        ((struct ActorMotion *)(out))->actorFlags = value;
    } else {
        ((struct ActorMotion *)(out))->actorFlags = 0;
    }

    ((struct ActorMotion *)(out))->start = first;
    ((struct ActorMotion *)(out))->end = second;
    ((struct ActorMotion *)(out))->grounded = 0;
    ((struct ActorMotion *)(out))->candidate = 0;
    ((struct ActorMotion *)(out))->candidateIndex = 0;
    ((struct ActorMotion *)(out))->orientationActive = 0;
    ((struct ActorMotion *)(out))->iteration = 0;
    ((struct ActorMotion *)(out))->surface = arg4;
    ((struct ActorMotion *)(out))->queryFlags = 0;
    ((struct ActorMotion *)(out))->horizontalTicks = 0;
    ((struct ActorMotion *)(out))->verticalTicks = 0;
    func_8023E838_de(out);

    active = 1;
    count = 0;
    do {
        if (func_8023D158_de(out) != 0) {
            func_8023E45C_de(out);
            count += 1;
            result = func_8023D380_de(out);
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->interpolated;
            ((struct ActorMotion *)(out))->end = ((struct ActorMotion *)(out))->position;
            ((struct ActorMotion *)(out))->orientation = ((struct ActorMotion *)(out))->projectedOrientation;
            active -= 1;
        } else {
            result = 0;
            ((struct ActorMotion *)(out))->start = ((struct ActorMotion *)(out))->end;
            active -= 1;
        }
    } while (result != 0 && active != 0);
    return count;
}
