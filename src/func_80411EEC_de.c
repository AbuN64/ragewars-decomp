#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Clears the 0x2A8-byte block D_801539B0 through func_802A0748_de, sets D_800E2AC0 and clears
   D_800E2AC4. */
extern char D_801539B0[];
extern s32 D_800E2AC0;
extern s32 D_800E2AC4;
extern void func_802A0748_de(void *, s32, s32);

void func_80411EEC_de(void) {
    func_802A0748_de(D_801539B0, 0, 0x2A8);
    D_800E2AC0 = 1;
    D_800E2AC4 = 0;
}
