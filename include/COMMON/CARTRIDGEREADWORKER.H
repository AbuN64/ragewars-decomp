#ifndef COMMON_CARTRIDGEREADWORKER_H
#define COMMON_CARTRIDGEREADWORKER_H
#include "TYPES.H"
#include "COMMON/PARAMSRECAT8V3.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct Chunk;

struct CartridgeReadWorker;
struct CartridgeReadWorker {
    u8 reserved[0x230];
    u8 requestQueueStorage;
    u8 reserved231[0xA48 - 0x231];
    u8 completionQueueStorage;
    u8 reservedA49[0x5068 - 0xA49];
    IntrusiveList available; /* 0x5068 */
    IntrusiveList pending; /* 0x507C */
};






struct Handles;
typedef struct Handles Handles;

struct Item57BD4;
typedef struct Item57BD4 Item57BD4;

struct Chunk;



extern int D_800CB708;


extern int D_800CB714;

struct CartridgeReadRequest;




struct Chunk;
struct Queue;

extern u32 func_802571F0_de(s32 offset, s32 length);

struct Window;
typedef struct Window Window;

struct Handles;
struct Handles {
    char pad0[0x60];
    s16 handles[17];
};


extern int D_801076A0;

struct Chunk;
typedef struct Chunk Chunk;

struct Item57BD4;

struct Window;
struct Window {
    struct Window *next;
    struct Window *prev;
    u32 base;
    u32 frame;
    s32 buffer;
};

struct ContextRecAt2BC0;
struct Voice;
typedef struct Voice Voice;



extern int D_800CD8C4_de;

struct Voice;
struct Voice {
    s32 unk0;
    s32 sound;
    s32 unk8;
    s32 unkC;
    u8 reserved10[8];
    s32 left; /* +0x18 */
    s32 right; /* +0x1C */
    u8 reserved20[0xC];
    f32 field2C; /* probe 20261019T020116365530Z */
    f32 field30;
    f32 field34;
    s16 priority;
    s16 channel;
    u8 reserved3C[8];
    CVector3 position; /* +0x44; probe 20261019T012703451174Z */
    u8 reserved50[4];
    s8 distanceMode;
    u8 reserved55[0x1F];
    u16 envelope[3];
    s16 envelopeFrames; /* +0x7A; probe 20261019T012704137584Z */
    u32 envelopeExtra;
    f32 envelopeValue, envelopeStep;
    u8 reserved88[0x18];
    s32 pending;
    s32 flags;
    s32 soundId;
    s32 fieldAC;
    struct ContextRecAt2BC0 *context; /* +0xB0; probe 20261019T012703451174Z */
    s32 fieldB4;
    f32 fieldB8;
    s32 fieldBC, fieldC0, fieldC4;
    f32 volumeScale;
};


struct CartridgeReadWorker;
typedef struct CartridgeReadWorker CartridgeReadWorker;

extern Window *D_80107DF4[];
extern u32 D_800CB700_de;
extern u32 D_800CB704_de;


struct ObjectLinksC;

struct CacheEntry;
struct CacheEntry {
    struct CacheEntry *next;
    void *key;
    u16 state;
    u16 size;
    s32 padC;
    char data[0x80];
};


struct ObjectLinksC;
typedef struct ObjectLinksC ObjectLinksC;

struct CartridgeReadRequest;
typedef struct CartridgeReadRequest CartridgeReadRequest;


struct CacheEntry;
typedef struct CacheEntry CacheEntry;



#include "COMMON/AUDIO_QUEUES.H"
#include "COMMON/AUDIO_SYNTH.H"
extern u32 D_800CB70C_de;
#endif
