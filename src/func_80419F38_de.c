#include "span_16E000/code_804196C0.h"
#include "types.h"

/* Returns one when nothing is pending at offset 0x84 of an object, and otherwise whether the word
   at offset 0x44 is zero; func_80419F18_de sets the pending word and func_80419F24_de clears it. */


s32 func_80419F38_de(struct ObjectRecAt84 *object) {
    if (object->pending == 0) {
        return 1;
    }
    return object->busy == 0;
}
