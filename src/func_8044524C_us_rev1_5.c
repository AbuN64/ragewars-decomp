#include "span_16E000/code_80444EC0.h"
#include "types.h"

/* Forwards its three arguments to func_80444FA0_us_rev1 with 0, 0, 1, 0xFF and the pooled constant (1.0f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_8044524C_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 0, 0, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to func_80444FA0_us_rev1 with 0, 1, 1, 0xFF and the pooled constant (1.0f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_80445288_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 0, 1, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to func_80444FA0_us_rev1 with 0, 2, 1, 0xFF and the pooled constant (1.0f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_804452C4_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 0, 2, 1, 0xFF, (1.0f));
}

/* Forwards its three arguments to func_80444FA0_us_rev1 with 1, 8, 0xA, 0x7D0 and the pooled constant (1.0f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_80445304_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 1, 8, 0xA, 0x7D0, (1.0f));
}

/* Forwards its three arguments to func_80444FA0_us_rev1 with 2, 0x10, 0x66, 0xA000 and the pooled constant (10.239999771118164f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_80445344_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 2, 0x10, 0x66, 0xA000, (10.239999771118164f));
}

/* Forwards its three arguments to func_80444FA0_us_rev1 with 2, 0x14, 1, 0xB4 and the pooled constant
   (1.0f). */
extern void func_80444FA0_us_rev1(void *, void *, void *, s32, s32, s32, s32, f32);

void func_80445384_us_rev1(void *first, void *second, void *third) {
    func_80444FA0_us_rev1(first, second, third, 2, 0x14, 1, 0xB4, (1.0f));
}
