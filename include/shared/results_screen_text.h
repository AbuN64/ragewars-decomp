#ifndef RESULTS_SCREEN_TEXT_H
#define RESULTS_SCREEN_TEXT_H
#include "TYPES.H"
#include "common/data.h"
/* PAL resources provide a string per selected language. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern const char D_800EE170[], D_800EE174[];
static inline const char *resultsNumberFormat(void) { return D_800EE170; }
static inline const char *resultsPercentFormat(void) { return D_800EE174; }
static inline char *resultsRankText(s32 rank) { return D_800DF964[rank][D_80152789]; }
#else
extern const char D_800DDAF0_de[], D_800DDAF4[];
static inline const char *resultsNumberFormat(void) { return D_800DDAF0_de; }
static inline const char *resultsPercentFormat(void) { return D_800DDAF4; }
static inline char *resultsRankText(s32 rank) { return D_800DF964[rank][0]; }
#endif
#endif
