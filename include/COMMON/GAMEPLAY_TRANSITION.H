#ifndef COMMON_GAMEPLAY_TRANSITION_H
#define COMMON_GAMEPLAY_TRANSITION_H
#include "TYPES.H"
#include "COMMON/OBJRECAT18V6.H"

#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/LEVEL_ACTOR.H"

/* Player-transition records from origin/legacy shared headers. */

typedef struct Shared_ActionSlot { s8 kind; s8 category; } Shared_ActionSlot;

typedef struct Shared_ActorView Shared_ActorView;
struct Shared_ActorView {
    u8 pad0[3];
    u8 id; /* 0x03 */
    u8 pad4[4];
    /* The actual player position also has a word representation in the published
     * SharedPlayer.views0.positionBits; Triple is the copy-provider transport ABI. */
    union { CVector3 vector; Triple words; } position;
    s32 modelId; /* +0x14: as LevelActor.model; func_80449E18_de refreshes it */
    void * model; /* +0x18: src/func_8021B468.c */
    char pad1C[0xC8];
    u16 kind; /* +0xE4: src/func_8021B468.c */
    u8 padE6[0x1D8 - 0xE6];
    void *self; /* 0x1D8 */
    u8 pad1DC[0x1F0 - 0x1DC];
    s32 frameValue; /* +0x1F0: src/func_8021B468.c */
    char pad1F4[0xF4];
    LevelActor weapon; /* 0x2E8: complete embedded weapon actor */
    s32 actorState; /* +0x5D0: src/func_8021B468.c */
    u32 mode; /* +0x5D4: src/func_8021B468.c */
    struct Shared_ControlView * controls; /* +0x5D8: src/func_8021B468.c */
    void *message; /* +0x5DC: src/func_8021B468.c */
    s32 state; /* +0x5E0: src/func_8021B468.c */
    s32 health; /* 0x5E4 */
    s16 fraction; /* 0x5E8 */
    s16 lives; /* 0x5EA */
    s32 spawn; /* 0x5EC */
    s32 field5F0; /* 0x5F0 */
    s16 ammo[3]; /* +0x5F4: src/func_8021B468.c */
    char pad5FA[4];
    s16 actionEnabled; /* 0x5FE */
    char pad600[2];
    Shared_ActionSlot actions[22]; /* 0x602 */
    s16 selectedAction; /* 0x62E */
    u8 pad630[0x20];
    s16 action; /* +0x650: src/func_8021B468.c */
    char pad652[6];
    f32 actionTimer; /* 0x658 */
    char pad65C[0x688 - 0x65C];
    char profile[0x10]; /* 0x688 */
    void *controller; /* +0x698: src/func_8021B468.c */
    char pad69C[8];
    f32 lateralInput; /* 0x6A4 */
    char pad6A8[4];
    s32 actionFlags; /* 0x6AC */
    char pad6B0[0x10];
    f32 forwardSpeed; /* 0x6C0 */
    f32 lateralSpeed; /* 0x6C4 */
    char pad6C8[0x30];
    CVector3 contactPosition; /* 0x6F8 */
    char pad704[0x718 - 0x704];
    f32 speed; /* +0x718: src/func_8021B468.c */
    u8 pad71C[4];
    f32 transitionBlend; /* 0x720 */
    u8 pad724[0x770 - 0x724];
    s16 nextWeapon; /* 0x770 */
    u8 pad772[0x780 - 0x772];
    f32 modelBlend; /* 0x780 */
    f32 speedFactor; /* 0x784 */
    s32 controllerMode; /* 0x788 */
    f32 controllerTimer; /* 0x78C */
    u8 pad790[4];
    void *controllerOwner; /* 0x794 */
    u8 pad798[0x7F4 - 0x798];
    s32 modelState; /* 0x7F4 */
    f32 modelDistance; /* 0x7F8 */
    void *effectModel; /* 0x7FC */
    CVector3 effectPosition; /* 0x800 */
    u8 pad80C[0x840 - 0x80C];
    f32 recoveryTime; /* +0x840; probe 20261019T015002519044Z */
    u8 reserved844[4];
    s32 collisionState; /* 0x848 */
    u8 pad84C[0x864 - 0x84C];
    s32 field864;
    s32 field868;
    s32 effectId; /* 0x86C */
    u8 pad870[0x938 - 0x870];
    char strokes[0xD40 - 0x938]; /* 0x938 */
    RecordRecAtE8 record; /* 0xD40 */
    u8 padE2C[0xE54 - 0xD40 - sizeof(RecordRecAtE8)];
    f32 effectTransform[16]; /* 0xE54 */
    f32 effectOffsetTransform[16]; /* 0xE94 */
    u8 padED4[0x11B4 - 0xED4];
    s32 actionState; /* 0x11B4 */
    u8 pad11B8[4];
    s32 field11BC;
    s32 field11C0;
    u8 pad11C4[8];
    s32 field11CC;
    u8 pad11D0[8];
    f32 stun; /* +0x11D8: src/func_8021B468.c */
    f32 impulse; /* 0x11DC */
    char pad11E0[4];
    f32 pending; /* +0x11E4: src/func_8021B468.c */
    s32 field11E8;
    f32 impactTimer; /* 0x11EC */
    u8 pad11F0[0xC];
    f32 field11FC; /* 0x11FC: target radius, cleared by player reset */
    CVector3 targetPosition; /* 0x1200 */
    char pad120C[4];
    s32 targeting; /* 0x1210 */
    u8 pad1214[4];
    s32 field1218; /* +0x1218: src/func_8021B468.c */
    s32 projectileBase; /* +0x121C: src/func_8021B468.c */
    s32 projectileIndex; /* +0x1220: src/func_8021B468.c */
    void * projectiles[2]; /* +0x1224: src/func_8021B468.c */
    s32 field122C; /* +0x122C: src/func_8021B468.c */
    s32 field1230; /* +0x1230: src/func_8021B468.c */
    s32 field1234; /* +0x1234: src/func_8021B468.c */
    s32 field1238; /* +0x1238: src/func_8021B468.c */
    char pad123C[0x4];
    s32 field1240; /* +0x1240: src/func_8021B468.c */
    u8 pad1244[0x12C0 - 0x1244];
    f32 reserve; /* 0x12C0 */
    s32 field12C4;
    s32 field12C8;
    s32 reset12CC[8];
    u8 pad12EC[8];
    s32 reset12F4[8];
    u8 pad1314[0x20];
    s32 field1334;
    s32 field1338;
    u8 pad133C[8];
    u8 messageHistory[5][0x15]; /* 0x1344 */
    u8 pad13AD[3];
    s32 messageIndex; /* 0x13B0 */
    s32 *field13B4;
    s32 weaponChanged; /* 0x13B8 */
    s32 secondaryChanged;
    s32 specialChanged;
    u8 specialState; /* +0x13C4: src/func_8021B468.c */
    char pad13C5[0x3];
    s32 special; /* +0x13C8: src/func_8021B468.c */
    char pad13CC[0x14];
    void * parent; /* +0x13E0: src/func_8021B468.c */
    u8 pad13E4[8];
    u8 effectPayload[0x64]; /* 0x13EC */
    s32 remote; /* 0x1450 */
    void *owner; /* 0x1454 */
    u8 pad1458[0x1600 - 0x1458];
    f32 transform1600[16]; /* 0x1600 */
    u8 pad1640[0x16C4 - 0x1640];
    CVector3 resetPosition; /* 0x16C4: previous reset position */
    u8 pad16D0[4];
    s32 field16D4;
    s16 field16D8;
    u8 pad16DA[6];
    struct Shared_ActorView * next; /* +0x16E0: src/func_8021B468.c */
};
typedef char Shared_ActorView_size_check[(sizeof(Shared_ActorView) == 0x16E4) ? 1 : -1];

