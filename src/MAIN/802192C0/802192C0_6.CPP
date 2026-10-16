#include "span_1000/code_802192C0.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "common/unused.h"
#include "gbi.h"
#include "n64sdk.h"
#include "shared/gameplay_transition.h"
#include "shared/world.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022C894.h"
#include "span_1000/code_8026AC38.h"
#include "TYPES.H"
#include "span_1000/code_8022E938.h"
#include "span_1000/code_8022F3E8.h"
#include "span_1000/code_80291054.h"


extern u8 D_801462E5;

extern s32 D_801468F4;


extern f32 func_8024D284_de(void *arg0);

extern void func_8028C6D4_de(void *arg0, void *arg1, void *arg2);

extern void func_80249E28_de(void *arg0, void *arg1);

extern void func_8021C698_de(void *arg0, void *arg1);


extern s32 D_8011FAC0;

extern void func_80291BE8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

void func_8021C9D8_de(void *arg0, void *arg1) {
    Vec3 pos;
    s32 value;
    Gfx *cmd;

    pos = ((LevelActor *)arg0)->position0;
    pos.y += ((LevelActor *)arg0)->eyeHeight;
    pos.y += func_8024D284_de(arg0) * ((D_800C7470_Pair *)&D_800C22B0_us)->second;
    func_8028C6D4_de(&D_8011FE88, &pos,
                  &((LevelActor *)arg0)->lighting[D_800D297C]);

    value = 0x66;
    if (D_801462E5 != 0) {
        if ((D_801468F4 != 0) &&
            (((Shared_ActorView *)arg0)->controls->transientFlag != 0)) {
            value = D_800CE47C;
        } else {
            value = D_800CE430[((MovementDescriptor *)((LevelActor *)arg0)->definition)->body.header.character];
            ((LevelActor *)arg0)->field3 =
                ((Shared_ActorView *)arg0)->controls->playerId;
        }
    }
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, arg0, value,
                  ((Actor_func_8022D290_de *)arg0)->unk_0x086C);

    cmd = D_80110634++;
    gDPPipeSync(cmd);
    cmd = D_80110634++;
    gDPSetCycleType(cmd, G_CYC_2CYCLE);
    cmd = D_80110634++;
    gSPGeometryMode(cmd, 0, G_FOG);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 4, 2);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 12, 2);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 20, 0xFFFE);
    cmd = D_80110634++;
    gSPMoveWord(cmd, G_MW_CLIP, 28, 0xFFFE);

    func_80249E28_de(arg0, arg1);
    if (((Actor_func_8022D290_de *)arg0)->unk_0x1210 != 0) {
        func_8021C698_de(arg0, arg1);
    }
}

void func_8021CBD0_de(void *arg0, WeaponMenuView *arg1) {
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
        rect = arg1->viewport;
        x = rect[0];
        y = rect[1];
        left = entry->scopeBounds[0] * x + rect[2];
        right = entry->scopeBounds[2] * x + rect[2];
        top = entry->scopeBounds[1] * y + rect[3];
        bottom = entry->scopeBounds[3] * y + rect[3];
        func_80291BE8_de(&D_8011FAC0, (s32)left, (s32)right, (s32)top,
                      (s32)bottom, arg1->clipMode);

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
