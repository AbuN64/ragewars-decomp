#include "RENDER/render_controller_input.H"
#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "AUDIO_4/802BFE60.H"
#include "sdk/os.h"

#include "sdk/OS_2/802BC630_2.H"
/* Reads the four controllers once per frame and folds them into the combined input record D_8010B0E0.
 * State 0 starts a read through the message queue, converts the pads to the four per-player input
 * records (Render_UpdateControllerInput), ORs their button words into the combined record, adds the stick
 * bytes, and rescales the combined sticks by D_800C42F0_de. States 1 and 3 restart or query the
 * controllers, state 2 does nothing. */
extern u8 D_8010BBB8;
extern char D_8010FC00;
extern ContPad D_8010AEA0[4];
extern float D_800C42F0_de;
extern void func_802B7538_de(void *);
extern void func_802B7740_de(void *, void *);
void Render_ReadControllerStates(void) {
    ControllerProfile *summary;
    s32 i;
    f32 scale;

    switch (D_8010BBB8) {
    case 0:
        osRecvMesg((OSMesgQueue *)&D_8010FC00, (OSMesg *)D_8010BBD8, 1);
        func_802B75F4_de(D_8010AEA0);
        D_8010B0E0.port = -1;
        D_8010B0E0.connected = 0;
        D_8010B0E0.stickX = 0;
        D_8010B0E0.stickY = 0;
        D_8010B0E0.previousStickX = 0;
        D_8010B0E0.previousStickY = 0;
        D_8010B0E0.buttons = 0;
        D_8010B0E0.previousButtons = 0;
        D_8010B0E0.pressedButtons = 0;
        D_8010B0E0.history[0] = 0;
        D_8010B0E0.history[1] = 0;
        D_8010B0E0.buttonState = 0;
        D_8010B0E0.inputButtons = 0;
        D_8010B0E0.inputPreviousButtons = 0;
        D_8010B0E0.inputPressedButtons = 0;
        D_8010B0E0.inputHistory[0] = 0;
        D_8010B0E0.inputHistory[1] = 0;
        D_8010B0E0.inputHistory[2] = 0;
        summary = &D_8010B0E0;
        for (i = 0; i < 4; i++) {
            Render_UpdateControllerInput(&D_8010F328[i], D_8010AEA0[i].stick_x, D_8010AEA0[i].stick_y,
                             D_8010AEA0[i].button);
            summary->connected |= D_8010F328[i].connected;
            summary->stickX += D_8010F328[i].stickX;
            summary->stickY += D_8010F328[i].stickY;
            summary->previousStickX += D_8010F328[i].previousStickX;
            summary->previousStickY += D_8010F328[i].previousStickY;
            summary->buttons |= D_8010F328[i].buttons;
            summary->pressedButtons |= D_8010F328[i].pressedButtons;
            summary->history[0] |= D_8010F328[i].history[0];
            summary->history[1] |= D_8010F328[i].history[1];
            summary->buttonState |= D_8010F328[i].buttonState;
            summary->inputButtons |= D_8010F328[i].inputButtons;
            summary->inputPreviousButtons |= D_8010F328[i].inputPreviousButtons;
            summary->inputPressedButtons |= D_8010F328[i].inputPressedButtons;
            summary->inputHistory[0] |= D_8010F328[i].inputHistory[0];
            summary->inputHistory[1] |= D_8010F328[i].inputHistory[1];
            summary->inputHistory[2] |= D_8010F328[i].inputHistory[2];
        }
        scale = D_800C42F0_de;
        D_8010B0E0.stickX = (s32)(D_8010B0E0.stickX * scale);
        D_8010B0E0.stickY = (s32)(D_8010B0E0.stickY * scale);
        D_8010B0E0.previousStickX = (s32)(D_8010B0E0.previousStickX * scale);
        D_8010B0E0.previousStickY = (s32)(D_8010B0E0.previousStickY * scale);
        break;
    case 1:
        osRecvMesg((OSMesgQueue *)&D_8010FC00, (OSMesg *)D_8010BBD8, 1);
        func_802B7538_de(D_8010BBE0);
        for (i = 0; i < 4; i++) {
            func_80263CF0_de(&D_8010F328[i]);
        }
        break;
    case 2:
        break;
    case 3:
        func_802B7740_de(&D_8010FC00, D_8010BBE0);
        break;
    }
}

