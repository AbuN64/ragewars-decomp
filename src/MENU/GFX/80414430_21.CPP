#include "COMMON/TEXTURE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "TYPES.H"
#include "MENU/GFX/80414430_21.H"

#include "COMMON/RECTANGLE_DRAW.H"

extern Gfx *D_80110634;

extern s32 D_800DF290;

extern s32 D_800E32E4;

extern s32 D_800DF274;

extern s32 D_800DF280;



extern void func_80417034_de(s32 mode);

extern void func_80416CF4_de(s32 mode);

extern void func_80416ECC_de(s32 mode);



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

extern int D_800DF250, D_800DF270, D_800DF274, D_800DF278, D_800E32CC;

extern int D_800DF280, D_800DF284, D_800E32D8, D_800DF28C, D_800DF290;

static inline void beginFrame(void) {
    Gfx *g;

    D_800E32E4 = 1;
    g = D_80110634++;
    gDPPipeSync(g);
}

void func_80418DA0_de(f32 x, f32 y, f32 unused, f32 width, f32 height, u32 color) {
    func_80417B20_de(x, y, unused, width, height, 0.0f, 0.0f, D_800DD410_de, D_800DD410_de, color);
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
    if (D_80153F60.x == 0) {
        func_80416ECC_de(9);
        func_80415C90_de(x, y, z, a4, a5, a6, a7, a8);
    }
}

void func_80418F8C_de(void) {
    if (D_800DF250 != 0) {
        D_800DF250 = 0;
        D_800DF270 = 0;
        D_800DF274 = 0;
        D_800DF278 = 0;
        D_800E32CC = 0;
        D_800DF280 = 0;
        D_800DF284 = 0;
        D_800E32D8 = 0;
        D_800DF28C = 0;
        D_800DF290 = 0;
    }
}

void func_80418FF4_de(s32 mode) {
    if (mode != D_800DF274) {
        D_800DF274 = mode;
        if (D_800E32E4 == 0) {
            beginFrame();
        }
        switch (mode) {
        case 6: {
            Gfx *g = D_80110634++;
            gDPSetTexturePersp(g, G_TP_PERSP);
            break;
        }
        case 7: {
            Gfx *g = D_80110634++;
            gDPSetTexturePersp(g, G_TP_NONE);
            break;
        }
        }
    }
}
