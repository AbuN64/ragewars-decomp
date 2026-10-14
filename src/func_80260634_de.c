#include "span_1000/code_8025E568.h"
/** Scale a value by the maximum integer represented by a bit count. */
float func_80260634_de(float value, int bits) {
    return value / (float)((1 << bits) - 1);
}
