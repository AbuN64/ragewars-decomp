#include "include_asm.h"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
extern u8 D_801462C8_b[];
typedef struct { void *a0, *a4, *a8, *aC, *a10; s32 a14; void *a18; } MenuBlockEu;
extern MenuBlockEu *D_800E5694;
extern char *D_800E1CE4[], *D_800E1D14[], *D_800E1C14[], *D_800E1C24[], *D_800E1D24[], *D_800E1D34_eu[], *D_800E1D44[];
extern void *Cache_AllocateMemory(s32);
extern void func_8041B110_de(s32), SmpButton_AppendListText(void *, char *);
extern void *func_8041ABC0_de(s32, s32), *func_8041A580_de(s32, s32, s32), *func_8040EC30_de(void *, s32);
extern void func_804368F8_de(s32);
/* Builds the 0x50-byte confirm popup: its three button rows (ids 0x1C9, 0x1D1, 0x1CB) get the labels of the current language,
   the two fade windows 0x1CF/0x1CD are created, and item 0x1C7 is kept as the cursor. Returns 0. */
s32 func_80437690_eu(void *window) {
    u8 lang;
    D_800E5694 = Cache_AllocateMemory(0x50);
    func_8041B110_de(0x1C6);
    lang = D_801462C8_b[0x581];
    D_800E5694->aC = func_8041ABC0_de(0x1C9, 0x1CA);
    SmpButton_AppendListText(D_800E5694->aC, D_800E1CE4[lang]);
    SmpButton_AppendListText(D_800E5694->aC, D_800E1D14[lang]);
    D_800E5694->a8 = func_8041ABC0_de(0x1D1, 0x1D2);
    SmpButton_AppendListText(D_800E5694->a8, D_800E1C14[lang]);
    SmpButton_AppendListText(D_800E5694->a8, D_800E1C24[lang]);
    func_8041A580_de(0x1CF, 0x1D0, 0xFF);
    D_800E5694->a0 = func_8041A580_de(0x1CD, 0x1CE, 0xFF);
    D_800E5694->a4 = func_8041ABC0_de(0x1CB, 0x1CC);
    D_800E5694->a10 = D_800E5694->a4;
    SmpButton_AppendListText(D_800E5694->a4, D_800E1D24[lang]);
    SmpButton_AppendListText(D_800E5694->a10, D_800E1D34_eu[lang]);
    SmpButton_AppendListText(D_800E5694->a10, D_800E1D44[lang]);
    func_8041B110_de(0x1C8);
    D_800E5694->a18 = func_8040EC30_de(window, 0x1C7);
    D_800E5694->a14 = 0;
    func_804368F8_de(0);
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80437690_eu);
#endif
#endif
