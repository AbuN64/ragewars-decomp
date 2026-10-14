#include "span_1000/code_802A25C4.h"
#include "types.h"
#include "common/types_1dc8418c21db.h"

/* Partial storage views: the named fields are the ones this routine accesses.
   The prefix and intervening bytes retain the observed node and descriptor layout. */




extern s32 func_802744D4_de(void);

/* Selects a frame using clamping, looping, ping-pong or random playback. */
s32 func_802A4134_de(AnimationFrameState *state,
                     AnimationFrameDefinition *definition, s32 *frame_count) {
    s32 frame = (s32)state->frame;
    s32 *selected = &frame;
    s32 value;

    switch (definition->mode) {
    case 0:
        value = *frame_count - 1;
        if (*selected >= value) {
            *selected = value;
            state->endpoint = (f32)*frame_count;
        }
        break;
    case 1:
        if (*selected >= *frame_count) {
            *selected = *frame_count - 1;
        }
        break;
    case 2:
        *selected %= *frame_count;
        break;
    case 3:
        value = *frame_count * 2 - 2;
        if (value > 0) {
            value = *selected % value;
        } else {
            value = 0;
        }
        *selected = value;
        if (value >= *frame_count) {
            s32 reflected = *frame_count * 2;
            s32 adjusted = value + 2;
            *selected = reflected - adjusted;
        }
        break;
    case 4:
        *selected = func_802744D4_de() % *frame_count;
        break;
    case 5:
        if (state->cached_frame == -1) {
            state->cached_frame = func_802744D4_de() % *frame_count;
        }
        *selected = state->cached_frame;
        break;
    }
    return frame;
}

/* Detaches an entity from linked effects while preserving their transforms and lifetimes; the unsigned offset-to-pointer cast preserves matrix-address scheduling and addition operand order. */
extern int D_800D297C;
extern f32 D_800C5E28_de,D_800C5E2C_de,D_800C5E30_de,D_800C5E34_de;
extern char D_801379C0;
extern void func_8027027C_de(void *,void *),func_80270910_de(void *,void *),func_80272828_de(void *),func_802732D0_de(void *,void *),func_802732EC_de(void *,void *),func_8027347C_de(void *,f32,f32,f32),func_802A25D0_de(void *,Node44 *,void *);
void func_802A42F4_de(Root752C *arg0, Entity1DC *arg1) {
    f32 sp10[16];
    f32 temp_f1;
    f32 var_f0;
    f32 var_f0_2;
    s32 temp_v1;
    u8 temp_v0;
    u8 temp_v0_2;
    char *temp_v1_2;
    Entity1DC *temp_v1_3;
    Entity1DC *temp_v1_4;
    struct Shape_typemap_6 *var_a0;
    ChildB4 *var_s0;
    Node44 *var_s1;
    struct Shape_typemap_6 *var_v0;
    var_s1 = arg0->unk_7528;
    if (var_s1 != 0) {
        do {
            temp_v1 = var_s1->unk_3C;
            if (temp_v1 & 8) {
                var_s0 = var_s1->unk_40;
                if (var_s0 != 0) {
loop_4:
                    if (var_s0->unk_B0 == arg1) {
                        if (arg1 != 0) {
                            if (arg1 == (void *)-1) {
                                ((struct ObjectState68 *) (((char *) var_s0) + (D_800D297C << 6)))->unk_28=((struct ObjectState68 *) (((char *) var_s0) + ((D_800D297C ^ 1) << 6)))->unk_28;
                                var_s0->unk_B0 = 0;
                            } else {
                                func_80270910_de(&sp10, (char *)arg1 + ((D_800D297C << 6) + 0x60));
                                var_f0 = D_800C5E28_de;
                                if (arg1->unk_118->unk14 != 0) {
                                    var_f0 = D_800C5E2C_de;
                                }
                                func_8027347C_de(&sp10, var_f0, var_f0, var_f0);
                                func_80272828_de(&sp10);
                                func_802732D0_de(&sp10, var_s0->pos);
                                if (var_s1->unk_3C & 4) {
                                    func_802732EC_de(&sp10, var_s0->rot);
                                } else {
                                    func_8027027C_de(&sp10, (char *)var_s0 + ((D_800D297C << 6) + 0x28));
                                }
                            }
                            var_s0->unk_8 = (f32) var_s1->unk_8->unk_8;
                        }
                        var_s0->unk_B0 = (Entity1DC *)-1;
                    }
                    var_s0 = var_s0->unk_4;
                    if (var_s0 != 0) {
                        goto loop_4;
                    }
                }
            } else if (var_s1->unk_1C == arg1) {
                if (temp_v1 & 2) {
                    unsigned int offset = D_800D297C << 6;
                    char *matrix = (char *)offset;
                    matrix += (unsigned int)arg1;
                    matrix += 0x60;
                    if (var_s1->unk_24 > 0.0f) {
                    func_80270910_de(&sp10, matrix);
                    var_f0_2 = D_800C5E30_de;
                    if (arg1->unk_118->unk14 != 0) {
                        var_f0_2 = D_800C5E34_de;
                    }
                    func_8027347C_de(&sp10, var_f0_2, var_f0_2, var_f0_2);
                    func_80272828_de(&sp10);
                    func_802A25D0_de(&D_801379C0, var_s1, &sp10);
                }
                }
                temp_v1_3 = var_s1->unk_1C;
                if (temp_v1_3 != 0) {
                    if (var_s1->unk_3C & 1) {
                        temp_v0 = temp_v1_3->unk_13B;
                        if (temp_v0 != 0) {
                            temp_v1_3->unk_13B = (u8) (temp_v0 - 1);
                        }
                    }
                    if (var_s1->unk_3C & 2) {
                        temp_v1_4 = var_s1->unk_1C;
                        temp_v0_2 = temp_v1_4->unk_1D9;
                        if (temp_v0_2 != 0) {
                            temp_v1_4->unk_1D9 = (u8) (temp_v0_2 - 1);
                        }
                    }
                }
                var_s1->unk_1C = 0;
                temp_f1 = var_s1->unk_8->unk_4;
                if (var_s1->unk_24 < temp_f1) {
                    var_s1->unk_24 = temp_f1;
                }
            }
            var_s1 = var_s1->unk_4;
        } while (var_s1 != 0);
    }
}
