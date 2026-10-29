#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/HUD_REFERENCE_VIEWPORT_HEIGHT.H"
#include "COMMON/WORLD.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/TRIPLE.H"
#include "RENDER/PLAYER_SPAWN_PLACEMENT.H"
#include "CINEMA/CINEMA.H"

extern f32 g_respawnPlayerInitialPartScale;
/* ROM offsets of the actor part tables: each version names its own copies. */
#if defined(VERSION_US_REV1)
extern u8 g_Gobjinst_BuildActorTransformAddressUsRev1[];
#define ACTORPART_T28C g_Gobjinst_BuildActorTransformAddressUsRev1
extern u8 g_Playerai_ApplyRangedPitchToMatrixAddressUsRev1[];
#define ACTORPART_T290 g_Playerai_ApplyRangedPitchToMatrixAddressUsRev1
extern u8 g_playerDamageReactionCallbackAddressUsRev1[];
#define ACTORPART_T280 g_playerDamageReactionCallbackAddressUsRev1
extern u8 g_Playerai_ApplyLinkedProjectileStatusAddressUsRev1[];
#define ACTORPART_T288 g_Playerai_ApplyLinkedProjectileStatusAddressUsRev1
extern u8 g_Player_DrawPlayerBodyAndWeaponAddressUsRev1[];
#define ACTORPART_ACTION g_Player_DrawPlayerBodyAndWeaponAddressUsRev1
extern u8 g_Player_BuildWeaponHandTransformAddressUsRev1[];
#define ACTORPART_PART1_T28C g_Player_BuildWeaponHandTransformAddressUsRev1
#elif defined(VERSION_US)
extern u8 g_Gobjinst_BuildActorTransformAddressUs[];
#define ACTORPART_T28C g_Gobjinst_BuildActorTransformAddressUs
extern u8 g_Playerai_ApplyRangedPitchToMatrixAddressUs[];
#define ACTORPART_T290 g_Playerai_ApplyRangedPitchToMatrixAddressUs
extern u8 g_playerDamageReactionCallbackAddressUs[];
#define ACTORPART_T280 g_playerDamageReactionCallbackAddressUs
extern u8 g_Playerai_ApplyLinkedProjectileStatusAddressUs[];
#define ACTORPART_T288 g_Playerai_ApplyLinkedProjectileStatusAddressUs
extern u8 g_Player_DrawPlayerBodyAndWeaponAddressUs[];
#define ACTORPART_ACTION g_Player_DrawPlayerBodyAndWeaponAddressUs
extern u8 g_Player_BuildWeaponHandTransformAddressUs[];
#define ACTORPART_PART1_T28C g_Player_BuildWeaponHandTransformAddressUs
#elif defined(VERSION_DE)
extern u8 g_Gobjinst_BuildActorTransformAddressDe[];
#define ACTORPART_T28C g_Gobjinst_BuildActorTransformAddressDe
extern u8 g_Playerai_ApplyRangedPitchToMatrixAddressDe[];
#define ACTORPART_T290 g_Playerai_ApplyRangedPitchToMatrixAddressDe
extern u8 g_playerDamageReactionCallbackAddressDe[];
#define ACTORPART_T280 g_playerDamageReactionCallbackAddressDe
extern u8 g_Playerai_ApplyLinkedProjectileStatusAddressDe[];
#define ACTORPART_T288 g_Playerai_ApplyLinkedProjectileStatusAddressDe
extern u8 g_Player_DrawPlayerBodyAndWeaponAddressDe[];
#define ACTORPART_ACTION g_Player_DrawPlayerBodyAndWeaponAddressDe
extern u8 g_Player_BuildWeaponHandTransformAddressDe[];
#define ACTORPART_PART1_T28C g_Player_BuildWeaponHandTransformAddressDe
#elif defined(VERSION_EU)
extern u8 g_Gobjinst_BuildActorTransformAddressEu[];
#define ACTORPART_T28C g_Gobjinst_BuildActorTransformAddressEu
extern u8 g_Playerai_ApplyRangedPitchToMatrixAddressEu[];
#define ACTORPART_T290 g_Playerai_ApplyRangedPitchToMatrixAddressEu
extern u8 g_playerDamageReactionCallbackAddressEu[];
#define ACTORPART_T280 g_playerDamageReactionCallbackAddressEu
extern u8 g_Playerai_ApplyLinkedProjectileStatusAddressEu[];
#define ACTORPART_T288 g_Playerai_ApplyLinkedProjectileStatusAddressEu
extern u8 g_Player_DrawPlayerBodyAndWeaponAddressEu[];
#define ACTORPART_ACTION g_Player_DrawPlayerBodyAndWeaponAddressEu
extern u8 g_Player_BuildWeaponHandTransformAddressEu[];
#define ACTORPART_PART1_T28C g_Player_BuildWeaponHandTransformAddressEu
#elif defined(VERSION_EU_X)
extern u8 g_Gobjinst_BuildActorTransformAddressEuX[];
#define ACTORPART_T28C g_Gobjinst_BuildActorTransformAddressEuX
extern u8 g_Playerai_ApplyRangedPitchToMatrixAddressEuX[];
#define ACTORPART_T290 g_Playerai_ApplyRangedPitchToMatrixAddressEuX
extern u8 g_playerDamageReactionCallbackAddressEuX[];
#define ACTORPART_T280 g_playerDamageReactionCallbackAddressEuX
extern u8 g_Playerai_ApplyLinkedProjectileStatusAddressEuX[];
#define ACTORPART_T288 g_Playerai_ApplyLinkedProjectileStatusAddressEuX
extern u8 g_Player_DrawPlayerBodyAndWeaponAddressEuX[];
#define ACTORPART_ACTION g_Player_DrawPlayerBodyAndWeaponAddressEuX
extern u8 g_Player_BuildWeaponHandTransformAddressEuX[];
#define ACTORPART_PART1_T28C g_Player_BuildWeaponHandTransformAddressEuX
#endif
extern void Gobjinst_InitializePlacedActor(void *, void *, void *, s32);
extern void Actor_RequestActorState(void *, void *, s32);
extern void Weaponai_ApplyWeaponSwitch(void *, void *);
extern void Player_UpdatePlayerCamera(void *, void *);
#include "MENU/INITVIEW.H"
#include "ACHIEVE/ACHIEVE.H"
/* Initialises an actor and its embedded part at 0x2E8: sets the shared table pointers and flag bits (one flag
 * depends on g_frontendScreenStatus.settings.local), runs the part setup calls, then copies the view's position into the actor. */
