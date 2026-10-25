#ifndef FRONTEND_JOIN_PLAYER_NAMES_H
#define FRONTEND_JOIN_PLAYER_NAMES_H
#include "TYPES.H"
#include "COMMON/LONE/D_80152789.H"
typedef struct JoinNameEntry { u8 **names; s32 pad; } JoinNameEntry;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800E1664_eu[], *D_800E1564_eu[];
extern JoinNameEntry D_800EFE40[];
#else
extern u8 *D_800D3304[], *D_800D32C4[];
extern JoinNameEntry D_800DF7D0[];
#endif
static inline u8 *joinName15(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1664_eu[D_80152789];
#else
    return D_800D3304[0];
#endif
}
static inline u8 *joinName16(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E1564_eu[D_80152789];
#else
    return D_800D32C4[0];
#endif
}
static inline u8 *joinTeamName(s32 index) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800EFE40[index].names[D_80152789];
#else
    return *D_800DF7D0[index].names;
#endif
}
#endif
