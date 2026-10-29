#ifndef AUDIO_INTEGERSTATE1DC4_H
#define AUDIO_INTEGERSTATE1DC4_H
#include "TYPES.H"

struct AudioLevelSettingView;
typedef struct AudioLevelSettingView AudioLevelSettingView;

struct SortTable;
typedef struct SortTable SortTable;

struct GameAudioContext;
extern void *Audio_GetMetadataSectionFiveEntry(struct GameAudioContext *audioContext, int entryIndex);

struct AudioWeightedVariantView;
struct AudioWeightedVariantView {
    char pad0[0x130];
    s32 lastPick;
    char pad134[0x2B54 - 0x134];
    s32 count;
    s32 ids;
    s32 *weights;
};

struct AudioWeightedVariantView;
typedef struct AudioWeightedVariantView AudioWeightedVariantView;

extern s32 Audio_ChooseWeightedSoundVariant(AudioWeightedVariantView *scene, s16 id, s16 avoid);

struct SortTable;
struct SortTable {
    char reservedHeader[0xE];
    s16 count;
    u32 entries[1];
};

extern void Audio_SortTableEntries(SortTable *table);

extern float g_audioLevelMaximum;

extern void Audio_SetVolumeSettingZero(struct GameAudioContext *audioContext, int volume);

extern void Audio_SetDialogVolume(struct GameAudioContext *object, float value);

extern int Audio_GetSpatialPanMode(void *object);

struct AudioLevelSettingView;
struct AudioLevelSettingView {
    char pad[0x2B9C];
    int level;
};

extern char *Audio_GetMetadataSectionThreeEntry(char *object, int index);

extern void Audio_SetSpatialPanMode(struct GameAudioContext *audioContext, int panMode);

extern int Audio_FindVoiceSlotById(char *context, int id);

extern void *Audio_GetMetadataSectionFourEntry(struct GameAudioContext *audioContext, int entryIndex);

extern double g_audioContextUnsignedValueCorrection;

extern void Audio_SetVolumeSettingOne(struct GameAudioContext *audioContext, float volume);

extern float g_audioLevelIntegerScale;
#endif
