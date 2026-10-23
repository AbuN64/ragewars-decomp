#ifndef COMMON_AIPROFILE_H
#define COMMON_AIPROFILE_H
#include "TYPES.H"
struct GameplayCamera;
#include "COMMON/GFX.H"
#include "COMMON/MODEL_INSTANCE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"
struct Player;
struct RangeNode;
typedef struct AiProfile {
    u8 pad0[0x7A];
    u8 sensitivity; /* 0x7A: Fx_BuildControllerState */
    s8 controlMode; /* 0x7B */
    u8 remap; /* 0x7C */
    u8 pitchMode; /* 0x7D */
    u8 pad7E[2];
    s8 character; /* 0x80 */
    s8 variant; /* 0x81: Render_DrawCharacterEffectParts */
    u8 pad82[0xD];
    u8 bonus; /* 0x8F: Render_DrawCharacterEffectParts, func_80449870_de */
    s8 state90; /* 0x90 */
    u8 pad91[2];
    u8 difficulty; /* 0x93 */
    u8 enabled; /* 0x94: Render_DrawCharacterEffectParts */
} AiProfile;


struct Player {
    u8 kind; /* 0x0 */
    u8 pad1[2];
    u8 playerId; /* 0x3 */
    u8 pad4[4];
    CVector3 pos; /* 0x8 */
    u8 pad14[0x4];
    void * definition; /* 0x18 */
    u8 pad1C[0x1C];
    s32 movementFlags; /* 0x38 */
    u8 pad3C[0x14];
    CVector3 scale; /* 0x50 */
    CQuatern orientation; /* 0x5C */
    f32 heading; /* 0x6C */
    u8 pad70[0x4];
    f32 matrix[16]; /* 0x74 */
    u8 padB4[0x30];
    u16 objectId; /* 0xE4 */
    u8 padE6[0x1A];
    s32 weaponFlags; /* 0x100 */
    u8 pad104[0xA];
    s8 animationDone; /* 0x10E */
    u8 pad10F[0x61];
    u8 motion[0x170]; /* 0x170 */
    u8 pad2E0[8];
    struct Object_func_8028B274_de weaponModel; /* 0x2E8 */
    u8 pad3CE[0xB6];
    struct AiBehaviourTable *weaponAnimationTable; /* 0x484 */
    u8 pad488[0xF0];
    s32 weaponAnimationCount; /* 0x578 */
    f32 weaponSpinStep; /* 0x57C: weapon state +0x124 */
    f32 weaponSpin; /* 0x580: weapon state +0x128 */
    u8 pad584[0xC];
    s32 weaponReset; /* 0x590: weapon state +0x138 */
    s32 gear; /* 0x594 */
    u8 pad598[0x3C];
    s32 slot; /* 0x5D4 */
    AiProfile * profile; /* 0x5D8 */
    void *owner; /* 0x5DC */
    s32 state; /* 0x5E0 */
    s32 health; /* 0x5E4 */
    u8 pad5E8[4];
    s32 model; /* 0x5EC: func_80449870_de passes it to Render_PlacePlayerAtSpawnPoint */
    u8 pad5F0[4];
    s16 ammo[7]; /* 0x5F4 */
    s8 actions[22][2]; /* 0x602 */
    s16 selectedAction; /* 0x62E */
    s16 queuedAction; /* 0x630 */
    s16 lastAction; /* 0x632 */
    u8 pad634[0x1C];
    s16 pose; /* 0x650 */
    u8 pad652[6];
    f32 poseTimer; /* 0x658 */
    u8 pad65C[4];
    s32 flags660; /* 0x660 */
    u8 pad664[0xC];
    f32 damageCooldown; /* 0x670 */
    u8 pad674[4];
    f32 rangeTimer; /* 0x678: Weapons_UpdatePlayerEffectLights */
    struct RangeNode *rangeNodes[3]; /* 0x67C: created by func_80268C1C_de */
    u8 tuning[0x10]; /* 0x688 */
    void *weaponAnimation; /* 0x698 */
    f32 steer; /* 0x69C */
    f32 pitch; /* 0x6A0 */
    f32 strafe; /* 0x6A4 */
    f32 forward; /* 0x6A8 */
    s32 inputFlags; /* 0x6AC */
    s32 actionFlags; /* 0x6B0 */
    u8 pad6B4[0xC];
    f32 stick; /* 0x6C0 */
    s32 state6C4; /* 0x6C4 */
    f32 landing; /* 0x6C8 */
    s32 state6CC; /* 0x6CC */
    s32 active; /* 0x6D0 */
    s32 state6D4;
    s32 state6D8;
    s32 state6DC;
    f32 movementScale; /* 0x6E0 */
    s32 state6E4;
    CVector3 previousPosition; /* 0x6E8 */
    f32 heightDelta; /* 0x6F4 */
    CVector3 previousTarget; /* 0x6F8 */
    u8 pad704[4];
    f32 state708;
    f32 state70C;
    f32 state710;
    f32 state714;
    f32 crouchDepth; /* 0x718 */
    s32 forceCrouch; /* 0x71C */
    f32 eyeOffset; /* 0x720 */
    f32 pitchOffset; /* 0x724 */
    f32 state728;
    f32 lean; /* 0x72C */
    f32 state730;
    f32 state734;
    f32 state738;
    s32 state73C;
    f32 baseHeight; /* 0x740 */
    f32 verticalOffset; /* 0x744 */
    CVector3 velocity; /* 0x748 */
    f32 velocityScale; /* 0x754 */
    s32 state758;
    s32 state75C;
    u8 pad760[0x10];
    s16 weapon; /* 0x770 */
    u8 pad772[2];
    CVector3 requestedPosition; /* 0x774 */
    f32 cameraOffset; /* 0x780 */
    f32 cameraScale; /* 0x784 */
    s32 controllerMode; /* 0x788 */
    f32 controllerTimer; /* 0x78C */
    u8 pad790[0x58];
    s32 state7E8; /* 0x7E8: Fx_BuildControllerState */
    f32 state7EC; /* 0x7EC */
    u8 pad7F0[0x1C];
    s32 controllerEnabled; /* 0x80C */
    u8 pad810[0x5C];
    s32 animation; /* 0x86C */
    u8 pad870[0xC8];
    s32 weaponBusy; /* 0x938 */
    u8 pad93C[0x37C];
    s32 weaponLocked; /* 0xCB8 */
    u8 padCBC[0x4F8];
    s32 locked; /* 0x11B4 */
    s32 lockState; /* 0x11B8 */
    void *firstHandle; /* 0x11BC */
    void *secondHandle; /* 0x11C0 */
    u8 pad11C4[0x14];
    f32 cooldown; /* 0x11D8 */
    u8 pad11DC[8];
    f32 pending; /* 0x11E4 */
    u8 pad11E8[4];
    f32 glow; /* 0x11EC: Render_DrawCharacterEffectParts */
    u8 pad11F0[4];
    f32 fireSpin; /* 0x11F4 */
    s32 fireFrame; /* 0x11F8 */
    f32 zoom; /* 0x11FC */
    CVector3 aimPosition; /* 0x1200 */
    s32 zoomMode; /* 0x120C */
    s32 overlay; /* 0x1210 */
    u8 pad1214[0x18];
    s32 reactionFlags; /* 0x122C */
    u8 pad1230[0xC];
    u8 color[3]; /* 0x123C: Render_DrawPlayerBodyAndWeapon */
    u8 pad123F;
    f32 opacity; /* 0x1240 */
    u8 pad1244[0xF8];
    s32 countdown; /* 0x133C: func_80449870_de */
    s32 resetState; /* 0x1340 */
    u8 pad1344[0x70];
    void *animationTable; /* 0x13B4 */
    u8 pad13B8[0x10];
    s32 overkill; /* 0x13C8: Render_ApplyPlayerDamage, Render_DrawPlayerBodyAndWeapon */
    u8 pad13CC[8];
    s32 toggle; /* 0x13D4 */
    void *reactionOwner; /* 0x13D8 */
    u8 pad13DC[0x74];
    s32 computer; /* 0x1450 */
    struct AiController * controller; /* 0x1454 */
};


