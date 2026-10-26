#include "COMMON/PROBE.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/FIELD_VEC_B0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "particle/8024D018_4.H"
#include "WEAPONS/80213ED4_23.H"

void Weapons_SpawnFlaggedEffects(Player *actor, s32 *emittedFlags, s32 emissionFlag, s32 primaryEffectMask, s32 secondaryEffectMask) {
    s32 *entry;

    if ((emittedFlags[0] & emissionFlag) != 0) {
        return;
    }

    emittedFlags[0] |= emissionFlag;
    entry = D_800C8FF0_de;
    if (entry[0] != 0) {
        do {
            if ((primaryEffectMask & entry[0]) != 0) {
                InstHdr_PlayActorGraphSound(actor,
                              actor->pos,
                              entry[1],
                              Nav_RandomBetween(D_800C21D8_de, D_800C21DC_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }

    entry = D_800C90F8_de;
    if (entry[0] != 0) {
        do {
            if ((secondaryEffectMask & entry[0]) != 0) {
                InstHdr_PlayActorGraphSound(actor,
                              actor->pos,
                              entry[1],
                              Nav_RandomBetween(D_800C21E0_de, D_800C21E4_de));
            }
            entry += 2;
        } while (entry[0] != 0);
    }
}
