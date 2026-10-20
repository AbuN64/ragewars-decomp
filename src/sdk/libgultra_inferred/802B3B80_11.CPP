#include "sdk/BUF16B.H"

/** Copy the requested number of bytes. */
void func_802B0310_de(unsigned char *source, unsigned char *destination, int count) {
    int index;
    for (index = 0; index < count; index++) {
        *destination++ = *source++;
    }
}
