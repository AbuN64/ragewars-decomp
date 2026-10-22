#include "include_asm.h"
#include "COMMON/NUMBERPADSCREEN.H"
#include "TYPES.H"
#include "COMMON/GLOBALS.H"

/* Tears down the match display: calls func_80245B28_de, stops the objects at D_80145088 and 0x48 bytes
   before it through func_8044A370_de and func_804499B0_de, releases resource 0x24 of D_8011FE88 through
   func_80286AA8_de, calls func_8025476C_de with one when func_8025477C_de reports nothing, then calls
   func_80245A10_de, func_80245A20_de with zero and func_80245A30_de. */
extern void func_80245B28_de();
extern void func_8044A370_de(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern void func_80286AA8_de(void *, s32, s32);
extern s32 func_8025477C_de();
extern void func_80245A10_de();

extern void func_80245A30_de();

void func_80422020_de(void) {
    char *object;

    func_80245B28_de();
    object = &D_80145088;
    func_8044A370_de(object, 0);
    func_804499B0_de(object - 0x48, 0, 0);
    func_80286AA8_de(&D_8011FE88, 0x24, 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
    func_80245A10_de();
    func_80245A20_de(0);
    func_80245A30_de();
}

void func_804220A8_de(int key) {
 Globals_func_804220A8_de *g = &D_80140FE8_de;
 ParticleView *o = g->object;
 float width = 45.0f;
 float height = D_800DD610[1];
 State_func_804220A8_de *state = D_800E2830;
 int selection;
 o->width = width; o->height = height;
 o->a = state->a; o->b = state->b; o->c = state->c; o->d = state->d;
 selection = func_804030E0_de(key);
 if (!func_8025477C_de()) func_8025476C_de(1);
 func_8044D528_de(&D_8011FE88, ~selection, 0);
 g->width = width; width = height; g->height = width;
}

#if defined(VERSION_US)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DC2C4);
#endif

#if defined(VERSION_EU_X)
INCLUDE_RODATA("data_800C", rodata_unresolved_800E8E54);
#endif

#if defined(VERSION_EU)
INCLUDE_RODATA("data_800C", rodata_unresolved_800EDC94);
#endif

#if defined(VERSION_DE)
INCLUDE_RODATA("data_800C", rodata_unresolved_800DD614);
#endif
