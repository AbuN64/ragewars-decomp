#include "span_1000/code_8028DF6C.h"
#include "types.h"

extern s32 func_802BD170_de(s32);




void func_8028F8BC_de(void *arg0, void *arg1) {
    s32 saved;
    OSScClientWork *cur;
    OSScClientWork *prev;

    prev = 0;
    cur = ((OSSched *)arg0)->clientList;
    saved = func_802BD170_de(1);
    while (cur != 0) {
        if (cur == arg1) {
            if (prev != 0) {
                prev->next = cur->next;
            } else {
                ((OSSched *)arg0)->clientList = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    func_802BD170_de(saved);
}
