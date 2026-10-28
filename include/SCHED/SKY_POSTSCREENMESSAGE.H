#ifndef SCHED_SKY_POSTSCREENMESSAGE_H
#define SCHED_SKY_POSTSCREENMESSAGE_H
#include "COMMON/DESCRIPTORRECAT29.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/ITEMRECAT20V1.H"
struct Rotor {
    char pad0[0xC];
    struct CROMSkyLayer *descriptor;
    u16 mask;
    char pad12[0xA];
    f32 angleA;
    f32 angleB;
    char pad24[0x1E4];
    f32 throttle;
    f32 phase;
    f32 speed;
    f32 phaseScale;
    char pad218[4];
    f32 trim;
};
struct ObjRecAt210 {
    char pad0[0x210];
    float unk210;
};
struct Scene {
    u8 reserved000[0x8A0];
    IntrusiveList freeObjects; /* +0x8A0; probe 20261019T012545644265Z */
    struct ObjectRecAt220 *objects; /* active-list head, +0x8B4 */
    struct ObjectRecAt220 *lastObject;
    s32 objectPrevOffset, objectNextOffset;
    s32 count;
    u16 effectMask; /* +0x8C8: Sky_UpdateSceneEffects */
    u8 reserved8CA[2];
};
struct IntegerState8A4 {
    unsigned char padding_0[2208];
    IntrusiveList unk_8A0;
    IntrusiveList unk_8B4;
};
struct Reusable {
    s32 unk0;
    char pad4[0x10];
    s32 unk14;
    char pad18[0x70];
    s32 unk88;
    char pad8C[0x10];
    s32 unk9C;
    char padA0[0x10];
    s32 unkB0;
    s32 unkB4;
    char padB8[0xC];
    s32 unkC4;
};
struct BlockVirtualFreeVirtualRegion {
    s16 type;
    s16 pad;
    s32 value;
    void *data;
};
struct PagerState {
    struct PagerCounters counters;
    s16 f20;
    char pad22[2];
    OSMesgQueue completion; /* pager completion queue, 0x18 bytes at +0x24 (D_800FF254) */
    char list0Data[0xC0 - 0x3C];
    char queue[0x2F0 - 0xC0]; /* thread 1 (osCreateThread) */
    char pool[0x4F0 - 0x2F0]; /* its stack */
    char queueData[0x720 - 0x4F0]; /* thread 2 (Vhandler_RunPagerDispatcher); its address is also thread 1's stack top */
    char pool2[0x920 - 0x720]; /* thread 2's stack */
    SlotVirtualInitializePagerEuroExtended slots[24];
    OSMesgQueue jobs;
    char list1Data[0xAD8 - 0xAB8];
    OSMesgQueue pending;
    char list2Data[0xB10 - 0xAF0];
    Channels channels[8];
    ResourcePageMapping *head; /* pager LRU list (head, tail), appended by Virtual_AppendPageChainNode; = D_800FFE20 */
    union { s32 fBF4; ResourcePageMapping *tail; };
    u8 lookup[0x100];
    EntryRecAt3 entries[24];
    struct Region regions; /* the first page region: ROM pages at source, slot map lookup */
    s16 fD70;
    s16 fD72;
    char padD74[4];
};
extern struct PagerState D_800FF230;
struct Block10 {
    s16 f28;
    s16 pad;
    s32 f2C;
    void *f30;
    void **f34;
};
struct AnimationInfo {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    s32 unk4;
    char pad4[0x8 - 0x4 - sizeof(s32)];
    void * unk8;
};
extern f32 func_8023A294_de(s32 unused0, f32 value, f32 target, f32 step);
extern CCameraText *Sky_PostScreenMessage(void *owner, void *pool, u8 *text, s32 kind, f32 size, s32 target);
#endif
