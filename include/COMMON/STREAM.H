#ifndef COMMON_STREAM_H
#define COMMON_STREAM_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct func_802604BC_S1;
typedef struct func_802604BC_S1 func_802604BC_S1;

struct Output8025EF54;
typedef struct Output8025EF54 Output8025EF54;

struct Output8025EF54;

extern void func_8025EF34_de(u32 *stream, Output8025EF54 *out, s32 count);



struct Stream;
typedef struct Stream Stream;

struct Segment8025FFD0;
typedef struct Segment8025FFD0 Segment8025FFD0;

struct func_802604CC_S1;
struct func_802604CC_S1 {
    char * unk0;
    char pad0[0x4 - 0x0 - sizeof(char*)];
    Rec_func_8024C92C_de * unk4;
    char pad4[0x8 - 0x4 - sizeof(Rec_func_8024C92C_de*)];
    void * unk8;
    char pad8[0x18 - 0x8 - sizeof(void*)];
    s32 unk18;
    char pad18[0x1C - 0x18 - sizeof(s32)];
    s32 unk1C;
    char pad1C[0x20 - 0x1C - sizeof(s32)];
    s32 unk20;
};


extern float D_800C9208;

extern float D_800C4168_de;

extern float D_800C91F8;



struct Segment8025FFD0;

struct Stream;
struct Stream {
    s32 unk0;
    char pad4[8];
    s32 unkC;
    float coeff[4];
    u32 unk20;
    u32 unk24;
    s32 unk28;
};

struct Decode8025EF54;

struct Curve;
typedef struct Curve Curve;


extern double D_800C40F8_de;

extern float D_800C9200;

extern double D_800C4100_de;


struct func_802604CC_S1;
typedef struct func_802604CC_S1 func_802604CC_S1;

struct Decode8025EF54;
typedef struct Decode8025EF54 Decode8025EF54;

struct Poly;

struct Poly;
typedef struct Poly Poly;

struct Curve;

struct func_802604BC_S1;
struct func_802604BC_S1 {
    char pad0[0x10];
    void **unk10;
};


/* Frame counts of the loaded motion, read by the stream decoder. */
extern s32 D_8010AC84;
extern s32 D_8010AC88;
#endif
