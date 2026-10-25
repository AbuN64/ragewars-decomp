#include "COMMON/RECORDRECATCV1.H"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_0044E4F8.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "MENU/80409A88.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WORLD.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "stddef.h"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/PAK/80409A88_5.H"
#include "SYSTEM_3/80265370.H"

/* Latches D_80153784 to one when the record's team value is not -1 and both func_802645D0_de and Pak_CheckStatusPrompt accept it, then returns D_80153784. Adapted from func_80409C0C_de with nothing changed (identical code). */






extern s32 D_8015375C;



static inline s32 func_80409BDC_de(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}
extern s32 Pak_CheckStatusPrompt(void *menu, s32 channel, s32 quiet);

/* Latches D_80146D60 and D_800E28CC to one the first time bit 12 of the word at offset 0xB0 of the
   object at 0x20 of a record is seen set, and returns D_80146D60. */








#include "COMMON/GAME_SESSION.H"

extern void func_80293268_de(void *arg0);


/* Calls func_80264788_de on its second argument, then func_8044D528_de on D_8011FE88 with D_8013B2C8
   and 2. */


extern void func_80264788_de(void *);


/* Searches the sixteen controller-pak notes for the requested name and returns the matching index when requested. */
extern void Pak_GetNoteGameName(s32,s32,s32 *),func_80405648_de(s32,void *,s32);


/* Returns the data table for a kind: kinds 1, 2 and 3 have their own, kind 0 and anything else use the
   first. */




/* Picks the pak menu prompt text: in pak mode, when a prompt is due, the text for the channel (D_800E28C8 when D_8015375C is set, else the widget's channel) from four channel texts; otherwise one of two texts in the other mode, or a third text when D_8015375C alone is set, and 0 when none applies. */











/* Finds the next available controller slot with wraparound. */

 /* extern */

s32 func_80409CEC_de(struct Shared_PakMenu *record) {
    if (D_80153784 == 0) {
        if (func_80409BDC_de(record) != -1) {
            if (func_802645D0_de(func_80409BDC_de(record)) != 0) {
                if (Pak_CheckStatusPrompt(record, func_80409BDC_de(record), 0) != 0) {
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

s32 func_80409E10_de(void *menu) {
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
        if ((D_800E28C8 != -1) && (func_802645D0_de(D_800E28C8) != 0) && (Pak_CheckStatusPrompt(menu, D_800E28C8, 0) != 0)) {
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
    Pak_ProbeStatus(value);
}

void func_80409F6C_de(void *unused, void *object) {
    func_80264788_de(object);
    Items_SetSelection(&D_8011FE88, D_8011FE88.selectionValues[3], 2);
}

s32 func_80409FA0_de(void *unused, void *arg1, s32 arg2, s32 *arg3) {
    char game_name[16];
    s32 game_ref;
    s32 note_index;
    for(note_index=0;note_index<16;note_index++) {
        Pak_GetNoteGameName(arg2,note_index,&game_ref);
        func_80405648_de(game_ref,&game_name,16);
        if(Resmgr_CompareStrings(&game_name,arg1)==0) {
            if(arg3) *arg3=note_index;
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

static inline void Pak_GetPromptChannel(struct Shared_PakMenu *menu, s32 *channel) {
    if (D_8015375C != 0) {
        *channel = D_800E28C8;
    } else {
        *channel = menu->owner->unk4;
    }
}

static inline char *Pak_GetChannelPrompt(s32 channel) {
    char *prompt;
    switch (channel) {
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
    return prompt;
}

char *Pak_GetPromptText(struct Shared_PakMenu *menu) {
    s32 channel;
    char *text;

    text = 0;
    if (D_8014D4C0_de != 0) {
        if (D_8014D4EC_de == 0) {
            return text;
        }
        Pak_GetPromptChannel(menu, &channel);
        text = Pak_GetChannelPrompt(channel);
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
s32 Pak_FindNextAvailableChannel(s32 currentChannel) {
    s32 channel = 0;
    s32 attempts;

    if (currentChannel != -1) {
        channel = currentChannel + 1;
        if (channel >= 4) {
            channel = 0;
        }
    }
    attempts = 0;
    do {
        Pak_ProbeStatus(channel);
        if (Pak_GetStatus(channel) != -2) {
            break;
        }
        channel++;
        if (channel >= 4) {
            channel = 0;
        }
        attempts++;
    } while (attempts < 4);
    if (attempts == 4) {
        channel = -1;
    }
    return channel;
}

/* The EU builds compile a different original body for func_8040A244_de; each version keeps its own. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* Shows D_800D3728 in a field when both D_8014D4EC_de and D_8014D4C0_de are set, D_800D372C when only D_8014D4C0_de is, and otherwise, when D_8015375C is set, points the field at D_800D3764 and formats D_800E28C8 plus one into it with D_800DCD7C one byte before the length Pak_CountLineChars reports, returning zero.
   Adapted from func_8044488C_de with the three flag tests, the texts, the format, the offset and the incremented value changed. */


extern s32 D_8015375C;
extern s32 Pak_CountLineChars(struct Field *);

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
        func_802658E4_de(text + (Pak_CountLineChars(field) - 1), g_pakFormatInt1, value + 1);
    }
    return 0;
}

#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* Points an option field at its text: when D_8014D4C0_de is set, D_800D3728 if D_8014D4EC_de is set and D_800D372C if not; otherwise, when D_8015375C is set, the table D_800E27E4, formatting its entry for the byte D_80152789 with D_800ED3FC and D_800E28C8 plus one from one byte before the length Pak_CountLineChars reports; returns zero. */



extern s32 D_8014D4EC_de;
extern s32 D_8014D4C0_de;
extern s32 D_8015375C;
extern char *D_800D3728[];
extern char *D_800D372C[];
extern char *D_800E27E4[];
extern s32 D_800E28C8;
extern char D_800ED3FC[];
extern s32 Pak_CountLineChars(struct Field *);

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
        func_802658E4_de(text + (Pak_CountLineChars(field) - 1), D_800ED3FC, value + 1);
    }
done:
    return 0;
}

#endif
