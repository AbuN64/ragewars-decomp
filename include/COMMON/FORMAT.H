#ifndef COMMON_FORMAT_H
#define COMMON_FORMAT_H
#include "TYPES.H"
extern int D_8014DA34;

extern int D_8014DA28;

extern int D_8014DA38;

extern int Frontend_HasOwnedImagePalette(void *object);

struct Format;
struct Format {
    s32 word0;
    s32 flags;
    s32 type;
    s32 bits;
    s32 word4;
    u32 mask[4];
    s32 shift[4];
};

struct Format;
extern struct Format D_800E2B20[];
extern void Frontend_GetPixelFormatDescriptor(s32 index, struct Format *out);


extern int D_8014DA24;


extern int D_80153C8C;

extern s32 Frontend_GetOwnedImagePixels(s32 *record);






extern int D_8014DA20;




extern unsigned char D_80153C75;


extern int D_8014DA2C;

extern s32 Frontend_GetOwnedImagePalette(s32 *record);

struct Format;
typedef struct Format Format;

extern u8 Frontend_OwnsImagePixels(u8 *record);

extern int D_8014DA3C;





extern unsigned char D_80153C77;


struct Config;
struct Config {
    unsigned char type;
    unsigned char flags;
    short last;
    short x;
    short y;
    short a;
    short b;
    int d;
    int e;
    int f;
    int g;
};

extern u8 Frontend_OwnsImagePalette(u8 *record);


extern int D_8014DA30;
#endif
