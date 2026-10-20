#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/ROUND_STATE_VARIANTS.H"

/* Player state, projectiles, effects and linked-actor transitions. */
#include "TYPES.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/VECTOR4F.H"
#include "RENDER_2/OBJECTSTATE8E.H"
#include "COMMON/RESULTS.H"
#include "SYSTEM/80255C40_3.H"
#include "SYSTEM/80255C40_7.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/8025DE50_5.H"
#include "RENDER_2/802192C0_3.H"
/* Apply player transitions, regional control gates, and localized linked-actor notifications. */






extern const Shared_HeightBonuses D_800C2608_eu;
extern const f32 D_800C22A0_us;
extern const f32 D_800C22A4_us;
extern s32 D_800C9228_de[2];



                                                  /* size = 0x18 */




void *func_8020C994_de(void *, s32);
s32 func_8020CB3C_de(void *, void *);
s32 func_802227F4_de(void *, void *, s32);
void *func_80237E80_de(void *, void *, u8 *);
void *func_80239770_de(void *, void *, void *, f32); /* extern */
CQuatern func_8024796C_de(char *);
s32 func_8024BE80_de(void *);
void func_8024E79C_de(void *, Triple, void *, s32 *, s32, s32); /* extern */
s32 func_8025DE54_de(s16, CVector3, s32, s32); /* extern */
void func_802647E8_de(void *, s32);
void func_80278D78_de(void *, s32, void *);
void func_80278E04_de(s32, s32, void *);
s32 func_802800C0_de(void *, void *, void *, s32 *, s32, s32, CVector3, CQuatern, CVector3, CVector3 *, s32, s32); /* extern */
void func_80283278_de(void *, s32);
s32 func_8028B21C_de(struct Shared_World *, s32);
void func_8028B898_de(void *, void *, s32);
void *func_8028FFD0_de(void *, s32 *, s32, CVector3, CVector3, s32, f32); /* extern */
struct ListNode80290528;
void func_80290548_de(struct ListNode80290528 *);
s32 func_802A01E8_de(void);
s32 func_80448EF4_de(void *, s8, s32);         /* extern */
void func_8044972C_de(void *);
void func_8044A07C_de(void *);


extern s32 D_8011D8D0;


extern s32 D_8013B364;
extern struct Shared_GlobalPlayers D_80145040;
extern struct Shared_GlobalRuntimeState D_80145060;










 /* unable to generate initializer: non-zero padding; const */








