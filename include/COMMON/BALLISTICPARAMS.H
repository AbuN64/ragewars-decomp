#ifndef COMMON_BALLISTICPARAMS_H
#define COMMON_BALLISTICPARAMS_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/APPROACHLOCATION.H"

/* Complete records from origin/legacy shared headers and source; historical gaps retained. */
typedef struct Shared_func_8027ADBC_S2 Shared_func_8027ADBC_S2;
struct Shared_func_8027ADBC_S2 {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/func_8027ADBC.c */
    char pad14[0x5C];
    f32 unk70; /* +0x70: src/func_8027ADBC.c */
    char pad74[0x166C];
    void * unk16E0; /* +0x16E0: src/func_8027ADBC.c */
};

typedef struct Shared_func_8027ADBC_S3 Shared_func_8027ADBC_S3;
struct Shared_func_8027ADBC_S3 {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/func_8027ADBC.c */
};

typedef struct Shared_func_8027ADBC_S6 Shared_func_8027ADBC_S6;
struct Shared_func_8027ADBC_S6 {
    char pad0[0x8];
    CVector3 pos; /* +0x8: src/func_8027ADBC.c */
};

typedef struct BallisticParams BallisticParams;
struct BallisticParams { u16 gravityHi; u16 gravityLo; u16 speedHi; u16 speedLo; char pad8[8]; u16 unk10; u16 unk12; };

typedef struct BallisticParamsHolder BallisticParamsHolder;
struct BallisticParamsHolder { u32 flags; char pad4[0xA]; s16 unkE; char pad10[0x20]; BallisticParams *unk30; char pad34[8]; };

/* Phase-1 candidate; target/descriptor layouts and helper ABI remain unresolved. */
typedef struct Shared_func_8027ADBC_S2 SharedRecAt16E0V2;
typedef struct Shared_func_8027ADBC_S3 func_8027ADBC_S3;
typedef struct Shared_func_8027ADBC_S6 func_8027ADBC_S6;
extern f32 D_800C4BCC_de;








extern f32 D_800C4BE0_de;











void func_80228DC4_de(void *, void *);
f32 Particle_GetActorHeight(void *);
f32 func_8024E420_de(void *);
void func_80270CD0_de(void *, f32, void *, void *);
void func_80272748_de(void *, f32);
void func_80274244_de(f32 *, f32 *);


void func_80279DD0_de(void *, f32);
f32 func_802B72B0_de(f32);
void func_80271818_de(void *, f32 *);            /* extern */
extern Shared_MenuData D_80145040;
extern Shared_GlobalRuntimeState D_80145060;
#endif
