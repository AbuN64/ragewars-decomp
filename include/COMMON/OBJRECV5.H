#include "COMMON/PARTICLE_LIGHTING.H"
#ifndef COMMON_OBJRECV5_H
#define COMMON_OBJRECV5_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
struct ObjRecV5;
typedef struct ObjRecV5 ObjRecV5;

extern float D_800C2B5C_de;

extern float D_800C2B64_de;



struct Rules;
#include "GAME/PLAYER_RULES.H"

struct Scores;
struct Scores {
    char pad[0x1c];
    short score[8];
};
struct ObjRecAt16E0V1;
struct Scores;
struct ObjRecAt16E0V1 {
    char pad[0x5d4];
    int unk5D4;
    struct Scores *unk5D8;
    char pad5dc[0x1104];
    struct ObjRecAt16E0V1 *unk16E0;
};

struct ObjRecAt16E0V1;
struct Root;
struct Root {
    char pad[0x20];
    struct ObjRecAt16E0V1 *unk20;
};

struct Stats;
typedef struct Stats Stats;

struct Shape_typemap_165;
struct ObjRecV6;
struct ObjRecV6 {
    char pad0[0x2F0];
    Triple unk2F0;
    char pad2F0[0x2FC - 0x2F0 - sizeof(Triple)];
    s32 unk2FC;
    char pad2FC[0x344 - 0x2FC - sizeof(s32)];
    struct Shape_typemap_165 unk344;
    char pad344[0x354 - 0x344 - sizeof(struct Shape_typemap_165)];
    f32 unk354;
    char pad354[0x3E8 - 0x354 - sizeof(f32)];
    s32 unk3E8;
};

extern float D_800C2BE8_de;

extern float D_800C2B50_de;

struct HudGlobals;
struct HudGlobals {
    u8 fade;
    u8 reserved;
    u8 state;
};

struct ObjRecV6;
typedef struct ObjRecV6 ObjRecV6;

struct SubActor;
struct SubActor {
    char pad0[4];
    s16 score; /* +0x04: Weapons_CheckScoreLimit tests it against the score limit */
    char pad6[0x8F - 6];
    u8 unk8F;
    u8 unk90;
};

struct ObjRecAt16E0V2;
typedef struct ObjRecAt16E0V2 ObjRecAt16E0V2;

struct PlayerCode80225D1080229FA0;
struct PlayerCode80225D1080229FA0 {
    char pad0[146];
    u8 unk92;
    u8 unk93;
};
struct Obj_func_80229FA0_de;
struct PlayerCode80225D1080229FA0;
struct Obj_func_80229FA0_de {
    u8 unk0;
    char pad1[227];
    unsigned short unkE4;
    char pade6[26];
    int unk100;
    char pad104[40];
    struct Obj_func_80229FA0_de * unk12C;
    char pad130[168];
    struct Obj_func_80229FA0_de * unk1D8;
    char pad1dc[1020];
    struct PlayerCode80225D1080229FA0 * unk5D8;
    char pad5dc[3700];
    int unk1450;
};

struct Held;
typedef struct Held Held;

struct Rules;


struct Round;
typedef struct Round Round;

extern float D_800C2B60_de;

struct ObjectLinks16E4_2;
struct ObjectLinks16E4_2 {
    char pad0[0x70];
    s32 unk_70;
    char pad70[0x358 - 0x70 - sizeof(s32)];
    s32 unk_358;
    char pad358[0x16E0 - 0x358 - sizeof(s32)];
    void * unk_16E0;
};

struct ObjectState5E8;
struct ObjectState5E8 {
    char pad0[0x170];
    char unk_170;
    char pad170[0x5E4 - 0x170 - sizeof(char)];
    s32 unk_5E4;
};


extern float D_800C2B58_de;

struct WorldWeaponsUpdateWorldPlayers;
struct WorldWeaponsUpdateWorldPlayers {
    char pad0[0x20];
    SharedPlayer *players;
    char pad24[0x40 - 0x24];
    s32 spin;
};

struct ActorNode;
typedef struct ActorNode ActorNode;

struct Receiver;
struct Receiver {
    char pad[0x5A4];
    s32 index;
    s32 amount;
};


