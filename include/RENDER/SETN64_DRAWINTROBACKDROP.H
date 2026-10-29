#ifndef RENDER_SETN64_DRAWINTROBACKDROP_H
#define RENDER_SETN64_DRAWINTROBACKDROP_H
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
struct IntegerStateB0 {
    unsigned char padding_0[136];
    s32 first;
    unsigned char padding_8C[32];
    s32 transitionActive;
};
struct IntroBackdropStateView {
    char pad0[0x160];
    s32 poolClearedWord;
};
#endif
