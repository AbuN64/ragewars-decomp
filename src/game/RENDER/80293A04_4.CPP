#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/AIPROFILE.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "RENDER/80293A04_2.H"
#include "RENDER/80293A04_4.H"
#include "GFX/TEXT/802A8A94_5.H"

/* Clears the map-view-active flag, emits a set-color-image display list command for the current frame
 * buffer, then draws image 0x389 scaled to fill the screen dimensions over the image's returned width
 * and height, when both are nonzero. */





extern Gfx *D_80110634;

#include "COMMON/DISPLAY.H"

extern s32 D_800E28D0;



extern void func_80293A20_de(s32 arg0, s32 arg1, s32 arg2);

extern void func_80293334_de(void *session, s32 count, s32 force_active);

extern void func_80286AA8_de(void *, void *, void *);

extern void func_80298368_de(s32 arg0);


/* func_80245A00_de: types.abi.declared: reuse existing C; propagated semantic conflicts remain named */

/* func_8028D90C_de: types.declaration: solved callee prototype */


void func_802941B8_de(void) {
    D_80141128 = 0;
    System_SetTextureEffect(0U);
}

void func_802941DC_de(struct GameSession *session) {
    s32 eight;
    eight = 8;
    func_80293904_de(session, 12.0f, eight, eight);
}

void func_80294200_de(void) {
    s32 width;
    s32 height;
    Gfx *cmd;

    D_800CC380 = 0;
    width = 0;
    height = 0;
    gDPSetColorImage(D_80110634++, G_IM_FMT_RGBA, G_IM_SIZ_16b, D_800E28D0, (u32)D_8011BDC0->colorImage);
    func_802AA950_de(0x389, 0, &width, &height);
    if ((width != 0) && (height != 0)) {
        Text_SetupSpriteMode(0xFA);
        func_802AAC28_de(0x389, 0, 0, 0, (f32)D_800E28D0 / (f32)width, (f32)D_800E28D4 / (f32)height, 1);
    }
}

void func_802942F0_de(s32 arg0) {
    func_8028D90C_de();
    ((s32 (*)(s32, s32))func_80293998_de)(arg0, 0x5A);
}

void func_80294320_de(s32 session) {
    func_80293A20_de(session, 7, 7);
}

void func_80294340_de(s32 session) {
    func_80293B28_de(session);
    func_80293DE8_de(session);
}

/** Perform no operation. */
void func_8029436C_de(void) {
}

/** Perform no operation. */
void func_80294374_de(void) {
}

/** Perform no operation. */
void func_8029437C_de(void) {
}

/** Thin wrapper calling func_8025E2D4_de with a fixed argument. */
void func_80294384_de(void) {
    func_8025E2D4_de(0x10);
}

void func_802943A0_de(struct GameSession *session) {
    func_80293904_de(session, 20.0f, 9, 8);
}

void func_802943C4_de(void *arg0) {
    func_80293334_de(arg0, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0, 0);
    D_801462C8.counters.transitionActive = 0;
    func_80298368_de(0x18);
    func_8025E2D4_de(0x34);
}

void func_80294410_de(void) {
}

/** Thin wrapper around func_80293CE4_de. */
void func_80294418_de(GameSession *session) {
    func_80293CE4_de(session);
}

/* func_80293998_de: types.abi.declared: reuse existing C; propagated semantic conflicts remain named */


                                                  /* size = 0x18 */

void func_80294434_de(s32 arg0) {
    D_800CD770 += 1;
    func_8028D90C_de();
    func_80245A00_de(0.5f);
    func_80293998_de(arg0, 0x6F);
}

void func_80294488_de(s32 session) {
    func_80293A20_de(session, 7, 8);
}

void func_802944A8_de(void *session) {
    func_80293B28_de(session);
}

void func_802944C4_de(s32 arg0) {
    func_8028D90C_de();
    ((s32 (*)(s32, s32))func_80293998_de)(arg0, 0x6F);
}
