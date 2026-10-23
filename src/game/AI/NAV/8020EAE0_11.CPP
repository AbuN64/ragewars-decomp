#include "include_asm.h"

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
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"
#include "stddef.h"
s32 func_80209874_de(void *, s32);
s32 func_80209A94_de(void *);
s32 func_80209AD8_de(void *);
f32 func_80209B64_de(void *);
s32 func_8020EA10_de(void *);
s32 func_8020F5A4_de(void *);
s32 func_8022AAD4_de(void *, s16);
s32 func_8022AB20_de(void *, s16);
s32 func_8022AC00_de(void *);
s32 func_8022ACB8_de(void *, s32, s32);
extern s32 D_801468A0;

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x10, 0x14, 0x18, 0x1c, 0x20, 0x24, 0x30, 0x34], gap at: 0x28. */
s32 func_8020FA10_de(void *brain) {
    s32 var_a1;
    f32 temp_f20;
    f32 temp_f21;
    f32 var_f20;
    s16 temp_s2;
    s16 temp_s3;
    s16 temp_s4;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    void *temp_a0;
    void *temp_a0_2;
    void *temp_a0_3;
    void *temp_v0_2;
    void *temp_v0_3;
    void *temp_v1_3;

    temp_a0 = M2C_FIELD(brain, void **, 0);
    temp_s0 = (s32) M2C_FIELD(temp_a0, s32 *, 0x5E4) >> 8;
    temp_a0_2 = M2C_FIELD(brain, void **, 0);
    temp_f20 = 100.0f;
    temp_f21 = ((f32) temp_s0 / (f32) (func_8022AC00_de(temp_a0) >> 8)) * temp_f20;
    temp_a0_3 = M2C_FIELD(brain, void **, 0);
    temp_s0_2 = func_8022AB20_de(temp_a0_2, M2C_FIELD(temp_a0_2, s16 *, 0x62E));
    temp_v0 = func_8022ACB8_de(M2C_FIELD(brain, void **, 0), func_8022AAD4_de(temp_a0_3, M2C_FIELD(temp_a0_3, s16 *, 0x62E)), 1);
    if ((temp_v0 != 0) && (temp_s0_2 != -1)) {
        var_f20 = ((f32) temp_s0_2 / (f32) temp_v0) * temp_f20;
    } else {
        var_f20 = 100.0f;
    }
    temp_v0_2 = M2C_FIELD(brain, void **, 0);
    temp_s2 = M2C_FIELD(temp_v0_2, s16 *, 0x5F4);
    temp_s3 = M2C_FIELD(temp_v0_2, s16 *, 0x5F6);
    temp_s4 = M2C_FIELD(temp_v0_2, s16 *, 0x5F8);
    temp_v0_3 = func_8022A83C_de(&D_80145040);
    if ((temp_v0_3 != NULL) && (D_80145040.game.counters.m_bCTFOn != 0)) {
        if (temp_v0_3 == M2C_FIELD(brain, void **, 0)) {
            var_a1 = 0xA;
            goto block_48;
        }
        var_a1 = 1;
        if (M2C_FIELD(brain, s32 *, 0x64) == 0) {
            goto block_9;
        }
        goto block_48;
    }
block_9:
    if ((M2C_FIELD(&D_801468A0, s32 *, 0x54) != 0) && (M2C_FIELD(M2C_FIELD(M2C_FIELD(brain, void **, 0), void **, 0x5D8), u8 *, 0x8F) != 0)) {
        if (M2C_FIELD(&D_801468A0, s32 *, 0x68) > 0) {
            if (M2C_FIELD(brain, s32 *, 0x21C) != 2) {
                func_80209874_de(brain, 2);
                M2C_FIELD(brain, s32 *, 0x2F4) = 1;
                M2C_FIELD(brain, s32 *, 0x2F8) = 1;
                return 1;
            }
            goto block_49;
        }
        var_a1 = 0xB;
        goto block_48;
    }
    var_s0 = (s32) ((1.0f - func_80209B64_de(brain)) * 80.0f);
    if ((D_80146938 != 0) && (M2C_FIELD(M2C_FIELD(M2C_FIELD(brain, void **, 0), void **, 0x5D8), u8 *, 0x94) != 0)) {
        var_s0 = 0;
    }
    if (func_80209AD8_de(brain) == 0) {
        var_v0 = 1;
        if (temp_f21 < (f32) var_s0) {
            goto block_20;
        }
    }
    if ((func_80209AD8_de(brain) == 0) && (var_f20 < 10.0f)) {
        M2C_FIELD(brain, s32 *, 0xBC) = func_8020F5A4_de(brain);
        goto block_21;
    }
    temp_v1 = M2C_FIELD(brain, s32 *, 0x21C);
    var_v0_2 = temp_s2 < 0xA;
    if ((((u32) (temp_v1 - 3) >= 2U) && (var_v0_2 = temp_s2 < 0xA, (temp_v1 != 0xD))) || (var_v0_2 == 0) || (temp_s3 >= 0xA) || (var_v0 = 4, (temp_s4 > 0))) {
        if ((func_80209A94_de(brain) != 0) && (M2C_FIELD(brain, s32 *, 0x64) == 0)) {
            goto block_32;
        }
        if ((func_8020EA10_de(brain) != 0) && (temp_v1_2 = M2C_FIELD(brain, s32 *, 0x21C), (temp_v1_2 != 9))) {
            if ((u32) (temp_v1_2 - 1) < 2U) {
                var_a1 = 9;
                goto block_48;
            }
        } else if ((func_80209AD8_de(brain) == 0) || !((f32) var_s0 < temp_f21) || !(10.0f < var_f20)) {
            if ((func_80209A94_de(brain) == 0) && (func_80209AD8_de(brain) == 0) && (M2C_FIELD(brain, s32 *, 0x64) != 0)) {
                temp_v1_3 = M2C_FIELD(M2C_FIELD(brain, void **, 0), void **, 0x5D8);
                if (M2C_FIELD(temp_v1_3, u8 *, 0x94) != 0) {
                    if (M2C_FIELD(temp_v1_3, s8 *, 0x80) == 0xC) {
                        var_a1 = 0xD;
                    } else {
                        goto block_47;
                    }
                } else {
block_47:
                    var_a1 = 1;
                }
                goto block_48;
            }
        } else {
block_32:
            var_a1 = 2;
            goto block_48;
        }
    } else {
block_20:
        M2C_FIELD(brain, s32 *, 0xBC) = var_v0;
block_21:
        var_a1 = 8;
block_48:
        func_80209874_de(brain, var_a1);
block_49:
    }
    return 1;
}
#else
INCLUDE_ASM("span_1000", func_8020FA10_de);
#endif
