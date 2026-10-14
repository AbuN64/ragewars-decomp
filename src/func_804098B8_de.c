#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405DC0.h"
#include "types.h"

/* Returns the last word of a self-sized block: the first word holds the block's byte length and
   the result is the word just before that many bytes from the start. */
s32 func_804098B8_de(s32 *block) {
    return ((struct Shape_typemap_3 *) (block[0] + (s32) block))[-1].field_0;
}
