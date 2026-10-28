#ifndef AUDIO_LIST_AND_CHANNEL_VIEWS_H
#define AUDIO_LIST_AND_CHANNEL_VIEWS_H
#include "TYPES.H"
#include "COMMON/LISTNODE.H"
#include "COMMON/UNUSED.H"
struct Lists {
    char pad0[4];
    NodeRecAtAC first;
    char padB4[0x24];
    NodeRecAtAC second;
};
struct ManagerRecAtD8V2 {
    struct SceneCode802591C0 *scene;
    Link_func_80259784_de active;
    char padC[0xCC];
    Link_func_80259784_de free;
};
struct ObjectLinks8 {
    void *unk_0;
    void *unk_4;
};
struct CellCode802591C0 {
    s32 index;
    s32 pad4;
    s32 texture;
    s32 sequence;
    s32 frame;
    char pad14[0x44 - 0x14];
    char data[1];
};
struct ManagerRecAtD8V1 {
    s32 *scene;
    LinkAudioWorldQueuePrioritizedSound active;
    char padC[0xCC];
    LinkAudioWorldQueuePrioritizedSound free;
};
struct LinkPair {
    void **first;
    void **second;
};
struct Bytes12 {
    char bytes[12];
};
struct ViewRecAtB0 {
    char pad0[0x10];
    Motion motion;
    Angles angles;
    char pad68[4];
    f32 pitch;
    f32 pitchStep;
    char pad74[0xB0 - 0x74];
    s32 presets;
};
#endif
