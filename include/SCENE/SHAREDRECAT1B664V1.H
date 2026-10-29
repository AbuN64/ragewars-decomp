#ifndef SCENE_SHAREDRECAT1B664V1_H
#define SCENE_SHAREDRECAT1B664V1_H
typedef struct SceneLoadedResourceView SceneLoadedResourceView;
struct SceneLoadedResourceView {
    char pad0[0x1B664];
    void * loadedResource; /* +0x1B664: src/Scene_LoadLevelResources_SceneResourceState.c */
};
typedef char SceneLoadedResourceViewSizeCheck[(sizeof(SceneLoadedResourceView) == 0x1B668) ? 1 : -1];
#endif
