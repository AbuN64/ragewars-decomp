#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Points a field's text at D_800D7810 when the option D_80153780 is set and at D_800D7814 otherwise, and returns
   zero: the label an option menu shows for that option. */


extern s32 D_80153780;
extern char D_800D7810[];
extern char D_800D7814[];

s32 func_8040A6A8_de(struct FieldRecAt14 *field) {
    if (D_80153780 != 0) {
        field->text = D_800D7810;
    } else {
        field->text = D_800D7814;
    }
    return 0;
}

/* Loads a text into the block D_8014561C through func_80442574_de from the record's words at 0x1C and
   0x20: from the resource D_44F100 when D_80153780 is set, otherwise from the record's word at 0x24.
   Returns one. */


extern s32 D_80153780;
extern char D_8014561C[];
extern char D_0044E4B0[];
extern void func_80442574_de(void *, void *, s32, s32, s32);

s32 func_8040A6DC_de(void *unused, struct RecordRecAt24 *record) {
    do {
        if (D_80153780 != 0) {
            func_80442574_de(D_8014561C, D_0044E4B0, record->first, record->second, 0);
        } else {
            func_80442574_de(D_8014561C, record->resource, record->first, record->second, 0);
        }
    } while (0);
    return 1;
}

/* Stores 1 in D_80153730 and 0 in D_80153774. */
extern s32 D_80153730;
extern s32 D_80153774;

void func_8040A748_de(void) {
    D_80153730 = 1;
    D_80153774 = 0;
}

/* Stores 0 in D_80153730 and 0 in D_80153774. */
extern s32 D_80153730;
extern s32 D_80153774;

void func_8040A764_de(void) {
    D_80153730 = 0;
    D_80153774 = 0;
}

/* Clears bits 23 and 24 of the flag words at offsets 0xA8 and 0xD0 of the object at offset 0xC
   of a record, clearing D_80153730 and setting D_80153774 between the two. */




extern s32 D_80153730;
extern s32 D_80153774;

void func_8040A77C_de(struct RecordRecAtCV1 *record) {
    record->target->first &= ~0x01800000;
    D_80153730 = 0;
    D_80153774 = 1;
    record->target->second &= ~0x01800000;
}

/* Points a field's text at D_800D77EC when D_80153730 is set, at D_800D77F4 when D_80153774 is set instead, and at
   D_800D77F0 otherwise. Returns zero. */


extern s32 D_80153730;
extern s32 D_80153774;
extern char D_800D77EC[];
extern char D_800D77F4[];
extern char D_800D77F0[];

s32 func_8040A7BC_de(struct FieldRecAt14 *field) {
    if (D_80153730 != 0) {
        field->text = D_800D77EC;
    } else if (D_80153774 != 0) {
        field->text = D_800D77F4;
    } else {
        field->text = D_800D77F0;
    }
    return 0;
}
