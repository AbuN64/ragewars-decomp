#ifndef FRONTEND_RESULTS_SCREEN_TEXT_H
#define FRONTEND_RESULTS_SCREEN_TEXT_H
#include "TYPES.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/EFFECTRENDER.H"
/* PAL resources provide a string per selected language. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern const char D_800EE170[], D_800EE174[];
static inline const char *resultsNumberFormat(void) { return D_800EE170; }
static inline const char *resultsPercentFormat(void) { return D_800EE174; }
static inline char *resultsRankText(s32 rank) { return D_800DF964[rank][g_languageIndex]; }
#else
extern const char g_resultRowIntFormat[], g_resultRowPercentFormat[];
static inline const char *resultsNumberFormat(void) { return g_resultRowIntFormat; }
static inline const char *resultsPercentFormat(void) { return g_resultRowPercentFormat; }
static inline char *resultsRankText(s32 rank) { return D_800DF964[rank][0]; }
#endif
#endif
