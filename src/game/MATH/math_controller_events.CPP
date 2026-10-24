#include "include_asm.h"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/8029AE80.H"
#include "MATH/80299ECC.H"
#include "MATH/math_controller_events.H"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80299E84);
#endif
#if !(defined(VERSION_DE)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", DispatchControllerButtonEvent);
#endif

extern s32 func_80299B4C_de(void);
extern s32 func_80299958_de(void);

#ifdef NON_MATCHING
#include "TYPES.H"


#if !defined(VERSION_DE)
/* Turns one control event into manager events. Controls 4..7 and 11..12 first send their own event on a
 * press (controls 4..7 send it twice with amount 10000 when the control was not already held); then every control
 * sends event 10 (first press only) and 9 on a press, or 11 on a release. The per-device held-flag bit for the
 * control is set on a press and cleared otherwise. A control of -1 is ignored. */
static inline s32 ControllerButtonIsHeld(s16 device, s16 control) {
    s32 index = control / 8;
    s32 shift = control - index * 8;
    return ((s8 *)D_8014D0B0->flags)[device * 4 + index] & (1 << shift);
}

static inline void ControllerButtonSetHeld(s16 device, s16 control, s16 pressed) {
    s32 index = control / 8;
    s32 bit = 1 << (control - index * 8);
    if (pressed == 1) {
        D_8014D0B0->flags[device * 4 + index] |= bit;
    } else {
        D_8014D0B0->flags[device * 4 + index] &= ~bit;
    }
}

/* 88/297 aligned edits; remaining: local-alloc order of the held-flag index/shift/bit temporaries (a0/a2/a1 in the ROM). */
void DispatchControllerButtonEvent(ControllerEvent *event) {
    s32 manager;
    s32 source;
    s32 control;
    s16 pressed;

    manager = func_80299958_de();
    source = ((u16)event->source << 16) | (u16)event->device;
    control = event->control;
    pressed = event->pressed == 1;
    if (control == -1) {
        return;
    }
    switch (control) {
    case 11:
        if (pressed && !ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 1, source, control, 0);
        break;
    case 12:
        if (pressed && !ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 2, source, control, 0);
        break;
    case 4:
        if (pressed) {
            if (!ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 5, source, 1, 10000);
            func_802995D4_de(manager, 5, source, 0, 10000);
        }
        break;
    case 5:
        if (pressed) {
            if (!ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 6, source, 1, 10000);
            func_802995D4_de(manager, 6, source, 0, 10000);
        }
        break;
    case 6:
        if (pressed) {
            if (!ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 7, source, 1, 10000);
            func_802995D4_de(manager, 7, source, 0, 10000);
        }
        break;
    case 7:
        if (pressed) {
            if (!ControllerButtonIsHeld((u16)event->device, control)) func_802995D4_de(manager, 8, source, 1, 10000);
            func_802995D4_de(manager, 8, source, 0, 10000);
        }
        break;
    }
    if (pressed == 1) {
        if (!ControllerButtonIsHeld((u16)event->device, control)) {
            func_802995D4_de(manager, 10, source, control, 0);
        }
        func_802995D4_de(manager, 9, source, control, 0);
    } else {
        func_802995D4_de(manager, 11, source, control, 0);
    }
    ControllerButtonSetHeld((u16)event->device, control, pressed);
}
#endif
#endif

static inline ControllerAxisState *Controller_FindAxisState(s32 device, s16 control) {
    return &D_8014D0B0->axes[device][control];
}

