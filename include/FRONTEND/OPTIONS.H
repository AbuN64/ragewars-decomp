#ifndef FRONTEND_OPTIONS_H
#define FRONTEND_OPTIONS_H
#include "TYPES.H"




extern s32 func_80428F08_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct MatchOptionsScreen;
struct MatchOptionsScreen {
    s32 transition[7];
    void *selectWidget;
    void *cursorWidget;
    void *widget24;
    void *widget28;
    void *widget2C;
    void *widget30;
    void *widget34;
    s32 countCap;
    s32 countDefault;
};
#endif
