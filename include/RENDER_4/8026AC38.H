#ifndef RENDER_4_8026AC38_H
#define RENDER_4_8026AC38_H
#include "TYPES.H"
struct Material {
    u8 pad[6];
    u8 flags;
};
struct Owner104 {
    char pad0[0x102];
    unsigned short flags;
};
struct ObjectState18 {
    s32 flags;
    u8 padding4[0xC];
    u8 color[4];
    u8 fog[4];
};
struct ObjRecAtCV2 {
    void *unk0;
    void *unk4;
    void *unk8;
    s32 unkC;
};
#endif
