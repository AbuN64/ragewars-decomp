#include "span_1000/code_802591C0.h"
#include "types.h"



void *func_80259694_de(LinkPair *arg0) {
    arg0->first[1] = (void *) arg0->second;
    arg0->second[0] = (void *) arg0->first;
    return arg0;
}
