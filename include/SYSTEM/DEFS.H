#ifndef SYSTEM_DEFS_H
#define SYSTEM_DEFS_H
#include "TYPES.H"
#include "COMMON/LIGHTDATA.H"
struct LightNode {
    char pad0[8];
    LightData *data;
    f32 intensity;
    s16 position[3];
    s16 active;
};
/* Text formatting helpers: each passes its arguments on to sprintf unchanged. */
extern void Defs_FormatIntegerValue(char *buffer, const char *format, s32 value);
extern void Defs_FormatSingleInteger(char *buffer, const char *format, s32 value);
extern void Defs_FormatThreeIntegers(char *buffer, const char *format, s32 a, s32 b, s32 c);
extern void Defs_FormatFourIntegers(char *buffer, const char *format, s32 a, s32 b, s32 c, s32 d);
extern s32 Defs_FindSortedGroupRange(u32 *sortedGroups, s32 count, u32 group, s32 *first, s32 *last);
#endif
