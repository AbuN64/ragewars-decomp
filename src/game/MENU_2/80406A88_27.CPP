#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#define EUP(p, t, o) (*(t *)((u8 *)(p) + (o)))
extern char D_0024B54C_eu[], D_0022E1A8_eu[], D_00219AD8_eu[], D_0022E358_eu[], D_0021A36C_eu[], D_0022F6E0_eu[];
extern f32 D_800C73E4;
extern void func_8024B3A8_de(), Weapons_RequestActorState(), Weapons_ApplyWeaponSwitch(), Weapons_UpdatePlayerCamera(), func_80245864_de();
/* Initialises a player record: links it to itself, sets the base flags (and the extra flag when D_801462E5 is clear), fills the
   callback slots and builds the attached sub-record at 0x2E8 and the body record at 0x458, then copies the start position. */
void Ovlgame_InitActorParts(u8 *p, void *a1, void *a2) {
    u8 *sub = p + 0x2E8;
    u8 *body = p + 0x458;
    u32 flags;

    EUP(p, u8 *, 0x1D8) = p;
    func_8024B3A8_de(p, a1, a2, 0);
    EUP(p, u8 *, 0x1D8) = p;
    flags = EUP(p, u32, 0x100) | 0x100000 | 0x10000 | 0x1000000 | 0x2000000;
    EUP(p, u32, 0x100) = flags;
    if (D_801462C8.local == 0) {
        EUP(p, u32, 0x100) = flags | 0x10000000;
    }
    EUP(p, void *, 0x28C) = D_0024B54C_eu;
    EUP(p, void *, 0x290) = D_0022E1A8_eu;
    EUP(p, void *, 0x280) = D_00219AD8_eu;
    EUP(p, void *, 0x288) = D_0022E358_eu;
    if (D_801462C8.local != 0) {
        EUP(p, void *, 0x27C) = D_0021A36C_eu;
    }
    EUP(p, u8 *, 0x4C0) = p;
    func_8024B3A8_de(sub, a1, a2, 0);
    EUP(p, void *, 0x574) = D_0022F6E0_eu;
    EUP(p, s8, 0x48C) = -1;
    flags = EUP(p, u32, 0x3E8) | 0x200000;
    EUP(p, u8 *, 0x4C0) = p;
    EUP(p, void *, 0x568) = D_00219AD8_eu;
    EUP(p, void *, 0x570) = D_0022E358_eu;
    EUP(p, u32, 0x3E8) = flags;
    EUP(p, s16, 0x62E) = -1;
    EUP(p, f32, 0x338) = D_800C73E4;
    EUP(p, f32, 0x33C) = D_800C73E4;
    EUP(p, f32, 0x340) = D_800C73E4;
    EUP(p, u32, 0x3E8) = flags & 0xFFFEFFFF;
    Weapons_RequestActorState(sub, body, 0);
    Weapons_ApplyWeaponSwitch(sub, body);
    Weapons_UpdatePlayerCamera(p, p);
    if (EUP(p, void *, 0x5DC) != 0) {
        func_80245864_de(EUP(p, void *, 0x5DC));
    }
    {
        u8 *src = EUP(p, u8 *, 0x18);
        EUP(p, f32, 0x50) = EUP(src, f32, 0xFC);
        EUP(p, f32, 0x54) = EUP(src, f32, 0x100);
        EUP(p, f32, 0x58) = EUP(src, f32, 0x104);
        EUP(src, u32, 4) &= ~4;
    }
}
#else
INCLUDE_ASM("ovl_80400000", Ovlgame_InitActorParts);
#endif
#endif
