#ifndef COMMON_GAMEPLAY_REACTIONS_H
#define COMMON_GAMEPLAY_REACTIONS_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

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


typedef struct CDamageInfo_t {
    Shared_ReactionActor *target;
    s32 damage;
    f32 radius;
    s32 flags;
    Shield *shield;
} CDamageInfo;

struct Shared_ReactionObjectKind {
    u8 unk0;
    char pad0[0x3];
    u16 unk4;
};

struct Shared_ReactionActor {
    union {
        struct {
            u8 category;
            char pad1[3];
            u16 type;
            char pad6[2];
        };
        Shared_ReactionObjectKind objectKind;
    };
    CVector3 position;
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
        CVector3 position;
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
    void *owner; /* 0x5DC: actor that shows the reaction text */
    char pad5E0[0x4];
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
    char pad1230[0x90];
    f32 reserve; /* 0x12C0: reaction reserve */
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
    char pad13C5[0x23];
    s32 messageNext; /* 0x13E8: next slot of messages */
    char messages[4][25]; /* 0x13EC */
    s32 unk1450;
    Shared_ReactionPlayerRecord * unk1454;
};

struct Shared_ReactionFlags {
    char pad0[0x20];
    f32 height; /* 0x20 */
    char pad24[0x44 - 0x24];
    u32 flags; /* 0x44 */
    char pad48[0x52 - 0x48];
    u16 unk52;
    char pad54[2];
    u16 mask; /* 0x56: effect objects enabled for this record */
};

struct Shared_ReactionInteraction {
    void* unk0;
    s32 unk4;
    f32 magnitude;
    s32 unkC;
    s32 unk10;
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
    char pad4C[0x38];
    char name[9]; /* 0x84: player name, terminated before counted */
    u8 counted;
    char pad8E[0x1];
    u8 unk8F;
    char pad90[0x2];
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
extern f32 gReactionReserveMaximum;
extern void func_80219A40_de(Shared_ReactionActor *, void *, Shared_ReactionInteraction *);
extern void Render_PostKillMessages(Shared_ReactionPlayer *, Shared_ReactionPlayer *, Shared_ReactionInteraction *);
#endif
