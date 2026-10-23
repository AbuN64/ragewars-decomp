#ifndef COMMON_GAMEPLAY_SETTINGS_H
#define COMMON_GAMEPLAY_SETTINGS_H
#include "TYPES.H"
/* Actual 0x96-byte player-settings records based at Game+0xD0.
 * ROM joining-player stores (+0x78/+0x7F) and exact transition caller
 * reads (+0x80/+0x95) corroborate the shared record. */
typedef struct Shared_PlayerSettingsRecord Shared_PlayerSettingsRecord;
struct Shared_PlayerSettingsRecord {
    char pad0[4];
    s16 score; /* +0x04: end-of-match reward statistic */
    char pad6[0x4C - 6];
    u8 weapons[0x16]; /* +0x4C: owned flag per weapon id (results weapon menu) */
    char pad62[0x78 - 0x62];
    u8 enabled; /* +0x78: Frontend_ApplyModeChoice ROM joining-player stores */
    char pad79[6];
    u8 slot; /* +0x7F: Frontend_ApplyModeChoice ROM slot-number stores */
    s8 character; /* +0x80: src/func_8021B468.c */
    u8 variant; /* +0x81: selected costume, func_80420618_de */
    char pad82[2];
    u8 name[13]; /* +0x84: localized player label, through +0x90. */
    u8 locked; /* +0x91: results-screen human/bot selector */
    u8 rank; /* +0x92: joining request byte 2 (request kind+1, team, rank) */
    u8 team; /* +0x93: team index 0..2, joinTeamName(team * 17 + ...) */
    u8 controlMode; /* +0x94: set by opponent kind when stage opponents are placed */
    u8 active; /* +0x95: src/func_8021B468.c */

};
typedef char Shared_PlayerSettingsRecord_size_check[(sizeof(Shared_PlayerSettingsRecord) == 0x96) ? 1 : -1];
#endif