struct func_8020A028_S4;
typedef struct func_8020A028_S4 func_8020A028_S4;

struct ObjRecAt1D8V2;
typedef struct ObjRecAt1D8V2 ObjRecAt1D8V2;

struct func_8022A404_S1;

struct func_80237E70_G1;
struct func_80237E70_G1 {
    u8 * unk0;
};

struct func_8022C070_S1;
typedef struct func_8022C070_S1 func_8022C070_S1;

struct Player;
typedef struct Player Player;

union func_80237E70_S1_UF24;
typedef union func_80237E70_S1_UF24 func_80237E70_S1_UF24;

struct Course;
struct Course {
    char pad0[0x28];
    u8 laps;
};

struct CollisionInfo8020CD74;
typedef struct CollisionInfo8020CD74 CollisionInfo8020CD74;

struct func_8021C9B4_S2;
typedef struct func_8021C9B4_S2 func_8021C9B4_S2;

struct ObjRecAtCV1;
typedef struct ObjRecAtCV1 ObjRecAtCV1;

struct ObjRecAtCV1;
struct ObjRecAtCV1 {
    char pad0[0xC];
    s16 unkC;
};

union func_80234DD0_S1_U260;
typedef union func_80234DD0_S1_U260 func_80234DD0_S1_U260;

