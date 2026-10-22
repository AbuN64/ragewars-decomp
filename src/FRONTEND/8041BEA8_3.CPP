#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Enables mode 1 through func_802A23C4_de, places the menu model at (17, -10, -50) with uniform scale 0.14, zero rotation and a (0, 5, 0) offset, then issues request 0xE78 through func_8025DF34_de; returns zero. */





/* The hub spells D_800E3590 as the padded menu block; this unit reaches the model name at +0x08
 * through its own view, so each use casts back to it. */
extern void func_80439B5C_de(char *model, s32 arg1, CVector3 scale, CVector3 position);
extern void func_80439BE0_de(char *model, CVector3 rotation);
extern void func_80439C30_de(char *model, CVector3 offset);

s32 func_8041DBCC_de(void) {
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 offset;

    func_802A23C4_de(1);
    scale.x = 0.14f;
    scale.y = 0.14f;
    scale.z = 0.14f;
    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;
    offset.x = 0.0f;
    offset.y = 5.0f;
    offset.z = 0.0f;
    position.x = 17.0f;
    position.y = -10.0f;
    position.z = -50.0f;
    func_80439B5C_de(((MenuRecAt8 *) D_800E3590)->model, 0, scale, position);
    func_80439BE0_de(((MenuRecAt8 *) D_800E3590)->model, rotation);
    func_80439C30_de(((MenuRecAt8 *) D_800E3590)->model, offset);
    func_8025DF34_de(0xE78);
    return 0;
}

#ifdef NON_MATCHING
/* The names m2c output assumes (its valid-syntax macros), so a draft compiles on its own. */
#ifndef NULL
#define NULL ((void *)0)
#endif
typedef int M2C_UNK;
typedef signed char M2C_UNK8;
typedef short M2C_UNK16;
typedef int M2C_UNK32;
typedef long long M2C_UNK64;
#define M2C_FIELD(base, type, offset) (*(type)((char *)(base) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK(...) (0)
#define M2C_SYNC(...) (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)
#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#include "COMMON/GFX.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "gbi.h"
s32 func_804399D0(void *);
s32 func_80439CC8_de(void *, Gfx **, Gfx *);
extern s32 D_800D15E0;
extern s32 D_800D15E4;
extern f32 D_800DD524_de;
extern f32 D_800DD52C_de;

s32 func_8041DCC0_de(s32 arg2) {
    Gfx *temp_a2;
    f32 temp_f20;

    if ((arg2 == 1) && (D_800E3590->unk216 == 3)) {
        temp_f20 = D_800DD524_de;
        D_800D15E0 = 0;
        temp_a2 = D_80110634;
        M2C_FIELD(&D_800D15E4, f32 *, 0) = temp_f20;
        M2C_FIELD(&D_800D15E4, f32 *, 4) = temp_f20;
        M2C_FIELD(&D_800D15E4, f32 *, 8) = temp_f20;
        M2C_FIELD(&D_800D15E4, f32 *, 0xC) = temp_f20;
        D_80110634 += 8;
        gDPSetScissorFrac(temp_a2, 0, 0, 0, (s32) ((f32) (D_800E28D0 - 1) * D_800DD528_de), (s32) ((f32) (D_800E28D4 - 1) * D_800DD528_de));
        
        if (func_80439CC8_de(&D_800E3590->record, &D_80110634, temp_a2) != 0) {
            D_800D15E0 = arg2;
            M2C_FIELD(&D_800D15E4, f32 *, 0xC) = (f32) D_800DD52C_de;
            func_804399D0(&D_800E3590->record);
            D_800D15E0 = 0;
            M2C_FIELD(&D_800D15E4, f32 *, 0xC) = temp_f20;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8041DCC0_de);
#endif
