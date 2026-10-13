#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"
#include "types.h"




/** Shift the trailing state-history slots down and clear the newest slot. */
void func_802644A8_de(void *arg0) {
    ControllerProfile *o = arg0;
    u8 t_c4;
    u8 t_c5;
    s32 t_b0;
    s32 t_18;
    ControllerConnectionSample t_1c;
    s32 t_20;
    s32 t_24;
    s32 t_28;

    t_c4 = o->stickX;
    t_c5 = o->stickY;
    t_b0 = o->buttons;
    t_18 = o->inputButtons;
    t_1c = o->inputConnection;
    t_20 = o->inputHistory[0];
    t_24 = o->inputHistory[1];
    t_28 = o->inputHistory[2];
    o->inputConnection = (ControllerConnectionSample){0, 0, 0};
    o->inputHistory[0] = 0;
    o->inputHistory[1] = 0;
    o->inputHistory[2] = 0;
    o->previousStickX = t_c4;
    o->previousStickY = t_c5;
    o->previousButtons = t_b0;
    o->buttons = t_18;
    o->connection = t_1c;
    o->history[0] = t_20;
    o->history[1] = t_24;
    o->buttonState = t_28;
}
