/* Opens the pulse-screen state for a course tree handle: clears the screen globals (D_800D15D0,
 * D_800D15E0 and the four-word copy of D_800CA4B0 in D_800D15E4), asks the controller recorder
 * func_8028B21C_de for a new recording handle on the world D_8011FE88, and while a handle exists:
 * resets the player, seeds the local matrix (func_80272C60_de with the bit patterns 0xC2C80000 and
 * 0xC3FA0000 as its limits, then a rotation of arg0-table-scaled angle, then func_80273D6C_de),
 * packs the matrix into the matrix table D_8011F5D0 at slot D_800D297C, confirms the recording,
 * reads it back through func_8026D980_de/func_8026DF30_de/func_8026D9D0_de, and hands the playback
 * request to func_80291FD8_de with the screen height half D_800E28D0 / 2 and the display constants. */
#include "span_1000/code_80233920.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "types.h"

extern s32 func_8028B21C_de(void *arg0, s32 arg1);
extern void func_80235AE0_de(Racer *arg0);
extern void func_80272C60_de(void *arg0, f32 arg1, f32 arg2, f32 arg3);
/* The original call site passes the angle as a plain int word carrying float bits (mfc1/mfc1 pair in
 * several versions of this call); the already-landed definition reinterprets that word internally. */
extern void func_802739C4_de(void *arg0, s32 angleBits);
extern void func_80273D6C_de(void *object);
extern void func_8027027C_de(f32 *src, PackedMatrixWords *dst);
extern s32 func_8028C198_de(void *arg0, s32 arg1);
extern s32 func_8026D980_de(void);
extern void func_8026DF30_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void func_8026D9D0_de(void);
extern void func_80291FD8_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7);

/* Link-published names: D_800CC380 is this cartridge's canonical symbol for the screen block
 * (0x800D15D0), D_80141008 for the player record block (0x801450C8); the D_auto_ names were landed
 * by the data harvest for the remaining blocks. D_800CA4BC has no published symbol; its word sits
 * right after D_800CA4B8, so it is reached through the published neighbor. */
extern int D_8014D428;
extern s32 D_800CC380;
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern f32 D_800CA4B0;
extern f32 D_800CA4B4;
extern f32 D_800CA4B8;
extern s32 D_800D0EF8;
extern s32 D_800D297C;
extern s32 D_auto_800D7068;
extern s32 D_800E28D0;
extern u8 D_26DB0[];
extern PackedMatrixWords D_auto_8011F5D0[];
extern Racer D_80141008;

void func_80290A68_us_rev1(s32 arg0) {
    f32 matrix[16];
    s32 temp_v1; /* FAKEMATCH: the original reads the work-buffer global here and never uses the value. */
    s32 var_s0;
    union { f32 f; s32 i; } angleBits;

    temp_v1 = D_8014D428;
    D_800CC380 = 0;
    var_s0 = func_8028B21C_de(&D_8011FE88, 0xE10);
    D_800D15E0 = 0;
    D_800D15E4[0] = D_800CA4B0;
    D_800D15E4[1] = D_800CA4B0;
    D_800D15E4[2] = D_800CA4B0;
    D_800D15E4[3] = D_800CA4B0;
    if (var_s0 != -1) {
        func_80235AE0_de(&D_80141008);
        func_80272C60_de(matrix, 0.0f, -100.0f, -500.0f);
        angleBits.f = *(f32 *)(&D_26DB0[arg0]) * D_800CA4B4;
        func_802739C4_de(matrix, angleBits.i);
        func_80273D6C_de(matrix);
        func_8027027C_de(matrix, &D_auto_8011F5D0[D_800D297C]);
        var_s0 = func_8028C198_de(&D_8011FE88, var_s0);
        var_s0 = func_8026D980_de();
        func_8026DF30_de(var_s0, (s32)(&D_auto_8011F5D0[D_800D297C]), (s32)&D_800D0EF8, 0, -1);
        func_8026D9D0_de();
        func_80291FD8_de(arg0, 0, D_auto_800D7068, D_800E28D0 / 2, 190, 10, D_800CA4B8, (&D_800CA4B8)[1]);
    }
}