typedef struct ActorInitPart {
    u8 pad0[0x18]; InitView *view;
    u8 pad1C[0x34]; f32 x, y, z;
    u8 pad5C[0xA4]; u32 flags;
    u8 pad104[0xA0]; s8 marker;
    u8 pad1A5[0x33]; void *owner;
    u8 pad1DC[0xA0]; void *action;
    void *table280; u8 pad284[4]; void *table288;
    void *table28C; void *table290; u8 pad294[0x54];
} ActorInitPart;
typedef struct ActorInitRecord {
    ActorInitPart part[2];
    u8 pad5D0[0xC]; void *auxiliary;
    u8 pad5E0[0x4E]; s16 selection;
} ActorInitRecord;
void Player_InitActorParts(SharedPlayer *player, LevelPlacedActorRecord *rec, s32 mode, s32 index) {
    char *actor = (char *)player;
    ActorInitRecord *record = (ActorInitRecord *)player;
    u32 flags;
    u32 t1, t2, t3;
    InitView *view;
    record->part[0].owner = actor;
    Gobjinst_InitializePlacedActor(actor, rec, (void *)mode, 0);
    record->part[0].owner = actor;
    t1 = record->part[0].flags | 0x100000;
    t2 = t1 | 0x10000;
    t3 = t2 | 0x1000000;
    flags = t3 | 0x2000000;
    record->part[0].flags = flags;
    if (g_frontendScreenStatus.settings.local == 0) {
        record->part[0].flags = flags | 0x10000000;
    }
    record->part[0].table28C = ACTORPART_T28C;
    record->part[0].table290 = ACTORPART_T290;
    record->part[0].table280 = ACTORPART_T280;
    record->part[0].table288 = ACTORPART_T288;
    if (g_frontendScreenStatus.settings.local != 0) {
        record->part[0].action = ACTORPART_ACTION;
    }
    record->part[1].owner = actor;
    Gobjinst_InitializePlacedActor((actor + 0x2E8), rec, (void *)mode, 0);
    record->part[1].table28C = ACTORPART_PART1_T28C;
    record->part[1].marker = -1;
    record->part[1].flags |= 0x200000;
    record->part[1].x = g_respawnPlayerInitialPartScale;
    record->part[1].y = g_respawnPlayerInitialPartScale;
    record->part[1].z = g_respawnPlayerInitialPartScale;
    record->part[1].owner = actor;
    record->part[1].table280 = ACTORPART_T280;
    record->part[1].table288 = ACTORPART_T288;
    record->selection = -1;
    record->part[1].flags &= 0xFFFEFFFF;
    Actor_RequestActorState((actor + 0x2E8), (actor + 0x458), 0);
    Weaponai_ApplyWeaponSwitch((actor + 0x2E8), (actor + 0x458));
    Player_UpdatePlayerCamera(actor, actor);
    if (record->auxiliary != 0) {
        Cinema_UpdateSequenceTrack(record->auxiliary);
    }
    record->part[0].x = (record->part[0].view)->x;
    record->part[0].y = (record->part[0].view)->y;
    record->part[0].z = (record->part[0].view)->z;
    view = record->part[0].view;
    view->flags &= ~4;
}