void func_8021B468_de(struct Shared_ActorView *arg0, void *arg1, s32 arg2, s32 arg3) {
    CVector3 spawnPosition;
    struct CVector3_t spawnVector;
    struct CVector3_t motionVector;
    struct Shared_GlobalPlayers *playersGlobal;
    struct Shared_GlobalFlowState *flow;
    struct Shared_GlobalFlowState *laterFlow;
    struct GameLocalizationState *localization;
    s32 *messageContext;
    CQuatern motionOutput;
    s32 sp90;
    
    s8 *settingsBase;
    struct Shared_PlayerSettingsRecord *var_s1;
    s16 temp_s0_2;
    s16 temp_s0_3;
    s16 temp_s0_4;
    s32 temp_v1_9;
    s16 var_a0_4;
    s16 var_a0_5;
    void *temp_a1_2;
    void *temp_a1_3;
    s32 temp_s0_6;
    void *temp_v0_11;
    s32 temp_v0_12;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v0_8;
    s32 temp_v0_9;
    s32 temp_v1_4;
    s32 temp_v1_6;
    s32 temp_v1_7;
    s32 temp_v1_8;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a2;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 var_s3;
    
    s32 loopLimit;
    s32 var_s3_2;
    s32 var_s4;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    struct Shared__struct_D_800D34C0_0x18 *temp_v0_10;
    struct Shared__struct_D_800D34C0_0x18 *temp_v0_4;
    struct Shared__struct_D_800D34C0_0x18 *temp_v0_7;
    u16 temp_v1_3;
    u16 temp_v1_5;
    u32 temp_v1;
    void *temp_a1;
    void *temp_s0;
    void *temp_s0_5;
    void *temp_v0;
    void *temp_v1_2;
    void *var_s0;
    void *var_s0_2;

    func_802647E8_de(((struct Shared_ActorView *)arg0)->controller, 0);
    if (((struct Shared_ActorView *)arg0)->action == 0x27) {
        func_802227F4_de(arg0, arg1, 2);
    }
    ((struct Shared_ActorView *)arg0)->field1218 = 0;
    func_80278D78_de(arg1, 1, arg1);
    func_8044A07C_de(arg0);
    func_8022B530_de((s32)arg0);
    ((struct Shared_ActorView *)arg0)->stun = 0;
    ((struct Shared_ActorView *)arg0)->field11FC = 0;
    func_80283278_de(&D_8011D8D0, (s32)arg0);
    flow = &D_80145060.flow;
    if ((flow->active != 0)
        && gameplayTransitionEnabled(arg0->controls->germanActive)
        && (var_s3 = 0, (((struct Shared_ActorView *)arg0)->controls->mode == 0xE))) {
        flow->count = (s32) (flow->count + 1);
        playersGlobal = &D_80145040;
        if (playersGlobal->count > 0) {
            settingsBase = (s8 *)&D_80146398;
            var_s1 = (struct Shared_PlayerSettingsRecord *)settingsBase;
            var_s4 = 0;
settings_loop:
            do {
                temp_s0 = playersGlobal->players + var_s4;
                if (var_s1->active != 0) {
                    if (((struct Shared_PlayerSettingsView *)settingsBase)->state == 1) {
                    ((struct Shared_ActorView *)temp_s0)->actorState = (s32) ((struct Shared_PlayerSettingsView *)settingsBase)->state;
                    func_80448EF4_de(temp_s0, var_s1->character, 1);
                    temp_v0 = ((struct Shared_ActorView *)temp_s0)->model;
                    ((struct Shared_ModelView *)temp_v0)->flags = (s32) (((struct Shared_ModelView *)temp_v0)->flags & ~4);
                    func_80214178_de(&((struct Shared_ActorView *)temp_s0)->weapon, &((struct Shared_ActorView *)temp_s0)->weapon.behaviorFlags, 2);
                    func_8021B1E4_de(temp_s0, ((struct Shared_PlayerSettingsView *)settingsBase)->effect, 0, 0);
                    func_80255ED8_de(playersGlobal->controller, temp_s0);
                    func_80255CB8_de(&playersGlobal->effects, temp_s0);
                    } else if (((struct Shared_PlayerSettingsView *)settingsBase)->state < 3) {
                        func_8044972C_de(temp_s0);
                    }
                }
block_13:
                do {
                    var_s1++;
                } while (0);
                loopLimit = playersGlobal->count;
                do {
                    var_s3 += 1;
                } while (0);
                var_s4 += 0x16E8;
                if (var_s3 < loopLimit) goto settings_loop;
            } while (0);
        }
        if (D_8014693C < 3) {
            ((struct Shared_ActorView *)arg0)->special = 0;
            func_802227F4_de(arg0, arg1, 0x2E);
            return;
        } else {
            goto block_17;
        }
    } else {
block_17:
        if (D_801462E5 != 0) {
            if ((((struct Shared_ActorView *)arg0)->ammo[0] > 0) || (((struct Shared_ActorView *)arg0)->ammo[1] > 0) || (((struct Shared_ActorView *)arg0)->ammo[2] > 0)) {
                temp_v1 = ((struct Shared_ActorView *)arg0)->mode;
                var_s3_2 = 0;
                switch (temp_v1) {
case 0:
default:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBD9;
                    break;
case 1:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBDB;
                    break;
case 2:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBDD;
                    break;
case 3:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBDF;
                    break;
case 4:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBE1;
                    break;
case 5:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBE3;
                    break;
case 6:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBE5;
                    break;
case 7:
                    var_s1_2 = ((struct Shared_ActorView *)arg0)->projectileIndex + 0xBE7;
                    break;
                }
                func_8028B21C_de(&D_8011FE88, var_s1_2);
                temp_v1_2 = ((struct Shared_ActorView *)arg0)->projectiles[((struct Shared_ActorView *)arg0)->projectileIndex];
                if (temp_v1_2 != 0) {
                    ((struct Shared_ProjectileView *)temp_v1_2)->flags = (u16) (((struct Shared_ProjectileView *)temp_v1_2)->flags | 1);
                    temp_a1 = ((struct Shared_ActorView *)arg0)->projectiles[((struct Shared_ActorView *)arg0)->projectileIndex];
                    if (((struct Shared_ProjectileView *)temp_a1)->flags & 8) {
                        func_80290548_de(temp_a1);
                    } else {
                        func_8028B898_de(&D_8011FE88, temp_a1, 1);
                        func_80278E04_de(((struct Shared_ProjectileView *)((struct Shared_ActorView *)arg0)->projectiles[((struct Shared_ActorView *)arg0)->projectileIndex])->source, 0x400, arg0);
                    }
                }
                temp_v1_3 = ((struct Shared_ActorView *)arg0)->kind;
                if (temp_v1_3 == D_800CE474[0]) {
                    var_s3_2 = 0;
                } else if (temp_v1_3 == D_800CE474[1]) {
                    var_s3_2 = 0;
                } else {
                    switch (func_802A01E8_de() % 3) {            /* switch 2; irregular */
                    case 0:                         /* switch 2 */
                        temp_s0_2 = ((struct Shared_ActorView *)arg0)->ammo[0];
                        var_a0 = 0;
                        if (temp_s0_2 != 0) {
                            temp_v0_2 = func_802A01E8_de();
                            temp_v0_3 = temp_v0_2 / temp_s0_2;
                            if (temp_s0_2 == 0) {

                            }
                            if ((temp_s0_2 == -1) && (temp_v0_3 == 0x80000000)) {

                            }
                            var_a0 = temp_v0_2 % temp_s0_2;
                        }
                        if (var_a0 != 0) {
                            var_s3_2 = 1;
                            temp_v0_4 = &((struct Shared__struct_D_800D34C0_0x18 *)&D_800D34C0)[((struct Shared_ActorView *)arg0)->projectileBase + ((struct Shared_ActorView *)arg0)->projectileIndex];
                            temp_v0_4->unkC = (s16) var_a0;
                            temp_v0_4->unkE = 0;
                            temp_v0_4->unk10 = 0;
                        }
                        break;
                    case 1:                         /* switch 2 */
                        temp_s0_3 = ((struct Shared_ActorView *)arg0)->ammo[1];
                        var_a0_2 = 0;
                        if (temp_s0_3 != 0) {
                            temp_v0_5 = func_802A01E8_de();
                            temp_v0_6 = temp_v0_5 / temp_s0_3;
                            if (temp_s0_3 == 0) {

                            }
                            if ((temp_s0_3 == -1) && (temp_v0_6 == 0x80000000)) {

                            }
                            var_a0_2 = temp_v0_5 % temp_s0_3;
                        }
                        if (var_a0_2 != 0) {
                            var_s3_2 = 1;
                            temp_v0_7 = &((struct Shared__struct_D_800D34C0_0x18 *)&D_800D34C0)[((struct Shared_ActorView *)arg0)->projectileBase + ((struct Shared_ActorView *)arg0)->projectileIndex];
                            temp_v0_7->unkE = (s16) var_a0_2;
                            temp_v0_7->unkC = 0;
                            temp_v0_7->unk10 = 0;
                        }
                        break;
                    case 2:                         /* switch 2 */
                        temp_s0_4 = ((struct Shared_ActorView *)arg0)->ammo[2];
                        var_a0_3 = 0;
                        if (temp_s0_4 != 0) {
                            temp_v0_8 = func_802A01E8_de();
                            temp_v0_9 = temp_v0_8 / temp_s0_4;
                            if (temp_s0_4 == 0) {

                            }
                            if ((temp_s0_4 == -1) && (temp_v0_9 == 0x80000000)) {

                            }
                            var_a0_3 = temp_v0_8 % temp_s0_4;
                        }
                        if (var_a0_3 != 0) {
                            var_s3_2 = 1;
                            temp_v0_10 = &((struct Shared__struct_D_800D34C0_0x18 *)&D_800D34C0)[((struct Shared_ActorView *)arg0)->projectileBase + ((struct Shared_ActorView *)arg0)->projectileIndex];
                            temp_v0_10->unk10 = (s16) var_a0_3;
                            temp_v0_10->unkC = 0;
                            temp_v0_10->unkE = 0;
                        }
                        break;
                    }
                }
                if (var_s3_2 != 0) {
                    temp_s0_5 = func_8020C994_de(&D_8013B364, func_8020CB3C_de(&D_8013B364, &arg0->position.vector));
                    func_8024E79C_de(arg0, arg0->position.words, &spawnPosition, &sp90, 0, 0);
                    if (temp_s0_5 != 0) {
                        spawnPosition = *(CVector3 *)temp_s0_5;
                    }
                    spawnVector.x = 0;
                    spawnVector.y = 0.0f;
                    spawnVector.z = 0;
                    temp_v0_11 = func_8028FFD0_de(&D_80131600, 0, var_s1_2, spawnVector, spawnPosition, 0, 0);
                    if (temp_v0_11 != 0) {
                        spawnPosition.y += D_800C2608_eu.spawn;
                        ((struct Shared_ActorView *)arg0)->projectiles[((struct Shared_ActorView *)arg0)->projectileIndex] = (void *)temp_v0_11;
                    }
                } else {
                    ((struct Shared_ActorView *)arg0)->projectiles[((struct Shared_ActorView *)arg0)->projectileIndex] = 0;
                }
                ((struct Shared_ActorView *)arg0)->projectileIndex = (s32) (((struct Shared_ActorView *)arg0)->projectileIndex == 0);
            }
            if ((((struct Shared_ActorView *)arg0)->controls->transientFlag != 0) && (laterFlow = &D_80145060.flow, laterFlow->transition != 0)) {
                if (D_800F3D08 != 0) {
                    func_80214178_de(D_800F3D08, ((struct Shared_SpecialObjectView *)D_800F3D08)->segment, 1);
                    ((struct Shared_SpecialObjectView *)D_800F3D08)->reset = 0;
                    laterFlow->reset = 0;
                    func_8025DF34_de(0x2D0);
                    var_s0 = D_80145060.actorList;
                    if (var_s0 != 0) {
                        messageContext = &D_80145060.messageContext;
                        localization = &D_80145060.localization;
                        do {
                            temp_a1_2 = ((struct Shared_ActorView *)var_s0)->message;
                            if (temp_a1_2 != 0) {
                                func_80237E80_de(gameplayMessageContext(messageContext), temp_a1_2, gameplayResetMessage(localization->language));
                            }
                            var_s0 = ((struct Shared_ActorView *)var_s0)->next;
                        } while (var_s0 != 0);
                    }
                }
                ((struct Shared_ActorView *)arg0)->controls->transientFlag = 0U;
                ((struct Shared_ActorView *)arg0)->controls->resetFlag = 0;
            }
            var_s0_2 = D_80145060.actorList;
            if (var_s0_2 != 0) {
                messageContext = &D_80145060.messageContext;
                localization = &D_80145060.localization;
                do {
                    if ((var_s0_2 != arg0) && (((struct Shared_ActorView *)var_s0_2)->parent == arg0)) {
                        temp_a1_3 = ((struct Shared_ActorView *)var_s0_2)->message;
                        ((struct Shared_ActorView *)var_s0_2)->pending = 0;
                        ((struct Shared_ActorView *)var_s0_2)->parent = 0;
                        if (temp_a1_3 != 0) {
                            func_80239770_de(gameplayMessageContext(messageContext), temp_a1_3, gameplayReleaseMessage(localization->language), 1.0f);
                        }
                    }
                    var_s0_2 = ((struct Shared_ActorView *)var_s0_2)->next;
                } while (var_s0_2 != 0);
            }
        }
        ((struct Shared_ActorView *)arg0)->field1238 = -1;
        ((struct Shared_ActorView *)arg0)->field1230 = 0;
        ((struct Shared_ActorView *)arg0)->field1234 = 0;
        ((struct Shared_ActorView *)arg0)->field1240 = 0;
        ((struct Shared_ActorView *)arg0)->field122C = (s32) (((struct Shared_ActorView *)arg0)->field122C & 0xFFFF0000);
        if (arg2 & 0x4000) {
            if ((u32) (((struct Shared_ActorView *)arg0)->state - 0x11) < 2U) {
                ((struct Shared_ActorView *)arg0)->special = 1;
            }
        }
        if (((struct Shared_ActorView *)arg0)->special == 0) {
            var_a0_4 = 0x2BC;
            if (arg3 != 0x1F) {
                var_a0_4 = func_80229C0C_de(arg0, 0x1397);
            }
            func_8025DE54_de(var_a0_4, arg0->position.vector, (s32)&arg0->position.vector, -1);
        } else {
            func_8025DE54_de(0x9FB, arg0->position.vector, (s32)&arg0->position.vector, -1);
        }
        func_8025DF34_de(0x212);
        if ((((struct Shared_ActorView *)arg0)->special != 0) || (temp_v1_5 = ((struct Shared_ActorView *)arg0)->kind, (temp_v1_5 == D_800C9228_de[0])) || (temp_v1_5 == D_800C9228_de[1])) {
            spawnVector.x = arg0->position.vector.x;
            spawnVector.y = arg0->position.vector.y + D_800C2608_eu.projectile;
            var_s1_3 = 1;
            spawnVector.z = arg0->position.vector.z;
            var_v0 = func_802A01E8_de();
            temp_v1_6 = var_v0;
            if (temp_v1_6 < 0) {
                var_v0 = temp_v1_6 + 0x3FF;
            }
            motionVector.x = (f32) (temp_v1_6 - ((var_v0 >> 0xA) << 0xA)) - D_800C22A0_us;
            var_v0_2 = func_802A01E8_de();
            temp_v1_7 = var_v0_2;
            if (temp_v1_7 < 0) {
                var_v0_2 = temp_v1_7 + 0x3FF;
            }
            motionVector.y = (f32) (temp_v1_7 - ((var_v0_2 >> 0xA) << 0xA)) - D_800C22A0_us;
            var_v0_3 = func_802A01E8_de();
            temp_v1_8 = var_v0_3;
            if (temp_v1_8 < 0) {
                var_v0_3 = temp_v1_8 + 0x3FF;
            }
            motionVector.z = (f32) (temp_v1_8 - ((var_v0_3 >> 0xA) << 0xA)) - D_800C22A0_us;
            motionOutput = func_8024796C_de((char *)arg0);
            temp_s0_6 = ((struct Shared_ActorView *)arg0)->frameValue;
            if (func_8024BE80_de(arg0) == 5) {
                var_s1_3 = 3;
            }
            func_802800C0_de(&D_8011D8D0, arg0, arg0, 0, temp_s0_6, 0x64, motionVector, motionOutput, spawnVector, 0, -1, var_s1_3);
        }
        if (arg3 != -1) {
            func_802227F4_de(arg0, arg1, arg3);
            return;
        }
        if (((struct Shared_ActorView *)arg0)->state != 0x11) {
            if (((struct Shared_ActorView *)arg0)->action == 0xA && (arg2 & 0x4000)) {
                func_802227F4_de(arg0, arg1, 0x2A);
                return;
            }
            if (arg2 & 0x4000) {
                func_802227F4_de(arg0, arg1, 0x29);
                return;
            }
        }
        var_v0_4 = 1;
        if (!(((struct Shared_ActorView *)arg0)->speed > D_800C22A4_us)) {
            var_v0_4 = 0;
        }
        if (var_v0_4 != 0) {
            func_802227F4_de(arg0, arg1, 0x1C);
            return;
        }
        temp_v1_9 = ((struct Shared_ActorView *)arg0)->action;
        if ((temp_v1_9 ^ 0xF) == 0) {
            func_802227F4_de(arg0, arg1, 0x21);
            return;
        }
        if (temp_v1_9 == 9) {
            func_802227F4_de(arg0, arg1, 0x1F);
            return;
        }
        if (temp_v1_9 == 10) {
            func_802227F4_de(arg0, arg1, 0x1F);
            return;
        }
        if (temp_v1_9 == 11) {
            func_802227F4_de(arg0, arg1, 0x1F);
            return;
        }
        if (temp_v1_9 == 12) {
            func_802227F4_de(arg0, arg1, 0x1F);
            return;
        }
        if (arg2 & 0x1000) {
            func_802227F4_de(arg0, arg1, 0x1F);
            return;
        }
        if (arg2 & 0x200) {
            func_802227F4_de(arg0, arg1, 0x19);
            return;
        }
        if ((((struct Shared_ActorView *)arg0)->state != 0x11) && (((struct Shared_ActorView *)arg0)->specialState == 1)) {
            func_802227F4_de(arg0, arg1, 0x1E);
            return;
        }
        if (((struct Shared_ActorView *)arg0)->specialState == 2) {
            func_802227F4_de(arg0, arg1, 0x1D);
            return;
        }
        func_802227F4_de(arg0, arg1, 0x16);
        return;
    }
}

