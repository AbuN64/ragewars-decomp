#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "TYPES.H"
#include "RENDER/802944E8_7.H"

#if !(defined(VERSION_US))
extern Entry80294AC4 D_800CD788[];







void func_80294AB0_de(void *gameSession) {
    void (*callback)(void *gameSession);
    s32 index;

    if ((D_80142CA8 == 2) &&
        (((struct GameSession *)gameSession)->transitionBlocked == 0)) {
        index = ((struct GameSession *)gameSession)->target;
        ((struct GameSession *)gameSession)->transitionTime = 0;
        ((struct GameSession *)gameSession)->mode = index;
        func_802456A0_de();
        func_8025E214_de(-1);
        Render_SetControllerMode(0);
        callback = D_800CD788[((struct GameSession *)gameSession)->mode].callback;
        if (callback != 0) {
            callback(gameSession);
        }
    }
}
#endif
