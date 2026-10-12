#include "types.h"
#include "gfx.h"
#include "gbi.h"
#include "span_1000/code_8023A284.h"
typedef struct View_func_8023B3F8_de FlareActor;
typedef struct FlareRadii { f32 value[7]; } FlareRadii;
typedef struct FlareAlphas { s32 value[7]; } FlareAlphas;
typedef struct FlareColors { s32 value[21]; } FlareColors;
extern const FlareRadii D_800C344C_de;
extern const FlareAlphas D_800C3468_de;
extern const FlareColors D_800C3484_de;
extern const f32 D_800C34D8_de, D_800C34DC_de, D_800C34E4_de, D_800C34E8_de;
extern const f32 D_800C34EC_de, D_800C34F0_de, D_800C34F4_de, D_800C34F8_de;
extern const f32 D_800C34FC_de, D_800C3500_de, D_800C3504_de, D_800C3508_de;
extern const f32 D_800C350C_de, D_800C3510_de, D_800C85D0;
extern s32 D_800E28D0, D_800E28D4;
extern Gfx *D_80110634;
extern f32 func_802B72B0_de(f32);
extern s32 func_802AAC28_de(s32,s32,s16,s16,f32,f32,s32);

void func_80238670_de(FlareActor *actor, f32 x, f32 y, f32 intensity, s32 special) {
    FlareRadii radii = D_800C344C_de;
    FlareAlphas alphas = D_800C3468_de;
    FlareColors colors = D_800C3484_de;
    f32 dx, dy, distance, ratio, nx, ny;
    f32 bottom, right, left, top, edge, width, half, alpha;
    Gfx *gfx;
    s32 texture, i;
    if (intensity == 0.0f || actor->hidden) return;
    dx = D_800E28D0 / 2 - x;
    dy = D_800E28D4 / 2 - y;
    gfx = D_80110634++;
    gDPSetTextureFilter(gfx, G_TF_BILERP);
    distance = func_802B72B0_de(dx * dx + dy * dy);
    if (!special) {
        ratio = distance / func_802B72B0_de((f32)(D_800E28D0 * D_800E28D0) * D_800C34D8_de + (f32)(D_800E28D4 * D_800E28D4) * D_800C34D8_de);
        if (ratio > D_800C34DC_de) intensity = 0.0f;
        else intensity *= D_800C34DC_de - ratio;
    }
    distance *= D_800C85D0;
    if ((dx < 0.0f ? -dx : dx) > (dy < 0.0f ? -dy : dy)) {
        nx = D_800C34E4_de;
        if (dx > 0.0f) nx = D_800C34E8_de;
        ny = dy / (dx < 0.0f ? -dx : dx);
    } else {
        nx = dx / (dy < 0.0f ? -dy : dy);
        ny = D_800C34EC_de;
        if (dy > 0.0f) ny = D_800C34F0_de;
    }
    if (special) {
        bottom = (f32)D_800E28D4 + D_800C34F4_de;
        right = (f32)D_800E28D0 + D_800C34F4_de - x;
        left = x + D_800C34F4_de;
        top = y + D_800C34F4_de;
        edge = bottom - y;
        edge = edge <= right ? edge : right;
        edge = edge <= top ? edge : top;
        edge = edge <= left ? edge : left;
        edge = edge <= D_800C34F4_de ? edge : D_800C34F4_de;
        if (edge < 0.0f) intensity = 0.0f;
        else {
            edge = bottom - y;
            edge = edge <= right ? edge : right;
            edge = edge <= top ? edge : top;
            edge = edge <= left ? edge : left;
            edge = edge <= D_800C34F4_de ? edge : D_800C34F4_de;
            intensity *= edge / D_800C34F4_de;
        }
        if (intensity > D_800C34F8_de || intensity < 0.0f) {
            if (intensity < 0.0f) intensity = 0.0f;
            else intensity = intensity > D_800C34F8_de ? D_800C34F8_de : intensity;
        }
    }
    for (i = 0; i < 7; i++) {
        x += nx * distance;
        y += ny * distance;
        if (special && i == 0) width = D_800C3500_de;
        else width = radii.value[i] * D_800C3504_de;
        width *= D_800C3508_de;
        half = width * D_800C350C_de;
        if (!(x > -half && x < D_800E28D0 + half && y > -half && y < D_800E28D4 + half)) return;
        if (special && i == 0) {
            gDPSetEnvColor(D_80110634++, 255, 255, 255, intensity * D_800C3510_de);
            func_802AAC28_de(600, 0, (s16)(s32)(x - half), (s16)(s32)(y - half), width, width, 1);
        } else {
            gDPSetEnvColor(D_80110634++, colors.value[i * 3], colors.value[i * 3 + 1], colors.value[i * 3 + 2], alphas.value[i] * intensity);
            func_802AAC28_de(601, 0, (s16)(s32)(x - half), (s16)(s32)(y - half), width, width, 1);
        }
    }
}
