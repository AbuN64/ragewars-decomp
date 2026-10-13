#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022BA90.h"
#include "types.h"
#include "shared/gameplay_transition.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"

s32 func_8022C460_de(void *arg0) {
    Shared_ActorView *player = arg0;
    s16 temp_v1;
    temp_v1 = player->action;
    if ((temp_v1 == 0x15) || (temp_v1 == 0x13) || (temp_v1 == 0x14)) {
        return 1;
    }
    return 0;
}

extern const struct D_800C7470_Pair D_800C2D40_de;


extern int D_80140FC0;
extern int D_800D297C;
extern void func_80226DD0_de(Player1680 *, Matrix *);
extern void func_802732D0_de(Matrix *, Vec3 *);
extern void func_802727D8_de(Matrix *);
extern void func_80273448_de(Matrix *, float, float, float);
extern void func_8027027C_de(Matrix *, void *);

static inline void getEye(Player1680 *player, Vec3 *pos) {
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

void func_8022C490_de(Player1680 *player) {
    Matrix mtx;
    Vec3 pos;

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

extern void func_80226708_de(void *arg0);






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
