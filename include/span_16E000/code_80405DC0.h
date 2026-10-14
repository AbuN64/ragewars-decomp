#ifndef UNBAKE_SPAN_16E000_CODE_80405DC0_H
#define UNBAKE_SPAN_16E000_CODE_80405DC0_H
#include "types.h"
#include "common/types_8a8189af7b05.h"
extern s32 D_8014AD94;

extern char D_0044EB70[];

extern int D_800D2448;

extern void func_80409964_de(void);

struct MenuRecAt24;
typedef struct MenuRecAt24 MenuRecAt24;

extern void func_804097E8_de();

extern s32 D_80153760;

extern void func_804098A4_de(s32 offset, s32 value);

struct Messages;
struct Messages {
    char pad0[0x554];
    char text[1];
};
struct Messages;
struct PlayerRecAt5EC;
struct PlayerRecAt5EC {
    char pad0[0x5DC];
    struct Messages *messages;
    char pad5E0[0xC];
    s32 menu;
};

extern s32 D_80153784;

extern s32 D_8014D4C0_de;

extern int D_800D2420;

extern s32 D_80146D60;

extern int D_800D2424;

struct MenuRecAt24;
struct PlayerRecAt5EC;
struct MenuRecAt24 {
    char pad0[0x1C];
    struct PlayerRecAt5EC *player;
    PakMenuSlot *slot;
    char *prompt;
};

struct Menu_func_80409144_de;
typedef struct Menu_func_80409144_de Menu_func_80409144_de;

struct PakNoteTextEntry;
typedef struct PakNoteTextEntry PakNoteTextEntry;

struct MenuRecAt20V3;
struct MenuRecAt20V3 {
    char pad0[0x1C];
    SharedPlayer_func_8022A398_de *player;
    PakMenuSlot *slot;
};

extern char *D_800D36D8;

struct Menu_func_80409144_de;
struct Menu_func_80409144_de {
    char pad0[0x1C];
    void *player;
    PakMenuSlot *slot;
    char *prompt;
};

struct Menu_func_80409144_de;
extern int func_80409144_de(void * owner, struct Menu_func_80409144_de * menu, void * arg);

extern void func_804098CC_de(void ***handle, void **data, s32 units);

extern int D_800D2428;

extern int D_800D241C;

extern int D_800D242C;

extern int D_800D2430;

extern int D_800D2438;

extern s32 D_8014D4EC_de;

struct MenuRecAt20V3;
typedef struct MenuRecAt20V3 MenuRecAt20V3;

extern s32 func_804085E0_de(void *unused, MenuRecAt20V3 *menu);

extern int D_8014D4D4;

extern int D_800D2440;

struct PlayerRecAt5EC;
typedef struct PlayerRecAt5EC PlayerRecAt5EC;

extern s32 D_8014AD9C;

extern s32 D_8014D4DC;

extern int D_8014D4FC;

extern char D_0044EBDC[];

extern int D_800D2434;

extern char *func_80409884_de(s32 block);

extern s32 D_800E28C8;

struct IntegerState610;
typedef struct IntegerState610 IntegerState610;

extern s32 func_804097D4_de(void);

struct IntegerState610;
struct IntegerState610 {
    unsigned char padding_0[1548];
    s32 unk_60C;
};

extern s32 func_804098B8_de(s32 *block);

extern s32 D_800DE874;

extern void func_80409744_de(void);

struct func_80408E1C_S1;
struct func_80408E1C_S1 {
    char pad0[0x554];
    char unk554;
};

extern int D_800D2444;

struct PakNoteTextEntry;
struct PakNoteTextEntry {
    s32 id;
    char pad4[0x10];
    u8 **text;
};

extern char *D_800D36D4;

extern int D_800D243C;

extern s32 D_80142CAC;

extern s32 func_80408DF0_de(void *owner, MenuRecAt24 *menu);

struct func_80408E1C_S1;
typedef struct func_80408E1C_S1 func_80408E1C_S1;

struct OwnerRecAt5D8V1;
extern void func_804099EC_de(struct OwnerRecAt5D8V1 *owner);

struct PakStatusPakSaveMenu;
struct PakNotesMenu;
extern s32 func_80408118_de(struct PakNoteTextEntry *entry, struct PakStatusPakSaveMenu *menu);
extern s32 func_80407F6C_de(struct PakNoteTextEntry *entry, struct PakNotesMenu *menu);
extern s32 func_8041C494_de(void);
#endif
