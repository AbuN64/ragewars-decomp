#ifndef UNBAKE_SPAN_1000_CODE_802A208C_H
#define UNBAKE_SPAN_1000_CODE_802A208C_H
#include "../types.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
/* unbake published declaration: published_05bfb7d7cd12aa850acf6088 */
extern void func_802A230C_de();

struct StatePair;
/* unbake published declaration: published_0921c3a33885685460081cef */
typedef struct StatePair StatePair;

struct func_802A2EC0_S1;
/* unbake published declaration: published_0a01d7152728076abd992447 */
struct func_802A2EC0_S1 {
    char pad0[0x48];
    s32 unk48;
    char pad48[0x5C - 0x48 - sizeof(s32)];
    s32 unk5C;
};


/* unbake published declaration: published_0afbf7aacfab4802d22bf804 */


/* unbake published declaration: published_15a9e07a38c33674102c5a91 */
extern int D_800CBC14;


/* unbake published declaration: published_1726470f0211657921eb8cea */


/* unbake published declaration: published_1c53b71059825d572eabe55a */
extern void func_802A2434_de();


/* unbake published declaration: published_27243183bc708630580309ca */



/* unbake published declaration: published_40a6528b7cc0fc51c73f17c2 */


/* unbake published declaration: published_48a1610c68f14e6d4faffffc */


/* unbake published declaration: published_4c7b39aa472d1d1455221971 */


struct StatePair;
/* unbake published declaration: published_5ce02486e8173493be78337d */
struct StatePair {
    f32 value;
    s32 state;
};

struct func_802A2EC0_S1;
/* unbake published declaration: published_5e604a54ae31ebf0eb623df2 */
typedef struct func_802A2EC0_S1 func_802A2EC0_S1;


/* unbake published declaration: published_7bc108cbf96fe5d4a0ca8969 */


/* unbake published declaration: published_85ecdd5e5f3dd284605569f3 */
extern void func_802A2320_de(void);

struct func_802A2D14_S1;
/* unbake published declaration: published_b0409229b87d81614a0b0e57 */
typedef struct func_802A2D14_S1 func_802A2D14_S1;

struct func_802A2D14_S1;
/* unbake published declaration: published_c6cae1cb4a84c4cf09647a97 */
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

/* unbake published declaration: published_e20165985f7d5212c988465d */
extern void func_802A2090_de();

/* unbake published declaration: published_fc3048a2b4b30dedb38be5e5 */
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

#endif
