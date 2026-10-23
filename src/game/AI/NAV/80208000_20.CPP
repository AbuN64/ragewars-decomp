#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/ACTORREC.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"

extern f32 func_8029DD3C_de(f32);


f32 func_80285630_de(s32 arg0);

s32 func_8020E674_de(ActorRec *actor, f32 scale, f32 lateral);

extern char D_80103FD0;

extern World *D_80103FCC;

extern s32 func_802444A4_de(InstanceHdr *arg0, CVector3 current, CVector3 desired,
                          void *collisionInfo);

/* Refine a launch angle by testing a ballistic arc against the destination.
 * State 0 initializes the bounds; later calls bisect the chosen quadrant. */
s32 func_8020DDF4_eu(ActorRec *actor) {
    CVector3 current;
    CVector3 delta;
    s32 first, last;
    s32 keyCount;
    BallisticInstance *instance;
    BallisticInstance *temp_v0_5;
    f32 temp_fs0_2;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 scale;
    f32 temp_ft0;
    f32 lateral;
    f32 temp_fv0_4;
    f32 temp_fv0f;
    f32 temp_fv0f_2;
    f32 temp_fv1;
    f32 temp_fv1_4;
    f32 temp_fv1_5;
    f32 temp_fv1f;
    f32 temp_fv1f_2;
    f32 temp_fv1f_3;
    s32 trajectoryMode;
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

    trajectoryMode = actor->instance->trajectoryMode;
    var_s2 = 0;
    if (trajectoryMode != actor->field26C) {
        actor->field268 = 0;
        actor->field26C = (s32) trajectoryMode;
    }
    if (actor != 0) {
        temp_v1 = actor->field268;
        if (temp_v1 == 0) {
            instance = actor->instance;
            current = instance->header.spatial.position;
            delta = actor->destination;
            temp_fv1f = delta.x - current.x;
            temp_fv1 = delta.y - current.y;
            temp_fv0f = delta.z - current.z;
            delta.x = temp_fv1f;
            delta.y = temp_fv1;
            delta.z = temp_fv0f;
            actor->field264 = func_802B72B0_de((temp_fv1f * temp_fv1f) + (temp_fv1 * temp_fv1) + (temp_fv0f * temp_fv0f));
            temp_fs1 = delta.y;
            delta.y = 0;
            temp_fs0f = func_802B72B0_de((delta.x * delta.x) + (delta.z * delta.z));
            {
                switch (trajectoryMode) {
                case 10:
                case 12:
                    actor->field268 = 1;
                    actor->field270 = 1;
                    actor->field274 = 0;
                    break;
                case 6:
                case 8:
                    actor->field268 = 0xB;
                    actor->field270 = 0;
                    actor->field274 = 1;
                    break;
                case 9:
                    actor->field268 = 1;
                    actor->field270 = 1;
                    actor->field274 = 1;
                    break;
                default:
                case 7:
                case 11:
                if (temp_fs0f == 0.0f) {
                    if (temp_fs1 < 0.0f) {
                        actor->field248 = (f32) -90.0f;
                    } else {
                        actor->field248 = (f32) 90.0f;
                    }
                } else {
                    actor->field248 = (f32) (func_8029C044_de(temp_fs1, temp_fs0f) * 57.2957764f);
                }
                actor->field270 = 0;
                actor->field274 = 0;
                actor->field24C = actor->field248;
                actor->field254 = actor->field250 = 0.0f;
                return 1;
                }
                    if (temp_fs0f == 0.0f) {
                        if (temp_fs1 < 0.0f) {
                            actor->field278 = -90.0f;
                        } else {
                            actor->field278 = 90.0f;
                        }
                    } else {
                        actor->field278 = func_8029C044_de(temp_fs1, temp_fs0f) * 57.2957764f;
                    }
                    actor->field24C = actor->field278;
                    if (45.0f < actor->field278) {
                        actor->field284 = 0;
                    } else {
                        var_v0 = 1;
                        if (!(actor->field278 > 0.0f)) {
                            var_v0 = 2;
                            if (!(-45.0f < actor->field278)) {
                                var_v0 = 3;
                            }
                        }
                        actor->field284 = var_v0;
                    }
                    actor->field27C = 90.0f - ((f32) actor->field284 * 45.0f);
                    actor->field280 = actor->field278;
                    actor->field278 = (actor->field27C + actor->field280) * 0.5f;
                    if (actor->field270 != 0) {
                        actor->field24C = actor->field278;
                    }
                    return 0;
            }
        } else {
            if (temp_v1 < 0xB) {
                switch (trajectoryMode) {
                case 2: var_s2 = 0x12E; break;
                case 9: var_s2 = 0x12E; break;
                case 10: var_s2 = 0x12E; break;
                case 12: var_s2 = 0x12E; break;
                }
            } else if (temp_v1 < 0x15) {
                actor->field270 = 0;
                switch (trajectoryMode) {
                case 6: var_s2 = 0x12E; break;
                case 8: var_s2 = 0x12E; break;
                case 9: var_s2 = 0x12E; break;
                }
            } else {
                goto block_88;
            }
            {
block_43:
                if (actor->field268 < 0x15) {
                    temp_s0_2 = D_8013D534;
                    temp_v0_2 = (void *)func_8028FDB4_de(temp_s0_2, 1);
                    keyCount = temp_v0_2->count;
                    if (func_80265550_de(temp_v0_2->keys, keyCount, var_s2, &first, &last) == 0) {
                        actor->field270 = 0;
                        actor->field274 = 0;
                        actor->field268 = 0;
                        return 1;
                    }
                    {
                        BallisticResourceRecords *records = (void *)func_8028FDB4_de(temp_s0_2, 2);
                        temp_s0_3 = records->records;
                        temp_s0_3 += first;
                    }
                    temp_v0_3 = temp_s0_3->unk30;
                    scale = func_80285630_de((temp_v0_3->speedHi << 0x10) | temp_v0_3->speedLo);
                    temp_v0_4 = temp_s0_3->unk30;
                    lateral = func_80285630_de((temp_v0_4->gravityHi << 0x10) | temp_v0_4->gravityLo);
                    temp_v0_5 = actor->instance;
                    current = temp_v0_5->header.spatial.position;
                    delta = actor->destination;
                    temp_ft0 = delta.x - current.x;
                    temp_fv1f_2 = delta.y - current.y;
                    temp_fv1_4 = delta.z - current.z;
                    delta.x = temp_ft0;
                    delta.y = temp_fv1f_2;
                    delta.z = temp_fv1_4;
                    actor->field264 = func_802B72B0_de((temp_ft0 * temp_ft0) + (temp_fv1f_2 * temp_fv1f_2) + (temp_fv1_4 * temp_fv1_4));
                    temp_fs1 = delta.y;
                    delta.y = 0;
                    temp_fs0f = func_802B72B0_de((delta.x * delta.x) + (delta.z * delta.z));
                    temp_fv0_4 = func_802B6560_de(actor->field278 * 0.0174532942f);
                    temp_fs0_2 = temp_fv0_4 * temp_fv0_4;
                    temp_fv0f_2 = (func_8029DD3C_de(actor->field278 * 0.0174532942f) * temp_fs0f) + ((lateral * (temp_fs0f * temp_fs0f)) / (2.0f * (scale * scale) * temp_fs0_2));
                    if (((temp_fs1 - 1.0f) <= temp_fv0f_2) && (temp_fv0f_2 <= (temp_fs1 + 1.0f))) {
                        if (func_8020E674_de(actor, scale, lateral) != 0) {
                            temp_v0_6 = actor->field284;
                            if (temp_v0_6 > 0) {
                                actor->field284--;
                                actor->field27C = (f32) (90.0f - ((f32) actor->field284 * 45.0f));
                                actor->field280 = (f32) (45.0f - ((f32) actor->field284 * 45.0f));
                                if (actor->field270 != 0) {
                                    actor->field268 = 1;
                                } else {
                                    actor->field268 = 0xB;
                                }
block_54:
                                return 0;
                            }
                        }
                        if ((actor->field270 != 0) && (actor->field274 != 0)) {
                            actor->field268 = 0xB;
                            actor->field270 = 0;
                            actor->field250 = (f32) (actor->field278 - actor->field248);
                            temp_fv1f_3 = actor->field24C;
                            if (45.0f < temp_fv1f_3) {
                                actor->field284 = 0;
                            } else {
                                var_v0_4 = 1;
                                if (!(temp_fv1f_3 > 0.0f)) {
                                    var_v0_4 = 2;
                                    if (!(-45.0f < temp_fv1f_3)) {
                                        var_v0_4 = 3;
                                    }
                                }
                                actor->field284 = var_v0_4;
                            }
                            actor->field27C = (f32) (90.0f - ((f32) actor->field284 * 45.0f));
                            actor->field280 = (f32) (45.0f - ((f32) actor->field284 * 45.0f));
                            return 0;
                        }
                        actor->field270 = 0;
                        actor->field274 = 0;
                        actor->field268 = (s32) (actor->field268 + 1);
                        actor->field250 = (f32) (actor->field278 - actor->field248);
                        return 1;
                    }
                    temp_v1_3 = actor->field268 + 1;
                    if (temp_v1_3 == 0xB) {
                        temp_fv1_5 = actor->field24C;
                        actor->field270 = 0;
                        actor->field268 = (s32) (actor->field268 + 1);
                        actor->field250 = (f32) (actor->field278 - actor->field248);
                        if (45.0f < temp_fv1_5) {
                            actor->field284 = 0;
                        } else {
                            var_v0_5 = 1;
                            if (!(temp_fv1_5 > 0.0f)) {
                                var_v0_5 = 2;
                                if (!(-45.0f < temp_fv1_5)) {
                                    var_v0_5 = 3;
                                }
                            }
                            actor->field284 = var_v0_5;
                        }
                        actor->field27C = (f32) (90.0f - ((f32) actor->field284 * 45.0f));
                        actor->field280 = (f32) (45.0f - ((f32) actor->field284 * 45.0f));
                        if (actor->field274 == 0) {
                            actor->field268 = 0;
                        }
                        return actor->field274 == 0;
                    }
                    if (temp_v1_3 >= 0x15) {
                        actor->field270 = 0;
                        actor->field274 = 0;
                        actor->field268 = (s32) (actor->field268 + 1);
                        actor->field254 = (f32) (actor->field278 - actor->field24C);
                        return 1;
                    }
                    if (temp_fv0f_2 < (temp_fs1 - 1.0f)) {
                        switch (actor->field284) {
                        case 0: actor->field27C = actor->field278; break;
                        case 1: case 2: case 3: actor->field280 = actor->field278; break;
                        }
                    } else {
                        switch (actor->field284) {
                        case 0: actor->field280 = actor->field278; break;
                        case 1: case 2: case 3: actor->field27C = actor->field278; break;
                        }
                    }
                    actor->field268 = (s32) (actor->field268 + 1);
                    actor->field278 = (actor->field27C + actor->field280) * 0.5f;
                    return 0;
                }
                goto block_88;
            }
block_88:
            actor->field268 = 0;
            actor->field270 = 0;
            actor->field274 = 0;
            /* Duplicate return node #89. Try simplifying control flow for better match */
            return 1;
        }
    } else {
        return 1;
    }
}

s32 func_8020E674_de(ActorRec *actor, f32 scale, f32 lateral) {
    CVector3 current;
    CVector3 desired;
    CVector3 delta;
    CVector3 acceleration;
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

#if defined(VERSION_DE)
unsigned int rodata_unresolved_8020EA04[3] = {
    0x6F857BAC, 0x71EB24F7, 0xCE54520A,
};
#endif
