#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_80203F04.h"
#include "types.h"
#include "common/unused.h"

extern void func_80285DB0_de(void *, void *, s32);
extern void func_80278D78_de(void *arg0, s32 arg1, void *arg2);
extern void func_802A5D38_de(void *, s32);









void func_80204658_de(void *arg0) {
    BreakableDefinition *temp_s1;
    s32 temp_v1;
    s32 masked;
    Shared_World *pFlag;

    temp_s1 = (BreakableDefinition *)((Actor_func_8024A7A0_de *)arg0)->definition;
    pFlag = &D_8011FE88;
    func_80285DB0_de(pFlag, arg0, 1);
    if (D_800C8270_de == 0) {
        func_80278D78_de(arg0, 0x80000, arg0);
    }
    func_802A5D38_de(&D_801379C0, arg0);
    if (pFlag->mode != 4) {
        temp_v1 = ((Actor_func_8024A7A0_de *)arg0)->flags | 0x08000000;
        ((Actor_func_8024A7A0_de *)arg0)->flags = temp_v1;
        if (temp_s1->flags & 2) {
            masked = temp_v1 & ~0x2000;
            masked = masked & ~0x100;
            ((Actor_func_8024A7A0_de *)arg0)->flags = masked;
        }
        if (((BreakableDefinition *)((Actor_func_8024A7A0_de *)arg0)->definition)->health == 0) {
            ((Actor_func_8024A7A0_de *)arg0)->flags = ((Actor_func_8024A7A0_de *)arg0)->flags & ~0x100;
        }
    }
}
