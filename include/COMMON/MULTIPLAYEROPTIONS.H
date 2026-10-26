#ifndef COMMON_MULTIPLAYEROPTIONS_H
#define COMMON_MULTIPLAYEROPTIONS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct SharedPlayer;

struct Actor_func_802238E0_de;
struct Actor_func_802238E0_de {
    char pad0[0x8];
    CVector3 unk8;
    char pad14[0xc];
    f32 unk20;
    char pad24[0x14];
    s32 inputFlags;
};

extern float D_800C78BC;


struct Body_func_80224408_de;
struct Body_func_80224408_de {
    char pad0[8];
    s32 x;
    s32 y;
    s32 z;
    char pad14[0x18 - 0x14];
    func_80204468_S3 *surface;
    char pad1C[0x20 - 0x1C];
    s32 stroke;
    char pad24[0x38 - 0x24];
    s32 flags;
    char pad3C[0x6C - 0x3C];
    f32 heading;
};

struct ObjectLinks854;
struct ObjectLinks854 {
    char pad0[0x14];
    u16 * unk_14;
    char pad14[0x50 - 0x14 - sizeof(u16*)];
    f32 unk_50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk_54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk_58;
    char pad58[0x5DC - 0x58 - sizeof(f32)];
    void * unk_5DC;
    char pad5DC[0x664 - 0x5DC - sizeof(void*)];
    u32 unk_664;
    char pad664[0x850 - 0x664 - sizeof(u32)];
    s32 unk_850;
};

struct Body_func_80224C4C_de;
struct Body_func_80224C4C_de {
    char pad0[8];
    s32 x;
    s32 y;
    s32 z;
    char pad14[0x18 - 0x14];
    func_80204468_S3 *surface;
    char pad1C[0x20 - 0x1C];
    s32 stroke;
    char pad24[0x38 - 0x24];
    s32 flags;
};

struct Body_func_80224C4C_de;
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
struct SharedPlayer;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* This transition uses the canonical player record; its original fields have identical offsets. */

struct BodyRecAt1C;
struct BodyRecAt1C {
    char pad0[0x1C];
    s32 motion[3];
};
struct BodyRecAt1C;
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

struct func_8021CD70_S1;
struct func_8021CD70_S1 {
    char pad0[0x170];
    s8 unk170;
    char pad170[0x4BD];
    s16 unk62E;
};


struct MovementDescriptor;
typedef struct MovementDescriptor MovementDescriptor;

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
struct SharedPlayer;
struct Shared_Body;
struct Shared_Hud;
struct Shared_Model;
struct Shared_Profile;
struct Shared_StateInfo;
struct Shared_Voice;
struct StateInfo;
struct TeamInfo;
struct View;
/* Movement and transition share the canonical player record. */

struct Body_func_80224F5C_de;
struct Body_func_80224F5C_de {
    char pad0[8];
    s32 x;
    s32 y;
    s32 z;
    char pad14[0x20 - 0x14];
    s32 stroke;
    char pad24[0x38 - 0x24];
    s32 flags;
};

struct Body_func_80224F5C_de;
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


struct ObjectState54;
struct ObjectState54 {
    char pad0[0x30];
    f32 unk_30;
    char pad30[0x52 - 0x30 - sizeof(f32)];
    u16 unk_52;
};

extern float D_800C9FA0_de;

extern float D_800C2994_de;

struct Tuning;
struct Tuning {
    char pad0[0x22];
    s16 strokeSound;
};

struct PlayerWeaponsUpdatePlayerCamera;
typedef struct PlayerWeaponsUpdatePlayerCamera PlayerWeaponsUpdatePlayerCamera;

extern float D_800C299C_de;


