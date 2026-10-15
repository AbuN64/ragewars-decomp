#include "span_1000/code_8023A284.h"
#include "span_1000/code_8023D370.h"
#include "types.h"
#include "common/unused.h"

/* Points the active table at D_801041F0 and runs the setup routine on the fixed record D_44B4A0. */

extern u8 D_801041F0[];

extern void *D_80103FCC;


extern void func_8023EE60_de(void *);

void func_8023EE00_de(void) {
    D_80103FCC = D_801041F0;
    func_8023EE60_de(D_0044A850);
}

/** Reset the selected fields of the current global record. */
void func_8023EE34_de(void) {
    Reusable *record = D_80103FCC;
    record->unk0 = 0;
    record->unk14 = -1;
    record->unk88 = 0;
    record->unk9C = 0;
    record->unkB0 = 0;
    record->unkB4 = 0;
    record->unkC4 = 0;
}
