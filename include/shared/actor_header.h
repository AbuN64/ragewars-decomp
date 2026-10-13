#ifndef RW_ACTOR_HEADER_H
#define RW_ACTOR_HEADER_H
#include "types.h"
/* Common actor header occupies player offsets 0 through 0x1B. */
struct Model_func_80223E34_de;
struct Object {
    char pad[0x18];
    struct Model_func_80223E34_de *owner;
    u8 reserved1C[0x740 - 0x1C];
    u8 effect740;
};

#endif
