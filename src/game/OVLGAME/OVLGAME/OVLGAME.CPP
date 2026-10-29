#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/S1.H"

void Ovlgame_InitializeSceneEffectPool(struct CAnimPool *animationPool) {
    SceneEffect *sceneEffect;
    s32 i;

    List_InitializeIntrusive(&animationPool->FreeList, 0x2E8, 0x2EC);
    List_InitializeIntrusive(&animationPool->UsedList, 0x2E8, 0x2EC);
    i = 0;
    sceneEffect = animationPool->DynAnims;
    do {
        List_AppendIntrusive(&animationPool->FreeList, sceneEffect);
        i += 1;
        sceneEffect += 1;
    } while (i < 0x20);
}

#if defined(VERSION_US)
unsigned int k_OvlgameEncodedWords[3] = {
    0x61775200, 0x00100100, 0x00080091,
};
#endif
