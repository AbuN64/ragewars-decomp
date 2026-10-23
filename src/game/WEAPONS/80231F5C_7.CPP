#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/TRIPLE.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOADSTATE.H"

extern void func_8022AF74_de(Shared_ActorView *arg0, s32 arg1);


void func_802328D8_de(Shared_ActorView *arg0, WeaponFireState *fireState) {
    Shared_ActorView *temp_a0;
    s16 idx;

    temp_a0 = arg0->self;
    idx = temp_a0->selectedAction;
    fireState->charge = ((WeaponInfo *)D_800D052C[idx])->chargeRate * D_800C3014_de;
    if ((temp_a0->selectedAction == 5) && (temp_a0->field11C0 == 0)) {
        func_8022AF74_de(temp_a0, 0x46A);
    }
}
