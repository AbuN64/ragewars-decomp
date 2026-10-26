#include "COMMON/RECORDRECATCV1.H"
#include "COMMON/LONE/D_0044E468.H"
#include "COMMON/LONE/D_80152789.H"
#include "MENU/PAK_LOAD.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/ITEMRECAT24.H"
#include "COMMON/TEXTLAYERMETRICS.H"
#include "MENU/PAK/80409A88.H"
#include "SYSTEM_3/80265370.H"
#include "COMMON/NODERECAT2A8.H"
#include "include_asm.h"
#include "COMMON/TRIPLE.H"
#include "COMMON/EFFECTRENDER.H"

extern s32 D_80153788;

/* Formats the score into the last four characters of the item's text and returns zero.
   PAL items select their text using the current language. */

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u16 D_8015D48C;
extern char D_800ED414[];
#else
#endif

extern s32 Pak_CountLineChars(LayeredText *);


/* Draws an item's label at its position into the text layer D_8014561C through Pak_OpenDialog, using
   the fixed label D_44F0B8 instead of the item's own when D_80153730 is set; returns 1. */


extern char D_8014561C[];


extern void Pak_OpenDialog(char *, char *, int, int, int);

/* Clears the word held in D_80153788. */


/* Sets the state word D_80153788 to 1; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 2; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 3; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 4; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 5; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 6; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 7; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Clears bit 26 and sets bit 3 of the flag word at offset 0x120 of the object at offset 0xC of a
   record, stores 8 in the state word D_80153788 between the two, and calls func_802649FC_de. */






/* Stores 9 in D_80153788 and 0 in D_80153758. */


/* Stores 9 in the state word D_80153788 and one in D_80153758; func_8040ABA0_de stores 9 and zero. */


/* Sets the state word D_80153788 to 0xA; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 0xB; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 0xC; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 0xD; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 0xE; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Sets the state word D_80153788 to 0xF; this is one of a run of functions that each store one
   state number there, and func_8040AAB8_de clears it. */


/* Points a field's text at the label for the state word D_80153788: the second string through the jump table
   jtbl_800E0E48 for states 0 to 15, and D_800D781C for any other state. Returns zero. An earlier attempt misjudged this switch as a dispatch head whose
   cases lay outside the interval; its case bodies are inside it. */




/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0E88 for states 0 to 15, and D_800D782C for any other state. Returns zero. */




/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0EC8 for states 0 to 15, and D_800D7830 for any other state. Returns zero. */




/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0F08 for states 0 to 15, and D_800D7834 for any other state. Returns zero. */




/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0F48 for states 0 to 15, and D_800D7838 for any other state. Returns zero. */




/* Points a field's text at the label for the state word D_80153788: one of 15 strings through the jump table
   jtbl_800E0F88 for states 0 to 15, and D_800D783C for any other state. Returns zero. */




/* Points a field's text at the label for the state word D_80153788: the second string through the jump table
   jtbl_800E0FC8 for states 0 to 15, and D_800D7824 for any other state. Returns zero. An earlier attempt misjudged this switch as a dispatch head whose
   cases lay outside the interval; its case bodies are inside it. */




/* Latches D_80153768 to one when the record's team value is not -1 and both func_802645D0_de and Pak_CheckStatusPrompt accept it, then returns D_80153768. Adapted from Pak_CheckMenuPakChange with the latch D_80153784 changed to D_80153768. */





extern s32 D_8015375C;

extern s32 Pak_CheckStatusPrompt(struct Shared_PakMenu *, s32, s32);

static inline s32 Pak_GetMenuChannel(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}

s32 func_8040A9A0_de(LayeredText *field) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    s32 value = D_8015D48C;
    char *text = (char *)field->text[g_languageIndex];

    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), D_800ED414, value);
#else
    s32 value = D_8014D488.values[2];
    char *text = (char *)*field->text;

    Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 4), g_pakFormatInt04, value);
#endif
    return 0;
}

/* Points a field's text at D_800D7810 when D_80153730 is set, at D_800D7818 when D_80153774 is set instead, and at
   D_800D7814 otherwise. Returns zero. */



s32 func_8040A9F8_de(struct FieldRecAt14 *field) {
    if (D_80153730 != 0) {
        field->text = D_800D7810;
    } else if (D_80153774 != 0) {
        field->text = D_800D7818;
    } else {
        field->text = D_800D7814;
    }
    return 0;
}

int func_8040AA4C_de(int unused, ItemRecAt24 *item) {
    if (D_80153730 != 0) {
        Pak_OpenDialog(D_8014561C, D_0044E468, item->x, item->y, 0);
    } else {
        Pak_OpenDialog(D_8014561C, item->label, item->x, item->y, 0);
    }
    return 1;
}

void func_8040AAB8_de(void) {
    D_80153788 = 0;
}

void func_8040AAC8_de(void) {
    D_80153788 = 1;
}

void func_8040AADC_de(void) {
    D_80153788 = 2;
}

void func_8040AAF0_de(void) {
    D_80153788 = 3;
}

