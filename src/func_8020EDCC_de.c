#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_8020EAE0.h"
/** Reset the float field of each occupied player slot's table entry to the default value. */
extern char D_8013B364[];

extern char *func_8020CFE0_de(char *, int);






void func_8020EDCC_de(char *arg0) {
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
