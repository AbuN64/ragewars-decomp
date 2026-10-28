#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "SOUND/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/OBJB.H"
#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
extern void Player_ReleaseObjectHandles(ResourceHandleOwner *object);

extern s32 D_800CED30;

/* Resets an actor's motion state, advances its wait timer, and fires action 0x13 or 0x14 once the timer passes its limit or the game mode allows it. */




extern f32 D_800C2DB0_de[];



extern void Player_UpdateViewAngles(s32, s32, void *);




extern void ContPad_ClearControllerInput(void *object);

s32 CCinema_RequestTrackWithCallbacks(s32, s32, s32 *);




void func_8022D290_de(Shared_ActorView *widget) {
    s32 clearedActorFlags;

    widget->unk_0x0860 = 0;
    Player_ReleaseObjectHandles((s32) widget);
    clearedActorFlags = widget->flags & 0xFF7FFFFF;
    widget->flags = clearedActorFlags;
    widget->unk_0x001C = 0;
    widget->unk_0x0020 = 0;
    widget->unk_0x0024 = 0;
    widget->stun = 0.0f;
    widget->flags = clearedActorFlags | 0x01000000;
    widget->marker.word = 0;
    widget->flags = clearedActorFlags | 0x01000000;
    if (widget->field13B4 == &D_800CED30) {
        widget->effectId = 0x5E24;
    } else {
        widget->effectId = 1;
    }
}

void func_8022D308_de(Shared_ActorView *player) {
    f32 wait;
    f32 D_800C7EA0_1;
    CGameStatus *mode;

    player->flags &= 0xFF7FFFFF;
    player->unk_0x001C = 0;
    player->unk_0x0020 = 0;
    player->unk_0x0024 = 0;
    player->stun = 0.0f;
    player->marker.word = 0;
    player->flags |= 0x01000000;
    if (player->field13B4 == &D_800CED30) {
        player->effectId = 0x5E24;
    } else {
        player->effectId = 1;
    }
    D_800C7EA0_1 = D_800C2DB0_de[1];
    wait = *(f32 *) &player->unk_0x0860 + D_800D2988;
    *(f32 *) &player->unk_0x0860 = wait;
    if (wait > D_800C7EA0_1) {
        goto fire;
    }
    if ((mode = &D_801462C8.counters)->round != 0 && mode->elapsed != 0) {
        fire:
        if ((mode = &D_801462C8.counters)->round != 0 && 0 == mode->elapsed) {
            Player_SetPlayerState(player, player, 0x14);
        } else {
            Player_SetPlayerState(player, player, 0x13);
        }

    }
}

void func_8022D3EC_de(void) {
}

void func_8022D3F4_de(void) {
}

void func_8022D3FC_de(s32 player, s32 body) {
    Player_UpdateViewAngles(player, body, &D_800CE7E4);
}

/** Perform no operation. */
void func_8022D420_de(void) {
}

void func_8022D428_de(void *player) {
    Shared_ActorView *actor = player;
    if (actor->unk_0x0850 == 0) {
        if ((actor->unk_0x0664 & 0x8000) == 0) {
            Graphu64_EaseValueToward(&actor->unk_0x072C, 1.308997f, 0.25f);
        }
        if (actor->actionTimer > D_800C2DB8_de) {
            Player_UpdateRunEndPlayer(player);
        }
    }
}

void func_8022D49C_de(void) {
}

void func_8022D4A4_de(void) {
}

/** Set bit 0x20 in the word at object offset 0x122C. */
void func_8022D4AC_de(struct SharedPlayer *player) {
    player->views122C.view122C_0.unk122C |= 0x20;
}

void func_8022D4BC_de(void *runEndPlayer)
{
  f32 new_var;
  new_var = ((ObjectLinks1458_2 *)(runEndPlayer))->unk_658;
  if (D_800C2DBC_de < new_var)
  {
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_13C8 = 1;
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_1238 = -1;
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_1230 = 0;
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_122C = (((ObjectLinks1458_2 *)(runEndPlayer))->unk_122C) & (~0x20);
    Player_UpdateRunEndPlayer(runEndPlayer);
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_50 = D_800C2DC0_de;
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_54 = D_800C2DC0_de;
    ((ObjectLinks1458_2 *)(runEndPlayer))->unk_58 = D_800C2DC0_de;
    return;
  }
  ContPad_ClearControllerInput(((Shared_ActorView *)runEndPlayer)->profile);
  ((struct IntegerState244 *) ((char *) ((ObjectLinks1458_2 *) runEndPlayer)->unk_1454))->unk_23C = 0;
  ((struct IntegerState244 *) ((char *) ((ObjectLinks1458_2 *) runEndPlayer)->unk_1454))->unk_240 = 0;
}

void func_8022D54C_de(s32 requestValue) {
    D_80102A48 = requestValue;
    CCinema_RequestTrackWithCallbacks(0x50, 0, &D_0022ED24);
}

void func_8022D57C_de(void *player) {
    Shared_ActorView *actor = player;
    f32 value;

    if (actor->unk_0x0850 != 0) {
        return;
    }
    if ((actor->unk_0x0664 & 0x8000) == 0) {
        Graphu64_EaseValueToward(&actor->unk_0x072C, 1.308997f, 0.25f);
    }
    value = actor->actionTimer;
    if (D_800C2DC4_de < value) {
        Player_UpdateRunEndPlayer(player);
    }
}

void func_8022D5F0_de(void *a, void *b) { Playerai_TryStartPlayerSequence(a, b, 0xA); }
