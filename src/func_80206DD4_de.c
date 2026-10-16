#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80206258.h"
#include "span_1000/code_80265370.h"
#include "types.h"
#include "stddef.h"
/* Places a rider along its path for the frame: clamps the throttle to 0..1 (eased through func_80265714_de unless the segment is linear), offsets its base by the segment's rise and circle point, moves the rider there through func_80271FC8_de, adds a bob to its height (one wave or a sum of four detuned waves by the segment's bob mode), applies its shake offsets, turns the actor by the segment's yaw mode (interpolated, constant spin unless held, or constant spin) and, for free segments, snaps the actor to the ground through func_80275DD4_de and func_802761EC_de. */


extern void func_80271FC8_de(Vec3 *, f32, Vec3 *, Vec3 *);
extern f32 func_80275DD4_de(s32, f32, f32);
extern void func_802761EC_de(s32, f32);
void func_80206DD4_de(Actor_func_80206DD4_de *actor, RiderCode80206258 *rider) {
    Vec3 point;
    SegmentRecAt5C *segment;
    f32 t;
    f32 phase;
    f32 amp;
    Vec3 *base;
    Actor_func_80206DD4_de *owner;
    t = rider->throttle;
    segment = (SegmentRecAt5C *)(actor->track + 0x14);
    if (t < 0.0f) {
        t = 0.0f;
    } else if (t > 1.0f) {
        t = 1.0f;
    }
    if (segment->linear == 0) {
        t = func_80265714_de(t);
    }
    owner = actor;
    point = rider->base;
    base = &rider->base;
    point.y += segment->rise;
    if (segment->moving != 0) {
        point.x += segment->radius * func_802B7130_de(segment->angle);
        point.z += segment->radius * func_802B6560_de(segment->angle);
    }
    func_80271FC8_de(&rider->pos, t, base, &point);
    switch (segment->bobMode) {
    case 0:
        rider->pos.y += segment->bob * func_802B7130_de(rider->phase);
        break;
    case 1:
        phase = rider->phase;
        amp = 0.25f;
        rider->pos.y += segment->bob * (func_802B7130_de(phase) * amp);
        rider->pos.y += segment->bob * (func_802B7130_de(phase * 1.1f) * amp);
        rider->pos.y += segment->bob * (func_802B7130_de(phase * 1.2f) * amp);
        rider->pos.y += segment->bob * (func_802B7130_de(phase * 1.3f) * amp);
        break;
    }
    rider->pos.x += rider->shake.x;
    rider->pos.y += rider->shake.y;
    rider->pos.z += rider->shake.z;
    switch (segment->yawMode) {
    case 0:
        owner->yaw = rider->baseYaw + t * ((rider->baseYaw + segment->yaw) - rider->baseYaw);
        break;
    case 1:
        if (rider->flags & 0x400) {
            break;
        }
    case 2:
        owner->yaw += segment->yaw * 0.06666667f;
        break;
    }
    if (segment->moving == 0) {
        func_802761EC_de(owner->model, func_80275DD4_de(owner->model, owner->x, owner->z) + rider->pos.y - owner->y);
    }
}
/* Steers an actor along path nodes, blending direction, speed and orientation as it advances waypoints. */
/* The values func_802070D0_de loads by address:
 * 0x800C6C18 = 3.0 (float, D_800C6C18 in this cartridge's tables)
 * 0x800C6C1C = 10.24 (float, unnamed in this cartridge's tables)
 * 0x800C6C20 = 1.0 (float, D_800C6C20 in this cartridge's tables)
 * 0x800C6C24 = 1.0 (float, unnamed in this cartridge's tables)
 * 0x800C6C28 = 1.0 (float, D_800C6C28 in this cartridge's tables)
 * 0x800C6C2C = 3.1415927 (float, D_800C6C2C in this cartridge's tables)
 * 0x800C6C30 = 0.5 (float, D_800C6C30 in this cartridge's tables)
 * 0x800C6C34 = 0.3 (float, D_800C6C34 in this cartridge's tables)
 * 0x800C6C38 = 15.0 (float, D_800C6C38 in this cartridge's tables)
 * 0x800D2988 = 1.0 (float, D_800D2988 in this cartridge's tables; not a literal: a variable, its value in the image, since D_800D2988: `swc1` at %lo(D_800D2988) in func_80213ED4_de.s)
 * 0x800C6C3C = 1.0 (float, D_800C6C3C in this cartridge's tables)
 * 0x800C6C40 = 3.1415927 (float, D_800C6C40 in this cartridge's tables)
 * 0x800C6C44 = 0.5 (float, D_800C6C44 in this cartridge's tables)
 * 0x800C6C48 = 2.670354 (float, D_800C6C48 in this cartridge's tables)
 * 0x800C6C4C = 0.5 (float, unnamed in this cartridge's tables)
 * 0x800C6C50 = 1.0 (float, D_800C6C50 in this cartridge's tables)
 * 0x800C6C54 = 0.017453294 (float, unnamed in this cartridge's tables)
 * 0x800C6C58 = 0.017453294 (float, D_800C6C58 in this cartridge's tables)
 * 0x800C6C5C = 0.1 (float, unnamed in this cartridge's tables)
 * 0x800C6C60 = 0.017453294 (float, D_800C6C60 in this cartridge's tables)
 * 0x800C6C64 = 0.017453294 (float, unnamed in this cartridge's tables)
 * 0x800C6C68 = 0.1 (float, D_800C6C68 in this cartridge's tables)
 * 0x800C6C6C = 0.017453294 (float, D_800C6C6C in this cartridge's tables)
 * 0x800C6C70 = 0.017453294 (float, D_800C6C70 in this cartridge's tables)
 * 0x800C6C74 = 0.1 (float, unnamed in this cartridge's tables)
 */
