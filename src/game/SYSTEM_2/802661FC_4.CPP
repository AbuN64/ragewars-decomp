#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/TARGET.H"
#include "TYPES.H"

extern void func_80266810_de(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void func_80267F98_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 0, 0x100);
}

extern void func_80266810_de(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void func_80267FF0_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 1, 0x100);
}

extern void func_80266810_de(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void func_80268048_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 0, 0x200);
}

extern void func_80266810_de(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void func_802680A0_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 1, 0x200);
}

extern void func_80266810_de(s32, s32, s32, Triple, struct IntPair, s32, s32, s32);
void func_802680F8_de(s32 arg0, s32 arg1, s32 arg2, Triple arg3, struct IntPair arg6) {
    func_80266810_de(arg0, arg1, arg2, arg3, arg6, 1, 0, 0x400);
}
