#include "types.h"
#include "span_1000/code_8023330C.h"
typedef struct ViewportBounds { f32 value[6]; } ViewportBounds;
typedef struct Viewport {
    char pad0[4]; struct Viewport *next; char pad8[0x5c]; s32 flags;
    char pad68[0x234]; f32 width, height, x, y; char pad2AC[0xa4];
    ViewportBounds clip, bounds;
} Viewport;
typedef struct FlareMessage { char pad0[4]; struct FlareMessage *next; char pad8[0x10]; State_func_802337D0_de x, y, z; } FlareMessage;
typedef struct ViewportOwner {
    char pad0[0x20]; Viewport *views; char pad24[0xc]; u32 mode,lastMode; s32 timer; char pad3C[4];
    Viewport own; char pad3C0[0xe18]; IntrusiveList free, active;
} ViewportOwner;
typedef struct ViewportOptions { char pad0[0x148]; u8 first; char pad149[0x95]; u8 second; char pad1DF[0x95]; u8 third; char pad275[0x95]; u8 fourth; } ViewportOptions;
typedef struct ViewportMode { char pad0[0xac]; s32 threePlayers; } ViewportMode;
extern ViewportOptions D_801462C8;
extern ViewportMode D_801468A0;
extern FlareMessage *D_801421B4;
extern s32 D_800E28D0,D_800E28D4,D_800CD8D0,D_80103220,D_80146894;
extern f32 D_800CB388,D_800CB38C_de,D_800CB394,D_800D05D0,D_800C3320_de;
extern u8 D_801462E7;
extern ViewportBounds D_800FF208,D_801031F0;
extern u32 func_802337D0_de(State_func_802337D0_de *);
extern void func_80255ED8_de(void *, void *);
extern void func_80255CB8_de(void *, void *);
extern s32 func_80245798_de(void),func_80245784_de(void);
extern u32 func_80245850_de(void);
extern void func_80234FEC_de(void *);
void func_80236874_de(ViewportOwner *arg0) {
    f32 temp_fs0;
    f32 temp_fs0f;
    f32 temp_fs2;
    f32 temp_fs2f;
    f32 var_fs1;
    f32 var_fs1f;
    f32 var_fv0;
    f32 var_fv0_10;
    f32 var_fv0_11;
    f32 var_fv0_12;
    f32 var_fv0_13;
    f32 var_fv0_2;
    f32 var_fv0_3;
    f32 var_fv0_4;
    f32 var_fv0_5;
    f32 var_fv0_6;
    f32 var_fv0_7;
    f32 var_fv0_8;
    f32 var_fv0_9;
    f32 var_fv0f;
    f32 var_fv0f_2;
    f32 var_fv1;
    FlareMessage *temp_s3;
    s32 temp_v0_3;
    FlareMessage *var_s1;
    s32 var_v1;
    u32 temp_s0;
    u32 temp_s2;
    u32 temp_v0;
    u32 temp_v0_2;
    u32 temp_v1;
    s32 *flags;
    ViewportOptions *temp_a0;
    Viewport *var_s0;

    var_fv0f = (f32) D_800E28D0;
    var_fs1 = 0.0f;
    var_fv1 = (f32) D_800E28D4;
    var_fs1f = 0.0f;
    if ((u32) arg0->mode >= 2U) {
        var_fs1 = D_800CB38C_de;
        var_fv1 -= D_800CB388;
        var_fs1f = D_800D05D0;
        var_fv0f -= D_800CB394;
    }
    temp_fs2f = var_fv1 - var_fs1;
    temp_fs0f = temp_fs2f * D_800C3320_de;
    temp_fs2 = var_fv0f - var_fs1f;
    temp_fs0 = temp_fs2 * D_800C3320_de;
    var_s1 = D_801421B4;
    var_s0 = &arg0->own;
    if (var_s1 != 0) {
        do {
            temp_s3 = var_s1->next;
            temp_s0 = func_802337D0_de(&var_s1->x);
            temp_s2 = func_802337D0_de(&var_s1->y);
            temp_v0 = func_802337D0_de(&var_s1->z);
            var_v1 = 0;
            if ((temp_s0 != 0) && (temp_s2 != 0)) {
                var_v1 = temp_v0 > 0U;
            }
            if (var_v1 != 0) {
                func_80255ED8_de(&arg0->active, var_s1);
                func_80255CB8_de(&arg0->free, var_s1);
            }
            var_s1 = temp_s3;
            var_s0 = &arg0->own;
        } while (var_s1 != 0);
    }
    var_s0->width = (f32) D_800E28D0;
    var_s0->height = (f32) D_800E28D4;
    var_s0->x = 0;
    var_s0->y = 0;
    if ((func_80245798_de() == 0) && (func_80245784_de() == 0)) {
        temp_v1 = arg0->mode;
        var_s0 = arg0->views;
        switch (temp_v1) {                          /* irregular */
        case 1:
            var_s0->width = temp_fs2;
            var_s0->height = temp_fs2f;
            var_s0->x = 0;
            var_s0->y = 0;
            break;
        case 2:
            if (D_801462E7 == 0) {
                var_s0->width = temp_fs2;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
            var_s0->y = var_fs1;
                var_s0 = var_s0->next;
                var_fv0 = var_fs1 + temp_fs0f;
                var_s0->width = temp_fs2;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
                goto block_42;
            } else {
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs2f;
                var_s0->x = var_fs1f;
            var_s0->y = var_fs1;
                var_s0 = var_s0->next;
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs2f;
                var_s0->y = var_fs1;
                var_s0->x = (f32) (var_fs1f + temp_fs0);
            }
            break;
        case 3:
            if (D_801468A0.threePlayers == 0) {
            temp_a0 = &D_801462C8;
            if (temp_a0->first == 1) {
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
            var_s0->y = var_fs1;
                var_s0 = var_s0->next;
            }
            if (temp_a0->second == 1) {
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->y = var_fs1;
                var_s0->x = (f32) (var_fs1f + temp_fs0);
                var_s0 = var_s0->next;
            }
            if (temp_a0->third == 1) {
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
                var_s0->y = (f32) (var_fs1 + temp_fs0f);
                var_s0 = var_s0->next;
            }
            if (temp_a0->fourth == 1) {
                var_fv0f_2 = var_fs1f + temp_fs0;
                var_fv0 = var_fs1 + temp_fs0f;
                goto block_41;
            }

            } else {
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
            var_s0->y = var_fs1;
                var_s0 = var_s0->next;
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->y = var_fs1;
                var_s0->x = (f32) (var_fs1f + temp_fs0);
                var_s0 = var_s0->next;
                var_fv0 = var_fs1 + temp_fs0f;
                var_s0->width = temp_fs0;
                var_s0->height = temp_fs0f;
                var_s0->x = var_fs1f;
                goto block_42;
            }
            break;
        case 4:
            var_s0->width = temp_fs0;
            var_s0->height = temp_fs0f;
            var_s0->x = var_fs1f;
            var_s0->y = var_fs1;
            var_s0 = var_s0->next;
            var_fv0f_2 = var_fs1f + temp_fs0;
            var_s0->width = temp_fs0;
            var_s0->height = temp_fs0f;
            var_s0->y = var_fs1;
            var_s0->x = var_fv0f_2;
            var_s0 = var_s0->next;
            var_fv0 = var_fs1 + temp_fs0f;
            var_s0->width = temp_fs0;
            var_s0->height = temp_fs0f;
            var_s0->x = var_fs1f;
            var_s0->y = var_fv0;
            var_s0 = var_s0->next;
block_41:
            var_s0->width = temp_fs0;
            var_s0->height = temp_fs0f;
            var_s0->x = var_fv0f_2;
block_42:
            var_s0->y = var_fv0;
            break;

        }
    }
        D_800FF208 = arg0->own.clip;
        D_801031F0 = arg0->own.bounds;
    D_80103220 = D_800CD8D0;
    func_80234FEC_de(&arg0->own);
    var_s0 = arg0->views;
    if (var_s0 != 0) {
        if ((D_80146894 != 0) || (func_80245850_de() != 0)) {
            func_80234FEC_de(var_s0);
        }
        if ((func_80245798_de() != 0) || (func_80245784_de() != 0)) {
            func_80234FEC_de(var_s0);
        }
        D_800FF208 = var_s0->clip;
        D_801031F0 = var_s0->bounds;
        D_80103220 = var_s0->flags;
        var_s0 = var_s0->next;
        if (var_s0 != 0) {
            flags = &D_80103220;
            do {
                if ((D_80146894 != 0) || (func_80245850_de() != 0)) {
                    func_80234FEC_de(var_s0);
                }
                var_fv0_2 = var_s0->clip.value[0];
                if (!(var_fv0_2 <= D_800FF208.value[0])) {
                    var_fv0_2 = D_800FF208.value[0];
                }
                D_800FF208.value[0] = var_fv0_2;
                var_fv0_3 = var_s0->clip.value[1];
                if (!(var_fv0_3 <= D_800FF208.value[1])) {
                    var_fv0_3 = D_800FF208.value[1];
                }
                D_800FF208.value[1] = var_fv0_3;
                var_fv0_4 = var_s0->clip.value[2];
                if (!(var_fv0_4 <= D_800FF208.value[2])) {
                    var_fv0_4 = D_800FF208.value[2];
                }
                D_800FF208.value[2] = var_fv0_4;
                var_fv0_5 = var_s0->clip.value[3];
                if (!(D_800FF208.value[3] <= var_fv0_5)) {
                    var_fv0_5 = D_800FF208.value[3];
                }
                D_800FF208.value[3] = var_fv0_5;
                var_fv0_6 = var_s0->clip.value[4];
                if (!(D_800FF208.value[4] <= var_fv0_6)) {
                    var_fv0_6 = D_800FF208.value[4];
                }
                D_800FF208.value[4] = var_fv0_6;
                var_fv0_7 = var_s0->clip.value[5];
                if (!(D_800FF208.value[5] <= var_fv0_7)) {
                    var_fv0_7 = D_800FF208.value[5];
                }
                D_800FF208.value[5] = var_fv0_7;
                var_fv0_8 = var_s0->bounds.value[0];
                if (!(var_fv0_8 <= D_801031F0.value[0])) {
                    var_fv0_8 = D_801031F0.value[0];
                }
                D_801031F0.value[0] = var_fv0_8;
                var_fv0_9 = var_s0->bounds.value[1];
                if (!(var_fv0_9 <= D_801031F0.value[1])) {
                    var_fv0_9 = D_801031F0.value[1];
                }
                D_801031F0.value[1] = var_fv0_9;
                var_fv0_10 = var_s0->bounds.value[2];
                if (!(var_fv0_10 <= D_801031F0.value[2])) {
                    var_fv0_10 = D_801031F0.value[2];
                }
                D_801031F0.value[2] = var_fv0_10;
                var_fv0_11 = var_s0->bounds.value[3];
                if (!(D_801031F0.value[3] <= var_fv0_11)) {
                    var_fv0_11 = D_801031F0.value[3];
                }
                D_801031F0.value[3] = var_fv0_11;
                var_fv0_12 = var_s0->bounds.value[4];
                if (!(D_801031F0.value[4] <= var_fv0_12)) {
                    var_fv0_12 = D_801031F0.value[4];
                }
                D_801031F0.value[4] = var_fv0_12;
                var_fv0_13 = var_s0->bounds.value[5];
                if (!(D_801031F0.value[5] <= var_fv0_13)) {
                    var_fv0_13 = D_801031F0.value[5];
                }
                D_801031F0.value[5] = var_fv0_13;
                *flags |= var_s0->flags;
                var_s0 = var_s0->next;
            } while (var_s0 != 0);
        }
    }
    temp_v0_2 = arg0->mode;
    if (arg0->lastMode != temp_v0_2) {
        arg0->timer = 2;
        arg0->lastMode = temp_v0_2;
        return;
    }
    temp_v0_3 = arg0->timer;
    if (temp_v0_3 != 0) {
        arg0->timer = (s32) (temp_v0_3 - 1);
    }
}
