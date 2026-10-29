#ifndef RENDER_VISIBLE_EFFECT_NODE_VIEWS_H
#define RENDER_VISIBLE_EFFECT_NODE_VIEWS_H
#include "TYPES.H"
struct ActorPoolFreeListView {
    char pad0[0x3C00];
    void * freeHead;
    char pad3C00[0x3C04 - 0x3C00 - sizeof(void*)];
    void * next;
    char pad3C04[0x3C08 - 0x3C04 - sizeof(void*)];
    void * activeTail;
};
struct VisibleEffectNodeLinks {
    char pad0[0x1C8];
    s32 clearedWord;
    char pad1C8[0x1D0 - 0x1C8 - sizeof(s32)];
    s32 flags;
    char pad1D0[0x1D8 - 0x1D0 - sizeof(s32)];
    void * previous;
    char pad1D8[0x1DC - 0x1D8 - sizeof(void*)];
    void * next;
};
struct VisibleEffectPoolView {
    char pad0[0x3C04];
    struct NodeSetN64CollectVisibleEffectNodes *head;
};
#endif
