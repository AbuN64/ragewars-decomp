#ifndef UNBAKE_SPAN_1000_CODE_802AE028_H
#define UNBAKE_SPAN_1000_CODE_802AE028_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
struct ObjectState10_2;
typedef struct ObjectState10_2 ObjectState10_2;

extern float D_800C7340_de;

struct func_802B3B80_S1;
typedef struct func_802B3B80_S1 func_802B3B80_S1;

struct CopyDest802B3998;
typedef struct CopyDest802B3998 CopyDest802B3998;




struct CallbackNode;
struct CallbackNode {
    s32 state;
    struct CallbackNode *self;
    void *callback;
};

struct ALCSeq_s;
typedef struct ALCSeq_s ALCSeq_s;

struct ALCSeqMarker;
struct ALCSeqMarker {
    u32 validTracks;
    s32 lastTicks;
    u32 lastDeltaTicks;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
};




struct ALCMidiHdr;
struct ALCMidiHdr {
    u32 trackOffset[16];
    u32 division;
};

extern double D_800C7318_de;

extern f32 func_802AE7BC_de(void **arg0, s32 arg1, s32 arg2);

struct InitParams;
struct InitParams {
    s32 count38;
    s32 count1C;
    u8 kind;
    u8 pad09[3];
    s32 context;
    s32 value10;
    s32 value14;
    s32 value18;
};

extern double D_800C7310_de;

struct ObjectState4C;
typedef struct ObjectState4C ObjectState4C;

struct ObjRecAt8V3;
typedef struct ObjRecAt8V3 ObjRecAt8V3;

struct ResourceTable;
typedef struct ResourceTable ResourceTable;

struct DecodeResult_func_802AE6BC_de;
struct DecodeResult_func_802AE6BC_de {
    s16 type;
    u8 pad2[2];
    u32 value;
    u8 pad8[8];
};

struct ObjectLinks4_5;
typedef struct ObjectLinks4_5 ObjectLinks4_5;

extern double D_800C7300_de;



struct ALCMidiHdr;
typedef struct ALCMidiHdr ALCMidiHdr;

