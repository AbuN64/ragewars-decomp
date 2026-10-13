#include "span_1000/code_8023A284.h"





/** Compare two records by the float at nested offset 0x210. */
int func_8023B978_de(void *first, void *second) {
    Rotor *left = *(void **)first;
    Rotor *right = *(void **)second;
    int result = 1;
    if (left->speed <
        right->speed) {
        result = -1;
    }
    return result;
}
