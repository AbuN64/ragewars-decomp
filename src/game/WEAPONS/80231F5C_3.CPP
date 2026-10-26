#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "WEAPONS/80231F5C_3.H"
#include "WEAPONS/80213ED4.H"


/** Thin wrapper around func_80214178_de. */
void Weapon_ForwardActorStateRequest(void *arg0, void *arg1, s32 arg2) {
    Nav_RequestActorState(arg0, arg1, arg2);
}
