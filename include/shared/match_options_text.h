#ifndef MATCH_OPTIONS_TEXT_H
#define MATCH_OPTIONS_TEXT_H
#include "shared/func_80425674_de_layout.h"
#if defined(VERSION_DE)
enum { OPTIONS_ID_SHIFT=-4 };
extern char *D_auto_800D3494;
static inline char *optionsLabel0(Shared_Game *game) { return D_auto_800D3494; }
extern char *D_auto_800D3498;
static inline char *optionsLabel1(Shared_Game *game) { return D_auto_800D3498; }
extern char *D_auto_800D349C;
static inline char *optionsLabel2(Shared_Game *game) { return D_auto_800D349C; }
extern char *D_auto_800D34A0;
static inline char *optionsLabel3(Shared_Game *game) { return D_auto_800D34A0; }
extern char *D_800D34A4;
static inline char *optionsLabel4(Shared_Game *game) { return D_800D34A4; }
extern char *D_auto_800D34A8;
static inline char *optionsLabel5(Shared_Game *game) { return D_auto_800D34A8; }
extern char *D_auto_800D34AC;
static inline char *optionsLabel6(Shared_Game *game) { return D_auto_800D34AC; }
#elif defined(VERSION_EU)
enum { OPTIONS_ID_SHIFT=0 };
extern char *D_auto_800E1CA4[];
static inline char *optionsLabel0(Shared_Game *game) { return D_auto_800E1CA4[game->language]; }
extern char *D_auto_800E1CB4[];
static inline char *optionsLabel1(Shared_Game *game) { return D_auto_800E1CB4[game->language]; }
extern char *D_auto_800E1CC4[];
static inline char *optionsLabel2(Shared_Game *game) { return D_auto_800E1CC4[game->language]; }
extern char *D_auto_800E1CD4[];
static inline char *optionsLabel3(Shared_Game *game) { return D_auto_800E1CD4[game->language]; }
extern char *D_800E1CE4[];
static inline char *optionsLabel4(Shared_Game *game) { return D_800E1CE4[game->language]; }
extern char *D_auto_800E1CF4[];
static inline char *optionsLabel5(Shared_Game *game) { return D_auto_800E1CF4[game->language]; }
extern char *D_auto_800E1D04[];
static inline char *optionsLabel6(Shared_Game *game) { return D_auto_800E1D04[game->language]; }
#elif defined(VERSION_EU_X)
enum { OPTIONS_ID_SHIFT=4 };
extern char *D_auto_800DD7F0[];
static inline char *optionsLabel0(Shared_Game *game) { return D_auto_800DD7F0[game->language]; }
extern char *D_auto_800DD7FC[];
static inline char *optionsLabel1(Shared_Game *game) { return D_auto_800DD7FC[game->language]; }
extern char *D_auto_800DD808[];
static inline char *optionsLabel2(Shared_Game *game) { return D_auto_800DD808[game->language]; }
extern char *D_auto_800DD814[];
static inline char *optionsLabel3(Shared_Game *game) { return D_auto_800DD814[game->language]; }
extern char *D_800E1CE4[];
static inline char *optionsLabel4(Shared_Game *game) { return D_800E1CE4[game->language]; }
extern char *D_auto_800DD82C[];
static inline char *optionsLabel5(Shared_Game *game) { return D_auto_800DD82C[game->language]; }
extern char *D_auto_800DD838[];
static inline char *optionsLabel6(Shared_Game *game) { return D_auto_800DD838[game->language]; }
#elif defined(VERSION_US_REV1)
enum { OPTIONS_ID_SHIFT=0 };
extern char *D_auto_800D74C0;
static inline char *optionsLabel0(Shared_Game *game) { return D_auto_800D74C0; }
extern char *D_auto_800D74C4;
static inline char *optionsLabel1(Shared_Game *game) { return D_auto_800D74C4; }
extern char *D_auto_800D74C8;
static inline char *optionsLabel2(Shared_Game *game) { return D_auto_800D74C8; }
extern char *D_auto_800D74CC;
static inline char *optionsLabel3(Shared_Game *game) { return D_auto_800D74CC; }
extern char *D_800D34A4;
static inline char *optionsLabel4(Shared_Game *game) { return D_800D34A4; }
extern char *D_auto_800D74D4;
static inline char *optionsLabel5(Shared_Game *game) { return D_auto_800D74D4; }
extern char *D_auto_800D74D8;
static inline char *optionsLabel6(Shared_Game *game) { return D_auto_800D74D8; }
#endif
#endif
