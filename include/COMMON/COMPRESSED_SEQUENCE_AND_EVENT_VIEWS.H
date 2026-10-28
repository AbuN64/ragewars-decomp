#ifndef COMMON_COMPRESSED_SEQUENCE_AND_EVENT_VIEWS_H
#define COMMON_COMPRESSED_SEQUENCE_AND_EVENT_VIEWS_H
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



extern double D_800C7328_de;

struct ObjectState4C;
struct ObjectState4C {
    char pad0[0x24];
    s32 unk_24;
    char pad24[0x48 - 0x24 - sizeof(s32)];
    char unk_48;
};

#endif
