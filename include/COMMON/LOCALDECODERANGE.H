#ifndef COMMON_LOCALDECODERANGE_H
#define COMMON_LOCALDECODERANGE_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/STREAM.H"
extern float D_800C41A0_de;

extern double D_800C4190_de;


extern float D_800C4198_de;

extern float D_8010AC70;

struct LocalDecodeRange;

struct LocalDecodeRange;
typedef struct LocalDecodeRange LocalDecodeRange;


extern double D_800C4170_de;




struct Track_func_80261180_de;


struct DecodeArray;

struct BitFieldSource;
typedef struct BitFieldSource BitFieldSource;

struct BitFieldSource;


struct DecodeArray;
typedef struct DecodeArray DecodeArray;



extern void func_80261180_de(char **stream, f32 *out, s32 frames);


extern double D_800C4188_de;



struct ObjRecAt4V4;
typedef struct ObjRecAt4V4 ObjRecAt4V4;

struct Pack;
struct Pack {
    s32 count;
    s32 offsets[1];
};

extern double D_800C4180_de;

struct Anim;
struct Anim {
    s32 time;
    s16 current;
    s16 next;
    u16 frames;
    u8 blending;
    u8 active;
    s32 length;
    void *resource;
};




struct Entry802612C8;

struct Anim;
typedef struct Anim Anim;

struct Pack;
typedef struct Pack Pack;


struct Entry802612C8;
typedef struct Entry802612C8 Entry802612C8;

extern float D_800C41A4_de;

struct Track_func_80261180_de;
typedef struct Track_func_80261180_de Track_func_80261180_de;





struct ObjRecAt4V4;


typedef struct AnimChannel {
    f32 time;
    s16 current,next,frames;
    u8 active,blending;
    char padc[4]; void *resource;
} AnimChannel;
extern f32 GraphU64_InterpolateWrappedValue(f32,f32,f32);
extern s32 func_802625C4_de(void *);
#endif
