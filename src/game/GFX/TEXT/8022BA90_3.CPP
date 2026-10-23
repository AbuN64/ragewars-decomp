#include "COMMON/OBJECTSTATE90.H"
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

extern s32 func_8024E7DC_de(void *);

extern f32 D_800D2988;

/** Set up a player's starting lives from the game mode and character, then reset its respawn state. */








extern Rules_func_8022C110_de D_801462C8;

extern Course *D_800E4680;

extern char D_80102B00[][0x190];

extern unsigned char func_8022F454_de(char *, int);

extern u8 D_801462DE;

extern s32 D_800E28D0;

extern s32 D_800E28D4;

void func_802A9234_de(u8 arg0);

extern const struct D_800C7470_Pair D_800C2D40_de;



extern void func_80226DD0_de(Player1680 *, Matrix *);

extern void func_802732D0_de(Matrix *, CVector3 *);

extern void func_802727D8_de(Matrix *);

extern void func_80273448_de(Matrix *, float, float, float);

extern void func_8027027C_de(Matrix *, void *);

static inline void getEye(Player1680 *player, CVector3 *pos) {
    Matrix frame;

    if (player->mount != 0) {
        *pos = player->mount->unk128;
    } else {
        func_80226DD0_de(player, &frame);
        func_802732D0_de(&frame, pos);
    }
}

static inline float getYaw(void) {
    return D_80140FC0 * D_800C2D40_de.first;
}

extern void func_80226708_de(void *arg0);

void func_8022C060_de(s32 arg0, s32 arg1) {
    func_8022BF04_de(arg0, arg1, 5, 0x1B);
}

void func_8022C080_de(void *arg0, void *arg1) {
    void *result;
    f32 t0;
    f32 t1;

    result = (void *)func_8024E7DC_de(arg1);
    if (result != 0) {
        t0 = ((ModelBlend *)result)->blend;
        t1 = ((Shared_ActorView *)arg0)->modelBlend;
        t0 = t0 - t1;
        t0 = t0 * D_800C2D28_de;
        t1 = t1 + t0;
        ((Shared_ActorView *)arg0)->modelBlend = t1;
    }
}

void func_8022C0D0_de(void *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    temp_f1 = (((struct FloatState67C *) ((s8 *) arg0))->unk_678);
    if (temp_f1 > 0.0f) {
        temp_f0 = temp_f1 - D_800D2988;
        (((struct FloatState67C *) ((s8 *) arg0))->unk_678) = temp_f0;
        if (temp_f0 < 0.0f) {
            (((struct FloatState67C *) ((s8 *) arg0))->unk_678) = 0.0f;
        }
    }
}

