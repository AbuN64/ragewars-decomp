#ifndef COMMON_ANIMATIONTRIGGERDEFINITION_H
#define COMMON_ANIMATIONTRIGGERDEFINITION_H
struct Shared_Actor;
struct SharedPlayer;
#ifndef SPAN_1000_CODE_80204E78_H
#define SPAN_1000_CODE_80204E78_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/VECTOR4F.H"
/* Animation-trigger definitions have delay bounds and signed animation IDs;
 * movement definitions instead carry event masks at these offsets. */
typedef struct AnimationTriggerDefinition {
    s32 flags;
    s32 enabled;
    s16 reserved8;
    s16 animation;
    f32 delayMinimum;
    f32 delayMaximum;
    s16 firstAnimation;
    s16 secondAnimation;
} AnimationTriggerDefinition;
typedef struct AnimationTriggerResource {
    s32 kind;
    u8 reserved4[0x10];
    AnimationTriggerDefinition trigger;
} AnimationTriggerResource;


extern unsigned int func_80205700_de(void *object);

extern void func_80206080_de(void *arg0, void *arg1);


struct ActionInfo;
struct ActionInfo {
    s32 flags;
    char pad4[4];
    s16 duration;
};

struct ActorRecAt134;
typedef struct ActorRecAt134 ActorRecAt134;

struct Damage;
typedef struct Damage Damage;

struct Cell;
typedef struct Cell Cell;



struct Damage;
struct Damage {
    s32 flags;
    u8 pad4[0x44];
    u8 model[4];
    u8 time[4];
    u8 threshold[4];
};

struct Health;
struct Health {
    u8 pad0[4];
    s32 health;
    s32 maxHealth;
    u8 padC[0x118];
    s32 model;
    s32 time;
};

struct Trigger;
extern void func_802056D0_de(struct Trigger *arg0);

extern void func_80204F78_de(void *unused, char *object, float value);

struct CallbackHolder;
typedef struct CallbackHolder CallbackHolder;

extern int func_802052F8_de(void *arg0);

struct Access_s32_40;
typedef struct Access_s32_40 Access_s32_40;

struct Hit;
struct Hit {
    u8 pad0[4];
    s32 damage;
    u8 pad8[4];
    u32 flags;
};

struct ActorRecAt134;
struct ActorRecAt134 {
    char pad0[0xE6];
    signed char always;
    char padE7[0x100 - 0xE7];
    int flags;
    float range;
    short x;
    short y;
    short level;
    char pad10E[0x12C - 0x10E];
    short altLevel;
    char pad12E[0x134 - 0x12E];
    float altRange;
};


struct Damageable;
typedef struct Damageable Damageable;

struct EventRecAt30;
typedef struct EventRecAt30 EventRecAt30;

struct BreakableHitContext;
struct ObjectStateCC;
extern void func_80205494_de(struct BreakableHitContext *arg0, struct ObjectStateCC *arg1);





extern float D_800C1ACC_de;

extern void func_80205628_de(void *arg0, void *arg1, void *arg2);

extern void func_80205EC4_de(void *arg0, void *arg1);

extern float D_800C1AD0_de;

struct Health;
typedef struct Health Health;




struct Action;
typedef struct Action Action;



struct Action;
struct Action {
    char pad0[0x64];
    f32 delay;
    char pad68[0x124 - 0x68];
    s32 timer;
    s32 duration;
};

struct ActionInfo;
typedef struct ActionInfo ActionInfo;

struct CallbackHolder;
struct EventRecAt30;
struct CallbackHolder {
    char pad0[8];
    void (*callback)(void *arg0, EventRecAt30 *arg1);
};

struct EventRecAt30 {
    char pad0[0x30];
    struct CallbackHolder *holder;
};


struct Descriptor;
struct Descriptor {
    u8 pad0[0x14];
    Damage damage;
};
struct Damageable;
struct Descriptor;
struct Damageable {
    u8 pad0;
    u8 stage;
    u8 pad2[0x16];
    struct Descriptor *desc;
};

extern void func_802055EC_de(void *arg0, void *arg1);

struct Cell;
struct Cell {
    char pad0[0xCA];
    unsigned char pos;
    signed char open;
};

struct Access_s32_40;
struct Access_s32_40 {
    unsigned char padding_0[64];
    int field;
};

extern int func_8020570C_de(struct Hit *arg0);

