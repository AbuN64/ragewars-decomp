#include "SYSTEM/DEFS.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/UNUSED.H"

/* Replaces the word at offset 0x10 of the option block D_801462C8 with what Menu_AdjustValue returns
   for the second argument, that word, 0x10, 0, 0x80 and 0, and returns zero. */


extern s32 Menu_AdjustValue(void *, s32, s32, s32, s32, s32);

s32 Pak_AdjustPackedButtonOption(void *first, void *second) {
    struct OptionsPakAdjustPackedButtonOption *options = &D_801462C8;

    options->value = Menu_AdjustValue(second, options->value, 0x10, 0, 0x80, 0);
    return 0;
}


#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM/DEFS.H"
extern u8 *D_800E22E4_eu[], *D_800E22F4[];

s32 Pak_FormatPackedButtonOption(LayeredText *item) {
    u32 code;
    u8 *text;
    s32 length;
    Shared_Game *game = &D_801462C8;
    code = (u32)game->buttons >> 4;
    Cache_SetResourceActivityState((u32)func_8025477C_de() + 2U);
    if (code == 0) item->text = D_800E22E4_eu;
    else {
        item->text = D_800E22F4;
        text = item->text[game->language];
        length = Menu_CountLineChars(item);
        Defs_FormatIntegerValue((char *)text + (length - 4), D_800DE758_de, code);
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800E22E4_eu[];
extern u8 *D_800E22F4[];
#else
extern u8 *D_800D3628;
#endif
extern s32 func_8025477C_de(void);
extern void Cache_SetResourceActivityState(u32);
extern s32 Menu_CountLineChars(LayeredText *);

s32 Pak_FormatPackedButtonOption(LayeredText *item) {
    u32 code;
    u8 *text;
    s32 length;

    code = D_801462C8.buttons >> 4;
    Cache_SetResourceActivityState((u32)func_8025477C_de() + 2U);
    if (code == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22E4_eu;
#else
        item->text = &D_800D3624;
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22F4;
        text = item->text[g_languageIndex];
#else
        item->text = &D_800D3628;
        text = *item->text;
#endif
        length = Menu_CountLineChars(item);
        Defs_FormatIntegerValue((char *)text + (length - 4), D_800DE758_de, code);
    }
    return 0;
}
#endif
