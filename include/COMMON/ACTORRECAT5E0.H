#ifndef COMMON_ACTORRECAT5E0_H
#define COMMON_ACTORRECAT5E0_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ActorRecAt5E0;
struct ActorRecAt5E0 {
    char pad0[8];
    Triple position;
    s32 id;
    char pad18[0x6C - 0x18];
    f32 field6C;
    char pad70[0x5E0 - 0x70];
    Block70 block;
    char pad650[0x16E8 - 0x650];
};

struct ActorList;
struct ActorRecAt5E0;

struct Snapshot;
struct Snapshot {
    s32 active;
    s32 mode;
    s32 countdown;
    s32 savedActorId;
    Block70 blocks[8];
    Triple positions[8];
    f32 values[8];
    s32 handles[8];
};

struct SampledCurve;
struct SampledCurve {
    int type;
    unsigned char samples[0x10];
    float length;
};

struct SampledCurve;

struct PlayerRecAt8;
struct PlayerRecAt8 {
    struct SampledCurve *curve;
    float time;
    float value;
};

extern void Control_DeactivateActorSnapshot();


struct PlayerRecAt8;
typedef struct PlayerRecAt8 PlayerRecAt8;

struct Snapshot;
typedef struct Snapshot Snapshot;
extern Snapshot D_8010BC40;

struct Snapshot;

extern void Control_SaveActorSnapshot();

struct Snapshot;

extern s32 Control_FindConnectedControllerPort(s32 arg0);


extern void Control_RestoreActorSnapshot();


extern void Control_TickSnapshotCountdown();

struct ActorRecAt5E0;
typedef struct ActorRecAt5E0 ActorRecAt5E0;

extern void func_802649FC_de();

extern void Control_EnableAllControllerPaks();


extern void Control_CycleActorSnapshotMode(void);

struct ActorList;
typedef struct ActorList ActorList;

extern void Control_ResetControllerProfiles();

extern void Control_ResetActorSnapshot();


extern void Control_RestoreControllerSetup();


extern s32 Control_AdvanceEffectCurve(void *arg0);

struct SampledCurve;
typedef struct SampledCurve SampledCurve;

extern void func_80264A0C_de();
#endif
