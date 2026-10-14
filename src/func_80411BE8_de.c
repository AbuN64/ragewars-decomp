#include "span_16E000/code_80411B68.h"
/* Returns the signed byte at offset 0xA of entry j in the 8-byte entries that begin record i of
   the 1180-byte record table D_80153C28 points to. */
extern char *D_80153C28;

signed char func_80411BE8_de(int entry, int index) {
    char *record = D_80153C28 + index * 1180;
    int size;

    return ((struct ObjectStateB *) ((D_80153C28 + (index * 1180)) + (((unsigned char) entry) * (size = 8))))->unk_A;
}
