#include "include_asm.h"

#include "COMMON/RESULTS.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "RENDER_4/8028FD2C_11.H"
#include "COMMON/TRIPLE.H"
typedef struct EffectDefinitionBounds {
    ActorDefinitionHeader header;
    f32 boundsA;
    f32 boundsB;
} EffectDefinitionBounds;
extern void func_80219460_de(void *definition);
/* Initialises the pool of 32 effect slots in a world record: threads them into a free list (slot 0 has no
 * predecessor, slot 31 no successor), empties the live list, sets up the two shared effect definitions
 * and points every slot at the default definition through func_80290408_de. */
void Ovlgame_InitEffectPool(WorldRecAt3C08 *world) {
    s32 i;

    world->free = world->slots;
    world->tail = 0;
    world->head = 0;
    for (i = 0; i < EFFECT_SLOTS - 1; i++) {
        world->slots[i].next = &world->slots[i + 1];
        world->slots[i].prev = &world->slots[i - 1];
    }
    world->slots[0].prev = 0;
    world->slots[EFFECT_SLOTS - 1].next = 0;
    func_80219460_de(&D_8011B388);
    ((ActorDefinitionHeader *)&D_8011B388)->kind = 8;
    ((ActorDefinitionHeader *)&D_8011B388)->flags = 1;
    ((ActorDefinitionHeader *)&D_8011B388)->send = 0;
    func_80219460_de(&D_8011B200);
    ((EffectDefinitionBounds *)&D_8011B200)->header.kind = 8;
    ((EffectDefinitionBounds *)&D_8011B200)->header.flags = 0;
    ((EffectDefinitionBounds *)&D_8011B200)->header.send = 0;
    ((EffectDefinitionBounds *)&D_8011B200)->boundsA = D_800C5390_de;
    ((EffectDefinitionBounds *)&D_8011B200)->boundsB = D_800C5390_de;
    for (i = 0; i < EFFECT_SLOTS; i++) {
        func_80290408_de(&world->slots[i]);
    }
}


#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", rodata_unresolved_8044F05C);
#endif
