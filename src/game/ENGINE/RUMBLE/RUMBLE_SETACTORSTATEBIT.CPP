#include "COMMON/PACKEDMESHMATERIAL.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/WORLD.H"
#include "RENDER/POOLRECAT28V1.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "RENDER/SETN64_GETPACKSECTION.H"


extern void SetN64_GetPackSectionSize(s32 arg0, s32 arg1);

void Rumble_SetActorStateBit(Shared_World *world, void *actor, s32 enabled) {
    LevelActor *entry;
    struct Def *cond;
    void *field80;
    void *table;
    u8 *base1;
    u8 *base2;
    s32 field1B40C;
    s32 mask;
    s32 index;
    s32 idx;
    s32 idx2;
    s32 lastOffset;
    u32 first;

    if (!(((LevelActor *)actor)->flags & 0x80000)) {
        first = (u32)world->actors;
        index = -1;
        if ((u32) actor >= first) {
            lastOffset = world->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32) actor) {
                index = ((u32) actor - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        return;
    }
    field1B40C = world->level;
    if (world->mode == 2) {
        return;
    }
    entry = &world->actors[index];
    cond = (struct Def *)entry->definition;
    if ((u32) (cond->type - 9) < 2) {
        if (cond->flags & 0x200) {
            return;
        }
    }
    field80 = world->bitSections;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 0);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base1 = (u8 *) SetN64_GetPackSection(table, 1);
    base2 = base1;
    mask = 1 << (index & 7);
    if (enabled != 0) {
        idx = index;
        if (index < 0) {
            idx = index + 7;
        }
        base1[idx >> 3] |= mask;
        return;
    }
    idx2 = index;
    if (idx2 < 0) {
        idx2 += 7;
    }
    base2[idx2 >> 3] &= ~mask;
}

s32 Rumble_TestActorStateBit(void *worldState, void *actorPointer) {
    Shared_World *world = worldState;
    LevelActor *actor = actorPointer;
    void *field80;
    void *table;
    u8 *base;
    s32 field1B40C;
    s32 mask;
    s32 index;
    s32 i;
    s32 lastOffset;
    u32 first;

    if (!(actor->flags & 0x80000)) {
        first = ((u32)world->actors);
        index = -1;
        if ((u32) actorPointer >= first) {
            lastOffset = world->actorCount * 0x2E8;
            lastOffset -= 0x2E8;
            if (first + lastOffset >= (u32) actorPointer) {
                index = ((u32) actorPointer - first) / 0x2E8;
            }
        }
    } else {
        index = -1;
    }
    if (index == -1) {
        return 0;
    }
    field80 = world->bitSections;
    field1B40C = world->level;
    table = SetN64_GetPackSection(SetN64_GetPackSection(SetN64_GetPackSection(field80, 0), field1B40C), 0);
    SetN64_GetPackSection(table, 0);
    SetN64_GetPackSectionSize((s32) table, 1);
    base = (u8 *) SetN64_GetPackSection(table, 1);
    mask = 1 << (index & 7);
    i = index;
    if (i < 0) {
        i += 7;
    }
    return (base[i >> 3] & mask) != 0;
}