void func_8040AB04_de(void) {
    D_80153788 = 4;
}

void func_8040AB18_de(void) {
    D_80153788 = 5;
}

void func_8040AB2C_de(void) {
    D_80153788 = 6;
}

void func_8040AB40_de(void) {
    D_80153788 = 7;
}

void func_8040AB54_de(struct RecordRecAtCV3 *record) {
    record->target->flags &= ~0x04000000;
    D_80153788 = 8;
    record->target->flags |= 8;
    func_802649FC_de();
}

void func_8040ABA0_de(void) {
    D_80153788 = 9;
    D_80153758 = 0;
}

void func_8040ABBC_de(void) {
    D_80153788 = 9;
    D_80153758 = 1;
}

void func_8040ABDC_de(void) {
    D_80153788 = 0xA;
}

void func_8040ABF0_de(void) {
    D_80153788 = 0xB;
}

void func_8040AC04_de(void) {
    D_80153788 = 0xC;
}

void func_8040AC18_de(void) {
    D_80153788 = 0xD;
}

void func_8040AC2C_de(void) {
    D_80153788 = 0xE;
}

void func_8040AC40_de(void) {
    D_80153788 = 0xF;
}

s32 func_8040AC54_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto state_other;
        case 2: goto state_other;
        case 3: goto state_other;
        case 4: goto state_other;
        case 5: goto case_1;
        case 6: goto case_1;
        case 7: goto state_other;
        case 8: goto state_other;
        case 9: goto case_1;
        case 10: goto case_1;
        case 11: goto state_other;
        case 12: goto case_1;
        case 13: goto state_other;
        case 14: goto state_other;
        case 15: goto case_1;
        }
state_other:
    field->text = D_800D781C;
    goto done;
case_1:
    field->text = D_800D37F4;
done:
    return 0;
}

s32 func_8040ACA0_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D782C;
    goto done;
case_1:
    field->text = D_800D3814;
    goto done;
case_2:
    field->text = D_800D3828;
    goto done;
case_3:
    field->text = D_800D3850;
    goto done;
case_4:
    field->text = D_800D383C;
    goto done;
case_5:
    field->text = D_800D3864;
    goto done;
case_6:
    field->text = D_800D3878;
    goto done;
case_7:
    field->text = D_800D388C;
    goto done;
case_8:
    field->text = D_800D38A0;
    goto done;
case_9:
    field->text = D_800D38B4;
    goto done;
case_10:
    field->text = D_800D38C8;
    goto done;
case_11:
    field->text = D_800D38DC;
    goto done;
case_12:
    field->text = D_800D38F0;
    goto done;
case_13:
    field->text = D_800D3904;
    goto done;
case_14:
    field->text = D_800D3918;
    goto done;
case_15:
    field->text = D_800D392C;
done:
    return 0;
}

s32 func_8040ADCC_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D7830;
    goto done;
case_1:
    field->text = D_800D3818;
    goto done;
case_2:
    field->text = D_800D382C;
    goto done;
case_3:
    field->text = D_800D3854;
    goto done;
case_4:
    field->text = D_800D3840;
    goto done;
case_5:
    field->text = D_800D3868;
    goto done;
case_6:
    field->text = D_800D387C;
    goto done;
case_7:
    field->text = D_800D3890;
    goto done;
case_8:
    field->text = D_800D38A4;
    goto done;
case_9:
    field->text = D_800D38B8;
    goto done;
case_10:
    field->text = D_800D38CC;
    goto done;
case_11:
    field->text = D_800D38E0;
    goto done;
case_12:
    field->text = D_800D38F4;
    goto done;
case_13:
    field->text = D_800D3908;
    goto done;
case_14:
    field->text = D_800D391C;
    goto done;
case_15:
    field->text = D_800D3930;
done:
    return 0;
}

s32 func_8040AEF8_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D7834;
    goto done;
case_1:
    field->text = D_800D381C;
    goto done;
case_2:
    field->text = D_800D3830;
    goto done;
case_3:
    field->text = D_800D3858;
    goto done;
case_4:
    field->text = D_800D3844;
    goto done;
case_5:
    field->text = D_800D386C;
    goto done;
case_6:
    field->text = D_800D3880;
    goto done;
case_7:
    field->text = D_800D3894;
    goto done;
case_8:
    field->text = D_800D38A8;
    goto done;
case_9:
    field->text = D_800D38BC;
    goto done;
case_10:
    field->text = D_800D38D0;
    goto done;
case_11:
    field->text = D_800D38E4;
    goto done;
case_12:
    field->text = D_800D38F8;
    goto done;
case_13:
    field->text = D_800D390C;
    goto done;
case_14:
    field->text = D_800D3920;
    goto done;
case_15:
    field->text = D_800D3934;
done:
    return 0;
}

s32 func_8040B024_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D7838;
    goto done;
case_1:
    field->text = D_800D3820;
    goto done;
case_2:
    field->text = D_800D3834;
    goto done;
case_3:
    field->text = D_800D385C;
    goto done;
case_4:
    field->text = D_800D3848;
    goto done;
