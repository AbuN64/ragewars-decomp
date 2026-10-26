#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "TYPES.H"





void func_8022B984_de(struct SharedPlayer *actor) {
    if (actor->views5E8.view1210_152.unk1210 == 0) {
        Weapons_SetPlayerState(actor, actor, 0x27);
        actor->views5E8.view1210_152.unk1210 = 1;
        actor->views5E8.view1214_154.unk1214 = 0;
    }
}
