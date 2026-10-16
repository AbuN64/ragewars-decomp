#ifndef UNBAKE_SPAN_1000_CODE_802BE0D0_H
#define UNBAKE_SPAN_1000_CODE_802BE0D0_H
#include "acmd.h"
#include "audio_callbacks.h"
#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
extern float D_801514C0[];

extern void func_802C021C_de();

extern float D_800C7CEC_de;

extern void func_802BFF90_de(float *arg0, float *arg1, float *arg2);

extern s32 func_802BF804_de(f32 *out, s16 *in);

struct ALLoadFilter48_2;
typedef struct ALLoadFilter48_2 ALLoadFilter48_2;

extern void func_802BFF30_de(float *arg0, float *arg1);

extern void func_802BF514_de();

extern float D_800CCF10;

extern float D_801512C0[];

extern u32 func_802BFE3C_de(void);

extern float D_801510C0[];

extern s16 func_802C0044_de(f32 arg0);

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

extern FftTables *func_802BF67C_de(s32 n);

struct Shape_typemap_165;
extern void func_802C000C_de(s32 unused0, struct Shape_typemap_165 *arg1, s32 unused2);

extern void func_802BFE68_de(s32 *arg0, s32 arg1);

struct ALLoadFilter_func_802BE514_de;
typedef struct ALLoadFilter_func_802BE514_de ALLoadFilter_func_802BE514_de;

struct ALLoadFilter48_2;
struct ALLoadFilter48_2 {
    ALFilter_s14 filter;
    void *state;
    void *lstate;
    ALRawLoop loop;
    void *table;
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

extern Acmd *func_802BE514_de(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p);

typedef struct DecodeState {
    s32 first;
    s32 third;
    void *source;
    s32 second;
    s32 count;
    void *cursor;
} DecodeState;
extern unsigned short D_800D54B8;
extern unsigned short D_800D54BA;
extern unsigned short D_800D54BC;
extern unsigned short D_800D54BE;
extern unsigned short D_800D54C0_de;

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

extern u16 func_802BEDB0_de(u16 *, u16, s32, s32, void *);

#endif
