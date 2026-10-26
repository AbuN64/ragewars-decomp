#include "COMMON/ITEMRECAT20V1.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"

#if defined(VERSION_EU) || defined(VERSION_EU_X)
void Weapon_ApplySwitchAndSetSingleRound(void *arg0, func_80232A38_S1 *arg1) {
    Weapon_ApplyWeaponSwitch(arg0, arg1);
    arg1->unk13C = 1;
    arg1->unk144 = 1;
}
#endif
