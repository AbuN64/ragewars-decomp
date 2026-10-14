#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"
/* Counts the four player records whose byte 0x78 is one and returns 3, 2 or 1 for one, two or three such players, otherwise zero. */



extern Player_func_8041EAC4_de D_80146398[];

s32 func_8041EAC4_de(void) {
    s32 count;
    s32 i;
    s32 result;
    Player_func_8041EAC4_de *player;

    count = 0;
    player = D_80146398;
    for (i = 0; i < 4; i++) {
        if (player[i].active == 1) {
            count++;
        }
    }
    result = 0;
    switch (count) {
    case 1:
        result = 3;
        break;
    case 2:
        result = 2;
        break;
    case 3:
        result = 1;
        break;
    }
    return result;
}
