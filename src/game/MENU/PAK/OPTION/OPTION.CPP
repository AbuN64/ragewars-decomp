#include "include_asm.h"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "sdk/AUDIO/sprintf.H"

#if !(defined(VERSION_US_REV1))
extern s32 D_801462C8;

/* Toggles bit 0 of the settings flag word D_801462C8 and returns 0. */
s32 Pak_ToggleTextChoice(void) {
    D_801462C8 ^= 1;
    return 0;
}
#endif

#if defined(VERSION_US_REV1)

s32 Pak_ToggleTextChoice(void) {
    D_800E63AC ^= 1;
    return 0;
}
#endif

#if defined(VERSION_US_REV1)
/* Points a field's text at D_800E62DC when the option D_800E63AC is set and at D_800E62F0 otherwise, and returns
   zero: the label an option menu shows for that option. */



extern char D_800E62DC[];
extern char D_800E62F0[];

s32 Pak_UpdateChoiceText(struct FieldRecAt14 *field) {
    if (D_800E63AC != 0) {
        field->text = D_800E62DC;
    } else {
        field->text = D_800E62F0;
    }
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[index] in step, giving a field still at -1 the remembered value and otherwise remembering the field low byte, then mirrors it into D_800CBC94[index] and formats it into the field text with D_800E27D8 three bytes before the length Menu_CountLineChars reports, returning zero. Adapted from Pak_SyncSecondaryByteOptionTwo with the fixed byte slots replaced by the tables D_800CBC90 and D_800CBC94 indexed by the second argument. */



extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern char D_800E27D8[];
extern s32 Menu_CountLineChars(struct Field *);

s32 Pak_SyncPrimaryByteOption(struct Field *field, s32 index) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[index];
    } else {
        D_800CBC90[index] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[index] = D_800CBC90[index];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[0] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[0] and formatted into the field's text with D_800E27D8, three bytes before the length
   Menu_CountLineChars reports. Returns zero. */



s32 Pak_SyncPrimaryByteOptionZero(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[0];
    } else {
        D_800CBC90[0] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[0] = D_800CBC90[0];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[1] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[1] and formatted into the field's text with D_800E27D8, three bytes before the length
   Menu_CountLineChars reports. Returns zero. */



s32 Pak_SyncPrimaryByteOptionOne(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[1];
    } else {
        D_800CBC90[1] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[1] = D_800CBC90[1];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[2] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[2] and formatted into the field's text with D_800E27D8, three bytes before the length
   Menu_CountLineChars reports. Returns zero. */



s32 Pak_SyncPrimaryByteOptionTwo(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[2];
    } else {
        D_800CBC90[2] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[2] = D_800CBC90[2];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[index] in step, giving a field still at -1 the remembered value and otherwise remembering the field low byte, then mirrors it into D_800CBC9C[index] and formats it into the field text with D_800E27D8 three bytes before the length Menu_CountLineChars reports, returning zero. Adapted from Pak_SyncSecondaryByteOptionTwo with the fixed byte slots replaced by the tables D_800D0EE8 and D_800CBC9C indexed by the second argument. */



extern u8 D_800D0EE8[];
extern u8 D_800CBC9C[];

s32 Pak_SyncSecondaryByteOption(struct Field *field, s32 index) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[index];
    } else {
        D_800D0EE8[index] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[index] = D_800D0EE8[index];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[0] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC9C[0] and formatted into the field's text with D_800E27D8, three bytes before the length
   Menu_CountLineChars reports. Returns zero. */



s32 Pak_SyncSecondaryByteOptionZero(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[0];
    } else {
        D_800D0EE8[0] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[0] = D_800D0EE8[0];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[1] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC9C[1] and formatted into the field's text with D_800E27D8, three bytes before the length
   Menu_CountLineChars reports. Returns zero. */



s32 Pak_SyncSecondaryByteOptionOne(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[1];
    } else {
        D_800D0EE8[1] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[1] = D_800D0EE8[1];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EEA[0] in step, giving a field still at -1 the remembered value and otherwise remembering the field's low byte, then mirrors it into D_800D0EEE[0] and formats it into the field's text with D_800E27D8 three bytes before the length Menu_CountLineChars reports, returning zero. Adapted from Pak_SyncPrimaryByteOptionZero. */



extern u8 D_800D0EEA[];
extern u8 D_800D0EEE[];

s32 Pak_SyncSecondaryByteOptionTwo(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EEA[0];
    } else {
        D_800D0EEA[0] = ((u8 *) &field->value)[3];
    }
    D_800D0EEE[0] = D_800D0EEA[0];
    func_802BD320_de(text + (Menu_CountLineChars(field) - 3), D_800E27D8, field->value);
    return 0;
}
#endif
