#include "span_1000/code_802636D0.h"
extern unsigned char D_8010FBE3[];

int func_80264614_de(int arg0) {
    return ((D_8010FBE3[arg0 * 4] >> 3) ^ 1) & 1;
}
