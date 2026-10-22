#include "sdk/libgultra.h"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/CONTREADFORMAT.H"

/** Store the low byte of the third argument in an indexed 0x30-byte record. */
void func_802B2ED0_de(ALSndPlayer *object, short index, unsigned char value) {
    ((ALSoundState *)object->sndState)[index].priority = value;
}
