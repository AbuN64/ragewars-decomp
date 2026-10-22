#include "COMMON/WORLD.H"
#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
extern void *D_800D052C[];
#include "WEAPONS/80213ED4.H"
#include "COMMON/CHANNEL.H"

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
extern s32 D_800CD730;




void func_8022FDAC_de(void *arg0, void *arg1) {
    s16 index;
    u16 unsigned_index;
    void *owner;
    void *state;

    state = ((Shared_ActorView *)arg0)->self;
    index = ((Shared_ActorView *)state)->nextWeapon;
    unsigned_index = (u16)((Shared_ActorView *)state)->nextWeapon;
    if ((((Shared_ActorView *)state)->selectedAction != index) || (D_8011FE88.mode != 4)) {
        if (func_80232780_de(index) != 0) {
            ((Shared_ActorView *)state)->weaponChanged = 1;
        } else if (func_802327A0_de(index) != 0) {
            ((Shared_ActorView *)state)->secondaryChanged = 1;
        } else if (func_802327D4_de(index) != 0) {
            ((Shared_ActorView *)state)->specialChanged = 1;
        }
        ((Shared_ActorView *)state)->selectedAction = unsigned_index;
        ((WeaponFireState *)arg1)->animation = ((WeaponInfo *)D_800D052C[(s16)unsigned_index])->animation;
        ((WeaponFireState *)arg1)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)state)->selectedAction]))->animationCount;
        owner = ((Shared_ActorView *)state)->message;
        if ((owner != 0) && ((u32)D_800CD730 >= 5U)) {
            func_80237E80_de(&D_80145088, owner,
                *(void **)*(void **)D_800D052C[((Shared_ActorView *)state)->selectedAction]);
        }
        ((WeaponFireState *)arg1)->spinStep = 0;
        ((WeaponFireState *)arg1)->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        ((WeaponFireState *)arg1)->charge = 0;
    }
    func_80214178_de(arg0, arg1, 0);
}

void func_8022FF04_de(void *arg0, WeaponFireState *arg1) {
    s16 temp_s0;
    u16 temp_s2;
    void *temp_a1;
    char *temp_s1;

    temp_s1 = ((Shared_ActorView *)arg0)->self;
    temp_s0 = ((Shared_ActorView *)temp_s1)->nextWeapon;
    temp_s2 = (u16)((Shared_ActorView *)temp_s1)->nextWeapon;
    if ((((Shared_ActorView *)temp_s1)->selectedAction != temp_s0) || (D_8011FE88.mode != 4)) {
        if (func_80232780_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->weaponChanged = 1;
        } else if (func_802327A0_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->secondaryChanged = 1;
        } else if (func_802327D4_de(temp_s0) != 0) {
            ((Shared_ActorView *)temp_s1)->specialChanged = 1;
        }
        ((Shared_ActorView *)temp_s1)->selectedAction = temp_s2;
        arg1->animation = ((WeaponInfo *)(D_800D052C[(s16)temp_s2]))->animation;
        arg1->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]))->animationCount;
        temp_a1 = ((Shared_ActorView *)temp_s1)->message;
        if ((temp_a1 != 0) && ((u32)D_800CD730 >= 5U)) {
            func_80237E80_de(&D_80145088, temp_a1,
                          **(void ***)D_800D052C[((Shared_ActorView *)temp_s1)->selectedAction]);
        }
        arg1->spinStep = 0;
        arg1->spin = 0;
        ((Shared_Actor *)arg0)->color = 0;
        arg1->charge = 0;
    }
    arg1->mode = 1;
    arg1->rounds = 1;
}
#endif

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
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "TYPES.H"
s32 func_80283228_de(s32 *, void *);
extern s32 D_8011D8D0;

s32 func_80230058_de(void *arg0, void *arg1) {
    s16 temp_v0;
    s32 var_v0;
    void *temp_s0;

    temp_s0 = M2C_FIELD(arg0, void **, 0x1D8);
    var_v0 = 0;
    if (!(M2C_FIELD(arg1, f32 *, 0x130) > 0.0f) && (var_v0 = 0, (Weapons_HasAmmoForMode(temp_s0, (s32) M2C_FIELD(temp_s0, s16 *, 0x62E)) != 0)) && ((M2C_FIELD(M2C_FIELD(temp_s0, void **, 0x5D8), u8 *, 0x8F) != 1) || (var_v0 = 0, (D_801468F4 == 0))) && (var_v0 = 0, !(M2C_FIELD(temp_s0, f32 *, 0x11D8) > 0.0f)) && (var_v0 = 0, (M2C_FIELD(temp_s0, s32 *, 0x11B4) == 0))) {
        temp_v0 = (u16) M2C_FIELD(temp_s0, s16 *, 0x62E) - 1;
        switch (temp_v0) {
        case 10:
            var_v0 = 1;
            if (M2C_FIELD(temp_s0, s32 *, 0x6AC) & 0x4000) {
                return 0;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        case 17:
            if (M2C_FIELD(temp_s0, s32 *, 0x788) != 2) {
                return 0;
            }
        default:
block_22:
            var_v0 = 1;
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        case 8:
            if ((!(M2C_FIELD(arg1, f32 *, 0x148) > 0.0f) || (var_v0 = 0, (M2C_FIELD(arg1, s32 *, 0x13C) != 2))) && ((M2C_FIELD(temp_s0, s16 *, 0x5F6) >= 0x32) || (var_v0 = 0, (M2C_FIELD(arg1, s32 *, 0x13C) != 2)))) {
                var_v0 = 1;
                if (M2C_FIELD(temp_s0, s16 *, 0x5F6) < 0xA) {
                    if (M2C_FIELD(arg1, s32 *, 0x13C) == 1) {
                        return 0;
                    }
                    /* Duplicate return node #23. Try simplifying control flow for better match */
                    return var_v0;
                }
                goto block_22;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        case 11:
            var_v0 = 1;
            if (func_80283228_de(&D_8011D8D0, temp_s0) >= 3) {
                return 0;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        case 0:
            var_v0 = 0;
            if (M2C_FIELD(arg1, s32 *, 0x144) != 0) {
                goto block_22;
            }
            /* Duplicate return node #23. Try simplifying control flow for better match */
            return var_v0;
        }
    } else {
        return var_v0;
    }
}
#else
INCLUDE_ASM("span_1000", func_80230058_de);
#endif
