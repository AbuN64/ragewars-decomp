#ifndef COMMON_SESSION_STATE_H
#define COMMON_SESSION_STATE_H
#include "TYPES.H"

struct CMenu_t;
typedef struct MessageList {
    struct CMenu_t *head;
    char pad04[0x10 - 0x4];
    s32 flag;
    s16 rotation; /* 0x14 */
} MessageList;

typedef struct RosterEntry {
    char pad0[0x78];
    u8 active;
    char pad79[0x92 - 0x79];
    u8 team;
    char pad93[0x96 - 0x93];
} RosterEntry;

typedef struct Settings580 {
    char pad0[0xD];
    u8 trialKind;
    char padE[0x1D - 0xE];
    u8 allowed;
    char pad1E[0xD0 - 0x1E];
    RosterEntry roster[8];
} Settings580;
#endif