INCLUDE_ASM("span_1000", func_8021BFC4_de);

#ifdef NON_MATCHING
#include "COMMON/FIELD_VEC_B0.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "TYPES.H"


extern s32 func_8022C460_de(void *arg0);
extern void func_8022B69C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B550_de(void *arg0, f32 arg1, f32 arg2, void *arg3,
                          s32 arg4);
extern void func_8022B60C_de(void *arg0, f32 arg1, void *arg2);
extern void func_8022B7F8_de(void *arg0, void *arg1);
extern void func_802227F4_de(void *, void *, s32);

void func_8021C45C_de(void *arg0, void *arg1, s32 arg2, void *arg3) {
    Player *actor = arg0;
    Shared_Particle *event = arg3;
    RenderCounters *audio;
    u16 type;

    if (actor->health == 0) {
        return;
    }
    if (func_8022C460_de(actor) != 0) {
        return;
    }
    if (actor->damageCooldown > 0.0f) {
        return;
    }
    audio = &D_801462C8.counters;
    if (audio->enabled != 0 &&
        actor->profile->character == 0xB &&
        audio->timer > 0) {
        return;
    }
    if (actor->reactionFlags & 0x8000) {
        return;
    }

    type = event->inst.type;
    switch (type) {
    case 0x3FB:
    case 0x4CD:
        func_8022B69C_de(actor, 0.1f, event->owner);
        return;
    case 0x3FD:
    case 0x4CF:
        func_8022B69C_de(actor, 0.125f, event->owner);
        return;
    case 0x3FE:
    case 0x4D0:
        func_8022B69C_de(actor, 0.3f, event->owner);
        return;
    case 0x432:
    case 0x4E3:
        func_8022B550_de(actor, 80.0f, 2.0f, event->owner, 1);
        return;
    case 0x408:
    case 0x4E0:
        func_8022B60C_de(actor, 0.25f, event->owner);
        return;
    case 0x419:
    case 0x4D3:
        func_8022B7F8_de(actor, event->owner);
        return;
    case 0x129:
        actor->cooldown = 0;
        actor->pending = 0;
        if (!(actor->reactionFlags & 0x8000)) {
            if (actor->reactionOwner == 0) {
                actor->reactionOwner = event->owner;
            }
            func_802227F4_de(actor, actor, 0x26);
        }
        return;
    }
}
#else
INCLUDE_ASM("span_1000", func_8021C45C_de);
#endif
