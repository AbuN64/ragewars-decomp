#include "gfx.h"
#include "span_16E000/code_804143D8.h"
#include "gbi.h"
/* Draws a sprite with the standard 2D state: resets the render-state cache, selects render mode
   0xC through func_80417034_de and combine mode 5 through func_80416CF4_de, emits the other-mode word
   0xE3000C00 and the texture enable (each only when its cached state changes, preceded by one
   pipeline sync), and unless drawing is suppressed (D_80153F60) sets vertex mode 9 and draws
   through func_80415C90_de with the same arguments. */
#include "types.h"

#include "types.h"
#include "n64sdk.h"

extern Gfx *D_80110634;
extern s32 D_800DF290;
extern s32 D_800E32E4;
extern s32 D_800DF274;
extern s32 D_800DF280;
extern s32 D_80153F60;

extern void func_80417034_de(s32 mode);
extern void func_80416CF4_de(s32 mode);
extern void func_80416ECC_de(s32 mode);
extern void func_80415C90_de(f32 x, f32 y, f32 z, f32 a3, s32 a4, s32 a5, s32 a6, s32 a7);

static inline void sync(void) {
    Gfx *cmd;

    if (D_800E32E4 == 0) {
        D_800E32E4 = 1;
        cmd = D_80110634++;
        gDPPipeSync(cmd);
    }
}

static inline void emit(unsigned int w0, unsigned int w1) {
    Gfx *cmd;

    cmd = D_80110634++;
    _GBI_CMD(cmd, w0, w1);
}

void func_80418DE0_de(f32 x, f32 y, s32 unused, f32 z, f32 a4, s32 a5, s32 a6, s32 a7, s32 a8) {
    D_800DF290 = 0;
    D_800E32E4 = 0;
    func_80417034_de(0xC);
    func_80416CF4_de(5);
    if (D_800DF274 != 7) {
        D_800DF274 = 7;
        sync();
        emit(0xE3000C00, 0);
    }
    if (D_800DF280 != 0xE) {
        D_800DF280 = 0xE;
        sync();
        emit(0xD7000000, 0x80008000);
    }
    if (D_80153F60 == 0) {
        func_80416ECC_de(9);
        func_80415C90_de(x, y, z, a4, a5, a6, a7, a8);
    }
}
