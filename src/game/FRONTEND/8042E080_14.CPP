#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8042E080_53.H"

extern char *D_800D3758;

extern char D_800DDEC0[];

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EE534[], D_800EE540[];
#else
extern char g_noteInfoIntFormat[];

#endif
extern s32 Pak_ReadNoteInfo(s32, s32, s32 *, char *, u8 *, s32 *, char *, char *);
extern s32 func_804057BC_de(char *, s32);
extern void Resmgr_CopyString(char *, char *);
extern void func_802A0C08_de(char *, char *, ...);
extern s32 Pak_GetFreePages(s32, s32 *);
extern s32 Frontend_GetRecordsNoteSize(void);
extern s32 Ovlgame_BytesToPakPages(s32);
extern void Frontend_RefreshPlayerPanel(s32, s32);
extern void func_80434250_de(s32, s32);

/* Builds a player's controller pak note list: each of the sixteen notes gets its name (a default when unnamed), its size and a numbered label with the extension when it has one, or empty entries once the pak cannot be read; then the free and used page counts are formatted into their menu items, and on any read failure the slot is marked failed instead of opening the note menu. */
#if defined(VERSION_DE)
enum { PAK_RESOURCE_2D7 = 750, PAK_RESOURCE_2D8 = 749, PAK_RESOURCE_2DB = 746, PAK_RESOURCE_2DC = 745, PAK_RESOURCE_2DD = 747 };
#elif defined(VERSION_EU)

extern u8 D_801462C8[];

extern char *D_800E27B4[], *D_800E1394[];
enum { PAK_RESOURCE_2D7 = 727, PAK_RESOURCE_2D8 = 728, PAK_RESOURCE_2DB = 731, PAK_RESOURCE_2DC = 732, PAK_RESOURCE_2DD = 733 };
#elif defined(VERSION_EU_X)

extern u8 D_801462C8[];

extern char *D_800DE03C[], *D_800DD124[];

enum { PAK_RESOURCE_2D7 = 753, PAK_RESOURCE_2D8 = 751, PAK_RESOURCE_2DB = 754, PAK_RESOURCE_2DC = 755, PAK_RESOURCE_2DD = 756 };
#else
enum { PAK_RESOURCE_2D7 = 727, PAK_RESOURCE_2D8 = 728, PAK_RESOURCE_2DB = 731, PAK_RESOURCE_2DC = 732, PAK_RESOURCE_2DD = 733 };
#endif

#if !defined(VERSION_EU) && !defined(VERSION_EU_X)
static const char controller_pak_note_label_format[] = "%d.%s.%s";
#endif

void func_80433EA0_de(s32 player)
{
    char name[0x18];
    u8 ext[8];
    char extra1[8];
    char extra2[8];
    s32 status;
    s32 size;
    s32 failed;
    s32 i;
    Label *item;
    s32 note_status;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    GameLocalizationState *settings;

#else
#endif
    failed = 0;
    for (i = 0; i < 16 && failed == 0; i++) {
        note_status = Pak_ReadNoteInfo(player, i, &status, name, ext, &size, extra1, extra2);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        settings = (GameLocalizationState *)D_801462C8;

#else
#endif
        if (note_status == 0) {
            if (status == 1) {
                if (func_804057BC_de(name, 16) == 1) {
#if defined(VERSION_EU)
                    Resmgr_CopyString(name, ((D_800E27B4)[settings->language]));
#elif defined(VERSION_EU_X)
                    Resmgr_CopyString(name, ((D_800DE03C)[settings->language]));
#else
                    Resmgr_CopyString(name, (D_800D3758));
#endif
                }
                Resmgr_CopyString(D_800E54A4->players[player].noteTexts[i].name, name);
                func_802A0C08_de(D_800E54A4->players[player].noteTexts[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 size);
                if (ext[0] != 0) {
                    func_802A0C08_de(D_800E54A4->players[player].noteTexts[i].label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800EE534,
#else
controller_pak_note_label_format,
#endif
 i + 1,
                                  D_800E54A4->players[player].noteTexts[i].name, ext);
                    continue;
                }
                goto numbered;
            }
        } else {
            failed = 1;
        }
#if defined(VERSION_EU)
        Resmgr_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((D_800E1394)[settings->language]));
#elif defined(VERSION_EU_X)
        Resmgr_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((D_800DD124)[settings->language]));
#else
        Resmgr_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((char *)D_800D3250[0]));
#endif
        func_802A0C08_de(D_800E54A4->players[player].noteTexts[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 0);
    numbered:
        func_802A0C08_de(D_800E54A4->players[player].noteTexts[i].label,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800EE540,
#else
D_800DDEC0,
#endif
 i + 1,
                      D_800E54A4->players[player].noteTexts[i].name);
    }
    if (failed == 0) {
        /* the hub EC30 returns the item view; Label is this unit's text-bearing view of it */
        item = (Label *)func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2D8);
        if (Pak_GetFreePages(player, &size) == 0) {
            func_802A0C08_de(D_800E54A4->players[player].freeText,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 size);
            item->text = D_800E54A4->players[player].freeText;
            item = (Label *)func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2D7);
            size = Frontend_GetRecordsNoteSize();
            func_802A0C08_de(D_800E54A4->players[player].usedText,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 Ovlgame_BytesToPakPages(size));
            item->text = D_800E54A4->players[player].usedText;
        } else {
            failed = 1;
        }
    }
    if (failed == 1) {
        D_800E54A4->players[player].state = failed;
        Frontend_RefreshPlayerPanel(player, PAK_RESOURCE_2DB);
        return;
    }
    D_800E54A4->players[player].slot = -1;
    D_800E54A4->players[player].scroll = 0;
    D_800E54A4->players[player].labels[0] = func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DB);
    D_800E54A4->players[player].labels[1] = func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DC);
    D_800E54A4->players[player].labels[2] = func_8040EC30_de(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DD);
    func_80434250_de(player, 1);
}

#if defined(VERSION_US)
unsigned char rodata_unresolved_800DCB6D[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_DE)
unsigned char rodata_unresolved_800DDEBD[3] = {
    0x00, 0x00, 0x00,
};
#endif

#if defined(VERSION_US_REV1)
unsigned char rodata_unresolved_800E1EED[3] = {
    0x00, 0x00, 0x00,
};
#endif
