#ifndef UNBAKE_SPAN_16E000_CODE_80444030_H
#define UNBAKE_SPAN_16E000_CODE_80444030_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8043F69C.h"
struct Settings_func_80444988_de;
struct Settings_func_80444988_de {
    char pad[0x79];
    u8 value;
};

struct Settings_func_80444BE8_de;
struct Settings_func_80444BE8_de {
    char pad[0x82];
    u8 flag;
};

struct Settings_func_80444AB8_de;
struct Settings_func_80444AB8_de {
    char pad[0x7A];
    u8 value;
};

struct Owner_func_80444BE8_de;
struct Settings_func_80444BE8_de;
struct Owner_func_80444BE8_de {
    char pad[0x5D8];
    struct Settings_func_80444BE8_de *settings;
};
struct HolderRecAt1CV2;
struct Owner_func_80444BE8_de;
struct HolderRecAt1CV2 {
    char pad[0x1C];
    struct Owner_func_80444BE8_de *owner;
};

struct Owner_func_80444988_de;
struct Settings_func_80444988_de;
struct Owner_func_80444988_de {
    char pad[0x5D8];
    struct Settings_func_80444988_de *settings;
};
struct Holder_func_80444988_de;
struct Owner_func_80444988_de;
struct Holder_func_80444988_de {
    char pad[0x1C];
    struct Owner_func_80444988_de *owner;
};

struct ActorRecAt1C;
struct OwnerRecAt5D8V2;
struct ActorRecAt1C {
    char pad[0x1C];
    struct OwnerRecAt5D8V2 *owner;
};

struct ActorRecAt1C;
extern char *func_804441F4_de(struct ActorRecAt1C *actor);

struct Settings_func_80444610_de;
struct Settings_func_80444610_de {
    char pad[0x7E];
    u8 value;
};

struct Owner_func_80444610_de;
struct Settings_func_80444610_de;
struct Owner_func_80444610_de {
    char pad[0x5D8];
    struct Settings_func_80444610_de *settings;
};
struct Holder_func_80444610_de;
struct Owner_func_80444610_de;
struct Holder_func_80444610_de {
    char pad[0x1C];
    struct Owner_func_80444610_de *owner;
};

extern void func_804441E4_de(void);

struct Settings_func_80444548_de;
struct Settings_func_80444548_de {
    char pad[0x7D];
    u8 value;
};

struct Owner_func_80444548_de;
struct Settings_func_80444548_de;
struct Owner_func_80444548_de {
    char pad[0x5D8];
    struct Settings_func_80444548_de *settings;
};
struct Holder_func_80444548_de;
struct Owner_func_80444548_de;
struct Holder_func_80444548_de {
    char pad[0x1C];
    struct Owner_func_80444548_de *owner;
};

struct Record_func_8043E494_de;
typedef struct Record_func_8043E494_de Record_func_8043E494_de;

struct Settings_func_80444488_de;
struct Settings_func_80444488_de {
    char pad[0x7C];
    u8 value;
};

struct Owner_func_80444AB8_de;
struct Settings_func_80444AB8_de;
struct Owner_func_80444AB8_de {
    char pad[0x5D8];
    struct Settings_func_80444AB8_de *settings;
};
struct Holder_func_80444AB8_de;
struct Owner_func_80444AB8_de;
struct Holder_func_80444AB8_de {
    char pad[0x1C];
    struct Owner_func_80444AB8_de *owner;
};

extern void func_80444094_de(u8 *record, u8 value);

struct Owner_func_80444488_de;
struct Settings_func_80444488_de;
struct Owner_func_80444488_de {
    char pad[0x5D8];
    struct Settings_func_80444488_de *settings;
};
struct Holder_func_80444488_de;
struct Owner_func_80444488_de;
struct Holder_func_80444488_de {
    char pad[0x1C];
    struct Owner_func_80444488_de *owner;
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
