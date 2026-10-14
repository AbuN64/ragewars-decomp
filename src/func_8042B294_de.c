#include "span_16E000/code_80429C10.h"
/* Maps a selection index to its display code: 0 gives 2, 1 gives 3, 2 gives 1 and anything else 0. */
int func_8042B294_de(int index) {
    int r;

    switch (index) {
    default:
        r = 0;
        break;
    case 2:
        return 1;
    case 1:
        return 3;
    case 0:
        r = 2;
    }
    return r;
}
