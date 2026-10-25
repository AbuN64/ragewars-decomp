#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "SOUND/8022C894.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/PROBE.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
extern s32 Weapons_SetPlayerState(void *, void *, s32);
extern void func_802233F0_de(void *, void *, void *);
extern void Weapons_UpdateViewAngles(void *, void *, void *);
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"

/* Runs a player's grounded movement state: updates it through func_8022404C_de, eases the value at
   0x72C to zero by a quarter, applies the movement tables D_800CE7FC and D_800CE7C0, then leaves for
   state 2 when not on the ground (animation 0x5E24 for the D_800CED30 state table, otherwise 1), or
   picks the animation from the stick at 0x6C0 and 0x6C4: 0xA64 at rest, 0xA67 or 0xA66 when the
   second axis dominates and 0xA65 or 0xA68 otherwise, by the sign of the dominant axis. */

extern void func_8022404C_de(void *, void *);




extern s32 D_800CED30;

extern s32 D_8013B2BC;


extern u8 *func_8024E6A0_de(void *arg0);

extern void func_8024E6D8_de(u8 *arg0, CVector3 *arg1);

/* Phase1 source candidate; contract holds and immutable inputs in per-function JSON. */



extern s32 func_8024E62C_de(void *arg0);

extern f32 func_8024E678_de(void *arg0, s32 arg1);




extern int D_80104418;

void func_8022C8A4_de(struct SharedPlayer *player, void *arg1) {
    if ((player->views5E8.view6C0_51.unk6C0 != 0.0f) || (player->views5E8.view6C4_54.unk6C4 != 0.0f)) {
        Weapons_SetPlayerState(player, arg1, 3);
    }
}

void func_8022C8EC_de(void) {
}

void func_8022C8F4_de(void) {
}

void func_8022C8FC_de(struct SharedPlayer *player, void *arg1) {
    f32 x;
    f32 y;
    f32 zero;

    func_8022404C_de(player, arg1);
    zero = 0.0f;
    Nav_EaseValueToward(&player->views5E8.view72C_75.unk72C, zero, 0.25f);
    Weapons_UpdateViewAngles(player, arg1, &D_800CE7FC);
    func_802233F0_de(player, arg1, &D_800CE7C0);
    if (!(player->views5E8.view6AC_45.unk6AC & 0x10)) {
        Weapons_SetPlayerState(player, arg1, 2);
        if (player->views13B4.view13B4_3.character == &D_800CED30) {
            player->views5E8.view86C_125.unk86C = 0x5E24;
        } else {
            player->views5E8.view86C_125.unk86C = 1;
        }
    } else {
        x = player->views5E8.view6C0_51.unk6C0;
        if (x != zero || player->views5E8.view6C4_54.unk6C4 != zero) {
            y = player->views5E8.view6C4_54.unk6C4;
            if (x < y) {
                if (zero < y) {
                    player->views5E8.view86C_125.unk86C = 0xA67;
                } else {
                    player->views5E8.view86C_125.unk86C = 0xA66;
                }
            } else if (zero < x) {
                player->views5E8.view86C_125.unk86C = 0xA65;
            } else {
                player->views5E8.view86C_125.unk86C = 0xA68;
            }
        } else {
            player->views5E8.view86C_125.unk86C = 0xA64;
        }
    }
}

void func_8022CA14_de(Player *player, void *arg1) {
    CVector3 vector;
    f32 scale;
    u8 *result;
    u8 state;
    s32 mode;
    CGameStatus *audio;

    scale = D_800C2D60_de;
    if (D_8013B2BC == 0x1DB1) {
        scale = D_800C2D64_de;
    }
    ((LevelActor *)arg1)->position1.y =
        scale * ((Resource_u1 *)((LevelActor *)arg1)->definition)->value20;
    result = func_8024E6A0_de(arg1);
    if (result != 0) {
        func_8024E6D8_de(result, &vector);
        Particle_AddVec3(&((LevelActor *)arg1)->position1,
                      &((LevelActor *)arg1)->position1, &vector);
    }

    state = ((Shared_ControlView *)player->profile)->transientFlag;
    if (state == 1) {
        audio = &D_801462C8.counters;
        if (audio->m_bFragTagOn != 0) {
            mode = audio->m_nFragTagSkin;
            switch (mode) {
        case 0:
            Render_PlaySoundAtPosition(0x18A1,
                          player->pos,
                          (s32)&player->pos, -1);
            break;
        case 1:
            Render_PlaySoundAtPosition(0x1969,
                          player->pos,
                          (s32)&player->pos, -1);
            break;
        case 2:
            Render_PlaySoundAtPosition(0x1905,
                          player->pos,
                          (s32)&player->pos, -1);
            break;
            }
        }
    }
}

