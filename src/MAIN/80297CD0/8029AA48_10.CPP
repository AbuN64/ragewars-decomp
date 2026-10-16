#include "span_1000/code_80299DB4.h"
#include "common/types_1dc8418c21db.h"
#include "TYPES.H"

extern s32 func_80299958_de(void);

extern void func_802995D4_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern void func_80299E80_de(EventCode80299DB4 *arg0);

extern void func_8029A324_de(EventCode80299DB4 *arg0);

extern void func_8029AB24_de(s8 port, s32 stick_x, s32 stick_y);

extern void func_8029AAD8_de(s8 port, s32 event, s32 pressed);

/** Store a word through the global pointer at D_8014D0B0. */


s32 func_8025305C_de(s32);

s32 func_802A0748_de(s32, s32, s32);

extern void func_802547E4_de(void *);

void func_8029A558_de(EventCode80299DB4 *arg0) {
    extern Callback *D_8014D0B0;
    s32 temp_s0;

    if (D_8014D0B0->callback != 0 && D_8014D0B0->callback() == 1) {
        return;
    }

    switch (arg0->f4) {
    case 0:
        temp_s0 = ((u16)arg0->f0 << 16) | (u16)arg0->f2;
        func_802995D4_de(func_80299958_de(), 0x11, temp_s0, arg0->fC, arg0->f6);
        break;
    case 1:
        if (arg0->f0 == 4) {
            arg0->f0 = 3;
            func_80299E80_de(arg0);
        }
        break;
    case 2:
    case 3:
    case 4:
        if (arg0->f0 == 4) {
            arg0->f0 = 3;
            func_8029A324_de(arg0);
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
void func_8029A650_de(char *arg0) {
    s32 current;
    s32 previous;
    current = ((struct ControllerProfile *)(arg0))->buttons;
    previous = ((struct ControllerProfile *)(arg0))->previousButtons;
    func_8029AB24_de(((struct ControllerProfile *)(arg0))->port, ((struct ControllerProfile *)(arg0))->stickX,
                  ((struct ControllerProfile *)(arg0))->stickY);
    if (current == previous) {
        return;
    }
    if (!(current & (0x1000))) goto release_start; if (previous & (0x1000)) goto select_start; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (13), 1); return; release_start: if (!(previous & (0x1000))) goto next_start; select_start: if (current & (0x1000)) goto next_start; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (13), 0); return; next_start: /* Start */
    if (!(current & (0x8000))) goto release_a; if (previous & (0x8000)) goto select_a; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (11), 1); return; release_a: if (!(previous & (0x8000))) goto next_a; select_a: if (current & (0x8000)) goto next_a; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (11), 0); return; next_a: /* A */
    if (!(current & (0x4000))) goto release_b; if (previous & (0x4000)) goto select_b; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (12), 1); return; release_b: if (!(previous & (0x4000))) goto next_b; select_b: if (current & (0x4000)) goto next_b; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (12), 0); return; next_b: /* B */
    if (!(current & (0x20))) goto release_l; if (previous & (0x20)) goto select_l; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (9), 1); return; release_l: if (!(previous & (0x20))) goto next_l; select_l: if (current & (0x20)) goto next_l; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (9), 0); return; next_l: /* L */
    if (!(current & (0x10))) goto release_r; if (previous & (0x10)) goto select_r; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (8), 1); return; release_r: if (!(previous & (0x10))) goto next_r; select_r: if (current & (0x10)) goto next_r; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (8), 0); return; next_r: /* R */
    if (!(current & (0x2000))) goto release_z; if (previous & (0x2000)) goto select_z; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (10), 1); return; release_z: if (!(previous & (0x2000))) goto next_z; select_z: if (current & (0x2000)) goto next_z; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (10), 0); return; next_z: /* Z */
    if (!(current & (0x800))) goto release_d_up; if (previous & (0x800)) goto select_d_up; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (4), 1); return; release_d_up: if (!(previous & (0x800))) goto next_d_up; select_d_up: if (current & (0x800)) goto next_d_up; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (4), 0); return; next_d_up: /* D-Up */
    if (!(current & (0x200))) goto release_d_left; if (previous & (0x200)) goto select_d_left; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (6), 1); return; release_d_left: if (!(previous & (0x200))) goto next_d_left; select_d_left: if (current & (0x200)) goto next_d_left; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (6), 0); return; next_d_left: /* D-Left */
    if (!(current & (0x100))) goto release_d_right; if (previous & (0x100)) goto select_d_right; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (7), 1); return; release_d_right: if (!(previous & (0x100))) goto next_d_right; select_d_right: if (current & (0x100)) goto next_d_right; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (7), 0); return; next_d_right: /* D-Right */
    if (!(current & (0x400))) goto release_d_down; if (previous & (0x400)) goto select_d_down; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (5), 1); return; release_d_down: if (!(previous & (0x400))) goto next_d_down; select_d_down: if (current & (0x400)) goto next_d_down; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (5), 0); return; next_d_down: /* D-Down */
    if (!(current & (8))) goto release_c_up; if (previous & (8)) goto select_c_up; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (0), 1); return; release_c_up: if (!(previous & (8))) goto next_c_up; select_c_up: if (current & (8)) goto next_c_up; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (0), 0); return; next_c_up: /* C-Up */
    if (!(current & (2))) goto release_c_left; if (previous & (2)) goto select_c_left; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (2), 1); return; release_c_left: if (!(previous & (2))) goto next_c_left; select_c_left: if (current & (2)) goto next_c_left; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (2), 0); return; next_c_left: /* C-Left */
    if (!(current & (1))) goto release_c_right; if (previous & (1)) goto select_c_right; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (3), 1); return; release_c_right: if (!(previous & (1))) goto next_c_right; select_c_right: if (current & (1)) goto next_c_right; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (3), 0); return; next_c_right: /* C-Right */
    if (!(current & (4))) goto release_c_down; if (previous & (4)) goto select_c_down; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (1), 1); return; release_c_down: if (!(previous & (4))) goto next_c_down; select_c_down: if (current & (4)) goto next_c_down; func_8029AAD8_de(((struct ControllerProfile *)(arg0))->port, (1), 0); return; next_c_down: /* C-Down */
}

void func_8029AA24_de(int arg0) {
    extern int *D_8014D0B0;
    *D_8014D0B0 = arg0;
}

void func_8029AA34_de(void) {
    extern s32 D_8014D0B0;
    s32 idx;
    s32 var_a0;
    s32 var_a1;
    Callback *context;

    var_a1 = 0;
    do {
        var_a0 = 0;
        do {
            idx = var_a0 + var_a1 * 4;
            var_a0 += 1;
            context = (Callback *)D_8014D0B0;
            context->flags[idx] = 0;
        } while (var_a0 < 4);
        var_a1 += 1;
    } while (var_a1 < 0x10);
}

void func_8029AA78_de(void) {
    extern s32 D_8014D0B0;
    s32 temp_v0;
    temp_v0 = func_8025305C_de(0xC44);
    D_8014D0B0 = temp_v0;
    func_802A0748_de(temp_v0, 0, 0xC44);
}

void func_8029AAAC_de(void) {
    extern s32 D_8014D0B0;
    func_802547E4_de(D_8014D0B0);
    D_8014D0B0 = 0;
}
