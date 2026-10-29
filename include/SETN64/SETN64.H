#ifndef SETN64_SETN64_H
#define SETN64_SETN64_H
#include "COMMON/RESULTS.H"
#include "RENDER/VISIBLE_EFFECT_NODE_VIEWS.H"
extern void *SetN64_GetPackSection(void *table, s32 index);
extern s32 SetN64_GetPackSectionOffsetAndSize(s32 directoryAddress, s32 sectionIndex, s32 *sectionSizeOut);
extern void SetN64_GetPackBaseAndSize(int *directory, int * *packBaseOut, int *packSizeOut);
extern int SetN64_GetRecordBlockSize(int *recordHeader);
extern void SetN64_GetChunkStorage(void *, void * *, s32 *);
extern void *SetN64_GetChunkPayload(int *, int *);
extern void SetN64_TransposeRecords(void *sourceBlock, void *destinationBlock, s32 copyBack);
extern void SetN64_UpdateEffectPool(EffectSlotPool *world);
extern void SetN64_InitializeEffectSlot(struct EffectSlot *effectSlot);
extern void SetN64_UpdateEffectMotionAndBounds(SceneEffect *effect);
extern void SetN64_DrawVisibleEffects(char *effectPool, char *view);
extern void *SetN64_AllocateActorFromPool(ActorPoolFreeListView *);
#endif
