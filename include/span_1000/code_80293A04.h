#ifndef UNBAKE_SPAN_1000_CODE_80293A04_H
#define UNBAKE_SPAN_1000_CODE_80293A04_H
#include "types.h"
#include "common/types_06e4f7ef1f9e.h"
extern void func_8029437C_de(void);

struct IntegerStateB0;
struct IntegerStateB0 {
    unsigned char padding_0[136];
    s32 unk_88;
    unsigned char padding_8C[32];
    s32 unk_AC;
};

extern void func_802941DC_de(s32 arg0);

extern int D_800CD774;

struct Session_func_80293A20_de;
struct Session_func_80293A20_de {
    char pad0[0x25580];
    char menu[0x48];
    char players[0x26DB0 - 0x255C8];
    f32 transitionTime; /* 0x26DB0 */
    s32 previousMode;
    s32 mode;
    s32 target;
    char pad26DC0;
    char phase;
    char pad26DC2[2];
    f32 timer;
    s32 enabled; /* 0x26DC8 */
    char pad26DCC[4];
    s32 transitionBlocked; /* 0x26DD0 */
    s32 clockPaused; /* 0x26DD4 */
    s32 selector; /* 0x26DD8 */
    s32 selectionActive; /* 0x26DDC */
};

extern void func_80293CE4_de();

extern void func_80293E9C_de(void);

struct IntegerStateB0;
typedef struct IntegerStateB0 IntegerStateB0;

extern void func_802944C4_de(s32 arg0);

extern void func_80294434_de(int arg0);

extern void func_802940F8_de(s32 value);

struct func_80293378_S1;
typedef struct func_80293378_S1 func_80293378_S1;

extern void func_80294374_de(void);

extern void func_80294418_de(void);

extern void func_802944A8_de(void);

extern void func_802943A0_de(s32 arg0);

extern void func_80294410_de(void);

extern float D_800C54AC_de;
extern float D_800C54B0_de;

struct IntegerState164;
typedef struct IntegerState164 IntegerState164;

extern float D_800C54A4_de;

extern float D_800C54C0_de;

struct Session_func_80293A20_de;
typedef struct Session_func_80293A20_de Session_func_80293A20_de;

struct ObjRecV2;
typedef struct ObjRecV2 ObjRecV2;

struct IntegerState164;
struct IntegerState164 {
    char pad0[0x160];
    s32 unk_160;
};

extern int D_800CD770;

extern void func_8029412C_de(void);

extern void func_80293DE8_de();

extern void func_802941B8_de(void);

extern void func_802942F0_de(s32 arg0);

extern void func_80294384_de(void);

struct ObjRecV2;
struct ObjRecV2 {
    char pad0[0x26DB0];
    func_80203908_S3_U124 unk26DB0;
};

extern void func_80294134_de(s32 arg0);

extern void func_8029436C_de(void);

extern float D_800C54A8_de;

extern float D_800C54B4_de;



extern void func_80294200_de(void);

struct func_80293378_S1;
struct func_80293378_S1 {
    char pad0[0x26DC4];
    f32 unk26DC4;
};

extern void func_80293FF0_de(void);

#endif
