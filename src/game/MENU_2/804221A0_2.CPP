#include "COMMON/WORLD.H"
#include "COMMON/S1_5.H"
#include "TYPES.H"

/* Sets up the match display: calls func_804221E8_de, starts the objects at D_80145088 and 0x48 bytes
   before it through Items_ResetActorPools and func_804499B0_de, loads the resource func_804030E0_de names for
   0x27D into D_8011FE88 through func_8044D528_de, and calls func_8025476C_de with one when func_8025477C_de
   reports nothing. */
#include "COMMON/MENU_MATCH_GLOBALS.H"


extern void Items_ResetActorPools(void *, s32);
extern void func_804499B0_de(void *, s32, s32);
extern s32 func_804030E0_de(s32);
extern void Items_SetSelection(void *, s32, s32);
extern s32 func_8025477C_de();
extern void func_8025476C_de(s32);

void func_80422170_de(void) {
    char *object;

    func_804221E8_de();
    object = &D_80145088;
    Items_ResetActorPools(object, 1);
    func_804499B0_de(object - 0x48, 1, 0);
    Items_SetSelection(&g_world, ~func_804030E0_de(0x27D), 0);
    if (func_8025477C_de() == 0) {
        func_8025476C_de(1);
    }
}

/* Calls func_80245A20_de with 1, func_80245A00_de with the pooled constant D_800E1648 and
   func_80245A5C_de with 0x43, 0x4F, 0x12 and 0x80. */




void func_804221E8_de(void) {
    func_80245A20_de(1);
    Camera_SetResponse((45.0f));
    func_80245A5C_de(0x43, 0x4F, 0x12, 0x80);
}
