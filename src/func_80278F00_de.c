#include "span_1000/code_80277444.h"
#include "types.h"



extern void func_80278C10_de(void *);

void func_80278F00_de(Record14 *arg0) {
    Record14 copy;
    u8 *bytes = (u8 *)arg0;

    bytes[0xE] |= 0x20;
    if (bytes[0x11] == 1) {
        copy = *arg0;
        ((u8 *)&copy)[0x12] = 2;
        ((u8 *)&copy)[0x10] = 0;
        func_80278C10_de(&copy);
    }
}
