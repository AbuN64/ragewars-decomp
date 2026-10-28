#ifndef COMMON_TEXTURE_H
#define COMMON_TEXTURE_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
struct Texture;
typedef struct Texture Texture;

struct Image_func_80419490_de;
typedef struct Image_func_80419490_de Image_func_80419490_de;




extern void func_8029D7E8_auto(void);

struct Image_func_80419490_de;

struct Command;

extern int D_8014DCE0;

struct Texture;
struct Texture {
    u8 unk0;
    char pad1[3];
    s16 width;
    s16 height;
    s16 stride;
    s16 rows;
    s32 size;
    s32 flags;
    void *palette;
    u32 data;
};


extern int D_80153F68;

extern float D_800DD410_de;










extern s32 D_800DF258;
extern s32 D_800DF25C;
extern s32 D_800DF260_de;
extern s32 D_800DF264_de;
extern s32 D_800DF26C_de;
extern s32 Frontend_HasImageFormatMaskComponent(u8 *);

extern const u8 g_printfLowercaseHexDigits[];
extern const u8 D_800DD1DC[];
extern const u8 D_800DD1F0[];
extern const u8 D_800DF230_de[];
extern const u8 D_800DF240[];

extern f64 D_800E1118;
extern f64 D_800E1130;
extern f64 D_800E1148;
extern f64 D_800E11F0;
#endif
