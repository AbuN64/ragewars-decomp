#include "include_asm.h"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"

/* Marks the pair ending at D_80154024 as set by storing one there, and stores its argument in the
   word before it; func_8042E9A0_de fills the pair ending at D_8015402C. */

void func_8042E988_de(s32 value) {
    s32 *pair = &D_80154020.ready;

    pair[0] = 1;
    pair[-1] = value;
}

/* Stores a pair of words: the second argument in D_8015402C and the first in the word before
   it; func_8042E988_de does the same for the pair ending at D_80154024. */
extern s32 D_8015402C;

void func_8042E9A0_de(s32 first, s32 second) {
    s32 *pair = &D_8015402C;

    pair[0] = second;
    pair[-1] = first;
}

/* Replaces every occurrence of the second string in the first with the third, in place: while
   func_802A052C_de finds a match (returning the position just past it), it copies the text before
   the match into a 200-byte buffer, appends the replacement through func_802A02E8_de, appends the
   rest of the text, copies the buffer back and searches again. */

extern char *func_802A052C_de(char *, char *);
extern s32 func_802A0238_de(char *);
extern void func_802A02E8_de(char *, char *);

void func_8042E9B4_de(char *text, char *find, char *replacement) {
    char buffer[200];
    char *match;
    s32 findLength;
    s32 length;
    s32 before;
    s32 copied;
    s32 i;
    s32 j;

    match = func_802A052C_de(text, find);
    findLength = func_802A0238_de(find);
    while (match != 0) {
        length = func_802A0238_de(text);
        before = match - text - findLength;
        i = 0;
        if (i < before) {
        copy_before:
            buffer[i] = text[i];
            i++;
            if (i < before) {
                goto copy_before;
            }
        }
        buffer[before] = 0;
        func_802A02E8_de(buffer, replacement);
        j = func_802A0238_de(buffer);
        i = before + findLength;
        if (i < length) {
        copy_after:
            buffer[j] = text[i];
            j++;
            i++;
            buffer[j] = 0;
            if (i < length) {
                goto copy_after;
            }
        }
        copied = func_802A0238_de(buffer);
        i = 0;
        if (i < copied) {
        copy_back:
            text[i] = buffer[i];
            i++;
            if (i < copied) {
                goto copy_back;
            }
        }
        text[copied] = 0;
        match = func_802A052C_de(text, find);
    }
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
#include "COMMON/GAME_SESSION.H"
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EB10_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) func_8042ED70_de((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,1,0,0);
 else func_8042ED70_de((f32)g->laps,0,g->trialScore,g->trialOther,1,0,0);
 func_8044DE7C_de(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EBA4_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) func_8042ED70_de((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,0,1,1);
 else func_8042ED70_de((f32)g->laps,0,g->trialScore,g->trialOther,0,1,1);
 func_8044DE7C_de(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EC38_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) func_8042ED70_de((f32)D_800E4680->time,D_800E4680->limit,D_800E4680->score,D_800E4680->other,0,1,0);
 else func_8042ED70_de((f32)g->laps,D_801462C8.players,g->trialScore,g->trialOther,0,1,0);
 func_8044DE7C_de(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042ECD8_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) func_8042ED70_de((f32)D_800E4680->time,D_800E4680->score,D_800E4680->score,D_800E4680->other,0,0,0);
 else func_8042ED70_de((f32)g->laps,D_801462C8.players,g->trialScore,g->trialOther,0,0,0);
 func_8044DE7C_de(&D_8011FAC0,func_8042EE34_de());
}

#ifdef NON_MATCHING
#include "TYPES.H"
/* Starts a match counter block: stores the six option words, scales the time limit by the mode's factor, and clears the score and count rows. */
void func_8042ED70_de(f32 rate, s32 identifier, s32 argument2, s32 argument3,
                     s32 argument4, s32 argument5, s32 argument6) {
    CGameStatus *state = &D_801462C8.counters;
    f32 scale;
    s32 i;
    state->m_FragTagLimit = argument2;
    state->m_CTFPlayerWithFlag = 0;
    state->unk7C = argument3;
    state->m_bFragTagOn = argument4;
    state->teams = argument5;
    scale = D_800DDB54;
    state->m_bCTFOn = argument6;
    if ((u32)(D_801462C8.controllerMode - 2) < 2) {
        scale = D_800DDB58;
    }
    state->timeLimit = rate * scale;
    i = 0;
    state->mask = 0xA00;
    state->mode = identifier;
    state->elapsed = 0;
    do {
        state->scores[i] = 0;
        state->counts[i] = 0;
        i++;
    } while (i < 5);
    state->round = 0;
    if (state->timeLimit == 0.0f) {
        state->timeLimit = D_800DDB5C_de;
    }
}
#else
INCLUDE_ASM("ovl_80400000", func_8042ED70_de);
#endif
