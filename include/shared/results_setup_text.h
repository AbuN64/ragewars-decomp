#ifndef RESULTS_SETUP_TEXT_H
#define RESULTS_SETUP_TEXT_H
#include "shared/func_80425674_de_layout.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
extern char *D_800E2044_eu[], *D_800E2064_eu[], *D_800E2074_eu[], *D_800E2084[], *D_800E2094_eu[];
static inline char *resultsUnavailable(void) { return D_800E2044_eu[D_801462C8.language]; }
static inline char *resultsFirstHeading(void) { return D_800E2064_eu[D_80152789]; }
static inline char *resultsSecondHeading(void) { return D_800E2074_eu[D_80152789]; }
static inline char *resultsThirdHeading(void) { return D_800E2084[D_80152789]; }
static inline char *resultsFourthHeading(void) { return D_800E2094_eu[D_80152789]; }
#else
extern char *D_800D357C, *D_800D3584, *D_800D3588, *D_800D358C, *D_800D3590;
static inline char *resultsUnavailable(void) { return D_800D357C; }
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
