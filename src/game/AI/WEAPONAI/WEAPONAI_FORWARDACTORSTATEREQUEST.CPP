#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "WEAPONS/WEAPONAI_FORWARDACTORSTATEREQUEST.H"
#include "WEAPONS/ACTOR_REQUESTACTORSTATE.H"


/** Thin wrapper around func_80214178_de. */
void Weaponai_ForwardActorStateRequest(void *arg0, void *arg1, s32 arg2) {
    Actor_RequestActorState(arg0, arg1, arg2);
}
