#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT20V1.H"
#include "TYPES.H"
#include "SDK/AUDIO/802BD1A8_19.H"

#if defined(VERSION_US_REV1)
/* Points a field's text at D_800E62DC when the option D_800E63AC is set and at D_800E62F0 otherwise, and returns
   zero: the label an option menu shows for that option. */



extern char D_800E62DC[];
extern char D_800E62F0[];

s32 func_804453E0_us_rev1(struct FieldRecAt14 *field) {
    if (D_800E63AC != 0) {
        field->text = D_800E62DC;
    } else {
        field->text = D_800E62F0;
    }
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[index] in step, giving a field still at -1 the remembered value and otherwise remembering the field low byte, then mirrors it into D_800CBC94[index] and formats it into the field text with D_800E27D8 three bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_80445824_us_rev1 with the fixed byte slots replaced by the tables D_800CBC90 and D_800CBC94 indexed by the second argument. */



extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445414_us_rev1(struct Field *field, s32 index) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[index];
    } else {
        D_800CBC90[index] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[index] = D_800CBC90[index];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[0] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[0] and formatted into the field's text with D_800E27D8, three bytes before the length
   func_80441FE8_de reports. Returns zero. */


extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_804454B4_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[0];
    } else {
        D_800CBC90[0] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[0] = D_800CBC90[0];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[1] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[1] and formatted into the field's text with D_800E27D8, three bytes before the length
   func_80441FE8_de reports. Returns zero. */


extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445544_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[1];
    } else {
        D_800CBC90[1] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[1] = D_800CBC90[1];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800CBC90[2] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC94[2] and formatted into the field's text with D_800E27D8, three bytes before the length
   func_80441FE8_de reports. Returns zero. */


extern u8 D_800CBC90[];
extern u8 D_800CBC94[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_804455D4_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800CBC90[2];
    } else {
        D_800CBC90[2] = ((u8 *) &field->value)[3];
    }
    D_800CBC94[2] = D_800CBC90[2];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[index] in step, giving a field still at -1 the remembered value and otherwise remembering the field low byte, then mirrors it into D_800CBC9C[index] and formats it into the field text with D_800E27D8 three bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_80445824_us_rev1 with the fixed byte slots replaced by the tables D_800D0EE8 and D_800CBC9C indexed by the second argument. */



extern u8 D_800D0EE8[];
extern u8 D_800CBC9C[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445664_us_rev1(struct Field *field, s32 index) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[index];
    } else {
        D_800D0EE8[index] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[index] = D_800D0EE8[index];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[0] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC9C[0] and formatted into the field's text with D_800E27D8, three bytes before the length
   func_80441FE8_de reports. Returns zero. */


extern u8 D_800D0EE8[];
extern u8 D_800CBC9C[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445704_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[0];
    } else {
        D_800D0EE8[0] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[0] = D_800D0EE8[0];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EE8[1] in step: a field still at -1 takes the
   remembered value, otherwise the field's low byte is remembered; the value is mirrored into
   D_800CBC9C[1] and formatted into the field's text with D_800E27D8, three bytes before the length
   func_80441FE8_de reports. Returns zero. */


extern u8 D_800D0EE8[];
extern u8 D_800CBC9C[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445794_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EE8[1];
    } else {
        D_800D0EE8[1] = ((u8 *) &field->value)[3];
    }
    D_800CBC9C[1] = D_800D0EE8[1];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}

/* Keeps an option field and the remembered byte D_800D0EEA[0] in step, giving a field still at -1 the remembered value and otherwise remembering the field's low byte, then mirrors it into D_800D0EEE[0] and formats it into the field's text with D_800E27D8 three bytes before the length func_80441FE8_de reports, returning zero. Adapted from func_804454B4_us_rev1. */



extern u8 D_800D0EEA[];
extern u8 D_800D0EEE[];
extern char D_800E27D8[];
extern s32 func_80441FE8_de(struct Field *);

s32 func_80445824_us_rev1(struct Field *field) {
    char *text = *field->text;

    if (field->value == -1) {
        field->value = D_800D0EEA[0];
    } else {
        D_800D0EEA[0] = ((u8 *) &field->value)[3];
    }
    D_800D0EEE[0] = D_800D0EEA[0];
    func_802BD320_de(text + (func_80441FE8_de(field) - 3), D_800E27D8, field->value);
    return 0;
}
#endif
