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
#include "SYSTEM/80265370.H"

/* Latches D_80153784 to one when the record's team value is not -1 and both func_802645D0_de and Snapshot_CheckStatusPrompt accept it, then returns D_80153784. Adapted from Timer_CheckMenuPakChange with nothing changed (identical code). */






extern s32 D_8015375C;



static inline s32 Pak_GetMenuChannel(struct Shared_PakMenu *record) {
    if (D_8015375C != 0) {
        return D_800E28C8;
    }
    return record->owner->unk4;
}
extern s32 Snapshot_CheckStatusPrompt(void *menu, s32 channel, s32 quiet);

/* Latches D_80146D60 and D_800E28CC to one the first time bit 12 of the word at offset 0xB0 of the
   object at 0x20 of a record is seen set, and returns D_80146D60. */








#include "COMMON/GAME_SESSION.H"

extern void SetN64_CommitSessionInputs(void *arg0);


/* Calls func_80264788_de on its second argument, then func_8044D528_de on D_8011FE88 with D_8013B2C8
   and 2. */


extern void Control_DisableControllerPak(void *);


/* Searches the sixteen controller-pak notes for the requested name and returns the matching index when requested. */
extern void Note_GetNoteGameName(s32,s32,s32 *),Note_DecodeNoteText(s32,void *,s32);


/* Returns the data table for a kind: kinds 1, 2 and 3 have their own, kind 0 and anything else use the
   first. */




/* Picks the pak menu prompt text: in pak mode, when a prompt is due, the text for the channel (D_800E28C8 when D_8015375C is set, else the widget's channel) from four channel texts; otherwise one of two texts in the other mode, or a third text when D_8015375C alone is set, and 0 when none applies. */











/* Finds the next available controller slot with wraparound. */

 /* extern */

s32 Timer_CheckChangedMenuChannel(struct Shared_PakMenu *record) {
    if (D_80153784 == 0) {
        if (Pak_GetMenuChannel(record) != -1) {
            if (Control_PeekPakChange(Pak_GetMenuChannel(record)) != 0) {
                if (Snapshot_CheckStatusPrompt(record, Pak_GetMenuChannel(record), 0) != 0) {
                    D_80153784 = 1;
                }
            }
        }
    }
    return D_80153784;
}

s32 Timer_LatchControllerRequest(struct RecordRecAt20V1 *record) {
    if ((record->inner->unkB0 & 0x1000) && D_800E28CC == 0) {
        D_80146D60 = 1;
        D_800E28CC = 1;
    }
    return D_80146D60;
}

s32 Timer_UpdateManagerStatus(void *menu) {
    if (D_80146D60 == 0) {
        SetN64_CommitSessionInputs(&D_8011FAC0);
        Control_TrackControllerPakChanges();
        if (D_80146D60 == 0) {
            if (D_8014AD9C != 0) {
                D_8014ADA0 = 1;
            }
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    if (D_80153784 == 0) {
        if ((D_800E28C8 != -1) && (Control_PeekPakChange(D_800E28C8) != 0) && (Snapshot_CheckStatusPrompt(menu, D_800E28C8, 0) != 0)) {
            D_8014AD94 = 0;
            D_80153784 = 1;
        }
    }
    return D_80153784;
}

s32 Timer_GetChannelAndResult(struct RecordRecAt20V2 *record, s32 *out) {
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

void Timer_ProbeMenuChannel(struct Shared_PakMenu *record) {
    s32 value;

    if (D_8015375C != 0) {
        value = D_800E28C8;
    } else {
        value = record->owner->unk4;
    }
    Note_ProbeStatus(value);
}

void Timer_ReturnToWorldMenu(void *unused, void *object) {
    Control_DisableControllerPak(object);
    Scene_SetSelection(&g_world, g_world.selectionValues[3], 2);
}

s32 Timer_FindNoteByGameName(void *unused, void *arg1, s32 arg2, s32 *arg3) {
    char game_name[16];
    s32 game_ref;
    s32 note_index;
    for(note_index=0;note_index<16;note_index++) {
        Note_GetNoteGameName(arg2,note_index,&game_ref);
        Note_DecodeNoteText(game_ref,&game_name,16);
        if(XPlus_CompareStrings(&game_name,arg1)==0) {
            if(arg3) *arg3=note_index;
            return 1;
        }
    }
    return 0;
}

char *Timer_GetPromptByKind(int unused, int kind) {
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

char *Timer_GetPromptText(struct Shared_PakMenu *menu) {
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
s32 Timer_FindNextAvailableChannel(s32 currentChannel) {
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
        Note_ProbeStatus(channel);
        if (Note_GetStatus(channel) != -2) {
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

/* The EU builds compile a different original body for Timer_UpdateManagerChannelLabel; each version keeps its own. */
#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
/* Shows D_800D3728 in a field when both D_8014D4EC_de and D_8014D4C0_de are set, D_800D372C when only D_8014D4C0_de is, and otherwise, when D_8015375C is set, points the field at D_800D3764 and formats D_800E28C8 plus one into it with D_800DCD7C one byte before the length Menu_CountLineChars reports, returning zero.
   Adapted from Items_FormatPackedGameOption with the three flag tests, the texts, the format, the offset and the incremented value changed. */


extern s32 Menu_CountLineChars(struct Field *);

s32 Timer_UpdateManagerChannelLabel(struct Field *field) {
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
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 1), g_pakFormatInt1, value + 1);
    }
    return 0;
}

#endif

#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* Points an option field at its text: when D_8014D4C0_de is set, D_800D3728 if D_8014D4EC_de is set and D_800D372C if not; otherwise, when D_8015375C is set, the table D_800E27E4, formatting its entry for the byte D_80152789 with D_800ED3FC and D_800E28C8 plus one from one byte before the length Menu_CountLineChars reports; returns zero. */



extern s32 Menu_CountLineChars(struct Field *);

s32 Timer_UpdateManagerChannelLabel(struct Field *field) {
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
        text = table[g_languageIndex];
        Defs_FormatIntegerValue(text + (Menu_CountLineChars(field) - 1), D_800ED3FC, value + 1);
    }
done:
    return 0;
}

#endif
