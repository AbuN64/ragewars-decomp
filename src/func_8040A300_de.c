#include "span_16E000/code_80409A88.h"
#include "span_16E000/code_8043F69C.h"
#include "common/types_1dc8418c21db.h"
#include "span_C76B0/data.h"
#include "types.h"

/* Uses the fixed option text while the mode flag is set. Otherwise formats
 * one more than the holder's signed option byte into the editable text,
 * one byte before the length returned by the item text helper. */
extern s32 D_8015375C;
extern u8 *D_800D7E14[];
extern char D_800DCD7C[];
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040A300_de(Item_func_80441FE8_de *field, struct Record_func_80409BDC_de *holder) {
    char *text;
    s32 value;
    if (D_8015375C != 0) {
        field->text = D_800D7E14;
    } else {
        value = holder->inner->unk4;
        field->text = (u8 **)&D_800D36E4;
        text = (char *)*(u8 **)&D_800D36E4;
        func_802658E4_de(text + (func_80441FE8_de(field) - 1),
                        D_800DCD7C, value + 1);
    }
    return 0;
}

#endif
