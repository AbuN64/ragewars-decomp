#ifndef UNBAKE_SPAN_1000_CODE_802AFEAC_H
#define UNBAKE_SPAN_1000_CODE_802AFEAC_H
#include "../types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/audio_initialize.h"
#include "types.h"
struct func_802B510C_S2;
/* unbake published declaration: published_275d50f0b6f32f21e20b32ac */
struct func_802B510C_S2 {
    char pad0[0x8];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    char unkC;
};

struct func_802B5410_S1;
/* unbake published declaration: published_2a377857b936ecb75445bcf5 */
struct func_802B5410_S1 {
    s32 unk0;
    char pad0[0x4 - 0x0 - sizeof(s32)];
    u32 unk4;
    char pad4[0x8 - 0x4 - sizeof(u32)];
    s32 unk8;
};

struct Buf16b;
/* unbake published declaration: published_60d1e054f40624926837b56f */
struct Buf16b {
    s16 count;
    s16 _pad2;
    s16 value;
    s16 _pad6;
    s32 _pad8;
    s32 _padC;
};

struct Buf16c;
/* unbake published declaration: published_6bef640bb82e315ec0832be6 */
typedef struct Buf16c Buf16c;

/* unbake published declaration: published_80ba2022e9cb523906e0c932 */


struct func_802B52B0_S1;
/* unbake published declaration: published_8a454ae9bcf1f70ba5596dc5 */
typedef struct func_802B52B0_S1 func_802B52B0_S1;

struct Buf16c;
/* unbake published declaration: published_92fa81b2a0e921b72b820ab9 */
struct Buf16c {
    s16 count;
    s16 _pad2;
    s32 zero;
    s8 f8;
    s8 f9;
    s8 fA;
    s8 _padB;
    s32 _padC;
};

struct func_802B5328_S2;
/* unbake published declaration: published_97082440971db72757b2530e */
typedef struct func_802B5328_S2 func_802B5328_S2;

struct func_802B5328_S2;
/* unbake published declaration: published_aa292a1168d66acee7133909 */
struct func_802B5328_S2 {
    char * unk0;
    char pad0[0x8 - 0x0 - sizeof(char*)];
    s32 unk8;
    char pad8[0xC - 0x8 - sizeof(s32)];
    s16 unkC;
};

struct Buf16b;
/* unbake published declaration: published_aaa9ebd95a8a6504864950b9 */
typedef struct Buf16b Buf16b;

struct func_802B5410_S1;
/* unbake published declaration: published_ac4d71347162f78f3076ac5e */
typedef struct func_802B5410_S1 func_802B5410_S1;

struct func_802B510C_S2;
/* unbake published declaration: published_dcd70473cb8b45660542a37c */
typedef struct func_802B510C_S2 func_802B510C_S2;

struct func_802B52B0_S1;
/* unbake published declaration: published_fcac7ab32b65c1675af132d0 */
struct func_802B52B0_S1 {
    char pad0[0x8];
    Node_func_80239AF4_de * unk8;
};

typedef struct SeqFreeVoice { struct SeqFreeVoice *next; char pad[0x34]; } SeqFreeVoice;
typedef struct SeqInitConfig {
    s32 voices, events;
    u8 channels, debug;
    u8 pad[2];
    void *heap;
    void *initOsc, *updateOsc, *stopOsc;
} SeqInitConfig;
typedef struct SeqInitPlayer {
    void *next;
    struct SeqInitPlayer *self;
    void *callback;
    char padC[8];
    void *driver;
    void *target;
    s32 time;
    void *bank;
    s32 uspt, delta, state;
    u16 mask;
    s16 volume;
    u8 channels, debug;
    u8 pad36[2];
    s16 eventType;
    char pad3A[0xE];
    char queue[0x14];
    s32 frameTime;
    void *channelState;
    SeqFreeVoice *allocHead, *allocTail, *freeList;
    void *initOsc, *updateOsc, *stopOsc;
    void *loopStart, *loopEnd;
    s32 loopCount;
} SeqInitPlayer;
extern char D_002B0554;
extern void func_802B1990_de(void *);

#endif
