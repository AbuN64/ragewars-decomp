#ifndef UNBAKE_SPAN_166000_CODE_80426310_H
#define UNBAKE_SPAN_166000_CODE_80426310_H
#include "TYPES.H"
struct CheatCode;
struct CheatCode {
    u8 *code;
    s32 unk4;
    s32 flags;
    s32 sound;
};

struct EntryRecAt0V2;
struct EntryRecAt0V2 {
    void *ptr;
    s32 pad[3];
};

typedef signed int ( *Handler80437868)(void *, signed int, signed int, signed int, signed int);

extern s32 func_804379B8_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Shared_Entry;
typedef struct Shared_Entry Shared_Entry;

struct MenuRecAt20V4;
struct MenuRecAt20V4 {
    s16 state;
    char pad2[0x1E];
    s32 input;
};

extern int D_8013B2D4;

extern void func_8043C998_de(void);

struct Shared_Entry;
struct Shared_Entry {
    s32 value;
    s32 timer;
    s32 count;
    u8 text[24];
};

struct EntryRecAt0V2;
typedef struct EntryRecAt0V2 EntryRecAt0V2;

extern float D_800E227C;

struct InputHistory;
typedef struct InputHistory InputHistory;

struct CheatCode;
typedef struct CheatCode CheatCode;

struct InputHistory;
struct InputHistory {
    s32 value;
    s32 timer;
    s32 count;
    u8 text[1];
};

extern void func_804397E8_de(char *);

struct MenuRecAt20V4;
typedef struct MenuRecAt20V4 MenuRecAt20V4;

extern s32 func_8042913C_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern s32 func_80437688_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

#endif
