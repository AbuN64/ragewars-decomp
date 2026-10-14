#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Calls func_8040F9E0_de when the halfword D_80153C2C is non-zero. */

extern void func_8040F9E0_de();

void func_80411DA4_de(void) {
    if (D_80153C2C != 0) {
        func_8040F9E0_de();
    }
}