struct Hit;
typedef struct Hit Hit;

extern int func_802054D0_de(void *object);



struct Actor_func_80205F18_de;
typedef struct Actor_func_80205F18_de Actor_func_80205F18_de;

struct LevelActor;
extern void func_8020520C_de(struct LevelActor *source, void *dest);

extern int func_80205314_de(void *arg0);

struct DescriptorCode80204E78;
struct DescriptorCode80204E78 {
    char pad0[0x14];
    ActionInfo info;
};
struct Actor_func_80205F18_de;
struct DescriptorCode80204E78;
struct Actor_func_80205F18_de {
    char pad0[0x18];
    struct DescriptorCode80204E78 *desc;
    char pad1C[0xE4 - 0x1C];
    u16 model;
    char padE6[0x100 - 0xE6];
    s32 flags;
};


typedef struct {
    s16 hi;
    s16 id;
} Half5324;
typedef union {
    s32 whole;
    Half5324 half;
} Word5324;
typedef struct {
    char pad0[0x10];
    s32 sound; /* full descriptor +0x24 */
    char pad14[4];
    s32 unk18;
    s32 unk1C;
    Word5324 unk20;
    s32 unk24;
    s32 unk28;
} Rec5324;
typedef struct {
    char pad0[0x14];
    Rec5324 r;
} Hold5324;
typedef union {
    CVector3 v;
    Triple t;
} Pos5324;
typedef struct {
    char pad0[0x8];
    Pos5324 pos;
    char pad14[0x4];
    Hold5324 *holder;
    char pad1C[0xE4];
    s32 flags;
} Obj5324;
struct Shared_World;
extern void Rumble_SetActorStateBit(struct Shared_World *, void *, s32);
extern void func_80278D78_de(struct Shared_Actor *arg0, s32 arg1, void *arg2);
extern void Weapons_SpawnActorEffect(void *, s32, Triple, s32);
extern s32 SoundElement_PlaySoundAtPosition(s16, CVector3, s32, s32);
struct Player;
extern void Weapons_SpawnFlaggedEffects(struct Player *, s32 *, s32, s32, s32);
struct SceneRecAt95A8;
extern void func_802A5D38_de(struct SceneRecAt95A8 *, s32);

typedef struct {
    s16 hi;
    s16 id;
} Half54E0;
typedef union {
    s32 whole;
    Half54E0 half;
} Word54E0;
typedef struct {
    char pad0[0x2C];
    s32 unk2C;
    s32 unk30;
    Word54E0 unk34;
    s32 unk38;
    s32 unk3C;
} Rec54E0;
typedef struct {
    char pad0[0x14];
    Rec54E0 r;
} Hold54E0;
typedef union {
    CVector3 v;
    Triple t;
} Pos54E0;
typedef struct {
    char pad0[0x8];
    Pos54E0 pos;
    char pad14[0x4];
    Hold54E0 *holder;
    char pad1C[0xE4];
    s32 flags;
} Obj54E0;

typedef struct { s16 id, weight; } SpawnChoice;
typedef struct { u32 flags; s32 kind; u8 unused8[0xC]; s16 id, selector; CVector3 velocity; s16 count; } SpawnDefinition;
typedef struct { u8 unused0[0x14]; SpawnDefinition spawn; } SpawnDispatchDefinition;
typedef struct SpawnDispatchActor {
    u8 unused0[8]; Triple position; void *world; s32 *definition;
    u8 unused1C[0x184]; s32 state; u8 unused1A4[0x148];
    struct SpawnDispatchActor *next;
} SpawnDispatchActor;
typedef struct {
    u8 unused0[8]; CVector3 position; void *world; SpawnDispatchDefinition *definition;
    CVector3 rotation; u8 unused28[0x34]; CQuatern motion; f32 scale;
} SpawnDispatchObject;
typedef struct {
    u8 unused0[0x2C];
    void *callbacks;
    u8 unused30[0x108 - 0x30];
    void *update;
    void *draw;
    void *hit;
    u8 unused114[0x10];
    s32 spawn, remaining;
} SpawnDispatchOwner;
typedef struct { u8 unused0[0x1D]; u8 enabled; } SpawnDispatchConfig;
extern s32 func_80222D64_de(void *arg0, s32 arg1);
extern int func_8022ADB0_de(struct SharedPlayer *object, s32 arg1);

#endif
#endif
