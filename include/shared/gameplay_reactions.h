#ifndef SHARED_REACTION_STATISTICS_H
#define SHARED_REACTION_STATISTICS_H
#include "types.h"
#include "common/types_1dc8418c21db.h"

/* Actor, interaction and score views used to select reactions and record statistics. */

typedef struct Shared_ReactionActor Shared_ReactionActor;
typedef struct Shared_ReactionPlayer Shared_ReactionPlayer;
typedef struct Shared_ReactionFlags Shared_ReactionFlags;
typedef struct Shared_ReactionInteraction Shared_ReactionInteraction;
typedef struct Shared_ReactionObjectKind Shared_ReactionObjectKind;
typedef struct Shared_ReactionFloatValue Shared_ReactionFloatValue;
typedef struct Shared_ReactionSource Shared_ReactionSource;
typedef struct Shared_ReactionAttribution Shared_ReactionAttribution;
typedef struct Shared_ReactionPlayerIndex Shared_ReactionPlayerIndex;
typedef struct Shared_ReactionMatchState Shared_ReactionMatchState;
typedef struct Shared_ReactionStatistics Shared_ReactionStatistics;
typedef struct Shared_ReactionObjectStatistics Shared_ReactionObjectStatistics;
typedef struct Shared_ReactionPlayerRecord Shared_ReactionPlayerRecord;

/* Damage packet passed by value to the area-hit callbacks. */
typedef struct Shared_DamageParameters {
    u16 radius;
    u16 damage;
    union {
        s32 control;
        struct { s8 impulse; u8 reserved[3]; };
    };
} Shared_DamageParameters;

typedef struct Shared_DamageEvent {
    Shared_ReactionActor *target;
    s32 damage;
    f32 radius;
    s32 flags;
    Shield *shield;
} Shared_DamageEvent;

struct Shared_ReactionActor {
    u8 category;
    char pad1[3];
    u16 type;
    char pad6[2];
    Vec3 position;
    char pad14[0x58];
    f32 unk6C;
    f32 height;
    char pad74[0x70];
    u16 team;
    char padE6[0x1A];
    s32 flags;
    char pad104[0x28];
    Shared_ReactionActor *owner;
    char pad130[0x40];
    s32 unk170;
    s32 unk174;
    char pad178[0x60];
    Shared_ReactionPlayer *unk1D8;
};

struct Shared_ReactionPlayer {
    u8 unk0;
    char pad0[0x7];
    union {
        Vec3 position;
        struct { f32 unk8, unkC, unk10; };
    };
    u16* unk14;
    char pad14[0xCC];
    u16 unkE4;
    char padE4[0x1A];
    s32 unk100;
    char pad104[0x6C];
    s32 unk170;
    s32 unk174;
    char pad178[0x60];
    Shared_ReactionPlayer *unk1D8;
    char pad1DC[0x10C];
    Shared_ReactionActor actor2E8;
    char pad4C4[0x110];
    s32 unk5D4;
    Shared_ReactionStatistics * unk5D8;
    char pad5D8[0x8];
    s32 unk5E4;
    char pad5E8[0x46];
    s16 unk62E;
    char pad630[0x20];
    s16 unk650;
    char pad652[0xB86];
    f32 unk11D8;
    char pad11DC[4];
    f32 unk11E0;
    char pad11E4[0x34];
    s32 unk1218;
    char pad121C[0x10];
    s32 unk122C;
    char pad122C[0x94];
    Shared_ReactionPlayer *unk12C4;
    Shared_ReactionPlayer *unk12C8;
    Shared_ReactionPlayer *unk12CC[8];
    Shared_ReactionPlayer *unk12EC;
    s32 unk12F0;
    s32 unk12F4[8];
    char pad1314[0x24];
    s32 unk1338;
    char pad1338[0x88];
    s8 unk13C4;
    char pad13C4[0x8B];
    s32 unk1450;
    Shared_ReactionPlayerRecord * unk1454;
};

struct Shared_ReactionFlags {
    char pad0[0x52];
    u16 unk52;
};

struct Shared_ReactionInteraction {
    void* unk0;
    s32 unk4;
    char pad4[0x4];
    s32 unkC;
};

struct Shared_ReactionObjectKind {
    u8 unk0;
    char pad0[0x3];
    u16 unk4;
};

struct Shared_ReactionFloatValue {
    char pad0[0x4];
    f32 unk4;
};

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

struct Shared_ReactionPlayerIndex {
    char pad0[0x5D4];
    s32 unk5D4;
};

struct Shared_ReactionMatchState {
    char pad0[0x18B4];
    s32 unk18B4;
};

struct Shared_ReactionStatistics {
    u16 deaths_self;
    u16 deaths_other;
    u16 score;
    u16 special_kills;
    u16 pad8;
    u16 special_hits;
    u16 kills_special[8];
    u16 deaths_special[8];
    u16 kills_normal[8];
    u16 deaths_normal[8];
    char pad4C[0x41];
    u8 counted;
    char pad8E[0x1];
    u8 unk8F;
    char pad8F[0x2];
    u8 unk92;
};

struct Shared_ReactionObjectStatistics {
    char pad0[0x38];
    s32 unk38;
    s32 unk3C;
};

struct Shared_ReactionPlayerRecord {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x31C];
    s32 unk324;
    Shared_ReactionPlayer *unk328;
};

#endif