#if defined(NON_MATCHING) || defined(VERSION_US_REV1) || defined(VERSION_US) || defined(VERSION_DE)
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
extern char g_localPlayerProfiles[];
extern void *g_currentStagePreset;
extern char g_roundStartModeSpecificDialogTable[], g_playerMenuDialogTable[], g_roundStartDefaultDialogTable[];
struct RespawnPlayer;
extern s32 Control_IsSnapshotActive(void);
extern void *Pools_RecycleModel(void *);
extern void TeamSelect_ResetWeaponWheel(void *);
extern void TeamSelect_ResetTeamWheel(void *);
extern u32 Player_GetLevelProgress(void *, s32);
extern void Player_ResetPlayerWeapons(struct RespawnPlayer *);
extern void Player_ResetRespawnedPlayer(struct RespawnPlayer *);
extern void Menu_OpenDialog(void *, void *, void *, s32, s32);
/* Resets a player/actor record for a new run: marks it active, stores the character, picks up the HUD
 * object, clears the per-slot counters and weapon tables, selects the start mode from the multiplayer setting
 * and zeroes the per-player entries of the two global tables. */
typedef struct PlayerRoundStats {
    s16 totals[6];
    s16 counts[4][8];
} PlayerRoundStats;

typedef struct PlayerRoundReset {
    u8 reserved0[0x5D8];
    PlayerRoundStats *stats;
    u8 reserved5DC[0x68];
    u8 counters[2][6];
} PlayerRoundReset;

