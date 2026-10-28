#ifndef RENDER_VISIBLE_EFFECT_NODE_VIEWS_H
#define RENDER_VISIBLE_EFFECT_NODE_VIEWS_H
#include "TYPES.H"
struct ObjectLinks3C0C {
    char pad0[0x3C00];
    void * unk_3C00;
    char pad3C00[0x3C04 - 0x3C00 - sizeof(void*)];
    void * next;
    char pad3C04[0x3C08 - 0x3C04 - sizeof(void*)];
    void * unk_3C08;
};
struct ObjectLinks1E0 {
    char pad0[0x1C8];
    s32 unk_1C8;
    char pad1C8[0x1D0 - 0x1C8 - sizeof(s32)];
    s32 unk_1D0;
    char pad1D0[0x1D8 - 0x1D0 - sizeof(s32)];
    void * unk_1D8;
    char pad1D8[0x1DC - 0x1D8 - sizeof(void*)];
    void * unk_1DC;
};
struct ContainerRecAt3C04 {
    char pad0[0x3C04];
    struct NodeSetN64CollectVisibleEffectNodes *head;
};
#endif
