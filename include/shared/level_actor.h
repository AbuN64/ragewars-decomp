#ifndef RW_LEVEL_ACTOR_H
#define RW_LEVEL_ACTOR_H
#include "common/types_06e4f7ef1f9e.h"
#include "shared/particle_lighting.h"
typedef struct Actor_func_8024A7A0_de Actor_func_8024A7A0_de;
struct Actor_func_8024A7A0_de {
    u8 kind;
    s8 team;
    char pad2;
    s8 field3;
    s16 modelIndex;
    u16 pad6;
    Vec3 position0;
    s32 model; /* 0x14 */
    s32 *definition; /* 0x18 */
    Vec3 position1;
    u8 pad28[0x10];
    s32 motionState; /* 0x38 */
    u8 pad3C[4];
    f32 floorHeight; /* 0x40 */
    Vec3 floorDirection; /* 0x44 */
    Vec3 scale; /* 0x50 */
    Vector4f rotation;
    f32 yaw; /* 0x6C */
    f32 eyeHeight; /* 0x70 */
    f32 transform[16]; /* 0x74 */
    s32 fieldB4;
    s32 fieldB8;
    void *shadow; /* 0xBC */
    u8 padC0[4];
    s32 resource; /* 0xC4 */
    s32 resourceKey; /* 0xC8 */
    s32 animationKey; /* 0xCC */
    s32 resourceFlags; /* 0xD0 */
    s32 resourceAlignment; /* 0xD4 */
    s32 resourceHandle; /* 0xD8 */
    s32 resourceState; /* 0xDC */
    s32 resourceWindow; /* 0xE0 */
    u16 type; /* 0xE4 */
    u8 stateE6;
    u8 stateE7;
    u8 padE8[0x100 - 0xE8];
    s32 flags; /* 0x100 */
    f32 animationTime; /* 0x104 */
    s16 animation; /* 0x108 */
    s16 nextAnimation; /* 0x10A */
    u8 pad10C[2];
    s8 animationPending; /* 0x10E */
    s8 animationChanged; /* 0x10F */
    u8 pad110[0x138 - 0x110];
    u8 state138;
    u8 state139;
    u8 shadowAlpha; /* 0x13A */
    u8 state13B;
    u8 pad13C[4];
    Shared_ParticleLighting lighting[2]; /* 0x140 */
    s32 behaviorFlags; /* 0x170 */
    s32 active; /* 0x174 */
    u8 pad178[4];
    s32 mask;
    u8 pad180[0x20];
    s32 collisionEnabled; /* 0x1A0 */
    u8 pad1A4;
    s8 animationState; /* 0x1A5 */
    u8 pad1A6[0x32];
    void *controller; /* 0x1D8: linked actor */
    u8 pad1DC[0x14];
    char *lockOn; /* 0x1F0 */
    u8 pad1F4[0x23A - 0x1F4];
    s8 lean; /* 0x23A */
    u8 updateCount; /* 0x23B */
    u8 pad23C[0x34];
    u8 effectMode; /* 0x270 */
    u8 pad271[0xB];
    void *update; /* 0x27C */
    u8 pad280[0xC];
    void (*controllerUpdate)(void *, void *); /* 0x28C */
    u8 pad290[4];
    f32 pitch; /* 0x294 */
    u8 pad298[0xC];
    f32 restPitch; /* 0x2A4 */
    u8 pad2A8[0x38];
    s32 renderFlags; /* 0x2E0 */
    s32 flags2E4;
};
#endif
