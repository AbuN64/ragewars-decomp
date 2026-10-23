#ifndef SYSTEM_2_802661FC_H
#define SYSTEM_2_802661FC_H
#include "TYPES.H"
#include "COMMON/TARGET.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Actor_func_80267958_de {
    char pad0[0x1D8];
    SharedPlayerCode802661FC *player;
};
struct Carrier {
    struct Actor_func_802676EC_de *owner;
    char pad4[0x10];
    s32 slot;
    Shield shield;
};
struct Vec4s {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
};
struct SevenBytes {
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 f;
    u8 g;
};
#endif
