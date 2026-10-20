#include "include_asm.h"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/AIPROFILE.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/SELF.H"
#include "AI/NAV/80212C90_15.H"

/* Runs a computer player's think step: when it has reached its goal node or the goal at 0x22C is past
   the node count D_8013B368, it picks a new goal as func_802136EC_de does (func_80213340_de for a player
   flagged at 0x94 in mode 12, otherwise up to ten random nodes of D_8013B364 not flagged 0x400); then
   it counts down the jump timer at 0x320 and on expiry makes its player jump (bit 0x10 at 0x6B0)
   unless the player is in state 0xF, holds input bits 0x3000 or the bot is busy at 0x314, rerolls an
   expired timer to 15 times 3 to 9 frames, and runs func_80211020_de, Nav_SteerAlongRoute and func_80208AAC_de. */

extern s32 D_8013B364;


extern void *func_8020C994_de(void *, s32);
extern void func_80211020_de(void *);
extern void Nav_SteerAlongRoute(void *);
extern void func_80208AAC_de(void *);
















void func_80213500_de(Shared_Actor *arg0) {
    void *actor = ((Actor_func_8022D290_de *)(arg0->entity))->unk_0x1454;
    void *player;
    s32 busy;
    s32 held;
    s32 state;

    if (((Brain_func_80212D78_eu_x *)(actor))->node == ((Brain_func_80212D78_eu_x *)(actor))->goal
        || !(((Brain_func_80212D78_eu_x *)(actor))->goal < D_8013B368)) {
        void *data = ((Actor_func_8022D290_de *)(*(void **) actor))->unk_0x05D8;
        if (((RecordRecAt94 *)(data))->display && ((RecordRecAt94 *)(data))->kind == 12) {
            func_80213340_de(actor);
        } else {
            s32 global_count = D_8013B368;
            s32 *table = &D_8013B364;
            s32 tries = 0;
            s32 candidate;

            if (global_count >= 2) {
                candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
loop:
                if (tries < 10) {
                    candidate = func_802744D4_de() % table[1];
                    if (((NavigationNode *)(func_8020C994_de(table, candidate)))->flags & 0x400) {
                        candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
                    }
                    tries++;
                    if (candidate != ((Brain_func_80212D78_eu_x *)(actor))->goal) {
                        goto store_both;
                    }
                    goto loop;
                } else {
                    ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
                    goto store_c;
                }
            } else {
                candidate = 1;
            }
store_both:
            ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
store_c:
            ((Brain_func_80212D78_eu_x *)(actor))->nextNode = candidate;
        }
    }
    if (--((Brain_func_80212D78_eu_x *)(actor))->jumpTimer == 0) {
        player = *(void **) actor;
        state = ((Actor_func_8022D290_de *)(player))->unk_0x0650 != 0xF;
        busy = ((Brain_func_80212D78_eu_x *)(actor))->busy != 0;
        held = (((Actor_func_8022D290_de *)(player))->unk_0x0038 & 0x3000) != 0;
        if (state && !held && !busy) {
            ((Actor_func_8022D290_de *)(player))->unk_0x06B0 |= 0x10;
        }
    }
    if (((Brain_func_80212D78_eu_x *)(actor))->jumpTimer < 0) {
        ((Brain_func_80212D78_eu_x *)(actor))->jumpTimer = (func_802744D4_de() % 7 + 3) * 15;
    }
    func_80211020_de(actor);
    Nav_SteerAlongRoute(actor);
    func_80208AAC_de(actor);
}

extern s32 D_8013B364;



extern void *func_8020C994_de(void *, s32);















void func_802136EC_de(Shared_Actor *arg0)
{
    void *actor = ((Actor_func_8022D290_de *)(arg0->entity))->unk_0x1454;

    ((Brain_func_80212D78_eu_x *)(actor))->unk220 = 0;
    {
        void *data = ((Actor_func_8022D290_de *)(*(void **)actor))->unk_0x05D8;
        if (((RecordRecAt94 *)(data))->display && ((RecordRecAt94 *)(data))->kind == 12) {
            func_80213340_de(actor);
        } else {
            s32 global_count = D_8013B368;
            s32 *table = &D_8013B364;
            s32 tries = 0;
            s32 candidate;

            if (global_count >= 2) {
                candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
loop:
                if (tries < 10) {
                    candidate = func_802744D4_de() % table[1];
                    if (((NavigationNode *)(func_8020C994_de(table, candidate)))->flags & 0x400) {
                        candidate = ((Brain_func_80212D78_eu_x *)(actor))->goal;
                    }
                    tries++;
                    if (candidate != ((Brain_func_80212D78_eu_x *)(actor))->goal) {
                        goto store_both;
                    }
                    goto loop;
                } else {
                    ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
                    goto store_c;
                }
            } else {
                candidate = 1;
            }
store_both:
            ((Brain_func_80212D78_eu_x *)(actor))->goal = candidate;
store_c:
            ((Brain_func_80212D78_eu_x *)(actor))->nextNode = candidate;
        }
    }
    func_80209988_de(actor);
    ((Brain_func_80212D78_eu_x *)(actor))->jumpTimer = -1;
}

extern s32 D_8013B364;

extern void *func_8020C994_de(void *, s32);






void func_80213810_de(void *arg0)
{
    s32 *table = &D_8013B364;
    s32 tries = 0;
    s32 candidate;

    if (table[1] >= 2) {
        candidate = ((Brain_func_80212D78_eu_x *)(arg0))->goal;
loop:
        if (tries < 10) {
            candidate = func_802744D4_de() % table[1];
            if (((NavigationNode *)(func_8020C994_de(table, candidate)))->flags & 0x400) {
                candidate = ((Brain_func_80212D78_eu_x *)(arg0))->goal;
            }
            tries++;
            if (candidate != ((Brain_func_80212D78_eu_x *)(arg0))->goal) {
                goto store_both;
            }
            goto loop;
        } else {
            ((Brain_func_80212D78_eu_x *)(arg0))->goal = candidate;
            goto store_c;
        }
    } else {
        candidate = 1;
    }
store_both:
    ((Brain_func_80212D78_eu_x *)(arg0))->goal = candidate;
store_c:
    ((Brain_func_80212D78_eu_x *)(arg0))->nextNode = candidate;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802138E8);
#endif