extern u8 g_gameControllerMode; /* MIXED Player_ResetPlayerForRound */
void Player_ResetPlayerForRound(void *actor, s32 character) {
    s32 i;
    unsigned long counterAddress;
    s32 openFlag = 0;
    char *globals;
    Control_IsSnapshotActive();
    FIELD(s32, actor, 0x5D0) = 1;
    FIELD(s32, actor, 0x5E0) = character;
    if (FIELD(s32, actor, 0x1450) == 0) {
        FIELD(void *, actor, 0x5DC) = Pools_RecycleModel(&g_frontendScreenStatus);
        if (FIELD(s32, &g_frontendScreenStatus, 0x18C4) != 0) {
            FIELD(s32, actor, 0x1450) = 1;
        }
    } else {
        FIELD(s32, actor, 0x5DC) = 0;
    }
    TeamSelect_ResetWeaponWheel((char *)actor + 0x938);
    TeamSelect_ResetTeamWheel((char *)actor + 0xCCC);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    for (i = 1; i < 22; i++) {
        FIELD(u8, actor, 0x602 + i * 2) = 0;
        FIELD(s8, actor, 0x603 + i * 2) = -1;
    }
    FIELD(u8, actor, 0x602) = 1;
    FIELD(u8, actor, 0x603) = 0;
    FIELD(u8, actor, 0x606) = 1;
    FIELD(u8, actor, 0x607) = 5;
    FIELD(u8, actor, 0x608) = 1;
    FIELD(u8, actor, 0x609) = 2;
    FIELD(u8, actor, 0x60A) = 1;
    FIELD(u8, actor, 0x60B) = 1;
    FIELD(u8, actor, 0x616) = 1;
    FIELD(u8, actor, 0x617) = 4;
    FIELD(u8, actor, 0x61E) = 1;
    FIELD(u8, actor, 0x61F) = 6;
#endif
    FIELD(s16, actor, 0x5E8) = 0;
    i = 5;
    counterAddress = (unsigned long)actor + i;
    do {
        *(u8 *)(counterAddress + 0x644) = 0;
        counterAddress--;
    } while (--i >= 0);
    i = 5;
    counterAddress = (unsigned long)actor + i;
    do {
        *(u8 *)(counterAddress + 0x64A) = 0;
        counterAddress--;
    } while (--i >= 0);
    if (g_frontendScreenStatus.settings.local != 0) {
        if (g_gameControllerMode == 1 && FIELD(s32, actor, 0x1450) == 0) {
            u32 value = Player_GetLevelProgress(g_localPlayerProfiles + FIELD(s32, actor, 0x5D4) * 0x190, FIELD(s8, FIELD(void *, actor, 0x5D8), 0x80));
            FIELD(s32, actor, 0x133C) = ((value & 0xFF) >> 1) + 1;
        }
        if (g_gameControllerMode == 4 && FIELD(s32, actor, 0x1450) == 0 && g_currentStagePreset != 0) {
            FIELD(s32, actor, 0x133C) = FIELD(u8, g_currentStagePreset, 0x28);
        }
        FIELD(s16, actor, 0x5EA) = 1;
    } else {
        FIELD(s16, actor, 0x5EA) = 3;
    }
    FIELD(s32, actor, 0x13C8) = 0;
    Player_ResetPlayerWeapons((struct RespawnPlayer *)actor);
    FIELD(s32, actor, 0x670) = 0;
    FIELD(s32, actor, 0x674) = 0;
    FIELD(s32, actor, 0x86C) = -1;
    FIELD(s32, actor, 0x870) = -1;
    for (i = 0; i < 8; i++) {
        ((PlayerRoundReset *)actor)->stats->counts[2][i] = 0;
        ((PlayerRoundReset *)actor)->stats->counts[3][i] = 0;
        ((PlayerRoundReset *)actor)->stats->counts[0][i] = 0;
        ((PlayerRoundReset *)actor)->stats->counts[1][i] = 0;
    }
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0x0) = 0;
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0x2) = 0;
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0x4) = 0;
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0x6) = 0;
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0xA) = 0;
    FIELD(s16, FIELD(void *, actor, 0x5D8), 0x8) = 0;
    FIELD(u8, FIELD(void *, actor, 0x5D8), 0x8D) = 0;
    FIELD(u8, FIELD(void *, actor, 0x5D8), 0x8E) = 0;
    FIELD(u8, FIELD(void *, actor, 0x5D8), 0x8F) = 0;
    FIELD(u8, FIELD(void *, actor, 0x5D8), 0x90) = 0;
    FIELD(s32, actor, 0x638) = 0;
    FIELD(s32, actor, 0x63C) = 1;
    FIELD(s32, actor, 0x640) = 0;
    FIELD(s32, actor, 0x868) = 1;
    Player_ResetRespawnedPlayer((struct RespawnPlayer *)actor);
    globals = (char *)&g_gameSettings;
    if (FIELD(u8, globals, 0x1D) != 0) {
        FIELD(s32, actor, 0x13E8) = 0;
    }
    if (openFlag != 0) {
        char *table;
        if (FIELD(u8, globals, 0x1D) != 0) {
            FIELD(u8, FIELD(void *, actor, 0x5D8), 0x80) = 0;
            FIELD(s32, actor, 0x5E0) = 0;
            FIELD(s32, actor, 0x85C) = 1;
            table = g_roundStartModeSpecificDialogTable;
            if (FIELD(s32, globals, 0x5FC) == 0) {
                table = g_playerMenuDialogTable;
            }
        } else {
            table = g_roundStartDefaultDialogTable;
        }
        Menu_OpenDialog((char *)FIELD(void *, actor, 0x5DC) + 0x554, table, actor, FIELD(s32, actor, 0x698), FIELD(s32, actor, 0x5D4));
    }
    g_playerHitCounts[FIELD(s32, actor, 0x5D4)] = 0;
    g_playerCountedShots[FIELD(s32, actor, 0x5D4)] = 0;

}
#else
INCLUDE_ASM("ovl_frontendMenu", Player_ResetPlayerForRound);
#endif

