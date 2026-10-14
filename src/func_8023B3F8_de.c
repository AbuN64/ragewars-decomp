#include "gfx.h"
#include "span_1000/code_8023A284.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"


/* Sorts and draws scene translucent objects in two groups around the view depth. */





extern Gfx *D_80110634;


extern char D_80142C60;
extern void D_0023B938();
extern void D_0023B94C();
extern void D_0023B978_de();
extern void func_8026925C_de(s32);
extern void func_802852C0_de(char *, u32, u32, void *, void *);
extern void func_8023A4E0_de(ObjectRecAt220 *, ClipView *);

void func_8023B3F8_de(Scene *scene, ClipView *view) {
    ObjectRecAt220 *near[4];
    ObjectRecAt220 *far[4];
    ObjectRecAt220 *object;
    s32 nearCount;
    s32 farCount;
    s32 i;

    if (scene->count == 0 || view->hidden != 0) {
        return;
    }
    gDPPipeSync(D_80110634++);
    gSPMatrix(D_80110634++, (u32)(((u32)&D_80142C60)), G_MTX_LOAD);
    gSPMoveWord(D_80110634++, G_MW_CLIP, 4, (u32)((2)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 12, (u32)((2)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 20, (u32)((0xFFFE)));
    gSPMoveWord(D_80110634++, G_MW_CLIP, 28, (u32)((0xFFFE)));
    gSPGeometryMode(D_80110634++, G_FOG, 0);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    func_8026925C_de(0xD);
    gSPGeometryMode(D_80110634++, G_CULL_BACK | G_LIGHTING | G_TEXTURE_GEN, 0);
    gSPGeometryMode(D_80110634++, 0, G_SHADE | G_SHADING_SMOOTH);
    gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
    gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
    nearCount = 0;
    farCount = 0;
    for (object = scene->objects; object != 0; object = object->next) {
        if (object->depth > view->depth) {
            near[nearCount++] = object;
        } else {
            far[farCount++] = object;
        }
    }
    func_802852C0_de((char *)near, nearCount, 4, D_0023B94C, D_0023B938);
    func_802852C0_de((char *)far, farCount, 4, D_0023B978_de, D_0023B938);
    for (i = 0; i < nearCount; i++) {
        func_8023A4E0_de(near[i], view);
    }
    for (i = 0; i < farCount; i++) {
        func_8023A4E0_de(far[i], view);
    }
}
