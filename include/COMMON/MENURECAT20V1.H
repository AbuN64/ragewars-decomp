#ifndef COMMON_MENURECAT20V1_H
#define COMMON_MENURECAT20V1_H
#include "TYPES.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ITEMRECAT20V1.H"
extern float D_800E2810;

struct MenuRecAt20V1;
struct MenuRecAt20V1 {
    s16 state;
    char pad2[0x1A];
    s32 id;
    s32 input;
};

struct Actor_func_8044560C_de;
struct Actor_func_8044560C_de {
    char pad0[0x80];
    s32 mask80;
    char pad84[0xA8 - 0x84];
    s32 maskA8;
};
struct Actor_func_8044560C_de;
struct PlayerRecAtC;
struct PlayerRecAtC {
    s16 state;
    char pad2[0xA];
    struct Actor_func_8044560C_de *actor;
};

struct PlayerRecAtC;
typedef struct PlayerRecAtC PlayerRecAtC;


struct Spinner;
typedef struct Spinner Spinner;

struct Style_func_80445BC0_de;
struct Style_func_80445BC0_de {
    char pad0[0x1C];
    s32 id;
    char pad20[0x10];
    f32 alpha;
    f32 fade;
};

struct State_func_80445EF4_de;
typedef struct State_func_80445EF4_de State_func_80445EF4_de;

struct EntryRecAtCV2;
struct EntryRecAtCV2 {
    s32 value;
    f32 timer;
    s32 count;
    u8 text[12];
};

struct State_func_80445EF4_de;
struct State_func_80445EF4_de {
    char pad[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
};


struct EntryRecAt1C;
struct EntryRecAt1C {
    char pad[0x1C];
    ObjRecAt5D8 *unk1C;
};



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
struct Spinner {
    s32 value;
    f32 timer;
    s32 max;
    char padC[0xC];
};


struct MenuRecAt20V1;
typedef struct MenuRecAt20V1 MenuRecAt20V1;

struct LocalizedInputState;
typedef struct LocalizedInputState LocalizedInputState;


struct TextEntryRecAtC;
struct TextEntryRecAtC {
    s32 length;
    s32 cursor;
    s32 count;
    char text[12];
};

struct EntryRecAt1C;
typedef struct EntryRecAt1C EntryRecAt1C;

struct Field;

extern u8 D_800E20AC[];

extern void func_802648C8_de(void);
#endif
