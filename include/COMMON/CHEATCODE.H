#ifndef COMMON_CHEATCODE_H
#define COMMON_CHEATCODE_H
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


struct Shared_Entry;
typedef struct Shared_Entry Shared_Entry;

struct MenuRecAt20V4;
struct MenuRecAt20V4 {
    s16 state;
    char pad2[0x1E];
    s32 input;
};

extern int D_8013B2D4;


struct Shared_Entry;
struct Shared_Entry {
    s32 value;
    f32 timer; /* blink period timer of the spinner, cleared by the digit editors */
    s32 count;
    u8 text[24];
};

struct EntryRecAt0V2;
typedef struct EntryRecAt0V2 EntryRecAt0V2;

extern float D_800E227C;


struct CheatCode;
typedef struct CheatCode CheatCode;

extern void func_804397E8_de(char *);

struct MenuRecAt20V4;
typedef struct MenuRecAt20V4 MenuRecAt20V4;
#endif
