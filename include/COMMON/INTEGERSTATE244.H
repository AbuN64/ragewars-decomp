#ifndef COMMON_INTEGERSTATE244_H
#define COMMON_INTEGERSTATE244_H
struct SharedPlayer;
#ifndef SPAN_1000_CODE_8022C894_H
#define SPAN_1000_CODE_8022C894_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LIBSN_AND_RESIDENT_CALLBACKS.H"
struct PlayerSequenceRunEndStateView;
typedef struct PlayerSequenceRunEndStateView PlayerSequenceRunEndStateView;



extern void func_8022D420_de(void);

extern void Playerai_SetRunEndFlag(struct SharedPlayer *player);

struct PlayerSequenceRunEndActorView;
typedef struct PlayerSequenceRunEndActorView PlayerSequenceRunEndActorView;

extern void Player_AimPreviousPositionAtReset(void *aimPlayerState);

extern void func_8022D254_de(void);


extern float g_playerLateralLeapVerticalSpeed;





extern float g_playerRunEndTransitionDelay;


extern void func_8022D49C_de(void);

extern float g_playerShortSequenceWaitLimit;

extern float g_playerFloatPoseMinimumDuration;






extern float g_playerMotionDamping;

extern float g_playerLateralLeapInitialVerticalSpeed;

extern float g_playerFloatForwardAnimationThreshold;

extern float g_playerLateralLeapDuration;





struct PlayerSequenceRunEndStateView;
struct PlayerSequenceRunEndStateView {
    unsigned char padding_0[572];
    s32 unk_23C;
    s32 unk_240;
};

extern float g_playerLateralLeapNegativeInputSpeed;

extern void Player_ClearGlobalFlagBit(void);


extern void func_8022D20C_de(void);


extern void func_8022D3F4_de(void);




extern float g_playerRunEndModelScale;


extern void func_8022D288_de(void);

extern void func_8022D4A4_de(void);



extern void func_8022C8EC_de(void);


extern float g_playerLateralLeapPositiveInputSpeed;

struct PlayerStrafeVelocityView;
typedef struct PlayerStrafeVelocityView PlayerStrafeVelocityView;


extern void func_8022C8F4_de(void);

extern void Player_ResetStunFlags(void *actorState);




extern void func_8022D1A0_de(void);

struct PlayerSequenceRunEndActorView;
struct PlayerSequenceRunEndActorView {
    char pad0[0x50];
    f32 unk_50;
    char pad50[0x54 - 0x50 - sizeof(f32)];
    f32 unk_54;
    char pad54[0x58 - 0x54 - sizeof(f32)];
    f32 unk_58;
    char pad58[0x658 - 0x58 - sizeof(f32)];
    f32 unk_658;
    char pad658[0x122C - 0x658 - sizeof(f32)];
    s32 unk_122C;
    char pad122C[0x1230 - 0x122C - sizeof(s32)];
    s32 unk_1230;
    char pad1230[0x1238 - 0x1230 - sizeof(s32)];
    s32 unk_1238;
    char pad1238[0x13C8 - 0x1238 - sizeof(s32)];
    s32 unk_13C8;
    char pad13C8[0x1454 - 0x13C8 - sizeof(s32)];
    void * unk_1454;
};


extern float g_playerFloatReverseAnimationThreshold;


struct PlayerStrafeVelocityView;
struct PlayerStrafeVelocityView {
    unsigned char padding_0[1700];
    f32 unk_6A4;
    unsigned char padding_6A8[28];
    f32 unk_6C4;
};









extern float g_playerJumpInitialSpeedScale;

extern void func_8022D198_de(void);

extern void func_8022D3EC_de(void);

extern void Graphu64_EaseValueToward(f32 *value, f32 target, f32 rate);
extern void Player_UpdateLeapMotion(s32 player, s32 body);

extern void Player_UpdateRunEndPlayer(void *);
struct PlayerSequenceActorView;
extern void Playerai_TryStartPlayerSequence(struct PlayerSequenceActorView *a, void *b, int c);

s32 Playerai_ApplyProjectileStatus(s32, void *, s32, s32);


#endif
#endif