void func_80216808_de(void *, s32, f32, f32);
void func_802192C0_de(void *);
struct Cursor;
void * func_80219408_de(struct Cursor *);
void *func_80219434_de(struct Cursor *);
void func_80271F68_de(void *, void *, void *);
void func_8027207C_de(f32 *);

f32 func_802B72B0_de(f32);
f32 func_80216F44_de(void *, Vec3); /* extern */
extern f32 D_800D2988;
/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x68, 0x6c], gap at: 0x5c. */
/* Steers an actor along path nodes, blending direction, speed and orientation as it advances waypoints. */
void func_802070D0_de(func_802070D0_S3 *arg0, func_802070D0_S1 *arg1) {
    Triple initial;
    Vec3 vec0;
    Vec3 vec1;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 temp_f1_5;
    f32 temp_f1_6;
    f32 temp_f1_7;
    f32 temp_f1_8;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 arg0_2;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 var_f1;
    f32 var_f3;
    u16 temp_v1;
    func_802070D0_S2 *temp_s2;
    void *temp_s3;
    func_802070D0_S2 *temp_v0;
    temp_s3 = (void *) &arg1->unk94;
    temp_v0 = func_80219408_de(temp_s3);
    initial = temp_v0->pos;
    func_80271F68_de(&vec0, &initial, &arg0->unk8);
    temp_s2 = func_80219434_de(temp_s3);
    temp_f2 = func_802B72B0_de(vec0.x * vec0.x + vec0.y * vec0.y + vec0.z * vec0.z);
    var_f1 = temp_v0->unk1C;
    temp_f20 = temp_s2->unk20;
    if (var_f1 < 3.0f) {
        var_f1 = 3.0f;
    }
    if (temp_f2 <= var_f1 * 10.24f) {
        arg1->unk14C = 0.0f;
        temp_s2->unk14.half = (u16) (temp_s2->unk14.half & 0x7FFF);
        func_802192C0_de(temp_s3);
        arg1->unk140 = (f32) arg1->unk150;
        arg1->unk144 = (f32) arg1->unk154;
        arg1->unk148 = (f32) arg1->unk158;
        arg1->unk15C = (f32) arg1->unk134;
        arg0_2 = arg0->unk6C;
        arg1->unk164 = (f32) arg1->unk138;
        arg1->unk160 = (f32) arg0_2;
        return;
    }
    if (temp_s2->unk14.half & 2) {
        temp_f1 = arg1->unk14C;
        if (temp_f1 <= 0.0f) {
            arg1->unk14C = temp_f20;
        } else {
            temp_f0 = temp_f1 + temp_f20;
            arg1->unk14C = temp_f0;
            if (temp_f0 > 1.0f) {
                arg1->unk14C = 1.0f;
            }
        }
        if (temp_s2 == temp_v0) {
            func_80271F68_de(&vec1, temp_s2, &arg0->unk8);
        } else {
            func_80271F68_de(&vec1, temp_v0, temp_s2);
        }
        func_8027207C_de(&vec1);
        ;
        vec1.x = arg1->unk140 + arg1->unk14C * (vec1.x - arg1->unk140);
        temp_f2_3 = arg1->unk144;
        vec1.y = temp_f2_3 + arg1->unk14C * (vec1.y - temp_f2_3);
        temp_f2_4 = arg1->unk148;
        vec1.z = temp_f2_4 + arg1->unk14C * (vec1.z - temp_f2_4);
        func_8027207C_de(&vec1);
        if (arg1->unk14C >= 1.0f) {
            goto block_17;
        }
    } else {
        func_8027207C_de(&vec0);
        ;
        vec1.x = arg1->unk140 + temp_f20 * (vec0.x - arg1->unk140);
        temp_f1_3 = arg1->unk144;
        vec1.y = temp_f1_3 + temp_f20 * (vec0.y - temp_f1_3);
        temp_f1_4 = arg1->unk148;
        vec1.z = temp_f1_4 + temp_f20 * (vec0.z - temp_f1_4);
        func_8027207C_de(&vec1);
        block_17:
        arg1->unk140 = vec1.x;
        arg1->unk144 = vec1.y;
        arg1->unk148 = vec1.z;
    }
    arg1->unk150 = vec1.x;
    arg1->unk154 = vec1.y;
    arg1->unk158 = vec1.z;
    temp_v1 = temp_s2->unk14.half;
    if (temp_v1 & 1) {
        if (arg1->unk168 > 0.0f && !(temp_v1 & 0x8000)) {
            var_f3 = arg1->unk168 + (func_802B6560_de((1.0f - temp_s2->unk30) * 3.1415927f) + 1.0f) * (-arg1->unk168 * 0.5f);
            if (var_f3 <= 0.3f) {
                arg1->unk16C = (f32) (temp_s2->unk34 * 15.0f);
                var_f3 = 0.0f;
                temp_s2->unk14.half = (u16) (temp_s2->unk14.half | 0x8000);
            }
        } else {
            temp_f1_5 = arg1->unk16C;
            var_f3 = 0.0f;
            if (temp_f1_5 > 0.0f) {
                temp_f0_2 = temp_f1_5 - D_800D2988;
                arg1->unk16C = temp_f0_2;
                if (temp_f0_2 <= 0.0f) {
                    arg1->unk16C = 0.0f;
                }
            } else if (temp_f1_5 == 0.0f) {
                var_f3 = arg1->unk168 + (func_802B6560_de((1.0f - temp_s2->unk30) * 3.1415927f) + 1.0f) * ((temp_s2->unk24 - arg1->unk168) * 0.5f);
            }
        }
    } else {
        var_f3 = arg1->unk168 + (func_802B6560_de(2.670354f) + 1.0f) * ((temp_s2->unk24 - arg1->unk168) * 0.5f);
    }
    if (arg0->unk38 & 8) {
        var_f3 = 0.0f;
    }
    arg1->unk168 = var_f3;
    arg1->unk54 = (f32) (arg0->unk8.v1 + vec1.x * var_f3 * D_800D2988);
    arg1->unk58 = (f32) (arg0->unkC + vec1.y * var_f3 * D_800D2988);
    temp_f1_5 = vec1.z;
    arg1->unk5C = (f32) (arg0->unk10 + temp_f1_5 * var_f3 * D_800D2988);
    if (temp_s2->unk14.half & 8) {
        if ((temp_s2->unk14.word & 0x420000) == 0x420000) {
            temp_f2_5 = arg1->unk160;
            arg0->unk6C = (f32) (temp_f2_5 + arg1->unk14C * (temp_s2->unk10 * 0.017453294f - temp_f2_5));
        } else {
            temp_f1_6 = arg0->unk6C;
            arg0->unk6C = (f32) (temp_f1_6 + (temp_s2->unk10 * 0.017453294f - temp_f1_6) * 0.1f);
        }
    } else {
        func_80216808_de(arg0, (s32) arg1, 10.0f, func_80216F44_de(arg0, *(Vec3 *) &arg1->unk54));
    }
    if (temp_s2->unk14.half & 4) {
        if ((temp_s2->unk14.word & 0x220000) == 0x220000) {
            temp_f2_6 = arg1->unk15C;
            arg1->unk134 = (f32) (temp_f2_6 + arg1->unk14C * (temp_s2->unk28 * 0.017453294f - temp_f2_6));
        } else {
            temp_f1_7 = arg1->unk134;
            arg1->unk134 = (f32) (temp_f1_7 + (temp_s2->unk28 * 0.017453294f - temp_f1_7) * 0.1f);
        }
    }
    if (temp_s2->unk14.half & 0x10) {
        if ((temp_s2->unk14.word & 0x820000) == 0x820000) {
            temp_f2_7 = arg1->unk164;
            arg1->unk138 = (f32) (temp_f2_7 + arg1->unk14C * (temp_s2->unk2C * 0.017453294f - temp_f2_7));
            return;
        }
        temp_f1_8 = (*arg1).unk138;
        arg1->unk138 = (f32) (temp_f1_8 + (temp_s2->unk2C * 0.017453294f - temp_f1_8) * 0.1f);
    }
}
/** Perform no operation. */
void func_80207730_de(void) {
}
