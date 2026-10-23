#ifndef COMMON_OBJRECAT26DD8_H
#define COMMON_OBJRECAT26DD8_H
#include "TYPES.H"
/* Independent simulation-time scale, adjacent to the current time step. */
extern f32 D_800D298C;
#include "COMMON/ITEMRECAT20V1.H"

struct Entry80294AC4;
struct ObjRecAt26DD8;
typedef struct ObjRecAt26DD8 ObjRecAt26DD8;

struct Entry80294AC4 {
    void (*callback)(void *arg0);
    s32 field4;
    s32 field8;
};

struct Entry80294AC4;
typedef struct Entry80294AC4 Entry80294AC4;



struct func_80294BB0_S1;
typedef struct func_80294BB0_S1 func_80294BB0_S1;


struct Prompt;
typedef struct Prompt Prompt;

struct Prompt;

struct func_80294BB0_S1;





extern float D_800C54DC_de;









struct func_80294AC4_S1;
typedef struct func_80294AC4_S1 func_80294AC4_S1;

struct Shape_func_8027ABF4_de_2;
struct Shape_func_8027ABF4_de_2 {
    unsigned char padding_0[4];
    int field_4;
};


extern float D_80142CB4;



struct func_802947DC_S1;
typedef struct func_802947DC_S1 func_802947DC_S1;


struct func_802947DC_S1;
struct func_802947DC_S1 {
    char pad0[0x26DBC];
    s32 unk26DBC;
    char pad26DBC[0x26DC1 - 0x26DBC - sizeof(s32)];
    s8 unk26DC1;
    char pad26DC1[0x26DD8 - 0x26DC1 - sizeof(s8)];
    s32 unk26DD8;
};

struct func_80294AC4_S1;
struct func_80294AC4_S1 {
    char pad0[0x26DB0];
    s32 unk26DB0;
    char pad26DB0[0x26DB8 - 0x26DB0 - sizeof(s32)];
    s32 unk26DB8;
    char pad26DB8[0x26DBC - 0x26DB8 - sizeof(s32)];
    s32 unk26DBC;
    char pad26DBC[0x26DD0 - 0x26DBC - sizeof(s32)];
    s32 unk26DD0;
};

extern void func_80294AB8_us(void);
extern void func_80294AC8_us(void);
extern void func_80294AD8_us(void);
#endif