struct MovementDescriptor;
/* The definition kind selects the word-health or halfword-health payload. */
#include "COMMON/ACTOR_DEFINITION.H"
typedef struct ActorHealthDefinition {
    ActorDefinitionHeader header;
    s32 health;
} ActorHealthDefinition;
typedef struct PickupHealthDefinition {
    ActorDefinitionHeader header;
    s16 health;
} PickupHealthDefinition;
struct MovementDescriptor {
    ActorHealthDefinition body;
    f32 speed;
    u8 pad20[0x20];
    u8 secondaryLevel;
    u8 level;
};

struct PlayerWeaponsUpdatePlayerCamera;
struct PlayerWeaponsUpdatePlayerCamera {
    char pad0[0x5D0];
    s32 cameraMode;
    char pad5D4[0x5DC - 0x5D4];
    void *view;
    char pad5E0[0x6AC - 0x5E0];
    s32 input;
    char pad6B0[0x708 - 0x6B0];
    f32 pitchBase;
    char pad70C[0x718 - 0x70C];
    f32 crouch;
    char pad71C[0x720 - 0x71C];
    f32 duck;
    f32 angles[3];
    f32 sway[3];
    f32 eye[3];
    char pad748[0x780 - 0x748];
    f32 eyeOffset;
    char pad784[0x7EC - 0x784];
    f32 zoom;
};

struct BodyWeaponsUpdatePlayerCamera;
struct BodyWeaponsUpdatePlayerCamera {
    char pad0[8];
    f32 x;
    f32 y;
    f32 z;
    s32 room;
    char pad18[0x5C - 0x18];
    Shared_Quad rotation;
    f32 heading;
};

struct BodyRecAt1C;
typedef struct BodyRecAt1C BodyRecAt1C;


struct SharedMovement;
typedef struct SharedMovement SharedMovement;

extern float D_800C2960_de;

struct func_80224078_Arg1;
typedef struct func_80224078_Arg1 func_80224078_Arg1;


struct Tuning;
typedef struct Tuning Tuning;


struct func_80224078_Arg0;
typedef struct func_80224078_Arg0 func_80224078_Arg0;


extern float D_800C2988_de;

struct Shared_HudPlayer;
typedef struct Shared_HudPlayer Shared_HudPlayer;

struct ObjectState521;
struct ObjectState521 {
    unsigned char padding_0[1312];
    u8 unk_520;
};

struct Desc;
typedef struct Desc Desc;



struct ObjectState108;
struct ObjectState108 {
    char pad0[0x44];
    u32 resourceFlagBits;
    char pad44[0xFC - 0x44 - sizeof(u32)];
    f32 unk_FC;
    char padFC[0x100 - 0xFC - sizeof(f32)];
    f32 unk_100;
    char pad100[0x104 - 0x100 - sizeof(f32)];
    f32 unk_104;
};

struct ObjectState108;
typedef struct ObjectState108 ObjectState108;

struct func_8021CD70_S1;
typedef struct func_8021CD70_S1 func_8021CD70_S1;

struct ObjectState54;
typedef struct ObjectState54 ObjectState54;

struct Desc;

extern float D_800C2998_de;

extern float D_800C2980_de;

extern float D_800C78B8;


struct func_8021CD70_S2;
typedef struct func_8021CD70_S2 func_8021CD70_S2;

extern float D_800C2978_de;

extern float D_800C2984_de;

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

