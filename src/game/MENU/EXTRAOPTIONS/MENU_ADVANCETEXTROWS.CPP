#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/NUMBERPADSCREEN.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SCREEN.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
const unsigned int rodata_func_80421568_de_800E15E8[10] = {
    0x00421B24, 0x00421B38, 0x00421B4C, 0x00421B60, 0x00421B74, 0x00421B88, 0x00421B9C, 0x00421BB0,
    0x00421BC4, 0x00421BD8,
};
#endif

#if (defined(VERSION_EU) || defined(VERSION_EU_X)) && !defined(NON_MATCHING)
INCLUDE_ASM("ovl_80400000", Menu_AdvanceTextRows);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X)) || defined(NON_MATCHING)
/* Fuzzy draft in EU and EU-X: their body differs. */
#if defined(VERSION_DE)
#define ID_ROW0 946
#define ID_CLOSE 933
#else
#define ID_ROW0 952
#define ID_CLOSE 939
#endif
void Menu_AdvanceTextRows(void) {
    MenuWidget *item;
    char *text;
    s32 line;
    s32 index;

    line = g_extraOptionsScreen->length;
    index = g_extraOptionsScreen->value;
    do {
        text = g_creditsLocalizedLines[0][index];

        if (text != 0) {
            index++;
        }
        item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0);
        switch (line) {
        case 0:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0);
            break;
        case 1:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 1);
            break;
        case 2:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 2);
            break;
        case 3:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 3);
            break;
        case 4:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 4);
            break;
        case 5:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 5);
            break;
        case 6:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 6);
            break;
        case 7:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 7);
            break;
        case 8:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 8);
            break;
        case 9:
            item = Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_ROW0 + 9);
            break;
        }
        item->text = text;
        line++;
    } while (line < 10);
        if (g_creditsLocalizedLines[0][g_extraOptionsScreen->value] != 0)

    {
        if (g_extraOptionsScreen->length == 0) {
            g_extraOptionsScreen->value++;
        }
    } else {
        Widget_SetWidgetFlag08(g_extraOptionsScreen->pad, 0);
        Widget_SetWidgetFlag08(Node_FindWidgetByResourceId(g_extraOptionsScreen->window, ID_CLOSE), 1);
        g_extraOptionsScreen->cursor = 1;
    }
    if (g_extraOptionsScreen->length > 0) {
        g_extraOptionsScreen->length--;
    }
}
#endif