case_5:
    field->text = D_800D3870;
    goto done;
case_6:
    field->text = D_800D3884;
    goto done;
case_7:
    field->text = D_800D3898;
    goto done;
case_8:
    field->text = D_800D38AC;
    goto done;
case_9:
    field->text = D_800D38C0;
    goto done;
case_10:
    field->text = D_800D38D4;
    goto done;
case_11:
    field->text = D_800D38E8;
    goto done;
case_12:
    field->text = D_800D38FC;
    goto done;
case_13:
    field->text = D_800D3910;
    goto done;
case_14:
    field->text = D_800D3924;
    goto done;
case_15:
    field->text = D_800D3938;
done:
    return 0;
}

s32 func_8040B150_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto case_1;
        case 2: goto case_2;
        case 3: goto case_3;
        case 4: goto case_4;
        case 5: goto case_5;
        case 6: goto case_6;
        case 7: goto case_7;
        case 8: goto case_8;
        case 9: goto case_9;
        case 10: goto case_10;
        case 11: goto case_11;
        case 12: goto case_12;
        case 13: goto case_13;
        case 14: goto case_14;
        case 15: goto case_15;
        }
state_other:
    field->text = D_800D783C;
    goto done;
case_1:
    field->text = D_800D3824;
    goto done;
case_2:
    field->text = D_800D3838;
    goto done;
case_3:
    field->text = D_800D3860;
    goto done;
case_4:
    field->text = D_800D384C;
    goto done;
case_5:
    field->text = D_800D3874;
    goto done;
case_6:
    field->text = D_800D3888;
    goto done;
case_7:
    field->text = D_800D389C;
    goto done;
case_8:
    field->text = D_800D38B0;
    goto done;
case_9:
    field->text = D_800D38C4;
    goto done;
case_10:
    field->text = D_800D38D8;
    goto done;
case_11:
    field->text = D_800D38EC;
    goto done;
case_12:
    field->text = D_800D3900;
    goto done;
case_13:
    field->text = D_800D3914;
    goto done;
case_14:
    field->text = D_800D3928;
    goto done;
case_15:
    field->text = D_800D393C;
done:
    return 0;
}

s32 func_8040B27C_de(struct FieldRecAt14 *field) {
    u32 state = D_80153788;

    if (state >= 16) {
        goto state_other;
    }
    switch (state) {
        case 0: goto state_other;
        case 1: goto state_other;
        case 2: goto state_other;
        case 3: goto state_other;
        case 4: goto state_other;
        case 5: goto state_other;
        case 6: goto state_other;
        case 7: goto state_other;
        case 8: goto case_1;
        case 9: goto state_other;
        case 10: goto state_other;
        case 11: goto state_other;
        case 12: goto state_other;
        case 13: goto state_other;
        case 14: goto state_other;
        case 15: goto state_other;
        }
state_other:
    field->text = D_800D7824;
    goto done;
case_1:
    field->text = D_800D37FC;
done:
    return 0;
}

s32 func_8040B2C8_de(struct Shared_PakMenu *record) {
    if (D_80153768 == 0) {
        if (Pak_GetMenuChannel(record) != -1) {
            if (Control_PeekPakChange(Pak_GetMenuChannel(record)) != 0) {
                if (Pak_CheckStatusPrompt(record, Pak_GetMenuChannel(record), 0) != 0) {
                    D_80153768 = 1;
                }
            }
        }
    }
    return D_80153768;
}

/* Stores 0 in D_80153768 and 1 in D_80153734. */

void func_8040B3A8_de(void) {
    D_80153768 = 0;
    D_80153734 = 1;
}

/* Stores 0 in D_80153768 and 0 in D_80153734. */

void func_8040B3C4_de(void) {
    D_80153768 = 0;
    D_80153734 = 0;
}

/* Points a field's text at D_800D7970 when the option D_80153734 is set and at D_800D797C otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_8040B3DC_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7970;
    } else {
        field->text = D_800D797C;
    }
    return 0;
}

/* Points a field's text at D_800D7974 when the option D_80153734 is set and at D_800D7980 otherwise, and returns
   zero: the label an option menu shows for that option. */



s32 func_8040B410_de(struct FieldRecAt14 *field) {
    if (D_80153734 != 0) {
        field->text = D_800D7974;
    } else {
        field->text = D_800D7980;
    }
    return 0;
}

extern void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value);

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#include "COMMON/PAK_MENU.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "SYSTEM_3/80265370.H"
extern s32 D_8015375C;
extern char D_800ED41C[];
extern char *D_800D394C[];
extern s32 Pak_CountLineChars(LayeredText *);

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
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2), D_800ED41C, value + 1);
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
   Adapted from Pak_UpdateOwnerChannelLabel with the value source chosen by D_8015375C, the text chosen by D_80153734, the offset two bytes, and the texts and format changed. */

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
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2), D_800ED41C, value + 1);
#else
        Defs_FormatIntegerValue(text + (Pak_CountLineChars(field) - 2), g_digitDotFormat, value + 1);
#endif
    }
    return 0;
}

#endif
#endif
