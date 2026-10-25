#include "COMMON/RECORDRECATCV1.H"
#include "COMMON/LONE/D_0044E4B0.H"
#include "MENU/80409A88.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
extern PakPreview *D_800E28BC;
#include "MENU/PAK/80409A88_9.H"
#include "SYSTEM_3/80265370.H"

/* Calls func_802B2378 on the word at offset 0x24 of the structure D_800E28BC points to and
   returns zero. */




#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_802B2378(s32);
#else
extern void func_802AD2A8(s32);
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800ED404_eu[];

#else
#endif


extern s32 func_80441FE8_de(struct Field *);


/* Points a field's text at D_800D7810 when the option D_80153780 is set and at D_800D7814 otherwise, and returns
   zero: the label an option menu shows for that option. */





extern char D_8014561C[];


extern void Pak_OpenDialog(void *, void *, s32, s32, s32);

/* Stores 1 in D_80153730 and 0 in D_80153774. */
extern s32 D_80153730;





s32 func_8040A5E8_de(void) {
    
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_802B2378
#else
func_802AD2A8
#endif
(D_800E28BC->handle);
    return 0;
}

/* Formats the three floats at offsets 0xC, 0x10 and 0x14 of the structure D_800E28BC points to,
   truncated to integers, into a field's text with the format D_800DCD84, nine bytes before the
   length func_80441FE8_de reports. Returns zero. */

s32 func_8040A614_de(struct Field *field) {
    s32 x = D_800E28BC->x;
    s32 y = D_800E28BC->y;
    s32 z = D_800E28BC->z;
    char *text =

#if defined(VERSION_EU) || defined(VERSION_EU_X)
        field->text[D_80152789];
#else
        *field->text;
#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
    func_8026591C_de(text + (func_80441FE8_de(field) - 9), D_800ED404_eu, z, y, x);
#else
    func_8026591C_de(text + (func_80441FE8_de(field) - 9), D_800DCD84, z, y, x);
#endif
    return 0;
}

s32 func_8040A6A8_de(struct FieldRecAt14 *field) {
    if (D_80153780 != 0) {
        field->text = D_800D7810;
    } else {
        field->text = D_800D7814;
    }
    return 0;
}

s32 func_8040A6DC_de(void *unused, struct RecordRecAt24 *record) {
    do {
        if (D_80153780 != 0) {
            Pak_OpenDialog(D_8014561C, D_0044E4B0, record->first, record->second, 0);
        } else {
            Pak_OpenDialog(D_8014561C, record->resource, record->first, record->second, 0);
        }
    } while (0);
    return 1;
}

void func_8040A748_de(void) {
    D_80153730 = 1;
    D_80153774 = 0;
}

void func_8040A764_de(void) {
    D_80153730 = 0;
    D_80153774 = 0;
}

void func_8040A77C_de(struct RecordRecAtCV1 *record) {
    record->target->first &= ~0x01800000;
    D_80153730 = 0;
    D_80153774 = 1;
    record->target->second &= ~0x01800000;
}

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
