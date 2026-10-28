#ifndef RENDER_8026AC38_H
#define RENDER_8026AC38_H
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
/* The fill/tint override the material and menu drawers apply: D_800D15E0 is its mode (0 = off, 1..6 colour/fade
 * modes) and D_800D15E4 its colour, RGBA 0..255 plus the fade target alpha [4]. The ROM reaches the two through
 * separate addresses (a shared struct base breaks 18 exact fns), so they are two objects. */
extern s32 D_800D15E0;
extern f32 D_800D15E4[5];
#endif
