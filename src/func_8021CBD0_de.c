#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_802192C0.h"
#include "span_1000/code_8026AC38.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"




extern void *D_800D052C[];
extern Gfx *D_80110634;
extern s32 D_8011FAC0;




extern void func_80291BE8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);
extern void func_80249E28_de(void *arg0, void *arg1);








void func_8021CBD0_de(void *arg0, void *arg1) {
    WeaponInfo *entry;
    f32 *rect;
    f32 x;
    f32 y;
    f32 left;
    f32 right;
    f32 top;
    f32 bottom;

    if ((((Shared_ActorView *)arg0)->selectedAction != -1) &&
        (((Shared_ActorView *)arg0)->lives != 0)) {
        gDPSetTextureFilter(D_80110634++, G_TF_BILERP);
        gDPSetTexturePersp(D_80110634++, G_TP_PERSP);
        func_8026D8F8_de();

        entry = D_800D052C[((Shared_ActorView *)arg0)->selectedAction];
        rect = ((WeaponMenuView *)arg1)->viewport;
        x = rect[0];
        y = rect[1];
        left = entry->scopeBounds[0] * x + rect[2];
        right = entry->scopeBounds[2] * x + rect[2];
        top = entry->scopeBounds[1] * y + rect[3];
        bottom = entry->scopeBounds[3] * y + rect[3];
        func_80291BE8_de(&D_8011FAC0, (s32)left, (s32)right, (s32)top,
                      (s32)bottom, ((WeaponMenuView *)arg1)->clipMode);

        gSPGeometryMode(D_80110634++, 0, G_FOG);
        gSPMoveWord(D_80110634++, G_MW_CLIP, 4, 1);
        gSPMoveWord(D_80110634++, G_MW_CLIP, 12, 1);
        gSPMoveWord(D_80110634++, G_MW_CLIP, 20, 0xFFFF);
        gSPMoveWord(D_80110634++, G_MW_CLIP, 28, 0xFFFF);
        func_8026D980_de();
        func_80249E28_de(&((Shared_ActorView *)arg0)->weapon, arg1);
        func_8026D9D0_de();
    }
}
