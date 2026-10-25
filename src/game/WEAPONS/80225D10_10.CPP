#include "COMMON/WORLD.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/ACTOR_HEADER.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/INTEGERSTATE1250.H"
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/UNUSED.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/PLAYERPROFILES.H"

extern f32 D_800C2CE0_de[2];

/** Start the round-end sequence once no menu or transition is active and any player is flagged. */
extern int func_80245798_de(void);

extern int func_80245784_de(void);

extern struct Shape_func_8021A2D4_de_2 D_801427FC;

extern void func_802227F4_de(Node_func_8022A748_de *arg0, Node_func_8022A748_de *arg1, s32 arg2);

extern void func_80285D30_de(s32 *);


extern void func_8024BE3C_de(void *arg0);

extern void func_80246E44_de(char *);






/** Return the capacity for an item slot: the player's own value, or in mode 1 the base value plus the character's bonus. */









extern f32 Particle_GetActorHeight(void);


void *func_8022A480_de(void *arg0, s32 point, s32 arg2, s32 arg3) {
    f32 var_f3;
    func_8022A470_S2 *var_v1;
    void *result;
    f32 dx, dy, dz, distSq;

    func_80228774_S1 *object;

    var_f3 = D_800C2CE0_de[1];
    object = arg0;
    var_v1 = object->unk20;
    result = 0;
    if (var_v1 != 0) {
        do {
            dx = var_v1->unk8 - *(f32 *)&point;
            dx = dx * dx;
            dy = var_v1->unkC - *(f32 *)&arg2;
            dy = dy * dy;
            dz = var_v1->unk10 - *(f32 *)&arg3;
            dz = dz * dz;
            distSq = (dx + dy) + dz;
            if (distSq < var_f3) {
                var_f3 = distSq;
                result = var_v1;
            }
            var_v1 = var_v1->unk16E0;
        } while (var_v1 != 0);
    }
    return result;
}

void *func_8022A504_de(struct Context *context, CVector3 position, void *arg4) {
    f32 var_f3;
    Shared_ActorView *actor;
    void *var_a1;
    f32 dx, dy, dz, distSq;

    var_f3 = D_800C2CE8_de;
    actor = (void *)context->head;
    var_a1 = 0;
    if (actor != 0) {
        do {
            if (actor->health != 0 && actor != arg4) {
                dx = ((LevelActor *)actor)->position0.x - position.x;
                dx = dx * dx;
                dy = ((LevelActor *)actor)->position0.y - position.y;
                dy = dy * dy;
                dz = ((LevelActor *)actor)->position0.z - position.z;
                dz = dz * dz;
                distSq = (dx + dy) + dz;
                if (distSq < var_f3) {
                    var_f3 = distSq;
                    var_a1 = actor;
                }
            }
            actor = actor->next;
        } while (actor != 0);
    }
    return var_a1;
}

s32 func_8022A5A0_de(void *arg0, unsigned int arg1)
{
    func_80203E78_S1 *arg0_record = arg0;
  return (arg1 - (arg0_record->unk4)) / 5864;
}

