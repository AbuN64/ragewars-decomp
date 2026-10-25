#ifndef MENU_PLAYER_STATUS_TEXT_H
#define MENU_PLAYER_STATUS_TEXT_H
#include "TYPES.H"
#include "COMMON/LONE/D_80152789.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char *D_800E1034_eu[];
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
extern char *D_800D3178;
extern char *D_800D317C;
extern char *D_800D3180;
extern char *D_800D3184;
extern char *D_800D3188;
extern char *D_800D318C_de;
extern char *D_800D3190_de;
extern char *D_800D3194;
extern char *D_800D3198;
extern char *D_800D319C;
extern char *D_800D31A0_de;
extern char *D_800D31A4;
extern char *D_800D31A8;
extern char *D_800D31AC;
extern char *D_800D31B0;
#endif
static inline char *playerStatusText0(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1034_eu[D_80152789];
#else
    return D_800D3178;
#endif
}
static inline char *playerStatusText1(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1044[D_80152789];
#else
    return D_800D317C;
#endif
}
static inline char *playerStatusText2(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1054[D_80152789];
#else
    return D_800D3180;
#endif
}
static inline char *playerStatusText3(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1064_eu[D_80152789];
#else
    return D_800D3184;
#endif
}
static inline char *playerStatusText4(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1074[D_80152789];
#else
    return D_800D3188;
#endif
}
static inline char *playerStatusText5(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1084[D_80152789];
#else
    return D_800D318C_de;
#endif
}
static inline char *playerStatusText6(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1094_eu[D_80152789];
#else
    return D_800D3190_de;
#endif
}
static inline char *playerStatusText7(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10A4[D_80152789];
#else
    return D_800D3194;
#endif
}
static inline char *playerStatusText8(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10B4[D_80152789];
#else
    return D_800D3198;
#endif
}
static inline char *playerStatusText9(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10C4[D_80152789];
#else
    return D_800D319C;
#endif
}
static inline char *playerStatusText10(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10D4_eu[D_80152789];
#else
    return D_800D31A0_de;
#endif
}
static inline char *playerStatusText11(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10E4[D_80152789];
#else
    return D_800D31A4;
#endif
}
static inline char *playerStatusText12(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E10F4[D_80152789];
#else
    return D_800D31A8;
#endif
}
static inline char *playerStatusText13(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1104[D_80152789];
#else
    return D_800D31AC;
#endif
}
static inline char *playerStatusText14(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1114[D_80152789];
#else
    return D_800D31B0;
#endif
}
#endif
