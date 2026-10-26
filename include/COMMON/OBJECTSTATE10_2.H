#ifndef COMMON_OBJECTSTATE10_2_H
#define COMMON_OBJECTSTATE10_2_H
#include "TYPES.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/ITEMRECAT20V1.H"
struct ObjectState10_2;
typedef struct ObjectState10_2 ObjectState10_2;

extern float D_800C7340_de;







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


struct InitParams;
struct InitParams {
    s32 count38;
    s32 count1C;
    u8 kind;
    u8 debugFlags;
    u8 pad0A[2];
    void *context;
    Lane_ALOscInit value10;
    Lane_ALOscUpdate value14;
    Lane_ALOscStop value18;
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
#endif
