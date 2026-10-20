#ifndef COMMON_CALLBACK_H
#define COMMON_CALLBACK_H
#include "TYPES.H"
struct Callback;
typedef struct Callback Callback;

/* Shared button/axis event produced by 8029AAD8 and 8029AB24. */
typedef struct ControllerEvent {
    s16 source;
    s16 device;
    s16 kind;
    s16 control;
    s32 reserved08;
    s16 pressed;
    s16 x;
    s16 y;
    s16 z;
} ControllerEvent;

typedef struct ControllerAxisState {
    s16 oldX, oldY, oldZ;
    s16 x, y, z;
} ControllerAxisState;

struct Callback;
struct Callback {
    s32 (*callback)(void);
    /* 8029A324: base + 4 + device * 0xC0 + axis * 12. */
    ControllerAxisState axes[16][16];
    u8 flags[64]; /* 0xC04: 16 groups of four dispatch flags; allocation is 0xC44 */
};

struct func_8029B650_S1;
struct func_8029B650_S1 {
    char pad0[0x4];
    s8 unk4;
    char pad4[0xAC - 0x4 - sizeof(s8)];
    s32 unkAC;
    char padAC[0xB0 - 0xAC - sizeof(s32)];
    s32 unkB0;
    char padB0[0xC4 - 0xB0 - sizeof(s32)];
    s8 unkC4;
    char padC4[0xC5 - 0xC4 - sizeof(s8)];
    s8 unkC5;
};

struct NodeRecAt12;
typedef struct NodeRecAt12 NodeRecAt12;

extern float D_800C5688_de;


struct func_8029BA34_S1;
typedef struct func_8029BA34_S1 func_8029BA34_S1;


struct StreamBuffer;



struct NodeRecAt12;
struct NodeRecAt12 {
    s32 unk0;
    struct NodeRecAt12 *left;
    struct NodeRecAt12 *right;
    s16 value;
    u16 type;
    u16 unk10;
    u16 flags;
};

struct func_8029B650_S1;
typedef struct func_8029B650_S1 func_8029B650_S1;

struct func_8029AA48_S1;
struct func_8029AA48_S1 {
    char pad0[0x534];
    int unk534;
    char pad534[0x538 - 0x534 - sizeof(int)];
    int unk538;
};

struct func_8029BA34_S1;
struct func_8029BA34_S1 {
    char pad0[0xC04];
    char unkC04;
};




struct func_8029AA48_S1;
typedef struct func_8029AA48_S1 func_8029AA48_S1;

/* Sequential read/write buffer, allocated by func_80299C38_de and freed by
 * func_80299C80_de; read and append cursors are independent. */
typedef struct StreamBuffer {
    s32 data;
    s32 capacity;
    s32 readPosition;
    s32 writePosition;
} StreamBuffer;
extern Callback *D_8014D0B0;
#endif
