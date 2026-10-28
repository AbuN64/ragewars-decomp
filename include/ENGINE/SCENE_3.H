#ifndef ENGINE_SCENE_3_H
#define ENGINE_SCENE_3_H
#include "COMMON/EXTERNS_9.H"
#include "SCENE/SCENE_UPDATEANDDRAWWORLD.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/OBJB.H"
#include "MENU/8044ACCC.H"
#include "COMMON/WORLD.H"
extern void Scene_RequestVisibleGridSections(DraftStreamWorld *);
extern void Scene_BuildCachedGeometry(DraftStreamWorld*world);
extern const char D_800C5210_de[];
extern void Scene_DrawCachedOpaqueGeometry(SceneSceneDrawCachedOpaqueGeometry *scene, void *camera);
extern void Scene_BuildPlacedActors(World *world, struct Shape_typemap_165 * *handle);
extern void Scene_LoadGridCells(Level_func_8044CD8C_de *level);
extern void Scene_InitPreview(Shared_World *world, s32 level);
#endif
