#include "span_1000/code_80293A04.h"
#include "span_1000/code_80291054.h"
#include "types.h"

extern void func_802A001C_de(s32 arg0, s32 arg1, s32 arg2);
extern void func_802BAC90_de(s32 arg0, s32 arg1, void *arg2, s32 arg3, s32 arg4, s32 arg5);
extern void func_802BB750_de(s32 arg0);
extern s32 func_802BB5F0_de(s32 *, s32);

extern char D_800E7C80_de[];
extern char D_8011B7C0[];
extern char D_00293534[];
extern char D_800EFC80_de[];






void func_80292FC0_de(s32 *arg0, s32 arg1) {
    func_802A001C_de((s32)D_800E7C80_de, 1, 0x8000);
    func_802BAC90_de((s32)D_8011B7C0, 1, D_00293534, arg1, (s32)D_800EFC80_de, D_800CD8B4);
    func_802BB750_de((s32)D_8011B7C0);
    {
        s32 temp = D_800CD8A0_de;
        ((Session_func_80293A20_de *)arg0)->enabled = 0;
        func_802BB5F0_de(0, temp);
    }
loop_1:
    goto loop_1;
}
