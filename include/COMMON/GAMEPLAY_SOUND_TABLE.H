#ifndef COMMON_GAMEPLAY_SOUND_TABLE_H
#define COMMON_GAMEPLAY_SOUND_TABLE_H
#include "TYPES.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
typedef struct GameplaySoundEntry { s32 *sound; s32 hook; } GameplaySoundEntry;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern GameplaySoundEntry D_800E45D4[];
extern f32 D_800D3F58, D_800C4DE0_eu;
#else
extern GameplaySoundEntry D_800D3F58[];
extern f32 D_800C1A6C_de, D_800C4B30_de;
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#define gameplaySoundValue(index) (D_800E45D4[index].sound[D_80145088.settings.language])
#else
#define gameplaySoundValue(index) (*D_800D3F58[index].sound)
#endif
static inline s32 gameplaySoundHook(s32 index) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800E45D4[index].hook;
#else
    return D_800D3F58[index].hook;
#endif
}
static inline f32 gameplaySoundWeight(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800D3F58;
#else
    return D_800C1A6C_de;
#endif
}
static inline f32 triggerSoundWeight(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
    return D_800C4DE0_eu;
#else
    return D_800C4B30_de;
#endif
}
#endif
