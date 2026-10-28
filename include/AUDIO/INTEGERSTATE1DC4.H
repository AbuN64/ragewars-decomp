#ifndef AUDIO_INTEGERSTATE1DC4_H
#define AUDIO_INTEGERSTATE1DC4_H
#include "TYPES.H"

struct ObjRecAt2B9C;
typedef struct ObjRecAt2B9C ObjRecAt2B9C;

struct SortTable;
typedef struct SortTable SortTable;

struct ContextRecAt2BC0;
extern void *Audio_GetMetadataSectionFiveEntry(struct ContextRecAt2BC0 *arg0, int arg1);

struct SceneRecAt2B5C;
struct SceneRecAt2B5C {
    char pad0[0x130];
    s32 lastPick;
    char pad134[0x2B54 - 0x134];
    s32 count;
    s32 ids;
    s32 *weights;
};

struct SceneRecAt2B5C;
typedef struct SceneRecAt2B5C SceneRecAt2B5C;

extern s32 Audio_ChooseWeightedSoundVariant(SceneRecAt2B5C *scene, s16 id, s16 avoid);

struct SortTable;
struct SortTable {
    char unknown00[0xE];
    s16 count;
    u32 entries[1];
};

extern void Audio_SortTableEntries(SortTable *table);

extern float D_800C8FE0;

extern void Audio_SetVolumeSettingZero(struct ContextRecAt2BC0 *arg0, int arg1);

extern void Audio_SetDialogVolume(struct ContextRecAt2BC0 *object, float value);

extern int Audio_GetSpatialPanMode(void *object);

struct ObjRecAt2B9C;
struct ObjRecAt2B9C {
    char pad[0x2B9C];
    int level;
};

extern char *Audio_GetMetadataSectionThreeEntry(char *object, int index);

extern void Audio_SetSpatialPanMode(struct ContextRecAt2BC0 *arg0, int arg1);

extern int Audio_FindVoiceSlotById(char *arg0, int id);

extern void *Audio_GetMetadataSectionFourEntry(struct ContextRecAt2BC0 *arg0, int arg1);

extern double D_800C3EE8_de;

extern void Audio_SetVolumeSettingOne(struct ContextRecAt2BC0 *arg0, float arg1);

extern float D_800C8FE4;
#endif
