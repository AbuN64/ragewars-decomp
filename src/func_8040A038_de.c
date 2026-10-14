#include "span_16E000/code_80409A88.h"
/* Returns the data table for a kind: kinds 1, 2 and 3 have their own, kind 0 and anything else use the
   first. */
extern char D_00450BF0_de[];
extern char D_00450C14_de[];
extern char D_00450C38_de[];
extern char D_00450C5C_de[];

char *func_8040A038_de(int unused, int kind) {
    switch (kind) {
    case 0:
    default:
        return D_00450BF0_de;
    case 1:
        return D_00450C14_de;
    case 2:
        return D_00450C38_de;
    case 3:
        return D_00450C5C_de;
    }
}
