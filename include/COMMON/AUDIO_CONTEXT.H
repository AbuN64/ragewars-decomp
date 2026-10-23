#ifndef COMMON_AUDIO_CONTEXT_H
#define COMMON_AUDIO_CONTEXT_H
#include "TYPES.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/ALBANK_S.H"
struct GameplayCamera;
typedef struct ContextRecAt2BC0 ContextRecAt2BC0;
struct ContextRecAt2BC0 {
    char pad0[0x24];
    s32 field24;
    s32 field28;
    ALHeap *field2C;
    char pad30[0x7C - 0x30];
    ALBank_s *font; /* +0x7C: first bank in the relocated bank file */
    ALBankFile *resource;
    ALSndPlayer list[1]; /* +0x84, a single SDK sound player */
    s32 soundState; /* +0xD8, separately cleared before player construction */
    s16 handles[16]; /* +0xDC */
    u8 reservedFC[6];
    s16 selectedHandle; /* +0x102 */
    s32 frame; /* 0x104 */
    s32 soundCounter; /* +0x108 */
    s32 playIdCounter; /* +0x10C: recursive-lock protected playback id */
    MenuRules lock;
    s32 lastInstrument; /* +0x130: previous randomized variant */
    s32 track; /* 0x134 */
    char view[0x1D64 - 0x138];
    char panel[0x1D6C - 0x1D64];
    s32 field1D6C;
    char pad1D70[0x1DA8 - 0x1D70];
    ALHeap frames[1]; /* +0x1DA8; probe 20261019T012542972565Z */
    struct ContextRecAt2BC0 *menu[1]; /* +0x1DB8: voice pool owner */
    Voice voices[17]; /* 0x1DBC */
    void *soundData; /* +0x2B48 */
    s32 *instrumentIndex;
    void *sequenceIndex;
    s32 instrumentCount;
    s32 *instrumentData;
    s32 *envelopeData;
    s32 *sequenceData;
    s32 sequenceCount;
    u8 reserved2B68[8];
    void *table2B70;
    void *table2B74;
    void *table2B78;
    s32 tableCount2B7C, tableCount2B80, tableCount2B84;
    u8 *field2B88; /* byte range, Audio_InitializeVoiceMix */
    s16 field2B8C;
    char pad2B8E[2];
    s32 field2B90;
    u8 field2B94;
    char pad2B95[3];
    struct GameplayCamera *field2B98; /* listener, Audio_InitializeVoiceMix */
    s32 field2B9C;
    f32 red;
    f32 green;
    f32 blue;
    s32 field2BAC;
    s32 field2BB0;
    s32 field2BB4;
    s32 field2BB8;
    f32 alpha;
    char dialog[1];
};
/* The game's audio context: func_8025DE30_de initialises it through func_80257360_de. */
extern struct ContextRecAt2BC0 D_8010C080;

#endif