void DispatchControllerAxisEvents(ControllerEvent *event) {
    s32 id, threshold, yValue, xValue, yCode, xCode, yCross, xCross;
    s16 dimensions;
    s32 device;
    u32 range;
    s32 hasZ;
    u16 sourceId;
    ControllerAxisState *state;
    sourceId = event->source;
    device = event->device;
    dimensions = (u16)event->kind;
    id = ((u32)sourceId << 16) | (u16)device;
    threshold = func_80299B4C_de();
    yValue = 0;
    xValue = 0;
    range = (u16)(dimensions - 3);
    hasZ = (s16)dimensions == 4;
    state = Controller_FindAxisState(device, event->control - 0x160);
    state->oldX = state->x;
    if (range < 2) state->oldY = state->y;
    if (hasZ) state->oldZ = state->z;
    state->x = event->x;
    if (range < 2) state->y = event->y;
    if (hasZ) state->z = event->z;
    yCode = 0; xCode = 0; yCross = 0; xCross = 0;
    if (state->y > state->oldY) {
        if (state->oldY < threshold) yCross = threshold < state->y;
        yCode = 5; yValue = state->y;
    } else if (state->y < state->oldY) {
        if (-threshold < state->oldY && state->y < -threshold) yCross = 1;
        yCode = 6; yValue = state->y;
    }
    if (state->x > state->oldX) {
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


extern s32 func_80299958_de(void);





void func_8029A558_de(ControllerEvent *event) {

    s32 source;

    if (D_8014D0B0->callback != 0 && D_8014D0B0->callback() == 1) {
        return;
    }

    switch (event->kind) {
    case 0:
        source = ((u16)event->source << 16) | (u16)event->device;
        func_802995D4_de(func_80299958_de(), 0x11, source, event->pressed, event->control);
        break;
    case 1:
        if (event->source == 4) {
            event->source = 3;
            DispatchControllerButtonEvent(event);
        }
        break;
    case 2:
    case 3:
    case 4:
        if (event->source == 4) {
            event->source = 3;
            DispatchControllerAxisEvents(event);
        }
        break;
    }
}

/**
 * Dispatch the first controller-button edge since the previous sample.
 *
 * @name CInput__DispatchButtonEdges
 * @param arg0 Per-controller input context. Offset 0x04 is the controller
 *             port identifier carried by emitted events; 0xB0 and 0xAC are
 *             the current and previous button bitfields; 0xC4 and 0xC5 are
 *             the current analog-stick X and Y samples.
 *
 * The analog-stick sample is posted first through func_8029AB24_de. If the
 * digital button bitfields differ, the masks are then tested in priority
 * order. The first 0-to-1 transition calls func_8029AAD8_de(port, event, 1) for
 * a press, while the first 1-to-0 transition calls it with 0 for a release;
 * the function returns after dispatching that one digital edge.
 *
 * Button event map: Start 0x1000 -> 13; A 0x8000 -> 11; B 0x4000 -> 12;
 * L 0x0020 -> 9; R 0x0010 -> 8; Z 0x2000 -> 10; D-Up 0x0800 -> 4;
 * D-Left 0x0200 -> 6; D-Right 0x0100 -> 7; D-Down 0x0400 -> 5;
 * C-Up 0x0008 -> 0; C-Left 0x0002 -> 2; C-Right 0x0001 -> 3;
 * C-Down 0x0004 -> 1.
 *
 * Game role: Converts raw controller state into the press/release events used
 * by firing, jumping, weapon switching, menu navigation, and pausing.
 */
void func_8029A650_de(char *controllerProfile) {
    s32 current;
    s32 previous;
    current = ((struct ControllerProfile *)(controllerProfile))->buttons;
    previous = ((struct ControllerProfile *)(controllerProfile))->previousButtons;
    func_8029AB24_de(((struct ControllerProfile *)(controllerProfile))->port, ((struct ControllerProfile *)(controllerProfile))->stickX,
                  ((struct ControllerProfile *)(controllerProfile))->stickY);
    if (current == previous) {
        return;
    }
    if (!(current & (0x1000))) goto release_start; if (previous & (0x1000)) goto select_start; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (13), 1); return; release_start: if (!(previous & (0x1000))) goto next_start; select_start: if (current & (0x1000)) goto next_start; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (13), 0); return; next_start: /* Start */
    if (!(current & (0x8000))) goto release_a; if (previous & (0x8000)) goto select_a; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (11), 1); return; release_a: if (!(previous & (0x8000))) goto next_a; select_a: if (current & (0x8000)) goto next_a; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (11), 0); return; next_a: /* A */
    if (!(current & (0x4000))) goto release_b; if (previous & (0x4000)) goto select_b; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (12), 1); return; release_b: if (!(previous & (0x4000))) goto next_b; select_b: if (current & (0x4000)) goto next_b; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (12), 0); return; next_b: /* B */
    if (!(current & (0x20))) goto release_l; if (previous & (0x20)) goto select_l; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (9), 1); return; release_l: if (!(previous & (0x20))) goto next_l; select_l: if (current & (0x20)) goto next_l; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (9), 0); return; next_l: /* L */
    if (!(current & (0x10))) goto release_r; if (previous & (0x10)) goto select_r; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (8), 1); return; release_r: if (!(previous & (0x10))) goto next_r; select_r: if (current & (0x10)) goto next_r; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (8), 0); return; next_r: /* R */
    if (!(current & (0x2000))) goto release_z; if (previous & (0x2000)) goto select_z; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (10), 1); return; release_z: if (!(previous & (0x2000))) goto next_z; select_z: if (current & (0x2000)) goto next_z; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (10), 0); return; next_z: /* Z */
    if (!(current & (0x800))) goto release_d_up; if (previous & (0x800)) goto select_d_up; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (4), 1); return; release_d_up: if (!(previous & (0x800))) goto next_d_up; select_d_up: if (current & (0x800)) goto next_d_up; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (4), 0); return; next_d_up: /* D-Up */
    if (!(current & (0x200))) goto release_d_left; if (previous & (0x200)) goto select_d_left; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (6), 1); return; release_d_left: if (!(previous & (0x200))) goto next_d_left; select_d_left: if (current & (0x200)) goto next_d_left; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (6), 0); return; next_d_left: /* D-Left */
    if (!(current & (0x100))) goto release_d_right; if (previous & (0x100)) goto select_d_right; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (7), 1); return; release_d_right: if (!(previous & (0x100))) goto next_d_right; select_d_right: if (current & (0x100)) goto next_d_right; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (7), 0); return; next_d_right: /* D-Right */
    if (!(current & (0x400))) goto release_d_down; if (previous & (0x400)) goto select_d_down; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (5), 1); return; release_d_down: if (!(previous & (0x400))) goto next_d_down; select_d_down: if (current & (0x400)) goto next_d_down; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (5), 0); return; next_d_down: /* D-Down */
    if (!(current & (8))) goto release_c_up; if (previous & (8)) goto select_c_up; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (0), 1); return; release_c_up: if (!(previous & (8))) goto next_c_up; select_c_up: if (current & (8)) goto next_c_up; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (0), 0); return; next_c_up: /* C-Up */
    if (!(current & (2))) goto release_c_left; if (previous & (2)) goto select_c_left; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (2), 1); return; release_c_left: if (!(previous & (2))) goto next_c_left; select_c_left: if (current & (2)) goto next_c_left; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (2), 0); return; next_c_left: /* C-Left */
    if (!(current & (1))) goto release_c_right; if (previous & (1)) goto select_c_right; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (3), 1); return; release_c_right: if (!(previous & (1))) goto next_c_right; select_c_right: if (current & (1)) goto next_c_right; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (3), 0); return; next_c_right: /* C-Right */
    if (!(current & (4))) goto release_c_down; if (previous & (4)) goto select_c_down; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (1), 1); return; release_c_down: if (!(previous & (4))) goto next_c_down; select_c_down: if (current & (4)) goto next_c_down; func_8029AAD8_de(((struct ControllerProfile *)(controllerProfile))->port, (1), 0); return; next_c_down: /* C-Down */
}
