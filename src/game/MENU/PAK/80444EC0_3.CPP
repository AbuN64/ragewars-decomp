#include "include_asm.h"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/OPTIONEDITSTATE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
extern void func_802658E4_de(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"
extern u8 *D_800E22E4_eu[], *D_800E22F4[];
extern char D_800DE758_de[];

s32 func_80444D9C_de(LayeredText *item) {
    u32 code;
    u8 *text;
    s32 length;
    Shared_Game *game = &D_801462C8;
    code = (u32)game->buttons >> 4;
    func_8025476C_de((u32)func_8025477C_de() + 2U);
    if (code == 0) item->text = D_800E22E4_eu;
    else {
        item->text = D_800E22F4;
        text = item->text[game->language];
        length = Pak_CountLineChars(item);
        func_802658E4_de((char *)text + (length - 4), D_800DE758_de, code);
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
extern void func_8025476C_de(u32);
extern s32 Pak_CountLineChars(LayeredText *);

s32 func_80444D9C_de(LayeredText *item) {
    u32 code;
    u8 *text;
    s32 length;

    code = D_801462C8.buttons >> 4;
    func_8025476C_de((u32)func_8025477C_de() + 2U);
    if (code == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22E4_eu;
#else
        item->text = &D_800D3624;
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22F4;
        text = item->text[D_80152789];
#else
        item->text = &D_800D3628;
        text = *item->text;
#endif
        length = Pak_CountLineChars(item);
        func_802658E4_de((char *)text + (length - 4), D_800DE758_de, code);
    }
    return 0;
}
#endif
