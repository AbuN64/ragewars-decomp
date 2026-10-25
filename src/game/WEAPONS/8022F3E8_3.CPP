#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "gbi.h"
#include "COMMON/GFX.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/OBJECTSTATE90.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "WEAPONS/8022F3E8_3.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"

extern s32 func_8022EB0C_de(void *arg0, s32 arg1);



extern WeaponActionRecord D_800CE8DC[];



void func_8022F770_de(void *object, void *unused) {
    MarkerActor *actor=object;
    MarkerNode *node;
    s32 red, alpha;
    node=actor->node;
    if(node->active) {
        gSPMatrix(D_80110634++, (u32)&node->matrices[D_800D297C], G_MTX_LOAD);
        gDPPipeSync(D_80110634++);
        func_8026D8F8_de();
        Render_SetModePreset(0xE);
        Render_SetCombineMode(0x1C);
        red=200; alpha=150;
        gSPGeometryMode(D_80110634++, G_CULL_BACK | G_FOG | G_LIGHTING | G_TEXTURE_GEN | 0x80, 0);
        gSPGeometryMode(D_80110634++, 0, G_SHADE | G_SHADING_SMOOTH);
        D_800FF1B0_de[0].x=1;
        D_800FF1B0_de[0].y=1;
        D_800FF1B0_de[0].z=0;
        D_800FF1B0_de[0].flag=0;
        D_800FF1B0_de[0].s=0;
        D_800FF1B0_de[0].t=0;
        D_800FF1B0_de[0].r=red;
        D_800FF1B0_de[0].g=0;
        D_800FF1B0_de[0].b=0;
        D_800FF1B0_de[0].a=red;
        D_800FF1B0_de[1].x=-1;
        D_800FF1B0_de[1].y=1;
        D_800FF1B0_de[1].z=0;
        D_800FF1B0_de[1].flag=0;
        D_800FF1B0_de[1].s=0;
        D_800FF1B0_de[1].t=0;
        D_800FF1B0_de[1].r=red;
        D_800FF1B0_de[1].g=0;
        D_800FF1B0_de[1].b=0;
        D_800FF1B0_de[1].a=red;
        D_800FF1B0_de[2].x=15;
        D_800FF1B0_de[2].y=1;
        D_800FF1B0_de[2].z=-1;
        D_800FF1B0_de[2].flag=0;
        D_800FF1B0_de[2].s=0;
        D_800FF1B0_de[2].t=0;
        D_800FF1B0_de[2].r=red;
        D_800FF1B0_de[2].g=0;
        D_800FF1B0_de[2].b=0;
        D_800FF1B0_de[2].a=alpha;
        D_800FF1B0_de[3].x=-15;
        D_800FF1B0_de[3].y=1;
        D_800FF1B0_de[3].z=-1;
        D_800FF1B0_de[3].flag=0;
        D_800FF1B0_de[3].s=0;
        D_800FF1B0_de[3].t=0;
        D_800FF1B0_de[3].r=red;
        D_800FF1B0_de[3].g=0;
        D_800FF1B0_de[3].b=0;
        D_800FF1B0_de[3].a=alpha;
        gSPVertex(D_80110634++, (u32)D_800FF1B0_de, 4, 0);
        gSP1Triangle(D_80110634++, 0, 1, 2, 0);
        gSP1Triangle(D_80110634++, 1, 2, 3, 0);
        if(node->extra) func_802A5498_de((u32)&node->extraMatrices[D_800D297C]);
    }
}

s32 func_8022F96C_de(void *arg0)
{
    s32 slot;
    s32 category;
    s32 special;
    Shared_ActorView *actor;
    char *indexed;
    char *scan;

    actor = arg0;
    category = actor->actions[actor->selectedAction].category;
    if (category < 0) {
        category = 0;
    }
    if (category >= 8) {
        category = 0;
    }

    category++;
    if (category < 8) {
        special = 6;
        do {
            for (slot = 0; slot < 22; slot++) {
                if (category == actor->actions[slot].category) {
                    break;
                }
            }
            if ((slot < 22) && func_8022EB0C_de(actor, slot)) {
                if ((slot != special) || (actor->ammo[0] >= 11)) {
                    if ((actor->remote == 0) || (slot < 18)) {
                        return slot;
                    }
                }
            }
            category++;
            slot = 0;
        } while (category < 8);
    }

    category = actor->actions[actor->selectedAction].category;
    if (category < 0) {
        category = 0;
    }
    if (category >= 8) {
        category = 0;
    }

    category--;
    if (category > 0) {
        special = 6;
        do {
            for (slot = 0; slot < 22; slot++) {
                if (category == actor->actions[slot].category) {
                    break;
                }
            }
            if ((slot < 22) && func_8022EB0C_de(actor, slot)) {
                if ((slot != special) || (actor->ammo[0] >= 11)) {
                    return slot;
                }
            }
            category--;
            slot = 0;
        } while (category > 0);
    }
    return 0;
}

