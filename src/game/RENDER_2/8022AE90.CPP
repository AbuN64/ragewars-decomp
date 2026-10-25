#include "COMMON/INTEGERSTATE1250.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/WORLD.H"
#include "RENDER_2/8022AE90.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "TYPES.H"
extern s32 Weapons_SetPlayerState(SharedPlayer *player, void *target, s32 state);

extern void *func_8025C95C_de(void *, s32, CVector3 *, void *, s32);

extern s32 *func_8025CC6C_de(void);
extern s32 func_8025CA24_de(void *, void *);

void func_8022AEA0_de(Shared_ActorView *actor, s32 arg1) {
    s32 field5DC;
    void *var_s1;

    field5DC = (s32) actor->message;
    if (field5DC != 0) {
        var_s1 = (void *)(field5DC + 0x128);
    } else {
        var_s1 = &actor->position;
    }
    if (g_world.frozen == 0 && D_8011FAC0.clockPaused == 0) {
        func_8025CA24_de(func_8025CC6C_de(), (void *)actor->field11BC);
        actor->field11BC = (s32)func_8025C95C_de((void *)func_8025CC6C_de(), arg1, var_s1, var_s1, (s32)actor);
    }
}

void func_8022AF40_de(void *player) {
    func_8025CA24_de(func_8025CC6C_de(), (void *)(((struct IntegerState11C0 *) ((s8 *) player))->unk_11BC));
    (((struct IntegerState11C0 *) ((s8 *) player))->unk_11BC) = 0;
}

void func_8022AF74_de(Shared_ActorView *actor, s32 arg1) {
    s32 field5DC;
    void *var_s1;

    if (g_world.frozen == 0 && D_8011FAC0.clockPaused == 0) {
        field5DC = (s32) actor->message;
        if (field5DC != 0) {
            var_s1 = (void *)(field5DC + 0x128);
        } else {
            var_s1 = &actor->position;
        }
        func_8025CA24_de(func_8025CC6C_de(), (void *)actor->field11C0);
        actor->field11C0 = (s32)func_8025C95C_de((void *)func_8025CC6C_de(), arg1, var_s1, var_s1, (s32)actor);
    }
}

void func_8022B00C_de(void *player) {
    func_8025CA24_de(func_8025CC6C_de(), (void *)(((struct IntegerState11C4 *) ((s8 *) player))->unk_11C0));
    (((struct IntegerState11C4 *) ((s8 *) player))->unk_11C0) = 0;
}

void func_8022B040_de(void *player, s32 arg1) {
    (((struct IntegerState16D4 *) ((s8 *) player))->unk_16D0) = arg1;
    Weapons_SetPlayerState(player, player, 0x10);
}
