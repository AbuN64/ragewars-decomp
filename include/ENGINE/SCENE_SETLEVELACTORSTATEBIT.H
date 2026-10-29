#ifndef ENGINE_SCENE_SETLEVELACTORSTATEBIT_H
#define ENGINE_SCENE_SETLEVELACTORSTATEBIT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/COLORENTRY.H"
struct ObjectCSceneStartEventClips {
    char pad[0xA8];
    struct StridedTable *clipGroupKeys;
    struct StridedTable *clipDefinitions;
};
struct Container {
    char pad0[0x138];
    struct SceneActorMatchRecord *actors;
    s32 actorCursor;
    s32 actorCount;
};
struct ScenePackSectionTableView {
    char pad0[0x78];
    void * sectionTable;
};
struct SceneActiveResourceCountView {
    char pad0[0x10BC];
    int activeResourceCount;
};
struct SceneNestedPackSectionTableView {
    char pad0[0x7C];
    void * nestedSectionTable;
};
struct OwnerSceneUnlockActiveSectionResources {
    char pad0[0x944];
    s32 reservedWord944;
    char pad948[0xC4C - 0x948];
    s32 reservedWordC4C;
    char padC50[0x10BC - 0xC50];
    s32 activeResourceCount;
    char pad10C0[0x1500 - 0x10C0];
    s32 prevCount;
    s32 count;
    Triple entries[1];
};
typedef struct AnimationPoseFrameSet {
    s32 stride;
    s32 count;
    AnimationPoseFrame frames[1];
} AnimationPoseFrameSet;
struct Field_void_80 {
    char pad[0x80];
    void * value;
};
#endif