/* Polls the controller paks when they are enabled: after func_80285C78_de it tries to take the pak lock
 * D_8010FBC0 without blocking and, holding it, refreshes the four pak entries through func_80264104_de and
 * advances the pak state (state 0 opens the pak through func_802B74B0_de once func_80264728_de detects it,
 * otherwise closes it through func_802B7560_de; states 1 to 3 reset to 0 and close it), then releases the
 * lock. */

extern u8 D_800CBC10;
extern char D_8010EC90;
extern ControllerProfile D_8010F328[4];


extern void func_80264104_de(void *);
extern void func_802B74B0_de(void *);
extern void func_802B7560_de(void *);

void func_80263AF4_de(void) {
    s32 locked;
    s32 i;

    if (D_800CBC10 != 0) {
        func_80285C78_de(&D_8010EC90);
        if ((locked = osRecvMesg(&D_8010FBC0, 0, 0) == 0)) {
            D_800CBC1C = func_802BAD80_de(0);
        }
        if (locked) {
            Render_ReadControllerStates();
            for (i = 0; i < 4; i++) {
                func_80264104_de(&D_8010F328[i]);
            }
            switch (D_8010BBB8) {
            case 0:
                if (func_80264728_de() != 0) {
                    D_8010BBB8 = 1;
                    func_802B74B0_de(&D_8010FC00);
                } else {
                    func_802B7560_de(&D_8010FC00);
                }
                break;
            case 1:
            case 2:
            case 3:
                D_8010BBB8 = 0;
                func_802B7560_de(&D_8010FC00);
                break;
            }
            D_800CBC1C = -1;
            osSendMesg(&D_8010FBC0, 0, 1);
        }
    }
}

/* Updates the state of the four controller ports: a port whose device is gone clears all three flags; a port whose device responds is marked ready, turning a pending reconnection into a reconnect event; a ready port that stops responding is marked pending. */





void func_80263C24_de(void)
{
    s32 i;

    for (i = 0; i < 4; i++) {
        if (func_8026475C_de(i) != 0) {
            if (func_80264634_de(i) != 0) {
                D_8010B310[i] = 1;
                if (D_8010BC28[i] != 0) {
                    D_8010BBF0[i] = 1;
                    D_8010BC28[i] = 0;
                }
            } else if (D_8010B310[i] != 0) {
                D_8010BC28[i] = 1;
            }
        } else {
            D_8010BBF0[i] = 0;
            D_8010BC28[i] = 0;
            D_8010B310[i] = 0;
        }
    }
}

extern s32 func_80285AC4_de(void *arg0, void *arg1, s32 arg2);




