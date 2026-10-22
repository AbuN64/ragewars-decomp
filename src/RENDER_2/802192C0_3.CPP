#include "RENDER_2/802192C0_3.H"
#include "include_asm.h"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "TYPES.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/TRIPLE.H"
#include "FX/802631D0.H"

extern char D_8010F328[];
extern void func_802227F4_de(void *, void *, s32);
void func_8021A78C_de(void *arg0) {
    char *object = arg0;
    void *attributes;
    void *state = object + 0x688;
    f32 zero;
    f32 default_value;
    f32 tail_value;
    CVector3 *tail_vector;
    s32 type;
    if (((ObjectLinks16D8 *)(object))->unk_1450 != 0) {
        attributes = D_8010EEB8;
    } else {
        s32 index = ((ObjectLinks16D8 *)(object))->unk_5D4;
        attributes = (void *)(index << 4);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 3);
        attributes = (char *)attributes + index;
        attributes = (void *)((s32)attributes << 2);
        attributes = D_8010F328 + (s32)attributes;
    }
    func_8026367C_de(state, attributes);
    ((ObjectLinks16D8 *)(object))->unk_6C0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6C4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6C8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6CC = 0;
    ((ObjectLinks16D8 *)(object))->unk_6D0 = 1;
    ((ObjectLinks16D8 *)(object))->unk_6D4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6D8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_6DC = 0;
    ((ObjectLinks16D8 *)(object))->unk_6E4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_758 = 0;
    ((ObjectLinks16D8 *)(object))->unk_75C = 0;
    ((ObjectLinks16D8 *)(object))->unk_11B4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_11B8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_708 = 0;
    ((ObjectLinks16D8 *)(object))->unk_70C = 0;
    ((ObjectLinks16D8 *)(object))->unk_710 = 0;
    ((ObjectLinks16D8 *)(object))->unk_714 = 0;
    ((ObjectLinks16D8 *)(object))->unk_724 = 0;
    ((ObjectLinks16D8 *)(object))->unk_728 = 0;
    ((ObjectLinks16D8 *)(object))->unk_72C = 0;
    ((ObjectLinks16D8 *)(object))->unk_730 = 0;
    ((ObjectLinks16D8 *)(object))->unk_734 = 0;
    ((ObjectLinks16D8 *)(object))->unk_738 = 0;
    ((ObjectLinks16D8 *)(object))->unk_73C = 0;
    ((ObjectLinks16D8 *)(object))->unk_740 = func_8022ADBC_de(object);
    default_value = D_800C22F8_de;
    ((ObjectLinks16D8 *)(object))->unk_744 = 0;
    (&((ObjectLinks16D8 *)(object))->unk_748)->x = (&((ObjectLinks16D8 *)(object))->unk_748)->y = (&((ObjectLinks16D8 *)(object))->unk_748)->z = 0;
    ((ObjectLinks16D8 *)(object))->unk_754 = default_value;
    ((ObjectLinks16D8 *)(object))->unk_780 = 0;
    ((ObjectLinks16D8 *)(object))->unk_784 = default_value;
    ((ObjectLinks16D8 *)(object))->unk_6E8 = ((ObjectLinks16D8 *)(object))->unk_8;
    ((ObjectLinks16D8 *)(object))->unk_6F8 = ((ObjectLinks16D8 *)(object))->unk_8;
    ((ObjectLinks16D8 *)(object))->unk_658 = 0;
    ((ObjectLinks16D8 *)(object))->unk_668 = 0;
    ((ObjectLinks16D8 *)(object))->unk_66C = 0;
    if (((ObjectLinks16D8 *)(object))->unk_18.v0 != 0) {
        ((ObjectLinks16D8 *)(object))->unk_6F4.v0 = ((struct ModelBlend *) ((ObjectLinks16D8 *) object)->unk_18.v1)->height;
    } else {
        ((ObjectLinks16D8 *)(object))->unk_6F4.v1 = 0;
    }
    tail_vector = &((ObjectLinks16D8 *)(object))->unk_7D8;
    ((ObjectLinks16D8 *)(object))->unk_7B0.v0 = 0;
    zero = ((ObjectLinks16D8 *)(object))->unk_7B0.v1;
    tail_value = D_800C22FC_de;
    type = 2;
    ((ObjectLinks16D8 *)(object))->unk_718 = 0;
    ((ObjectLinks16D8 *)(object))->unk_71C = 0;
    ((ObjectLinks16D8 *)(object))->unk_720 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7EC = 0;
    ((ObjectLinks16D8 *)(object))->unk_7F0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7E8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_788 = 0;
    ((ObjectLinks16D8 *)(object))->unk_78C = 0;
    ((ObjectLinks16D8 *)(object))->unk_790 = 0;
    ((ObjectLinks16D8 *)(object))->unk_794 = 0;
    ((ObjectLinks16D8 *)(object))->unk_798 = -1;
    ((ObjectLinks16D8 *)(object))->unk_79C = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A0 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7A8 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7AC = 0;
    tail_vector->x = tail_vector->y = tail_vector->z = zero;
    ((ObjectLinks16D8 *)(object))->unk_7E4 = tail_value;
    ((ObjectLinks16D8 *)(object))->unk_7B4 = 0;
    ((ObjectLinks16D8 *)(object))->unk_7B8 = -1;
    ((ObjectLinks16D8 *)(object))->unk_7C0 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7C4 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7C8 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7CC = zero;
    ((ObjectLinks16D8 *)(object))->unk_7D0 = zero;
    ((ObjectLinks16D8 *)(object))->unk_7D4 = zero;
    func_802227F4_de(object, object, type);
    ((ObjectLinks16D8 *)(object))->unk_80C = 0;
    ((ObjectLinks16D8 *)(object))->unk_838 = zero;
    ((ObjectLinks16D8 *)(object))->unk_83C = zero;
    ((ObjectLinks16D8 *)(object))->unk_840 = zero;
    ((ObjectLinks16D8 *)(object))->unk_848 = 0;
    ((struct ObjectState8E *) ((ObjectLinks16D8 *) object)->unk_5D8)->state = 0;
    ((ObjectLinks16D8 *)(object))->unk_704 = zero;
    ((ObjectLinks16D8 *)(object))->unk_16D4 = 0;
}

