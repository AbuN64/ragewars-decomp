#include "span_16E000/code_80413728.h"


void func_80413720_de(struct Config *out, unsigned char type, short x, short y,
                  short a, short b, int enable1, int d, int e, int enable2,
                  int f, int g, short last) {
    out->type = type;
    out->x = x;
    out->y = y;
    out->flags = 0;
    out->last = last;
    out->a = a;
    out->b = b;
    out->g = e;
    out->d = d;
    out->f = g;
    out->e = f;
    if (enable1) {
        out->flags = 1;
    }
    if (enable2) {
        out->flags |= 2;
    }
}
