#include "COMMON/RECORDRECATCV1.H"
#include "COMMON/LONE/D_0044E4B0.H"
#include "MENU/80409A88.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
extern PakPreview *D_800E28BC;
#include "MENU/PAK/80409A88_9.H"
#include "SYSTEM/DEFS.H"
#include "MENU/PAK/TIMER.H"

/* Calls Menu_ClassifyResourceRange on the word at offset 0x24 of the structure D_800E28BC points to and
   returns zero. */




#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void Menu_ClassifyResourceRange(s32);
#else
extern void Pickup_ClassifyMenuCode(s32);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)

#else
#endif


extern s32 Menu_CountLineChars(struct Field *);


/* Points a field's text at D_800D7810 when the option D_80153780 is set and at D_800D7814 otherwise, and returns
   zero: the label an option menu shows for that option. */





extern char D_8014561C[];


extern void Menu_OpenDialog(void *, void *, s32, s32, s32);

/* Stores 1 in D_80153730 and 0 in D_80153774. */





s32 Timer_DispatchPreviewHandle(void) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
Menu_ClassifyResourceRange
#else
Pickup_ClassifyMenuCode
#endif
(D_800E28BC->handle);
    return 0;
}

/* Formats the three floats at offsets 0xC, 0x10 and 0x14 of the structure D_800E28BC points to,
   truncated to integers, into a field's text with the format D_800DCD84, nine bytes before the
   length Menu_CountLineChars reports. Returns zero. */

s32 Timer_FormatPreviewDottedTriple(struct Field *field) {
    s32 x = D_800E28BC->x;
    s32 y = D_800E28BC->y;
    s32 z = D_800E28BC->z;
    char *text =

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text[g_languageIndex];
#else
        *field->text;
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    Defs_FormatThreeIntegers(text + (Menu_CountLineChars(field) - 9), D_800ED404_eu, z, y, x);
#else
    Defs_FormatThreeIntegers(text + (Menu_CountLineChars(field) - 9), g_pakFormatDottedTriple, z, y, x);
#endif
    return 0;
}

s32 Timer_UpdateAlternateActionLabel(struct FieldRecAt14 *field) {
    if (D_80153780 != 0) {
        field->text = D_800D7810;
    } else {
        field->text = D_800D7814;
    }
    return 0;
}

s32 Timer_OpenSelectedPrompt(void *unused, struct RecordRecAt24 *record) {
    do {
        if (D_80153780 != 0) {
            Menu_OpenDialog(D_8014561C, D_0044E4B0, record->first, record->second, 0);
        } else {
            Menu_OpenDialog(D_8014561C, record->resource, record->first, record->second, 0);
        }
    } while (0);
    return 1;
}

void Timer_EnableProfilePreview(void) {
    D_80153730 = 1;
    D_80153774 = 0;
}

void Timer_ClearProfilePreview(void) {
    D_80153730 = 0;
    D_80153774 = 0;
}

void Timer_DisablePreviewSelection(struct RecordRecAtCV1 *record) {
    record->target->first &= ~0x01800000;
    D_80153730 = 0;
    D_80153774 = 1;
    record->target->second &= ~0x01800000;
}

s32 Timer_UpdatePreviewKindLabel(struct FieldRecAt14 *field) {
    if (D_80153730 != 0) {
        field->text = D_800D77EC;
    } else if (D_80153774 != 0) {
        field->text = D_800D77F4;
    } else {
        field->text = D_800D77F0;
    }
    return 0;
}
