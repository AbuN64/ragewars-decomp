#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECATCV1.H"
#include "SYSTEM_3/80265370.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
INCLUDE_ASM("ovl_80400000", func_8040A58C_de);
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Formats the halfword at offset 0x22 of the structure D_800E28BC points to into a field's text
   with the format D_800DCD80, two bytes before the length func_80441FE8_de reports, and returns
   zero. */

struct PreviewTextValue { char pad[0x22]; s16 value; };

extern struct PreviewTextValue *D_800E28BC;
extern s32 func_80441FE8_de(struct Field *);

s32 func_8040A58C_de(struct Field *field) {
    s32 value = D_800E28BC->value;
    char *text = *field->text;

    func_802658E4_de(text + (func_80441FE8_de(field) - 2), D_800DCD80, value);
    return 0;
}
#endif
