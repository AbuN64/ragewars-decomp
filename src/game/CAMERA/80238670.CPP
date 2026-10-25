#include "include_asm.h"
#include "COMMON/LONE/D_800E28D4.H"
#include "TYPES.H"
#include "COMMON/GFX.H"
#include "gbi.h"
#include "COMMON/DESCRIPTORRECAT29.H"
#include "GFX/TEXT/802A8A94_5.H"
typedef struct ClipView FlareActor;
#include "COMMON/LENS_FLARE.H"
extern s32 D_800E28D0;
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


/* An object that shines a lens flare: its world position, the views that see it (bit 3 + view index),
 * a pointer to its state flags (0x80000 = flare lit) and the flare brightness (0..255). Unit-private view. */
typedef struct FlareSource FlareSource;
struct FlareSource {
    char pad0[0x8];
    CVector3 position;
    char pad14[0x5C - 0x14];
    s32 viewMask;
    char pad60[0x118 - 0x60];
    s32 *state;
    char pad11C[0x198 - 0x11C];
    f32 brightness;
    char pad19C[0x1F4 - 0x19C];
    FlareSource *next;
};
typedef struct FlareSourceList { FlareSource *first; } FlareSourceList;
extern FlareSourceList D_8012D4E4;
extern void func_802A9234_de(s32);
extern void Render_SetModePreset(s32);
extern void func_80272A10_de(void *, void *, CVector3 *);

/* Same body as func_80239244_de: project a world point through the view matrix to screen pixels. */
static inline void Camera_ProjectToScreen(FlareActor *view, CVector3 *point, f32 *screenX, f32 *screenY) {
    CVector3 value;
    f32 half;
    func_80272A10_de(view->viewProjection, point, &value);
    half = (f32)(D_800E28D0 / 2);
    *screenX = value.x * half + half;
    *screenY = value.y * (f32)(-D_800E28D4 / 2) + (f32)(D_800E28D4 / 2);
}

/* Draws the lens flares of every lit flare source the view can see. */
void Camera_DrawObjectFlares(FlareActor *view) {
    Gfx **gfx = &D_80110634;
    Gfx *g;
    FlareSource *source;
    f32 x, y;
    s32 mask = 8 << view->index;

    func_802A9234_de(100);
    Render_SetModePreset(0x1A);
    g = *gfx;
    gDPSetTextureFilter(g++, G_TF_BILERP);
    *gfx = g;
    for (source = D_8012D4E4.first; source != 0; source = source->next) {
        if ((source->viewMask & mask) && (*source->state & 0x80000)) {
            Camera_ProjectToScreen(view, &source->position, &x, &y);
            func_80238670_de(view, x, y, source->brightness * (1.0f / 255.0f), 0, 0);
        }
    }
}