struct Shared_HudOwner;
struct Shared_HudOwner {
    char pad0[0x4];
    s16 score;
    s16 count;
    char pad8[0x7C];
    char name[11];
    u8 active;
    char pad90[0x2];
    u8 team;
};
struct Shared_HudOwner;
struct Shared_HudPlayer;
struct Shared_HudPlayer {
    char pad0[0xE4];
    u16 kind;
    char padE6[0x4F2];
    struct Shared_HudOwner *owner;
    char pad5DC[0x8];
    s32 health;
    char pad5E8[0x2];
    s16 lives;
    char pad5EC[0xC];
    s16 ammo;
    char pad5FA[0x34];
    s16 weapon;
    char pad630[0x248];
    char effect[0xC0];
    char strokes[0x394];
    char trails[0x74];
    char marks[0xEC];
    char anim0[0x3C];
    char anim1[0x3C];
    char anim2[0x3C];
    char anim3[0x10];
    f32 healthX;
    f32 healthY;
    char padEF8[0x24];
    s32 livesAnim;
    char padF20[0x4];
    s32 livesShown;
    char padF28[0x4];
    f32 livesX;
    f32 livesY;
    char padF34[0x20];
    s32 livesLast;
    char anim5[0xF0];
    s32 scoreAnim;
    char pad104C[0x4];
    u32 scoreState;
    char pad1054[0x4];
    f32 scoreX;
    f32 scoreY;
    char pad1060[0x1C];
    f32 alpha;
    s32 scoreLast;
    s32 countAnim;
    char pad1088[0x4];
    u32 countState;
    char pad1090[0x4];
    f32 countX;
    f32 countY;
    char pad109C[0x20];
    s32 countLast;
    s32 squadAnim;
    char pad10C4[0x4];
    u32 squadState;
    char pad10CC[0x4];
    f32 squadX;
    f32 squadY;
    char pad10D8[0x20];
    s32 squadLast;
    char pad10FC[0x8];
    s32 flashState;
    char pad1108[0x28];
    f32 flashAlpha;
    s32 flashHealth;
    char pad1138[0x8];
    s32 iconState;
    char pad1144[0x28];
    f32 iconAlpha;
    s32 iconLast;
    char pad1174[0x8];
    s32 statusState;
    char pad1180[0x28];
    f32 statusAlpha;
    s32 statusLast;
    char pad11B0[0x1C];
    s32 scoreFrame;
    s32 squadFrame;
    s32 countFrame;
    f32 hurt;
    char pad11DC[0x8];
    f32 boost;
    char pad11E8[0x44];
    s32 fxFlags;
    f32 fxTime;
    char pad1234[0x4];
    s32 fxStage;
    char pad123C[0x84];
    f32 zoom;
    char pad12C4[0x8];
    struct Shared_HudPlayer *names[8];
    char pad12EC[0x8];
    s32 nameFades[8];
    s32 nameWidths[8];
    s32 nameTail;
    s32 nameHead;
    s32 lifeCount;
    char pad1340[0x110];
    s32 hideLives;
};

struct ObjectLinks854;
typedef struct ObjectLinks854 ObjectLinks854;

extern float D_800C2968_de;


struct Body_func_80224408_de;
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

extern float D_800C298C_de;

struct View;

struct BodyWeaponsUpdatePlayerCamera;
typedef struct BodyWeaponsUpdatePlayerCamera BodyWeaponsUpdatePlayerCamera;

struct SharedMovement;
struct SharedMovement {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    char pad20[0x2];
    s16 unk22;
};

extern float D_800CAB88_eu;

extern float D_800CAB78_eu[];

struct Body_func_80224F5C_de;
typedef struct Body_func_80224F5C_de Body_func_80224F5C_de;

struct Body;
struct Character;
struct Controller;
struct Controls;
struct Ctrl;
struct Held;
struct Mode;
struct ModelBlend;
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

extern float D_800C2970_de;

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

struct func_80224078_Arg0;
struct func_80224078_Arg0 {
    char pad0[0x5DC];
    void *unk5DC;
    char pad5E0[0x650 - 0x5E0];
    s16 unk650;
    char pad652[0x698 - 0x652];
    void *unk698;
    char pad69C[0x6A4 - 0x69C];
    f32 unk6A4;
    f32 unk6A8;
    s32 unk6AC;
    s32 unk6B0;
    char pad6B4[0x6C0 - 0x6B4];
    f32 unk6C0;
    f32 unk6C4;
    char pad6C8[0x6E8 - 0x6C8];
    CVector3 unk6E8;
    char pad6F4[0x724 - 0x6F4];
    f32 unk724;
    s32 unk728;
    s32 unk72C;
};




