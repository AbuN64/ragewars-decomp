#ifndef UNBAKE_SPAN_1000_CODE_802609CC_H
#define UNBAKE_SPAN_1000_CODE_802609CC_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "span_1000/code_8025E568.h"
extern float D_800C41A0_de;

extern double D_800C4190_de;

extern f32 func_802615B4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 arg5);

extern float D_800C4198_de;

extern float D_8010AC70;

struct LocalDecodeRange;
struct LocalDecodeRange {
    u32 unused;
    Func802608ECResult range;
};

struct LocalDecodeRange;
typedef struct LocalDecodeRange LocalDecodeRange;

extern f32 func_80260EF8_de(LocalDecodeRange *arg0);

extern double D_800C4170_de;

extern void func_80260C6C_de(void *arg0, int arg1, Func802608ECResult t, int arg5);


struct func_80260C8C_S1;
typedef struct func_80260C8C_S1 func_80260C8C_S1;

struct Track_func_80261180_de;
struct Track_func_80261180_de {
    s32 keys;
    char pad4[0x2C - 4];
    s32 stride;
};

extern unsigned int func_8026100C_de(unsigned int *arg0, unsigned int arg1);

struct DecodeArray;
struct DecodeArray {
    s32 base;
    Func802608ECResult range;
    s32 count; /* 0x10 */
};

struct BitFieldSource;
typedef struct BitFieldSource BitFieldSource;

struct BitFieldSource;
struct BitFieldSource {
    int base;
    unsigned int width;
};

extern int func_80260E4C_de(BitFieldSource *arg0, int arg1);

struct DecodeArray;
typedef struct DecodeArray DecodeArray;

extern f32 func_80260C9C_de(DecodeArray *arg0, s32 arg1);

extern int func_8026140C_de(char *object);

extern void func_80261180_de(char **stream, f32 *out, s32 frames);

extern unsigned int func_8026160C_de(unsigned int value);

extern double D_800C4188_de;

extern int func_80260DA8_de(BitFieldSource *arg0, int arg1);

extern u32 func_80261614_de(s32 arg0);

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

extern void func_80260FF0_de(unsigned int *record, int index);

extern void func_80260A5C_de(s32 arg0, Func802608ECResult range, f32 arg4);

extern void func_80260E1C_de(void *arg0, int arg1, Func802608ECResult t, int arg5);

struct Entry802612C8;
struct Entry802612C8 {
    s32 x;
    s32 pad4;
    s32 z;
    f32 f0C;
    s32 n10;
    s32 n14;
};

struct Anim;
typedef struct Anim Anim;

struct Pack;
typedef struct Pack Pack;

extern void func_80260ECC_de(void *arg0, int arg1, Triple t);

struct Entry802612C8;
typedef struct Entry802612C8 Entry802612C8;

extern float D_800C41A4_de;

struct Track_func_80261180_de;
typedef struct Track_func_80261180_de Track_func_80261180_de;

extern f32 func_802609AC_de(s32 bitAddress, Func802608ECResult range);

extern void func_80260D78_de(void *arg0, int arg1, Func802608ECResult t, int arg5);

struct func_80260C8C_S1;
struct func_80260C8C_S1 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    Triple unk4;
    char pad4[0x10 - 0x4 - sizeof(Triple)];
    int unk10;
};


struct ObjRecAt4V4;
struct ObjRecAt4V4 {
    int unk0;
    char pad0[0x4 - 0x0 - sizeof(int)];
    Triple unk4;
};

extern void func_8026107C_de(int *arg0, int arg1);

typedef struct AnimChannel {
    f32 time;
    s16 current,next,frames;
    u8 active,blending;
    char padc[4]; void *resource;
} AnimChannel;
typedef struct RootActor { char pad0[0x100]; u32 flags; } RootActor;
typedef struct RootClip { u16 count,loopStart; char pad4[4]; f32 rate; } RootClip;
typedef struct AngleKeys { char header[8]; s16 keys[1]; } AngleKeys;
extern void func_802476C8_de(char *,void *,f32,f32);
extern f32 func_80273EE4_de(f32,f32,f32);
extern s32 func_802625C4_de(void *);

#endif
