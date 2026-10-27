#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/WORLD.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "TYPES.H"


extern s32 *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);

void func_8022AEA0_de(Shared_ActorView *actor, s32 soundId) {
    s32 field5DC;
    void *soundPosition;

    field5DC = (s32) actor->message;
    if (field5DC != 0) {
        soundPosition = (void *)(field5DC + 0x128);
    } else {
        soundPosition = &actor->position;
    }
    if (g_world.frozen == 0 && D_8011FAC0.clockPaused == 0) {
        func_8025CA24_de(func_8025CC6C_de(), (void *)actor->field11BC);
        actor->field11BC = (s32)func_8025C95C_de((void *)func_8025CC6C_de(), soundId, soundPosition, soundPosition, (s32)actor);
    }
}

void func_8022AF40_de(void *player) {
    func_8025CA24_de(func_8025CC6C_de(), (void *)(((struct IntegerState11C0 *) ((s8 *) player))->unk_11BC));
    (((struct IntegerState11C0 *) ((s8 *) player))->unk_11BC) = 0;
}

void func_8022AF74_de(Shared_ActorView *actor, s32 soundId) {
    s32 field5DC;
    void *soundPosition;

    if (g_world.frozen == 0 && D_8011FAC0.clockPaused == 0) {
        field5DC = (s32) actor->message;
        if (field5DC != 0) {
            soundPosition = (void *)(field5DC + 0x128);
        } else {
            soundPosition = &actor->position;
        }
        func_8025CA24_de(func_8025CC6C_de(), (void *)actor->field11C0);
        actor->field11C0 = (s32)func_8025C95C_de((void *)func_8025CC6C_de(), soundId, soundPosition, soundPosition, (s32)actor);
    }
}

void func_8022B00C_de(void *player) {
    func_8025CA24_de(func_8025CC6C_de(), (void *)(((struct IntegerState11C4 *) ((s8 *) player))->unk_11C0));
    (((struct IntegerState11C4 *) ((s8 *) player))->unk_11C0) = 0;
}

void func_8022B040_de(void *player, s32 transitionParameter) {
    (((struct IntegerState16D4 *) ((s8 *) player))->unk_16D0) = transitionParameter;
    Player_SetPlayerState(player, player, 0x10);
}