typedef struct Shared_ControlView Shared_ControlView;
struct Shared_ControlView {
    char pad0[0x80];
    s8 mode; /* +0x80: src/func_8021B468.c */
    u8 playerId; /* 0x81 */
    u8 pad82;
    u8 selection; /* 0x83: menu option adjusted by func_8043E28C_de */
    char pad84[0xA];
    u8 roundEnded; /* 0x8E */
    u8 transientFlag; /* +0x8F: src/func_8021B468.c */
    s8 resetFlag; /* +0x90: src/func_8021B468.c */
    char pad91[2];
    u8 difficulty; /* 0x93 */
    u8 germanActive; /* +0x94: src/func_8021B468.c */
};
typedef char Shared_ControlView_size_check[(sizeof(Shared_ControlView) == 0x95) ? 1 : -1];

typedef struct Shared_ProjectileView Shared_ProjectileView;
struct Shared_ProjectileView {
    char pad0[0x14];
    s32 source; /* +0x14: src/func_8021B468.c */
    char pad18[0x184];
    u16 flags; /* +0x19C: src/func_8021B468.c */
    char pad19E[0x32];
    s32 stateFlags; /* 0x1D0 */
};
typedef char Shared_ProjectileView_size_check[(sizeof(Shared_ProjectileView) == 0x1D4) ? 1 : -1];

