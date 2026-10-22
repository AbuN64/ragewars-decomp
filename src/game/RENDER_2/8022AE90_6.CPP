#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "TYPES.H"

extern u8 *func_802A025C_de(u8 *, u8 *);
extern void func_80239770_de(void *, s32, void *, f32);
#include "COMMON/MENU_MATCH_GLOBALS.H"




void func_8022B75C_de(void *arg0, u8 *arg1, f32 arg2) {
    s32 count;
    s32 temp;

    count = ((Shared_ActorView *)arg0)->messageIndex + 1;
    ((Shared_ActorView *)arg0)->messageIndex = count;
    if (count == 5) {
        ((Shared_ActorView *)arg0)->messageIndex = 0;
    }
    func_802A025C_de(((Shared_ActorView *)arg0)->messageHistory[((Shared_ActorView *)arg0)->messageIndex], arg1);
    temp = (s32)((Shared_ActorView *)arg0)->message;
    if (temp != 0) {
        func_80239770_de(&D_80145088, temp,
                      ((Shared_ActorView *)arg0)->messageHistory[((Shared_ActorView *)arg0)->messageIndex],
                      arg2);
    }
}
