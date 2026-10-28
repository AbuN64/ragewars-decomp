#ifndef TYPES_H
#define TYPES_H

struct ControllerProfile;

typedef signed char s8;

typedef unsigned char u8;

typedef signed short s16;

typedef unsigned short u16;

typedef signed int s32;

typedef unsigned int u32;

typedef signed long long s64;

typedef unsigned long long u64;

typedef float f32;

typedef double f64;

typedef struct IntrusiveList IntrusiveList;

/* A doubly linked list threaded through its nodes: head and tail are the end nodes, prevOffset and
   nextOffset are the byte offsets of the previous and next links inside each node, and count is the
   number of nodes. */
struct IntrusiveList {
    void *head;
    void *tail;
    s32 prevOffset;
    s32 nextOffset;
    s32 count;
};

struct IntrusiveList;

extern s32 Libsn_ReadPortWord(s32 portAddress);

extern void Scaled_ResetBehaviorState(void *object);

struct CloseAttackBrain;

extern s32 Nav_SelectCloseAttackPickupGoal(struct CloseAttackBrain *closeAttackBrain);

extern s32 Nav_SelectChaseObjectGoal(void *arg0);

struct AiController;

extern s32 Nav_SelectStationaryObjectGoal(struct AiController *controller);

extern void Nav_ResetPatrolRouteSelection(void *object);

extern void Nav_SelectFlaggedRoamingGoal(void *arg0);

struct AimPlayer;

extern void func_8021A9A4_de(struct AimPlayer *aimPlayer, s32 effect);

extern s32 Player_HasAmmoForMode(void *, s32);

extern void func_8022B00C_de(void *player);

struct LevelActor;

extern void Player_ZeroBodyVelocity(void *arg0, struct LevelActor *actor);

extern void Player_UpdateJumpAirMotion(void *player, void *body);

extern void Player_BeginLateralLeap(void *movementState, void *actorMotion);

extern void Player_AbsorbImpact(void *player, struct LevelActor *actor);

extern void Player_DampMotion(void *actorState, void *levelActor);

extern void Player_ResetMovementInput(void *motionPlayerState, struct LevelActor *actor);

extern void Player_ResetObjectVelocity(void *unused, void *object);

extern void Player_InitializeProfileSlot(s32 arg0);

extern void Cinema_SetResponse(float responseValue);

extern void Cinema_SetLoopMode(int loopMode);

extern void Cinema_SetViewport(int viewportWidth, int viewportHeight, int viewportLeft, int viewportTop);

extern void Cinema_InitializeSequenceOnce(s32 unused);

extern s32 Gobjinst_RequestAnimationIndex(void *levelActor, s32 animationIndex, s32 allowDuringBlend);

extern s32 Cache_EvictResource(s32 unused0, s32 unused1, s32 keep_recent);

extern void *Cache_AllocateHeapWithEviction(s32 arg0, u32 byteCount, s32 allocatorSelection, u32 evictionFlags);

extern void Cache_ClearResourceSlotProtection(s32, s32);

extern void func_80255F70_de(IntrusiveList *list);

struct RecordD90;

extern s32 Audio_ReleaseMatchingExclusiveVoice(struct RecordD90 *record, s16 value, s16 id);

extern void Audio_SetVoiceTrackId(void *arg0, int newTrackId);

extern void SoundElement_PlayDialogGroup(s32 callback);

extern void SoundElement_StopAudioExceptKey(s32 retainedKey);

extern void func_8025E2D4_de(s32 a);

extern void SoundElement_SetClampedAudioLevel(f32 arg0);

extern int Control_IsLeftPressed(struct ControllerProfile *object);

extern int Control_IsRightPressed(struct ControllerProfile *object);

extern s32 Control_AcquireControllerLock(s32 block);

extern int Control_IsControllerPakEnabled(int arg0);

extern void Control_SetControllerMode(s32 a);

extern void Gdynlight_ReleaseLight(void *a, s32 b);

extern void Graphu64_WrapPeriodicValue(f32 *value);

extern void Graphu64_NormalizeQuaternion(f32 *rotation);

extern f32 Graphu64_RandomFloat(f32 range);

extern f32 Graphu64_ArcCos(f32 cosineValue);

extern f32 Graphu64_IntegrateBoundedValue(f32 value, f32 velocity, f32 limit);

extern f32 Graphu64_DecayToZero(f32 value, f32 rate);

extern f32 Graphu64_RandomBetween(f32 shakeMin, f32 shakeMax);

extern void Gregion_DesaturateColor(u8 amount, u8 r, u8 g, u8 b, u8 *outR, u8 *outG, u8 *outB);

extern void Map_ResetFramePool(void *batch);

extern int Particle_HasSurfaceFlag(void *particle);

extern void Particle_StopSound(void *a);

extern void Rumble_RecycleFinishedEffectNodes(void *pool);

