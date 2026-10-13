#include "types.h"
#include "gfx.h"
#include "gbi.h"

#include "span_1000/code_802A25C4.h"
#include "span_1000/code_80291054.h"
#include "span_1000/code_8022F3E8.h"
#include "span_C76B0/data.h"
#include "shared/ribbon_draw.h"

void func_802A3DD4_de(func_802A66B4_S1 *pool, Actor_func_802A274C_de *actor) {
    Morph storage;
    Morph *morph = &storage;
    func_80212828_S7 *clock, *next;
    Vtx *vertices;
    u32 count, i;
    s32 edges;
    morph->blends = actor->track->blends;
    morph->count = actor->track->count;
    if (actor->flags & 2) { morph->first = actor->first; morph->second = actor->second; }
    else { morph->first = actor->first; morph->second = actor->first; }
    morph->scaleS = actor->track->scaleS * D_800C5E08_de;
    morph->scaleT = actor->track->scaleT * D_800C5E08_de;
    clock = actor->clock;
    next = clock->next;
    count = actor->track->count;
    edges = count - 1;
    gSPMatrix(D_80110634++, &clock->matrix[D_800D297C], G_MTX_LOAD);
    while (clock != 0 && next != 0 && 0.0f < clock->unk8 && 0.0f < next->unk8) {
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) break;
        func_802A274C_de(actor, clock, vertices, &storage);
        gSPVertex(D_80110634++, vertices, count, 0);
        gSPMatrix(D_80110634++, &next->matrix[D_800D297C], G_MTX_LOAD);
        vertices = func_802A56C4_de(pool, count);
        if (vertices == 0) return;
        func_802A274C_de(actor, next, vertices, &storage);
        gSPVertex(D_80110634++, vertices, count, count);
        i = 0;
        while ((s32)i < edges) {
            { Gfx *cmd = D_80110634++;
              cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | ((count + i + 1) * 2 & 255)) | (G_TRI2 << 24);
              cmd->words.w1 = ((i * 2 & 255) << 16) | (((count + i + 1) * 2 & 255) << 8) | ((i + 1) * 2 & 255);
            }
            i++;
        }
        if (actor->track->closed) {
            { Gfx *cmd = D_80110634++;
              cmd->words.w0 = (((i * 2 & 255) << 16) | (((count + i) * 2 & 255) << 8) | (count * 2 & 255)) | (G_TRI2 << 24);
              cmd->words.w1 = ((i * 2 & 255) << 16) | ((count * 2 & 255) << 8);
            }
        }
        clock = next;
        next = clock->next;

    }
}
