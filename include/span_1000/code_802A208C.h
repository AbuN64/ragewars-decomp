#ifndef UNBAKE_SPAN_1000_CODE_802A208C_H
#define UNBAKE_SPAN_1000_CODE_802A208C_H
#include "types.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
extern void func_802A230C_de();

struct StatePair;
typedef struct StatePair StatePair;

struct func_802A2EC0_S1;
struct func_802A2EC0_S1 {
    char pad0[0x48];
    s32 unk48;
    char pad48[0x5C - 0x48 - sizeof(s32)];
    s32 unk5C;
};




extern int D_800CBC14;




extern void func_802A2434_de();











struct StatePair;
struct StatePair {
    f32 value;
    s32 state;
};

struct func_802A2EC0_S1;
typedef struct func_802A2EC0_S1 func_802A2EC0_S1;




extern void func_802A2320_de(void);

struct func_802A2D14_S1;
typedef struct func_802A2D14_S1 func_802A2D14_S1;

struct func_802A2D14_S1;
struct func_802A2D14_S1 {
    char pad0[0x4C];
    s32 unk4C;
    char pad4C[0x50 - 0x4C - sizeof(s32)];
    s32 unk50;
    char pad50[0x54 - 0x50 - sizeof(s32)];
    s32 unk54;
    char pad54[0x58 - 0x54 - sizeof(s32)];
    s32 unk58;
};

extern void func_802A2090_de();

extern void func_802A21F4_de();


/* Shared object layout established by command-list consumers. */
struct LinkedCommandEntry {
    u8 padding000[4];
    struct LinkedCommandEntry *next; /* 0x04 */
    u8 padding008[6];
    u16 kind; /* 0x0E */
    u8 command; /* 0x10, consumers only store this byte */
};
struct CommandListController {
    u8 padding000[8];
    struct LinkedCommandEntry *entries; /* 0x08 */
    u8 padding00C[0x3C];
    s32 progress; /* 0x48 */
    u8 padding04C[0x10];
    s32 state; /* 0x5C */
};
struct CommandListMenu {
    u8 padding000[8];
    struct LinkedCommandEntry *entries; /* 0x08 */
    u8 padding00C[0x48];
    s32 state; /* 0x54 */
};

extern void func_802A1D14_de(void *arg0);

s32 func_802A2480_de(s32, s32);

extern void func_8042DEA0_de(void);
extern void func_802A2400_de(f32);

#endif
