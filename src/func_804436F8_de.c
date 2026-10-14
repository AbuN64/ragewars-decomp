#include "span_16E000/code_80443868.h"
#include "types.h"

/* Sets the byte at offset 0x8E of the object reached through offset 0x1C of the second argument
   and then offset 0x5D8, and returns one. */






s32 func_804436F8_de(void *unused, struct RootRecAt1C *root) {
    root->middle->leaf->flag = 1;
    return 1;
}
