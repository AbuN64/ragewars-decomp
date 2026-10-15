#ifndef UNBAKE_SPAN_1000_CODE_802A0888_H
#define UNBAKE_SPAN_1000_CODE_802A0888_H
#include "types.h"
#include "common/types_1dc8418c21db.h"

/* Single-message queue used by the acquire/release helpers. */
typedef struct MessageSemaphore {
    OSMesgQueue queue;
    s32 message;
} MessageSemaphore;
extern s32 func_802A03F4_de(u8 *arg0, u8 *arg1);

struct func_802A1A48_S1;
typedef struct func_802A1A48_S1 func_802A1A48_S1;



extern int D_8014D0C4;

extern void func_8029FB74_de(char *base, char *max);

extern u8 *func_802A0294_de(u8 *arg0, u8 *arg1, s32 arg2);

extern int D_800CD900;

extern void func_802A01D8_de(int arg0);

extern int func_802A05B8_de(int arg0);

extern int D_8014D0C8;

struct func_802A1A48_S1;
struct func_802A1A48_S1 {
    char pad0[0x18];
    char unk18;
};

extern u8 *func_802A07DC_de(u8 *arg0, s32 arg1, s32 arg2);

extern void func_8029FE38_de(char *base, s32 n, s32 size, s32 (*compare)(char *a, char *b));

extern int D_8014D0C0;

extern void func_802A0960_de(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);

extern u32 func_802A08B8_de(u8 *arg0, u32 arg1, u32 arg2);

extern signed int ( *D_8014D0CC)(char *, char *);

extern u8 *func_802A0324_de(u8 *destination, u8 *source, s32 count);

extern void func_802A066C_de(s32 n, char *s);

extern u8 *func_802A0444_de(u8 *s, int c);

extern void func_8029F888_de(u8 *path, u8 *drive, u8 *dir, u8 *name, u8 *ext);

extern s32 func_802A0814_de(u8 *arg0, u8 *arg1, s32 arg2);

#endif
