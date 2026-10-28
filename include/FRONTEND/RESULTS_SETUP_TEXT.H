#ifndef FRONTEND_RESULTS_SETUP_TEXT_H
#define FRONTEND_RESULTS_SETUP_TEXT_H
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_80152789.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern ResultsHeadingCharacter D_800F00DC[];
extern char *D_auto_800E2034[], *D_auto_800E2054[], *D_auto_800E20A4[], *D_auto_800E20B4[];
extern char *D_800E2044_eu[], *D_800E2064_eu[], *D_800E2074_eu[], *D_800E2084[], *D_800E2094_eu[];
static inline char *resultsUnavailable(Shared_Game *game) { return D_800E2044_eu[game->language]; }
static inline char *resultsFirstHeading(void) { return D_800E2064_eu[g_languageIndex]; }
static inline char *resultsSecondHeading(void) { return D_800E2074_eu[g_languageIndex]; }
static inline char *resultsThirdHeading(void) { return D_800E2084[g_languageIndex]; }
static inline char *resultsFourthHeading(void) { return D_800E2094_eu[g_languageIndex]; }
#else
extern char *D_800D357C, *D_800D3584, *D_800D3588, *D_800D358C, *D_800D3590;
static inline char *resultsUnavailable(Shared_Game *game) { return D_800D357C; }
static inline char *resultsFirstHeading(void) { return D_800D3584; }
static inline char *resultsSecondHeading(void) { return D_800D3588; }
static inline char *resultsThirdHeading(void) { return D_800D358C; }
static inline char *resultsFourthHeading(void) { return D_800D3590; }
#endif
#if defined(VERSION_DE)
enum { RESULTS_HEADING1=0x237, RESULTS_HEADING2=0x236 };
#elif defined(VERSION_EU_X)
enum { RESULTS_HEADING1=0x23F, RESULTS_HEADING2=0x240 };
#else
enum { RESULTS_HEADING1=0x23A, RESULTS_HEADING2=0x23B };
#endif
#endif
