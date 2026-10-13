#ifndef RW_BOX_CONTACT_H
#define RW_BOX_CONTACT_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
struct Object_func_8044A07C_de;
typedef struct BoxContactActor {
    u8 reserved0[0x18];
    s32 *kind;
    u8 reserved1C[0x1BC];
    struct Object_func_8044A07C_de *widget;
} BoxContactActor;
typedef struct ContactProjectile {
    u8 type;
    u8 reserved1[3];
    u16 kind;
    u8 reserved6[2];
    Vec3 position;
    u8 reserved14[8];
    Vec3 color;
    u8 reserved28[0x104];
    BoxContactActor *owner;
    u8 reserved130[4];
    s32 ticks;
    u8 reserved138[4];
    BoxContactActor *lastHit;
    u8 reserved140[12];
    u16 contactState;
} ContactProjectile;
typedef struct BoxContactMaterial {
    u8 reserved0[4];
    s8 kind, alternateKind;
    u8 reserved6[10];
    f32 response;
} BoxContactMaterial;
typedef struct BoxContactTransform { u32 words[28]; } BoxContactTransform;
typedef struct BoxContactPolygon {
    s32 type;
    f32 response;
    s32 kind;
    s32 count;
    s32 flags;
    s32 valid;
    Vec3 point;
    u8 reserved24[0x24];
    Vec3 normal;
    BoxContactActor *actor;
    s32 index;
    BoxContactTransform transform;
    f32 t;
    Vec3 hit;
} BoxContactPolygon;
typedef struct BoxContactRay {
    ContactProjectile *projectile;
    u8 reserved4[0x3C];
    BoxContactMaterial *material;
    Vec3 start, end, direction;
    u8 reserved68[0x18];
    f32 slack;
    u8 reserved84[0x2C];
    BoxContactPolygon nearest;
} BoxContactRay;
typedef struct ContactEffectStyle {
    s16 kind, flags;
    s8 mode, red, green, blue;
} __attribute__((aligned(4))) ContactEffectStyle;
#endif
