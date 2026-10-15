#include "types.h"

typedef struct { u16 source; s16 device; s16 dimensions; u16 control; u8 pad8[6]; s16 x, y, z; } AxisEvent;
typedef struct { s16 oldX, oldY, oldZ, x, y, z; } AxisState;
typedef struct { s32 header; AxisState axes[15]; u8 padB8[8]; } DeviceAxes;
extern DeviceAxes *D_8014D0B0;
extern s32 func_80299B4C_de(void);
extern s32 func_80299958_de(void);
extern s32 func_802995D4_de(s32, s32, s32, s32, s32);

void func_8029A324_de(AxisEvent *event) {
    s32 id, threshold, yValue, xValue, yCode, xCode, yCross, xCross;
    s32 dimensions, multi;
    AxisState *state;
    id = ((u32)event->source << 16) | (u16)event->device;
    dimensions = event->dimensions;
    threshold = func_80299B4C_de();
    yValue = 0;
    xValue = 0;
    state = &D_8014D0B0[event->device].axes[(s16)(event->control - 0x160)];
    state->oldX = state->x;
    multi = (u16)(dimensions - 3) < 2;
    if (multi) state->oldY = state->y;
    if (dimensions == 4) state->oldZ = state->z;
    state->x = event->x;
    if (multi) state->y = event->y;
    if (dimensions == 4) state->z = event->z;
    yCode = 0; xCode = 0; yCross = 0; xCross = 0;
    if (state->oldY < state->y) {
        yCross = state->oldY < threshold && threshold < state->y;
        yCode = 5; yValue = state->y;
    } else if (state->y < state->oldY) {
        if (-threshold < state->oldY && state->y < -threshold) yCross = 1;
        yCode = 6; yValue = state->y;
    }
    if (state->oldX < state->x) {
        if (state->oldX < threshold && threshold < state->x) xCross = 1;
        xCode = 8; xValue = state->x;
    } else if (state->x < state->oldX) {
        if (-threshold < state->oldX && state->x < -threshold) xCross = 1;
        xCode = 7; xValue = state->x;
    }
    if (yCode != 0) func_802995D4_de(func_80299958_de(), yCode, id, yCross, yValue);
    if (xCode != 0) func_802995D4_de(func_80299958_de(), xCode, id, xCross, xValue);
    state->oldX = state->x;
    state->oldY = state->y;
}
