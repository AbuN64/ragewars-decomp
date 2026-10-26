#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/S1.H"

void Ovlgame_InitializeSceneEffectPool(ObjRecAt5F14 *arg0) {
    SceneEffect *sceneEffect;
    s32 i;

    func_80255CA0_de(&arg0->unk5F00, 0x2E8, 0x2EC);
    func_80255CA0_de(&arg0->unk5F14, 0x2E8, 0x2EC);
    i = 0;
    sceneEffect = arg0->effects;
    do {
        func_80255D14_de(&arg0->unk5F00, sceneEffect);
        i += 1;
        sceneEffect += 1;
    } while (i < 0x20);
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_8044AFD4[3] = {
    0x61775200, 0x00100100, 0x00080091,
};
#endif
