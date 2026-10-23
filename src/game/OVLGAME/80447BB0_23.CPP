#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "RENDER_2/802192C0_3.H"

#if defined(VERSION_US_REV1)
extern f32 D_800C73E4;
extern u8 D_0024B52C_us_rev1[], D_0022E0A0_us_rev1[], D_00219A40_us_rev1[], D_0022E250_us_rev1[];
extern u8 D_0021A2D4_us_rev1[], D_0022F5D0_us_rev1[];
extern void func_8024B3A8_de(void *, void *, void *, s32);
extern void func_80214178_de(void *, void *, s32);
extern void func_802325FC_de(void *, void *);
extern void func_80220A80_de(void *, void *);
extern void func_80245864_de(void *);
typedef struct InitView { char pad0[4]; u32 flags; char pad8[0xF4]; f32 x, y, z; } InitView;
/* Initialises an actor and its embedded part at 0x2E8: sets the shared table pointers and flag bits (one flag
 * depends on D_801462E5), runs the part setup calls, then copies the view's position into the actor. */
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
void Ovlgame_InitActorParts(SharedPlayer *player, InputRecAt27 *rec, s32 mode, s32 index) {
    char *actor = (char *)player;
    ActorInitRecord *record = (ActorInitRecord *)player;
    u32 flags;
    u32 t1, t2, t3;
    InitView *view;
    record->part[0].owner = actor;
    func_8024B3A8_de(actor, rec, (void *)mode, 0);
    record->part[0].owner = actor;
    t1 = record->part[0].flags | 0x100000;
    t2 = t1 | 0x10000;
    t3 = t2 | 0x1000000;
    flags = t3 | 0x2000000;
    record->part[0].flags = flags;
    if (D_801462E5 == 0) {
        record->part[0].flags = flags | 0x10000000;
    }
    record->part[0].table28C = D_0024B52C_us_rev1;
    record->part[0].table290 = D_0022E0A0_us_rev1;
    record->part[0].table280 = D_00219A40_us_rev1;
    record->part[0].table288 = D_0022E250_us_rev1;
    if (D_801462E5 != 0) {
        record->part[0].action = D_0021A2D4_us_rev1;
    }
    record->part[1].owner = actor;
    func_8024B3A8_de((actor + 0x2E8), rec, (void *)mode, 0);
    record->part[1].table28C = D_0022F5D0_us_rev1;
    record->part[1].marker = -1;
    record->part[1].flags |= 0x200000;
    record->part[1].x = D_800C73E4;
    record->part[1].y = D_800C73E4;
    record->part[1].z = D_800C73E4;
    record->part[1].owner = actor;
    record->part[1].table280 = D_00219A40_us_rev1;
    record->part[1].table288 = D_0022E250_us_rev1;
    record->selection = -1;
    record->part[1].flags &= 0xFFFEFFFF;
    func_80214178_de((actor + 0x2E8), (actor + 0x458), 0);
    func_802325FC_de((actor + 0x2E8), (actor + 0x458));
    func_80220A80_de(actor, actor);
    if (record->auxiliary != 0) {
        func_80245864_de(record->auxiliary);
    }
    record->part[0].x = (record->part[0].view)->x;
    record->part[0].y = (record->part[0].view)->y;
    record->part[0].z = (record->part[0].view)->z;
    view = record->part[0].view;
    view->flags &= ~4;
}
#endif

#ifdef NON_MATCHING
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
extern s32 D_800FEAE0[], D_800FF140_de[];
extern char D_80102B00[];
extern void *D_800E4680;
extern char D_0044FC04[], D_0044FB2C[], D_0044FF80[];
struct RespawnPlayer;
extern s32 func_80264B6C_de(void);
extern void *func_8044A738_de(void *);
extern void func_8021836C_de(void *);
extern void func_80218E98_de(void *);
extern u32 func_8022F454_de(void *, s32);
extern void Render_ResetPlayerWeapons(struct RespawnPlayer *);
extern void func_8044952C_de(struct RespawnPlayer *);
extern void func_80442574_de(void *, void *, void *, s32, s32);
/* Resets a player/actor record for a new run: marks it active, stores the character, picks up the HUD
 * object, clears the per-slot counters and weapon tables, selects the start mode from the multiplayer setting
 * and zeroes the per-player entries of the two global tables. */
