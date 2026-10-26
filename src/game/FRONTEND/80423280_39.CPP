#include "include_asm.h"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "TYPES.H"
#include "COMMON/RECRECAT4.H"
#include "FRONTEND/80423280_39.H"
#include "ACHIEVE/80424E30_3.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern struct ResultsHeadingCharacter D_800F00DC[];
extern char D_800EE048[];
extern char D_800EE050[];
#define RES_TIMEFMT D_800EE048
#define RES_TIMEPOST D_800EE050
#define RES_HEAD3 ((char *)D_800E1DC4[g_languageIndex])
#define RES_HEAD4 ((char *)D_800E1DB4[settings->language])
#define RES_NAME(m) (((char **)D_800F00DC[m].name)[settings->language])
#else
#define RES_TIMEFMT D_800DD9C8
#define RES_TIMEPOST D_800DD9D0_de
#define RES_HEAD3 D_800D34DC
#define RES_HEAD4 D_800D34D8
#define RES_NAME(m) (D_800DFA6C[m].name->text)
#endif
/* Writes the heading of the results screen D_800E4690 into item 0x153: in one-player mode the
   label 0x69 followed by the name of the character in the player's status record; in three-player
   mode the label 0x3D with the stage's best time as minutes and seconds in item 0x156 (the record's
   time when set, else the stage default from Achieve_CopyPreset) and the heading D_800D34DC; in
   four-player mode the heading D_800D34D8. */

/* The results screen item and phrase ids renumber on the de cartridge: its heading item is 0x151,
   its name phrase 0x6B, its time phrase 0x3F and its time item 0x154; on eu-x 0x157, 0x6C, 0x40 and
   0x15A. eu and eu-x pick the heading and character name strings by language (RES_* above). */
#if defined(VERSION_DE)
enum { HEADING_ITEM = 0x151, NAME_PHRASE = 0x6B, TIME_PHRASE = 0x3F, TIME_ITEM = 0x154 };
#elif defined(VERSION_EU_X)
enum { HEADING_ITEM = 0x157, NAME_PHRASE = 0x6C, TIME_PHRASE = 0x40, TIME_ITEM = 0x15A };
#else
enum { HEADING_ITEM = 0x153, NAME_PHRASE = 0x69, TIME_PHRASE = 0x3D, TIME_ITEM = 0x156 };
#endif

extern struct ResultsHeadingScreen *D_800E4690;
extern struct ResultsHeadingRecord D_80102B00[];
extern struct ResultsHeadingCharacter D_800DFA6C[];

extern void XPlus_CopyString(char *, char *);
extern s32 Frontend_FindKeyIndex(s32);
extern void XStdio_FormatBuffer(char *, char *, ...);

void Frontend_UpdateResultsHeading(void) {
    Shared_Game *settings;
    struct Label *item;
    s32 time;
    u8 best;
    char buffer[32];

    /* the hub lookup returns its Item view; the Label view names the text pointer this unit writes */
    ((struct Label *) Frontend_FindWidgetByResourceId(D_800E4690->window, HEADING_ITEM))->text = D_800E4690->heading;
    settings = &D_801462C8;
    switch (settings->controllerMode) {
    case 1:
        XPlus_CopyString(D_800E4690->heading, Frontend_GetStringByIndex(NAME_PHRASE));
        Frontend_ReplaceTextOccurrences(D_800E4690->heading, D_800DD9BC,
                      RES_NAME(Frontend_FindKeyIndex(settings->playerSettings[D_800E4690->record].character)));
        break;
    case 3:
        XPlus_CopyString(D_800E4690->time, Frontend_GetStringByIndex(TIME_PHRASE));
        item = (struct Label *) Frontend_FindWidgetByResourceId(D_800E4690->window, TIME_ITEM);
        Frontend_SetWidgetFlag08(item, 1);
        item->text = D_800E4690->time;
        time = D_80102B00[D_800E4690->record].times[D_800E4690->stage];
        if (time > 0) {
            XStdio_FormatBuffer(buffer, RES_TIMEFMT, time / 60, time % 60);
        } else {
            best = ((struct ResultsHeadingStage *) Achieve_CopyPreset(D_800E4690->stage, 3, 0))->time;
            XStdio_FormatBuffer(buffer, RES_TIMEFMT, (u8)(best / 60), (u8)(best % 60));
        }
        Frontend_ReplaceTextOccurrences(D_800E4690->time, RES_TIMEPOST, buffer);
        XPlus_CopyString(D_800E4690->heading, RES_HEAD3);
        break;
    case 4:
        XPlus_CopyString(D_800E4690->heading, RES_HEAD4);
        break;
    }
}
