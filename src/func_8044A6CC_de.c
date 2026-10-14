#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_8044ACCC.h"
/* Updates each of the group's items (count at 0x8, 0xED8-byte records from the address at 0x4) through
   the block at 0x570 of each, then the group's own block at 0x5B0, all with func_8044A7D0_de. */


extern void func_8044A7D0_de(char *);

void func_8044A6CC_de(Triple *group) {
    int i;

    for (i = 0; i < group->z; i++) {
        func_8044A7D0_de((char *)(i * 0xED8 + group->y + 0x570));
    }
    func_8044A7D0_de((char *)group + 0x5B0);
}
