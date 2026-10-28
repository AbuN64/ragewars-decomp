#ifndef ENGINE_SCENE_DRAWTRANSITIONCOLOROVERLAY_H
#define ENGINE_SCENE_DRAWTRANSITIONCOLOROVERLAY_H
#include "COMMON/COLORENTRY.H"
#include "ENGINE/SCENE_SETLEVELACTORSTATEBIT.H"
#include "COMMON/WORLD.H"
extern void *Scene_GetEffectCurveRecord(Shared_World *world, s32 index);
extern s32 Scene_CollectMatchingLevelActors(Container *arg0, s32 key0, s32 key1, s32 key2, RecordRecAtE4 **out, s32 max);
#endif
