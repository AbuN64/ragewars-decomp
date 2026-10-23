#include "include_asm.h"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/UNUSED.H"
#include "AUDIO/8025A3EC.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON.H"
#include "COMMON/GAMEPLAY_CAMERA.H"

#ifdef NON_MATCHING
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "AUDIO/EXTERNS.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SHAREDRECV4.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
int func_80245784_de(void);
f32 func_80274808_de(f32 arg0, f32 arg1, f32 arg2);
void func_802B2F10_de(void *arg0, s16 arg1);




extern f32 D_800C3F4C_de;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x30, 0x34], gap at: 0x24. */
void func_8025A3CC_de(View_func_8025AE1C_de *arg0) {
    ContextCode8025A3EC *temp_a0;
    ContextCode8025A3EC *temp_v1_2;
    ContextCode8025A3EC *temp_v1_7;
    ObjRecAt40V2 *temp_s0;
    ObjRecAt40V2 *temp_s1;
    f32 temp_fa1;
    f32 temp_fv0;
    f32 temp_fv0_2;
    f32 temp_fv0_3;
    f32 temp_fv0_4;
    f32 temp_fv1;
    f32 temp_fv1f;
    f32 var_fa1;
    f32 var_fs0;
    f32 var_fs0f;
    f32 var_fv0;
    f32 var_fv0_2;
    f32 var_fv0f;
    f32 var_fv0f_2;
    f32 var_fv0f_3;
    s32 temp_ft0;
    s32 temp_v0;
    s32 temp_v1_3;
    s32 temp_v1_6;
    s32 var_condition_bit;
    s32 var_s0;
    s8 temp_v1;
    s8 temp_v1_5;
    void *temp_v0_2;
    void *temp_v1_4;

    temp_fv0 = *((f32 *) ((u8 *) (arg0->context->result) + 1320));
    var_condition_bit = temp_fv0 < D_800C3F38_de;
    var_fv0f = temp_fv0;
    if (temp_fv0 < D_800C3F38_de) {
        var_fv0f = D_800C3F38_de;
        var_condition_bit = temp_fv0 < D_800C3F38_de;
    }
    if (var_condition_bit) {
        var_fv0f_2 = var_fv0f * D_800C3F38_de;
    } else {
        var_fv0f_2 = var_fv0f * temp_fv0;
    }
    D_800D0D10 = var_fv0f_2;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    temp_v1 = (*((s8 *) ((u8 *) arg0 + 84)));
    switch (temp_v1) {                              /* irregular */
    case 2:
        var_fv0 = D_800C3F3C_de;
block_10:
        D_800D0D10 = var_fv0f_2 + (var_fv0f_2 * var_fv0);
        break;
    case 1:
        var_fv0 = D_800C3F40_de;
        goto block_10;
    }
    temp_v1_2 = arg0->context;
    if (arg0->flags & 0x200) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_fs0f = *((f32 *) ((u8 *) (temp_v1_2) + 11176));
    } else {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        var_fs0f = *((f32 *) ((u8 *) (temp_v1_2) + 11168));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if ((*((s32 *) ((u8 *) (arg0) + 196)) != 0) && (*((s32 *) ((u8 *) (temp_v1_2) + 11192)) != 0)) {
            var_fs0f *= D_800C3F44_de;
        }
    }
    temp_v1_3 = arg0->flags;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    if ((temp_v1_3 & 0x400) && (*((s32 *) ((u8 *) (arg0) + 192)) == 0) && (temp_v1_4 = &arg0->frame + 0x34, ((temp_v1_3 & 0x800) == 0))) {
        temp_v0 = arg0->context->result;
        temp_fv1 = *((f32 *) ((u8 *) (&arg0->frame) + 52)) - ((f32 *) temp_v0)[296 / sizeof(f32)];
        temp_v0_2 = temp_v0 + 0x128;
        temp_fv1f = ((f32 *) temp_v1_4)[4 / sizeof(f32)] - ((f32 *) temp_v0_2)[4 / sizeof(f32)];
        temp_fv0_2 = ((f32 *) temp_v1_4)[8 / sizeof(f32)] - ((f32 *) temp_v0_2)[8 / sizeof(f32)];
        temp_fv0_3 = (temp_fv1 * temp_fv1) + (temp_fv1f * temp_fv1f) + (temp_fv0_2 * temp_fv0_2);
        if (!(D_800D0D10 <= temp_fv0_3)) {
            var_fa1 = D_800C3F48_de - (temp_fv0_3 / D_800D0D10);
        } else {
            var_fa1 = 0.0f;
        }
        temp_v1_5 = *((s8 *) ((u8 *) (&arg0->frame) + 68));
        if (temp_v1_5 != 1) {
            if (temp_v1_5 < 2) {
                if (temp_v1_5 != 0) {
                    goto block_32;
                }
                temp_fa1 = var_fa1 * var_fa1;
                var_fa1 = temp_fa1 * temp_fa1;
                goto block_31;
            }
            var_fs0 = var_fa1;
            if (temp_v1_5 == 2) {

            } else {
block_32:
                var_fs0 = 0.0f;
            }
        } else {
block_31:
            var_fs0 = var_fa1 * var_fa1;
        }
        if (func_80245784_de() == 0) {
            *((f32 *) ((u8 *) (&arg0->frame) + 28)) = var_fs0;
        } else {
            *((f32 *) ((u8 *) (&arg0->frame) + 28)) = func_80274808_de(*((f32 *) ((u8 *) (&arg0->frame) + 28)), var_fs0, 0.017f);
        }
    } else {
        *((f32 *) ((u8 *) (&arg0->frame) + 28)) = (f32) D_800C3F4C_de;
    }
    temp_v1_6 = arg0->flags;
    if (temp_v1_6 & 4) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        if ((*((s16 *) ((u8 *) arg0 + 124))) > 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            (*((s16 *) ((u8 *) arg0 + 124))) = (u16) (*((s16 *) ((u8 *) arg0 + 124))) - 1;
        } else {
            var_s0 = 0;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            if ((*((f32 *) ((u8 *) arg0 + 132))) < 0.0f) {
                var_s0 = 1;
            }
            if (var_s0 != 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                if ((*((f32 *) ((u8 *) arg0 + 128))) < func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120))))) {
                    goto block_47;
                }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
            } else if (func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120)))) < (*((f32 *) ((u8 *) arg0 + 128)))) {
block_47:
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                (*((f32 *) ((u8 *) arg0 + 128))) -= (*((f32 *) ((u8 *) arg0 + 132)));
                if (var_s0 != 0) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    if (func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120)))) < (*((f32 *) ((u8 *) arg0 + 128)))) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                        (*((f32 *) ((u8 *) arg0 + 128))) = func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120))));
                    }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                } else if ((*((f32 *) ((u8 *) arg0 + 128))) < func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120))))) {
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    temp_fv0_4 = func_802B2350((s32) (*((u16 *) ((u8 *) arg0 + 120))));
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                    (*((f32 *) ((u8 *) arg0 + 128))) = temp_fv0_4;
                    if (temp_fv0_4 == 0.0f) {
                        temp_a0 = arg0->context;
                        arg0->done = 1;
                        arg0->tracked = NULL;
                        temp_s0 = (void *) ((u8 *) &temp_a0->slots + 8);
                        if (arg0->frame != temp_a0->frame) {
                            func_802B2F00_de(temp_s0, temp_a0->slots.ids[arg0->slot]);
                            if (func_802B2620_de(temp_s0) != 0) {
                                alSndpStop(temp_s0);
                            }
                            arg0->handle = -1;
                        }
                    }
                }
            }
        }
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
        temp_ft0 = (s32) (func_802B2350((s32) *((u16 *) ((u8 *) (arg0) + 116))) * (*((f32 *) ((u8 *) arg0 + 128))));
        var_fv0_2 = (f32) temp_ft0 * *((f32 *) ((u8 *) (&arg0->frame) + 28));
        *((s32 *) ((u8 *) (&arg0->frame) + 8)) = temp_ft0;
    } else {
        if (temp_v1_6 & 0x400) {
            var_fv0f_3 = *((f32 *) ((u8 *) (&arg0->frame) + 28));
        } else {
            var_fv0f_3 = *((f32 *) ((u8 *) (&arg0->frame) + 32));
        }
        var_fv0_2 = (f32) *((s32 *) ((u8 *) (&arg0->frame) + 8)) * var_fv0f_3;
    }
    temp_v1_7 = arg0->context;
    temp_s1 = (void *) ((u8 *) &temp_v1_7->slots + 8);
    func_802B2F00_de(temp_s1, temp_v1_7->slots.ids[arg0->slot]);
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
    func_802B2F10_de(temp_s1, (s16) (s32) ((f32) (s32) (var_fv0_2 * var_fs0f) * *((f32 *) ((u8 *) (arg0) + 200))));
}
#else
INCLUDE_ASM("span_1000", func_8025A3CC_de);
#endif