extern float D_800C2C08_de;

struct CPlayerDamageOverTime_t;
struct CPlayerDamageOverTime_t {
    char pad0[0x4];
    f32 m_FramesRemaining;
    char pad4[0x8 - 0x4 - sizeof(f32)];
    void * m_pDamageSource;
    char pad8[0xC - 0x8 - sizeof(void*)];
    f32 m_TotalDamage;
    char padC[0x10 - 0xC - sizeof(f32)];
    f32 m_DamageIssued;
    char pad10[0x14 - 0x10 - sizeof(f32)];
    s32 m_bIsInflator;
};

struct SubActor;
typedef struct SubActor SubActor;



struct Body;
struct Character;
struct Controller;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct RecordRecAt94;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;

struct World_func_802283B8_de;
struct World_func_802283B8_de {
    char pad0[0x20];
    SharedPlayer *players;
};

struct IntegerStateB4C;
typedef struct IntegerStateB4C IntegerStateB4C;

extern void func_80225F44_de();

struct ViewState;
struct ViewState {
    u8 bytes[0x29C];
    f32 width;
    f32 height;
};

struct PlayerCode80225D10;
typedef struct PlayerCode80225D10 PlayerCode80225D10;




struct IntegerStateB4C;
struct IntegerStateB4C {
    char pad0[0xB48];
    s32 itemCount2;
};

struct CPlayerDamageOverTime_t;
typedef struct CPlayerDamageOverTime_t CPlayerDamageOverTime;

struct Game;
struct Game {
    s32 state;
    char pad4[0x24 - 0x4];
    Rules rules;
};


struct ViewCode80225D10;
typedef struct ViewCode80225D10 ViewCode80225D10;

struct ActorNode;
struct SubActor;
struct ActorNode {
    char pad0[0x5D4];
    s32 kind; /* +0x5D4: below 4 for the human players */
    struct SubActor *scores;
    char pad1[0x16E0 - 0x5D8 - 4];
    struct ActorNode *next;
};

struct Receiver;
typedef struct Receiver Receiver;

struct ActorRecAt86C;
typedef struct ActorRecAt86C ActorRecAt86C;

struct ObjRecAt16E0V2;
struct ObjRecAt16E0V2 {
    char pad0[0xC4];
    s32 unkC4;
    char padC4[0xD0 - 0xC4 - sizeof(s32)];
    s32 unkD0;
    char padD0[0x100 - 0xD0 - sizeof(s32)];
    s32 unk100;
    char pad100[0x2E8 - 0x100 - sizeof(s32)];
    char unk2E8;
    char pad2E8[0x5DC - 0x2E8 - sizeof(char)];
    void * unk5DC;
    char pad5DC[0x16E0 - 0x5DC - sizeof(void*)];
    void * unk16E0;
};

extern float D_800C2B54_de;

struct IntegerState1230;
typedef struct IntegerState1230 IntegerState1230;

struct IntegerState948;
struct IntegerState948 {
    char pad0[0x944];
    s32 itemCount1;
};

struct ObjectLinks94C;
typedef struct ObjectLinks94C ObjectLinks94C;

struct IntegerState948;
typedef struct IntegerState948 IntegerState948;

extern float D_800C2BF0_de;

struct ObjectLinks16E4;
typedef struct ObjectLinks16E4 ObjectLinks16E4;

struct ObjectLinks148;
typedef struct ObjectLinks148 ObjectLinks148;


struct ObjectLinks16E4;
struct ObjectLinks16E4 {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x5DC - 0x5D8 - sizeof(char*)];
    s32 unk_5DC;
    char pad5DC[0x11FC - 0x5DC - sizeof(s32)];
    f32 unk_11FC;
    char pad11FC[0x120C - 0x11FC - sizeof(f32)];
    s32 unk_120C;
    char pad120C[0x1210 - 0x120C - sizeof(s32)];
    s32 unk_1210;
    char pad1210[0x16E0 - 0x1210 - sizeof(s32)];
    char * unk_16E0;
};

struct HudGlobals;
typedef struct HudGlobals HudGlobals;

struct ViewCode80225D10;
struct ViewCode80225D10 {
    char pad0[0x128];
    Triple position;
};

struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct ViewCode80225D10;

struct Game;
typedef struct Game Game;

struct MenuWeaponsUpdateWorldPlayers;
struct MenuWeaponsUpdateWorldPlayers {
    char pad0[0xCC9];
    u8 allowed;
    char padCCA[0x1278 - 0xCCA];
    s32 open;
    char pad127C[0x1284 - 0x127C];
    MenuRules rules;
};

struct Damage_func_80229FA0_de;
struct Obj_func_80229FA0_de;
struct Damage_func_80229FA0_de {
    struct Obj_func_80229FA0_de *unk0;
    int unk4;
};

struct WorldWeaponsUpdateWorldPlayers;
typedef struct WorldWeaponsUpdateWorldPlayers WorldWeaponsUpdateWorldPlayers;

struct Stats;
struct Stats {
    char pad0[0x3C];
    s16 kills[8];
};

struct HudState;
typedef struct HudState HudState;

struct HudState;
struct HudState {
    u8 reserved[0x5D4];
    f32 timer;
};

struct Player16C0;
typedef struct Player16C0 Player16C0;

extern float D_800C2BF4_de;

struct Player16C0;
struct Player16C0 {
    char pad0[0x5E4];
    s32 alive;
    char pad5E8[0x1640 - 0x5E8];
    UnitMtx markers[2];
};

struct ObjectLinks16E4_2;
typedef struct ObjectLinks16E4_2 ObjectLinks16E4_2;

struct Body;
struct Controller;
struct Controls;
struct Ctrl;
struct Desc;
struct Held;
struct Mode;
struct Model;
struct Mount;
struct Profile;
struct Record;
struct Rider;
struct Settings;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;

struct ObjectLinks148;
struct ObjectLinks148 {
    char pad0[0x144];
    void * unk_144;
};

struct Inventory;
struct Inventory {
    char pad[0x5F4];
    s16 items[3];
};

struct Inventory;
typedef struct Inventory Inventory;


struct ObjectLinks94C;
struct ObjectLinks94C {
    unsigned char padding_0[2376];
    void *unk_948;
};


struct Damage_func_80229FA0_de;
typedef struct Damage_func_80229FA0_de Damage_func_80229FA0_de;

struct ViewState;
typedef struct ViewState ViewState;

struct Root;
typedef struct Root Root;

struct MenuWeaponsUpdateWorldPlayers;
typedef struct MenuWeaponsUpdateWorldPlayers MenuWeaponsUpdateWorldPlayers;

struct RulesWeaponsDrawTintedPlayer;
typedef struct RulesWeaponsDrawTintedPlayer RulesWeaponsDrawTintedPlayer;

struct Obj_func_80229FA0_de;
typedef struct Obj_func_80229FA0_de Obj_func_80229FA0_de;

struct CPlayerPool_t;
extern s32 func_80229A80_de(struct CPlayerPool_t *game);

extern float D_800C2BE0_de;

extern float D_800C2BDC_de;

union func_802285C4_S2_U11BC;
typedef union func_802285C4_S2_U11BC func_802285C4_S2_U11BC;

union func_802285C4_S2_U11BC;
union func_802285C4_S2_U11BC {
    void * v0;
    s32 v1;
};

struct Shape_typemap_165;
struct ObjRecV5;
struct ObjRecV5 {
    char pad0[0x8];
    Triple unk8;
    char pad8[0x14 - 0x8 - sizeof(Triple)];
    s32 unk14;
    char pad14[0x5C - 0x14 - sizeof(s32)];
    struct Shape_typemap_165 unk5C;
    char pad5C[0x6C - 0x5C - sizeof(struct Shape_typemap_165)];
    f32 unk6C;
    char pad6C[0x10E - 0x6C - sizeof(f32)];
    u8 unk10E;
    char pad10E[0x2E8 - 0x10E - sizeof(u8)];
    Block unk2E8;
    char pad2E8[0x5DC - 0x2E8 - sizeof(Block)];
    void * unk5DC;
    char pad5DC[0x5EA - 0x5DC - sizeof(void*)];
    s16 unk5EA;
    char pad5EA[0x86C - 0x5EA - sizeof(s16)];
    s32 unk86C;
    char pad86C[0x11BC - 0x86C - sizeof(s32)];
    func_802285C4_S2_U11BC unk11BC;
    char pad11BC[0x11C0 - 0x11BC - sizeof(func_802285C4_S2_U11BC)];
    func_802285C4_S2_U11BC unk11C0;
    char pad11C0[0x11D8 - 0x11C0 - sizeof(func_802285C4_S2_U11BC)];
    f32 unk11D8;
    char pad11D8[0x16E0 - 0x11D8 - sizeof(f32)];
    char * unk16E0;
};