#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern char g_hudStatusWidgetMoverScriptOne[], g_hudStatusWidgetMoverScriptTwo[], g_hudStatusWidgetMoverScriptThree[], g_hudStatusWidgetMoverScriptFour[], g_hudLivesInitialMoverScript[];
extern char k_PlaceplayerlightEncodedWords[], g_hudScoreInitialMoverScript[], g_hudCountInitialMoverScript[], g_hudSquadInitialMoverScript[];
extern u32 g_activeActorKind;
extern void Playerai_LoadActorModel(void *actor);
extern void Playerai_UpdateCharacterModel(void *);
extern void OnScreen_InitMover(void *, s32, s32);
extern void Link_DispatchObjectLinks(void *, s32, void *);
/* Prepares an actor's per-run HUD state: runs the mode-specific setup when the session byte is set, resets
 * the record at 0x878 to its defaults, lays out the nine on-screen widgets at 0xE2C..0x10C0 (position, then
 * their string tables), the two score fields and the 0x10FC panel, and copies the parent's four-word block. */
typedef struct { s32 a, b, c, d; } HudQuad;
void Player_InitActorHudState(void *actor) {
    char *session = (char *)&g_gameSettings;
    char *hud;
    char *widget;
    s32 enabled;
    if (FIELD(u8, session, 0x1D) != 0) {
        Playerai_LoadActorModel(actor);
        Playerai_UpdateCharacterModel(actor);
        if (FIELD(u8, FIELD(void *, actor, 0x5D8), 0x91) == 0 && FIELD(u8, session, 0xD) == 1) {
            Achieve_ApplyProfileWeaponUnlocks(actor);
        }
    }
    hud = (char *)actor + 0x878;
    FIELD(s32, hud, 0xB4) = 0;
    FIELD(s32, hud, 0x8) = 0;
    FIELD(s32, hud, 0xB8) = 0;
    FIELD(s32, hud, 0x4) = -1;
    FIELD(s32, actor, 0x878) = -1;
    FIELD(s32, hud, 0xA8) = 0;
    FIELD(s32, hud, 0x9C) = 0;
    FIELD(s32, hud, 0xA4) = 0;
    FIELD(f32, hud, 0xAC) = 437.5f;
    FIELD(f32, hud, 0xB0) = (-675.0f);
    FIELD(f32, hud, 0x90) = 0.25f;
    FIELD(f32, hud, 0x94) = 0.1875f;
    FIELD(f32, hud, 0x98) = 0.25f;
    FIELD(f32, hud, 0xA0) = 1.5707965f;
    FIELD(s32, actor, 0x11B0) = 0;
    Control_SetProfileMode((void *)FIELD(s32, actor, 0x698), 1);
    FIELD(s32, actor, 0x678) = 0;
    FIELD(s32, actor, 0x67C) = 0;
    FIELD(s32, actor, 0x680) = 0;
    FIELD(s32, actor, 0x684) = 0;
    widget = (char *)actor + 0xE2C;
    OnScreen_InitMover(widget, 0x78, 0x60);
    OnScreen_StartMoverScript(widget, g_hudStatusWidgetMoverScriptOne);
    widget = (char *)actor + 0xE68;
    OnScreen_InitMover(widget, 0xBE, 0x60);
    OnScreen_StartMoverScript(widget, g_hudStatusWidgetMoverScriptTwo);
    widget = (char *)actor + 0xEA4;
    OnScreen_InitMover(widget, 0x104, 0x60);
    OnScreen_StartMoverScript(widget, g_hudStatusWidgetMoverScriptThree);
    widget = (char *)actor + 0xEE0;
    OnScreen_InitMover(widget, 0x1C, 0x60);
    OnScreen_StartMoverScript(widget, g_hudStatusWidgetMoverScriptFour);
    widget = (char *)actor + 0xF1C;
    OnScreen_InitMover(widget, -0x40, 0x10);
    OnScreen_StartMoverScript(widget, g_hudLivesInitialMoverScript);
    widget = (char *)actor + 0xF58;
    OnScreen_InitMover(widget, 0x28, 0x10);
    OnScreen_StartMoverScript(widget, k_PlaceplayerlightEncodedWords);
    widget = (char *)actor + 0x1048;
    OnScreen_InitMover(widget, -0x52, 0x10);
    OnScreen_StartMoverScript(widget, g_hudScoreInitialMoverScript);
    widget = (char *)actor + 0x1084;
    FIELD(f32, actor, 0x107C) = 255.0f;
    OnScreen_InitMover(widget, -0x52, 0x44);
    OnScreen_StartMoverScript(widget, g_hudCountInitialMoverScript);
    widget = (char *)actor + 0x10C0;
    OnScreen_InitMover(widget, -0x52, 0x44);
    OnScreen_StartMoverScript(widget, g_hudSquadInitialMoverScript);
    OnScreen_InitMover((char *)actor + 0xFD0, 0x18, (s16)((u16)g_hudReferenceViewportHeight + 0x60));
    OnScreen_InitMover((char *)actor + 0x100C, 0x18, (s16)((u16)g_hudReferenceViewportHeight + 0x60));
    OnScreen_InitMover((char *)actor + 0x10FC, 0x64, 0x64);
    FIELD(s32, actor, 0x11C4) = 0;
    FIELD(s32, actor, 0x7BC) = 0;
    FIELD(s32, actor, 0x1134) = FIELD(s32, actor, 0x5E4);
    if (FIELD(void *, actor, 0x5DC) != 0) {
        *(HudQuad *)((char *)actor + 0x760) = *(HudQuad *)((char *)FIELD(void *, actor, 0x5DC) + 0x140);
    }
    Playerai_InitializeMovementAndAim(actor);
    enabled = 0;
    if (Cinema_IsSequenceActive() == 0) {
        enabled = enabled < (u32)(g_activeActorKind ^ 0x3E7);
    }
    if (g_world.visibilityEnabled != 0) {
        enabled = 1;
    }
    if (enabled != 0) {
        FIELD(s32, actor, 0x5EC) = g_activeActorKind;
    }
    FIELD(s32, actor, 0x1228) = 0;
    FIELD(s32, actor, 0x1224) = 0;
    Cinema_ClearPlaybackFlag();
    if (FIELD(void *, actor, 0x14) != 0) {
        Link_DispatchObjectLinks(FIELD(void *, actor, 0x14), 1, actor);
    }
    Cinema_SetPlaybackFlag();
}

