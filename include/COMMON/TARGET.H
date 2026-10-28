#ifndef COMMON_TARGET_H
#define COMMON_TARGET_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Target;
struct Target {
    u8 kind;
    char pad1[3];
    u16 type;
};

struct Vec4s;
typedef struct Vec4s Vec4s;


extern float D_800C442C_de;


struct ResourceManagerState;
struct Triple;


extern float D_800C4440_de;

struct ActorEventsComputeDamageScale;
struct PlayerRecAt122C;
struct ActorEventsComputeDamageScale {
    char pad0[8];
    CVector3 position;
    char pad14[0x70 - 0x14];
    f32 height;
    char pad74[0x100 - 0x74];
    s32 flags;
    char pad104[0x1D8 - 0x104];
    struct PlayerRecAt122C *player;
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
struct func_8023945C_S1;

struct ActorEventsSpawnRiderImpactEffect;

struct ResourceManagerState;
struct Triple;
typedef void ( *EventsDispatchCallbackCallback)(void *, void *, signed int, CVector3, struct ResourceManagerState);

struct EventCallbackEntry;

extern float D_800C4424_de;




struct ClipEventTargetView;
typedef struct ClipEventTargetView ClipEventTargetView;



struct s_CEventValueFormat7a;
typedef struct s_CEventValueFormat7a CEventValueFormat7a;

extern float D_800C4420_de;



struct ActorEventsSpawnRiderImpactEffect;
typedef struct ActorEventsSpawnRiderImpactEffect ActorEventsSpawnRiderImpactEffect;

struct ActorEventsComputeDamageScale;
struct Carrier;


struct EventCallbackEntry;
typedef struct EventCallbackEntry EventCallbackEntry;

struct Carrier;
typedef struct Carrier Carrier;

struct ActorEventsComputeDamageScale;
typedef struct ActorEventsComputeDamageScale ActorEventsComputeDamageScale;

struct ClipEventTargetView;

struct Vec4s;

extern float D_800C9538;


struct NodeEventsStartCameraFadeAtPoint;
struct NodeEventsStartCameraFadeAtPoint {
    s32 unused;
    struct NodeEventsStartCameraFadeAtPoint *next;
};


extern float D_800C46E8_eu;

struct s_CEventValueFormat7a;


extern float D_800C4428_de;

struct NodeEventsStartCameraFadeAtPoint;
typedef struct NodeEventsStartCameraFadeAtPoint NodeEventsStartCameraFadeAtPoint;

extern float D_800C4430_de;

struct Target;
typedef struct Target Target;


extern s32 SoundElement_PlayPositionedSoundWithScale(s32 trackId, CVector3 soundPosition, s32 spatialMode, s32 ownerId,
                         f32 playbackScale);

extern void Weapon_SpawnTargetPlayerFireEffect(void *aiTarget, s32 unused1, s32 effect);
#endif
