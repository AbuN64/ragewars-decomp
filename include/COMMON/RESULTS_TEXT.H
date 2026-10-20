#ifndef COMMON_RESULTS_TEXT_H
#define COMMON_RESULTS_TEXT_H
/* Results-screen texts: one per language in PAL builds, chosen by the game settings. */
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENU_TEXT.H"
/* The game settings record. */
static inline Shared_Game *currentGame(void) {
    return &D_801462C8;
}
#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* PAL builds keep one text per language, chosen by the game settings. */
#define RESULTS_LANGUAGE (currentGame()->language)
extern u8 D_80152789;
extern ResultsHeadingCharacter D_800F00DC[];
extern char D_800C5594[];
extern char *D_800E1664_eu[], *D_800E1724[], *D_800E1734_eu[], *D_800E1744[], *D_800E1754[], *D_800E1784[],
    *D_800E1794_eu[], *D_800E17A4[], *D_800E17B4[], *D_800E17C4[], *D_800E17D4[], *D_800E17E4_eu[],
    *D_800E17F4[], *D_800E1804[], *D_800E1814[], *D_800E1824[], *D_800E1834[], *D_800E1844[],
    *D_800E1854_eu[], *D_800E1864[], *D_800E1874[], *D_800E1884[], *D_800E1894[], *D_800E18A4[],
    *D_800E18B4_eu[];
#define RESULTS_CHARACTERS D_800F00DC
#define RESULTS_NAME_FORMAT D_800C5594
#else
#define RESULTS_LANGUAGE 0
#define RESULTS_CHARACTERS D_800DFA6C
#define RESULTS_NAME_FORMAT D_800C52E4_de
#endif
/* A results text in the language the game settings select. */
#define RESULTS_TEXT(fixed, table) RW_LOCALIZED_TEXT(fixed, table, table, RESULTS_LANGUAGE)
#endif
