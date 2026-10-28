#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
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
extern int Cinema_IsSequenceInWindow(void);


extern struct Shape_func_8021A2D4_de_2 D_801427FC;


extern void Rumble_FreeAllPoolNodes(s32 *);


extern void func_8024BE3C_de(void *base);

extern void func_80246E44_de(char *);






/** Return the capacity for an item slot: the player's own value, or in mode 1 the base value plus the character's bonus. */









extern f32 Gobjinst_GetActorHeight(void);


void *Playerai_FindNearestPlayer(void *world, s32 point, s32 pointYBits, s32 pointZBits) {
    f32 nearestDistanceSquared;
    func_8022A470_S2 *candidatePlayer;
    void *result;
    f32 dx, dy, dz, distSq;

    func_80228774_S1 *object;

    nearestDistanceSquared = D_800C2CE0_de[1];
    object = world;
    candidatePlayer = object->unk20;
    result = 0;
    if (candidatePlayer != 0) {
        do {
            dx = candidatePlayer->unk8 - *(f32 *)&point;
            dx = dx * dx;
            dy = candidatePlayer->unkC - *(f32 *)&pointYBits;
            dy = dy * dy;
            dz = candidatePlayer->unk10 - *(f32 *)&pointZBits;
            dz = dz * dz;
            distSq = (dx + dy) + dz;
            if (distSq < nearestDistanceSquared) {
                nearestDistanceSquared = distSq;
                result = candidatePlayer;
            }
            candidatePlayer = candidatePlayer->unk16E0;
        } while (candidatePlayer != 0);
    }
    return result;
}

void *Playerai_FindNearestLivePlayer(struct Context *context, CVector3 position, void *excludedPlayer) {
    f32 nearestDistanceSquared;
    Shared_ActorView *actor;
    void *nearestPlayer;
    f32 dx, dy, dz, distSq;

    nearestDistanceSquared = D_800C2CE8_de;
    actor = (void *)context->head;
    nearestPlayer = 0;
    if (actor != 0) {
        do {
            if (actor->health != 0 && actor != excludedPlayer) {
                dx = ((LevelActor *)actor)->position0.x - position.x;
                dx = dx * dx;
                dy = ((LevelActor *)actor)->position0.y - position.y;
                dy = dy * dy;
                dz = ((LevelActor *)actor)->position0.z - position.z;
                dz = dz * dz;
                distSq = (dx + dy) + dz;
                if (distSq < nearestDistanceSquared) {
                    nearestDistanceSquared = distSq;
                    nearestPlayer = actor;
                }
            }
            actor = actor->next;
        } while (actor != 0);
    }
    return nearestPlayer;
}

s32 Player_GetPlayerIndex(void *world, unsigned int playerAddress)
{
    func_80203E78_S1 *arg0_record = world;
  return (playerAddress - (arg0_record->unk4)) / 5864;
}

void *Playerai_FindPlayerByController(char *object, s32 controllerAddress) {
    Round *round = (Round *)object;
    Shared_ActorView *record = (Shared_ActorView *)round->players;
    if (record != 0) {
        do {
            if ((s32)record->controller == controllerAddress) {
                return record;
            }
            record = record->next;
        } while (record != 0);
    }
    return 0;
}

void *Playerai_GetPlayerByIndex(void *world, u32 playerIndex) {
    Shared_ActorView *actor;
    s32 currentPlayerIndex;

    actor = 0;
    currentPlayerIndex = 0;
    if (playerIndex < 8U) {
        actor = ((struct Context *)world)->head;
        if (actor != 0) {
            do {
                if (currentPlayerIndex == (s32)playerIndex) {
                    return actor;
                }
                actor = actor->next;
                currentPlayerIndex += 1;
            } while (actor != 0);
        }
    }
    return actor;
}