struct Message;
struct Message {
    struct Message *prev; /* 0x00 */
    struct Message *next; /* 0x04: traversal from the message pool head */
    f32 hold; /* 0x08 */
    f32 size;
    f32 alpha;
    s32 kind;
    s32 timer;
    s32 target;
    s32 pad20;
    u8 *text;
    f32 progress;
    s32 pad2C;
    f32 x;
    f32 y;
    f32 scaleX;
    f32 scaleY;
};

struct Message;
union func_80237E70_S1_UF24;
union func_80237E70_S1_UF24 {
    struct Message * v0;
    char v1;
};

struct func_8022C884_S1;
typedef struct func_8022C884_S1 func_8022C884_S1;

struct func_80237E70_S2;
typedef struct func_80237E70_S2 func_80237E70_S2;

struct func_80209B64_S2;
struct func_80209B64_S2 {
    char pad0[0x93];
    u8 unk93;
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
struct View;

struct ObjRecAt18V5;
struct ObjRecAt18V5 {
    char pad0[0x18];
    void * unk18;
};

extern int D_800CE47C;

struct func_80229A54_S2;
struct func_80229A54_S2 {
    char pad0[0x5D8];
    char * unk5D8;
    char pad5D8[0x16E0 - 0x5D8 - sizeof(char*)];
    char * unk16E0;
};

struct Message;
typedef struct Message Message;

union func_80234DD0_S1_U260;
union func_80234DD0_S1_U260 {
    CVector3 v0;
    f32 v1;
};

struct Message;
union func_80237E70_S2_UE40;
union func_80237E70_S2_UE40 {
    char v0;
    struct Message * v1;
};

union func_80237E70_S2_UE40;
typedef union func_80237E70_S2_UE40 func_80237E70_S2_UE40;

struct func_80237E70_S2;
struct func_80237E70_S2 {
    char pad0[0xE40];
    IntrusiveList unkE40;
};

struct ObjectLinks3C;
typedef struct ObjectLinks3C ObjectLinks3C;

struct func_80237E70_S4;
typedef struct func_80237E70_S4 func_80237E70_S4;

struct ObjRecAt5D8;
typedef struct ObjRecAt5D8 ObjRecAt5D8;

struct ObjRecAt5D8;
struct ObjRecAt5D8 {
    char pad0[0x5D8];
    void * unk5D8;
};

struct func_80237E70_G1;
typedef struct func_80237E70_G1 func_80237E70_G1;

struct ModelBlend;
struct ModelBlend {
    s32 kind; /* 0x00 */
    char pad4[0x28];
    f32 blend; /* 0x2C: model-specific player interpolation target */
    u8 pad30[4];
    CVector3 effectOffset; /* 0x34 */
    u8 pad40[4];
    s32 collisionFlags; /* 0x44: model collision eligibility */
    char pad48[4];
    u32 collisionOptions; /* 0x4C */
    char pad50[2];
    u16 materialFlags; /* 0x52 */
    char pad54[4];
    u8 byte58; /* model byte queried by func_80276054_de */
    u8 byte59; /* model byte queried by func_80276088_de */
    char pad5A[0x9A];
    f32 height;
};

struct ObjRecAt20V2;
struct ObjRecAt20V2 {
    char pad0[0x20];
    char * unk20;
};


union func_80209DAC_S2_U93;
typedef union func_80209DAC_S2_U93 func_80209DAC_S2_U93;

struct func_80216BF4_S1;
struct func_80216BF4_S1 {
    char pad0[0xC];
    f32 unkC;
};

union func_80209DAC_S2_U93;
union func_80209DAC_S2_U93 {
    u8 v0;
    s8 v1;
};

struct func_8021C9B4_S2;
struct func_8021C9B4_S2 {
    char pad0[0x81];
    u8 unk81;
    char pad81[0x8F - 0x81 - sizeof(u8)];
    u8 unk8F;
};

struct Message;
struct func_80237E70_S4;
struct func_80237E70_S4 {
    char pad0[0x4];
    struct Message * unk4;
};

struct func_8020D1FC_S1;
struct func_8020D1FC_S1 {
    char pad0[0x38];
    s32 unk38;
};

struct func_8020D1FC_S1;
typedef struct func_8020D1FC_S1 func_8020D1FC_S1;


struct func_80207ABC_S1;
typedef struct func_80207ABC_S1 func_80207ABC_S1;

struct func_80237E70_S1;
struct func_80237E70_S1 {
    char pad0[0xF24];
    IntrusiveList unkF24;
};

struct ModelBlend;
typedef struct ModelBlend ModelBlend;

struct Course;
typedef struct Course Course;

struct ObjectLinks3C;
struct ObjectLinks3C {
    char pad0[0x18];
    char * unk_18;
    char pad18[0x38 - 0x18 - sizeof(char*)];
    s32 unk_38;
};


struct func_80204620_S2;
struct func_80204620_S2 {
    char pad0[0x28];
    s16 unk28;
};

struct func_80207ABC_S1;
struct func_80207ABC_S1 {
    char pad0[0x18];
    void * unk18;
    char pad18[0x38 - 0x18 - sizeof(void*)];
    s32 unk38;
};

struct ObjRecAt1D8V2;
struct ObjRecAt1D8V2 {
    char pad0[0x1D8];
    char * unk1D8;
};

struct func_80203E78_S1;
struct func_80203E78_S1 {
    char pad0[0x4];
    s32 unk4;
};

struct func_8022C070_S1;
struct func_8022C070_S1 {
    char pad0[0x2C];
    f32 unk2C;
};

struct func_80216BF4_S1;
typedef struct func_80216BF4_S1 func_80216BF4_S1;

struct func_8020A028_S4;
struct func_8020A028_S4 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s32 unkC;
    char padC[0x10 - 0xC - sizeof(s32)];
    s32 unk10;
};

