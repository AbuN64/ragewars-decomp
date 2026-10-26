#ifndef MENU_TEAMMENU_H
#define MENU_TEAMMENU_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct TeamMenu;
typedef struct TeamMenu TeamMenu;

extern float D_800C2250_de;

extern float D_800C22A8_de;

struct Shared_ActorView;

/* The weapon barrel (wheel) menu: CBarrel_t and CBarrelWeapon_t of the debug catalog. */
typedef struct CBarrelWeapon_t {
    s32 m_Weapon;
    void *m_pInfo;
    s32 m_bEnabled;
    f32 m_Rot;
    f32 m_Spin;
    f32 m_Scale;
} CBarrelWeapon;
typedef struct CBarrel_t {
    s32 m_Mode;
    f32 m_Time;
    f32 m_Alpha;
    f32 m_Rot;
    s32 m_Dir;
    f32 m_Glow;
    s32 CurrentWeaponListSize;
    CBarrelWeapon m_WeaponList[36];
    s32 m_Selected;
    s32 m_QuickSelect;
    s32 m_ButtonAWheel;
    s32 m_DisplaySlot;
    s32 m_UnderwaterWhenSetup;
    s32 m_WheelIndexLastFrame;
} CBarrel;

extern float D_800C2254_de;

struct Item;
typedef struct Item Item;

struct SlotRecAt10;
typedef struct SlotRecAt10 SlotRecAt10;


struct Entry;
typedef struct Entry Entry;

struct PlayerRecAt698;
typedef struct PlayerRecAt698 PlayerRecAt698;

struct Menu_func_80218F9C_de;
typedef struct Menu_func_80218F9C_de Menu_func_80218F9C_de;

struct ControllerRecAtC7;
struct PlayerRecAt698;
struct PlayerRecAt698 {
    char pad0[0x698];
    struct ControllerRecAtC7 *controller;
};

struct ObjectLinks11BC;
struct ObjectLinks11BC {
    char pad0[0x5D8];
    char * unk_5D8;
    char pad5D8[0x670 - 0x5D8 - sizeof(char*)];
    f32 unk_670;
    char pad670[0x698 - 0x670 - sizeof(f32)];
    char * unk_698;
    char pad698[0x11B4 - 0x698 - sizeof(char*)];
    s32 unk_11B4;
    char pad11B4[0x11B8 - 0x11B4 - sizeof(s32)];
    s32 unk_11B8;
};

struct ItemRecAt18V1;
typedef struct ItemRecAt18V1 ItemRecAt18V1;


struct Item;
struct Item {
    s32 slot;
    s32 weapon;
    CVector3 position;
    s32 icon;
    f32 width;
    f32 height;
};

struct SlotRecAt10;
struct SlotRecAt10 {
    s32 team;
    s32 unused;
    f32 angle;
    s32 unused2;
    f32 scale;
};

struct TeamMenu {
    s32 state;
    s32 unused;
    f32 open;
    s32 reset;
    u8 reserved10[4];
    f32 spin;
    s32 count;
    SlotRecAt10 slots[4];
    s32 cursor;
    s32 hover;
};

struct ObjectLinks11BC;
typedef struct ObjectLinks11BC ObjectLinks11BC;

struct IntegerState74;
struct IntegerState74 {
    char pad0[0x6C];
    s32 unk_6C;
    char pad6C[0x70 - 0x6C - sizeof(s32)];
    s32 unk_70;
};

struct Entry34;
struct Entry34 {
    char pad0[0x1C];
    s32 weapon;
    void *info;
    s32 owned;
    f32 x;
    s32 y;
    f32 z;
};


struct IntegerState74;
typedef struct IntegerState74 IntegerState74;


struct ObjectLinks69C;
typedef struct ObjectLinks69C ObjectLinks69C;

struct Entry;
struct Entry {
    char pad0[0x1E];
    u16 team;
    s32 enabled;
};

struct Entry34;
typedef struct Entry34 Entry34;


struct ItemRecAt18V1;
struct ItemRecAt18V1 {
    s32 slot;
    CVector3 position;
    s32 icon;
    f32 width;
    f32 height;
};

struct ObjectLinks69C;
struct ObjectLinks69C {
    unsigned char padding_0[1496];
    void *unk_5D8;
    unsigned char padding_5DC[188];
    void *unk_698;
};

extern float D_800C21F0_de;

extern float D_800C224C_de;

struct Body;
struct Character;
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
struct ObjRecAtB0;

extern float D_800C21E8_de;

extern float D_800C22C8_de;

struct ObjectLinks11B8;
struct ObjectLinks11B8 {
    char pad0[0x38];
    s32 unk_38;
    char pad38[0x5D8 - 0x38 - sizeof(s32)];
    char * unk_5D8;
    char pad5D8[0x62E - 0x5D8 - sizeof(char*)];
    s16 unk_62E;
    char pad62E[0x698 - 0x62E - sizeof(s16)];
    char * unk_698;
    char pad698[0x770 - 0x698 - sizeof(char*)];
    s16 unk_770;
    char pad770[0xCC0 - 0x770 - sizeof(s16)];
    s32 unk_CC0;
    char padCC0[0x11B4 - 0xCC0 - sizeof(s32)];
    s32 unk_11B4;
};


struct ObjectLinks11B8;
typedef struct ObjectLinks11B8 ObjectLinks11B8;

struct Menu_func_80218F9C_de;
struct Menu_func_80218F9C_de {
    s32 active;
    s32 unused;
    f32 open;
    char padC[0x10];
    SlotRecAt10 slots[4];
    s32 cursor;
};

typedef struct StickInput { char pad00[0xC6]; s8 x, y; } StickInput;
typedef struct StickPlayer { char pad00[0x698]; StickInput *input; } StickPlayer;

extern char s_selectTeamText[];

struct TeamWeaponPlayer;
typedef struct TeamWeaponPlayer TeamWeaponPlayer;
extern void TeamSelect_InitWeaponChoices(CBarrel *barrel, s32 buttonAWheel, TeamWeaponPlayer *player);

extern void func_8025E1C4_de(s32);
#endif
