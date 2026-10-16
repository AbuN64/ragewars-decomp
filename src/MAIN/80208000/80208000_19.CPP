#include "span_1000/code_80208000.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/unused.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_8020D370.h"
#include "TYPES.H"

extern f32 func_8029DD3C_de(f32);

s32 func_80265550_de(u32 *arg0, s32 arg1, u32 arg2, s32 *arg3, s32 *arg4);

f32 func_80285630_de(s32 arg0);

s32 func_8020E674_de(ActorRec *actor, f32 scale, f32 lateral);

extern char D_80103FD0;

extern World *D_80103FCC;

extern s32 func_802444A4_de(InstanceHdr *arg0, Vec3 current, Vec3 desired,
                          void *collisionInfo);

/* Refine a launch angle by testing a ballistic arc against the destination.
 * State 0 initializes the bounds; later calls bisect the chosen quadrant. */
s32 func_8020DDF4_eu(ActorRec *arg0) {
    Vec3 current;
    Vec3 delta;
    s32 first, last;
    s32 keyCount;
    BallisticInstance *temp_v0;
    BallisticInstance *temp_v0_5;
    f32 temp_fs0_2;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fs1f;
    f32 temp_ft0;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1f;
    f32 temp_fv1f_2;
    f32 temp_fv1f_3;
    s32 temp_s0;
    s32 *temp_s0_2;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_3;
    s32 var_v0;
    s32 var_v0_4;
    s32 var_v0_5;
    BallisticResourceKeys *temp_v0_2;
    u32 var_s2;
    BallisticParamsHolder *temp_s0_3;
    BallisticParams *temp_v0_3;
    BallisticParams *temp_v0_4;

    temp_s0 = arg0->instance->trajectoryMode;
    var_s2 = 0;
    if (temp_s0 != arg0->field26C) {
        arg0->field268 = 0;
        arg0->field26C = (s32) temp_s0;
    }
    if (arg0 != 0) {
        temp_v1 = arg0->field268;
        if (temp_v1 == 0) {
            temp_v0 = arg0->instance;
            current = temp_v0->header.spatial.position;
            delta = arg0->destination;
            temp_fv1f = delta.x - current.x;
            temp_fv1 = delta.y - current.y;
            temp_fv0f = delta.z - current.z;
            delta.x = temp_fv1f;
            delta.y = temp_fv1;
            delta.z = temp_fv0f;
            arg0->field264 = func_802B72B0_de((temp_fv1f * temp_fv1f) + (temp_fv1 * temp_fv1) + (temp_fv0f * temp_fv0f));
            temp_fs1 = delta.y;
            delta.y = 0;
            temp_fs0f = func_802B72B0_de((delta.x * delta.x) + (delta.z * delta.z));
            {
                switch (temp_s0) {
                case 10:
                case 12:
                    arg0->field268 = 1;
                    arg0->field270 = 1;
                    arg0->field274 = 0;
                    break;
                case 6:
                case 8:
                    arg0->field268 = 0xB;
                    arg0->field270 = 0;
                    arg0->field274 = 1;
                    break;
                case 9:
                    arg0->field268 = 1;
                    arg0->field270 = 1;
                    arg0->field274 = 1;
                    break;
                default:
                case 7:
                case 11:
                if (temp_fs0f == 0.0f) {
                    if (temp_fs1 < 0.0f) {
                        arg0->field248 = (f32) -90.0f;
                    } else {
                        arg0->field248 = (f32) 90.0f;
                    }
                } else {
                    arg0->field248 = (f32) (func_8029C044_de(temp_fs1, temp_fs0f) * 57.2957764f);
                }
                arg0->field270 = 0;
                arg0->field274 = 0;
                arg0->field24C = arg0->field248;
                arg0->field254 = arg0->field250 = 0.0f;
                return 1;
                }
                    if (temp_fs0f == 0.0f) {
                        if (temp_fs1 < 0.0f) {
                            arg0->field278 = -90.0f;
                        } else {
                            arg0->field278 = 90.0f;
                        }
                    } else {
                        arg0->field278 = func_8029C044_de(temp_fs1, temp_fs0f) * 57.2957764f;
                    }
                    arg0->field24C = arg0->field278;
                    if (45.0f < arg0->field278) {
                        arg0->field284 = 0;
                    } else {
                        var_v0 = 1;
                        if (!(arg0->field278 > 0.0f)) {
                            var_v0 = 2;
                            if (!(-45.0f < arg0->field278)) {
                                var_v0 = 3;
                            }
                        }
                        arg0->field284 = var_v0;
                    }
                    arg0->field27C = 90.0f - ((f32) arg0->field284 * 45.0f);
                    arg0->field280 = arg0->field278;
                    arg0->field278 = (arg0->field27C + arg0->field280) * 0.5f;
                    if (arg0->field270 != 0) {
                        arg0->field24C = arg0->field278;
                    }
                    return 0;
            }
        } else {
            if (temp_v1 < 0xB) {
                switch (temp_s0) {
                case 2: var_s2 = 0x12E; break;
                case 9: var_s2 = 0x12E; break;
                case 10: var_s2 = 0x12E; break;
                case 12: var_s2 = 0x12E; break;
                }
            } else if (temp_v1 < 0x15) {
                arg0->field270 = 0;
                switch (temp_s0) {
                case 6: var_s2 = 0x12E; break;
                case 8: var_s2 = 0x12E; break;
                case 9: var_s2 = 0x12E; break;
                }
            } else {
                goto block_88;
            }
            {
block_43:
                if (arg0->field268 < 0x15) {
                    temp_s0_2 = D_8013D534;
                    temp_v0_2 = (void *)func_8028FDB4_de(temp_s0_2, 1);
                    keyCount = temp_v0_2->count;
                    if (func_80265550_de(temp_v0_2->keys, keyCount, var_s2, &first, &last) == 0) {
                        arg0->field270 = 0;
                        arg0->field274 = 0;
                        arg0->field268 = 0;
                        return 1;
                    }
                    {
                        BallisticResourceRecords *records = (void *)func_8028FDB4_de(temp_s0_2, 2);
                        temp_s0_3 = records->records;
                        temp_s0_3 += first;
                    }
                    temp_v0_3 = temp_s0_3->unk30;
                    temp_fs1f = func_80285630_de((temp_v0_3->speedHi << 0x10) | temp_v0_3->speedLo);
                    temp_v0_4 = temp_s0_3->unk30;
                    temp_fv0_3 = func_80285630_de((temp_v0_4->gravityHi << 0x10) | temp_v0_4->gravityLo);
                    temp_v0_5 = arg0->instance;
                    current = temp_v0_5->header.spatial.position;
                    delta = arg0->destination;
                    temp_ft0 = delta.x - current.x;
                    temp_fv1f_2 = delta.y - current.y;
                    temp_fv1_4 = delta.z - current.z;
                    delta.x = temp_ft0;
                    delta.y = temp_fv1f_2;
                    delta.z = temp_fv1_4;
                    arg0->field264 = func_802B72B0_de((temp_ft0 * temp_ft0) + (temp_fv1f_2 * temp_fv1f_2) + (temp_fv1_4 * temp_fv1_4));
                    temp_fs1 = delta.y;
                    delta.y = 0;
                    temp_fs0f = func_802B72B0_de((delta.x * delta.x) + (delta.z * delta.z));
                    temp_fv0_4 = func_802B6560_de(arg0->field278 * 0.0174532942f);
                    temp_fs0_2 = temp_fv0_4 * temp_fv0_4;
                    temp_fv0f_2 = (func_8029DD3C_de(arg0->field278 * 0.0174532942f) * temp_fs0f) + ((temp_fv0_3 * (temp_fs0f * temp_fs0f)) / (2.0f * (temp_fs1f * temp_fs1f) * temp_fs0_2));
                    if (((temp_fs1 - 1.0f) <= temp_fv0f_2) && (temp_fv0f_2 <= (temp_fs1 + 1.0f))) {
                        if (func_8020E674_de(arg0, temp_fs1f, temp_fv0_3) != 0) {
                            temp_v0_6 = arg0->field284;
                            if (temp_v0_6 > 0) {
                                arg0->field284--;
                                arg0->field27C = (f32) (90.0f - ((f32) arg0->field284 * 45.0f));
                                arg0->field280 = (f32) (45.0f - ((f32) arg0->field284 * 45.0f));
                                if (arg0->field270 != 0) {
                                    arg0->field268 = 1;
                                } else {
                                    arg0->field268 = 0xB;
                                }
block_54:
                                return 0;
                            }
                        }
                        if ((arg0->field270 != 0) && (arg0->field274 != 0)) {
                            arg0->field268 = 0xB;
                            arg0->field270 = 0;
                            arg0->field250 = (f32) (arg0->field278 - arg0->field248);
                            temp_fv1f_3 = arg0->field24C;
                            if (45.0f < temp_fv1f_3) {
                                arg0->field284 = 0;
                            } else {
                                var_v0_4 = 1;
                                if (!(temp_fv1f_3 > 0.0f)) {
                                    var_v0_4 = 2;
                                    if (!(-45.0f < temp_fv1f_3)) {
                                        var_v0_4 = 3;
                                    }
                                }
                                arg0->field284 = var_v0_4;
                            }
                            arg0->field27C = (f32) (90.0f - ((f32) arg0->field284 * 45.0f));
                            arg0->field280 = (f32) (45.0f - ((f32) arg0->field284 * 45.0f));
                            return 0;
                        }
                        arg0->field270 = 0;
                        arg0->field274 = 0;
                        arg0->field268 = (s32) (arg0->field268 + 1);
                        arg0->field250 = (f32) (arg0->field278 - arg0->field248);
                        return 1;
                    }
                    temp_v1_3 = arg0->field268 + 1;
                    if (temp_v1_3 == 0xB) {
                        temp_fv1_5 = arg0->field24C;
                        arg0->field270 = 0;
                        arg0->field268 = (s32) (arg0->field268 + 1);
                        arg0->field250 = (f32) (arg0->field278 - arg0->field248);
                        if (45.0f < temp_fv1_5) {
                            arg0->field284 = 0;
                        } else {
                            var_v0_5 = 1;
                            if (!(temp_fv1_5 > 0.0f)) {
                                var_v0_5 = 2;
                                if (!(-45.0f < temp_fv1_5)) {
                                    var_v0_5 = 3;
                                }
                            }
                            arg0->field284 = var_v0_5;
                        }
                        arg0->field27C = (f32) (90.0f - ((f32) arg0->field284 * 45.0f));
                        arg0->field280 = (f32) (45.0f - ((f32) arg0->field284 * 45.0f));
                        if (arg0->field274 == 0) {
                            arg0->field268 = 0;
                        }
                        return arg0->field274 == 0;
                    }
                    if (temp_v1_3 >= 0x15) {
                        arg0->field270 = 0;
                        arg0->field274 = 0;
                        arg0->field268 = (s32) (arg0->field268 + 1);
                        arg0->field254 = (f32) (arg0->field278 - arg0->field24C);
                        return 1;
                    }
                    if (temp_fv0f_2 < (temp_fs1 - 1.0f)) {
                        switch (arg0->field284) {
                        case 0: arg0->field27C = arg0->field278; break;
                        case 1: case 2: case 3: arg0->field280 = arg0->field278; break;
                        }
                    } else {
                        switch (arg0->field284) {
                        case 0: arg0->field280 = arg0->field278; break;
                        case 1: case 2: case 3: arg0->field27C = arg0->field278; break;
                        }
                    }
                    arg0->field268 = (s32) (arg0->field268 + 1);
                    arg0->field278 = (arg0->field27C + arg0->field280) * 0.5f;
                    return 0;
                }
                goto block_88;
            }
block_88:
            arg0->field268 = 0;
            arg0->field270 = 0;
            arg0->field274 = 0;
            /* Duplicate return node #89. Try simplifying control flow for better match */
            return 1;
        }
    } else {
        return 1;
    }
}

