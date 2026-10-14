#include "span_16E000/code_80444EC0.h"
#include "span_16E000/code_8043F69C.h"
#include "span_C76B0/data.h"
#include "types.h"

/* Shows the fixed sound value text when D_800E63B8 is zero. Otherwise
 * formats its current value into the alternate text, two bytes before
 * the line length reported by the text item helper. */
extern s32 D_800E63B8;
extern u8 *D_800D3DBC;
extern char D_800DE7B0_de[];
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US_REV1)
s32 func_80445ECC(Item_func_80441FE8_de *field) {
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
