#include "span_16E000/code_8040F1E0.h"
#include "span_16E000/code_80411B68.h"
/* Runs func_80411518_de for each of the manager D_80153C20's entries unless its mode word at 0x34 is 1. */


extern Manager_func_80411D18_de D_80153C20;


void func_80411D18_de(void) {
    int i;

    if (D_80153C20.mode != 1) {
        for (i = 0; i < D_80153C20.count; i++) {
            func_80411518_de(i);
        }
    }
}
