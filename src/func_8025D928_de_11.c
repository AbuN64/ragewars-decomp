#include "span_1000/code_802B339C.h"



/** Store the supplied halfword at offset 0x16. */
void func_802B3470_de(void *unused, void *object, unsigned short value) {
    func_802B8540_S1 *record = object;
    record->unk16 = value;
}
