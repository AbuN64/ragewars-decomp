#ifndef SCENE_802508E0_9_H
#define SCENE_802508E0_9_H
#include "COMMON/RESOURCELOCKSTATE.H"
extern s32 Cache_FinishResourceSlot();
struct Node80253610;
extern void Cache_UnlockResource(void *heap, struct Node80253610 *resource);
extern void Cache_MarkResourceInUse(s32 heap, struct Node80253610 *resource);
#endif