extern s32 D_80140FF8;
extern s32 D_8011D8D0;
CQuatern func_8024796C_de(void *actor);
s16 *func_8022AA9C_de(AimPlayer *arg0, s32 arg1);
void func_8022B144_de(void *arg0, f32 *arg1);
s32 func_802800C0_de(EffectSystem *sys, EffectActor *source, EffectActor *owner, s32 *refCount, s32 arg4, s32 kind, CVector3 arg6, CQuatern rotation, CVector3 pos, CVector3 *aim, s32 arg10, s32 arg11);

static __inline__ s32 containsFire(s16 **entries,s32 effect) {
 s32 i=0; s16 **p=entries;
 search:
  if (*p==0) return 0;
  if ((*p)[2]==effect) return 1;
  i++; p++;
 if(i<3) goto search;
 return 0;
}
void func_8021A9A4_de(AimPlayer *arg0, s32 effect) {

    AimView *weapon;
    s16 *mode;
    s16 **entries;
    CVector3 direction;
    CVector3 position;
    CQuatern aim;
    s32 value; void *extra; f32 timer;
    f32 amount;
    s16 *ammo;
    weapon = arg0->view;
    if (arg0->state < 2 || (s16)arg0->state == 0x10 || (s16)arg0->state == 0x11) return;
    aim = func_8024796C_de(arg0);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) arg0->unk594 = 2;
    mode = func_8022AA9C_de(arg0, arg0->unk62E);
    if (effect == 0x439 || effect == 0x4C4 || effect == 0x432 || effect == 0x4E3 ||
        effect == 0x419 || effect == 0x4D3 || effect == 0x425 || effect == 0x4CA) arg0->unk594 = 1;
    if (mode) {
        WeaponInfo *table = D_800D052C[arg0->unk62E];
        if (!arg0->controlled && D_80140FF8 == 1) entries=&table->weaponClass;
        else entries=table->computerClasses;
        if (containsFire(entries,effect)) goto fire;
    }
    if (arg0->unk62E != 0 && arg0->unk62E != 0x10) goto spawn;
