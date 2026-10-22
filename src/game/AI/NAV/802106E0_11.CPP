#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SELF.H"
#include "TYPES.H"
#include "AI/NAV/802106E0_11.H"

#if !(defined(VERSION_DE))
/* Drives combat pursuit, retreat and strafing while refreshing target visibility, routes and fire timing. */








extern s32 D_800D297C;
extern char D_8013B364[];

extern void func_80211020_de(CloseAttackBrain *);
extern s32 func_802099B4_de(CloseAttackBrain *, CloseAttackActor *);
extern void func_80209874_de(CloseAttackBrain *, s32);
extern f32 func_802726BC_de(CVector3 *, CVector3 *);
extern f32 func_80209BE0_de(CloseAttackBrain *);
extern f32 func_80209DAC_de(CloseAttackBrain *);
extern f32 func_80209308_de(CloseAttackBrain *, CVector3 *, f32, f32);
extern s32 func_80210EFC_de(f32);
extern void func_80210964_de(CloseAttackActor *, s32);
extern void func_80209E80_de(CloseAttackBrain *);
extern s32 func_8020D1CC_de(char *, s32, s32);


extern void Nav_SteerAlongRoute(CloseAttackBrain *),func_80208AAC_de(CloseAttackBrain *),func_8020FA10_de(CloseAttackBrain *);
extern struct {char pad[0xC];unsigned short flags;} *func_8020C994_de(char *,int);
extern float D_800C22D0_eu[];

void func_80211490_eu(CloseAttackActor *actor) {
 char *routes;int mine,theirs,dir; CloseAttackActor *player;
    CloseAttackActor *temp_a1;
    CloseAttackActor *temp_s0;
    CloseAttackActor *temp_v1_3;
    CloseAttackBrain *temp_s1;
    CVector3 *temp_s0_2;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_s2;
    s32 temp_v0;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v0_4;
    s32 var_v0_5;

    temp_s1 = actor->self->brain;
    func_80211020_de(temp_s1);
    temp_a1 = temp_s1->target;routes=D_8013B364;
    if (temp_a1 != 0) {
        if (!(temp_s1->frames & 3)) {
            temp_s1->visible = func_802099B4_de(temp_s1, temp_a1);
        }
        temp_s1->frames += 1;
        temp_s0 = temp_s1->target->self;
        mine=temp_s1->player->flags&0x3000;theirs=(temp_s0->flags&0x3000)!=0;
        if (mine && !theirs) {
            func_80209874_de(temp_s1,12);return;
        }
        temp_s2 = temp_s0->brain->route;
        if (func_8020C994_de(routes, temp_s2)->flags & 0x400) {
            temp_s1->target = 0;
            func_8020FA10_de(temp_s1);
            return;
        }
        if (temp_s1->visible != 0) {
            temp_f21 = func_80209BE0_de(temp_s1);
            temp_v0 = temp_s1->timer - 1;
            temp_f20 = temp_f21 * 0.6f;
            temp_s1->timer = temp_v0;
            if (temp_v0 <= 0) {
                temp_s1->timer=func_802744D4_de()%4+12;
                temp_s1->pattern = func_802744D4_de() % 2;
                temp_s1->distance = (func_802744D4_de() % 250000) + 0x57E40;
            }
            temp_s0_2 = &temp_s0->pos;
            func_80209308_de(temp_s1, temp_s0_2, 2.0f, func_80209DAC_de(temp_s1));
            temp_f0 = func_802726BC_de(temp_s0_2, &temp_s1->player->pos);
            temp_f1 = temp_f0 + 10000.0f;
            temp_f2 = (f32) temp_s1->distance;
            if (temp_f1 < 0.0f) {
                if (temp_f2 < -temp_f1) {
                    goto block_19;
                }
                goto block_23;
            }
            if (temp_f2 < temp_f1) {
block_19:
                dir = func_80210EFC_de(temp_s1->player->yaw - 3.1415927f);
                player = temp_s1->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (!(temp_s1->walk[dir] < 100.0f)) {
                    temp_s1->player->forward = 1.0f;
                } else {
                    goto block_31;
                }
            } else {
block_23:
                temp_f1_2 = temp_f0 - 10000.0f;
                temp_f2_2 = (f32) temp_s1->distance;
                if (temp_f1_2 < 0.0f) {
                    if (-temp_f1_2 < temp_f2_2) {
                        goto block_27;
                    }
                    goto block_31;
                }
                if (temp_f1_2 < temp_f2_2) {
block_27:
                    dir = func_80210EFC_de(temp_s1->player->yaw);
                    player = temp_s1->player;
                    if ((player->slot % 2) == D_800D297C) {
                        func_80210964_de(player, dir);
                    }
                    if (!(temp_s1->walk[dir] < 100.0f)) {
                        temp_s1->player->forward = -1.0f;
                    } else {
                        goto block_31;
                    }
                } else {
block_31:
                    temp_s1->player->forward = 0.0f;
                }
            }
            temp_v1_2 = temp_s1->pattern;
            if (temp_v1_2 == 0) {
                dir = func_80210EFC_de((temp_s1->player->yaw - 3.1415927f) - 1.5707964f);
                player = temp_s1->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (!(temp_s1->walk[dir] < 100.0f)) {
                    temp_s1->player->strafe = -temp_f20;
                } else {
                    goto block_41;
                }
            } else if (temp_v1_2 == 1) {
                dir = func_80210EFC_de((temp_s1->player->yaw - 3.1415927f) + 1.5707964f);
                player = temp_s1->player;
                if ((player->slot % 2) == D_800D297C) {
                    func_80210964_de(player, dir);
                }
                if (temp_s1->walk[dir] < 100.0f) {
block_41:
                    temp_s1->player->strafe = 0.0f;
                    temp_s1->pattern = 2;
                } else {
                    temp_s1->player->strafe = temp_f20;
                }
            } else {
                temp_s1->player->strafe = 0.0f;
            }
            temp_s1->routeNodes[0] = -1;
            temp_v0_6 = temp_s1->fireTimer - 1;
            temp_s1->fireTimer = temp_v0_6;
            if ((temp_v0_6 == 0) && ((func_802744D4_de() % 100) < (s32) temp_f21)) {
                temp_v1_3 = temp_s1->player;
                temp_v1_3->buttons |= 0x10;
            }
            if (temp_s1->fireTimer < 0) {
                temp_s1->fireTimer = ((func_802744D4_de() % 2) + 2) * 0xF;
            }
            func_80209E80_de(temp_s1);
        } else {
            temp_s1->destination = temp_s2;
            Nav_SteerAlongRoute(temp_s1);
            func_80208AAC_de(temp_s1);
        }
        if (temp_s2 != temp_s1->node) {
            temp_s1->node = temp_s2;
            if (func_8020D1CC_de(routes, temp_s1->route, temp_s2) == 0) {
                func_80209874_de(temp_s1,1);
            }
        }
    }
}
#endif
