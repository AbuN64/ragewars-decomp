#include "span_16E000/code_80429C10.h"
/* Maps a selection index to its code: 0 gives 5, 1 gives 7, 2 gives 17, 3 gives 11 and anything else
   0. */
int func_8042B154_de(int index) {
    int r;

    switch (index) {
    case 0:
        return 5;
    case 1:
        return 7;
    case 3:
        return 11;
    case 2:
        return 17;
    default:
        r = 0;
        break;
    }
    return r;
}
