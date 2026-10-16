#include "span_16E000/code_8044ACCC.h"
#include "span_1000/code_80255BEC.h"
#include "types.h"

/* Initialises the two lists at offsets 0x8B4 and 0x8A0 of a pool with node offsets 0 and 4
   through func_80255CA0_de, adds the pool's four entries of 0x228 bytes to the second list through
   func_80255D14_de and clears the halfword at 0x8C8. */




void func_8044A7D0_de(ObjRecAt8C8 *pool) {
    s32 i;
    struct EntryCode8044ACCC *entry;

    func_80255CA0_de(&pool->active, 0, 4);
    func_80255CA0_de(&pool->free, 0, 4);
    for (i = 0, entry = pool->entries; i < 4; i++, entry++) {
        func_80255D14_de(&pool->free, entry);
    }
    pool->unk8C8 = 0;
}
