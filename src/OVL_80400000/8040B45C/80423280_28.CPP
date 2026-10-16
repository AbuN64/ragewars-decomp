#include "span_16E000/code_80423280.h"
#include "TYPES.H"
#include "common/unused.h"



extern s8 D_80102B0D[][400];
extern RecRecAt4 D_80146398[];

/* Adds the current record's deltas to both running totals of each player still in play, capping each at 99999. */
void func_80424B90_de(void) {
    s32 i;
    s32 v;
    RecRecAt4 *rec;

    for (i = 0; i < 4; i++) {
        if (D_80102B0D[i][0] >= 0) {
            rec = &D_80146398[i];
            v = D_800FEB6C[i][0] + rec->unk4;
            if (v > 99999) {
                D_800FEB6C[i][0] = 99999;
            } else {
                D_800FEB6C[i][0] = v;
            }
            v = D_800FEB74[i][0] + rec->unk2;
            if (v > 99999) {
                D_800FEB74[i][0] = 99999;
            } else {
                D_800FEB74[i][0] = v;
            }
        }
    }
}
