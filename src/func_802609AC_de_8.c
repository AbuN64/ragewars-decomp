#include "span_1000/code_802609CC.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8044DA54_de_closed.h"
#include "span_1000/code_8027302C.h"
#include "types.h"

/* Switches an animation track to its pending clip when asked and the clip differs: keeps a copy of the track, loads the pending clip's resource and, when it is ready, reads its frame count and length, hands the old state to the previous track slot, restarts the track on the new clip and reports the switch; otherwise, or when not switching, it reloads the current clip and reports no switch. */



extern char D_0025F56C;

extern char D_800C41B0_de;

extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);

extern void *func_8025193C_de(s32, s32, s32, s32, s32, Anim *, void *, void *, s32);

extern s32 func_802624D8_de(Anim *);

extern void *func_8028FDB4_de(void *, s32);

static inline s32 load(Anim *anim, s32 table, s32 key, s32 id) {
    extern void *func_8026049C_de(Anim *);
    s32 size;
    s32 clip;
    void *header;

    if (id == -1) {
        anim->resource = 0;
        return 0;
    }
    clip = func_8028FE3C_de(table, key, id, &size);
    anim->resource = func_8025193C_de(0, clip, clip, size, 4, anim, &D_0025F56C, &D_800C41B0_de, 0);
    if (func_802624D8_de(anim) == 0) {
        return 0;
    }
    header = func_8026049C_de(anim);
    anim->frames = ((u16 *)func_8028FDB4_de(header, 0))[3];
    anim->current = id;
    anim->length = ((u16 *)func_8028FDB4_de(func_8028FDB4_de(header, 3), 0))[1];
    return 1;
}

extern void func_8025E5B0_de(void *,s32,f32,Vec3 *);

extern f32 D_800C41BC_de;

extern f32 D_800C41C0_de;

extern f32 D_800C41F0_de;

extern f32 D_800C41F4_de;

extern f64 D_800C41C8_de,D_800C41D0_de,D_800C41D8_de,D_800C41E0_de,D_800C41E8_de;

static __inline__ f64 unsignedDouble(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if ((s32)value<0) result+=*bias;
    return result;
}

static __inline__ f32 wrapAngle(AnimChannel *anim,f32 time) {
    extern void *func_8026049C_de(void *);
    s16 *keys;
    s32 first,next,last;
    keys=((AngleKeys *)func_8028FDB4_de(func_8026049C_de(anim),0))->keys;
    first=(s32)time;
    next=first+1;
    last=anim->frames-1;
    if(next<last) last=next;
    return func_80273EE4_de(time-(f32)first,(f32)keys[first]*D_800C41F0_de,(f32)keys[last]*D_800C41F0_de);
}

void func_80261670_de(Anim *anim, s32 table, s32 key, s32 blend, s32 *switched, Anim *previous) {
    s32 current;
    s32 next;
    Anim saved;

    current = anim->current;
    next = anim->next;
    if (next != current && blend != 0) {
        anim->active = 1;
        saved = *anim;
        if (load(anim, table, key, next)) {
            if (previous != 0) {
                *previous = saved;
                previous->current = current;
                previous->next = current;
                previous->active = 1;
            }
            anim->current = next;
            anim->next = next;
            anim->time = 0;
            anim->blending = 0;
            anim->active = 1;
            if (switched != 0) {
                *switched = 1;
            }
            return;
        }
        if (switched != 0) {
            *switched = 0;
        }
        load(anim, table, key, current);
        return;
    }
    if (switched != 0) {
        *switched = 0;
    }
    load(anim, table, key, current);
}

