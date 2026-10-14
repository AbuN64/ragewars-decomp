#include "span_1000/code_802508E0.h"



/** Return the nested signed byte unless flag 0x40 suppresses it. */
int func_80250A64_de(char *object) {
    if (((ObjectLinksDC *)(object))->unk_D8 & 0x40) {
        return 0;
    }
    return ((struct ObjectState13 *) ((ObjectLinksDC *) object)->unk_18)->unk_12;
}
