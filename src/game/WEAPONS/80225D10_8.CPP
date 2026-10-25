#include "include_asm.h"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/OBJRECV5.H"
#include "WEAPONS/80225D10_8.H"
#include "WEAPONS/80213ED4.H"

#if (defined(VERSION_DE) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", func_80229814_de);
#endif

#if (defined(VERSION_DE) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
const unsigned int rodata_func_80229814_de_800C7D48[10] = {
    0x42960000, 0x41700000, 0x42960000, 0x40F00000, 0x4F000000, 0x3D888889, 0x3FC00000, 0x41700000,
    0x4F000000, 0x4F000000,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800C2F64[1] = {
    0x00000000,
};
#endif

#if !(defined(VERSION_DE) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
typedef struct {
    char pad0[0x98];
    s32 rule;
    char pad9C[0xA0 - 0x9C];
    s32 protect;
} StunProtectionRules;

extern StunProtectionRules D_801468A0[];
extern void func_802227F4_de(SharedPlayer *, SharedPlayer *, s32);

extern void func_802391AC_de(ViewRecAt54D *, s32, s32, s32, s32, s32, s32, s32);

void func_80229814_de(SharedPlayer *player, f32 amount) {
    f32 stun;

    if (amount != 0.0f && !(75.0f <= player->views5E8.view11D8_149.stun) && !(player->views5E8.view670_31.shield > 0.0f)
        && !(D_801468A0->rule != 0 && player->views5D8.view5D8_2.controls->mode == 0xB && D_801468A0->protect > 0)
        && !(player->views122C.view122C_2.options & 0x8000)) {
        stun = player->views5E8.view11D8_149.stun + amount * 15.0f;
        if (75.0f < stun) {
            stun = 75.0f;
        }
        player->views5E8.view11D8_149.stun = stun;
        func_80214178_de(player->views1C.view2E8_28.weapon, player->views1C.view458_30.ammo, 2);
        if (player->views5E8.view1210_153.marker != 0) {
            if (player->views5E4.view5E4_4.holding != 0) {
                func_802227F4_de(player, player, 2);
            }
            player->views5E8.view1210_153.marker = 0;
            player->views5E8.view1214_156.markerShown = 0;
        }
        player->views1C.view100_9.flags &= ~0x01000000;
        if (player->views5DC.view5DC_2.view != 0) {
            if (((ViewRecAt54D *)player->views5DC.view5DC_2.view)->flash == 0) {
                func_802391AC_de((ViewRecAt54D *)player->views5DC.view5DC_2.view, 0x80, 0, 0, 0xFA, (u8) (u32) Nav_RandomFloat(7.5f), 0,
                              (u8) (u32) ((player->views5E8.view11D8_149.stun * 0.06666667f - 1.5f) * 15.0f));
            } else {
                ((ViewRecAt54D *)player->views5DC.view5DC_2.view)->flash = 3;
                ((ViewRecAt54D *)player->views5DC.view5DC_2.view)->level = (u32) player->views5E8.view11D8_149.stun;
            }
        }
    }
}
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800C2F24[1] = {
    0x00000000,
};
#endif
