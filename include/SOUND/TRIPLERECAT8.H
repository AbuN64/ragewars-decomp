#ifndef SOUND_TRIPLERECAT8_H
#define SOUND_TRIPLERECAT8_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

struct ActorSurfaceSampleVector;
typedef struct ActorSurfaceSampleVector ActorSurfaceSampleVector;

struct ActorSurfaceHeightView;
typedef struct ActorSurfaceHeightView ActorSurfaceHeightView;

struct InstanceItemValueView;
struct InstanceItemValueView {
    unsigned char kind;
    char pad[0x33];
    void *value;
    unsigned flags;
};

extern int InstHdr_GetTypeOneItemValue(void *actorStorage);


struct ActorSurfaceHeightView;
struct ActorSurfaceHeightView {
    unsigned char padding_0[12];
    f32 unk_C;
    unsigned char padding_10[4];
    void *unk_14;
};


struct LevelActor;
extern int InstHdr_IsDefinitionKindOne(struct LevelActor *actor);

struct ActorSurfaceSampleVector;
struct ActorSurfaceSampleVector {
    f32 a;
    s32 b;
    f32 c;
};

struct ActorSurfaceKeyView;
struct StateFlags;
struct ActorSurfaceKeyView {
    char pad[0x14];
    struct StateFlags *key;
};

extern s32 InstHdr_IsActorControllerActive(char *actor);

extern float g_defaultActorShadowRadius;
#endif
