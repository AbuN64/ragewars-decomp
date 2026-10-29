#ifndef WEAPONS_PLAYERRECAT1450V1_H
#define WEAPONS_PLAYERRECAT1450V1_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WEAPON_MARKER_AND_PROFILE_VIEWS.H"
struct WeaponPlayerPermissionView;
typedef struct WeaponPlayerPermissionView WeaponPlayerPermissionView;

struct WeaponSwitchActionView;
struct WeaponSwitchActionView {
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
    s32 reservedWord;
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

extern float g_weaponSpinClampedFeedback;

struct WeaponNormalFireActionView;
typedef struct WeaponNormalFireActionView WeaponNormalFireActionView;

extern float g_weaponFireInitialValue;

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

extern float g_weaponSpinNegativeFeedbackLimit;

extern float g_weaponSpinPositiveOutputScale;

extern float g_weaponSpinPositiveFeedbackScale;



struct WeaponPlayerPermissionView;
struct WeaponPlayerPermissionView {
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

extern float g_chargedAlternateFirstMessageDuration;

extern float g_weaponTriggerStunThreshold;

extern void Weaponai_ApplyWeaponSwitch(void *part, void *body);



struct Event;
typedef struct Event Event;


struct WeaponSwitchActionView;
typedef struct WeaponSwitchActionView WeaponSwitchActionView;

extern s32 Weapon_IsSpecialSwitchGroup(s32 weaponId);

struct Shared_ActorView;
struct WeaponFireState;


extern float g_weaponEightChargeRateScale;



extern float g_weaponPermissionNoticeDuration;

extern float g_weaponSideYawSpeedScale;

struct WeaponNormalFireActionView;
struct WeaponNormalFireActionView {
    char pad0[0x64];
    f32 unk_64;
    char pad64[0x130 - 0x64 - sizeof(f32)];
    f32 unk_130;
    char pad130[0x13C - 0x130 - sizeof(f32)];
    s32 unk_13C;
};

extern s32 Weapon_IsPrimarySwitchGroup(s32 weaponId);

struct Dest;
struct Lookup;
extern void Weapon_DrawWeaponLookupModel(void *actor, struct Dest *weaponState, struct Lookup *lookup);

extern float g_chargedAlternateSecondMessageDuration;

extern void Weaponai_InitializeSwitchAndRequestIdle(void *actor, void *weaponFireState);


extern void YawMatrixLocal(void *, float);
extern void Playerai_StartPrimaryAttachedSound(struct Shared_ActorView *actor, s32 soundId);
extern void YawMatrixLocal(void *, f32);
#endif
