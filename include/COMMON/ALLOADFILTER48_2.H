#ifndef COMMON_ALLOADFILTER48_2_H
#define COMMON_ALLOADFILTER48_2_H
#include "acmd.h"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
extern float D_801514C0[];


extern float D_800C7CEC_de;



struct ALWaveTable_s;

struct ALLoadFilter48_2;
typedef struct ALLoadFilter48_2 ALLoadFilter48_2;



extern float D_800CCF10;

extern float D_801512C0[];


extern float D_801510C0[];


struct ALRawLoop;
typedef struct ALRawLoop ALRawLoop;

struct ALRawLoop;
struct ALRawLoop {
    u32 start;
    u32 end;
    u32 count;
};

struct ALADPCMWaveInfo_func_802BE514_de;
typedef struct ALADPCMWaveInfo_func_802BE514_de ALADPCMWaveInfo_func_802BE514_de;

struct ALADPCMBook;
typedef struct ALADPCMBook ALADPCMBook;

struct ALADPCMBook;
struct ALADPCMBook {
    s32 order;
    s32 npredictors;
    s16 book[1];
};
struct ALADPCMWaveInfo_func_802BE514_de;
struct ALADPCMWaveInfo_func_802BE514_de {
    void *loop;
    ALADPCMBook *book;
};
struct ALWaveTableSCode802BE0D0;
struct ALWaveTableSCode802BE0D0 {
    u8 *base;
    s32 len;
    u8 type;
    u8 flags;
    union {
        ALADPCMWaveInfo_func_802BE514_de adpcmWave;
    } waveInfo;
};
struct ALLoadFilter_func_802BE514_de;
struct ALWaveTableSCode802BE0D0;
struct ALLoadFilter_func_802BE514_de {
    ALFilter_s14 filter;
    void *state;
    void *lstate;
    ALRawLoop loop;
    struct ALWaveTableSCode802BE0D0 *table;
    s32 bookSize;
    ALDMAproc dma;
    void *dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
};


struct Shape_typemap_165;


struct ALLoadFilter_func_802BE514_de;
typedef struct ALLoadFilter_func_802BE514_de ALLoadFilter_func_802BE514_de;

struct ALLoadFilter48_2;
struct ALLoadFilter48_2 {
    ALFilter_s14 filter;
    void *state;
    void *lstate;
    ALRawLoop loop;
    struct ALWaveTable_s *table;
    s32 bookSize;
    ALDMAproc dma;
    void *dmaState;
    s32 sample;
    s32 lastsam;
    s32 first;
    s32 memin;
};

extern float D_801516C0[];

extern float D_800C7CF0_de;

extern float D_800C7CF4_de;

extern float D_800CCF18;

extern Acmd *func_802C3988(ALLoadFilter_func_802BE514_de *filter, s16 *outp, s32 byteCount, s32 sampleOffset, Acmd *p);

extern float D_800CCF24;

extern float D_800CCF20;

extern float D_800C7CE8_de;


typedef struct DecodeState {
    s32 first;
    s32 third;
    void *source;
    s32 second;
    s32 count;
    void *cursor;
    u16 frame[336]; /* +0x18: Audio_DecodeFrame header and coefficients */
} DecodeState;
extern unsigned short D_800D54B8;
extern unsigned short D_800D54BA;
extern unsigned short D_800D54BC;
extern s16 D_800D54BE;
extern s16 D_800D54C0_de;

/* Dictionary decoder records, shared by the block and phrase streams. */
typedef struct DecodeNode {
    u16 first;
    u16 second;
} DecodeNode;

typedef struct DecodeSample {
    u16 tag;
    u16 value;
} DecodeSample;

typedef struct DecodePhrase {
    u8 pad0[0xA0];
    DecodeSample samples[64];
    s32 count;                     /* 0x1A0 */
    u8 pad1A4[0x14];
} DecodePhrase;

typedef struct DecodeTable {
    u8 pad0[0xE];
    u16 width;
    u8 pad10[0xC];
    DecodePhrase *phrases;          /* 0x1C */
    DecodeNode *tree;               /* 0x20 */
} DecodeTable;

typedef struct DecodeBlock {
    s32 kind;
    s32 start;
    s32 length;
    s32 offset;
    DecodeTable *table;
} DecodeBlock;
#endif
