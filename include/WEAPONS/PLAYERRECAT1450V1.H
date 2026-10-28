#ifndef WEAPONS_PLAYERRECAT1450V1_H
#define WEAPONS_PLAYERRECAT1450V1_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/OBJECTLINKS14C.H"
struct PlayerRecAt1450V1;
typedef struct PlayerRecAt1450V1 PlayerRecAt1450V1;

struct func_80232A38_S1;
struct func_80232A38_S1 {
    char pad0[0x2C];
    char * unk2C;
    char pad2C[0x108 - 0x2C - sizeof(char*)];
    char * unk108;
    char pad108[0x10C - 0x108 - sizeof(char*)];
    char * unk10C;
    char pad10C[0x124 - 0x10C - sizeof(char*)];
    s32 unk124;
    char pad124[0x128 - 0x124 - sizeof(s32)];
    s32 unk128;
    char pad128[0x12C - 0x128 - sizeof(s32)];
    f32 unk12C;
    char pad12C[0x130 - 0x12C - sizeof(f32)];
    s32 unk130;
    char pad130[0x138 - 0x130 - sizeof(s32)];
    s32 unk138;
    char pad138[0x13C - 0x138 - sizeof(s32)];
    s32 unk13C;
    char pad13C[0x144 - 0x13C - sizeof(s32)];
    s32 unk144;
    char pad144[0x148 - 0x144 - sizeof(s32)];
    s32 unk148;
    char pad148[0x14C - 0x148 - sizeof(s32)];
    s32 unk14C;
    char pad14C[0x150 - 0x14C - sizeof(s32)];
    s32 unk150;
};

extern float D_800C303C_de;

struct ObjectState140;
typedef struct ObjectState140 ObjectState140;

extern float D_800C3018_de;

struct SourceWeaponApplyScaledSideYaw;
struct SourceWeaponApplyScaledSideYaw {
    char pad[0x294];
    float speed;
};
struct Event;
struct SourceWeaponApplyScaledSideYaw;
struct Event {
    int unk0;
    int side;
    struct SourceWeaponApplyScaledSideYaw *source;
};

extern float D_800C3028_de;

extern float D_800C3038_de;

extern float D_800C302C_de;



struct PlayerRecAt1450V1;
struct PlayerRecAt1450V1 {
    char pad0[0x5D4];
    int character;
    char pad5D8[4];
    void *hud;
    char pad5E0[0x62E - 0x5E0];
    short weapon;
    char pad630[0x11D8 - 0x630];
    float shield;
    char pad11DC[0x1450 - 0x11DC];
    int isBot;
};

extern float D_800C2FC4_de;

extern float D_800C301C_de;

extern void Weaponai_ApplyWeaponSwitch(void *arg0, void *arg1);



struct Event;
typedef struct Event Event;


struct func_80232A38_S1;
typedef struct func_80232A38_S1 func_80232A38_S1;

extern s32 Weapon_IsSpecialSwitchGroup(s32 arg0);

struct Shared_ActorView;
struct WeaponFireState;


extern float D_800C3020_de;



extern float D_800C8100;

extern float D_800C8130;

struct ObjectState140;
struct ObjectState140 {
    char pad0[0x64];
    f32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(f32)];
    f32 unk_130;
    char pad130[0x13C - 0x130 - sizeof(f32)];
    s32 unk_13C;
};

extern s32 Weapon_IsPrimarySwitchGroup(s32 arg0);

struct Dest;
struct Lookup;
extern void Weapon_DrawWeaponLookupModel(void *arg0, struct Dest *arg1, struct Lookup *arg2);

extern float D_800C2FC8_de;

extern void Weaponai_InitializeSwitchAndRequestIdle(void *arg0, void *arg1);


extern void YawMatrixLocal(void *, float);
extern void func_8022AEA0_de(struct Shared_ActorView *arg0, s32 arg1);
extern void YawMatrixLocal(void *, f32);
#endif
