#include "types.h"
typedef struct Shared_HeapBlock Shared_HeapBlock;
struct Shared_HeapBlock {
    u32 start;
    u32 unknown4[2];
    u32 flags;
    u32 unknown10[5];
    Shared_HeapBlock *next;
};
typedef struct Shared_HashLink Shared_HashLink;
struct Shared_HashLink {
    u32 unknown0[3];
    Shared_HashLink *next;
};

#include "common/unused.h"
#include "types.h"

extern s32 D_800CB6F8;
extern s32 D_80101194;

void func_8025558C_de(void) {
    s32 var_a1;
    s32 var_v1;
    u32 var_a0;
    u32 var_a0_2;
    u32 limit;
    Shared_HashLink *var_v0;
    Shared_HashLink *buckets;

    var_a1 = 0;
    var_a0 = var_a1;
    limit = D_800CB6F0;
    if (limit != 0) {
        var_v1 = limit;
        do {
            var_a0 += 1;
        } while (var_a0 < (u32)var_v1);
    }
    var_a0_2 = 0;
    if (D_800CB6F0 != 0) {
        buckets = (Shared_HashLink *)D_80101194;
        do {
            var_v0 = &buckets[var_a0_2];
            var_v1 = 0;
            if (var_v0 != 0) {
                do {
                    var_v0 = var_v0->next;
                    var_v1 += 1;
                } while (var_v0 != 0);
            }
            if (var_v1 < var_a1) {
                var_v1 = var_a1;
            }
            var_a0_2 += 1;
            var_a1 = var_v1;
        } while (var_a0_2 < D_800CB6F0);
    }
    if (D_800CB6F8 != 0) {
        D_800CB6F8 = 0;
    }
}
