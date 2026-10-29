#ifndef FRONTEND_RESULTS_SETUP_TEXT_H
#define FRONTEND_RESULTS_SETUP_TEXT_H
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern ResultsHeadingCharacter g_resultCharacterHeadingTranslations[];
extern char *g_resultCharacterUnlockTranslations[], *g_resultPreviouslyCompletedTranslations[], *g_resultCampaignCompleteTranslations[], *g_resultTrialsCompleteTranslations[];
extern char *D_800E2044_eu[], *D_800E2064_eu[], *g_resultModeHeadingTranslations[], *g_resultTrialModeTranslations[], *g_resultChallengeModeTranslations[];
static inline char *resultsUnavailable(Shared_Game *game) { return D_800E2044_eu[game->language]; }
static inline char *resultsFirstHeading(void) { return D_800E2064_eu[g_languageIndex]; }
static inline char *resultsSecondHeading(void) { return g_resultModeHeadingTranslations[g_languageIndex]; }
static inline char *resultsThirdHeading(void) { return g_resultTrialModeTranslations[g_languageIndex]; }
static inline char *resultsFourthHeading(void) { return g_resultChallengeModeTranslations[g_languageIndex]; }
#else
extern char *D_800D357C, *D_800D3584, *g_resultModeHeadingText, *g_resultTrialModeText, *g_resultChallengeModeText;
static inline char *resultsUnavailable(Shared_Game *game) { return D_800D357C; }
static inline char *resultsFirstHeading(void) { return D_800D3584; }
static inline char *resultsSecondHeading(void) { return g_resultModeHeadingText; }
static inline char *resultsThirdHeading(void) { return g_resultTrialModeText; }
static inline char *resultsFourthHeading(void) { return g_resultChallengeModeText; }
#endif
#if defined(VERSION_DE)
enum { RESULTS_HEADING1=0x237, RESULTS_HEADING2=0x236 };
#elif defined(VERSION_EU_X)
enum { RESULTS_HEADING1=0x23F, RESULTS_HEADING2=0x240 };
#else
enum { RESULTS_HEADING1=0x23A, RESULTS_HEADING2=0x23B };
#endif
#endif
