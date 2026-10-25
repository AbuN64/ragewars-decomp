#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENULISTSCREEN.H"
#include "TYPES.H"
#include "MENU_2/804366D0_2.H"

#if defined(NON_MATCHING) || (!defined(VERSION_EU) && !defined(VERSION_EU_X))
#if defined(VERSION_DE)
#define PLAYER_SETTINGS_ID(id) ((id) - 2)
#else
#define PLAYER_SETTINGS_ID(id) (id)
#endif
extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern char *D_800D34A4[1], *D_800D34B0[1], *D_800D3470_de[1], *D_800D3474[1], *D_800D34B4[1], *D_800D34B8[1], *D_800D34BC[1];
extern void *Scene_AllocateMemory(s32);
extern void *func_8041A280_de(s32, s32);
extern void func_8041B110_de(s32);
extern void *func_8041ABC0_de(s32, s32);
extern void Menu_AppendListText(void *, char *);
extern void *func_8041A580_de(s32, s32, s32);
extern void *func_80419E54_de(s32, s32);
extern void *func_8040EC30_de(s32, s32);
#define ST ((void **)D_800E5690)
/* Builds the five player-settings controls and opens their parent screen. */
s32 Menu_InitPlayerSettingsScreen(s32 root) {
    D_800E5690 = (struct StateMenuSelectPlayerSettingsEntry *)Scene_AllocateMemory(0x64);
    ST[0] = func_8041A280_de(PLAYER_SETTINGS_ID(0x5B), PLAYER_SETTINGS_ID(0x5C));
    func_8041B110_de(PLAYER_SETTINGS_ID(0x5E));
    D_800E5690->a = func_8041ABC0_de(PLAYER_SETTINGS_ID(0x64), PLAYER_SETTINGS_ID(0x65));
    Menu_AppendListText(D_800E5690->a, D_800D34A4[0]);
    Menu_AppendListText(D_800E5690->a, D_800D34B0[0]);
    D_800E5690->b = func_8041ABC0_de(PLAYER_SETTINGS_ID(0x61), PLAYER_SETTINGS_ID(0x63));
    Menu_AppendListText(D_800E5690->b, D_800D3470_de[0]);
    Menu_AppendListText(D_800E5690->b, D_800D3474[0]);
    D_800E5690->c = func_8041A580_de(PLAYER_SETTINGS_ID(0x66), PLAYER_SETTINGS_ID(0x67), 0xF8);
    D_800E5690->d = func_8041A580_de(PLAYER_SETTINGS_ID(0x6A), PLAYER_SETTINGS_ID(0x6B), 0xF8);
    D_800E5690->e = func_8041ABC0_de(PLAYER_SETTINGS_ID(0x68), PLAYER_SETTINGS_ID(0x69));
    Menu_AppendListText(D_800E5690->e, D_800D34B4[0]);
    Menu_AppendListText(D_800E5690->e, D_800D34B8[0]);
    Menu_AppendListText(D_800E5690->e, D_800D34BC[0]);
    func_8041B110_de(PLAYER_SETTINGS_ID(0x60));
    ST[1] = func_80419E54_de(PLAYER_SETTINGS_ID(0x5D), 0x6E);
    ((s32 *)D_800E5690)[9] = 3;
    ((s32 *)D_800E5690)[8] = -1;
    ST[0xB] = func_8040EC30_de(root, PLAYER_SETTINGS_ID(0x5F));
    ((s32 *)D_800E5690)[10] = 0;
    Menu_SelectPlayerSettingsEntry(0);
    return 0;
}
#undef ST
#undef PLAYER_SETTINGS_ID
#else
INCLUDE_ASM("ovl_80400000", Menu_InitPlayerSettingsScreen);
#endif

/* Stores arg0 into its own D_80146417 entry and pushes the five settings of slot arg0 of the D_80102C89 table into the objects D_800E5690 holds through func_8041AD10_de and func_8041A6EC_de. */


extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern void Menu_SelectListEntry(void *, s32);
extern void func_8041A6EC_de(void *, s32);

void Menu_SelectPlayerSettingsEntry(s32 entryIndex) {
    u8 *slot = &D_801462C8.playerSettings[entryIndex].slot;

    *slot = entryIndex;
    Menu_SelectListEntry(D_800E5690->a, D_80102C89[entryIndex * 0x190]);
    Menu_SelectListEntry(D_800E5690->b, D_800FEC8A[entryIndex * 0x190]);
    func_8041A6EC_de(D_800E5690->c, D_800FEC8B[entryIndex * 0x190]);
    func_8041A6EC_de(D_800E5690->d, D_800FEC8C[entryIndex * 0x190]);
    Menu_SelectListEntry(D_800E5690->e, D_800FEC8D[entryIndex * 0x190]);
}

/* Reads five settings from the objects D_800E5690 holds through func_8041AD04_de and func_8041A6E0_de into slot arg0 of the D_80102C89 table and copies them into the matching bytes of the arg0 entry of D_80146398. */


extern struct StateMenuSelectPlayerSettingsEntry *D_800E5690;
extern s8 D_80102C89[];
extern u8 D_800FEC8A[];
extern u8 D_800FEC8B[];
extern u8 D_800FEC8C[];
extern u8 D_800FEC8D[];
extern u8 D_80146398[];
extern s32 func_8041AD04_de(void *);
extern s32 func_8041A6E0_de(void *);

void func_804367A8_de(s32 arg0) {
    u8 *config;

    config = D_80146398 + arg0 * 0x96;
    D_80102C89[arg0 * 0x190] = func_8041AD04_de(D_800E5690->a);
    do {
        D_800FEC8A[arg0 * 0x190] = func_8041AD04_de(D_800E5690->b);
        D_800FEC8B[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->c);
        D_800FEC8C[arg0 * 0x190] = func_8041A6E0_de(D_800E5690->d);
        D_800FEC8D[arg0 * 0x190] = func_8041AD04_de(D_800E5690->e);
    } while (0);
    config[0x7B] = D_80102C89[arg0 * 0x190];
    config[0x7D] = D_800FEC8A[arg0 * 0x190];
    config[0x79] = D_800FEC8B[arg0 * 0x190];
    config[0x7A] = D_800FEC8C[arg0 * 0x190];
    config[0x82] = D_800FEC8D[arg0 * 0x190];
}
