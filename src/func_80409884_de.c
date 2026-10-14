#include "span_16E000/code_80405DC0.h"
#include "types.h"

/* Returns the address of block n, n times 256; block zero is the area 0x610 bytes into the
   buffer D_8011FECC points to. */
extern char *D_8011FECC;

char *func_80409884_de(s32 block) {
    if (block == 0) {
        return D_8011FECC + 0x610;
    }
    return (char *) (block << 8);
}