fire:
    if (weapon) aim = arg0->rotation;
    if (arg0->unk62E != 0 && arg0->unk62E != 0x10) {
        ammo = &arg0->ammo[mode[0]];
        *ammo -= (u16)mode[3];
        if (*ammo < 0) *ammo = 0;
        if (*ammo == 0) {
            if (arg0->weapons[arg0->unk62E][1] == 3 || arg0->weapons[arg0->unk62E][1] == 7) {
                arg0->weapons[arg0->unk62E][0] = 0;
                arg0->weapons[arg0->unk62E][1] = -1;
            }
        }
    }
    if (arg0->equippedKind == 0x11) {
        if (arg0->animation == 0x1004) {timer=arg0->animationTimer; amount = D_800C2318_de;}
        else if (arg0->animation == 4000) {timer=arg0->animationTimer; amount = D_800C231C_de;}
        else {
            if (arg0->weaponKind == 8) arg0->animation = 0x1004;
            else arg0->animation = 4000;
            goto clear;
        }
        goto consume;
    }
    if (arg0->animation == 1) arg0->animation = 0x1130;
    else if (arg0->animation == 0x1130) { timer=arg0->animationTimer; amount = D_800C2320_de; goto consume; }
    else if (arg0->animation == 0xA28) arg0->animation = 0x1135;
    else if (arg0->animation == 0x1135) { timer=arg0->animationTimer; amount = D_800C2324_de; goto consume; }
    else if (arg0->animation == 0x14) arg0->animation = 0x1144;
    else if (arg0->animation == 0x1144) { timer=arg0->animationTimer; amount = D_800C2328_de; goto consume; }
    else if (arg0->unk62E == 0 && arg0->weaponKind == 8) arg0->animation = 0x5E5E;
    else {
            if (arg0->animation == 0x5E5E) { timer=arg0->animationTimer; amount = D_800C232C_de; goto consume; }
        if ((u32)(arg0->animation - 0x5E24) < 3) arg0->animation = 0x5E56;
        else if (arg0->animation == 0x5E56) { timer=arg0->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (arg0->animation == 0x5E29) arg0->animation = 0x5E59;
        else if (arg0->animation == 0x5E59) { timer=arg0->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (arg0->animation == 0x5E2A) arg0->animation = 0x5E5A;
        else if (arg0->animation == 0x5E5A) { timer=arg0->animationTimer; amount = D_800C2330_de; goto consume; }
        else if (arg0->animation == 0x5E2B) arg0->animation = 0x5E5B;
        else if (arg0->animation == 0x5E5B) { timer=arg0->animationTimer; amount=D_800C2334_de; goto consume; }
        else if (arg0->animation == 0x5E2C) arg0->animation = 0x5E5C;
        else {
                    if (arg0->animation == 0x5E5C) { timer=arg0->animationTimer; amount=D_800C2334_de; goto consume; }
            if (arg0->animation == 0x5E2D) arg0->animation = 0x5E5D;
            else if (arg0->animation == 0x5E5D) { timer=arg0->animationTimer; amount=D_800C2334_de; goto consume; }
            else { arg0->firing = 0; goto spawn; }
        }
    }
    goto clear;
ordinary:
    timer=arg0->animationTimer; amount = D_800C2334_de;
consume:
    if (!(amount <= timer)) { arg0->firing = 0; goto spawn; }
    arg0->animationTimer = timer-amount;
clear:
    arg0->firing = 0;
spawn:
    if (weapon && weapon->mode != 1) direction = weapon->origin;
    else func_8022B144_de(arg0, &direction.x);
    position = arg0->position;
    extra = 0;
    if (arg0->unk788 == 2) extra = arg0->unk794;
    func_802800C0_de(&D_8011D8D0, arg0, arg0, 0, extra, effect, position, aim,
                     direction, &arg0->aim, -1, (arg0->movementFlags&0x1000)?5:1);
    if (effect == 0x414 || effect == 0x42D) {
        s32 shots = arg0->shots - 1;
        if (shots < 0) shots = 0;
        arg0->shots = shots;
    }
    if (arg0->unk62E != 9 && arg0->unk62E != 0x15 && arg0->unk62E != 0x14)
        D_800FF140_de[arg0->playerIndex]++;
}

/* Resets a player record for a new round: clears the ammo and the 22 action slots, marks every action but the first
   unavailable when the match is local and the player has a definition and no bonus, calls the setup for the current mode,
   sets the starting ammo by whether the player has a definition, and chooses the starting weapon (fixed for states 17 and
   18, none for a bonus profile, the fourth loadout item of the definition when the player is a computer, else the first
   action marked 1) before loading the weapon's animation table and count. */
extern s32 D_801468F4;
extern void *D_800D052C[];
extern s32 func_80426090_de(struct Player *);
extern s32 func_80426174_de(struct Player *);
extern s32 func_804261DC_de(struct Player *);

void func_8021AF6C_de(struct Player *player) {
    Shared_Game *game;
    s32 i;
    s32 j;
    s32 k;
    struct WeaponInfo *weaponInfo;
    AiCharacterDefinition *definition;
    for (i = 6; i >= 0; i--) {
        player->ammo[i] = 0;
    }
    for (i = 21; i >= 0; i--) {
        player->actions[i][0] = 0;
    }
    game = &D_801462C8;
    if (game->local == 1 && player->definition != 0) {
        if (game->unk62C == 0 || player->profile->bonus == 0) {
            for (j = 1; j < 22; j++) {
                player->actions[j][0] = 0;
                player->actions[j][1] = -1;
            }
        }
        switch (D_801462D5) {
        case 1:
            func_80426090_de(player);
            break;
        case 4:
            func_804261DC_de(player);
            break;
        default:
            func_80426174_de(player);
            break;
        }
    }
    if (player->definition == 0) {
        player->ammo[0] = 100;
        player->ammo[1] = 100;
        player->ammo[2] = 50;
    } else {
        player->ammo[0] = 50;
        player->ammo[1] = 0;
        player->ammo[2] = 0;
        player->ammo[3] = 0;
    }
    if (player->state == 17) {
        player->weapon = 16;
        player->selectedAction = 16;
        player->queuedAction = 16;
        player->lastAction = 16;
    } else if (player->state == 18) {
        player->weapon = 17;
        player->selectedAction = 17;
        player->queuedAction = 17;
        player->lastAction = 17;
    } else if (D_801468F4 != 0 && player->profile->bonus != 0) {
        player->selectedAction = 0;
        player->weapon = 0;
        player->queuedAction = 0;
        player->lastAction = player->selectedAction;
    } else {
        if (player->computer != 0) {
            definition = player->definition;
            if (definition != 0 && definition->loadout != 0) {
                player->weapon = definition->loadout[3] - 0x4C3;
                player->selectedAction = player->weapon;
            } else {
                player->weapon = 0;
                player->selectedAction = 0;
            }
        } else {
            for (k = 0; k < 22; k++) {
                if (player->actions[k][1] == 1) {
                    break;
                }
            }
            if (k < 22) {
                player->weapon = k;
                player->selectedAction = k;
            } else {
                player->weapon = 0;
                player->selectedAction = 0;
            }
        }
        player->queuedAction = player->selectedAction;
        player->lastAction = player->selectedAction;
    }
    if (D_801462E5 != 0) {
        weaponInfo = D_800D052C[player->weapon];
        player->weaponAnimationTable = weaponInfo->animation;
        weaponInfo = D_800D052C[player->selectedAction];
        player->weaponAnimationCount = weaponInfo->animationCount;
    }
}

INCLUDE_ASM("span_1000", func_8021B1E4_de);
