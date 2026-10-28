#include "include_asm.h"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/PAKINTERFACE_GETRECORDSNOTESIZE.H"

extern char *D_800D3758;

extern char D_800DDEC0[];

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EE534[], D_800EE540[];
#else
extern char g_noteInfoIntFormat[];

#endif
extern s32 Note_ReadNoteInfo(s32, s32, s32 *, char *, u8 *, s32 *, char *, char *);
extern s32 Note_ContainsInvalidNameByte(char *, s32);
extern void XPlus_CopyString(char *, char *);
extern void XStdio_FormatBuffer(char *, char *, ...);
extern s32 Note_GetFreePages(s32, s32 *);
extern u32 Note_BytesToPakPages(u32);
extern void PAKInterface_RefreshPlayerPanel(s32, s32);
extern void PAKInterface_ScrollNoteList(s32, s32);

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

void PAKInterface_LoadNoteList(s32 player)
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
        note_status = Note_ReadNoteInfo(player, i, &status, name, ext, &size, extra1, extra2);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        settings = (GameLocalizationState *)D_801462C8;

#else
#endif
        if (note_status == 0) {
            if (status == 1) {
                if (Note_ContainsInvalidNameByte(name, 16) == 1) {
#if defined(VERSION_EU)
                    XPlus_CopyString(name, ((D_800E27B4)[settings->language]));
#elif defined(VERSION_EU_X)
                    XPlus_CopyString(name, ((D_800DE03C)[settings->language]));
#else
                    XPlus_CopyString(name, (D_800D3758));
#endif
                }
                XPlus_CopyString(D_800E54A4->players[player].noteTexts[i].name, name);
                XStdio_FormatBuffer(D_800E54A4->players[player].noteTexts[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 size);
                if (ext[0] != 0) {
                    XStdio_FormatBuffer(D_800E54A4->players[player].noteTexts[i].label,
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
        XPlus_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((D_800E1394)[settings->language]));
#elif defined(VERSION_EU_X)
        XPlus_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((D_800DD124)[settings->language]));
#else
        XPlus_CopyString(D_800E54A4->players[player].noteTexts[i].name, ((char *)D_800D3250[0]));
#endif
        XStdio_FormatBuffer(D_800E54A4->players[player].noteTexts[i].size,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 0);
    numbered:
        XStdio_FormatBuffer(D_800E54A4->players[player].noteTexts[i].label,
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
        item = (Label *)Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2D8);
        if (Note_GetFreePages(player, &size) == 0) {
            XStdio_FormatBuffer(D_800E54A4->players[player].freeText,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 size);
            item->text = D_800E54A4->players[player].freeText;
            item = (Label *)Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2D7);
            size = PAKInterface_GetRecordsNoteSize();
            XStdio_FormatBuffer(D_800E54A4->players[player].usedText,
#if defined(VERSION_EU) || defined(VERSION_EU_X)
D_800DDEC0,
#else
g_noteInfoIntFormat,
#endif
 Note_BytesToPakPages(size));
            item->text = D_800E54A4->players[player].usedText;
        } else {
            failed = 1;
        }
    }
    if (failed == 1) {
        D_800E54A4->players[player].state = failed;
        PAKInterface_RefreshPlayerPanel(player, PAK_RESOURCE_2DB);
        return;
    }
    D_800E54A4->players[player].slot = -1;
    D_800E54A4->players[player].scroll = 0;
    D_800E54A4->players[player].labels[0] = Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DB);
    D_800E54A4->players[player].labels[1] = Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DC);
    D_800E54A4->players[player].labels[2] = Node_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget, PAK_RESOURCE_2DD);
    PAKInterface_ScrollNoteList(player, 1);
}
