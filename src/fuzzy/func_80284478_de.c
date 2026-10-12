#include "types.h"

struct PoolNode84478;
typedef struct PoolBucket84478 {
    struct PoolNode84478 *head;
    struct PoolNode84478 *tail;
    s32 data[3];
} PoolBucket84478;
typedef struct PoolOwner84478 {
    char pad0[0xFC00];
    PoolBucket84478 free;
    char padFC14[0x14];
    PoolBucket84478 slots[256];
} PoolOwner84478;
typedef struct PoolNode84478 {
    char pad0[0x5C];
    s32 state;
    char pad60[0x184];
    PoolBucket84478 *owner;
    char pad1E8[8];
    s32 counter;
    s32 flags;
} PoolNode84478;
extern void func_80255ED8_de(PoolBucket84478 *, PoolNode84478 *);
extern s32 func_80255CB8_de(PoolBucket84478 *, PoolNode84478 *);
extern void func_80284570_de(PoolOwner84478 *, PoolNode84478 *);

PoolNode84478 *func_80284478_de(PoolOwner84478 *owner, s32 index) {
    PoolNode84478 *node;
    PoolBucket84478 *slot;
    s32 i;
    if (owner->free.head == 0) {
        for (i = 0; i <= (index & 0xFF); i++) {
            node = owner->slots[i].tail;
            if (node != 0) {
                func_80284570_de(owner, node);
                break;
            }
        }
    }
    node = owner->free.head;
    if (node == 0) {
        return 0;
    }
    func_80255ED8_de(&owner->free, node);
    slot = &owner->slots[index & 0xFF];
    func_80255CB8_de(slot, node);
    node->owner = slot;
    node->flags = 0;
    node->counter = 0;
    node->state = 0x100;
    return node;
}
