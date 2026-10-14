#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802022E0.h"
typedef struct Owner Owner;



/** Return the nested record's field, or a fallback constant when zero. */
int func_80203A94_de(void *arg0) {
    int temp = ((struct MenuRules *) ((Owner *) arg0)->track)->locked;
    if (temp != 0) {
        return temp;
    }
    return 0x2F44;
}