void *func_8022A634_de(struct Context *context, u32 viewPlayerIndex) {
    void *result;
    void *playerView;
    s32 currentViewIndex;

    result = 0;
    currentViewIndex = 0;
    if (viewPlayerIndex < 8U) {
        result = context->head;
        if (result != 0) {
            do {
                playerView = ((Shared_ActorView *)result)->message;
                if (playerView != 0 && ((GameplayCamera *)playerView)->messageList.flag == 0) {
                    if (currentViewIndex == (s32) viewPlayerIndex) {
                        return result;
                    }
                    currentViewIndex += 1;
                }
                result = ((Shared_ActorView *)result)->next;
            } while (result != 0);
        }
    }
    return result;
}

int Playerai_BeginRoundEnd(char *forcePlayerList) {
    Shared_ActorView *p;
    int count;
    CGameStatus *s;
    CGameStatus *t;

    if (Cinema_IsSequenceInWindow() != 0 || Cinema_IsSequenceActive() != 0 || g_world.frozen != 0) {
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

void Playerai_EndRound(void *roundContext) {
    CGameStatus *state;
    Round *round = roundContext;
    Node_Weapons_EndRound *node;

    state = &D_801462C8.counters;
    if ((state->elapsed != 0) || (state->state != 0)) {
        return;
    }

    Control_SetControllerMode(0);
    if (state->teams != 0) {
        if (state->round == 0) {
            state->round = 1;
            node = (Node_Weapons_EndRound *)round->players;
            while (node != 0) {
                Player_SetPlayerState(node, node, 0x15);
                node = node->next;
            }
        }
    } else {
        state->elapsed = 1;
        node = (Node_Weapons_EndRound *)round->players;
        while (node != 0) {
            Player_SetPlayerState(node, node, 0x15);
            node = node->next;
        }
    }

    D_801427FC.field_0 = 1;
    node = (Node_Weapons_EndRound *)round->players;
    while (node != 0) {
        node->field85C = 0;
        node->state[0x8E] = 1;
        node = node->next;
    }
}

/** Find the first linked record whose nested flags include either type marker. */
void *Playerai_FindPlayerWithMarker(char *object) {
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

void Playerai_ResetPlayerControllers(struct Context *object) {
    Shared_ActorView *record = (void *)object->head;
    if (record != 0) {
        do {
            Rumble_FreeAllPoolNodes((char *)record->controller + 0x140);
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

void func_8022A928_de(ObjRecAtB4 *record, int newValue) {
    if (record->unk4 == newValue) {
        record->unkB4 = 1;
    }
    record->unk4 = newValue;
}

void func_8022A940_de(Shared_Effect *effect) {
    s32 val = effect->state;
    if (val != 0 && val != 3) {
        effect->state = 3;
    }
}

void func_8022A95C_de(void *player) {
    LevelActor *base;
    s32 old_value;
    s32 new_value;
    f32 saved_value;

    base = &((Shared_ActorView *)player)->weapon;
    old_value = ((Shared_ActorView *)player)->effectId;
    saved_value = D_800D2988;
    base->renderFlags = 0x10;
    base->flags &= 0xFFFDFFFF;
    func_8024BE3C_de(base);
    if (((Shared_ActorView *)player)->stun <= 0.0f) {
        func_80246E44_de(base);
    }
    new_value = ((Shared_ActorView *)player)->effectId;
    D_800D2988 = saved_value;
    if (old_value != new_value) {
        ((LevelActor *)player)->animationPending = 0;
    }
    ((Shared_ActorView *)player)->weapon.position0 = ((LevelActor *)player)->position0;
    ((Shared_ActorView *)player)->weapon.yaw = ((LevelActor *)player)->yaw;
    ((Shared_ActorView *)player)->weapon.model = ((LevelActor *)player)->model;
    ((Shared_ActorView *)player)->weapon.rotation = ((LevelActor *)player)->rotation;
}

f32 func_8022AA44_de(SharedRecAt848 *rampState) {
    f32 value;
    f32 scaled;
    f32 initial;
    initial = rampState->value - 285.0f;
    if (rampState->override != 0) {
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

s32 func_8022AA9C_de(AimPlayer *aimPlayer, s32 weaponId) {
    void *p = D_800D052C[weaponId];
    if (aimPlayer->unk594 == 1) {
        return ((GlobalState *)p)->field20;
    }
    return ((GlobalState *)p)->field24;
}

s16 Playerai_GetWeaponClassId(Player *player, s32 weaponId) {
    s16 *selectedClassEntry;
    WeaponInfo *weaponDefinition;

    weaponDefinition = D_800D052C[weaponId];
    if (player->gear == 1) {
        selectedClassEntry = weaponDefinition->weaponClass;
    } else {
        selectedClassEntry = weaponDefinition->alternateClass;
    }
    if (selectedClassEntry != 0) {
        return *selectedClassEntry;
    }
    return -1;
}

s16 Playerai_GetWeaponAmmo(void *actor, s32 weaponId) {
    s16 *selectedClassEntry;
    s32 ammoSlot;
    WeaponInfo *weapon;

    if ((weaponId == 1) && (((Shared_ActorView *)actor)->actions[1].kind != 0)) {
        return -1;
    }
    weapon = D_800D052C[weaponId];
    if (((Player *)actor)->gear == 1) {
        selectedClassEntry = weapon->weaponClass;
    } else {
        selectedClassEntry = weapon->alternateClass;
    }
    if (selectedClassEntry != 0) {
        ammoSlot = *selectedClassEntry;
    } else {
        ammoSlot = -1;
    }
    if (ammoSlot != -1) {
        return ((Shared_ActorView *)actor)->ammo[ammoSlot];
    }
    return -1;
}

s32 func_8022AB9C_de(void *player) {
    s16 *selectedClassEntry;
    s32 ammoClassId;
    WeaponInfo *weapon;

    weapon = D_800D052C[((Shared_ActorView *)player)->selectedAction];
    if (((Player *)player)->gear == 1) {
        selectedClassEntry = weapon->weaponClass;
    } else {
        selectedClassEntry = weapon->alternateClass;
    }
    if (selectedClassEntry != 0) {
        ammoClassId = *selectedClassEntry;
    } else {
        ammoClassId = -1;
    }
    if (ammoClassId != -1) {
        return D_800CB348_de[ammoClassId];
    }
    return -1;
}

s32 Player_GetMaxHealth(void *player) {
    char *o = (char *)player;
    s32 value;
    s8 type;

    if (D_801462C8.counters.enabled != 0 && ((struct RecordRecAt94 *) ((ObjectLinks1454_3 *) o)->unk_5D8)->display != 0) {
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
    if (D_801462C8.controllerMode == 1 && ((ObjectLinks1454_3 *)(o))->unk_1450 == 0) {
        value += D_800FEB10[((ObjectLinks1454_3 *)(o))->unk_5D4].value;
    }
    return value;
}

int Player_GetAmmoCapacity(PlayerWeaponsGetAmmoCapacity *player, int slot) {
    int value;

    if (slot == -1) {
        return 0;
    }
    if (D_801462C8.controllerMode != 1) {
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

f32 Playerai_GetObjectOwnerHeight(void *actorObject) {
    struct EffectOwnerObject *object = actorObject;
    struct ModelBlend *owner;

    owner = object->owner;
    if (owner != 0) {
        return owner->height * D_800C2D04_de;
    }
    return D_800C2D00_de;
}

f32 func_8022ADF0_de(LevelActor *actor) {
    if (actor->definition != 0) {
        return Gobjinst_GetActorHeight();
    } else {
        return D_800C2D08_de;
    }
}

int func_8022AE28_de(void *player, void *newPosition) {
    int flag;
    CVector3 *src;
    src = newPosition;
    flag = ((int (*)(void *))Scene_FindFloorPolygon)(&g_world);
    ((LevelActor *)player)->position0 = *src;
    ((LevelActor *)player)->model = flag;
    ((Shared_ActorView *)player)->weapon.position0 = *src;
    ((Shared_ActorView *)player)->weapon.model = flag;
    return flag != 0;
}
