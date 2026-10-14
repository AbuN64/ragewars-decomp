#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80403BCC.h"
/* For a player slot whose state D_801534F0 is 3, writes its score (the first word of its 0x204-byte
   record in D_800E2854 divided by 256, or 0 when the flag D_80153500 is set) and returns the flag;
   other states return -2. */


extern int *D_800E2854;

int func_80405160_de(int slot, int *score) {
    if (D_801534F0[slot] != 3) {
        return -2;
    }
    if (D_80153500[slot] == 0) {
        *score = D_800E2854[slot * 0x81] / 256;
    } else {
        *score = 0;
    }
    return D_80153500[slot];
}
