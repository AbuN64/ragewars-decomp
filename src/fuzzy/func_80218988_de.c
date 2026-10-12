#include "types.h"

typedef struct StickInput { char pad00[0xC6]; s8 x, y; } StickInput;
typedef struct StickPlayer { char pad00[0x698]; StickInput *input; } StickPlayer;

s32 func_80218988_de(StickPlayer *player) {
    StickInput *input;
    s32 x, y, difference, a, b;
    u8 rawX, rawY;
    input = player->input;
    x = input->x;
    y = input->y;
    rawX = (u8)input->x;
    rawY = (u8)input->y;
    if (x*x + y*y < 0xE10) return -1;
    a = x;
    if ((f32)a < 0.0f) a = -a;
    if ((f32)y < 0.0f) difference = a + y;
    else difference = a - y;
    if ((f32)difference < 0.0f) {
        a = (s8)rawX;
        if ((f32)a < 0.0f) a = -a;
        b = (s8)rawY;
        if ((f32)b < 0.0f) b = -b;
        difference = b - a;
    } else {
        a = (s8)rawX;
        if ((f32)a < 0.0f) a = -a;
        b = (s8)rawY;
        if ((f32)b < 0.0f) difference = a + b;
        else difference = a - b;
    }
    if (difference < 46 && rawX && rawY) return -1;
    a = (s8)rawX;
    if ((f32)a < 0.0f) a = -a;
    b = (s8)rawY;
    if ((f32)b < 0.0f) b = -b;
    if (a > b) {
        if ((s8)rawX > 0) return 1;
        return 3;
    }
    return ((s8)rawY <= 0) << 1;
}