/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "TYPES.H"
#include "COMMON/PLAYER_POOL_AND_INODE_CACHE_VIEWS.H"
#include "COMMON/LEVEL_ACTOR.H"
/** Reset a player for a new life: restore health, clear status timers and effects, and drop any carried object. */





typedef struct RespawnPair {
    signed char kind;
    signed char state;
} RespawnPair;

typedef struct RespawnPlayer {
    char pad0[0x38];
    int moving;
    char pad3C[0x174 - 0x3C];
    int maxHealth;
    char pad178[0x5D4 - 0x178];
    int character;
    char pad5D8[0x5E4 - 0x5D8];
    int health;
    char pad5E8[0x5EA - 0x5E8];
    short state;
    char pad5EC[0x602 - 0x5EC];
    RespawnPair effects[22];
    char pad62E[0x670 - 0x62E];
    float bob;
    char pad674[0x698 - 0x674];
    void *anim;
    char pad69C[0x11B4 - 0x69C];
    int reservedWordA;
    int movementBlocked;
    char pad11BC[0x11D8 - 0x11BC];
    int recoil;
    char pad11DC[0x11E4 - 0x11DC];
    int reservedWordB;
    LevelActor *carried;
    int reservedWordC;
    char pad11F0[0x11FC - 0x11F0];
    int reservedWordD;
    char pad1200[0x1210 - 0x1200];
    int reservedWordE;
    char pad1214[0x12C0 - 0x1214];
    float fade;
    char pad12C4[0x13C8 - 0x12C4];
    int sequenceRunEndActive;
    char pad13CC[0x13D4 - 0x13CC];
    int reservedWordF;
    int heldActor;
    int reservedWordG;
    int reservedWordH;
    int reservedWordI;
    char pad13E8[0x1450 - 0x13E8];
    int isBot;
    void *brain;
} RespawnPlayer;



