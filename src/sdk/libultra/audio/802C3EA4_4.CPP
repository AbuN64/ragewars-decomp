#include "COMMON/LLDIVRESULT.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "sdk/AUDIO/802C3EA4_4.H"

extern void Audio_DecodeFrame(void *arg0);





void *Audio_NextDecodedSampleBlock(void) {
    struct DecodeState *base = &D_8014BA38_de;
    unsigned short *counter;
    char *slots;
    unsigned short temp;

    if (base->count == 0) {
        return 0;
    }
    Audio_DecodeFrame(base);
    counter = &D_800D54C2;
    temp = *counter + 1;
    *counter = temp;
    if ((unsigned int)(temp & 0xFFFF) >= 6) {
        *counter = 0;
    }
    slots = &D_8014BCF0_de;
    Audio_DecodeTransformBlock(slots + (*counter << 9), base);
    base->count = base->count - 1;
    return slots + (*counter << 9);
}

/** Return the global state word. */
unsigned int Audio_GetDecodeFramesRemaining(void) {
    return D_8014BA38_de.count;
}

/** Clear the global word at VRAM 0x80151CD8. */
void Audio_ClearDecodeFramesRemaining(void) {
    D_8014BA38_de.count = 0;
}
