#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80254CE4.h"
extern int D_80105180;

extern void func_80255FB8_de(void *arg0);




void func_80254DA4_de(void *arg0, void *arg1) {
    func_8022BC04_S3 *arg1_record = arg1;
    int *p = &D_80105180;
    arg1_record->unk10 = *p;
    func_80255FB8_de((char *)p - 0xC10);
}
