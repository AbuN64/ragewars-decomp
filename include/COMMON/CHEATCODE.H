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

struct MenuPointerEntry;
struct MenuPointerEntry {
    void *ptr;
    s32 pad[3];
};

typedef signed int ( *Handler80437868)(void *, signed int, signed int, signed int, signed int);


struct Shared_Entry;
typedef struct Shared_Entry Shared_Entry;

struct CheatMenuInputView;
struct CheatMenuInputView {
    s16 state;
    char pad2[0x1E];
    s32 input;
};

extern int g_persistedOptionUnlockFlags;


struct Shared_Entry;
struct Shared_Entry {
    s32 value;
    f32 timer; /* blink period timer of the spinner, cleared by the digit editors */
    s32 count;
    u8 text[24];
};

struct MenuPointerEntry;
typedef struct MenuPointerEntry MenuPointerEntry;



struct CheatCode;
typedef struct CheatCode CheatCode;

extern void func_804397E8_de(char *);

struct CheatMenuInputView;
typedef struct CheatMenuInputView CheatMenuInputView;
#endif
