#include "types.h"

typedef struct { s8 taps; u8 age, repeat, held; } InputButton;
typedef struct { s32 active; char pad4[0x10]; u32 previous, current, pressed, released, doubleTap, repeating; InputButton buttons[20]; char pad7C[0x48]; s8 x, y; } InputState;
extern f32 D_800C42F4_de, D_800C42F8_de, D_800C42FC_de, D_800C4300_de, D_800C4304_de;

void func_80263DFC_de(InputState *state, s8 x, s8 y, u32 buttons) {
    s8 ax, ay;
    f32 fx, fy;
    u32 old, pressed, mask;
    InputButton *button;
    s32 i;
    if (state->active == 0) return;
    buttons &= 0xFFFF;
    if (x < -30) buttons |= 0x20000;
    else if (x > 30) buttons |= 0x40000;
    if (y < -30) buttons |= 0x80000;
    else if (y > 30) buttons |= 0x10000;
    if (x > 0) { ax = x - 3; if (ax < 0) ax = 0; }
    else { ax = x + 3; if (ax > 0) ax = 0; }
    if (y > 0) { ay = y - 3; if (ay < 0) ay = 0; }
    else { ay = y + 3; if (ay > 0) ay = 0; }
    fx = D_800C42F8_de;
    if ((f32)ax != D_800C42F4_de) fx = ax;
    fy = D_800C42FC_de;
    if ((f32)ay != D_800C42F4_de) fy = ay;
    if (fx < D_800C4300_de) fx = D_800C4300_de;
    if (D_800C4304_de < fx) fx = D_800C4304_de;
    if (fy < D_800C4300_de) fy = D_800C4300_de;
    if (D_800C4304_de < fy) fy = D_800C4304_de;
    old = state->current;
    state->x = (s32)fx;
    state->y = (s32)fy;
    state->current = buttons;
    state->previous = old;
    pressed = (old ^ buttons) & buttons;
    state->pressed |= pressed;
    state->repeating |= pressed;
    mask = 1;
    button = state->buttons;
    for (i = 19; i >= 0; i--, button++, mask <<= 1) {
        if (pressed & mask) {
            if ((s8)button->age < 30) {
                button->age = 0;
                button->taps++;
                if (button->taps > 1) { state->doubleTap |= mask; button->taps = 0; }
            } else { button->taps = 1; button->age = 0; }
        }
        button->age++;
        if ((s8)button->age > 30) button->age = 30;
        if (!(buttons & mask)) {
            if (button->held < 17) {
                if (!(state->previous & mask)) button->held = 0;
                else { state->released |= mask; button->held = 0; }
            } else button->held = 0;
            state->repeating &= ~mask;
            button->repeat = 48;
        } else {
            if ((s8)button->held >= 0) button->held += 2;
            button->repeat--;
            if ((s8)button->repeat < 0) { button->repeat += 5; state->repeating |= mask; }
        }
    }
}
