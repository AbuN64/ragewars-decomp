#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80296014.h"
#include "span_1000/code_802A25C4.h"
#include "n64sdk.h"
#include "gbi.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"
#include "n64sdk.h"


/* Draws the scene's ten particle lists unless the free list holds exactly 100 particles: sets the render state and the shared particle texture D_800D14B0 (a 16x16 texture drawn in grey at alpha 200 through D_800D2E60), then for every particle inside the view box ending at D_801031F8 + 4 loads its matrix and draws the shared quad D_801469A0, while particles outside it are unlinked (func_80255ED8_de) and returned to the free list (func_80255D14_de); finally restores the render state through func_8026D8F8_de and func_80295FF4_de. */










extern Gfx *D_80110634;
extern f32 D_801031F8;
extern char D_800D14B0;
extern char D_800D2E60;
extern char D_801469A0;
extern void func_80255ED8_de(void *list, Particle *particle);






void func_802A5180_de(Scene_func_802A5180_de *scene) {
    Particle *particle;
    Particle *next;
    f32 *max;
    IntrusiveList *list;
    f32 pos[3];
    s32 i;

    if (scene->free.count == 100) {
        return;
    }
    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_2CYCLE);
    gDPSetTextureImage(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 1, (u32)&D_800D14B0);
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_16b, 0, 0, G_TX_LOADTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPLoadSync(D_80110634++);
    gDPLoadBlock(D_80110634++, G_TX_LOADTILE, 0, 0, 127, 1024);
    gDPPipeSync(D_80110634++);
    gDPSetTile(D_80110634++, G_IM_FMT_I, G_IM_SIZ_8b, 2, 0, G_TX_RENDERTILE, 0, G_TX_CLAMP, 0, 0, G_TX_CLAMP, 0, 0);
    gDPSetTileSize(D_80110634++, G_TX_RENDERTILE, 0, 0, 60, 60);
    gDPSetPrimColor(D_80110634++, 0, 0, 255, 255, 255, 200);
    gSPDisplayList(D_80110634++, (u32)&D_800D2E60);
    for (i = 0; i < 10; i++) {
        max = (&D_801031F8 + 1);
        list = &scene->lists[i];
        particle = list->head;
        while (particle != 0) {
            Transform *transform = &particle->transform;

            next = particle->next;
            pos[0] = transform->position[0];
            pos[1] = transform->position[1];
            pos[2] = transform->position[2];
            if (!(pos[0] < max[0] && pos[1] < max[1] && pos[2] < max[2] && max[-3] <= pos[0] &&
                  max[-2] <= pos[1] && max[-1] <= pos[2])) {
                func_80255ED8_de(list, particle);
                func_80255D14_de(&scene->free, particle);
            } else {
                gSPMatrix(D_80110634++, (u32)transform, G_MTX_LOAD);
                gSPVertex(D_80110634++, (u32)&D_801469A0, 4, 0);
                gSP2Triangles(D_80110634++, 0, 1, 2, 0, 2, 3, 0, 0);
            }
            particle = next;
        }
    }
    func_8026D8F8_de();
    func_80295FF4_de();
}