void func_8022CB5C_de(void *player, LevelActor *actor) {
    f32 scale;

    scale = D_800C2D68_de;
    if (D_8013B2BC == 0x1DB1) {
        scale = D_800C2D6C_de;
    }
    if (((Player *)player)->computer != 0) {
        f32 current;

        current = ((Player *)player)->poseTimer;
        if (D_800C2D70_de <= current) {
            goto transition;
        }
        goto scale_value;
    }
    if (!(((Player *)player)->inputFlags & 0x10)) {
        goto transition;
    } else {
        f32 current;

        current = ((Player *)player)->poseTimer;
        if (!(D_800C2D74_de <= current)) {
            goto scale_value;
        }
    }
transition:
    Weapons_SetPlayerState(player, actor, 6);
    goto finish;
scale_value:
    actor->position1.y =
        scale * ((Resource_u1 *)actor->definition)->value20;
finish:
    func_8022CC34_de(player, actor);
}

void func_8022CC34_de(void *player, void *body) {
    s32 value;

    Nav_EaseValueToward(&((Player *)player)->lean, 0.0f, 0.25f);
    Weapons_UpdateViewAngles(player, body, &D_800CE7E4);
    if (!(((Player *)player)->flags660 & 0x8000)) {
        func_802233F0_de(player, body, &D_800C94EC_de);
    }
    if (((LevelActor *)body)->position1.y <= 0.0f) {
        if (func_8024E62C_de(body) != 0) {
            Weapons_SetPlayerState(player, body, 2);
        }
    }
    if (((LevelActor *)body)->position1.y <= 0.0f) {
        if (func_8024E678_de(body, 0) < 0.0f) {
            if (-func_8024E678_de(body, 0) < D_800C2D78_de[0]) {
                goto set_value;
            }
        } else if (func_8024E678_de(body, 0) < D_800C2D78_de[1]) {
set_value:
            if (((Player *)player)->animationTable == &D_800CED30) {
                ((Player *)player)->animation = 0x5E2E;
            } else {
                ((Player *)player)->animation = 0x7F8;
            }
        }
    }
}

void func_8022CD78_de(void *arg0, void *arg1) {
    if ((((struct FloatState6C8 *) ((s8 *) arg0))->unk_6A4) < 0.0f) {
        (((struct FloatState6C8 *) ((s8 *) arg0))->unk_6C4) = (f32) D_800C2D80_de;
    } else {
        (((struct FloatState6C8 *) ((s8 *) arg0))->unk_6C4) = (f32) D_800C2D84_de;
    }
    (((struct func_8022CA04_S3 *) ((s8 *) arg1))->unk20) = (f32) D_800C2D88_de;
}

void func_8022CDBC_de(void *player, LevelActor *actor) {
    f32 temp_f2;

    temp_f2 = ((Shared_ActorView *)player)->lateralSpeed;
    if ((temp_f2 < 0.0f && ((Shared_ActorView *)player)->lateralInput >= 0.0f) ||
        (temp_f2 > 0.0f && ((Shared_ActorView *)player)->lateralInput <= 0.0f) ||
        (((Shared_ActorView *)player)->actionTimer >= D_800C2D8C_de)) {
        Weapons_SetPlayerState(player, actor, 8);
    } else {
        actor->position1.y = D_800C2D90_de;
    }
    func_8022CE78_de((s32)player, (s32)actor);
}

void func_8022CE78_de(s32 player, s32 body) {
    Nav_EaseValueToward(player + 0x72C, 0.0f, 0.25f);
    Weapons_UpdateViewAngles((void *)player, (void *)body, &D_800CE7E4);
    func_802233F0_de((void *)player, (void *)body, &D_800C9558_de);
    if (((LevelActor *)body)->position1.y <= 0.0f) {
        if (func_8024E62C_de((void *) body) != 0) {
            Weapons_SetPlayerState((void *) player, (void *) body, 2);
        }
    }
}

void func_8022CF18_de(void) {
    int *p = &D_80104418;
    *p &= 0xFFEFFFFF;
}