struct World_func_802283B8_de;
typedef struct World_func_802283B8_de World_func_802283B8_de;

struct PlayerCode80225D10;
struct PlayerCode80225D10 {
    char pad0[0xE4];
    u16 kind;
    char padE6[0x5D8 - 0xE6];
    ObjRecAt8F *controls;
    struct GameplayCamera *camera;
    s32 state;
    s32 health;
    char pad5E8[0x62E - 0x5E8];
    s16 selectedWeapon;
    char pad630[0x11D8 - 0x630];
    f32 ghost;
    char pad11DC[0x122C - 0x11DC];
    u32 flags;
    f32 tintTime;
    char pad1234[4];
    s32 tintMode;
    u8 red, green, blue, reserved123F;
    f32 opacity;
    char pad1244[0x13C8 - 0x1244];
    s32 hidden;
    char pad13CC[0x1450 - 0x13CC];
    s32 fixedAlpha;
};

struct ObjRecAt16E0V1;
typedef struct ObjRecAt16E0V1 ObjRecAt16E0V1;

struct IntegerState1230;
struct IntegerState1230 {
    char pad0[0x100];
    s32 unk_100;
    char pad100[0x122C - 0x100 - sizeof(s32)];
    s32 unk_122C;
};

struct RulesWeaponsDrawTintedPlayer;
struct RulesWeaponsDrawTintedPlayer {
    char pad0[0x54];
    s32 teams;
    char pad58[0x73 - 0x58];
    u8 colour;
};

extern float D_800C2BEC_de;


struct ObjectState5E8;
typedef struct ObjectState5E8 ObjectState5E8;

struct ActorRecAt86C;
struct ActorRecAt86C {
    u8 pad000[0x3E8];
    s32 flags;
    u8 pad3EC[0x480];
    s32 value86C;
};

struct ActorNode;
struct Round;
struct Round {
    char pad0[0x20];
    struct ActorNode *players;
};

struct PlayerCode80225D10;


struct SharedPlayer;

typedef struct ForcePlayer ForcePlayer;
struct ForcePlayer { u8 pad0[0x5D0]; s32 active; u8 pad5D4[0xC28]; f32 strength; CVector3 origin; s32 attract; u8 pad1210[0x4D0]; ForcePlayer *next; };
typedef struct { u8 pad0[0x20]; ForcePlayer *head; } ForcePlayerList;
typedef struct { u8 pad0[8]; CVector3 position; u8 pad14[8]; CVector3 velocity; u8 pad28[0x14C]; CVector3 direction; } ForceBody;

extern char D_800C95D0;
extern SharedMovement D_800C9510_de[2];
extern CVector3 D_800C94D0_de;

extern char s_playersText[];

void func_8022C5AC_de(char *);
void func_8022C5DC_de(void *);
s32 func_8022C620_de(char *);
extern f32 D_800C2BA0_de;
extern f32 D_800C2BA4_de;
extern f32 D_800C2BA8_de;
extern f32 D_800C2BAC_de;
extern f32 D_800C2BB0_de;
extern f32 D_800C2BB4_de;
extern f32 D_800C2BB8_de;
extern f32 D_800C2BBC_de;
extern s32 D_800C91B8_de;

extern void func_8024B4F4_de(void *arg0, s32 arg1);

extern void func_8022B60C_de(void *arg0, f32 arg1, void *arg2);

extern void func_8022BC94_de(void *arg0, s32 arg1);
extern s32 func_8024B7E4_de(void *arg0, s32 arg1);
struct WeaponMenuView;
#endif
