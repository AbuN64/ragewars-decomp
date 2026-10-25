#ifndef COMMON_SHARED_GAMESLOT_H
#define COMMON_SHARED_GAMESLOT_H
#include "TYPES.H"
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RENDERCOUNTERS.H"
typedef struct Shared_GameSlot Shared_GameSlot;
struct Shared_GameSlot {
    u8 enabled;
    u8 unknown01[6];
    u8 slot;
    s8 kind;
    u8 unknown09[0x10];
    u8 controller;
    u8 unknown1A[2];
    u8 role;
    u8 escort;
    u8 secondListMode;
    u8 unknown1F[0x77];
};
typedef struct Shared_Game Shared_Game;
struct Shared_Game {
    u32 flags;
    s32 unlockedLevels; /* 0x04: one bit per level, tested with levelBit() */
    u32 sceneMask; /* 0x08: bits tested against each actor definition */
    u8 unknown0C;
    u8 controllerMode;
    u8 unknown0E[2];
    u32 buttons; /* 0x10 */
    u16 packedOptions; /* 0x14 */
    u8 hudFade;
    u8 unknown17;
    u8 volume[3]; /* 0x18: the three audio option bytes */
    u8 firstListMode;
    u8 unknown1C;
    u8 local;
    u8 mode1E;
    u8 unknown1F;
    /* The ROM addresses these overlapping arrays from Game+0xD0 and +0x148.
     * Each 0x96-byte settings record's +0x78/+0x7F fields are the same
     * enabled/slot bytes used by the existing slots array. */
    union {
        struct {
            f32 speedFactor; /* 0x20 */
            s8 laps; /* +0x24 */
            s8 players; /* +0x25 */
            s8 trialOther; /* +0x26: func_8042EB10_de */
            s8 trialScore; /* +0x27 */
            u8 unknown28[3];
            u8 bonusIcon; /* +0x2B: shows the 0x2DA HUD icon */
            u8 unknown2C;
            u8 menuToggles[9]; /* +0x2D: on/off rows 2..9 of the options list (+0x34 unused) */
            u8 unknown36[0x148 - 0x36];
            Shared_GameSlot slots[8];
            u8 unknown5F8[0x34];
            s32 unk62C;
            u8 unknown630[0x40];
            s32 split;
            u32 unknown674[3];
            s32 humanWon;
            s32 threePlayerLayout;
        };
        struct {
            u8 reserved20[0xB0];
            Shared_PlayerSettingsRecord playerSettings[8];
            u8 reserved580;
            u8 language;
            u8 reserved582[0x32];
            s32 state;
            u8 reserved5B8[0x20];
            CGameStatus counters; /* +0x5D8: D_801468A0 */
        };
    };
    /* origin/legacy shared/game.h retains the complete 0xCAC-byte game record. */
    u8 reserved688[0xCAC - 0x688];
};
extern Shared_Game D_801462C8;

typedef char RenderCounters_size_check[(sizeof(CGameStatus) == 0xB0) ? 1 : -1];
typedef char Shared_Game_size_check[(sizeof(Shared_Game) == 0xCAC) ? 1 : -1];
typedef char Shared_Game_settings_offset_check[(((u32)&((Shared_Game *)0)->playerSettings) == 0xD0) ? 1 : -1];
typedef char Shared_Game_slots_offset_check[(((u32)&((Shared_Game *)0)->slots) == 0x148) ? 1 : -1];
#endif
