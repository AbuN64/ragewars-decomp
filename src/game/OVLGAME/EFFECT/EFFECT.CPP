#include "COMMON/ACTOR_DEFINITION.H"
#include "include_asm.h"
#include "COMMON/RESULTS.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "RENDER_4/8028FD2C_11.H"
#include "COMMON/TRIPLE.H"

extern void func_80219460_de(void *definition);
/* Initialises the pool of 32 effect slots in a world record: threads them into a free list (slot 0 has no
 * predecessor, slot 31 no successor), empties the live list, sets up the two shared effect definitions
 * and points every slot at the default definition through SetN64_InitializeEffectSlot. */
void Effect_InitEffectPool(WorldRecAt3C08 *world) {
    s32 i;

    world->free = world->slots;
    world->tail = 0;
    world->head = 0;
    for (i = 0; i < EFFECT_SLOTS - 1; i++) {
        world->slots[i].next = &world->slots[i + 1];
        world->slots[i].prev = (struct EffectSlot *)((u32)world->slots + (i - 1) * sizeof(world->slots[0]));
    }
    world->slots[0].prev = 0;
    world->slots[EFFECT_SLOTS - 1].next = 0;
    func_80219460_de(&g_defaultEffectDefinition);
    ((ActorDefinitionHeader *)&g_defaultEffectDefinition)->kind = 8;
    ((ActorDefinitionHeader *)&g_defaultEffectDefinition)->flags = 1;
    ((ActorDefinitionHeader *)&g_defaultEffectDefinition)->send = 0;
    func_80219460_de(&g_boundedEffectDefinition);
    ((EffectDefinitionBounds *)&g_boundedEffectDefinition)->header.kind = 8;
    ((EffectDefinitionBounds *)&g_boundedEffectDefinition)->header.flags = 0;
    ((EffectDefinitionBounds *)&g_boundedEffectDefinition)->header.send = 0;
    ((EffectDefinitionBounds *)&g_boundedEffectDefinition)->boundsA = D_800C5390_de;
    ((EffectDefinitionBounds *)&g_boundedEffectDefinition)->boundsB = D_800C5390_de;
    for (i = 0; i < EFFECT_SLOTS; i++) {
        SetN64_InitializeEffectSlot(&world->slots[i]);
    }
}

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_8044F05C[1] = {
    0x0044309C,
};
#endif

/* ROM-grounded data: src/rw_pool_8044DB70_CB080_us_rev1.c */
const unsigned int D_blob_6f8820d74bd3dac26c79[1] = {
    0x42F5C28F,
};
