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
extern void Frontend_InitGameStatus(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void Ovlgame_StartMatchTransition(GameSession *, s32);
void func_8042EB10_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) Frontend_InitGameStatus((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,1,0,0);
 else Frontend_InitGameStatus((f32)g->laps,0,g->trialScore,g->trialOther,1,0,0);
 Ovlgame_StartMatchTransition(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void Frontend_InitGameStatus(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void Ovlgame_StartMatchTransition(GameSession *, s32);
void func_8042EBA4_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) Frontend_InitGameStatus((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,0,1,1);
 else Frontend_InitGameStatus((f32)g->laps,0,g->trialScore,g->trialOther,0,1,1);
 Ovlgame_StartMatchTransition(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void Frontend_InitGameStatus(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void Ovlgame_StartMatchTransition(GameSession *, s32);
void func_8042EC38_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) Frontend_InitGameStatus((f32)D_800E4680->time,D_800E4680->limit,D_800E4680->score,D_800E4680->other,0,1,0);
 else Frontend_InitGameStatus((f32)g->laps,D_801462C8.players,g->trialScore,g->trialOther,0,1,0);
 Ovlgame_StartMatchTransition(&D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Active *D_800E4680;
extern void Frontend_InitGameStatus(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void Ovlgame_StartMatchTransition(GameSession *, s32);
void func_8042ECD8_de(void) {
 Shared_Game *g=&D_801462C8;
 if(g->controllerMode != 0) Frontend_InitGameStatus((f32)D_800E4680->time,D_800E4680->score,D_800E4680->score,D_800E4680->other,0,0,0);
 else Frontend_InitGameStatus((f32)g->laps,D_801462C8.players,g->trialScore,g->trialOther,0,0,0);
 Ovlgame_StartMatchTransition(&D_8011FAC0,func_8042EE34_de());
}

/* Starts the match status block: the frag tag limit, the second score limit, the frag tag, team and
 * capture-the-flag switches and the mode, the time limit scaled by 900 (15 in controller modes 2 and 3,
 * -1 when there is no limit), then clears the score and count rows. */
static inline CGameStatus *GameCounters(void) { return &D_801462C8.counters; }
void Frontend_InitGameStatus(f32 duration, s32 mode, s32 fragTagLimit, s32 otherLimit,
                     s32 fragTagOn, s32 teams, s32 ctfOn) {
    s32 i;
    GameCounters()->m_FragTagLimit = fragTagLimit;
    GameCounters()->m_CTFPlayerWithFlag = 0;
    GameCounters()->unk7C = otherLimit;
    GameCounters()->m_bFragTagOn = fragTagOn;
    GameCounters()->teams = teams;
    GameCounters()->m_bCTFOn = ctfOn;
    if ((u32)(D_801462C8.controllerMode - 2) < 2) {
        GameCounters()->timeLimit = duration * 15.0f;
    } else {
        GameCounters()->timeLimit = duration * 900.0f;
    }
    GameCounters()->mask = 0xA00;
    GameCounters()->mode = mode;
    GameCounters()->elapsed = 0;
    for (i = 0; i < 5; i++) {
        GameCounters()->scores[i] = 0;
        GameCounters()->counts[i] = 0;
    }
    GameCounters()->round = 0;
    if (GameCounters()->timeLimit == 0.0f) {
        GameCounters()->timeLimit = -1.0f;
    }
}
