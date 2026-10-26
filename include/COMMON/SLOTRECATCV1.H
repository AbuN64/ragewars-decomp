#ifndef COMMON_SLOTRECATCV1_H
#define COMMON_SLOTRECATCV1_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct SlotRecAtCV1;
struct SlotRecAtCV1 {
    char pad0[8];
    u16 flags;
    char padA[2];
    char data[0x20];
};

struct EntryCode8040B45C80411518;
struct SlotRecAtCV1;
struct EntryCode8040B45C80411518 {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct SlotRecAtCV1 **ns;
    char pad488[4];
    ObjRecAtE *def;
    char pad490[0xC];
};
struct EntryCode8040B45C80411518;
struct PoolFrontendReleaseChunkImages;
struct PoolFrontendReleaseChunkImages {
    s16 count;
    char pad2[6];
    struct EntryCode8040B45C80411518 *entries;
};


extern void Frontend_SkipResourceOperation(void);

struct EntryRecAt18V1;
typedef struct EntryRecAt18V1 EntryRecAt18V1;


struct SlotRecAtCV2;
struct SlotRecAtCV2 {
    char pad0[4];
    s32 owner;
    u16 flags;
    char padA[2];
    char data[0x20];
};


struct ChunkRecAt48C;
struct ChunkRecAt48C {
    char pad[0x484];
    void **primary;
    void **optional;
    char rest[0x10];
};


struct ResourceFrontendUpdateImageReleaseTimers;
struct ResourceFrontendUpdateImageReleaseTimers {
    void *data;
    s32 flags;
    char pad8[0x14];
};
struct TimerFrontendUpdateImageReleaseTimers;
struct TimerFrontendUpdateImageReleaseTimers {
    s32 owner;
    s16 delay;
};
struct PoolRecAtC;
struct ResourceFrontendUpdateImageReleaseTimers;
struct TimerFrontendUpdateImageReleaseTimers;
struct PoolRecAtC {
    s16 count;
    struct ResourceFrontendUpdateImageReleaseTimers *resources;
    s32 unk8;
    struct TimerFrontendUpdateImageReleaseTimers *timers;
};

struct Field_u16_14;


extern int g_frontendResourceFirstScreen;




struct QuadRecAt2C;
struct QuadRecAt2C {
    char pad[0x2C];
    s32 values[4];
};

extern s32 Frontend_GetFirstResourceScreen(void);

struct PoolFrontendReleaseChunkImages;
typedef struct PoolFrontendReleaseChunkImages PoolFrontendReleaseChunkImages;

struct ButtonWidget;
typedef struct ButtonWidget ButtonWidget;



struct SlotRecAtCV1;
typedef struct SlotRecAtCV1 SlotRecAtCV1;



extern s16 Frontend_GetTextureEntryHeight(s32 index);

struct EntryCode8040B45C;
struct SlotRecAtCV2;
struct EntryCode8040B45C {
    s32 active;
    char pad4[0x300];
    void *buffers[0x60];
    struct SlotRecAtCV2 **pages;
    char pad488[4];
    ObjRecAtE *def;
    unsigned char refCount;
    char pad491[0xB];
};
struct EntryCode8040B45C;
struct PoolFrontendReleaseActiveChunkImages;
struct PoolFrontendReleaseActiveChunkImages {
    s16 count;
    char pad2[6];
    struct EntryCode8040B45C *entries;
};

struct Style;
struct Style {
    f32 scaleX;
    f32 scaleY;
    s32 v[5];
};

struct UiWidget;
struct UiWidget {
    s32 name;
    struct UiWidget *next;
    struct UiWidget *children;
    char padC[2];
    u16 type;
    char pad10[2];
    u16 flags;
    char pad14[0x18];
    s32 words[4];
    char pad3C[8];
    s32 extra;
};

extern s16 Frontend_GetResourceScreenCount(void);

struct FileHeader;
typedef struct FileHeader FileHeader;

struct EntryRecAt18V1;
struct EntryRecAt18V1 {
    s32 unk0;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

struct EntryRecAt18V1;
struct FileHeader;
struct FileHeader {
    char pad0[0x25C];
    struct EntryRecAt18V1 *unk25C;
};

struct UiWidget;
typedef struct UiWidget UiWidget;

struct Pair2C;
struct Pair2C {
    char pad[0x2C];
    u8 first;
    u8 second;
};

struct Pair2C;

extern s16 Frontend_GetTextureEntryWidth(s32 index);



struct SlotRecAtCV2;
typedef struct SlotRecAtCV2 SlotRecAtCV2;

struct Style;
typedef struct Style Style;



struct PoolRecAtC;
typedef struct PoolRecAtC PoolRecAtC;

struct Pair14;
struct ButtonWidget;
struct ButtonWidget {
    char pad0[0x2C];
    struct Pair14 *normal;
    struct Pair14 *highlighted;
    struct Pair14 *pressed;
};

struct FileState;
struct EntryRecAt8V1;
struct ResourceRecAt6;
struct ChunkFrontendEvictExpiredImages;
struct FileState {
    s32 unk0;
    char pad4[0x244];
    s32 unk248;
    char pad24C[0x10];
    s16 count;
    struct EntryRecAt8V1 *entries;
    char pad264[4];
    struct ResourceRecAt6 *resources;
    char pad26C[4];
    s16 chunkCount;
    char pad272[6];
    struct ChunkFrontendEvictExpiredImages *chunks;
    char pad27C[0x28];
    s32 locked;
};

struct PoolFrontendReleaseActiveChunkImages;
typedef struct PoolFrontendReleaseActiveChunkImages PoolFrontendReleaseActiveChunkImages;

struct FileState;
typedef struct FileState FileState;

struct QuadRecAt2C;

extern s32 Frontend_GetTextureChromaKey(s32 index);

struct ChunkFrontendEvictExpiredImages;
struct SlotRecAtCV2;
struct ObjRecAtE;
struct ChunkFrontendEvictExpiredImages {
    void *active;
    char pad4[0x480];
    struct SlotRecAtCV2 **slots;
    char pad488[4];
    struct ObjRecAtE *header;
    u8 live;
    char pad491[0xB];
};
struct ChunkFrontendEvictExpiredImages;
struct EntryRecAt8V1;
struct ResourceRecAt6;
#endif
