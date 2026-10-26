#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "COMMON/INTEGERSTATE244.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "AI/NAV/80208000_5.H"
#include "RENDER_4/8028FD2C_6.H"

extern f32 Weapons_GetSignedAngleToPoint(Player *, CVector3);

/* Runs a computer player's engagement timer: while the countdown at 0x2E4 is positive it rerolls the
   wait at 0x2E8 as the config's base at 8 plus a random share (scale D_800C6E00) of its spread at 0xC
   and counts down; at zero it counts the opponents in range through func_80283228_de (three counting as
   the whole wait) and either flags waiting at 0x23C while fewer than the wait or starts pursuit with
   the countdown at -1 and a wait from the config's 0x24 and 0x28 (scale D_800C6E04); during pursuit
   the wait runs down, ends early once the player is within D_800C6E08 of its target on the target's
   height, and when it reaches zero flags 0x240 and acts through func_8020A95C_de. Written in the style of
   func_8020A458_de with the random scale loaded into a local first. */






extern char D_8011D8D0;

extern s32 func_80283228_de(char *, void *);

struct EffectSystem;
extern void func_80284FF4_de(struct EffectSystem *, void *, CVector3 *);

extern f32 func_802726BC_de(CVector3 *, CVector3 *);

struct LevelActor;
extern void func_802850C8_de(struct EffectSystem *arg0, struct LevelActor *arg1, f32 *arg2);

extern f32 Nav_GetEngagementDistance(void *arg0);


extern f32 Weapons_GetSignedAngleToPoint(Player *arg0, CVector3 point);

void func_80209E80_de(void *arg0)
{
    /* Dispatch the current actor mode through its per-type behavior table. */
    void *state;
    s32 mode;
    s32 type;
    Shared_ActorView *actor;

    state = arg0;
    if (state == 0) {
        return;
    }
    actor = *(Shared_ActorView **)state;
    if (0.0f < actor->stun) {
        return;
    }

    mode = actor->weapon.field2AC;
    type = actor->selectedAction;
    mode -= 1;
    {
        u32 dispatch = *(&D_800C87F0 + mode + type * 2);
        if (dispatch >= 9) {
            return;
        }
        switch (dispatch) {
        case 0: goto case_0;
        case 1: goto case_0;
        case 2: goto case_0;
        case 3: goto case_0;
        case 4: goto case_1;
        case 5: goto case_3;
        case 6: goto case_5;
        case 7: goto case_4;
        case 8: goto case_2;
        }
    }
case_0:
        func_8020A6D8_de(state, &D_800F3D20 + type * 0x38 + mode * 0x1C);
        goto dispatched;
case_1:
        func_8020A7B0_de(state, &D_800F3D20 + type * 0x38 + mode * 0x1C);
        goto dispatched;
case_2:
        ((ObjectLinks2EC *)state)->unk_240 = 1;
        goto dispatched;
case_3:
        func_8020A028_de(state, &D_800F3D20 + type * 0x38);
        goto dispatched;
case_4:
        func_8020A2D4_de(state, &D_800F3D20 + type * 0x38);
        goto dispatched;
case_5:
        func_8020A458_de(state, &D_800F3D20 + type * 0x38);
case_6:
case_7:
case_8:
dispatched:

    if (((ObjectLinks2EC *)state)->unk_240 > 0) {
        ((Shared_ActorView *)(*(void **)state))->unk_0x06B0 |= 0x4000;
        ((Shared_ActorView *)(*(void **)state))->actionFlags |= 0x4000;
        ((ObjectLinks2EC *)state)->unk_240 -= 1;
    }
}

