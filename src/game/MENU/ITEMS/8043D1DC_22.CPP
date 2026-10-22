#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"
#include "RENDER_2/802192C0_3.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern f32 D_800C73E4;
extern u8 D_0024B52C_us_rev1[], D_0022E0A0_us_rev1[], D_00219A40_us_rev1[], D_0022E250_us_rev1[];
extern u8 D_0021A2D4_us_rev1[], D_0022F5D0_us_rev1[];
extern void func_8024B3A8_de(void *, void *, void *, s32);
extern void func_80214178_de(void *, void *, s32);
extern void func_802325FC_de(void *, void *);
extern void func_80220A80_de(void *, void *);
extern void func_80245864_de(void *);
typedef struct InitView { char pad0[4]; u32 flags; char pad8[0xF4]; f32 x, y, z; } InitView;
/* Initialises an actor and its embedded part at 0x2E8: sets the shared table pointers and flag bits (one flag
 * depends on D_801462E5), runs the part setup calls, then copies the view's position into the actor. */
void func_80449970_us_rev1(SharedPlayer *player, InputRecAt27 *rec, s32 mode, s32 index) {
    char *actor = (char *)player;
    char *part = actor + 0x2E8;
    char *aux = actor + 0x458;
    u32 flags;
    u32 flags2;
    InitView *view;
    func_8024B3A8_de(actor, rec, (void *)mode, 0);
    *(void **)(actor + 0x1D8) = actor;
    flags = *(u32 *)(actor + 0x100) | 0x100000 | 0x10000 | 0x1000000 | 0x2000000;
    *(u32 *)(actor + 0x100) = flags;
    if (D_801462E5 == 0) {
        *(u32 *)(actor + 0x100) = flags | 0x10000000;
    }
    *(void **)(actor + 0x28C) = D_0024B52C_us_rev1;
    *(void **)(actor + 0x290) = D_0022E0A0_us_rev1;
    *(void **)(actor + 0x280) = D_00219A40_us_rev1;
    *(void **)(actor + 0x288) = D_0022E250_us_rev1;
    if (D_801462E5 != 0) {
        *(void **)(actor + 0x27C) = D_0021A2D4_us_rev1;
    }
    *(void **)(actor + 0x4C0) = actor;
    func_8024B3A8_de(part, rec, (void *)mode, 0);
    *(void **)(actor + 0x574) = D_0022F5D0_us_rev1;
    *(s8 *)(actor + 0x48C) = -1;
    flags2 = *(u32 *)(actor + 0x3E8) | 0x200000;
    *(void **)(actor + 0x4C0) = actor;
    *(void **)(actor + 0x568) = D_00219A40_us_rev1;
    *(void **)(actor + 0x570) = D_0022E250_us_rev1;
    *(u32 *)(actor + 0x3E8) = flags2;
    *(s16 *)(actor + 0x62E) = -1;
    *(f32 *)(actor + 0x338) = D_800C73E4;
    *(f32 *)(actor + 0x33C) = D_800C73E4;
    *(f32 *)(actor + 0x340) = D_800C73E4;
    *(u32 *)(actor + 0x3E8) = flags2 & 0xFFFEFFFF;
    func_80214178_de(part, aux, 0);
    func_802325FC_de(part, aux);
    func_80220A80_de(actor, actor);
    if (*(void **)(actor + 0x5DC) != 0) {
        func_80245864_de(*(void **)(actor + 0x5DC));
    }
    view = *(InitView **)(actor + 0x18);
    *(f32 *)(actor + 0x50) = view->x;
    *(f32 *)(actor + 0x54) = view->y;
    *(f32 *)(actor + 0x58) = view->z;
    view->flags &= ~4;
}
#else
INCLUDE_ASM("ovl_80400000", func_80449970_us_rev1);
#endif
#endif
