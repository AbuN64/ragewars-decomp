#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/OUTPUT.H"
#include "SCHED/8023A284.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CCOLLISIONSETUP_T.H"
#include "SCHED/8023A284_29.H"

/* Points the active collision state at D_801041F0 and fills the collision infos from the setup table
 * D_0044A850 (the KUSEG alias of D_8044A850). */

extern u8 D_801041F0[];

extern void *D_80103FCC;


extern CCollisionSetup_t D_0044A850[];
extern void func_8023EE60_de(CCollisionSetup_t *);

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