void *func_8022A5C0_de(char *object, s32 arg1) {
    Round *round = (Round *)object;
    Shared_ActorView *record = (Shared_ActorView *)round->players;
    if (record != 0) {
        do {
            if ((s32)record->controller == arg1) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}

void *func_8022A5F4_de(void *world, u32 arg1) {
    Shared_ActorView *actor;
    s32 var_a2;

    actor = 0;
    var_a2 = 0;
    if (arg1 < 8U) {
        actor = ((struct Context *)world)->head;
        if (actor != 0) {
            do {
                if (var_a2 == (s32)arg1) {
                    return actor;
                }
                actor = actor->next;
                var_a2 += 1;
            } while (actor != 0);
        }
    }
    return actor;
}

void *func_8022A634_de(struct Context *context, u32 arg1) {
    void *result;
    void *temp_v0;
    s32 var_a2;

    result = 0;
    var_a2 = 0;
    if (arg1 < 8U) {
        result = context->head;
        if (result != 0) {
            do {
                temp_v0 = ((Shared_ActorView *)result)->message;
                if (temp_v0 != 0 && ((GameplayCamera *)temp_v0)->messageList.flag == 0) {
                    if (var_a2 == (s32) arg1) {
                        return result;
                    }
                    var_a2 += 1;
                }
                result = ((Shared_ActorView *)result)->next;
            } while (result != 0);
        }
    }
    return result;
}

int func_8022A68C_de(char *forcePlayerList) {
    Shared_ActorView *p;
    int count;
    CGameStatus *s;
    CGameStatus *t;

    if (func_80245798_de() != 0 || func_80245784_de() != 0 || D_8011FE88.frozen != 0) {
        return 0;
    }
    t = &D_801462C8.counters;
    if (t->state != 0 || t->elapsed == 0) {
        return 0;
    }
    count = 0;
    for (p = (Shared_ActorView *)((ForcePlayerList *)forcePlayerList)->head; p != 0; p = p->next) {
        if (p->controls->roundEnded == 1) {
            count++;
        }
    }
    if (count <= 0) {
        return 0;
    }
    s = &D_801462C8.counters;
    s->state = 1;
    s->elapsed = 0;
    return 1;
}

void func_8022A748_de(void *arg0) {
    CGameStatus *state;
    Round *round = arg0;
    Node_func_8022A748_de *node;

    state = &D_801462C8.counters;
    if ((state->elapsed != 0) || (state->state != 0)) {
        return;
    }

    Render_SetControllerMode(0);
    if (state->teams != 0) {
        if (state->round == 0) {
            state->round = 1;
            node = (Node_func_8022A748_de *)round->players;
            while (node != 0) {
                func_802227F4_de(node, node, 0x15);
                node = node->next;
            }
        }
    } else {
        state->elapsed = 1;
        node = (Node_func_8022A748_de *)round->players;
        while (node != 0) {
            func_802227F4_de(node, node, 0x15);
            node = node->next;
        }
    }

    D_801427FC.field_0 = 1;
    node = (Node_func_8022A748_de *)round->players;
    while (node != 0) {
        node->field85C = 0;
        node->state[0x8E] = 1;
        node = node->next;
    }
}

/** Find the first linked record whose nested flags include either type marker. */
void *func_8022A83C_de(char *object) {
    Shared_ActorView *record = (void *)((struct Context *)object)->head;
    while (record != 0) {
        Shared_ControlView *nested = record->controls;
        if (nested->transientFlag == 1 ||
            (u8)nested->resetFlag == 1) {
            return record;
        }
        record = record->next;
    }
    return record;
}

void func_8022A880_de(struct Context *object) {
    Shared_ActorView *record = (void *)object->head;
    if (record != 0) {
        do {
            func_80285D30_de((char *)record->controller + 0x140);
            ((struct IntegerStateD4 *)record->controller)->unk_D0 = 0;
            record = record->next;
        } while (record != 0);
    }
}

void func_8022A8C8_de(char *object, f32 arg1) {
    ObjRecAt20V2 *object_record = (void *)object;
    func_8022A8B8_S2 *record = object_record->unk20;
    if (record != 0) {
        do {
            record->unk670 = arg1;
            record = record->unk16E0;
        } while (record != 0);
    }
}

s32 func_8022A8F0_de(struct Context *context) {
    Shared_ActorView *record = (void *)context->head;
    s32 count = 0;
    if (record != 0) {
        do {
            if (record->actionEnabled != 0 && record->remote == 0) {
                count += 1;
            }
            record = record->next;
        } while (record != 0);
    }
    return count;
}

void func_8022A928_de(ObjRecAtB4 *arg0, int arg1) {
    if (arg0->unk4 == arg1) {
        arg0->unkB4 = 1;
    }
    arg0->unk4 = arg1;
}

void func_8022A940_de(Shared_Effect *effect) {
    s32 val = effect->state;
    if (val != 0 && val != 3) {
        effect->state = 3;
    }
}

void func_8022A95C_de(void *arg0) {
    LevelActor *base;
    s32 old_value;
    s32 new_value;
    f32 saved_value;

    base = &((Shared_ActorView *)arg0)->weapon;
    old_value = ((Shared_ActorView *)arg0)->effectId;
    saved_value = D_800D2988;
    base->renderFlags = 0x10;
    base->flags &= 0xFFFDFFFF;
    func_8024BE3C_de(base);
    if (((Shared_ActorView *)arg0)->stun <= 0.0f) {
        func_80246E44_de(base);
    }
    new_value = ((Shared_ActorView *)arg0)->effectId;
    D_800D2988 = saved_value;
    if (old_value != new_value) {
        ((LevelActor *)arg0)->animationPending = 0;
    }
    ((Shared_ActorView *)arg0)->weapon.position0 = ((LevelActor *)arg0)->position0;
    ((Shared_ActorView *)arg0)->weapon.yaw = ((LevelActor *)arg0)->yaw;
    ((Shared_ActorView *)arg0)->weapon.model = ((LevelActor *)arg0)->model;
    ((Shared_ActorView *)arg0)->weapon.rotation = ((LevelActor *)arg0)->rotation;
}

f32 func_8022AA44_de(SharedRecAt848 *arg0) {
    f32 value;
    f32 scaled;
    f32 initial;
    initial = arg0->value - 285.0f;
    if (arg0->override != 0) {
        value = 1.0f;
    } else {
        scaled = initial * 0.06666667f;
        if (scaled > 1.0f) {
            value = 1.0f;
        } else {
            value = scaled;
        }
    }
    return 1.0f - value;
}

s32 func_8022AA9C_de(AimPlayer *aimPlayer, s32 arg1) {
    void *p = D_800D052C[arg1];
    if (aimPlayer->unk594 == 1) {
        return ((GlobalState *)p)->field20;
    }
    return ((GlobalState *)p)->field24;
}

s16 func_8022AAD4_de(Player *player, s32 arg1) {
    s16 *var_v0;
    WeaponInfo *temp_a0;

    temp_a0 = D_800D052C[arg1];
    if (player->gear == 1) {
        var_v0 = temp_a0->weaponClass;
    } else {
        var_v0 = temp_a0->alternateClass;
    }
    if (var_v0 != 0) {
        return *var_v0;
    }
    return -1;
}

s16 func_8022AB20_de(void *actor, s32 arg1) {
    s16 *var_v0;
    s32 temp_v1;
    WeaponInfo *weapon;

    if ((arg1 == 1) && (((Shared_ActorView *)actor)->actions[1].kind != 0)) {
        return -1;
    }
    weapon = D_800D052C[arg1];
    if (((Player *)actor)->gear == 1) {
        var_v0 = weapon->weaponClass;
    } else {
        var_v0 = weapon->alternateClass;
    }
    if (var_v0 != 0) {
        temp_v1 = *var_v0;
    } else {
        temp_v1 = -1;
    }
    if (temp_v1 != -1) {
        return ((Shared_ActorView *)actor)->ammo[temp_v1];
    }
    return -1;
}

s32 func_8022AB9C_de(void *player) {
    s16 *var_v0;
    s32 temp_v1;
    WeaponInfo *weapon;

    weapon = D_800D052C[((Shared_ActorView *)player)->selectedAction];
    if (((Player *)player)->gear == 1) {
        var_v0 = weapon->weaponClass;
    } else {
        var_v0 = weapon->alternateClass;
    }
    if (var_v0 != 0) {
        temp_v1 = *var_v0;
    } else {
        temp_v1 = -1;
    }
    if (temp_v1 != -1) {
        return D_800CB348_de[temp_v1];
    }
    return -1;
}

s32 func_8022AC00_de(void *arg0) {
    char *o = (char *)arg0;
    s32 value;
    s8 type;

    if (D_80146938 != 0 && ((struct RecordRecAt94 *) ((ObjectLinks1454_3 *) o)->unk_5D8)->display != 0) {
        type = ((struct RecordRecAt94 *) ((ObjectLinks1454_3 *) o)->unk_5D8)->kind;
        if (type == 0xB) {
            value = 0x19000;
        } else if (type == 0xC) {
            value = 0x19000;
        } else if (type == 0xE) {
            value = 0x12C00;
        } else if (type == 0xD) {
            value = 0x12C00;
        } else {
            value = ((ActorHealthDefinition *)((ObjectLinks1454_3 *)o)->unk_18)->health << 8;
        }
    } else {
        value = ((ActorHealthDefinition *)((ObjectLinks1454_3 *)o)->unk_18)->health << 8;
    }
    if (D_801462D5 == 1 && ((ObjectLinks1454_3 *)(o))->unk_1450 == 0) {
        value += D_800FEB10[((ObjectLinks1454_3 *)(o))->unk_5D4].value;
    }
    return value;
}

int func_8022ACB8_de(Player_func_8022ACB8_de *player, int slot) {
    int value;

    if (slot == -1) {
        return 0;
    }
    if (D_801462D5 != 1) {
        value = player->loadout->capacity[slot];
    } else {
        value = D_800CE3E8[slot];
        if (player->isBot == 0) {
            if (slot == 0) {
                value += D_80102B00[player->character].bonus0;
            } else if (slot == 1) {
                value += D_80102B00[player->character].bonus1;
            } else if (slot == 2) {
                value += D_80102B00[player->character].bonus2;
            }
        }
    }
    return value;
}

/** Report whether the signed word at byte offset 0x5E4 is below 0x6400. */
int func_8022ADB0_de(struct SharedPlayer *object, s32 unused1) {
    return object->views5E4.view5E4_0.unk5E4 < 0x6400;
}

f32 func_8022ADBC_de(void *arg0) {
    struct Object *object = arg0;
    struct ModelBlend *owner;

    owner = object->owner;
    if (owner != 0) {
        return owner->height * D_800C2D04_de;
    }
    return D_800C2D00_de;
}

f32 func_8022ADF0_de(LevelActor *actor) {
    if (actor->definition != 0) {
        return Particle_GetActorHeight();
    } else {
        return D_800C2D08_de;
    }
}

int func_8022AE28_de(void *arg0, void *arg1) {
    int flag;
    CVector3 *src;
    src = arg1;
    flag = ((int (*)(void *))Scene_FindFloorPolygon)(&D_8011FE88);
    ((LevelActor *)arg0)->position0 = *src;
    ((LevelActor *)arg0)->model = flag;
    ((Shared_ActorView *)arg0)->weapon.position0 = *src;
    ((Shared_ActorView *)arg0)->weapon.model = flag;
    return flag != 0;
}