s32 func_8020E674_de(ActorRec *actor, f32 scale, f32 lateral) {
    Vec3 current;
    Vec3 desired;
    Vec3 delta;
    Vec3 acceleration;
    f32 invDuration;
    f32 total;
    f32 segment;
    f32 elapsed;
    f32 accelScale;
    f32 accelX;
    f32 accelY;
    f32 accelZ;
    s32 count;
    s32 i;

    if (actor == 0 || actor->field264 == 0.0f) {
        return 0;
    }

    invDuration = D_800C1E40_de / actor->field264;
    delta.x = (actor->field258 - actor->instance->header.spatial.position.x) * invDuration;
    delta.x *= scale * func_802B6560_de(actor->field278);
    delta.z = (actor->field260 - actor->instance->header.spatial.position.z) * invDuration;
    delta.z *= scale * func_802B6560_de(actor->field278);
    delta.y = scale * func_802B7130_de(actor->field278);

    acceleration.x = 0.0f;
    acceleration.y = lateral;
    acceleration.z = 0.0f;

    total = (scale * func_802B6560_de(actor->field278)) / actor->field264;
    if (total == 0.0f) {
        return 0;
    }
    count = (s32)(total * D_800C1E44_de);
    if (count == 0) {
        return 0;
    }

    segment = total / (f32)count;
    current = actor->instance->header.spatial.position;
    accelScale = segment * segment * D_800C1E48_de;
    accelX = acceleration.x * accelScale;
    accelY = acceleration.y * accelScale;
    accelZ = acceleration.z * accelScale;

    desired.x = current.x + delta.x * segment + accelX;
    desired.y = current.y + delta.y * segment + accelY;
    desired.z = current.z + delta.z * segment + accelZ;

    elapsed = segment;

    if (func_802444A4_de(&actor->instance->header, current, desired, &D_80103FD0) != 0 &&
        (unsigned)(D_80103FCC->state - 7) >= 2) {
        return 1;
    }

    i = 0;
    delta.x += acceleration.x * elapsed;
    delta.y += acceleration.x * elapsed;
    delta.z += acceleration.x * elapsed;
    elapsed += segment;

    while (i < count) {
        current = desired;
        desired.x = current.x + delta.x * elapsed + accelX;
        desired.y = current.y + delta.y * elapsed + accelY;
        desired.z = current.z + delta.z * elapsed + accelZ;

        if (func_802444A4_de(&actor->instance->header, current, desired, &D_80103FD0) != 0 &&
            (unsigned)(D_80103FCC->state - 7) >= 2) {
            return 1;
        }

        delta.x += acceleration.x * elapsed;
        delta.y += acceleration.x * elapsed;
        delta.z += acceleration.x * elapsed;
        elapsed += segment;
        i++;
    }
    return 0;
}
