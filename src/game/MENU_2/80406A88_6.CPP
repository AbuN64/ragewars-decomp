#include "include_asm.h"

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
typedef struct EuOptsPage_eux { void *title; void *list; void *bar; void *rowC; void *row10; void *row14; s32 pad18, pad1C, sel, count; } EuOptsPage_eux;
extern EuOptsPage_eux *g_optionsPage;
extern char *D_800E1C14[], *D_800E1C34[], *D_800E1C44[], *D_auto_800E1C54[], *D_auto_800E1C64[], *D_800D2134[], *D_800D2138[], *D_800D213C[];
extern void *Scene_AllocateMemory(); extern void *func_8041A280_de(); extern void func_8041B110_de(); extern void *func_8041ABC0_de();
extern void Menu_AppendListText(); extern void Menu_SelectListEntry(); extern u32 System_GetMemorySize(); extern void *func_8041A580_de();
extern void func_8041A6EC_de(); extern void *func_80419E54_de(); extern void *func_8040EC30_de();
extern char *D_auto_800DDB08[];
/* Builds the options page (0x28-byte state g_optionsPage): title, the three toggle rows (ids 0x53/0x56/0x58) labelled in the
   current language and set from the option bytes 0x1B, 0x1F and 0x580 of D_801462C8, the volume bar 0x5A and its list. Returns 0. */
s32 func_804229E0_eu_x(void *window) {
    u8 lang = D_801462C8.language;
    g_optionsPage = Scene_AllocateMemory(0x28);
    g_optionsPage->title = func_8041A280_de(0x4F, 0x50);
    func_8041B110_de(0x52);
    func_8041B110_de(0x55);
    g_optionsPage->rowC = func_8041ABC0_de(0x53, 0x54);
    Menu_AppendListText(g_optionsPage->rowC, D_800E1C14[lang]);
    Menu_AppendListText(g_optionsPage->rowC, D_800E1C34[lang]);
    Menu_AppendListText(g_optionsPage->rowC, D_800E1C44[lang]);
    Menu_SelectListEntry(g_optionsPage->rowC, *((u8 *)&D_801462C8 + 0x1B));
    g_optionsPage->row10 = func_8041ABC0_de(0x56, 0x57);
    Menu_AppendListText(g_optionsPage->row10, D_auto_800E1C54[lang]);
    Menu_AppendListText(g_optionsPage->row10, D_auto_800E1C64[lang]);
    Menu_SelectListEntry(g_optionsPage->row10, *((u8 *)&D_801462C8 + 0x1F));
    g_optionsPage->row14 = func_8041ABC0_de(0x58, 0x59);
    Menu_AppendListText(g_optionsPage->row14, D_800D2134[lang]);
    if (System_GetMemorySize() != 0x400000) {
        Menu_AppendListText(g_optionsPage->row14, D_800D2138[lang]);
        Menu_AppendListText(g_optionsPage->row14, D_800D213C[lang]);
        Menu_SelectListEntry(g_optionsPage->row14, *((u8 *)&D_801462C8 + 0x580));
    }
    g_optionsPage->bar = func_8041A580_de(0x5A, 0x5B, 0x80);
    func_8041A6EC_de(g_optionsPage->bar, *(s32 *)((u8 *)&D_801462C8 + 0x10));
    func_8041B110_de(0x5D);
    ((u8 **)func_8040EC30_de(window, 0x5E))[0x38 / 4] = (u8 *)D_auto_800DDB08[lang];
    func_8041B110_de(0x5C);
    g_optionsPage->list = func_80419E54_de(0x51, 0x6E);
    g_optionsPage->count = 3;
    g_optionsPage->sel = -1;
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_804229E0_eu_x);
#endif
#endif
