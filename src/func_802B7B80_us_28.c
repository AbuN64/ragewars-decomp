#include "span_1000/code_802B7B80.h"
#include "types.h"

/** CRC-5-style bit-shuffle: 16 rounds folding bit 10 of arg0 with a rotating tap. */
int func_802B8C40_de(unsigned int arg0) {
    int var_a1;
    int var_a2;
    int var_a3;
    unsigned int var_a0;
    unsigned int temp_v1;
    int temp_v0;

    var_a0 = arg0;
    var_a1 = 0;
    var_a3 = 0xF;
    do {
        var_a2 = 0;
        if (var_a1 & 0x10) {
            var_a2 = 0x15;
        }
        var_a1 = var_a1 * 2;
        temp_v1 = var_a0 >> 10;
        var_a0 = var_a0 * 2;
        temp_v0 = ((var_a1 & 0xFF) | (temp_v1 & 1)) ^ var_a2;
        var_a1 = temp_v0;
        var_a3 -= 1;
    } while (var_a3 >= 0);
    return temp_v0 & 0x1F;
}

/* __osContDataCrc, drafted from ultralib src/io/crc.c (the branch before 2.0J): the CRC of a
   32-byte Controller Pak block with generator 0x85, flushed with eight zero bits. */

u8 func_802B8C88_de(u8 *data)
{
    u8 temp = 0;
    u8 temp2;
    int i;
    int j;

    for (i = 0; i <= 32; i++) {
        for (j = 7; j > -1; j--) {
            temp2 = (temp & 0x80) ? 0x85 : 0;

            temp <<= 1;

            if (i == 32) {
                temp &= -1;
            } else {
                temp |= ((*data & (1 << j)) ? 1 : 0);
            }

            temp ^= temp2;
        }
        data++;
    }
    return temp;
}
