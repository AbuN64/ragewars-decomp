#ifndef UNBAKE_SPAN_1000_CODE_80299DB4_H
#define UNBAKE_SPAN_1000_CODE_80299DB4_H
#include "types.h"
struct Callback;
typedef struct Callback Callback;

struct EventCode80299DB4;
struct EventCode80299DB4 {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s16 f8;
    s16 fA;
    s16 fC;
};

extern void func_8029AA78_de();

extern void func_80299B60_de(float *arg0, float *arg1);

struct Msg;
struct Msg {
    s16 f0;
    s16 f2;
    s16 f4;
    s16 f6;
    s32 f8;
    s16 fC;
    s16 fE;
    s16 f10;
    s16 f12;
};

struct Callback;
struct Callback {
    s32 (*callback)(void);
    u8 pad4[0xC00];
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

struct Msg;
typedef struct Msg Msg;

struct func_8029BA34_S1;
typedef struct func_8029BA34_S1 func_8029BA34_S1;

struct EventCode80299DB4;
typedef struct EventCode80299DB4 EventCode80299DB4;

struct StreamBuffer;
extern void func_80299C80_de(struct StreamBuffer *arg0);

extern void func_8029AAAC_de();

extern void func_80299A5C_de(s32 *arg0, s32 *arg1);

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



extern void func_8029AA24_de(int arg0);

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

#endif