void func_80263CF0_de(void *arg0) {
    char *o = (char *) arg0;
    s32 type;
    s32 bit;
    s32 bit2;
    s32 i;

    type = ((ObjectState224 *)(o))->unk_4;
    bit = ((D_8010FBE3[type * 4] >> 3) ^ 1) & 1;
    if (bit != 0 && ((ObjectState224 *)(o))->unk_0 == 0) {
        i = 0;
        ((ObjectState224 *)(o))->unk_4 = type;
        ((ObjectState224 *)(o))->unk_0 = 0;
        ((ObjectState224 *)(o))->unk_C8 = 0;
        ((ObjectState224 *)(o))->unk_CC = 0;
        ((ObjectState224 *)(o))->unk_220 = 0;
        ((ObjectState224 *)(o))->unk_8 = 0;
        ((ObjectState224 *)(o))->unk_C = 0;
        ((ObjectState224 *)(o))->unk_10 = 0;
        ((ObjectState224 *)(o))->unk_C4 = 0;
        ((ObjectState224 *)(o))->unk_C5 = 0;
        ((ObjectState224 *)(o))->unk_C6 = 0;
        ((ObjectState224 *)(o))->unk_C7 = 0;
        ((ObjectState224 *)(o))->unk_14 = 0;
        ((ObjectState224 *)(o))->unk_18 = 0;
        ((ObjectState224 *)(o))->unk_1C = 0;
        ((ObjectState224 *)(o))->unk_20 = 0;
        ((ObjectState224 *)(o))->unk_24 = 0;
        ((ObjectState224 *)(o))->unk_28 = 0;
        do {
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2C = 0;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2D = 0;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2E = 0x30;
            ((struct ObjectState30 *) (o + (i * 4)))->unk_2F = 0;
            i += 1;
        } while (i < 0x20);
        bit2 = ((D_8010FBE3[type * 4] >> 3) ^ 1) & 1;
        ((ObjectState224 *)(o))->unk_D0 = 0;
        ((ObjectState224 *)(o))->unk_D4 = 0;
        ((ObjectState224 *)(o))->unk_0 = bit2;
        func_80285AC4_de(o + 0x140, o + 0x16C, 3);
    }
    ((ObjectState224 *)(o))->unk_0 = bit;
}

void Render_UpdateControllerInput(ControllerProfile *state, s8 x, s8 y, u32 buttons) {
    f32 fx, fy;
    u32 old, pressed, mask;
    ControllerButtonHistory *button;
    s32 i;
    if (state->connected == 0) return;
    buttons &= 0xFFFF;
    if (x < -30) buttons |= 0x20000;
    else if (x > 30) buttons |= 0x40000;
    if (y < -30) buttons |= 0x80000;
    else if (y > 30) buttons |= 0x10000;
    if (x > 0) { x = x - 3; if (x < 0) x = 0; }
    else { x = x + 3; if (x > 0) x = 0; }
    if (y > 0) { y = y - 3; if (y < 0) y = 0; }
    else { y = y + 3; if (y > 0) y = 0; }
    /* fakematch: the one-shot loop gives X one extra gcc register reference. */
    do { fx = x; } while (0);
    fy = y;
    if (fx == -128.0f) fx = -127.0f;
    if (fy == -128.0f) fy = -127.0f;
    if (fx < -80.0f) fx = -80.0f;
    if (80.0f < fx) fx = 80.0f;
    if (fy < -80.0f) fy = -80.0f;
    if (80.0f < fy) fy = 80.0f;
    old = state->inputButtons;
    state->stickX = (s32)fx;
    state->stickY = (s32)fy;
    state->inputButtons = buttons;
    state->inputPreviousButtons = old;
    pressed = (old ^ buttons) & buttons;
    state->inputPressedButtons |= pressed;
    state->inputHistory[2] |= pressed;
    mask = 1;
    button = state->buttonHistory;
    i = 19;
    do {
        if (pressed & mask) {
            if ((s8)button->age < 30) {
                button->age = 0;
                button->taps++;
                if (button->taps > 1) { state->inputHistory[1] |= mask; button->taps = 0; }
            } else { button->taps = 1; button->age = 0; }
        }
        button->age++;
        if ((s8)button->age > 30) button->age = 30;
        if (buttons & mask) {
            if ((s8)button->held >= 0) button->held += 2;
            button->repeat--;
            if ((s8)button->repeat < 0) { button->repeat += 5; state->inputHistory[2] |= mask; }
        } else {
            if ((u8)button->held < 17) {
                if (!(state->inputPreviousButtons & mask)) button->held = 0;
                else { state->inputHistory[0] |= mask; button->held = 0; }
            } else button->held = 0;
            state->inputHistory[2] &= ~mask;
            button->repeat = 48;
        }
        button++;
        mask <<= 1;
    } while (i-- != 0);
}