void func_8020A028_de(AiController *arg0, AiConfig *arg1)
{
    s32 v0;
    f32 f20;
    f32 f1;
    f32 new_var;
    s32 s1;

    v0 = arg0->unk2EC;
    if (v0 > 0) {
        v0 = v0 - 1;
        arg0->unk2EC = v0;
        if (v0 == 0) {
            f20 = D_800C1CF4_de;
            if (Nav_RandomFloat(f20) < D_800C1CF8_de) {
                arg0->unk2EC = -1;
                arg0->unk2E4 = arg1->unk1C;
                arg0->unk2E4 = (s32) ((f32) arg0->unk2E4
                    + (Nav_RandomFloat(f20) * (f32) arg1->unk20));
                arg0->unk2E8 = arg1->unk24;
                arg0->unk2E8 = (s32) ((f32) arg0->unk2E8
                    + (Nav_RandomFloat(f20) * (f32) arg1->unk28));
            } else {
                arg0->unk2EC = arg1->unk10;
                arg0->unk2EC = (s32) ((f32) arg0->unk2EC
                    + (Nav_RandomFloat(f20) * (f32) arg1->unk14));
            }
        }
    }
    if (arg0->unk2EC == -1) {
        v0 = arg0->unk2E8 - 1;
        arg0->unk2E8 = v0;
        if (v0 == 0) {
            f20 = D_800C1CFC_de;
            arg0->unk2EC = arg1->unk10;
            arg0->unk2EC = (s32) ((f32) arg0->unk2EC
                + (Nav_RandomFloat(f20) * (f32) arg1->unk14));
            arg0->unk2E4 = arg1->unk0;
            arg0->unk2E4 = (s32) ((f32) arg0->unk2E4
                + (Nav_RandomFloat(f20) * (f32) arg1->unk4));
            arg0->unk2E8 = arg1->unk8;
            f1 = (f32) arg0->unk2E8
                + (Nav_RandomFloat(f20) * (f32) arg1->unkC);
            arg0->unk240 = 0;
            arg0->unk2E8 = (s32) f1;
        } else {
            arg0->unk240 = 1;
        }
    }
    v0 = arg0->unk2E4;
    if (v0 > 0) {
        arg0->unk2E4 = v0 - 1;
        return;
    }
    if (arg0->unk240 > 0) {
        s1 = arg1->unk1C;
        new_var = Nav_RandomFloat(D_800C1D00_de);
        if (1) {
            f20 = D_800C1D04_de;
            s1 = (s32) ((f32) s1 + (new_var * (f32) arg1->unk20));
        }
    } else {
        s1 = arg1->unk0;
        s1 = (s32) ((f32) s1 + (Nav_RandomFloat(D_800C1D08_de) * (f32) arg1->unk4));
        f20 = D_800C1D0C_de;
    }
    {
        AiTarget *p = arg0->target;
        Player *q = p->player;
        if (!(f20 < Weapons_GetSignedAngleToPoint(arg0->player,
                                    q->pos))) {
            arg0->unk23C = 1;
            arg0->unk2E4 = s1;
        }
    }
}

void func_8020A2D4_de(ObjectLinks2EC *arg0, IntegerState2C *config) {
    s32 count;
    char *target;
    CVector3 pos;
    f32 range;
    f32 scale;

    if (arg0->unk_2E4 > 0) {
        scale = D_800C6E00;
        arg0->unk_2E8 = config->unk_8;
        arg0->unk_2E8 =
            (f32) arg0->unk_2E8
            + Nav_RandomFloat(scale) * (f32) config->unk_C;
        arg0->unk_2E4 -= 1;
        return;
    }
    if (arg0->unk_2E4 == 0) {
        count = func_80283228_de(&D_8011D8D0, *(void **) arg0);
        if (count == 3) {
            arg0->unk_2E8 = count;
        }
        if (count < arg0->unk_2E8) {
            arg0->unk_23C = 1;
            return;
        }
        arg0->unk_2E4 = -1;
        scale = D_800C6E04;
        arg0->unk_2E8 = config->unk_24;
        arg0->unk_2E8 =
            (f32) arg0->unk_2E8
            + Nav_RandomFloat(scale) * (f32) config->unk_28;
        return;
    }
    arg0->unk_2E8 -= 1;
    target = ((struct ObjRecAt1D8V2 *) arg0->unk_64)->unk1D8;
    func_80284FF4_de(&D_8011D8D0, *(void **) arg0, &pos);
    range = D_800C6E08;
    pos.y = ((Player *)target)->pos.y;
    if (func_802726BC_de(&pos, &((Player *)(target))->pos) < range) {
        arg0->unk_2E8 = 0;
    }
    if (arg0->unk_2E8 == 0) {
        arg0->unk_240 = 1;
        func_8020A95C_de(arg0, config);
    }
}

void func_8020A458_de(void *object, void *settings) {
    AiController *controller = object;
    AiConfig *arg1 = settings;
    s32 timer;
    s32 minus_one;
    Player *record;
    f32 distance;

    if (controller == 0) {
        return;
    }

    timer = controller->unk2EC;
    if (timer == 0) {
        f32 value;

        func_802850C8_de(&D_8011D8D0, controller->player, &value);
        if (value < D_800C1D1C_de) {
            f32 k = D_800C1D24_de;
            f32 threshold = Nav_RandomFloat(D_800C1D20_de) + k;

            if ((f32) arg1->unk34 < threshold) {
                s32 base = arg1->unk24;
                controller->unk240 =
                    (s32) ((f32) base + Nav_RandomFloat(k) * (f32) arg1->unk28);
            }
            controller->unk2EC = arg1->unk2C;
            controller->unk2EC =
                (s32) ((f32) controller->unk2EC +
                       Nav_RandomFloat(k) * (f32) arg1->unk30);
            controller->unk2EC += controller->unk240;
        }
    } else {
        controller->unk2EC = timer - 1;
    }

    timer = controller->unk2E4;
    if (timer > 0) {
        controller->unk2E4 = timer - 1;
        return;
    }
    minus_one = -1;
    if (timer == minus_one) {
        controller->unk23C = 1;
        controller->unk2E8 += minus_one;
    } else {
        record = controller->target->player;
        distance = Weapons_GetSignedAngleToPoint(controller->player,
                                 record->pos);
        if (Nav_GetEngagementDistance(controller) < distance) {
            return;
        }
        controller->unk23C = 1;
        controller->unk2E4 = minus_one;
    }
    if (controller->unk2E8 == 0) {
        controller->unk23C = 0;
        func_8020A95C_de(controller, arg1);
    }
}

