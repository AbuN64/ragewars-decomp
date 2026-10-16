#include "span_16E000/code_80409A88.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "shared/world.h"
#include "span_1000/code_802636D0.h"
#include "stddef.h"
#include "TYPES.H"
#include "common/unused.h"
#include "shared/func_804220A8_de_closed.h"
#include "span_16E000/code_80405DC0.h"

/* Latches D_80153784 to one when the record's team value is not -1 and both func_802645D0_de and func_80406178_de accept it, then returns D_80153784. Adapted from func_80409C0C_de with nothing changed (identical code). */






extern s32 D_8015375C;



static inline s32 func_80409BDC_de(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}

/* Latches D_80146D60 and D_800E28CC to one the first time bit 12 of the word at offset 0xB0 of the
   object at 0x20 of a record is seen set, and returns D_80146D60. */








extern s32 D_8011FAC0;

extern void func_80293268_de(void *arg0);


/* Calls func_80264788_de on its second argument, then func_8044D528_de on D_8011FE88 with D_8013B2C8
   and 2. */


extern void func_80264788_de(void *);


/* Searches the sixteen controller-pak notes for the requested name and returns the matching index when requested. */
extern void func_80405338_de(s32,s32,s32 *),func_80405648_de(s32,void *,s32);

extern s32 func_802A037C_de(void *,void *);

/* Returns the data table for a kind: kinds 1, 2 and 3 have their own, kind 0 and anything else use the
   first. */




/* Picks the pak menu prompt text: in pak mode, when a prompt is due, the text for the channel (D_800E28C8 when D_8015375C is set, else the widget's channel) from four channel texts; otherwise one of two texts in the other mode, or a third text when D_8015375C alone is set, and 0 when none applies. */





extern char D_0044E4F8[];






/* Finds the next available controller slot with wraparound. */

 /* extern */

s32 func_80409CEC_de(struct Shared_PakMenu *record) {
    extern s32 func_80406178_de(struct Shared_PakMenu *, s32, s32);
    if (D_80153784 == 0) {
        if (func_80409BDC_de(record) != -1) {
            if (func_802645D0_de(func_80409BDC_de(record)) != 0) {
                if (func_80406178_de(record, func_80409BDC_de(record), 0) != 0) {
                    D_80153784 = 1;
                }
            }
        }
    }
    return D_80153784;
}

s32 func_80409DCC_de(struct RecordRecAt20V1 *record) {
    if ((record->inner->unkB0 & 0x1000) && D_800E28CC == 0) {
        D_80146D60 = 1;
        D_800E28CC = 1;
    }
    return D_80146D60;
}