void func_8026193C_de(AnimChannel *arg0, Vec3 *arg1, f32 *arg2, RootActor *arg3) {
    extern void *func_8026049C_de(void *);
    Vec3 sp10;
    Vec3 sp20;
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fs1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv1;
    f32 var_fs1f;
    f64 var_fa0;
    f64 var_fv0f;
    f64 var_fv0f_2;
    f64 var_fv0f_3;
    f64 var_fv1;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s16 *temp_a2;
    s16 *temp_a2_2;
    s16 *temp_a2_3;
    s16 *temp_a2_4;
    s32 temp_fv1f;
    s32 temp_fv1f_2;
    s32 temp_fv1f_3;
    s32 temp_fv1f_4;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    RootClip *temp_s2;
    u16 temp_v1;
    u32 var_s0;
    s32 temp_s5;

    void *header;
    header = func_8026049C_de(arg0);
    arg1->x = 0.0f;
    arg1->y = 0.0f;
    arg1->z = 0.0f;
    *arg2 = 0.0f;
    if (arg3->flags & 0x08000000) {
        temp_fv0 = (f32) (arg0->frames - 1);
        arg0->time = temp_fv0;
        func_802476C8_de((char *)arg3, arg0, 0.0f, temp_fv0);
        arg3->flags = (s32) (arg3->flags & 0xF7FFFFFF);
    }
    temp_s2 = func_8028FDB4_de(header,3);
    temp_s2 = func_8028FDB4_de(temp_s2,0);
    func_8025E5B0_de(arg0, 0, arg0->time, &sp10);
    temp_fs0 = arg0->time;
    temp_a2 = ((AngleKeys *)func_8028FDB4_de(func_8026049C_de(arg0), 0))->keys;
    var_v1 = arg0->frames - 1;
    temp_fv1f = (s32) temp_fs0;
    temp_a0 = temp_fv1f + 1;
    if (temp_a0 < var_v1) {
        var_v1 = temp_a0;
    }
    temp_fs1 = D_800C41BC_de;
    var_fs1f = func_80273EE4_de(temp_fs0 - (f32) temp_fv1f, (f32) temp_a2[temp_fv1f] * temp_fs1, (f32) temp_a2[var_v1] * temp_fs1);
    temp_fv1 = arg0->time;
    if (!(arg3->flags & 0x08000000)) {
        arg0->time = (f32) (temp_fv1 + (D_800D2988 * temp_s2->rate * D_800C41C0_de));
    }
    func_802476C8_de((char *)arg3, arg0, temp_fv1, arg0->time);
    temp_s5 = arg0->frames - 1;
    temp_fs0f = (f32) temp_s5;
    if (temp_fs0f < arg0->time) {
        func_8025E5B0_de(arg0, 0, temp_fs0f, &sp20);
        temp_a2_2 = ((AngleKeys *)func_8028FDB4_de(func_8026049C_de(arg0), 0))->keys;
        temp_fv1f_2 = (s32) temp_fs0f;
        temp_a0_2 = temp_fv1f_2 + 1;
        var_v1_2 = arg0->frames - 1;
        if (temp_a0_2 < var_v1_2) {
            var_v1_2 = temp_a0_2;
        }
        temp_fs0 = func_80273EE4_de(temp_fs0f - (f32) temp_fv1f_2, (f32) temp_a2_2[temp_fv1f_2] * temp_fs1, (f32) temp_a2_2[var_v1_2] * temp_fs1);
        func_80271F34_de(arg1, arg1, &sp20);
        func_80271F68_de(arg1, arg1, &sp10);
        *arg2 += func_80273F94_de(temp_fs0, var_fs1f);
        temp_v1 = temp_s2->loopStart;
        var_s0 = 0;
        if (temp_v1 != 0xFFFF) {
            var_s0 = temp_v1;
        }
        var_fv1 = unsignedDouble(var_s0, &D_800C41C8_de);
        temp_fv0_2 = ((f32) var_fv1 + arg0->time) - temp_fs0f;
        arg0->time = temp_fv0_2;
        if (temp_fs0f < temp_fv0_2) {
            var_fv0f = unsignedDouble(var_s0, &D_800C41D0_de);
            arg0->time = (f32) var_fv0f;
        }
        if ((var_s0 >= (u32)temp_s5) && (arg0->current == arg0->next) && (func_802625C4_de(arg0) == 0)) {
            arg0->blending = 0;
        }
        var_fv0f_2 = unsignedDouble(var_s0, &D_800C41D8_de);
        func_802476C8_de((char *)arg3, arg0, (f32) var_fv0f_2, arg0->time);
        var_fv0f_3 = unsignedDouble(var_s0, &D_800C41E0_de);
        func_8025E5B0_de(arg0, 0, (f32) var_fv0f_3, &sp10);
        var_fs1f = wrapAngle(arg0,(f32)unsignedDouble(var_s0,&D_800C41E8_de));
        arg0->active = 1;
    }
    func_8025E5B0_de(arg0, 0, arg0->time, &sp20);
    temp_fs0 = arg0->time;
    temp_a2_4 = ((AngleKeys *)func_8028FDB4_de(func_8026049C_de(arg0), 0))->keys;
    var_v1_4 = arg0->frames - 1;
    temp_fv1f_4 = (s32) temp_fs0;
    temp_a0_4 = temp_fv1f_4 + 1;
    if (temp_a0_4 < var_v1_4) {
        var_v1_4 = temp_a0_4;
    }
    temp_fs0 = func_80273EE4_de(temp_fs0 - (f32) temp_fv1f_4, (f32) temp_a2_4[temp_fv1f_4] * D_800C41F4_de, (f32) temp_a2_4[var_v1_4] * D_800C41F4_de);
    func_80271F34_de(arg1, arg1, &sp20);
    func_80271F68_de(arg1, arg1, &sp10);
    *arg2 += func_80273F94_de(temp_fs0, var_fs1f);
}
