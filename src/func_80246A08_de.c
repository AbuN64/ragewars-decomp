#include "shared/level_actor.h"
#include "span_1000/code_80279208.h"
#include "common/types_8fd754e1e915.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */
#include "common/unused.h"
#include "span_1000/code_80245980.h"
#include "types.h"









extern s32 D_800C3864_de[];

extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void *func_8028FDB4_de(void *, s32);
extern s32 func_802654E8_de(void *, s32, s32);
extern void func_8027985C_de(WeightedTable *);
extern s32 func_80279864_de(WeightedTable *, s16, s16);
extern s16 func_802798A8_de(WeightedTable *);
extern void func_80253754_de(s32, void *);




s32 func_80246A08_de(LevelActor *arg0, s32 arg1, s32 arg2) {
    WeightedTable table;
    void **resource;
    s32 *entries;
    void *data;
    s32 count;
    s32 total;
    s32 original;

    if (!(arg0->flags & 0x40000)) {
        goto fail;
    }
    resource = func_8025193C_de(0, ((struct Access_s32_C4 *)(arg0))->field,
                             ((struct Access_s32_C4 *)(arg0))->field, ((struct Access_s32_D0 *)(arg0))->field,
                             0, 0, 0, D_800C3864_de, 1);
    if (resource == 0) {
        goto fail;
    }
    data = func_8028FDB4_de(*resource, 1);
    entries = &((struct func_80254D70_S2 *)(data))->unk8;
    total = ((struct func_80203E78_S1 *)(data))->unk4;
    count = func_802654E8_de(entries, ((struct Access_s8_E6 *)(arg0))->field, arg1);
    if (count != -1) {
        original = count;
        while (count > 0) {
            if (entries[count - 1] != arg1) {
                break;
            }
            count--;
        }

        func_8027985C_de(&table);
        if (arg2 == -1) {
            while (count < total && entries[count] == arg1) {
                func_80279864_de(&table, count++, 10);
            }
        } else {
            while (count < total && entries[count] == arg1) {
                if (arg2 != count) {
                    func_80279864_de(&table, count, 10);
                }
                count++;
            }
        }
        if (table.count == 0) {
            func_80279864_de(&table, original, 10);
        }
        count = func_802798A8_de(&table);
    }
    func_80253754_de(0, resource);
    return count;

fail:
    return -1;
}

