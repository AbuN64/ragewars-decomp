#include "include_asm.h"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
extern s32 *g_optionsPage;
extern u8 D_801462C8[];
extern s32 D_auto_800D3480, D_auto_800D3484, D_auto_800D3488, D_auto_800D348C, D_auto_800D3490;
extern void *Cache_AllocateMemory(s32);
extern void *func_8041A280_de(s32, s32);
extern void func_8041B110_de(s32);
extern void *func_8041ABC0_de(s32, s32);
extern void SmpButton_AppendListText(void *, s32);
extern void SmpButton_SelectListEntry(void *, s32);
extern s32 Defs_GetMemorySize(void);
extern void *func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(void *, s32);
extern void *func_80419E54_de(s32, s32);
/* Builds the options page g_optionsPage (0x28 bytes) from resources 0x4D to 0x58 and wires its widgets to the settings in D_801462C8; returns zero. */
s32 func_804230E0_de(void) {
    g_optionsPage = (s32 *)Cache_AllocateMemory(0x28);
    g_optionsPage[0] = (s32)func_8041A280_de(0x4D, 0x4E);
    func_8041B110_de(0x57);
    func_8041B110_de(0x58);
    g_optionsPage[4] = (s32)func_8041ABC0_de(0x51, 0x52);
    SmpButton_AppendListText((void *)g_optionsPage[4], D_auto_800D3480);
    SmpButton_AppendListText((void *)g_optionsPage[4], D_auto_800D3484);
    SmpButton_SelectListEntry((void *)g_optionsPage[4], D_801462C8[0x1F]);
    g_optionsPage[5] = (s32)func_8041ABC0_de(0x53, 0x54);
    SmpButton_AppendListText((void *)g_optionsPage[5], D_auto_800D3488);
    if (Defs_GetMemorySize() != 0x400000) {
        SmpButton_AppendListText((void *)g_optionsPage[5], D_auto_800D348C);
        SmpButton_AppendListText((void *)g_optionsPage[5], D_auto_800D3490);
    }
    SmpButton_SelectListEntry((void *)g_optionsPage[5], D_801462C8[0x580]);
    g_optionsPage[2] = (s32)func_8041A580_de(0x55, 0x56, 0x80);
    func_8041A6EC_de((void *)g_optionsPage[2], *(s32 *)(D_801462C8 + 0x10));
    func_8041B110_de(0x50);
    g_optionsPage[1] = (s32)func_80419E54_de(0x4F, 0x6E);
    g_optionsPage[9] = 3;
    g_optionsPage[8] = -1;
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804230E0_de);
#endif
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_80423274_de_padding_189274[12] = { 0x3C, 0x04, 0x80, 0x0E, 0x8C, 0x84, 0x04, 0xC0, 0x27, 0xBD, 0xFF, 0xE8 };
#endif