static inline int isOnline(void) {
    return g_frontendScreenStatus.settings.local;
}
extern unsigned int g_gameLoopFrameCount;


extern void Playerai_ClearDamageTimers(struct RespawnPlayer *);
extern void Control_SetProfileMode(void *, int);
extern void Playerai_InitializePlayerHealth(struct RespawnPlayer *);
extern int SetN64_IsModeThirteen(void);

extern void Player_ResetPlayerWeapons(struct RespawnPlayer *);
extern void Nav_ResetPlayerState(void *);
extern void Barrel_StopActorLoopingSound(LevelActor *, s32 *);
extern void Animpool_ReleaseSceneEffect(LevelActor *);
static inline void releaseState(LevelActor *carried, s32 *state) {
    if (state != 0) {
        Barrel_StopActorLoopingSound(carried, state);
        *state |= 0x20;
    }
}

void Player_ResetRespawnedPlayer(struct RespawnPlayer *player) {
    int i;
    LevelActor *carried;

    Playerai_ClearDamageTimers(player);
    player->moving = 0;
    player->fade = g_respawnPlayerInitialFade;
    Control_SetProfileMode(player->anim, 1);
    if (g_frontendScreenStatus.settings.local != 0) {
        Playerai_InitializePlayerHealth(player);
    } else {
        if (player->isBot == 0) {
            player->health = g_characterHealthBonuses[player->character].value + 0x6400;
        } else {
            player->health = 0x6400;
        }
        player->maxHealth = player->health;
    }
    player->bob = g_respawnPlayerInitialBob;
    Playerai_InitializeMovementAndAim(player);
    player->recoil = 0;
    player->reservedWordD = 0;
    player->reservedWordH = 0;
    player->reservedWordE = 0;
    player->reservedWordC = 0;
    player->reservedWordB = 0;
    player->heldActor = 0;
    player->reservedWordG = 0;
    player->reservedWordI = 0;
    player->reservedWordF = 0;
    if (SetN64_IsModeThirteen() != 0 && g_frontendScreenStatus.settings.local == 0 && g_gameLoopFrameCount > 10 && player->state < 11) {
        SoundElement_PlayDialogGroup(g_playerStateDialogGroups[player->state]);
    }
    if (isOnline()) {
        Player_ResetPlayerWeapons(player);
    }
    player->reservedWordA = 0;
    player->movementBlocked = 0;
    player->sequenceRunEndActive = 0;
    if (player->isBot != 0) {
        Nav_ResetPlayerState(player->brain);
    }
    for (i = 1; i < 22; i++) {
        if (player->effects[i].state == 3 || player->effects[i].state == 7) {
            player->effects[i].kind = 0;
            player->effects[i].state = -1;
        }
    }
    carried = player->carried;
    if (carried != 0) {
        releaseState(carried, &carried->behaviorFlags);
        carried->flags &= ~0x2000;
        carried->flags &= ~0x100;
        Animpool_ReleaseSceneEffect(player->carried);
        player->carried = 0;
    }
}