struct Shared_World;
struct CVector3_t;
extern s32 Scene_FindFloorPolygon(struct Shared_World *, struct CVector3_t *);

extern s32 Scene_GetModelSectionTwoRecord(void *world, s32 arg1);

extern void Sched_HandleRspCompletion(void *object);

struct OSSched;

extern void __scAppendList(struct OSSched *scheduler, void *task);

extern void __scYield(void *scheduler);

extern int SetN64_CompareByteStrings(u8 *a, u8 *b);

struct GameSession;

extern void SetN64_SetTransitionTarget(struct GameSession *object, int value);

extern void SetN64_ResetPlayerItems(s32 sessionAddress, s32 selectionKey);

extern void SetN64_InitializeFrontendScreenState(struct GameSession *gameSession);

extern s32 DispatchElementEvent(s32 id, s32 event, s32, s32, s32);

extern s32 SmSmngr_DispatchPrimaryScreenEvent(s32 event, s32, s32, s32);

extern f32 XMath_EvaluateSine(f32 arg0);

extern void XMath_EvaluateSineCosine(f32 angle, f32 *sinOut, f32 *cosOut);

extern f32 XMath_EvaluateArcTangentTwo(f32 y, f32 x);

extern void XMath_MultiplyMatrices(s32 matrix, s32 arg1, s32 arg2);

extern s32 XMath_AbsoluteInteger(s32 fifth);

extern void XMath_EvaluateCosine(f32 arg0);

extern f32 XMath_EvaluateArcSine(f32 x);

extern s32 XPlus_ParseDecimalInteger(u8 *s);

extern void N64Eng_GetScreenSize(int *arg0, int *arg1);

extern void Tsmos_SetModeOneFlag(s32 arg0);

extern void OnScreen_DrawTextGlyphs(u8 *text, f32 x, f32 y, f32 width, f32 height, s32 shadow, s32 alpha, s32 language);

extern void OnScreen_GetImageDimensions(s32 arg0, s32 arg1, s32 *arg2, s32 *arg3);

extern void OnScreen_SetTextColors(int arg0, int arg1, int arg2, int arg3, int arg4, int arg5);

extern void OnScreen_SetTextScale(float arg0, float arg1);

extern s32 Pickup_ApplyAmmo(void *player, void *pickupEntry);

extern s32 Pickup_ApplyLifePoints(void *arg0, void *arg1);

struct ActorPickupCanCollect;

struct MultiChannelItemEffect;

extern s32 Pickup_ApplyAmmoBundle(struct ActorPickupCanCollect *player, struct MultiChannelItemEffect *ammoBundle);

extern void osUnmapTLB(int arg0);

extern void __CSPHandleNextSeqEvent(void *rawPlayer);

extern void __CSPPostNextSeqEvent(void *arg0);

extern void __setUsptFromTempo(void *arg0, f32 arg1);

extern f32 func_802AFE30_de(s32 arg0);

extern void alCSPSetBank(s32 player, s32 bank);


extern void alCSPSetVol(s32 player, s16 arg1);

extern void alCopy(unsigned char *source, unsigned char *destination, int count);

extern s32 __voiceNeedsNoteKill(void *arg0, s32 targetVoice, s32 releaseDeadline);

extern void __seqpStopOsc(void *seqPlayer, void *voiceState);

extern float Math_Cosf(float x);

extern float Gu_Sinf(float x);

extern unsigned int func_802B7EF0_eu(void *motorContext);

extern void osViSwapBuffer(s32 framebuffer);

typedef struct OSMesgQueue OSMesgQueue;

struct OSMesgQueue {
    void **mtqueue;
    void **fullqueue;
    s32 validCount;
    s32 first;
    s32 msgCount;
    void **msg;
};

struct OSMesgQueue;

typedef struct Block40 Block40;

struct Block40 {
    u8 bytes[0x28];
};


struct Block40;

extern unsigned int func_802B80B4_eu(void *motorContext);

typedef struct __OSContRamReadFormat __OSContRamReadFormat;

struct __OSContRamReadFormat {
    u8 dummy;
    u8 txsize;
    u8 rxsize;
    u8 cmd;
    u16 address;
    u8 data[32];
    u8 datacrc;
};

struct __OSContRamReadFormat;

typedef struct OSPfs OSPfs;

struct OSPfs {
    int status;
    struct OSMesgQueue *queue;
    int channel;
    u8 id[32];
    u8 label[32];
    int version;
    int dir_size;
    int inode_table;
    int minode_table;
    int dir_table;
    int inode_start_page;
    u8 banks;
    u8 activebank;
};

struct OSPfs;

struct Triple;

extern u32 osMotorStop(struct Triple *);

extern u32 func_802B7C50_de(struct Triple *);

extern u32 func_802B7F30_eu_x(struct Triple *);

#endif