struct func_802B3B80_S1;
struct func_802B3B80_S1 {
    char pad0[0x14];
    s32 unk14;
    char pad14[0x18 - 0x14 - sizeof(s32)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
    char pad20[0x24 - 0x20 - sizeof(s32)];
    s32 unk24;
    char pad24[0x28 - 0x24 - sizeof(s32)];
    s32 unk28;
    char pad28[0x2C - 0x28 - sizeof(s32)];
    s32 unk2C;
    char pad2C[0x30 - 0x2C - sizeof(s32)];
    s16 unk30;
    char pad30[0x32 - 0x30 - sizeof(s16)];
    s16 unk32;
    char pad32[0x34 - 0x32 - sizeof(s16)];
    u8 unk34;
    char pad34[0x38 - 0x34 - sizeof(u8)];
    s16 unk38;
    char pad38[0x5C - 0x38 - sizeof(s16)];
    s32 unk5C;
    char pad5C[0x60 - 0x5C - sizeof(s32)];
    s32 unk60;
    char pad60[0x64 - 0x60 - sizeof(s32)];
    s32 unk64;
    char pad64[0x68 - 0x64 - sizeof(s32)];
    s32 unk68;
    char pad68[0x6C - 0x68 - sizeof(s32)];
    func_8028472C_S2_U118 unk6C;
    char pad6C[0x70 - 0x6C - sizeof(func_8028472C_S2_U118)];
    s32 unk70;
    char pad70[0x74 - 0x70 - sizeof(s32)];
    s32 unk74;
    char pad74[0x78 - 0x74 - sizeof(s32)];
    s32 unk78;
};

struct CopySource802B3998;
struct CopySource802B3998 {
    int word0;
    int word4;
    int word8;
    int wordsC[16];
    int words4C[16];
    unsigned char bytes8C[16];
    unsigned char bytes9C[16];
    int wordsAC[16];
};

struct CallbackNode;
typedef struct CallbackNode CallbackNode;

struct Node_func_802AFD6C_de;
struct Node_func_802AFD6C_de {
    struct Node_func_802AFD6C_de *prev;
    struct Node_func_802AFD6C_de *next;
    s32 value;
    short type;
};

struct Node_func_802AFD6C_de;
struct ObjRecAt8V3;
struct ObjRecAt8V3 {
    char pad0[0x8];
    struct Node_func_802AFD6C_de * unk8;
};

struct Node_func_802AFD6C_de;
typedef struct Node_func_802AFD6C_de Node_func_802AFD6C_de;

struct ObjectLinks54_2;
struct ObjectLinks54_2 {
    unsigned char padding[80];
    Node_func_802AFD6C_de * link;
};

extern u32 func_802AE824_de(void **arg0, f32 arg1, s32 arg2);

struct RuntimeState;
typedef struct RuntimeState RuntimeState;

struct ValueSet;
typedef struct ValueSet ValueSet;

struct RuntimeState;
struct RuntimeState {
    void *resources;
    u32 active;
    u32 scale;
    u32 total;
    u32 previous;
    u32 first;
    u8 *objects[16];
    u32 values[16];
    u8 flags98[16];
    u8 flagsA8[16];
    u32 results[16];
};

struct InitParams;
typedef struct InitParams InitParams;

extern float D_800C7330_de;

struct DecodeResult;
struct DecodeResult {
    s16 type;
    u8 pad2[6];
    u8 status;
    u8 first_data;
    u8 second_data;
    u8 extra1;
    u32 extra2;
};



struct ObjectLinks54_2;
typedef struct ObjectLinks54_2 ObjectLinks54_2;

extern float D_800C7320_de;

struct DecodeResult_func_802AE6BC_de;
typedef struct DecodeResult_func_802AE6BC_de DecodeResult_func_802AE6BC_de;

struct ALCMidiHdr;
struct ALCSeq_s;
struct ALCSeq_s {
    struct ALCMidiHdr *base;
    u32 validTracks;
    f32 qnpt;
    u32 lastTicks;
    u32 lastDeltaTicks;
    u32 deltaFlag;
    u8 *curLoc[16];
    u8 *curBUPtr[16];
    u8 curBULen[16];
    u8 lastStatus[16];
    u32 evtDeltaTicks[16];
};



struct ValueSet;
struct ValueSet {
    char pad0[4];
    u32 mask;
    char pad8[8];
    u32 amount;
    s32 active;
    char pad18[0xA0];
    u32 values[16];
};

struct ObjectLinks4_5;
struct ObjectLinks4_5 {
    Node_func_802AFD6C_de * link;
};

extern int func_802AE7B0_de(void *arg0);

struct CopySource802B3998;
typedef struct CopySource802B3998 CopySource802B3998;

struct CopyDest802B3998;
struct CopyDest802B3998 {
    int pad0;
    int word4;
    int pad8;
    int wordC;
    int word10;
    int pad14;
    int words18[16];
    int words58[16];
    unsigned char bytes98[16];
    unsigned char bytesA8[16];
    int wordsB8[16];
};

extern void func_802AE93C_de(CopyDest802B3998 *src, CopySource802B3998 *dst);

extern void func_802AE8C8_de(CopyDest802B3998 *dst, CopySource802B3998 *src);

extern float D_800C7308_de;

struct ObjectState10_2;
struct ObjectState10_2 {
    s16 type;
    u8 pad2[6];
    u8 unk_8;
    u8 unk_9;
    u8 padA;
    u8 unk_B;
    u8 unk_C;
    u8 unk_D;
    u8 padE[2];
};

extern double D_800C7338_de;

struct ALCSeqMarker;
typedef struct ALCSeqMarker ALCSeqMarker;

extern void func_802AE290_de(ALCSeq_s *seq, ALCSeqMarker *m, u32 ticks);

struct DecodeResult;
typedef struct DecodeResult DecodeResult;

struct ResourceTable;
struct ResourceTable {
    u32 entries[17];
};

struct ResourceTable;
struct RuntimeStateRecAtB8;
struct RuntimeStateRecAtB8 {
    struct ResourceTable *resources;
    u32 active;
    f32 scale;
    u32 unkC;
    u32 unk10;
    u32 one14;
    void *objects[16];
    u32 unk58[16];
    s8 flags98[16];
    s8 flagsA8[16];
    u32 results[16];
};

extern double D_800C7328_de;

struct ObjectState4C;
struct ObjectState4C {
    char pad0[0x24];
    s32 unk_24;
    char pad24[0x48 - 0x24 - sizeof(s32)];
    char unk_48;
};

struct RuntimeStateRecAtB8;
typedef struct RuntimeStateRecAtB8 RuntimeStateRecAtB8;

/* Process one compact-sequence MIDI message; O32/native all-version proof retained. */
void func_802AF2E0_de(void *object, ALEvent *message);

#endif
