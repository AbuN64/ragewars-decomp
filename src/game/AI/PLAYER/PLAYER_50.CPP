#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "TYPES.H"

extern u8 *XPlus_CopyString(u8 *, u8 *);
extern void Sky_PostScaledScreenMessage(void *, s32, void *, f32);
#include "COMMON/MENU_MATCH_GLOBALS.H"




void func_8022B75C_de(void *player, u8 *message, f32 size) {
    s32 count;
    s32 temp;

    count = ((Shared_ActorView *)player)->messageIndex + 1;
    ((Shared_ActorView *)player)->messageIndex = count;
    if (count == 5) {
        ((Shared_ActorView *)player)->messageIndex = 0;
    }
    XPlus_CopyString(((Shared_ActorView *)player)->messageHistory[((Shared_ActorView *)player)->messageIndex], message);
    temp = (s32)((Shared_ActorView *)player)->message;
    if (temp != 0) {
        Sky_PostScaledScreenMessage(&D_80145088, temp,
                      ((Shared_ActorView *)player)->messageHistory[((Shared_ActorView *)player)->messageIndex],
                      size);
    }
}