/* Updates a voice pan from its sweep, position or centered fallback and applies it to the owner sound. */

extern s32 func_80258D2C_de(OwnerCode8025A3EC *);
extern s16 func_80259B10_de(void *, GameplayCamera *);

extern void func_802B2F00_de(void *, s16);
extern void alSndpSetPan(void *, s32);

static inline void apply_pan(Voice_func_8025A844_de *voice, u8 pan) {
    OwnerCode8025A3EC *owner = voice->owner;
    char *sound = owner->sound;

    func_802B2F00_de(sound, owner->samples[voice->index]);
    alSndpSetPan(sound, pan);
}

void func_8025A844_de(Voice_func_8025A844_de *voice) {
    s32 rising;
    ParamsRecAt18 *params;

    params = &voice->params;
    if (func_80258D2C_de(voice->owner) == 0) {
        apply_pan(voice, 0x40);
        return;
    }
    if (voice->sweeping != 0) {
        if (voice->delay > 0) {
            voice->delay--;
        } else {
            rising = 0;
            if (voice->step < 0.0f) {
                rising = 1;
            }
            if (rising ? voice->value < RW_BITS_TO_FLOAT(voice->target) : RW_BITS_TO_FLOAT(voice->target) < voice->value) {
                voice->value -= voice->step;
                if (rising) {
                    if (!(RW_BITS_TO_FLOAT(voice->target) < voice->value)) goto clamp_done;
                } else {
                    if (!(voice->value < RW_BITS_TO_FLOAT(voice->target))) goto clamp_done;
                }
                voice->value = RW_BITS_TO_FLOAT(voice->target);
clamp_done:
                ;
            }
        }
        params->pan = voice->value;
        goto apply;
    }
    if ((voice->flags & 0x400) && voice->fixed == 0) {
        params->pan = func_80259B10_de(voice->position, voice->owner->listener);
    apply:
        apply_pan(voice, params->pan);
        return;
    }
    params->pan = 0x40;
}

