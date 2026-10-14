#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8028CCB8.h"
#include "types.h"
/* Releases the resource of each of the owner's listed entries through func_80253754_de, then clears the counters at 0x944, 0xC4C and 0x10BC, and moves the entry count to 0x1500 and zeroes it. */





extern void func_80253754_de(s32, s32);

void func_8028D888_de(Owner_func_8028D888_de *owner) {
    s32 i;
    s32 n;
    s32 count;
    Triple *entries;

    n = owner->count;
    entries = owner->entries;
    for (i = 0; i < n; i++) {
        func_80253754_de(0, entries[i].x);
    }
    count = owner->count;
    owner->unk944 = 0;
    owner->unkC4C = 0;
    owner->unk10BC = 0;
    owner->count = 0;
    owner->prevCount = count;
}
