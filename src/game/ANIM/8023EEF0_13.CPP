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
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
s32 func_80272018_de(f32 *, void *, f32 *);

/* Warning: Gap in callee-saved word stack region.
 * Saved: [0x40, 0x44, 0x48, 0x4c, 0x50, 0x54, 0x58, 0x5c, 0x68, 0x6c, 0x78, 0x7c, 0x80, 0x84], gap at: 0x60. */
s32 func_802406D0_de(void *arg0, void *arg1, f32 arg2) {
    s32 sp14;
    s32 sp18;
    s32 sp24;
    s32 sp28;
    s32 sp34;
    s32 sp38;
    f32 sp10;
    f32 sp20;
    f32 sp30;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f23;
    f32 temp_f24;
    s32 temp_v1;
    s32 var_s2;
    s32 var_s2_2;
    s32 var_v0;
    void *var_s0;
    void *var_s4;

    var_v0 = 1;
    temp_v1 = M2C_FIELD(arg0, s32 *, 0x14);
    if (temp_v1 != 1) {
        var_s0 = arg0 + ((temp_v1 * 0xC) + 0xC);
        var_s4 = arg0 + 0x18;
        temp_f24 = arg2 * arg2;
        if ((u32) (M2C_FIELD(arg0, s32 *, 0) - 3) < 2U) {
            var_s2 = temp_v1 - 1;
            if (var_s2 != -1) {
loop_4:
                func_80271F68_de(&sp20, var_s4, var_s0);
                func_80272018_de(&sp10, arg0 + 0x48, &sp20);
                func_80271F68_de(&sp30, arg1, var_s0);
                if (((sp10 * sp30) + (sp14 * sp34) + (sp18 * sp38)) > 0.0f) {
                    var_v0 = 0;
                    if (arg2 > 0.0f) {
                        temp_f20 = (sp20 * sp30) + (sp24 * sp34) + (sp28 * sp38);
                        if (temp_f20 > 0.0f) {
                            temp_f12 = (sp20 * sp20) + (sp24 * sp24) + (sp28 * sp28);
                            if (!(temp_f12 <= temp_f20)) {
                                func_80271F9C_de(&sp20, &sp20, temp_f20 / temp_f12);
                            }
                            func_80271F68_de(&sp30, &sp30, &sp20);
                        }
                        var_v0 = 0;
                        if (!(temp_f24 < ((sp30 * sp30) + (sp34 * sp34) + (sp38 * sp38)))) {
                            goto block_11;
                        }
                        /* Duplicate return node #25. Try simplifying control flow for better match */
                        return var_v0;
                    }
                    /* Duplicate return node #25. Try simplifying control flow for better match */
                    return var_v0;
                }
block_11:
                var_s0 = var_s4;
                var_s2 -= 1;
                var_s4 += 0xC;
                if (var_s2 == -1) {
                    return 1;
                }
                goto loop_4;
            }
            goto block_24;
        }
        var_s2_2 = temp_v1 - 1;
        if (var_s2_2 != -1) {
            temp_f23 = D_800C8820;
loop_15:
            func_80271F68_de(&sp20, var_s4, var_s0);
            func_80272018_de(&sp10, arg0 + 0x48, &sp20);
            func_80271F68_de(&sp30, arg1, var_s0);
            if (((sp10 * sp30) + (sp14 * sp34) + (sp18 * sp38)) > 0.0f) {
                var_v0 = 0;
                if (arg2 > 0.0f) {
                    temp_f12_2 = (sp20 * sp20) + (sp24 * sp24) + (sp28 * sp28);
                    temp_f20_2 = ((sp20 * sp30) + (sp24 * sp34) + (sp28 * sp38)) / temp_f12_2;
                    if (temp_f20_2 < 0.0f) {
                        if (temp_f20_2 < (-arg2 / func_802B72B0_de(temp_f12_2))) {
                            goto block_19;
                        }
                        goto block_22;
                    }
                    if (!(temp_f23 < temp_f20_2) || !(((arg2 / func_802B72B0_de(temp_f12_2)) + temp_f23) < temp_f20_2)) {
block_22:
                        func_80271F9C_de(&sp20, &sp20, temp_f20_2);
                        func_80271F68_de(&sp30, &sp30, &sp20);
                        var_v0 = 0;
                        if (!(temp_f24 < ((sp30 * sp30) + (sp34 * sp34) + (sp38 * sp38)))) {
                            goto block_23;
                        }
                        /* Duplicate return node #25. Try simplifying control flow for better match */
                        return var_v0;
                    }
block_19:
                    return 0;
                }
                /* Duplicate return node #25. Try simplifying control flow for better match */
                return var_v0;
            }
block_23:
            var_s0 = var_s4;
            var_s2_2 -= 1;
            var_s4 += 0xC;
            if (var_s2_2 == -1) {
                goto block_24;
            }
            goto loop_15;
        }
block_24:
        var_v0 = 1;
        /* Duplicate return node #25. Try simplifying control flow for better match */
        return var_v0;
    }
    return var_v0;
}
#else
INCLUDE_ASM("span_1000", func_802406D0_de);
#endif