typedef struct Shared_PlayerSettingsView Shared_PlayerSettingsView;
struct Shared_PlayerSettingsView {
    char pad0[0x80];
    s8 character; /* +0x80: src/func_8021B468.c */
    char pad81[0x14];
    u8 active; /* +0x95: src/func_8021B468.c */
    char pad96[0x46A];
    s32 effect; /* +0x500: src/func_8021B468.c */
    char pad504[0xA0];
    s32 state; /* +0x5A4: src/func_8021B468.c */
};
typedef char Shared_PlayerSettingsView_size_check[(sizeof(Shared_PlayerSettingsView) == 0x5A8) ? 1 : -1];

#include "COMMON/GAMEPLAY_SETTINGS.H"

typedef struct Shared_ModelView Shared_ModelView;
struct Shared_ModelView {
    s32 unused; /* +0x0: src/func_8021B468.c */
    s32 flags; /* +0x4: src/func_8021B468.c */
};
typedef char Shared_ModelView_size_check[(sizeof(Shared_ModelView) == 0x8) ? 1 : -1];

typedef struct Shared_SpecialObjectView Shared_SpecialObjectView;
struct Shared_SpecialObjectView {
    char pad0[0x170];
    char segment[100]; /* +0x170: src/func_8021B468.c */
    s32 reset; /* +0x1D4: src/func_8021B468.c */
};
typedef char Shared_SpecialObjectView_size_check[(sizeof(Shared_SpecialObjectView) == 0x1D8) ? 1 : -1];

typedef struct Shared_GlobalPlayers Shared_GlobalPlayers;
struct Shared_GlobalPlayers {
    s32 unused; /* +0x0: src/func_8021B468.c */
    char *players; /* +0x4: src/func_8021B468.c */
    s32 count; /* +0x8: src/func_8021B468.c */
    char controller[20]; /* +0xC: src/func_8021B468.c */
    char effects; /* +0x20: src/func_8021B468.c */
    char pad21[0x3];
};
typedef char Shared_GlobalPlayers_size_check[(sizeof(Shared_GlobalPlayers) == 0x24) ? 1 : -1];

typedef struct Shared_struct_D_800D34C0_0x18 Shared_struct_D_800D34C0_0x18;
struct Shared_struct_D_800D34C0_0x18 {
    char pad0[4];
    s16 id; /* 0x04, lookup key */
    char pad6[6];
    s16 unkC; /* +0xC: src/func_8021B468.c */
    s16 unkE; /* +0xE: src/func_8021B468.c */
    s16 unk10; /* +0x10: src/func_8021B468.c */
    char pad12[0x6];
};
typedef char Shared_struct_D_800D34C0_0x18_size_check[(sizeof(Shared_struct_D_800D34C0_0x18) == 0x18) ? 1 : -1];

typedef struct Shared_HeightBonuses Shared_HeightBonuses;
struct Shared_HeightBonuses {
    f32 spawn; /* +0x0: src/func_8021B468.c */
    f32 projectile; /* +0x4: src/func_8021B468.c */
};
typedef char Shared_HeightBonuses_size_check[(sizeof(Shared_HeightBonuses) == 0x8) ? 1 : -1];
#endif
