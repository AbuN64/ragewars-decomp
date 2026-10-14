#include "span_1000/code_80200400.h"
#include "span_1000/code_80200610.h"

extern s32 func_802005A0_de(s32 address);

void func_802012D8_de(void) {
    u32 savedSource;
    u32 cursor;
    u32 wordCount;
    u32 destination;
    register u32 i;

    savedSource = func_802005A0_de(0xB1FFFFF4) & 0xB1FFFFFC;
    cursor = func_802005A0_de(0xB1FFFFF8) & 0x01FFFFFC;
    func_80200568_de(0xB1FFFFFC, 0);

    while (func_802005A0_de(0xB0000010) == 0) {
        func_802005DC_de(500);
    }

    wordCount = cursor >> 2;
    i = 0;
    if (wordCount != 0) {
        destination = savedSource & 0xB07FFFFF;
        cursor = savedSource;
        do {
            func_80200568_de(destination, func_802005A0_de(cursor));
            destination += 4;
            i++;
            cursor += 4;
        } while (i < wordCount);
    }

    func_802005DC_de(2000);
    func_80200568_de(0xB1FFFFF4, 0);
    return;
}