s32 func_80409E10_de(s32 arg0) {
    extern s32 func_80406178_de(s32, s32, s32);
    if (D_80146D60 == 0) {
        func_80293268_de(&D_8011FAC0);
        func_80263C24_de();
        if (D_80146D60 == 0) {
            if (D_8014AD9C != 0) {
                D_8014ADA0 = 1;
            }
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    if (D_80153784 == 0) {
        if ((D_800E28C8 != -1) && (func_802645D0_de(D_800E28C8) != 0) && (func_80406178_de(arg0, D_800E28C8, 0) != 0)) {
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    return D_80153784;
}

s32 func_80409EF4_de(struct RecordRecAt20V2 *record, s32 *out) {
    s32 value;
    s32 result;

    if (D_8015375C != 0) {
        value = D_800E28C8;
        result = 0;
    } else {
        value = record->inner->unk4;
        result = record->result;
    }
    *out = value;
    return result;
}

void func_80409F2C_de(struct Shared_PakMenu *record) {
    s32 value;

    if (D_8015375C != 0) {
        value = D_800E28C8;
    } else {
        value = record->owner->unk4;
    }
    func_80404E28_de(value);
}

void func_80409F6C_de(void *unused, void *object) {
    func_80264788_de(object);
    func_8044D528_de(&D_8011FE88, D_8013B2C8, 2);
}

s32 func_80409FA0_de(void *unused, void *arg1, s32 arg2, s32 *arg3) {
    char sp10[16];
    s32 sp20;
    s32 var_s0;
    for(var_s0=0;var_s0<16;var_s0++) {
        func_80405338_de(arg2,var_s0,&sp20);
        func_80405648_de(sp20,&sp10,16);
        if(func_802A037C_de(&sp10,arg1)==0) {
            if(arg3) *arg3=var_s0;
            return 1;
        }
    }
    return 0;
}

char *func_8040A038_de(int unused, int kind) {
    switch (kind) {
    case 0:
    default:
        return D_00450BF0_de;
    case 1:
        return D_00450C14_de;
    case 2:
        return D_00450C38_de;
    case 3:
        return D_00450C5C_de;
    }
}

char *func_8040A09C_de(struct Shared_PakMenu *menu) {
    s32 channel[2]; /* FAKEMATCH: unused second slot keeps channel in the frame */
    char *text;
    char *prompt; /* FAKEMATCH: copy-only local routes the switch result through its own register before text */

    text = 0;
    if (D_8014D4C0_de != 0) {
        if (D_8014D4EC_de == 0) {
            return text;
        }
        if (D_8015375C != 0) {
            channel[0] = D_800E28C8;
        } else {
            channel[0] = menu->owner->unk4;
        }
        switch (channel[0]) {
        case 0:
        default:
            prompt = D_00450BF0_de;
            break;
        case 1:
            prompt = D_00450C14_de;
            break;
        case 2:
            prompt = D_00450C38_de;
            break;
        case 3:
            prompt = D_00450C5C_de;
            break;
        }
        text = prompt;
    } else if (D_80153760 != 0) {
        text = D_0044FFA4;
        if (D_8014D4EC_de != 0) {
            text = D_0044FB50;
        }
    } else if (D_8015375C != 0) {
        text = D_0044E4F8;
    }
    return text;
}

 /* extern */
s32 func_8040A1B0_de(s32 arg0) {
    s32 var_s0;
    s32 var_s1;
    s32 unavailable;
    var_s0 = 0;
    if (arg0 != -1) {
        var_s0 = arg0 + 1;
        if (var_s0 >= 4) {
            var_s0 = 0;
        }
    }
    var_s1 = 0;
    unavailable = -2;
loop_4:
    func_80404E28_de(var_s0);
    if (func_80404F04_de(var_s0) == unavailable) {
        var_s0 += 1;
        if (var_s0 >= 4) {
            var_s0 = 0;
        }
        var_s1 += 1;
        if (var_s1 < 4) {
            goto loop_4;
        }
    }
    if (var_s1 == 4) {
        var_s0 = -1;
    }
    return var_s0;
}

/* FAKEMATCH: version selection preserves distinct original same-start bodies mapped to this live identity; only one original body is compiled for each owning version. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* Shows D_800D3728 in a field when both D_8014D4EC_de and D_8014D4C0_de are set, D_800D372C when only D_8014D4C0_de is, and otherwise, when D_8015375C is set, points the field at D_800D3764 and formats D_800E28C8 plus one into it with D_800DCD7C one byte before the length func_80441FE8_de reports, returning zero.
   Adapted from func_8044488C_de with the three flag tests, the texts, the format, the offset and the incremented value changed. */


extern s32 D_8015375C;
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A244_de(struct Field *field) {
    char *text;
    s32 value;

    if (D_8014D4EC_de != 0 && D_8014D4C0_de != 0) {
        field->text = D_800D3728;
    } else if (D_8014D4EC_de == 0 && D_8014D4C0_de != 0) {
        field->text = D_800D372C;
    } else if (D_8015375C != 0) {
        value = D_800E28C8;
        field->text = D_800D3764;
        text = D_800D3764[0];
        func_802658E4_de(text + (func_80441FE8_de(field) - 1), D_800DCD7C, value + 1);
    }
    return 0;
}

#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* Points an option field at its text: when D_8014D4C0_de is set, D_800D3728 if D_8014D4EC_de is set and D_800D372C if not; otherwise, when D_8015375C is set, the table D_800E27E4, formatting its entry for the byte D_80152789 with D_800ED3FC and D_800E28C8 plus one from one byte before the length func_80441FE8_de reports; returns zero. */



extern s32 D_8014D4EC_de;
extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern char *D_800D3728[];
extern char *D_800D372C[];
extern char *D_800E27E4[];
extern u8 D_80152789;
extern s32 D_800E28C8;
extern char D_800ED3FC[];
extern s32 func_80441FE8_de(struct Field *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_8040A244_de(struct Field *field) {
    char **table;
    char *text;
    s32 value;

    if (D_8014D4EC_de != 0) {
        if (D_8014D4C0_de != 0) {
            field->text = D_800D3728;
            goto done;
        }
    } else if (D_8014D4C0_de != 0) {
        field->text = D_800D372C;
        goto done;
    }
    if (D_8015375C != 0) {
        do {
            table = D_800E27E4;
        } while (0);
        field->text = table;
        value = D_800E28C8;
        text = table[D_80152789];
        func_802658E4_de(text + (func_80441FE8_de(field) - 1), D_800ED3FC, value + 1);
    }
done:
    return 0;
}

#endif
