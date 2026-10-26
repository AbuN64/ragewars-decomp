#ifndef WEAPONS_AIM_TYPES_H
#define WEAPONS_AIM_TYPES_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/VECTOR4F.H"

typedef union AimOutput { CVector3 xyz; CQuatern full; Shared_Quad words; } AimOutput;

typedef struct AimActor {
    u8 kind; char pad1[7]; CVector3 pos; char pad14[0x5c];
    f32 height; char pad74[0x8c]; s32 flags; char pad104[0x144]; CVector3 focus;
} AimActor;

typedef struct AimController { char pad0[0x7e]; u8 active; } AimController;

typedef struct AimView {
    char pad0[0x24]; s32 mode; char pad28[0x100]; CVector3 origin;
    char pad134[0x2c]; f32 matrix[16];
} AimView;

typedef struct AimWeapon { char pad0[14]; s16 idle; s16 locked; } AimWeapon;

typedef struct AimHit { AimActor *actor; char pad4[0xe0]; CVector3 point; CVector3 normal; } AimHit;

#endif
