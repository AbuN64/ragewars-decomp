#ifndef MENU_80442BC8_H
#define MENU_80442BC8_H
#include "TYPES.H"
#include "COMMON/PARTICLE_LIGHTING.H"
struct ItemRecAt14 {
    char pad[20];
    struct Binding *binding;
};
struct ObjectItemsDrawActorWithRedMenuEffect {
    char pad[0x140];
    Shared_ParticleLighting view[1];
};
#endif
