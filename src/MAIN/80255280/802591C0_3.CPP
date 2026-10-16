#include "MAIN/80255280.H"
#include "span_1000/code_802591C0.h"
/* Returns 1 when the object's owner at 0x102 is set, or when the id is below 256 and at least six of
   its seventeen 0xCC-byte slots at 0x1E64 already carry that id; otherwise 0. */




int func_80259200_de(ObjRecAt1E64 *obj, int id) {
    int count;
    int i;

    if (obj->owner != -1) {
        return 1;
    }
    if (id < 256) {
        count = 0;
        for (i = 0; i < 17; i++) {
            if (obj->slots[i].id == id) {
                count++;
            }
        }
        if (count >= 6) {
            return 1;
        }
    }
    return 0;
}
