#ifndef GFX_802A8A94_H
#define GFX_802A8A94_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ObjectLinksC_2 {
    unsigned char padding_0[4];
    s32 *unk_4;
    s32 unk_8;
};
struct IntegerState48 {
    unsigned char padding_0[60];
    s32 unk_3C;
    s32 unk_40;
    s32 unk_44;
};
struct IntegerState90 {
    unsigned char padding_0[132];
    s32 unk_84;
    s32 unk_88;
    s32 unk_8C;
};
struct COverlay {
    s32 active;
    s32 *script;
    s32 state;
    s32 wait;
    f32 x;
    f32 y;
    f32 targetX;
    f32 targetY;
    f32 velX;
    f32 velY;
    f32 accelX;
    f32 accelY;
    f32 rate;
    u8 pad34[4];
    s32 handle; /* 0x38: resource handle initialized by the mover constructor */
};
struct Table802AB8DC {
    s16 count;
    u8 pad2[6];
    Entry802AB8DC entries[1];
};
#endif
