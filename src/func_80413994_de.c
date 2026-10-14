#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"

/* Sets the read position D_80153C78 to row y of column x, the row stride being the halfword at
   offset 8 of the structure D_80153D54 points to, calls the reader D_80153CD8 points to, and
   returns the value it left in D_80153C80. */


extern struct func_8022BECC_S2 *D_80153D54;
extern void (*D_80153CD8)(void);
extern s32 D_80153C78;
extern s32 D_80153C80;

s32 func_80413994_de(s32 x, s32 y) {
    D_80153C78 = x + y * D_80153D54->unk8;
    D_80153CD8();
    return D_80153C80;
}
