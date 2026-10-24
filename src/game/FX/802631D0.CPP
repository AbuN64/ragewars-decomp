#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/OBJRECAT5F14.H"
#include "TYPES.H"
extern void func_802636B0_de(void *object);

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/OBJRECAT5F14.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
#include "FX/EXTERNS.H"
#include "COMMON/AIPROFILE.H"


extern f32 D_800C42A4_de;
extern f32 D_800C42A8_de;
extern f32 D_800C42B0_de;
extern f32 D_800C42B4_de;
extern f32 D_800C42C0_de;
extern f32 D_800C42C4_de;
extern f32 D_800C42CC_de;
extern f32 D_800C42D0_de;
extern s32 D_800CBB70;

/* 40/307 aligned edits; remaining: the original keeps profile in a saved register (live across
 * func_802747A0_de) and the pitch step in $f5. */
void Fx_BuildControllerState(char *stateBytes, SharedPlayer *player) {
    AiProfile *profile;
    f32 rate;
    f32 strafe;
    f32 sensitivityFactor;
    f32 pitchStep;
    f32 pitch;
    f32 moveSquared;
    f32 turnSquared;
    f32 move;
    f32 turn;
    f32 recenterStep;
    f32 pitchLimit;
    f32 nextPitch;
    f32 shapedMove;
    s32 *buttonMapping;
    s32 sourceButtons;
    s32 mappedButtons;
    s32 moveButtons;
    s32 strafeButtons;
    s32 alternateMoveButtons;
    s32 pitchButtons;
    s8 stickY;
    s8 controlMode;
    struct ControllerProfile *controller;

    profile = player->views5D8.view5D8_0.unk5D8;
    sensitivityFactor = D_800C4298_de - (player->views5E8.view7EC_132.unk7EC * D_800C4290_de);
    controller = ((void **) stateBytes)[16 / sizeof(void *)];
    pitchStep = (f32)profile->sensitivity * D_800C4294_de - D_800C4298_de;
    rate = D_800D2988 * (sensitivityFactor * D_800C429C_de);
    pitchStep = pitchStep * D_800C42A0_de + D_800C4298_de;
    pitchStep *= rate;
    buttonMapping = NULL;
    if (profile->controlMode < 2) {
        if (profile->controlMode >= 0 && profile->remap == 1) {
            buttonMapping = &D_800CBB70;
        }
    }
    if (buttonMapping != NULL) {
        ((s32 *) stateBytes)[36 / sizeof(s32)] = 0;
        ((s32 *) stateBytes)[40 / sizeof(s32)] = 0;
        ((s32 *) stateBytes)[44 / sizeof(s32)] = 0;
        ((s32 *) stateBytes)[48 / sizeof(s32)] = 0;
        ((s32 *) stateBytes)[52 / sizeof(s32)] = 0;
        if (*buttonMapping != 0) {
            do {
                sourceButtons = ((s32 *) buttonMapping)[0 / sizeof(s32)];
                mappedButtons = ((s32 *) buttonMapping)[4 / sizeof(s32)];
                if (controller->buttons & sourceButtons) {
                    ((s32 *) stateBytes)[36 / sizeof(s32)] = (s32) (((s32 *) stateBytes)[36 / sizeof(s32)] | mappedButtons);
                }
                if ((s32)controller->pressedButtons & sourceButtons) {
                    ((s32 *) stateBytes)[40 / sizeof(s32)] = (s32) (((s32 *) stateBytes)[40 / sizeof(s32)] | mappedButtons);
                }
                if (controller->history[0] & sourceButtons) {
                    ((s32 *) stateBytes)[44 / sizeof(s32)] = (s32) (((s32 *) stateBytes)[44 / sizeof(s32)] | mappedButtons);
                }
                if (controller->history[1] & sourceButtons) {
                    ((s32 *) stateBytes)[48 / sizeof(s32)] = (s32) (((s32 *) stateBytes)[48 / sizeof(s32)] | mappedButtons);
                }
                buttonMapping += 2;
                if ((s32)controller->buttonState & sourceButtons) {
                    ((s32 *) stateBytes)[52 / sizeof(s32)] = (s32) (((s32 *) stateBytes)[52 / sizeof(s32)] | mappedButtons);
                }
            } while (*buttonMapping != 0);
        }
    } else {
        ((s32 *) stateBytes)[36 / sizeof(s32)] = (s32) controller->buttons;
        ((s32 *) stateBytes)[40 / sizeof(s32)] = (s32) (s32)controller->pressedButtons;
        ((s32 *) stateBytes)[44 / sizeof(s32)] = (s32) controller->history[0];
        ((s32 *) stateBytes)[48 / sizeof(s32)] = (s32) controller->history[1];
        ((s32 *) stateBytes)[52 / sizeof(s32)] = (s32) (s32)controller->buttonState;
    }
    controlMode = profile->controlMode;
    switch (controlMode) {                            /* irregular */
    case 0:
        moveButtons = ((s32 *) stateBytes)[36 / sizeof(s32)];
        if (moveButtons & 1) {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = (f32) D_800C42A4_de;
        } else if (moveButtons & 2) {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = (f32) D_800C42A8_de;
        } else {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = 0.0f;
        }
        strafeButtons = ((s32 *) stateBytes)[36 / sizeof(s32)];
        ((f32 *) stateBytes)[0 / sizeof(f32)] = (f32) ((f32) controller->previousStickX * D_800C42AC_de);
        if (strafeButtons & 8) {
            ((f32 *) stateBytes)[12 / sizeof(f32)] = (f32) D_800C42B0_de;
        } else if (strafeButtons & 4) {
            ((f32 *) stateBytes)[12 / sizeof(f32)] = (f32) D_800C42B4_de;
        } else {
            ((f32 *) stateBytes)[12 / sizeof(f32)] = 0.0f;
        }
        if (profile->pitchMode != 0) {
            ((f32 *) stateBytes)[4 / sizeof(f32)] = (f32) ((f32) controller->previousStickY * D_800C42B8_de);
        } else if (player->views5E8.view11B4_135.unk11B4 == 0) {
            stickY = controller->previousStickY;
            if (stickY != 0) {
                ((f32 *) stateBytes)[4 / sizeof(f32)] = (f32) (((f32 *) stateBytes)[4 / sizeof(f32)] + (pitchStep * D_800C42BC_de * (f32) stickY));
            }
            pitch = ((f32 *) stateBytes)[4 / sizeof(f32)];
            if (D_800C42C0_de < pitch) {
                ((f32 *) stateBytes)[4 / sizeof(f32)] = (f32) D_800C42C0_de;
            } else if (pitch < D_800C42C4_de) {
                ((f32 *) stateBytes)[4 / sizeof(f32)] = (f32) D_800C42C4_de;
            }
        }
        break;
    case 1:
        alternateMoveButtons = ((s32 *) stateBytes)[36 / sizeof(s32)];
        ((f32 *) stateBytes)[0 / sizeof(f32)] = (f32) ((f32) controller->previousStickX * D_800C42C8_de);
        if (alternateMoveButtons & 1) {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = (f32) D_800C42CC_de;
        } else if (alternateMoveButtons & 2) {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = (f32) D_800C42D0_de;
        } else {
            ((f32 *) stateBytes)[8 / sizeof(f32)] = 0.0f;
        }
        if (player->views5E8.view11B4_135.unk11B4 == 0) {
            ((f32 *) stateBytes)[12 / sizeof(f32)] = (f32) ((f32) controller->previousStickY * D_800C42D4_de);
        } else {
            ((f32 *) stateBytes)[12 / sizeof(f32)] = 0.0f;
        }
        pitchButtons = ((s32 *) stateBytes)[36 / sizeof(s32)];
        if (!(pitchButtons & 0x10)) {
            if (pitchButtons & 8) {
                nextPitch = ((f32 *) stateBytes)[4 / sizeof(f32)] + (pitchStep * D_800C42D8_de);
                pitchLimit = D_800C42DC_de;
                if (pitchLimit < nextPitch) {
                    nextPitch = pitchLimit;
                }
                ((f32 *) stateBytes)[4 / sizeof(f32)] = nextPitch;
            } else if (pitchButtons & 4) {
                nextPitch = ((f32 *) stateBytes)[4 / sizeof(f32)] - (pitchStep * D_800C42E0_de);
                pitchLimit = D_800C42E4_de;
                if (nextPitch < pitchLimit) {
                    nextPitch = pitchLimit;
                }
                ((f32 *) stateBytes)[4 / sizeof(f32)] = nextPitch;
            } else if (profile->pitchMode != 0) {
                strafe = ((f32 *) stateBytes)[12 / sizeof(f32)];
                if ((strafe != 0.0f) && (player->views5E8.view7E8_105.unk7E8 == 0)) {
                    recenterStep = strafe * (sensitivityFactor * D_800C42E8_de);
                    if (recenterStep < 0.0f) {
                        recenterStep = -recenterStep;
                    }
                    ((f32 *) stateBytes)[4 / sizeof(f32)] = func_802747A0_de(((f32 *) stateBytes)[4 / sizeof(f32)], recenterStep);
                }
            }
        }
        break;
    }
    move = ((f32 *) stateBytes)[8 / sizeof(f32)];
    moveSquared = move * move;
    if (moveSquared < 0.0f) {
        shapedMove = move * -moveSquared;
    } else {
        shapedMove = move * moveSquared;
    }
    turn = ((f32 *) stateBytes)[0 / sizeof(f32)];
    turnSquared = turn * turn;
    ((f32 *) stateBytes)[28 / sizeof(f32)] = shapedMove;
    if (turnSquared < 0.0f) {
        ((f32 *) stateBytes)[20 / sizeof(f32)] = (f32) (turn * -turnSquared);
    } else {
        ((f32 *) stateBytes)[20 / sizeof(f32)] = (f32) (turn * turnSquared);
    }
    ((f32 *) stateBytes)[32 / sizeof(f32)] = (f32) ((f32 *) stateBytes)[12 / sizeof(f32)];
    ((f32 *) stateBytes)[24 / sizeof(f32)] = (f32) ((f32 *) stateBytes)[4 / sizeof(f32)];
}
/* Warning: struct Character is not defined (only forward-declared) */
/* Warning: struct TeamInfo is not defined (only forward-declared) */
#else
INCLUDE_ASM("span_1000", Fx_BuildControllerState);
#endif

void func_8026367C_de(void *arg0, s32 attributes) {
    func_802636B0_de(arg0);
    (((struct func_8022BC04_S3 *) ((s8 *) arg0))->unk10) = attributes;
}