void func_80448EF4_de(void *actor, s32 character) {
    s32 i;
    s32 openFlag = 0;
#define globals ((char *)&D_801462C8)
    func_80264B6C_de();
    FIELD(s32, actor, 0x5D0) = 1;
    FIELD(s32, actor, 0x5E0) = character;
    if (FIELD(s32, actor, 0x1450) == 0) {
        FIELD(void *, actor, 0x5DC) = func_8044A738_de(&D_80145088);
        if (FIELD(s32, &D_80145088, 0x18C4) != 0) {
            FIELD(s32, actor, 0x1450) = 1;
        }
    } else {
        FIELD(s32, actor, 0x5DC) = 0;
    }
    func_8021836C_de((char *)actor + 0x938);
    func_80218E98_de((char *)actor + 0xCCC);
    FIELD(s16, actor, 0x5E8) = 0;
    for (i = 5; i >= 0; i--) {
        FIELD(u8, actor, 0x644 + i) = 0;
    }
    for (i = 5; i >= 0; i--) {
        FIELD(u8, actor, 0x64A + i) = 0;
    }
    if (D_801462E5 != 0) {
        if (D_801462D5 == 1 && FIELD(s32, actor, 0x1450) == 0) {
            u32 value = func_8022F454_de(D_80102B00 + FIELD(s32, actor, 0x5D4) * 0x190, FIELD(s8, FIELD(void *, actor, 0x5D8), 0x80));
            FIELD(s32, actor, 0x133C) = ((value & 0xFF) >> 1) + 1;
        }
        if (D_801462D5 == 4 && FIELD(s32, actor, 0x1450) == 0 && D_800E4680 != 0) {
            FIELD(s32, actor, 0x133C) = FIELD(u8, D_800E4680, 0x28);
        }
        FIELD(s16, actor, 0x5EA) = 1;
    } else {
        FIELD(s16, actor, 0x5EA) = 3;
    }
    FIELD(s32, actor, 0x13C8) = 0;
    Render_ResetPlayerWeapons((struct RespawnPlayer *)actor);
    FIELD(s32, actor, 0x670) = 0;
    FIELD(s32, actor, 0x674) = 0;
    FIELD(s32, actor, 0x86C) = -1;
    FIELD(s32, actor, 0x870) = -1;
    for (i = 0; i < 8; i++) {
        FIELD(s16, FIELD(void *, actor, 0x5D8), 0x2C + i * 2) = 0;
        FIELD(s16, FIELD(void *, actor, 0x5D8), 0x3C + i * 2) = 0;
        FIELD(s16, FIELD(void *, actor, 0x5D8), 0xC + i * 2) = 0;
        FIELD(s16, FIELD(void *, actor, 0x5D8), 0x1C + i * 2) = 0;
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
    func_8044952C_de((struct RespawnPlayer *)actor);
    if (FIELD(u8, globals, 0x1D) != 0) {
        FIELD(s32, actor, 0x13E8) = 0;
    }
    if (openFlag != 0) {
        char *table;
        if (FIELD(u8, globals, 0x1D) != 0) {
            FIELD(u8, FIELD(void *, actor, 0x5D8), 0x80) = 0;
            FIELD(s32, actor, 0x5E0) = 0;
            FIELD(s32, actor, 0x85C) = 1;
            table = D_0044FC04;
            if (FIELD(s32, globals, 0x5FC) == 0) {
                table = D_0044FB2C;
            }
        } else {
            table = D_0044FF80;
        }
        func_80442574_de((char *)FIELD(void *, actor, 0x5DC) + 0x554, table, actor, FIELD(s32, actor, 0x698), FIELD(s32, actor, 0x5D4));
    }
    D_800FEAE0[FIELD(s32, actor, 0x5D4)] = 0;
    D_800FF140_de[FIELD(s32, actor, 0x5D4)] = 0;
#undef globals
}
#else
INCLUDE_ASM("ovl_80400000", func_80448EF4_de);
#endif

#ifdef NON_MATCHING
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
extern f32 D_800C2300_de, D_800C2304_de, D_800C2308_de, D_800C73FC, D_800C2310_de, D_800C2314_de;
extern char D_800C9278_de[], D_800C92E8_de[], D_800C9358[], D_auto_800CE480[], D_800C93C8_de[];
extern char D_auto_rodata_unresolved_800CE410_unclaimed_CF230[], D_800C942C_de[], D_800C9458[], D_800C9494_de[];
extern s32 D_800E28D4;
extern u32 D_8013B2BC;
extern void Text_LoadActorModel(void *actor);
extern void func_8022BB80_de(void *);
extern void func_80426090_de(void *);
extern void func_802AA6D0_de(void *, s32, s32);
extern void func_8021A78C_de(void *);
extern s32 func_80245784_de(void);
extern void func_802458D8_de(void);
extern void func_802458C4_de(void);
extern void func_80278E04_de(void *, s32, void *);
/* Prepares an actor's per-run HUD state: runs the mode-specific setup when the session byte is set, resets
 * the record at 0x878 to its defaults, lays out the nine on-screen widgets at 0xE2C..0x10C0 (position, then
 * their string tables), the two score fields and the 0x10FC panel, and copies the parent's four-word block. */
void Ovlgame_InitActorHudState(void *actor) {
    char *globals = (char *)&D_801462C8;
    char *sub;
    char *widget;
    s32 enabled;
    if (FIELD(u8, globals, 0x1D) != 0) {
        Text_LoadActorModel(actor);
        func_8022BB80_de(actor);
        if (FIELD(u8, FIELD(void *, actor, 0x5D8), 0x91) == 0 && FIELD(u8, globals, 0xD) == 1) {
            func_80426090_de(actor);
        }
    }
    sub = (char *)actor + 0x878;
    FIELD(s32, sub, 0xB4) = 0;
    FIELD(s32, sub, 0x8) = 0;
    FIELD(s32, sub, 0xB8) = 0;
    FIELD(s32, sub, 0x4) = -1;
    FIELD(s32, actor, 0x878) = -1;
    FIELD(s32, sub, 0xA8) = 0;
    FIELD(s32, sub, 0x9C) = 0;
    FIELD(s32, sub, 0xA4) = 0;
    FIELD(f32, sub, 0xAC) = D_800C2300_de;
    FIELD(f32, sub, 0xB0) = D_800C2304_de;
    FIELD(f32, sub, 0x90) = D_800C2308_de;
    FIELD(f32, sub, 0x94) = D_800C73FC;
    FIELD(f32, sub, 0x98) = D_800C2308_de;
    FIELD(f32, sub, 0xA0) = D_800C2310_de;
    FIELD(s32, actor, 0x11B0) = 0;
    func_802647E8_de((void *)FIELD(s32, actor, 0x698), 1);
    FIELD(s32, actor, 0x678) = 0;
    FIELD(s32, actor, 0x67C) = 0;
    FIELD(s32, actor, 0x680) = 0;
    FIELD(s32, actor, 0x684) = 0;
    widget = (char *)actor + 0xE2C;
    func_802AA6D0_de(widget, 0x78, 0x60);
    func_802AA70C_de(widget, D_800C9278_de);
    widget = (char *)actor + 0xE68;
    func_802AA6D0_de(widget, 0xBE, 0x60);
    func_802AA70C_de(widget, D_800C92E8_de);
    widget = (char *)actor + 0xEA4;
    func_802AA6D0_de(widget, 0x104, 0x60);
    func_802AA70C_de(widget, D_800C9358);
    widget = (char *)actor + 0xEE0;
    func_802AA6D0_de(widget, 0x1C, 0x60);
    func_802AA70C_de(widget, D_auto_800CE480);
    widget = (char *)actor + 0xF1C;
    func_802AA6D0_de(widget, -0x40, 0x10);
    func_802AA70C_de(widget, D_800C93C8_de);
    widget = (char *)actor + 0xF58;
    func_802AA6D0_de(widget, 0x28, 0x10);
    func_802AA70C_de(widget, D_auto_rodata_unresolved_800CE410_unclaimed_CF230);
    widget = (char *)actor + 0x1048;
    func_802AA6D0_de(widget, -0x52, 0x10);
    func_802AA70C_de(widget, D_800C942C_de);
    widget = (char *)actor + 0x1084;
    FIELD(f32, actor, 0x107C) = D_800C2314_de;
    func_802AA6D0_de(widget, -0x52, 0x44);
    func_802AA70C_de(widget, D_800C9458);
    widget = (char *)actor + 0x10C0;
    func_802AA6D0_de(widget, -0x52, 0x44);
    func_802AA70C_de(widget, D_800C9494_de);
    func_802AA6D0_de((char *)actor + 0xFD0, 0x18, (s16)((u16)D_800E28D4 + 0x60));
    func_802AA6D0_de((char *)actor + 0x100C, 0x18, (s16)((u16)D_800E28D4 + 0x60));
    func_802AA6D0_de((char *)actor + 0x10FC, 0x64, 0x64);
    FIELD(s32, actor, 0x11C4) = 0;
    FIELD(s32, actor, 0x7BC) = 0;
    FIELD(s32, actor, 0x1134) = FIELD(s32, actor, 0x5E4);
    if (FIELD(void *, actor, 0x5DC) != 0) {
        FIELD(s32, actor, 0x760) = FIELD(s32, FIELD(void *, actor, 0x5DC), 0x140);
        FIELD(s32, actor, 0x764) = FIELD(s32, FIELD(void *, actor, 0x5DC), 0x144);
        FIELD(s32, actor, 0x768) = FIELD(s32, FIELD(void *, actor, 0x5DC), 0x148);
        FIELD(s32, actor, 0x76C) = FIELD(s32, FIELD(void *, actor, 0x5DC), 0x14C);
    }
    func_8021A78C_de(actor);
    enabled = 0;
    if (func_80245784_de() == 0) {
        enabled = 0 < (D_8013B2BC ^ 0x3E7);
    }
    if (D_8013B290 != 0) {
        enabled = 1;
    }
    if (enabled != 0) {
        FIELD(s32, actor, 0x5EC) = D_8013B2BC;
    }
    FIELD(s32, actor, 0x1228) = 0;
    FIELD(s32, actor, 0x1224) = 0;
    func_802458D8_de();
    if (FIELD(void *, actor, 0x14) != 0) {
        func_80278E04_de(FIELD(void *, actor, 0x14), 1, actor);
    }
    func_802458C4_de();
}
#else
INCLUDE_ASM("ovl_80400000", Ovlgame_InitActorHudState);
#endif

/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "TYPES.H"
#include "COMMON/OBJECTSTATE96.H"
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
    int field11B4;
    int field11B8;
    char pad11BC[0x11D8 - 0x11BC];
    int field11D8;
    char pad11DC[0x11E4 - 0x11DC];
    int field11E4;
    LevelActor *carried;
    int field11EC;
    char pad11F0[0x11FC - 0x11F0];
    int field11FC;
    char pad1200[0x1210 - 0x1200];
    int field1210;
    char pad1214[0x12C0 - 0x1214];
    float fade;
    char pad12C4[0x13C8 - 0x12C4];
    int field13C8;
    char pad13CC[0x13D4 - 0x13CC];
    int field13D4;
    int field13D8;
    int field13DC;
    int field13E0;
    int field13E4;
    char pad13E8[0x1450 - 0x13E8];
    int isBot;
    void *brain;
} RespawnPlayer;



