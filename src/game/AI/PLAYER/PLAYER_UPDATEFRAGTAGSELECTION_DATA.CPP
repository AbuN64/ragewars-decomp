#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/LONE/D_800E28D4.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "GFX/8022BA90.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "GAME/CODE_8027302C.H"
#include "GFX/TEXT/802A8A94_5.H"

extern void func_8022BF04_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3);

extern s32 InstHdr_FindActorModelEntry(void *);

extern f32 D_800D2988;

/** Set up a player's starting lives from the game mode and character, then reset its respawn state. */








extern Rules_func_8022C110_de D_801462C8;

extern Course *D_800E4680;

extern char D_80102B00[][0x190];

extern unsigned char Player_GetLevelProgress(char *, int);

extern u8 D_801462DE;

extern s32 D_800E28D0;


void OnScreen_SetupSpriteMode(u8 arg0);

extern const struct D_800C7470_Pair D_800C2D40_de;



extern void Player_BuildPlayerViewTransform(Player1680 *, Matrix *);

extern void Graphu64_GetMatrixTranslation(Matrix *, CVector3 *);

extern void Graphu64_IdentityMatrix(Matrix *);

extern void TranslateMatrix(Matrix *, float, float, float);

extern void Graphu64_ConvertMatrixToFixed(Matrix *, void *);

static inline void getEye(Player1680 *player, CVector3 *pos) {
    Matrix frame;

    if (player->mount != 0) {
        *pos = player->mount->unk128;
    } else {
        Player_BuildPlayerViewTransform(player, &frame);
        Graphu64_GetMatrixTranslation(&frame, pos);
    }
}

static inline float getYaw(void) {
    return D_80140FC0 * D_800C2D40_de.first;
}

extern void Playerai_InitializePlayerHealth(void *arg0);

void func_8022C060_de(s32 player, s32 arg1) {
    func_8022BF04_de(player, arg1, 5, 0x1B);
}

void func_8022C080_de(void *actorView, void *bodyActor) {
    void *result;
    f32 t0;
    f32 t1;

    result = (void *)InstHdr_FindActorModelEntry(bodyActor);
    if (result != 0) {
        t0 = ((ModelBlend *)result)->blend;
        t1 = ((Shared_ActorView *)actorView)->modelBlend;
        t0 = t0 - t1;
        t0 = t0 * D_800C2D28_de;
        t1 = t1 + t0;
        ((Shared_ActorView *)actorView)->modelBlend = t1;
    }
}

void func_8022C0D0_de(void *player) {
    f32 remainingTime;
    f32 previousTime;
    previousTime = (((struct FloatState67C *) ((s8 *) player))->unk_678);
    if (previousTime > 0.0f) {
        remainingTime = previousTime - D_800D2988;
        (((struct FloatState67C *) ((s8 *) player))->unk_678) = remainingTime;
        if (remainingTime < 0.0f) {
            (((struct FloatState67C *) ((s8 *) player))->unk_678) = 0.0f;
        }
    }
}

void func_8022C110_de(PlayerRecAt1450V2 *player) {
    short state;

    if (D_801462C8.started != 0) {
        if (D_801462C8.mode == 1 && player->isBot == 0) {
            player->lives = (unsigned char)Player_GetLevelProgress(D_80102B00[player->character], player->info->unk80) / 2 + 1;
        }
        if (D_801462C8.mode == 4 && player->isBot == 0 && D_800E4680 != 0) {
            player->lives = D_800E4680->laps;
        }
        state = 1;
    } else {
        state = 3;
    }
    player->state = state;
    player->timer = 0;
}

void func_8022C1E8_de(char *player, char *view) {
    f32 x, y;
    f32 sx, sy;
    f32 bx, by;
    f32 t1, t2;
    f32 w;
    f32 screenX, screenY;

    OnScreen_SetupSpriteMode(D_801462DE);

    x = ((Shared_HudView *)view)->width;
    sx = x / (f32) D_800E28D0;
    bx = sx * D_800C2D2C_de;

    y = ((Shared_HudView *)view)->height;
    sy = y / (f32) D_800E28D4;
    by = sy * D_800C2D2C_de;

    t1 = ((Shared_HudView *)view)->x + x;
    t2 = ((Shared_HudView *)view)->y + y;
    w = ((SharedPlayer *)player)->views5E8.view7BC_101.unk7BC;

    screenX = t1 + bx;
    screenY = t2 + by;

    OnScreen_DrawSpriteResource(0x1FC, (s32) w, (s16) (s32) screenX, (s16) (s32) screenY, sx, sy, 1);
}

