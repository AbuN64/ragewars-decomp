#ifndef MENU_ITEMS_SCENE_7_H
#define MENU_ITEMS_SCENE_7_H
#include "COMMON/OBJB.H"
#include "COMMON/WORLD.H"
#include "MENU/8044ACCC.H"
extern void Scene_ResetSelectionState(char *);
extern void Scene_InitPreview(struct Shared_World *world, s32 level);
extern void Scene_ChangePreviewSelection(ItemsPreviewStateB *state, int selection);
extern s32 OvlScene_FindPlacedObjectsByKey(void *world, s32 kind, s32 key, Shared_Placed *out, s32 max);
#endif