void func_8022C110_de(PlayerRecAt1450V2 *player) {
    short state;

    if (D_801462C8.started != 0) {
        if (D_801462C8.mode == 1 && player->isBot == 0) {
            player->lives = (unsigned char)func_8022F454_de(D_80102B00[player->character], player->info->unk80) / 2 + 1;
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

void func_8022C1E8_de(char *arg0, char *arg1) {
    f32 x, y;
    f32 sx, sy;
    f32 bx, by;
    f32 t1, t2;
    f32 w;
    f32 screenX, screenY;

    func_802A9234_de(D_801462DE);

    x = ((Shared_HudView *)arg1)->width;
    sx = x / (f32) D_800E28D0;
    bx = sx * D_800C2D2C_de;

    y = ((Shared_HudView *)arg1)->height;
    sy = y / (f32) D_800E28D4;
    by = sy * D_800C2D2C_de;

    t1 = ((Shared_HudView *)arg1)->x + x;
    t2 = ((Shared_HudView *)arg1)->y + y;
    w = ((SharedPlayer *)arg0)->views5E8.view7BC_101.unk7BC;

    screenX = t1 + bx;
    screenY = t2 + by;

    func_802AAC28_de(0x1FC, (s32) w, (s16) (s32) screenX, (s16) (s32) screenY, sx, sy, 1);
}

void func_8022C2B4_de(void *arg0, struct ScreenRectangle *arg1)
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
  func_802A9234_de(D_801462DE);
  x = arg1->x;
  ax = x * D_800C2D30_de;
  y = arg1->y;
  ay = y * D_800C2D30_de;
  sx = x / ((f32) D_800E28D0);
  bx = sx * D_800C2D34_de;
  sy = y / ((f32) D_800E28D4);
  by = sy * D_800C2D34_de;
  screenX = ((arg1->width) + ax) - bx;
  screenY = ((arg1->height) + ay) - by;
  func_802AAC28_de(0x1FB, 0, (s16) ((s32) (((arg1->width) + ax) - bx)), (s16) ((s32) screenY), sx, sy, 1);
}

void func_8022C37C_de(char *arg0, char *arg1) {
    f32 x, y;
    f32 sx, sy;
    f32 bx, by, cz;
    f32 t1, t2;
    f32 w;
    f32 screenX, screenY;

    func_802A9234_de(D_801462DE);

    x = ((Shared_HudView *)arg1)->width;
    sx = x / (f32) D_800E28D0;
    bx = sx * D_800C2D38_de;

    y = ((Shared_HudView *)arg1)->height;
    sy = y / (f32) D_800E28D4;
    by = sy * D_800C2D38_de;

    cz = sy * D_800C2D3C_de;

    t1 = ((Shared_HudView *)arg1)->x + x;
    t2 = ((Shared_HudView *)arg1)->y + y;
    w = ((SharedPlayer *)arg0)->views5E8.view7BC_101.unk7BC;

    screenX = t1 + bx;
    screenY = t2 + by;

    func_802AAC28_de(0x201, (s32) w, (s16) (s32) screenX, (s16) (s32) screenY, sx, cz, 1);
}

void *func_8022C454_de(void *arg0) {
    struct Player *player = arg0;
    AiProfile *p = player->profile;
    p->state90 = 0;
    return p;
}

s32 func_8022C460_de(void *arg0) {
    Shared_ActorView *player = arg0;
    s16 temp_v1;
    temp_v1 = player->action;
    if ((temp_v1 == 0x15) || (temp_v1 == 0x13) || (temp_v1 == 0x14)) {
        return 1;
    }
    return 0;
}

void func_8022C490_de(Player1680 *player) {
    Matrix mtx;
    CVector3 pos;

    getEye(player, &pos);
    func_802727D8_de(&mtx);
    func_802736D4_de(&mtx, getYaw());
    func_80273448_de(&mtx, pos.x, pos.y + D_800C2D40_de.second, pos.z);
    func_8027027C_de(&mtx, &player->views[D_800D297C]);
}

void *func_8022C55C_de(void *arg0, u32 arg1) {
    struct World24 *world = arg0;
    Shared_ActorView *var_v1;
    s32 var_a2;

    var_v1 = 0;
    var_a2 = 0;
    if (arg1 < 8U) {
        var_v1 = (void *)world->players;
        if (var_v1 != 0) {
            do {
                if ((u8)var_v1->controls->resetFlag == 0) {
                    if (var_a2 == (s32) arg1) {
                        return var_v1;
                    }
                    var_a2 += 1;
                }
                var_v1 = var_v1->next;
            } while (var_v1 != 0);
        }
    }
    return var_v1;
}

void func_8022C5AC_de(char *object) {
    struct World24 *world = (void *)object;
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
    struct World24 *world = (void *)object;
    Shared_ActorView *record = (void *)world->players;
    if (record != 0) {
        do {
            record->controls->transientFlag = 0;
            func_80226708_de(record);
            record = record->next;
        } while (record != 0);
    }
}

s32 func_8022C620_de(char *object) {
    struct World24 *world = (void *)object;
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
    struct World24 *world = (void *)object;
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
