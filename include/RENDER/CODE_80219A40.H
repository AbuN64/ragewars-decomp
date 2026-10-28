#ifndef RENDER_2_CODE_80219A40_H
#define RENDER_2_CODE_80219A40_H
#include "TYPES.H"
#include "COMMON/GAMEPLAY_REACTIONS.H"
struct Shared_ReactionSource {
    u8 unk0;
    char pad0[0x3];
    u16 unk4;
    char pad4[0x2];
    f32 unk8;
    char pad8[0x4];
    f32 unk10;
    char pad10[0xEC];
    s32 unk100;
    char pad100[0x28];
    Shared_ReactionPlayer *unk12C;
    char pad12C[0xA8];
    Shared_ReactionPlayer *unk1D8;
};
struct Shared_ReactionAttribution {
    u8 unk0;
    char pad0[0x3];
    u16 unk4;
    char pad4[0xFA];
    s32 unk100;
    char pad100[0xD4];
    Shared_ReactionPlayerIndex * unk1D8;
};
struct Shared_ReactionMatchState {
    char pad0[0x18B4];
    s32 unk18B4;
};
struct Shared_ReactionObjectStatistics {
    char pad0[0x38];
    s32 unk38;
    s32 unk3C;
};
#endif