s32 func_8022FAF8_de(Object_func_8022FAF8_de *player) {
    s32 value;
    s32 number;
    s32 index;
    s32 result;

    value = player->values[player->selected * 2];
    if (value < 0) {
        value = 0;
    }
    if (value >= 8) {
        value = 0;
    }
    value++;
    while (value < 8) {
        number = 0;
        while ((number < 22) && (value != player->values[number * 2])) {
            number++;
        }
        if ((number < 22) && (func_8022EB0C_de(player, number) != 0)) {
            return number;
        }
        value++;
    }
    value = player->values[player->selected * 2];
    number = 1;
    while (number < value) {
        index = 0;
        while ((index < 22) && (number != player->values[index * 2])) {
            index++;
        }
        if ((index < 22) && (func_8022EB0C_de(player, index) != 0)) {
            return index;
        }
        number++;
    }
    func_8025DF34_de(0xD4D);
    result = player->selected;
    return result;
}

void func_8022FC20_de(void *arg0, void *arg1) {
    void *actor;
    s16 index;
    s32 value;
    f32 old_delta;
    f32 scaled_delta;
    f32 zero;
    f32 timer;
    void *callback_owner;
    void (*callback)(void *, void *);

    actor = ((ObjectLinks1DC_2 *)(arg0))->unk_1D8;
    index = ((ObjectState1230 *)(actor))->unk_650;
    value = D_800CE8DC[index].action;

    if (0.0f < ((ObjectState1230 *)(actor))->unk_11D8) {
        return;
    }

    old_delta = D_800D2988;
    scaled_delta = old_delta * D_800C2E90_de;
    if (actor != 0 && (((ObjectState1230 *)(actor))->unk_122C & 0x2000)) {
        D_800D2988 = scaled_delta;
    } else {
        D_800D2988 = old_delta;
    }

    timer = ((ObjectLinks14C *)(arg1))->unk_148;
    zero = 0.0f;
    if (zero < timer) {
        ((ObjectLinks14C *)(arg1))->unk_148 = timer - D_800D2988;
        ((ObjectLinks1DC_2 *)(arg0))->unk_1 = 0;
    } else {
        ((ObjectLinks1DC_2 *)(arg0))->unk_1 = 0;
    }

    if (zero < ((ObjectLinks14C *)(arg1))->unk_130) {
        ((ObjectLinks14C *)(arg1))->unk_130 -= D_800D2988;
    }

    if (value == 1) {
        Weapons_RequestActorState(arg0, arg1, 1);
    }
    if (((ObjectState1230 *)(actor))->unk_770 != ((ObjectState1230 *)(actor))->unk_62E) {
        ((ObjectState1230 *)(actor))->unk_7E8 = 0;
        Weapons_RequestActorState(arg0, arg1, 1);
    }

    callback_owner = ((ObjectLinks14C *)(arg1))->callback_owner;
    if (callback_owner != 0) {
        callback = ((struct Hook *) ((char *) callback_owner))->fn;
        if (callback != 0) {
            callback(arg0, arg1);
        }
    }

    callback = ((struct CallbackState60 *) ((char *) D_800D052C[((ObjectState1230 *) actor)->unk_62E]))->callback;
    if (callback != 0) {
        callback(arg0, arg1);
    }
    func_8022BC14_de(actor);
    D_800D2988 = old_delta;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#include "COMMON/WORLD.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/OBJECTLINKS14C.H"
extern s32 D_800CD730;
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/CHANNEL.H"














void func_802325FC_de(void *part, void *body) {
    s16 index;
    u16 unsigned_index;
    void *owner;
    void *state;

    state = ((Shared_ActorView *)part)->self;
    index = ((Shared_ActorView *)state)->nextWeapon;
    unsigned_index = (u16)((Shared_ActorView *)state)->nextWeapon;
    if ((((Shared_ActorView *)state)->selectedAction != index) || (D_8011FE88.mode != 4)) {
        if (func_80232780_de(index) != 0) {
            ((Shared_ActorView *)state)->weaponChanged = 1;
        } else if (func_802327A0_de(index) != 0) {
            ((Shared_ActorView *)state)->secondaryChanged = 1;
        } else if (func_802327D4_de(index) != 0) {
            ((Shared_ActorView *)state)->specialChanged = 1;
        }
        ((Shared_ActorView *)state)->selectedAction = unsigned_index;
        ((WeaponFireState *)body)->animation = ((WeaponInfo *)D_800D052C[(s16)unsigned_index])->animation;
        ((WeaponFireState *)body)->animationCount = ((WeaponInfo *)(D_800D052C[((Shared_ActorView *)state)->selectedAction]))->animationCount;
        owner = ((Shared_ActorView *)state)->message;
        if ((owner != 0) && ((u32)D_800CD730 >= 5U)) {
            Camera_PostScreenMessage(&D_80145088, owner,
                *(void **)*(void **)D_800D052C[((Shared_ActorView *)state)->selectedAction]);
        }
        ((WeaponFireState *)body)->spinStep = 0;
        ((WeaponFireState *)body)->spin = 0;
        ((Shared_Actor *)part)->color = 0;
        ((WeaponFireState *)body)->charge = 0;
    }
}
#else
INCLUDE_ASM("span_1000", func_802325FC_de);
#endif
#endif
