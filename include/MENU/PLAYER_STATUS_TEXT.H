#ifndef MENU_PLAYER_STATUS_TEXT_H
#define MENU_PLAYER_STATUS_TEXT_H
#include "TYPES.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *g_playerStatusMessage0Translations[];
extern char *D_800E1044[];
extern char *D_800E1054[];
extern char *D_800E1064_eu[];
extern char *D_800E1074[];
extern char *D_800E1084[];
extern char *D_800E1094_eu[];
extern char *D_800E10A4[];
extern char *D_800E10B4[];
extern char *D_800E10C4[];
extern char *D_800E10D4_eu[];
extern char *D_800E10E4[];
extern char *D_800E10F4[];
extern char *D_800E1104[];
extern char *D_800E1114[];
#else
extern char *g_playerStatusMessage0;
extern char *g_playerStatusMessage1;
extern char *g_playerStatusMessage2;
extern char *g_playerStatusMessage3;
extern char *g_playerStatusMessage4;
extern char *g_playerStatusMessage5;
extern char *g_playerStatusMessage6;
extern char *g_playerStatusMessage7;
extern char *g_playerStatusMessage8;
extern char *g_playerStatusMessage9;
extern char *g_playerStatusMessage10;
extern char *g_playerStatusMessage11;
extern char *g_playerStatusMessage12;
extern char *g_playerStatusMessage13;
extern char *g_playerStatusMessage14;
#endif
static inline char *playerStatusText0(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return g_playerStatusMessage0Translations[g_languageIndex];
#else
    return g_playerStatusMessage0;
#endif
}
static inline char *playerStatusText1(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1044[g_languageIndex];
#else
    return g_playerStatusMessage1;
#endif
}
static inline char *playerStatusText2(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1054[g_languageIndex];
#else
    return g_playerStatusMessage2;
#endif
}
static inline char *playerStatusText3(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1064_eu[g_languageIndex];
#else
    return g_playerStatusMessage3;
#endif
}
static inline char *playerStatusText4(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1074[g_languageIndex];
#else
    return g_playerStatusMessage4;
#endif
}
static inline char *playerStatusText5(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1084[g_languageIndex];
#else
    return g_playerStatusMessage5;
#endif
}
static inline char *playerStatusText6(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1094_eu[g_languageIndex];
#else
    return g_playerStatusMessage6;
#endif
}
static inline char *playerStatusText7(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10A4[g_languageIndex];
#else
    return g_playerStatusMessage7;
#endif
}
static inline char *playerStatusText8(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10B4[g_languageIndex];
#else
    return g_playerStatusMessage8;
#endif
}
static inline char *playerStatusText9(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10C4[g_languageIndex];
#else
    return g_playerStatusMessage9;
#endif
}
static inline char *playerStatusText10(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10D4_eu[g_languageIndex];
#else
    return g_playerStatusMessage10;
#endif
}
static inline char *playerStatusText11(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10E4[g_languageIndex];
#else
    return g_playerStatusMessage11;
#endif
}
static inline char *playerStatusText12(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10F4[g_languageIndex];
#else
    return g_playerStatusMessage12;
#endif
}
static inline char *playerStatusText13(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1104[g_languageIndex];
#else
    return g_playerStatusMessage13;
#endif
}
static inline char *playerStatusText14(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1114[g_languageIndex];
#else
    return g_playerStatusMessage14;
#endif
}
#endif
