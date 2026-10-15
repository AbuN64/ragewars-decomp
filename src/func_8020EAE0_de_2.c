#include "span_1000/code_8020EAE0.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8fd754e1e915.h"
#include "shared/navigation_graph.h"
#include "types.h"

extern s32 func_8020D1CC_de(void *arg0, s32 arg1, s32 arg2);

extern s32 func_8020BC50_de(void *arg0, s32 arg1, s32 arg2, void *arg3);

/** Reset the float field of each occupied player slot's table entry to the default value. */


extern char *func_8020CFE0_de(char *, int);

extern void *func_8020C994_de(void *, s32);

s32 func_8020ED50_de(Func8020ED50Arg *arg0) {
    extern s32 D_8013B364;
    s32 *base;

    base = &D_8013B364;
    if (base != 0) {
        if (arg0->field10 == -1) {
            return 1;
        }
        if (arg0->field4 == arg0->field10) {
            return 1;
        }
        if (func_8020D1CC_de(base, arg0->field4, arg0->field10) == 0) {
            arg0->fieldC = func_8020BC50_de(base, arg0->field4, arg0->field10, arg0);
        }
    }
    return 1;
}

void func_8020EDCC_de(char *arg0) {
    extern char D_8013B364[];
    char *table = D_8013B364;
    int i;
    float value;

    if (table != 0) {
        value = D_800C1EDC_de;
        for (i = 0; i < 10; i++) {
            Actor1DC *a = ((struct ObjectLinks40 *) (arg0 + (i * 4)))->unk_3C;
            if (a != 0) {
                ((struct ObjRecAt18V3 *) func_8020CFE0_de(table, ((struct func_80203E78_S1 *) ((ObjectLinks1458 *) a->info)->unk_1454)->unk4))->unk18 = value;
            }
        }
    }
}

void func_8020EE50_de(void) {
    NavigationSearchNode *var_a0;
    f32 k;

    var_a0 = D_801372C8;
    if (var_a0 != 0) {
        k = D_800C1EE0_de;
        do {
            var_a0->extra =
                var_a0->extra +
                (f32) (var_a0->ticks * 0x1E) * k;
            var_a0 = var_a0->next;
        } while (var_a0 != 0);
    }
}

void func_8020EEA4_de(void) {
    extern s32 D_8013B364;
    NavigationGraph *base;
    NavigationSearchNode *node;
    NavigationPoint *result;
    f32 addVal;
    u16 field0E;

    base = (NavigationGraph *)&D_8013B364;
    node = base->nodes;
    if (node != 0) {
        addVal = D_800C1EE4_de;
        do {
            result = func_8020C994_de(base, node->key);
            if (result->flags & 1) {
                field0E = result->objectId;
                if (func_8020F55C_de(field0E) != 0 || func_8020F57C_de(result->objectId) != 0) {
                    node->extra = node->extra + addVal;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