void Nav_LoadCollisionTable(void *arg0) {
    s32 s0;
    s32 s1;
    s32 s2;
    s32 s4;
    s32 base2;
    char *tbl;
    CollisionInfo8020CD74 *src;
    char *dst;

    s2 = 0;
    tbl = &D_800F3D20;
    s4 = 0;
    do {
        s0 = 0;
        base2 = s2 * 2;
        s1 = s4;
        do {
            src = Render_GetPackSection(arg0, base2 + s0);
            dst = (char *)(s1 + (s32)tbl);
            *(CollisionInfo8020CD74 *)dst = *src;
            s0 += 1;
            s1 += 0x1C;
        } while (s0 < 2);
        s2 += 1;
        s4 += 0x38;
    } while (s2 < 0x16);
}

void func_8020A6D8_de(void *controller, void *settings) {
    s32 timer;
    s32 minus_one;
    Player *record;
    f32 distance;

    if (controller == 0) {
        return;
    }
    func_8020A884_de(controller, settings);
    timer = ((AiController *)controller)->unk2E4;
    if (timer > 0) {
        ((AiController *)controller)->unk2E4 = timer - 1;
        return;
    }
    minus_one = -1;
    if (timer == minus_one) {
        ((AiController *)controller)->unk23C = 1;
        ((AiController *)controller)->unk2E8 += minus_one;
    } else {
        record = ((AiController *)controller)->target->player;
        distance = Weapons_GetSignedAngleToPoint(((AiController *)controller)->player, record->pos);
        if (Nav_GetEngagementDistance(controller) < distance) {
            return;
        }
        ((AiController *)controller)->unk23C = 1;
        ((AiController *)controller)->unk2E4 = minus_one;
    }
    if (((AiController *)controller)->unk2E8 == 0) {
        ((AiController *)controller)->unk23C = 0;
        func_8020A95C_de(controller, settings);
    }
}

void func_8020A7B0_de(void *controller, void *settings) {
    AiController *brain = controller;
    s32 timer;
    Player *record;
    f32 distance;

    if (controller == 0) {
        return;
    }
    func_8020A884_de(controller, settings);
    timer = brain->unk2E4;
    if (timer > 0) {
        brain->unk2E4 = timer - 1;
        return;
    }
    if (timer == 0) {
        brain->unk23C = 1;
        brain->unk2E8 -= 1;
    }
    if (brain->unk2E8 != 0) {
        return;
    }
    brain->unk2E4 = -1;
    record = brain->target->player;
    distance = Weapons_GetSignedAngleToPoint(brain->player, record->pos);
    if (Nav_GetEngagementDistance(controller) < distance) {
        brain->unk23C = 1;
        return;
    }
    brain->unk23C = 0;
    func_8020A95C_de(controller, settings);
}

void func_8020A884_de(void *arg0, void *settings) {
    AiController *o = arg0;
    AiConfig *i = settings;
    s32 timer = o->unk2EC;

    if (timer == 0) {
        if (o->unk23C == 0 && o->unk240 <= 0) {
            f32 k = D_800C1D2C_de;
            f32 threshold = Nav_RandomFloat(D_800C1D28_de) + k;

            if ((f32) i->unk18 < threshold) {
                o->unk240 = 1;
                func_8020A95C_de(arg0, settings);
            }
            o->unk2EC = i->unk10;
            o->unk2EC =
                (s32) ((f32) o->unk2EC +
                       Nav_RandomFloat(k) * (f32) i->unk14);
        }
    } else {
        o->unk2EC = timer - 1;
    }
}

void func_8020A95C_de(void *object, void *settings) {
    AiController *controller = object;
    AiConfig *aiConfig = settings;
    f32 k = D_800C6E20;

    controller->unk2E4 = aiConfig->unk0;
    controller->unk2E4 = (s32) ((f32) controller->unk2E4 + (Nav_RandomFloat(k) * (f32) aiConfig->unk4));
    controller->unk2E8 = aiConfig->unk8;
    controller->unk2E8 = (s32) ((f32) controller->unk2E8 + (Nav_RandomFloat(k) * (f32) aiConfig->unkC));
    if (aiConfig->unk18 == 0x64) {
        controller->unk240 = 1;
    }
}
