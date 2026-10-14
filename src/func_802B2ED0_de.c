#include "span_1000/code_802B7488.h"
#include "span_1000/code_802B2614.h"





/** Store the low byte of the third argument in an indexed 0x30-byte record. */
void func_802B2ED0_de(ALSndPlayer *object, short index, unsigned char value) {
    ((ALSoundState *)object->sndState)[index].priority = value;
}
