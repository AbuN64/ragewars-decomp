#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/MENURECAT24.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/EFFECTRENDER.H"
extern void func_802658E4_de(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"
extern s32 D_8015375C;
extern char D_800ED41C[];
extern s32 D_80153734;
extern s32 D_800E28C8;
extern char *D_800D394C[];
extern char *D_800E2FB4[];
extern s32 Pak_CountLineChars(struct Field *);

s32 func_8040B444_de(struct Field *field, Shared_PakMenu *pThis) {
    char *text;
    char **strings;
    s32 value;
    if (D_8015375C != 0) {
        value = D_800E28C8;
    } else {
        value = pThis->owner->unk4;
    }
    if (D_80153734 != 0) {
        field->text = D_800D394C;
    } else {
        strings = D_800E2FB4;
        field->text = strings;
        text = strings[D_801462C8.language];
        func_802658E4_de(text + (Pak_CountLineChars(field) - 2), D_800ED41C, value + 1);
    }
    return 0;
}
#endif

#if !(defined(VERSION_EU) || defined(VERSION_EU_X))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800ED41C[];
#else
#endif
/* Takes D_800E28C8 when D_8015375C is set and otherwise the signed byte at offset 4 of the second argument's record at 0x20, then shows D_800D394C in a field when D_80153734 is set and otherwise points the field at D_800D3958 and formats one more than that value into it with D_800DCD9C two bytes before the length Pak_CountLineChars reports, returning zero.
   Adapted from func_8040A300_de with the value source chosen by D_8015375C, the text chosen by D_80153734, the offset two bytes, and the texts and format changed. */

extern s32 D_8015375C;

extern u8 *D_800D394C[];

extern char g_digitDotFormat[];
extern s32 Pak_CountLineChars(LayeredText *);

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8040B444_de(LayeredText *field, struct Shared_PakMenu *holder) {
    char *text;
    s32 value;

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    u8 **table;

#else
#endif
    if (D_8015375C != 0) {
        value = D_800E28C8;
    } else {
        value = holder->owner->unk4;
    }
    if (D_80153734 != 0) {
        field->text = D_800D394C;
    } else {

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        table = ((u8 **)(void *)D_800E2FB4);
        field->text = table;
        text = (char *)table[g_languageIndex];
#else
        field->text = ((u8 **)(void *)&D_800D3958);
        text = ((char **)(void *)&D_800D3958)[0];
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        func_802658E4_de(text + (Pak_CountLineChars(field) - 2), D_800ED41C, value + 1);
#else
        func_802658E4_de(text + (Pak_CountLineChars(field) - 2), g_digitDotFormat, value + 1);
#endif
    }
    return 0;
}

#endif
#endif
