#ifndef ENGINE_SCENE_SETLEVELACTORSTATEBIT_H
#define ENGINE_SCENE_SETLEVELACTORSTATEBIT_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/COLORENTRY.H"
struct ObjectCSceneStartEventClips {
    char pad[0xA8];
    struct StridedTable *unkA8;
    struct StridedTable *unkAC;
};
struct Container {
    char pad0[0x138];
    struct RecordRecAtE4 *unk138;
    s32 unk13C;
    s32 unk140;
};
struct ObjRecAt78V1 {
    char pad0[0x78];
    void * unk78;
};
struct ObjRecAt10BC {
    char pad0[0x10BC];
    int unk10BC;
};
struct ObjRecAt7C {
    char pad0[0x7C];
    void * unk7C;
};
struct OwnerSceneUnlockActiveSectionResources {
    char pad0[0x944];
    s32 unk944;
    char pad948[0xC4C - 0x948];
    s32 unkC4C;
    char padC50[0x10BC - 0xC50];
    s32 unk10BC;
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
