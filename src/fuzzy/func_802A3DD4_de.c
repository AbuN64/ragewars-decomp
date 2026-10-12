#include "types.h"
#include "gfx.h"
#include "gbi.h"

typedef struct RibbonVertex RibbonVertex;
typedef struct { s32 words[16]; } RibbonMatrix;
typedef struct { char pad0[0x12]; u8 closed; char pad13[0xE]; u8 scaleS, scaleT, count; char blends[1]; } RibbonTrack;
typedef struct RibbonClock { struct RibbonClock *next; s32 unk4; f32 time; char padC[0x1C]; RibbonMatrix matrix[2]; } RibbonClock;
typedef struct { s32 unk0, unk4; RibbonTrack *track; void *first, *second; char pad14[0x28]; u32 flags; s32 unk40; RibbonClock *clock; } RibbonActor;
typedef struct { s32 count; void *blends, *first, *second; f32 scaleS, scaleT; } RibbonMorph;
extern Gfx *D_80110634;
extern s32 D_800D297C;
extern f32 D_800C5E08_de;
extern RibbonVertex *func_802A56C4_de(void *, s32);
extern void func_802A274C_de(RibbonActor *, RibbonClock *, RibbonVertex *, RibbonMorph *);

void func_802A3DD4_de(void *pool, RibbonActor *actor) {
    RibbonMorph morph;
    RibbonClock *clock, *next;
    RibbonVertex *vertices;
    u32 count, i;
    morph.count = actor->track->count;
    morph.blends = actor->track->blends;
    if (actor->flags & 2) { morph.first = actor->first; morph.second = actor->second; }
    else { morph.first = actor->first; morph.second = actor->first; }
    morph.scaleS = actor->track->scaleS * D_800C5E08_de;
    morph.scaleT = actor->track->scaleT * D_800C5E08_de;
    clock = actor->clock;
    next = clock->next;
    count = actor->track->count;
    gSPMatrix(D_80110634++, &clock->matrix[D_800D297C], G_MTX_LOAD);
    if (clock == 0 || next == 0 || !(0.0f < clock->time)) return;
    while (0.0f < next->time) {
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) break;
        func_802A274C_de(actor, clock, vertices, &morph);
        gSPVertex(D_80110634++, vertices, count, 0);
        gSPMatrix(D_80110634++, &next->matrix[D_800D297C], G_MTX_LOAD);
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) return;
        func_802A274C_de(actor, next, vertices, &morph);
        gSPVertex(D_80110634++, vertices, count, count);
        i = 0;
        while ((s32)i < (s32)(count - 1)) {
            gSP2Triangles(D_80110634++, i, count + i, count + i + 1, 0,
                          i, count + i + 1, i + 1, 0);
            i++;
        }
        if (actor->track->closed) {
            gSP2Triangles(D_80110634++, i, count + i, count, 0, i, count, 0, 0);
        }
        if (next == 0 || next->next == 0) return;
        clock = next;
        next = next->next;
        if (clock->time <= 0.0f) return;
    }
}
