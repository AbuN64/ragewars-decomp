#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8028DF6C.h"
#include "types.h"








void func_8028F954_de(void *arg0, void *arg1) {
    void *temp_v0;

    if ((((struct OSScTask_s *)arg1)->list.type) == 2) {
        temp_v0 = ((OSSched *)arg0)->audioListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            ((OSSched *)arg0)->audioListHead = arg1;
        }
        ((OSSched *)arg0)->audioListTail = arg1;
        ((OSSched *)arg0)->doAudio = 1;
    } else {
        temp_v0 = ((OSSched *)arg0)->gfxListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            ((OSSched *)arg0)->gfxListHead = arg1;
        }
        ((OSSched *)arg0)->gfxListTail = arg1;
    }
    ((struct OSScTask_s *)arg1)->next = 0;
    ((struct OSScTask_s *)arg1)->state = (((struct OSScTask_s *)arg1)->flags) & 3;
}
