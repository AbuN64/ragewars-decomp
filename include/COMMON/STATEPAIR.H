#ifndef COMMON_STATEPAIR_H
#define COMMON_STATEPAIR_H
#include "TYPES.H"
#include "COMMON/SELECTIONSCREENSTATE.H"

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















struct StatePair;

struct func_802A2EC0_S1;
typedef struct func_802A2EC0_S1 func_802A2EC0_S1;





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




/* Shared object layout established by command-list consumers. */
struct LinkedCommandEntry {
    u8 padding000[4];
    struct LinkedCommandEntry *next; /* 0x04 */
    u8 padding008[6];
    u16 kind; /* 0x0E */
    u8 command; /* 0x10, consumers only store this byte */
};
struct CommandListMenu {
    u8 padding000[8];
    struct LinkedCommandEntry *entries; /* 0x08 */
    u8 padding00C[0x48];
    s32 state; /* 0x54 */
};


struct Widget;
void func_802A2480_de(struct Widget *, struct Widget *);

extern void func_8042DEA0_de(void);
#endif
