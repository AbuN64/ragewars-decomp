#include "span_1000/code_802AE028.h"




void func_802AE8C8_de(CopyDest802B3998 *dst, CopySource802B3998 *src) {
    int i;

    dst->word4 = src->word0;
    dst->wordC = src->word4;
    dst->word10 = src->word8;
    for (i = 0; i < 16; i++) {
        dst->words18[i] = src->wordsC[i];
        dst->words58[i] = src->words4C[i];
        dst->bytes98[i] = src->bytes8C[i];
        dst->bytesA8[i] = src->bytes9C[i];
        dst->wordsB8[i] = src->wordsAC[i];
    }
}