void func_8022C2B4_de(void *arg0, struct ScreenRectangle *viewport)
{
  f32 x;
  f32 y;
  f32 ax;
  f32 ay;
  f32 sx;
  f32 sy;
  f32 bx;
  f32 by;
  f32 screenX;
  f32 screenY;
  OnScreen_SetupSpriteMode(D_801462DE);
  x = viewport->x;
  ax = x * D_800C2D30_de;
  y = viewport->y;
  ay = y * D_800C2D30_de;
  sx = x / ((f32) D_800E28D0);
  bx = sx * D_800C2D34_de;
  sy = y / ((f32) D_800E28D4);
  by = sy * D_800C2D34_de;
  screenX = ((viewport->width) + ax) - bx;
  screenY = ((viewport->height) + ay) - by;
  OnScreen_DrawSpriteResource(0x1FB, 0, (s16) ((s32) (((viewport->width) + ax) - bx)), (s16) ((s32) screenY), sx, sy, 1);
}

void func_8022C37C_de(char *player, char *view) {
    f32 x, y;
    f32 sx, sy;
    f32 bx, by, cz;
    f32 t1, t2;
    f32 w;
    f32 screenX, screenY;

    OnScreen_SetupSpriteMode(D_801462DE);

    x = ((Shared_HudView *)view)->width;
    sx = x / (f32) D_800E28D0;
    bx = sx * D_800C2D38_de;

    y = ((Shared_HudView *)view)->height;
    sy = y / (f32) D_800E28D4;
    by = sy * D_800C2D38_de;

    cz = sy * D_800C2D3C_de;

    t1 = ((Shared_HudView *)view)->x + x;
    t2 = ((Shared_HudView *)view)->y + y;
    w = ((SharedPlayer *)player)->views5E8.view7BC_101.unk7BC;

    screenX = t1 + bx;
    screenY = t2 + by;

    OnScreen_DrawSpriteResource(0x201, (s32) w, (s16) (s32) screenX, (s16) (s32) screenY, sx, cz, 1);
}

void *func_8022C454_de(void *actorObject) {
    struct Player *player = actorObject;
    AiProfile *p = player->profile;
    p->state90 = 0;
    return p;
}

s32 func_8022C460_de(void *actorObject) {
    Shared_ActorView *player = actorObject;
    s16 action;
    action = player->action;
    if ((action == 0x15) || (action == 0x13) || (action == 0x14)) {
        return 1;
    }
    return 0;
}

void func_8022C490_de(Player1680 *player) {
    Matrix mtx;
    CVector3 pos;

    getEye(player, &pos);
    Graphu64_IdentityMatrix(&mtx);
    BuildYawMatrix(&mtx, getYaw());
    TranslateMatrix(&mtx, pos.x, pos.y + D_800C2D40_de.second, pos.z);
    Graphu64_ConvertMatrixToFixed(&mtx, &player->views[D_800D297C]);
}

void *func_8022C55C_de(void *playerWorld, u32 eligiblePlayerIndex) {
    struct World_func_802283B8_de *world = playerWorld;
    Shared_ActorView *actor;
    s32 eligibleOrdinal;

    actor = 0;
    eligibleOrdinal = 0;
    if (eligiblePlayerIndex < 8U) {
        actor = (void *)world->players;
        if (actor != 0) {
            do {
                if ((u8)actor->controls->resetFlag == 0) {
                    if (eligibleOrdinal == (s32) eligiblePlayerIndex) {
                        return actor;
                    }
                    eligibleOrdinal += 1;
                }
                actor = actor->next;
            } while (actor != 0);
        }
    }
    return actor;
}

void func_8022C5AC_de(char *object) {
    struct World_func_802283B8_de *world = (void *)object;
    Shared_ActorView *record = (void *)world->players;
    while (record != 0) {
        Shared_ControlView *nested = record->controls;
        if ((u8)nested->resetFlag == 1) {
            nested->resetFlag = 0;
        }
        record = record->next;
    }
}

void func_8022C5DC_de(void *object) {
    struct World_func_802283B8_de *world = (void *)object;
    Shared_ActorView *record = (void *)world->players;
    if (record != 0) {
        do {
            record->controls->transientFlag = 0;
            Playerai_InitializePlayerHealth(record);
            record = record->next;
        } while (record != 0);
    }
}

s32 func_8022C620_de(char *object) {
    struct World_func_802283B8_de *world = (void *)object;
    Shared_ActorView *record = (void *)world->players;
    s32 count = 0;
    while (record != 0) {
        Shared_ControlView *nested = record->controls;
        if ((u8)nested->resetFlag == 0) {
            count += 1;
        }
        record = record->next;
    }
    return count;
}

s32 func_8022C650_de(char *object) {
    struct World_func_802283B8_de *world = (void *)object;
    Shared_ActorView *record = (void *)world->players;
    s32 count = 0;
    while (record != 0) {
        if (record->actorState != 0) {
            count += 1;
        }
        record = record->next;
    }
    return count;
}
