#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "GFX/TEXT/802A8A94_5.H"
typedef struct ClipView FlareActor;
#include "COMMON/LENS_FLARE.H"
extern s32 D_800E28D0, D_800E28D4;
extern Gfx *D_80110634;
extern f32 func_802B72B0_de(f32);
void func_80238670_de(FlareActor *actor, f32 x, f32 y, f32 intensity, s32 special, s32 unused) {
    FlareRadii radii = D_800C344C_de;
    FlareAlphas alphas = D_800C3468_de;
    FlareColors colors = D_800C3484_de;
    f32 dx, dy, distance, nx, ny;
    f32 bottom, right, left, top, edge, width, half, alpha;
    Gfx *gfx;
    s32 i;
    if (intensity == 0.0f || actor->hidden) return;
    dx = D_800E28D0 / 2 - x;
    dy = D_800E28D4 / 2 - y;
    gfx = D_80110634++;
    gDPSetTextureFilter(gfx, G_TF_BILERP);
    distance = func_802B72B0_de(dx * dx + dy * dy);
    if (!special) {
        edge = distance / func_802B72B0_de((f32)(D_800E28D0 * D_800E28D0) * 0.25f + (f32)(D_800E28D4 * D_800E28D4) * 0.25f);
        if (edge > 1.0f) intensity = 0.0f;
        else intensity *= 1.0f - edge;
    }
    distance *= 0.4f;
    if ((dx < 0.0f ? -dx : dx) > (dy < 0.0f ? -dy : dy)) {
        nx = -1.0f;
        if (dx > 0.0f) nx = 1.0f;
        ny = dy / (dx < 0.0f ? -dx : dx);
    } else {
        nx = dx / (dy < 0.0f ? -dy : dy);
        ny = -1.0f;
        if (dy > 0.0f) ny = 1.0f;
    }
    if (special) {
        half = 35.2f;
        bottom = (f32)D_800E28D4 + half;
        right = (f32)D_800E28D0 + half - x;
        left = x + half;
        top = y + half;
        edge = bottom - y;
        if (!(edge <= right)) edge = right;
        if (!(edge <= top)) edge = top;
        if (!(edge <= left)) edge = left;
        if (!(edge <= half)) edge = half;
        if (edge < 0.0f) intensity = 0.0f;
        else {
            alpha = bottom - y;
            if (!(alpha <= right)) alpha = right;
            if (!(alpha <= top)) alpha = top;
            if (!(alpha <= left)) alpha = left;
            if (!(alpha <= half)) alpha = half;
            intensity *= alpha / half;
        }
        intensity = intensity > 1.0f || !(intensity < 0.0f) ? (intensity > 1.0f ? 1.0f : intensity) : 0.0f;
    }
    for (i = 0; i < 7; i++) {
        x += nx * distance;
        y += ny * distance;
        if (special && i == 0) width = 2.0f;
        else width = radii.value[i] * 0.03125f;
        width *= 0.55f;
        half = width * 16.0f;
        if (!(x > -half && x < D_800E28D0 + half && y > (top = -half) && y < D_800E28D4 + half)) return;
        if (special && i == 0) {
            gDPSetEnvColor(D_80110634++, 255, 255, 255, intensity * 255.0f);
            func_802AAC28_de(600, 0, (s16)(s32)(x - half), (s16)(s32)(y - half), width, width, 1);
        } else {
            gDPSetEnvColor(D_80110634++, colors.value[i * 3], colors.value[i * 3 + 1], colors.value[i * 3 + 2], alphas.value[i] * intensity);
            func_802AAC28_de(601, 0, (s16)(s32)(x - half), (s16)(s32)(y - half), width, width, 1);
        }
    }
}

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vector3f;

typedef struct { Gfx * unk0; } func_80238D20_G1;
extern Gfx *D_80110634;
struct func_80238D20_S2;
extern struct func_80238D20_S2 *D_8012D4E4;
typedef struct { s32 unk0; } func_80238D20_G2;
typedef struct { f32 unk0; } func_80238D20_G3;
extern f32 D_800C3514_de;
extern void func_802A9234_de(s32);
extern s32 func_8026925C_de(s32);
extern void func_80272A10_de(void *, void *, Vector3f *);

typedef struct func_80238D20_S1 func_80238D20_S1;
typedef struct func_80238D20_S2 func_80238D20_S2;
typedef struct RecCode80200610 RecCode80200610;
struct func_80238D20_S1 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0x1E0 - 0x8 - sizeof(s32)];
    char unk1E0;
};
struct func_80238D20_S2 {
    char pad0[0x8];
    char unk8;
    char pad8[0x5C - 0x8 - sizeof(char)];
    s32 unk5C;
    char pad5C[0x118 - 0x5C - sizeof(s32)];
    s32* unk118;
    char pad118[0x198 - 0x118 - sizeof(s32*)];
    f32 unk198;
    char pad198[0x1F4 - 0x198 - sizeof(f32)];
    struct func_80238D20_S2 *unk1F4;
};
struct RecCode80200610 {
    char pad0[0x4];
    s32 unk4;
};

void Camera_DrawObjectFlares(func_80238D20_S1 *view) {
    Vector3f value;
    f32 screen_x;
    f32 screen_y;
    f32 half;
    f32 *x;
    f32 *y;
    s32 mask;
    s32 state_mask;
    func_80238D20_S2 *node;

    mask = 8 << view->unk8;
    func_802A9234_de(0x64);
    func_8026925C_de(0x1A);
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    node = D_8012D4E4;
    if (node != 0) {
        state_mask = 0x80000;
        x = &screen_x;
        y = &screen_y;
        do {
            if ((node->unk5C & mask) &&
                (*node->unk118 & state_mask)) {
                func_80272A10_de(&view->unk1E0, &node->unk8, &value);
                half = (f32)(D_800E28D0 / 2);
                *x = value.x * half + half;
                *y = value.y *
                         (f32)(-(&D_800E28D0)[1] / 2) +
                     (f32)((&D_800E28D0)[1] / 2);
                func_80238670_de((FlareActor *)view, screen_x, screen_y,
                              node->unk198 * D_800C3514_de,
                              0, 0);
            }
            node = node->unk1F4;
        } while (node != 0);
    }
}
#else
INCLUDE_ASM("span_1000", Camera_DrawObjectFlares);
#endif
