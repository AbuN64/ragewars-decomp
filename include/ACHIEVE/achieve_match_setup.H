#ifndef ACHIEVE_80424E30_4_H
#define ACHIEVE_80424E30_4_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/STATERECAT91.H"
struct Match_func_80420618_de {
    char pad00[0xD];
    unsigned char mode;
    char pad0E[0x16];
    s8 unk24;
    s8 unk25;
    char pad26[0xAA];
    RosterSlot slots[8];
};
struct PlayerRecAt602 {
    char pad[0x5D8];
    struct InfoCode80423280 *info;
    char pad5DC[0x26];
    struct {
        unsigned char flag;
        unsigned char value;
    } options[22];
};
typedef struct WeaponPlayer {
    u8 pad[0x5D8];
    WeaponStatus *status;
    u8 pad5DC[0x26];
    u8 weapons[22][2];
} WeaponPlayer;
extern s32 Achieve_MatchQualifies(void);
#endif
