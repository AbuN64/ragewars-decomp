#ifndef UNBAKE_SPAN_1000_CODE_802B243C_H
#define UNBAKE_SPAN_1000_CODE_802B243C_H
#include "types.h"
#include "common/types_1dc8418c21db.h"

struct MidiState802B70B8;
struct MidiState802B70B8 {
    s32 start;
    s32 track_start;
    s32 current;
    s32 unkC;
    s32 end;
    f32 tick_scale;
    s16 division;
    s16 unk1A;
};


struct ObjRecAt18V1;
typedef struct ObjRecAt18V1 ObjRecAt18V1;

extern u32 func_802B2120_de(ObjRecAt18V1 *seq, f32 sec, u32 tempo);

extern double D_800C74E8_de;

struct ALEndEvent;

struct ALTempoEvent;


struct func_802B742C_S1;
typedef struct func_802B742C_S1 func_802B742C_S1;

struct ALEvent;

struct func_802B73C4_S1;
typedef struct func_802B73C4_S1 func_802B73C4_S1;

struct func_802B742C_S1;
struct func_802B742C_S1 {
    char pad0[0x8];
    u8 * unk8;
};

struct func_802B73C4_S1;
struct func_802B73C4_S1 {
    s32 unk0;
    char pad0[0x8 - 0x0 - sizeof(s32)];
    u32 unk8;
    char pad8[0x10 - 0x8 - sizeof(u32)];
    s32 unk10;
};

struct ALSeq_s;
typedef struct ALSeq_s ALSeq_s;

struct MidiState802B70B8;
typedef struct MidiState802B70B8 MidiState802B70B8;

extern float D_800C74E0_de;

extern f32 func_802B20D4_de(ObjRecAt18V1 *arg0, s32 arg1, s32 arg2);

struct func_802B738C_S2;
struct func_802B738C_S2 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    int unk4;
    char pad4[0xC - 0x4 - sizeof(int)];
    unsigned short unkC;
};

struct ALSeqMarker;
struct ALSeqMarker {
    u8 *curPtr;
    s32 lastTicks;
    s32 curTicks;
    s16 lastStatus;
};

struct func_802B738C_S1;
typedef struct func_802B738C_S1 func_802B738C_S1;

struct ALSeq_s;
struct ALSeq_s {
    u8 *base;
    u8 *trackStart;
    u8 *curPtr;
    s32 lastTicks;
    s32 len;
    f32 qnpt;
    s16 division;
    s16 lastStatus;
};

struct ALSeqMarker;
typedef struct ALSeqMarker ALSeqMarker;

extern void func_802B22D8_de(void *arg0, void *arg1);

struct func_802B738C_S2;
typedef struct func_802B738C_S2 func_802B738C_S2;

struct func_802B738C_S1;
struct func_802B738C_S1 {
    char pad0[0x8];
    int unk8;
    char pad8[0xC - 0x8 - sizeof(int)];
    int unkC;
    char padC[0x1A - 0xC - sizeof(int)];
    unsigned short unk1A;
};

#endif
