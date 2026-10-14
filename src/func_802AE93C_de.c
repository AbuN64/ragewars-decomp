#include "span_1000/code_802AE028.h"
#include "types.h"





void func_802AE93C_de(CopyDest802B3998 *src, CopySource802B3998 *dst) {
    s32 i;

    dst->word0 = src->word4;
    dst->word4 = src->wordC;
    dst->word8 = src->word10;
    for (i = 0; i < 16; i++) {
        dst->wordsC[i] = src->words18[i];
        dst->words4C[i] = src->words58[i];
        dst->bytes8C[i] = src->bytes98[i];
        dst->bytes9C[i] = src->bytesA8[i];
        dst->wordsAC[i] = src->wordsB8[i];
    }
}
