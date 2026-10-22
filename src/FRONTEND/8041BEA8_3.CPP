#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/LABEL.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

/* Enables mode 1 through func_802A23C4_de, places the menu model at (17, -10, -50) with uniform scale 0.14, zero rotation and a (0, 5, 0) offset, then issues request 0xE78 through func_8025DF34_de; returns zero. */





/* The hub spells D_800E3590 as the padded menu block; this unit reaches the model name at +0x08
 * through its own view, so each use casts back to it. */
extern void func_80439B5C_de(char *model, s32 arg1, CVector3 scale, CVector3 position);
extern void func_80439BE0_de(char *model, CVector3 rotation);
extern void func_80439C30_de(char *model, CVector3 offset);

s32 func_8041DBCC_de(void) {
    CVector3 scale;
    CVector3 position;
    CVector3 rotation;
    CVector3 offset;

    func_802A23C4_de(1);
    scale.x = 0.14f;
    scale.y = 0.14f;
    scale.z = 0.14f;
    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = 0.0f;
    offset.x = 0.0f;
    offset.y = 5.0f;
    offset.z = 0.0f;
    position.x = 17.0f;
    position.y = -10.0f;
    position.z = -50.0f;
    func_80439B5C_de(((MenuRecAt8 *) D_800E3590)->model, 0, scale, position);
    func_80439BE0_de(((MenuRecAt8 *) D_800E3590)->model, rotation);
    func_80439C30_de(((MenuRecAt8 *) D_800E3590)->model, offset);
    func_8025DF34_de(0xE78);
    return 0;
}

#ifdef NON_MATCHING
/* 66/77 words; remaining: scheduler places the D_800DD528_de load after the D_800D15E4 stores and pointer writeback instead of before the s0 address setup */
#include "gbi.h"
extern s32 func_804399D0(void *);
extern s32 func_80439CC8_de(void *, Gfx **, Gfx *);
extern s32 D_800D15E0;
extern f32 D_800D15E4[4];
extern f32 D_800DD524_de;
extern f32 D_800DD528_de;
extern f32 D_800DD52C_de;
extern s32 D_800E28D0, D_800E28D4;
extern Gfx *D_80110634;
s32 func_8041DCC0_de(void *arg0, void *arg1, s32 event) {
    Gfx *gfx;
    f32 value;
    f32 scale;
    if (event == 1 && D_800E3590->unk216 == 3) {
        value = D_800DD524_de;
        scale = D_800DD528_de;
        D_800D15E0 = 0;
        gfx = D_80110634++;
        gDPSetScissorFrac(gfx, 0, 0, 0, (s32)((f32)(D_800E28D0 - 1) * scale), (s32)((f32)(D_800E28D4 - 1) * scale));
        D_800D15E4[0] = value;
        D_800D15E4[1] = value;
        D_800D15E4[2] = value;
        D_800D15E4[3] = value;
        if (func_80439CC8_de(((MenuRecAt8 *) D_800E3590)->model, &D_80110634, gfx) != 0) {
            D_800D15E0 = event;
            D_800D15E4[3] = D_800DD52C_de;
            func_804399D0(((MenuRecAt8 *) D_800E3590)->model);
            D_800D15E0 = 0;
            D_800D15E4[3] = value;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_8041DCC0_de);
#endif
