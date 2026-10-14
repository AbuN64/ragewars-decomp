#include "span_1000/code_802B369C.h"
extern void *D_800D4070;




void func_802B3C24_de(void *arg0) {
    struct ALParam_s1C *parameter = arg0;
    ALGlobals *head = D_800D4070;
    parameter->next = head->drvr.paramList;
    head->drvr.paramList = arg0;
}
