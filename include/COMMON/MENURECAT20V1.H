#ifndef COMMON_MENURECAT20V1_H
#define COMMON_MENURECAT20V1_H
#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
extern float D_800E2810;

struct MenuRecAt20V1;

struct Actor_func_8044560C_de;
struct Actor_func_8044560C_de {
    char pad0[0x80];
    s32 mask80;
    char pad84[0xA8 - 0x84];
    s32 maskA8;
};
struct Actor_func_8044560C_de;
struct PlayerRecAtC;

struct PlayerRecAtC;
typedef struct PlayerRecAtC PlayerRecAtC;


struct Spinner;
typedef struct Spinner Spinner;

struct Style_func_80445BC0_de;


struct EntryRecAtCV2;



struct EntryRecAt1C;



struct EntryRecAtCV2;
typedef struct EntryRecAtCV2 EntryRecAtCV2;

struct LocalizedInputState;
struct LocalizedInputState {
    u8 reserved[0x1809];
    u8 language;
};

extern float D_800DE7C8_de;

struct Style_func_80445BC0_de;
typedef struct Style_func_80445BC0_de Style_func_80445BC0_de;

struct TextEntryRecAtC;
typedef struct TextEntryRecAtC TextEntryRecAtC;

struct Spinner;


struct MenuRecAt20V1;
typedef struct MenuRecAt20V1 MenuRecAt20V1;

struct LocalizedInputState;
typedef struct LocalizedInputState LocalizedInputState;


struct TextEntryRecAtC;

struct EntryRecAt1C;
typedef struct EntryRecAt1C EntryRecAt1C;

struct Field;

extern u8 D_800E20AC[];

extern void Control_SaveControllerSetup(void);
#endif
