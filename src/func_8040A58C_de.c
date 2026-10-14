#include "types.h"
#include "span_16E000/code_804453C4.h"

/* Formats the halfword at offset 0x22 of the structure D_800E28BC points to into a field's text
   with the format D_800DCD80, two bytes before the length func_80441FE8_de reports, and returns
   zero. */

struct PreviewTextValue { char pad[0x22]; s16 value; };

extern struct PreviewTextValue *D_800E28BC;
extern char D_800DCD80[];
extern s32 func_80441FE8_de(struct Field_func_80445414_us_rev1 *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A58C_de(struct Field_func_80445414_us_rev1 *field) {
    s32 value = D_800E28BC->value;
    char *text = *field->text;

    func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DCD80, value);
    return 0;
}
