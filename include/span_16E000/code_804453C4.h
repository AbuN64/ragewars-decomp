#ifndef UNBAKE_SPAN_16E000_CODE_804453C4_H
#define UNBAKE_SPAN_16E000_CODE_804453C4_H
#include "types.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_1dc8418c21db.h"
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

extern void func_8044560C_de(PlayerRecAtC *player);

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

extern s32 func_80445B88_de(u8 *a, u8 *b, s32 count);

struct EntryRecAt1C;
struct EntryRecAt1C {
    char pad[0x1C];
    ObjRecAt5D8 *unk1C;
};

extern void func_8044569C_de(void);

extern s32 func_80445EF4_de(void);

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

extern void func_804456B8_de(void);

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

extern int func_80446330_us_rev1(void * arg0);
struct Field;
extern s32 func_80445310_de(struct Field *field);
#endif
