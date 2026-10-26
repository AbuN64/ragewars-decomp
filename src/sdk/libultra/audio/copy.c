#include "sdk/BUF16B.H"

/** Copy the requested number of bytes. */
void alCopy(unsigned char *source, unsigned char *destination, int count) {
    int index;
    for (index = 0; index < count; index++) {
        *destination++ = *source++;
    }
}
