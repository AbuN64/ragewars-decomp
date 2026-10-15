#include "span_1000/code_8023D370.h"
#include "types.h"
/* Refills a reusable slot state and copies each list entry's packed record into its own struct. */







extern Reusable *D_80103FCC;




void func_8023EE60_de(EntryRecAt24 *arg0)
{
    EntryRecAt24 *e = arg0;
    s32 counter = -1;

    if (e->dst != 0) {
        do {
            Dst *dst = e->dst;

            D_80103FCC->unk0 = 0;
            D_80103FCC->unk14 = counter;
            D_80103FCC->unk88 = 0;
            D_80103FCC->unk9C = 0;
            D_80103FCC->unkB0 = 0;
            D_80103FCC->unkB4 = 0;
            D_80103FCC->unkC4 = 0;

            dst->unk0 = e->val0;
            dst->unk4 = e->flag0;
            dst->unk5 = e->flag1;
            dst->unk6 = e->flag2;
            dst->unk8 = e->x;
            dst->unkC = e->y;
            dst->unk10 = e->z;
            dst->unk14 = e->w;
            dst->unk18 = e->extra;
            e += 1;
        } while (e->dst != 0);
    }
}