struct func_80228774_S1;
struct func_80228774_S1 {
    char pad0[0x20];
    void * unk20;
};

struct ObjRecAt20V2;
typedef struct ObjRecAt20V2 ObjRecAt20V2;

struct func_8022C884_S1;
struct func_8022C884_S1 {
    char pad0[0x1C];
    int unk1C;
    char pad1C[0x20 - 0x1C - sizeof(int)];
    int unk20;
    char pad20[0x24 - 0x20 - sizeof(int)];
    int unk24;
};

extern int D_801371DC;

extern int D_800CE430[];

struct func_8022A404_S1;
typedef struct func_8022A404_S1 func_8022A404_S1;

struct RecordRecAt94;
typedef struct RecordRecAt94 RecordRecAt94;

struct func_80237E70_S1;
typedef struct func_80237E70_S1 func_80237E70_S1;

struct func_80209B64_S2;
typedef struct func_80209B64_S2 func_80209B64_S2;

struct ObjRecAt18V5;
typedef struct ObjRecAt18V5 ObjRecAt18V5;

struct CollisionInfo8020CD74;
struct CollisionInfo8020CD74 {
    s32 w[7];
};

struct func_80229A54_S2;
typedef struct func_80229A54_S2 func_80229A54_S2;

struct func_80203E78_S1;
typedef struct func_80203E78_S1 func_80203E78_S1;

struct func_80228774_S1;
typedef struct func_80228774_S1 func_80228774_S1;

#endif
