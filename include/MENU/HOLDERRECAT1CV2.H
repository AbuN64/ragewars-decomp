#ifndef MENU_HOLDERRECAT1CV2_H
#define MENU_HOLDERRECAT1CV2_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TEXTLAYERMETRICS.H"
/* A player's option record: the record an owner holds at 0x5D8, or the defaults D_80146302. */
struct PlayerOptions;
struct PlayerOptions {
    char text[0x79]; /* +0x00: shown as the name when there is no owner */
    u8 option79;
    u8 option7A;
    s8 option7B;
    u8 option7C;
    u8 option7D;
    u8 option7E;
    char pad7F[0x82 - 0x7F];
    u8 flag82;
};
extern struct PlayerOptions D_80146302;
struct ActorRecAt1C;
struct OwnerRecAt5D8V2;
struct ActorRecAt1C {
    char pad[0x1C];
    struct OwnerRecAt5D8V2 *owner;
};
struct MenuItemRecAt14;
struct MenuItemRecAt14 {
    char pad0[8];
    u32 flags;
    char padC[8];
    void *table;
};

struct MenuItemRecAt14;
typedef struct MenuItemRecAt14 MenuItemRecAt14;

#if defined(VERSION_DE) || defined(VERSION_US) || defined(VERSION_US_REV1)
s32 func_8044488C_de(struct LayeredText *field);
#endif

extern u8 *D_800D35EC[];
extern u8 *D_800D35F0[];
extern char D_800DE750_de[];
#endif
