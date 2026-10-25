#include "include_asm.h"

#if defined(VERSION_US)
#ifdef NON_MATCHING
extern char *D_800E3590;
extern void *Scene_AllocateMemory(s32);
extern void *func_8041B610_de(s32, s32);
extern void func_8041B6E8_de(s32, s32, s32);
extern void func_8041B968_de(void *, s32);
extern u8 *func_8040EC30_de(s32, s32);
extern void *func_80419E54_de(s32, s32);
extern void Frontend_SetWidgetFlag08(void *, s32);
extern void Frontend_AdvanceActiveSlot(void *);
extern void func_8041D6A8_de(void);
extern void Frontend_ShowUnlockedEntries(s32);
#define ST_W(off) (*(s32 *)(D_800E3590 + (off)))
#define HW(w, off) (*(s16 *)((char *)(w) + (off)))
#define UHW(w, off) (*(u16 *)((char *)(w) + (off)))
/* Opens the 0x210-byte screen state D_800E3590 for owner arg0: a four-row list, the side widgets 0x1E8, 0x1E7 and 0x1E4 pushed out by their width quarter, plus the labels 0x1E2, 0x22F, 0x1EC, 0x1ED, 0x1FC, 0x1FB, 0x1FA and 0x1E9; returns zero. */
s32 func_8041CEB0_us(s32 arg0) {
    u8 *w;
    D_800E3590 = (char *)Scene_AllocateMemory(0x210);
    ST_W(0) = arg0;
    ST_W(4) = (s32)func_8041B610_de(arg0, 4);
    func_8041B6E8_de(arg0, 0, 0x1FD);
    func_8041B6E8_de(arg0, 1, 0x1FD);
    func_8041B6E8_de(arg0, 2, 0x1FD);
    func_8041B6E8_de(arg0, 3, 0x1FD);
    func_8041B968_de((void *)ST_W(4), 1);
    ST_W(0xD8) = 1;
    ST_W(0xDC) = 4;
    w = func_8040EC30_de(arg0, 0x1E8);
    ST_W(0xC8) = (s32)w;
    UHW(w, 0x14) = UHW(w, 0x14) - UHW(w, 0x18);
    ST_W(0xCC) = HW(w, 0x18) / 4;
    w = (u8 *)ST_W(0xC8);
    UHW(w, 0x14) = UHW(w, 0x14) + (HW(w, 0x18) - ST_W(0xCC) * 4);
    w = func_8040EC30_de(arg0, 0x1E7);
    ST_W(0xD0) = (s32)w;
    UHW(w, 0x14) = UHW(w, 0x14) + UHW(w, 0x18);
    ST_W(0xD4) = HW(w, 0x18) / 4;
    w = (u8 *)ST_W(0xD0);
    UHW(w, 0x14) = UHW(w, 0x14) - (HW(w, 0x18) - ST_W(0xD4) * 4);
    func_8040EC30_de(arg0, 0x1E4)[0x10] = 0x6E;
    w = (u8 *)func_80419E54_de(0x1E2, 0xFF);
    ST_W(0xE0) = (s32)w;
    w = func_8040EC30_de(arg0, 0x1E2);
    ST_W(0xE4) = (s32)w;
    Frontend_SetWidgetFlag08(w, 0);
    w = func_8040EC30_de(arg0, 0x22F);
    ST_W(0xE8) = (s32)w;
    Frontend_SetWidgetFlag08(w, 0);
    func_8040EC30_de(arg0, 0x1EC)[0x10] = 0x6E;
    func_8040EC30_de(arg0, 0x1ED)[0x10] = 0x78;
    w = func_8040EC30_de(arg0, 0x1FC);
    ST_W(0xF4) = (s32)w;
    Frontend_SetWidgetFlag08(w, 0);
    ST_W(0xFC) = 0;
    ST_W(0xF8) = 0x1B;
    w = func_8040EC30_de(arg0, 0x1FB);
    ST_W(0x100) = (s32)w;
    Frontend_SetWidgetFlag08(w, 0);
    ((u8 *)ST_W(0x100))[0x10] = 0;
    ST_W(0x104) = 0x19;
    ST_W(0xF0) = (s32)func_8040EC30_de(arg0, 0x1FA);
    ST_W(0x108) = 0;
    ST_W(0x10C) = -1;
    Frontend_AdvanceActiveSlot(D_800E3590 + 0x10C);
    func_8041D6A8_de();
    Frontend_ShowUnlockedEntries(ST_W(0xFC));
    func_8040EC30_de(arg0, 0x1E9)[0x10] = 0x6E;
    ST_W(0xEC) = 0;
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8041CEB0_us);
#endif
#endif
