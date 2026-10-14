#include "common/unused.h"
#include "shared/gameplay_transition.h"
#include "span_1000/code_8021CD70.h"
#include "span_1000/code_8022C894.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802192C0.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"
#include "n64sdk.h"
#include "span_1000/code_8026AC38.h"










extern s32 D_800D297C;

extern u8 D_801462E5;

extern s32 D_801468F4;




extern Gfx * D_80110634;

extern f32 func_8024D284_de(void *arg0);
extern void func_8028C6D4_de(void *arg0, void *arg1, void *arg2);

extern void func_80249E28_de(void *arg0, void *arg1);
extern void func_8021C698_de(void *arg0, void *arg1);










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
