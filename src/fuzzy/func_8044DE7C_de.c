#include "span_16E000/code_8044ACCC.h"
#include "types.h"

struct ResetActorDE7C {
    char pad0[0x26825];
    u8 enabled;
    char pad26826[0x596];
    s32 state;
    char pad26DC0;
    u8 phase;
    char pad26DC2[0x16];
    s32 key;
    s32 counter;
};
struct ResetMenuDE7C {
    s32 first, second, third, fourth;
    char pad10[0x78];
    s32 counter;
    char pad8C[0x20];
    s32 enabled;
};
extern World D_8011FE88;
extern struct ResetMenuDE7C D_801468A0;
extern s32 func_8044D220_de(World *, s32, s32, Object_func_8044D220_de *, s32);

void func_8044DE7C_de(struct ResetActorDE7C *actor, s32 key) {
    Object_func_8044D220_de entry;
    s32 next;
    if (func_8044D220_de(&D_8011FE88, -1, key, &entry, 1) == 0) {
        key = 0;
    }
    D_801468A0.first = 0;
    D_801468A0.second = 0;
    D_801468A0.third = 0;
    D_801468A0.fourth = 0;
    D_801468A0.counter = 0;
    actor->counter = 0;
    actor->key = key;
    if (actor->enabled != 0 && D_801468A0.enabled != 0) {
        actor->phase = 2;
        next = 13;
    } else {
        actor->phase = 2;
        next = 12;
    }
    actor->state = next;
}
