#include "COMMON/RECORDRECATCV1.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "MENU/80409A88.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
extern PakPreview *D_800E28BC;
#include "COMMON/UNUSED.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/PAK/TIMER_UPDATEOPERATIONCHOICELABEL.H"
#include "SYSTEM/DEFS.H"

extern s32 D_8015375C;









extern char *D_800D7E14[];


/* Sets D_80153780 to one; Timer_DisableAlternatePrompt clears it. */



/* Points the output record's table at 0x14 at the variant for the display depth at 0x90 of
   D_800E28BC: 16 and 32 have their own, 8 and anything else use the default; returns 0. */









#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Formats the word at offset 0x1C of the structure D_800E28BC points to, shifted down eight bits,
   into a field's text with the format D_800E0DA4, three bytes before the length Menu_CountLineChars
   reports, and returns zero. */







extern s32 Menu_CountLineChars(struct Field *);


/* Selects a menu field's label table from the connection mode and the option index. */
s32 Timer_UpdateOperationChoiceLabel(struct Field *field, s16 *option_ptr) {
    s32 option;
    u32 rel;

    option = *option_ptr;
    rel = option - 3;
    if (D_80153760 != 0) {
        if (D_8014D4EC_de != 0) {
            field->text = D_800D373C;
        } else {
            field->text = D_800D3744;
        }
        goto done;
    }
    if (D_8014D4C0_de != 0) {
        if (rel < 16) {
            field->text = D_800D3750;
            return 0;
        }
        if (option == 0x15) {
            field->text = D_800D7E14;
        } else if (D_8014D4EC_de != 0) {
            field->text = D_800D3740;
        } else {
            field->text = D_800D3748;
        }
        goto done;
    }
    if (D_8015375C != 0) {
        field->text = D_800D3760;
    }
done:
    return 0;
}

s32 Timer_SetManagerHeading(struct ObjRecAt14V1 *record) {
    if (D_8015375C != 0) {
        record->unk14 = D_800D7794;
    }
    return 0;
}

void Timer_EnableAlternatePrompt(void) {
    D_80153780 = 1;
}

void Timer_DisableAlternatePrompt(void) {
    D_80153780 = 0;
}

s32 Timer_UpdateAlternatePromptLabel(struct FieldRecAt14 *field) {
    if (D_80153780 != 0) {
        field->text = g_pakNoteLabelSlots;
    } else {
        field->text = D_800D77D0;
    }
    return 0;
}

int Timer_UpdatePreviewDepthLabel(ObjRecAt14V1 *out) {
    switch (D_800E28BC->depth) {
    case 8:
    default:
        out->unk14 = &D_800D37A8;
        break;
    case 16:
        out->unk14 = &D_800D37AC;
        break;
    case 32:
        out->unk14 = &D_800D37B0;
        break;
    }
    return 0;
}

s32 Timer_FormatPreviewPageCount(struct Field *field) {
    s32 value = D_800E28BC->value >> 8;
    char *text =
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text[g_languageIndex];
#else
        *field->text;
#endif

    Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 3), g_pakFormatInt3, value);
    return 0;
}