struct func_8021CD70_S2;
struct ObjRecAt14V3;
struct func_8021CD70_S2 {
    char pad0[0x18];
    struct ObjRecAt14V3 * unk18;
    char pad18[0xE4];
    s32 unk100;
    char pad100[0x70];
    s32 unk174;
    char pad174[0x2C];
    s8 unk1A4;
    char pad1A4[0x437];
    void * unk5DC;
};

extern float D_800C297C_de;

struct func_80224078_Arg1;
struct func_80224078_Arg1 {
    char pad0[8];
    char unk8;
    char pad9[0x14 - 9];
    s32 unk14;
    char pad18[0x20 - 0x18];
    f32 unk20;
    char pad24[0x6C - 0x24];
    f32 unk6C;
};

extern float D_800C2974_de;

struct ObjectState521;
typedef struct ObjectState521 ObjectState521;


struct SharedPlayer;




struct Actor_func_802238E0_de;
typedef struct Actor_func_802238E0_de Actor_func_802238E0_de;

struct Body_func_80224408_de;
typedef struct Body_func_80224408_de Body_func_80224408_de;

struct Body_func_80224C4C_de;
typedef struct Body_func_80224C4C_de Body_func_80224C4C_de;

struct ModelBlend;
struct Object;


extern float D_800C2990_de;


#include "WEAPONS/AIM_TYPES.H"






extern const f32 D_800C23B4_de;
extern const f32 D_800C23B8_de;

typedef struct DraftAimPlayer {
    char pad0[8]; CVector3 position;
    char pad14[0x5C]; f32 height;
    char pad74[0x1D4]; CVector3 specialAim;
    char pad254[0x3DA]; s16 weapon;
    char pad630[0x10B0]; struct DraftAimPlayer *next;
} DraftAimPlayer;
typedef struct DraftAimWeapon { char pad0[0x1C]; f32 angle; } DraftAimWeapon;
typedef struct AimGlobals { void *head; char pad4[0x1281]; u8 enabled; } AimGlobals;
extern f32 Player_GetObjectOwnerHeight(void *);

typedef struct ThrowDefinition { s32 kind; } ThrowDefinition;
typedef struct ThrowState { u32 flags; s32 active; char pad08[0x2C]; s8 kind, timer; } ThrowState;
typedef struct ThrowActor {
    u8 category; char pad01[0x17]; ThrowDefinition *definition;
    f32 vx, vy, vz; char pad28[0x148]; ThrowState state;
} ThrowActor;
typedef struct ThrowPlayer {
    char pad00[0x5DC]; void *effect;
    char pad5E0[0x84]; u32 flags;
    char pad668[0x58]; f32 speed;
    char pad6C4[0x148]; ThrowActor *selected;
} ThrowPlayer;
typedef struct ThrowPosition {
    char pad00[8]; CVector3 pos; char pad14[0x58]; f32 angle;
} ThrowPosition;
extern f32 D_800C2870_de;
extern f32 D_800C2878_de;
extern void Sky_StartScaledShake(char *, f32, f32, f32, f32, s32, CVector3);

typedef struct PowerHudAnimation {
    void *object; s32 pad4, state; f32 padC, x, y;
    char pad18[0x20]; s32 last;
} PowerHudAnimation;
typedef struct PowerHudPlayer {
    char pad0[0x5F4]; s16 first, second, third;
    char pad5FA[0x34]; s16 weapon;
    char pad630[0x7FC]; PowerHudAnimation a,b,c;
    char padEE0[0x4D8]; s32 refreshA,refreshB,refreshC;
} PowerHudPlayer;
extern s32 Frontend_GetScreenMode(void);
extern s32 func_8022AB9C_de(void *);
extern s32 func_802AA70C_de(void *,s32 *);
extern void OnScreen_DrawSpriteNumber(s32,f32,f32,f32,f32,s32,s32,s32);
extern s32 D_800C9288_de[];
extern s32 D_800C9328_de[];
extern s32 D_800C9368[];
extern s32 D_800C9398_de[];
#endif
