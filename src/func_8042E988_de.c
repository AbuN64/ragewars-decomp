#include "span_16E000/code_8042E080.h"
#include "types.h"

/* Marks the pair ending at D_80154024 as set by storing one there, and stores its argument in the
   word before it; func_8042E9A0_de fills the pair ending at D_8015402C. */
extern s32 D_80154024;

void func_8042E988_de(s32 value) {
    s32 *pair = &D_80154024;

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


extern Settings_func_8042EB10_de D_801462C8;
extern Active *D_800E4680;
extern char D_8011FAC0[];
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EB10_de(void) {
 Settings_func_8042EB10_de *g=&D_801462C8;
 if(g->trialKind != 0) func_8042ED70_de((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,1,0,0);
 else func_8042ED70_de((f32)g->time,0,g->score,g->other,1,0,0);
 func_8044DE7C_de(D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Settings_func_8042EB10_de D_801462C8;
extern Active *D_800E4680;
extern char D_8011FAC0[];
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EBA4_de(void) {
 Settings_func_8042EB10_de *g=&D_801462C8;
 if(g->trialKind != 0) func_8042ED70_de((f32)D_800E4680->time,0,D_800E4680->score,D_800E4680->other,0,1,1);
 else func_8042ED70_de((f32)g->time,0,g->score,g->other,0,1,1);
 func_8044DE7C_de(D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Settings_func_8042EB10_de D_801462C8;
extern Active *D_800E4680;
extern char D_8011FAC0[];
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042EC38_de(void) {
 Settings_func_8042EB10_de *g=&D_801462C8;
 if(g->trialKind != 0) func_8042ED70_de((f32)D_800E4680->time,D_800E4680->limit,D_800E4680->score,D_800E4680->other,0,1,0);
 else func_8042ED70_de((f32)g->time,D_801462C8.limit,g->score,g->other,0,1,0);
 func_8044DE7C_de(D_8011FAC0,func_8042EE34_de());
}

/* Applies the selected rule settings and refreshes the menu state. */


extern Settings_func_8042EB10_de D_801462C8;
extern Active *D_800E4680;
extern char D_8011FAC0[];
extern void func_8042ED70_de(f32,s32,s32,s32,s32,s32,s32);
extern s32 func_8042EE34_de(void);
extern void func_8044DE7C_de(void *,s32);
void func_8042ECD8_de(void) {
 Settings_func_8042EB10_de *g=&D_801462C8;
 if(g->trialKind != 0) func_8042ED70_de((f32)D_800E4680->time,D_800E4680->score,D_800E4680->score,D_800E4680->other,0,0,0);
 else func_8042ED70_de((f32)g->time,D_801462C8.limit,g->score,g->other,0,0,0);
 func_8044DE7C_de(D_8011FAC0,func_8042EE34_de());
}
