#include "include_asm.h"
#include "MENU/OPTIONEDITSTATE.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", func_80445ECC);
#endif

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
/* Shows the fixed sound value text when D_800E63B8 is zero. Otherwise
 * formats its current value into the alternate text, two bytes before
 * the line length reported by the text item helper. */
extern s32 func_80441FE8_de(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445ECC(LayeredText *field) {
    char *text;
    if (D_800E63B8 == 0) {
        field->text = &D_800D3DBC;
    } else {
        field->text = (u8 **)&D_800D3DC0;
        text = (char *)*(u8 **)&D_800D3DC0;
        func_802658E4_de(text + (func_80441FE8_de(field) - 2),
                        D_800DE7B0_de, D_800E63B8);
    }
    return 0;
}

#endif
#endif
