#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/RECORDRECATCV1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
extern void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"
extern s32 D_8015375C;
extern char *D_800D7E14[];
extern s32 Pak_CountLineChars(struct Field *);

s32 func_8040A300_de(struct Field *field, Shared_PakMenu *pThis) {
    char *text;
    char **strings;
    s32 value;
    if (D_8015375C != 0) {
        field->text = D_800D7E14;
    } else {
        value = pThis->owner->unk4;
        strings = D_800E25E4;
        field->text = strings;
        text = strings[D_801462C8.language];
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 1), D_800ED3FC, value + 1);
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
/* Uses the fixed option text while the mode flag is set. Otherwise formats
 * one more than the holder's signed option byte into the editable text,
 * one byte before the length returned by the item text helper. */
extern s32 D_8015375C;
extern u8 *D_800D7E14[];
extern s32 Pak_CountLineChars(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040A300_de(LayeredText *field, struct Shared_PakMenu *holder) {
    char *text;
    s32 value;
    if (D_8015375C != 0) {
        field->text = D_800D7E14;
    } else {
        value = holder->owner->unk4;
        field->text = (u8 **)&D_800D36E4;
        text = (char *)*(u8 **)&D_800D36E4;
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 1),
                        g_pakFormatInt1, value + 1);
    }
    return 0;
}

#endif
#endif
