#include "span_1000/code_80206258.h"
#include "types.h"

extern void func_8024B6A0_de(void *a, s32 c, s32 flag);
extern void func_802472F0_de(void *arg0);




void func_802065C0_de(void *a, void *b, s32 c) {
    ((ActorMotionState *)b)->action = -1;
    ((ActorMotionState *)b)->actionPending = 0;
    ((ActorMotionState *)b)->unk124 = c;
    func_8024B6A0_de(a, c, 1);
    func_802472F0_de(a);
}