static inline int isOnline(void) {
    return D_801462E5;
}
extern unsigned int D_800CD730;


extern void func_8022B510_de(struct RespawnPlayer *);
extern void func_802647E8_de(void *, int);
extern void func_80226708_de(struct RespawnPlayer *);
extern int func_802934F8_de(void);

extern void Render_ResetPlayerWeapons(struct RespawnPlayer *);
extern void World_ResetPlayerState(void *);
extern void func_80217388_de(LevelActor *, s32 *);
extern void func_80262C88_de(LevelActor *);
static inline void releaseState(LevelActor *carried, s32 *state) {
    if (state != 0) {
        func_80217388_de(carried, state);
        *state |= 0x20;
    }
}

void func_8044952C_de(struct RespawnPlayer *player) {
    int i;
    LevelActor *carried;

    func_8022B510_de(player);
    player->moving = 0;
    player->fade = D_800C2338_de;
    func_802647E8_de(player->anim, 1);
    if (D_801462E5 != 0) {
        func_80226708_de(player);
    } else {
        if (player->isBot == 0) {
            player->health = D_800FEB10[player->character].value + 0x6400;
        } else {
            player->health = 0x6400;
        }
        player->maxHealth = player->health;
    }
    player->bob = D_800C233C_de;
    func_8021A78C_de(player);
    player->field11D8 = 0;
    player->field11FC = 0;
    player->field13E0 = 0;
    player->field1210 = 0;
    player->field11EC = 0;
    player->field11E4 = 0;
    player->field13D8 = 0;
    player->field13DC = 0;
    player->field13E4 = 0;
    player->field13D4 = 0;
    if (func_802934F8_de() != 0 && D_801462E5 == 0 && D_800CD730 > 10 && player->state < 11) {
        func_8025E11C_de(D_800CF198[player->state]);
    }
    if (isOnline()) {
        Render_ResetPlayerWeapons(player);
    }
    player->field11B4 = 0;
    player->field11B8 = 0;
    player->field13C8 = 0;
    if (player->isBot != 0) {
        World_ResetPlayerState(player->brain);
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
        func_80262C88_de(player->carried);
        player->carried = 0;
    }
}
