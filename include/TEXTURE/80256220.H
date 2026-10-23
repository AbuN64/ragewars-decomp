#ifndef TEXTURE_80256220_H
#define TEXTURE_80256220_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
typedef struct AudioInitializeConfig {
    u8 reserved0[0x10]; s32 *(*callback)(s32 **);
    ALHeap *heap;
    s32 frequency;
} AudioInitializeConfig;
typedef struct AudioInitializeTiming { u32 frequency, frameTime, samples; } AudioInitializeTiming;
struct Chunk {
    u32 source; /* cartridge device address */
    void *destination;
    s32 length;
    void *queue;
    s32 value;
};
struct CartridgeReadRequest {
    u32 devAddr;
    void *buffer;
    s32 size;
    void *replyQueue;
    void *replyMsg;
    s32 active; /* 0x14 */
    void *next;
    void *prev;
};
struct Item57BD4 {
    s16 field0;
    s16 field2;
    s16 field4;
    u16 flags;
};
struct ObjectLinksC {
    u8 unk_0;
    unsigned char padding_1[3];
    s32 unk_4;
    s32 *unk_8;
};
typedef struct CacheCountdownEntry { struct CacheCountdownEntry *next; char pad4[4]; u16 state; } CacheCountdownEntry;
#endif
