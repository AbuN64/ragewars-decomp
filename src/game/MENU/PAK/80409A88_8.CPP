#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "TYPES.H"
#include "COMMON/MENURECAT20V1.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RECORDRECATCV1.H"
#include "SYSTEM_3/80265370.H"

/* Formats the halfword at offset 0x22 of the structure D_800E28BC points to into a field's text
   (the current menu language's text in the EU builds) with the format string, two bytes before
   the length Pak_CountLineChars reports, and returns zero. */

struct PreviewTextValue { char pad[0x22]; s16 value; };

extern struct PreviewTextValue *D_800E28BC;
extern s32 Pak_CountLineChars(struct Field *);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800ED400[];
#define PREVIEW_VALUE_FORMAT D_800ED400
#else
#define PREVIEW_VALUE_FORMAT D_800DCD80
#endif

s32 func_8040A58C_de(struct Field *field) {
    s32 value = D_800E28BC->value;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    char *text = field->text[D_80152789];
#else
    char *text = *field->text;
#endif

    func_802658E4_de(text + (Pak_CountLineChars(field) - 2), PREVIEW_VALUE_FORMAT, value);
    return 0;
}
