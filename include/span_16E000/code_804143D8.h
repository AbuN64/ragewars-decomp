#ifndef UNBAKE_SPAN_16E000_CODE_804143D8_H
#define UNBAKE_SPAN_16E000_CODE_804143D8_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "types.h"
struct Texture;
typedef struct Texture Texture;

struct Image_func_80419490_de;
typedef struct Image_func_80419490_de Image_func_80419490_de;

extern void func_80419430_de(void *source);

extern void func_80419278_de(s32 left, s32 top, s32 right, s32 bottom, f32 u0, f32 v0, f32 u1, f32 v1);

extern void func_80417138_de(s32 flags);

extern void func_8029D7E8_auto(void);

struct Image_func_80419490_de;
struct Image_func_80419490_de {
    char pad0[8];
    s16 width;
    s16 height;
    char padC[0xC];
    s32 *pixels;
};

struct Command;
struct Command {
    unsigned words[2];
};

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

extern void func_80419608_de();

extern int D_80153F68;

extern float D_800DD410_de;

extern double func_804147F0_eu_x();

extern void func_80418F8C_de();

extern void func_804191A4_de(void);

extern void func_804190C4_de(s32 mode);

extern void func_80414360_de();

extern void func_804191E8_de(void);

extern void func_80414384_de();

extern void func_80419868_eu_x(void);

extern void func_802BA1B0_de(s32 arg0);

extern s32 D_800DF258;
extern s32 D_800DF25C;
extern s32 D_800DF260_de;
extern s32 D_800DF264_de;
extern s32 D_800DF26C_de;
extern s32 func_804136D8_de(u8 *);
extern s32 func_8041737C_de(s32, void *);

extern const u8 D_800DD1C8[];
extern const u8 D_800DD1DC[];
extern const u8 D_800DD1F0[];
extern const u8 D_800DF230_de[];
extern const u8 D_800DF240[];
extern s32 func_80414400_de(u8 *buf, f64 value, s32 ch, s32 width, s32 prec);

extern f64 D_800E1118;
extern f64 D_800E1130;
extern f64 D_800E1148;
extern f64 D_800E11F0;

#endif
