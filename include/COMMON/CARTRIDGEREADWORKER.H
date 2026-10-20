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

struct func_802566A8_S1;
struct func_802566A8_S1 {
    char pad0[0x5068];
    char unk5068;
    char pad5068[0x507C - 0x5068 - sizeof(char)];
    char unk507C;
};

struct func_802566A8_S1;
typedef struct func_802566A8_S1 func_802566A8_S1;




struct Handles;
typedef struct Handles Handles;

struct Item57BD4;
typedef struct Item57BD4 Item57BD4;

struct Chunk;
struct Chunk {
    u32 source; /* cartridge device address */
    void *destination;
    s32 length;
    void *queue;
    s32 value;
};


struct func_8025663C_S1;
struct func_8025663C_S1 {
    char pad0[0x5068];
    IntrusiveList unk5068;
    char pad5068[0x507C - 0x5068 - sizeof(IntrusiveList)];
    char unk507C;
};

extern int D_800CB708;

struct func_8025844C_S1;
struct func_8025844C_S1 {
    char pad0[0x104];
    s32 unk104;
    char pad104[0x134 - 0x104 - sizeof(s32)];
    s32 unk134;
    char pad134[0x1DB8 - 0x134 - sizeof(s32)];
    void * unk1DB8;
    char pad1DB8[0x2BA0 - 0x1DB8 - sizeof(void*)];
    f32 unk2BA0;
    char pad2BA0[0x2BA4 - 0x2BA0 - sizeof(f32)];
    f32 unk2BA4;
    char pad2BA4[0x2BA8 - 0x2BA4 - sizeof(f32)];
    f32 unk2BA8;
    char pad2BA8[0x2BB0 - 0x2BA8 - sizeof(f32)];
    s32 unk2BB0;
    char pad2BB0[0x2BB4 - 0x2BB0 - sizeof(s32)];
    s32 unk2BB4;
};

extern int D_800CB714;

struct CartridgeReadRequest;
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

struct func_80257A34_S1;
struct func_80257A34_S1 {
    char pad0[0x7C];
    Handles unk7C;
    char pad7C[0x110 - 0x7C - sizeof(Handles)];
    char unk110;
    char pad110[0x138 - 0x110 - sizeof(char)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
    char pad1DB8[0x1DBC - 0x1DB8 - sizeof(char)];
    char unk1DBC;
};

extern int D_801076A0;

struct Chunk;
typedef struct Chunk Chunk;

struct Item57BD4;
struct Item57BD4 {
    s16 field0;
    s16 field2;
    s16 field4;
    u16 flags;
};

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

struct func_80257BD4_S1;
typedef struct func_80257BD4_S1 func_80257BD4_S1;

struct CartridgeReadWorker;
typedef struct CartridgeReadWorker CartridgeReadWorker;

extern Window *D_80107DF4[];
extern u32 D_800CB700_de;
extern u32 D_800CB704_de;

struct func_80257BD4_S1;
struct func_80257BD4_S1 {
    char pad0[0x110];
    char unk110;
    char pad110[0x138 - 0x110 - sizeof(char)];
    char unk138;
    char pad138[0x1DB8 - 0x138 - sizeof(char)];
    char unk1DB8;
    char pad1DB8[0x2B8C - 0x1DB8 - sizeof(char)];
    s16 unk2B8C;
    char pad2B8C[0x2B90 - 0x2B8C - sizeof(s16)];
    s32 unk2B90;
    char pad2B90[0x2B98 - 0x2B90 - sizeof(s32)];
    void * unk2B98;
};

struct ObjectLinksC;
struct ObjectLinksC {
    u8 unk_0;
    unsigned char padding_1[3];
    s32 unk_4;
    s32 *unk_8;
};

struct CacheEntry;
struct CacheEntry {
    struct CacheEntry *next;
    void *key;
    u16 state;
    u16 size;
    s32 padC;
    char data[0x80];
};

struct func_80257A34_S1;
typedef struct func_80257A34_S1 func_80257A34_S1;

struct ObjectLinksC;
typedef struct ObjectLinksC ObjectLinksC;

struct CartridgeReadRequest;
typedef struct CartridgeReadRequest CartridgeReadRequest;

struct func_8025663C_S1;
typedef struct func_8025663C_S1 func_8025663C_S1;

struct CacheEntry;
typedef struct CacheEntry CacheEntry;


struct func_8025844C_S1;
typedef struct func_8025844C_S1 func_8025844C_S1;

typedef struct CacheCountdownEntry { struct CacheCountdownEntry *next; char pad4[4]; u16 state; } CacheCountdownEntry;
#include "COMMON/AUDIO_QUEUES.H"
#include "COMMON/AUDIO_SYNTH.H"
extern u32 D_800CB70C_de;
typedef char Voice_size_check[(sizeof(Voice) == 0xCC) ? 1 : -1];
#endif
