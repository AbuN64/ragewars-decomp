#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_8041DF04.h"
#include "types.h"
/* Returns the score of the three entries: 5, 10 or 20 points by kind for each active one, repeating the previous award for other kinds. */



extern struct EntryRecAt8V1 D_80153F80[];

s32 func_8041EBBC_de(void) {
    s32 score;
    s32 points;
    s32 i;

    score = 0;
    points = 0;
    for (i = 0; i < 3; i++) {
        if (D_80153F80[i].unused >= 0) {
            switch (D_80153F80[i].flags) {
            case 0:
                points = 5;
                break;
            case 1:
                points = 10;
                break;
            case 2:
                points = 20;
                break;
            }
            score += points;
        }
    }
    return score;
}
