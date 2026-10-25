#include "include_asm.h"
#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"

#if !defined(VERSION_US)
/* Shows the fixed sound value text when D_800E63B8 is zero. Otherwise
 * formats its current value into the alternate text (the current menu
 * language's line in the EU builds), two bytes before the line length
 * reported by the text item helper. */
extern s32 Pak_CountLineChars(LayeredText *);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* The menu language byte; read as an array element, which keeps the read after the text store. */
extern u8 g_languageIndex[];
extern char D_800EEE20[];
#define VALUE_TEXT D_800E4154
#define VALUE_FORMAT D_800EEE20
#else
#define VALUE_TEXT ((u8 **)&D_800D3DC0)
#define VALUE_FORMAT D_800DE7B0_de
#endif

s32 func_80445ECC(LayeredText *field) {
    char *text;
    if (D_800E63B8 == 0) {
        field->text = &D_800D3DBC;
    } else {
        field->text = VALUE_TEXT;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        text = (char *)field->text[g_languageIndex[0]];
#else
        text = (char *)*VALUE_TEXT;
#endif
        func_802658E4_de(text + (Pak_CountLineChars(field) - 2),
                        VALUE_FORMAT, D_800E63B8);
    }
    return 0;
}
#endif