/* Fades emitter 0x8AC with the listener's distance: optionally resets its level, stores the squared
 * distance to the listener, lowers the level by a step while the distance grows and raises it while it
 * shrinks (clamped to the D_800C9048 range, remembering the distance), and otherwise eases the level one
 * step toward the rest level D_800C9044. */
void func_8025AA2C_de(Emitter *emitter) {
    char *listener;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distance;
    f32 level;
    f32 current;

    if (emitter->id != 0x8AC) {
        return;
    }
    if (emitter->reset != 0) {
        emitter->level = D_800C3F50_de;
    }
    listener = ((OwnerCode8025A3EC *)emitter->scene)->listener;
    dx = emitter->x - ((GameplayCamera *)listener)->position.x;
    dy = emitter->y - ((GameplayCamera *)listener)->position.y;
    dz = emitter->z - ((GameplayCamera *)listener)->position.z;
    distance = dx * dx + dy * dy + dz * dz;
    emitter->distance = distance;
    if (emitter->lastDistance < distance) {
        emitter->level -= D_800CB8E8;
    } else if (distance < emitter->lastDistance) {
        emitter->level += D_800CB8E8;
    } else {
        current = emitter->level;
        if (D_800C9044 < current) {
            level = current - D_800CB8E8;
            if (level < D_800C9044) {
                level = D_800C9044;
            }
            emitter->level = level;
        } else if (current < D_800C9044) {
            level = current + D_800CB8E8;
            if (D_800C9044 < level) {
                level = D_800C9044;
            }
            emitter->level = level;
        }
        return;
    }
    level = emitter->level;
    if (D_800C9048 < level) {
        emitter->level = D_800C9048;
    } else if (level < (&D_800C9048)[1]) {
        emitter->level = (&D_800C9048)[1];
    }
    emitter->lastDistance = emitter->distance;
}
