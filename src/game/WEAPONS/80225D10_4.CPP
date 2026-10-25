#include "include_asm.h"
#include "COMMON/OBJRECV5.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/LOADOUT.H"
#include "TYPES.H"
#include "GFX/TEXT/802A8A94_5.H"
extern void func_8022A748_de(void *);
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/SELF.H"
#include "COMMON/VIEWFLAGS.H"
#include "WEAPONS/80213ED4.H"
#include "RENDER_2/802192C0_3.H"

/* Updates round state, player health and round-start presentation. */

typedef struct Shared_func_80227014_S1 func_80227014_S1;

typedef struct Shared_func_80227014_S2 func_80227014_S2;

typedef struct Shared_func_80227014_S3 func_80227014_S3;

typedef struct Shared_func_80227014_S5 SharedRecV6;

typedef struct Shared_func_80227014_S6 func_80227014_S6;

typedef struct Shared_func_80227014_S7 SharedRecAt18;

typedef struct Shared_func_80227014_S8 func_80227014_S8;

typedef struct Shared_func_80227014_S9 SharedRecAt564V3;

typedef struct Shared_func_80227014_S10 func_80227014_S10;

typedef struct Shared_func_80227014_S11 func_80227014_S11;

typedef struct Shared_func_80227014_S13 func_80227014_S13;

typedef struct Shared_func_80227014_S14 SharedRecAt564V2;

typedef struct Shared_func_80227014_S10 func_80227014_S15;

typedef struct Shared_func_80227014_S16 func_80227014_S16;

typedef struct Shared_func_80227014_S18 func_80227014_S18;

typedef struct Shared_func_80227014_S19 func_80227014_S19;

typedef struct Shared_func_80227014_S20 SharedRecAt564V4;

typedef struct Shared_func_80227014_S10 func_80227014_S21;

typedef struct Shared_func_80227014_S22 func_80227014_S22;


void func_80218464_de(void *);

void Weapons_InitializePlayerHealth(void *);

s32 func_802281F0_de(void *);

void * func_8022A5F4_de(void *, u32);

void * func_8022C55C_de(void *, u32);









 /* extern */
/* Provider passes the position identity as a 32-bit address; see func_8025DE54_de
 * and the published func_80230630_de caller. */













/* Advances an elimination round when rule D_80146918 is on and not paused (func_80245784_de,
   func_80245798_de): counts the players still in, clears D_800F7D10 while one is waiting, then by the
   round state at 0x84 of D_801468A0 revives the first waiting player (crediting a point in state 1,
   scheduling D_80146924 = 3 otherwise) or moves to state 2, and ends the round through func_8022A748_de
   when func_802282EC_de reports it over. */


extern s32 D_801427FC;



s32 func_802282EC_de(Round *arg0);



extern u8 D_801462D5; /* MIXED func_80227038_de */
extern u8 D_801462DE; /* MIXED func_80227038_de */
void func_80227038_de(s8 *world) {
    CGameStatus *initial_rules; 
    CGameStatus *select_rules; 
    CGameStatus *case2_rules; 
    CGameStatus *case3_entry; 
    CGameStatus *case3_loop; 
    CGameStatus *case4_entry; 
    CGameStatus *case6_entry; 
    CGameStatus *case4_loop; 
    CGameStatus *case6_active_rules; 
    CGameStatus *rules;
    u32 state;
    s32 var_a0;
    s32 var_a0_3;
    s32 var_a0_5;
    s32 var_a0_7;
    f32 scaled6x;
    f32 scaled6y;
    f32 scaled5x;
    f32 scaled5y;
    f32 scaled_x4;
    f32 scaled_y4;
    f32 scaled_x;
    f32 scaled_y;
    f32 banner_half;
    f32 banner_size;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 temp_f2_7;
    f32 temp_f2_8;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f3_3;
    f32 temp_f3_4;
    f32 temp_f3_5;
    f32 temp_f3_6;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_s1;
    s32 temp_v0;
    s32 temp_v0_10;
    s32 temp_v0_2; /* Reused for each initialized rule and actor-kind result in the health loops. */
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 var_v1;
    s8 temp_v0_7;
    s8 temp_v0_9;
    s8 temp_v1_2;
    s8 temp_v1_5;
    s32 var_s2;
    func_80227014_S11 *temp_a1;
    func_80227014_S16 *temp_a1_2;
    SharedRecAt564V1 *temp_s1_2;
    SharedRecAt564V3 *temp_s1_3;
    SharedRecAt564V2 *temp_s1_4;
    SharedRecAt564V4 *temp_s1_5;
    func_80227014_S18 *temp_v0_11;
    func_80227014_S2 *player;
    func_80227014_S8 *temp_v0_6;
    func_80227014_S13 *temp_v0_8;
    func_80227014_S3 *temp_v1;
    func_80227014_S19 *temp_v1_3;
    func_80227014_S22 *temp_v1_4;

    if ((func_80245784_de() == 0) && (func_80245798_de() == 0) && ((initial_rules = &D_801462C8.counters)->m_bFragTagOn != 0)) {
        if ((func_802281F0_de(world) != 0) && (initial_rules->elapsed == 0)) {
            func_8022A748_de(world);
            return;
        }
        temp_v0 = func_8022C620_de(world);
        if (temp_v0 > 0) {
            state = D_80146914;
            switch (state) {
            case 0:
            default:
                func_8022C5AC_de(world);
                func_8022C5DC_de(world);
                D_80146914 = 1;
                return;
            case 1:
                func_8022C5DC_de(world);
                if (temp_v0 > 0) {
                    temp_s1 = (select_rules = &D_801462C8.counters)->m_FragTagSelectionType;
                    if (temp_s1 == 3) {
                        temp_v0_2 = Nav_NextRandom();
                        temp_v0_3 = temp_v0_2 / temp_v0;
                        if (temp_v0 == 0) {

                        }
                        if ((temp_v0 == -1) && (temp_v0_3 == 0x80000000)) {

                        }
                        var_v1 = temp_v0_2 % temp_v0;
                        select_rules->unk74 = temp_s1;
                        select_rules->unk60 = var_v1;
                        select_rules->unk5C = var_v1;
                        return;
                    } else {
                        temp_v0_4 = select_rules->unk60 + 1;
                        if (temp_v0 == 0) {

                        }
                        if ((temp_v0 == -1) && ((temp_v0_4 / temp_v0) == 0x80000000)) {

                        }
                        var_v1 = temp_v0_4 % temp_v0;
                        select_rules->unk74 = 4;
                        select_rules->unk60 = var_v1;
                        select_rules->unk5C = var_v1;
                        return;
                    }
                }
                goto state_end;
            case 2:
                if (temp_v0 > 0) {
                    (case2_rules = &D_801462C8.counters)->unk74 = 5;
                    case2_rules->restrictionActive = 0xE1;
                    case2_rules->unk5C = (s32) case2_rules->unk60;
                }
                func_8022C5DC_de(world);
                return;
            case 5:                                 /* switch 1 */
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    banner_half = D_800C2BA0_de;
                    banner_size = D_800C2BA4_de;
                    do {
                        player = func_8022A5F4_de(world, var_s2);
                        if (player != 0) {
                            temp_v1 = player->unk5D8;
                            if (temp_v1->unk90 == 0) {
                                temp_s1_2 = player->unk5DC;
                                if ((temp_s1_2 != 0) && (temp_s1_2->unk564 == 0)) {
                                    func_802A9234_de((s32) D_801462DE);
                                    temp_f2 = temp_s1_2->unk29C;
                                    temp_f3 = temp_s1_2->unk2A0;
                                    scaled5x = temp_f2 * banner_half;
                                    scaled5y = temp_f3 * banner_half;
                                    temp_f2_2 = temp_f2 / (f32) D_800E28D0;
                                    temp_f3_2 = temp_f3 / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_2->unk2A4 + scaled5x) - (temp_f2_2 * banner_size)), (s16) (s32) ((temp_s1_2->unk2A8 + scaled5y) - (temp_f3_2 * banner_size)), temp_f2_2, temp_f3_2, 1);
                                }
                                player->unk5D8->unk8F = 1;
                                switch (D_80142850) {
                                case 0:
                                    Render_PlaySoundAtPosition(0x18A1, player->position, (s32)&player->position, -1);
                                    break;
                                case 1:
                                    Render_PlaySoundAtPosition(0x1969, player->position, (s32)&player->position, -1);
                                    break;
                                case 2:
                                    Render_PlaySoundAtPosition(0x1905, player->position, (s32)&player->position, -1);
                                    break;
                                }
                                func_80218464_de(&player->unk938);
                                player->unk11B4 = 0;
                                Weapons_RequestActorState(&player->unk2E8, &player->unk458, 1);
                                Render_PlacePlayerAtSpawnPoint(player, player->unk5EC, 0, 1);
                                Weapons_InitializePlayerHealth(player);
                                player->unk5E4 = (s32) D_8014284C;
                            } else {
                                if ((D_80146938 != 0) && (temp_v1->unk94 != 0)) {
                                    temp_v1_2 = temp_v1->unk80;
                                    if (temp_v1_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v1_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = player->unk18->unk18 << 8;
                                    }
                                } else {
                                    var_a0 = player->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (player->unk1450 == 0)) {
                                    var_a0 += D_800FEB10[player->unk5D4].value;
                                }
                                player->unk5E4 = var_a0;
                                player->unk174 = var_a0;
                            }
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= (s32) var_s2);
                }
                func_8022C5AC_de(world);
                D_80146914 = 6;
                return;
            case 3:
                case3_entry = &D_801462C8.counters;
                if (temp_v0 == 0) {

                }
                if ((temp_v0 == -1) && (((s32) case3_entry->unk5C / temp_v0) == 0x80000000)) {

                }
                case3_entry->restrictionActive = 0;
                temp_v0_6 = func_8022C55C_de(world, (u32) ((s32) case3_entry->unk5C % temp_v0));
                temp_s1_3 = temp_v0_6->unk5DC;
                if ((temp_s1_3 != 0) && (temp_s1_3->unk564 == 0)) {
                    func_802A9234_de((s32) D_801462DE);
                    temp_f3_3 = temp_s1_3->unk29C;
                    temp_f2_3 = temp_s1_3->unk2A0;
                    scaled_x = temp_f3_3 * D_800C2BA8_de;
                    scaled_y = temp_f2_3 * D_800C2BA8_de;
                    temp_f2_4 = temp_f2_3 / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_3->unk2A4 + scaled_x) - ((temp_f3_3 / (f32) D_800E28D0) * D_800C2BAC_de)), (s16) (s32) ((temp_s1_3->unk2A8 + scaled_y) - (temp_f2_4 * D_800C2BAC_de)), (temp_f3_3 / (f32) D_800E28D0), temp_f2_4, 1);
                }
                rules = &D_801462C8.counters;
                temp_a0 = rules->unk5C + 1;
                rules->unk5C = temp_a0;
                if (temp_a0 >= (((5 - temp_v0) * 0x14) - rules->unk60)) {
                    func_8022C5AC_de(world);
                    rules->unk74 = 7;
                    temp_v0_6->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        Render_PlaySoundAtPosition(0x18A1, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    case 1:
                        Render_PlaySoundAtPosition(0x1969, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    case 2:
                        Render_PlaySoundAtPosition(0x1905, temp_v0_6->position, (s32)&temp_v0_6->position, -1);
                        break;
                    }
                    func_80218464_de(&temp_v0_6->unk938);
                    temp_v0_6->unk11B4 = 0;
                    Weapons_RequestActorState(&temp_v0_6->unk2E8, &temp_v0_6->unk458, 1);
                    Render_PlacePlayerAtSpawnPoint(temp_v0_6, temp_v0_6->unk5EC, 0, 1);
                    Weapons_InitializePlayerHealth(temp_v0_6);
                }
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    temp_a1 = temp_v0_6->unk5D8;
                    case3_loop = &D_801462C8.counters;
                    do {
                        if (temp_a1->unk8F != 0) {
                            temp_v0_6->unk5E4 = (s32) case3_loop->mask;
                        } else {
                            temp_v0_2 = D_80146938;
                            if ((temp_v0_2 != 0) && (temp_a1->unk94 != 0)) {
                                temp_v0_2 = temp_a1->unk80;
                                if (temp_v0_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v0_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_6->unk18->unk18 << 8;
                                    }
                            } else {
                                var_a0 = temp_v0_6->unk18->unk18 << 8;
                            }
                            temp_v0_2 = D_801462D5;
                            if ((temp_v0_2 == 1) && (temp_v0_6->unk1450 == 0)) {
                                var_a0 += D_800FEB10[temp_v0_6->unk5D4].value;
                            }
                            temp_v0_6->unk5E4 = var_a0;
                            temp_v0_6->unk174 = var_a0;
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= var_s2);
                    return;
                }
                goto state_end;
            case 4:
                case4_entry = &D_801462C8.counters;
                if (temp_v0 == 0) {

                }
                if ((temp_v0 == -1) && (((s32) case4_entry->unk5C / temp_v0) == 0x80000000)) {

                }
                case4_entry->restrictionActive = 0;
                temp_v0_8 = func_8022C55C_de(world, (u32) ((s32) case4_entry->unk5C % temp_v0));
                temp_s1_4 = temp_v0_8->unk5DC;
                if ((temp_s1_4 != 0) && (temp_s1_4->unk564 == 0)) {
                    func_802A9234_de((s32) D_801462DE);
                    temp_f3_4 = temp_s1_4->unk29C;
                    temp_f2_5 = temp_s1_4->unk2A0;
                    scaled_x4 = temp_f3_4 * D_800C2BB0_de;
                    scaled_y4 = temp_f2_5 * D_800C2BB0_de;
                    temp_f2_6 = temp_f2_5 / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_4->unk2A4 + scaled_x4) - ((temp_f3_4 / (f32) D_800E28D0) * D_800C2BB4_de)), (s16) (s32) ((temp_s1_4->unk2A8 + scaled_y4) - (temp_f2_6 * D_800C2BB4_de)), (temp_f3_4 / (f32) D_800E28D0), temp_f2_6, 1);
                }
                rules = &D_801462C8.counters;
                temp_a0_2 = rules->unk5C + 1;
                rules->unk5C = temp_a0_2;
                if (temp_a0_2 >= (((5 - temp_v0) * 0x14) - rules->unk60)) {
                    func_8022C5AC_de(world);
                    rules->unk74 = 7;
                    temp_v0_8->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        Render_PlaySoundAtPosition(0x18A1, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    case 1:
                        Render_PlaySoundAtPosition(0x1969, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    case 2:
                        Render_PlaySoundAtPosition(0x1905, temp_v0_8->position, (s32)&temp_v0_8->position, -1);
                        break;
                    }
                    func_80218464_de(&temp_v0_8->unk938);
                    temp_v0_8->unk11B4 = 0;
                    Weapons_RequestActorState(&temp_v0_8->unk2E8, &temp_v0_8->unk458, 1);
                    Render_PlacePlayerAtSpawnPoint(temp_v0_8, temp_v0_8->unk5EC, 0, 1);
                    Weapons_InitializePlayerHealth(temp_v0_8);
                }
                var_s2 = 0;
                if (temp_v0 >= 0) {
                    temp_a1_2 = temp_v0_8->unk5D8;
                    case4_loop = &D_801462C8.counters;
                    do {
                        if (temp_a1_2->unk8F != 0) {
                            temp_v0_8->unk5E4 = (s32) case4_loop->mask;
                        } else {
                            temp_v0_2 = D_80146938;
                            if ((temp_v0_2 != 0) && (temp_a1_2->unk94 != 0)) {
                                temp_v0_2 = temp_a1_2->unk80;
                                if (temp_v0_2 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v0_2 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v0_2 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_8->unk18->unk18 << 8;
                                    }
                            } else {
                                var_a0 = temp_v0_8->unk18->unk18 << 8;
                            }
                            temp_v0_2 = D_801462D5;
                            if ((temp_v0_2 == 1) && (temp_v0_8->unk1450 == 0)) {
                                var_a0 += D_800FEB10[temp_v0_8->unk5D4].value;
                            }
                            temp_v0_8->unk5E4 = var_a0;
                            temp_v0_8->unk174 = var_a0;
                        }
                        var_s2 += 1;
                    } while (temp_v0 >= var_s2);
                    return;
                }
                goto state_end;
            case 6:
                case6_entry = &D_801462C8.counters;
                temp_v0_10 = case6_entry->restrictionActive - 1;
                case6_entry->restrictionActive = temp_v0_10;
                if (temp_v0_10 <= 0) {
                    case6_entry->restrictionActive = 0;
                    if (D_800C91B8_de != 0) {
                        func_8025E2D4_de(D_800C91B8_de);
                    }
                    var_s2 = 0;
                    banner_half = D_800C2BB8_de;
                    banner_size = D_800C2BBC_de;
                    do {
                        temp_v0_11 = func_8022A5F4_de(world, var_s2);
                        if (temp_v0_11 != 0) {
                            temp_v1_3 = temp_v0_11->unk5D8;
                            if (temp_v1_3->unk8F == 0) {
                                temp_s1_5 = temp_v0_11->unk5DC;
                                if ((temp_s1_5 != 0) && (temp_s1_5->unk564 == 0)) {
                                    func_802A9234_de((s32) D_801462DE);
                                    temp_f2_7 = temp_s1_5->unk29C;
                                    temp_f3_5 = temp_s1_5->unk2A0;
                                    scaled6x = temp_f2_7 * banner_half;
                                    scaled6y = temp_f3_5 * banner_half;
                                    temp_f2_8 = temp_f2_7 / (f32) D_800E28D0;
                                    temp_f3_6 = temp_f3_5 / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((temp_s1_5->unk2A4 + scaled6x) - (temp_f2_8 * banner_size)), (s16) (s32) ((temp_s1_5->unk2A8 + scaled6y) - (temp_f3_6 * banner_size)), temp_f2_8, temp_f3_6, 1);
                                }
                                temp_v0_11->unk5D8->unk8F = 1U;
                                switch (D_80142850) {
                                case 0:
                                    Render_PlaySoundAtPosition(0x18A1, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                case 1:
                                    Render_PlaySoundAtPosition(0x1969, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                case 2:
                                    Render_PlaySoundAtPosition(0x1905, temp_v0_11->position, (s32)&temp_v0_11->position, -1);
                                    break;
                                }
                                func_80218464_de(&temp_v0_11->unk938);
                                temp_v0_11->unk11B4 = 0;
                                Weapons_RequestActorState(&temp_v0_11->unk2E8, &temp_v0_11->unk458, 1);
                                Render_PlacePlayerAtSpawnPoint(temp_v0_11, temp_v0_11->unk5EC, 0, 1);
                                Weapons_InitializePlayerHealth(temp_v0_11);
                            } else {
                                temp_v1_3->unk90 = 0;
                                temp_v0_11->unk5D8->unk8F = 0U;
                                Render_PlacePlayerAtSpawnPoint(temp_v0_11, temp_v0_11->unk5EC, 0, 1);
                            }
                            temp_v1_4 = temp_v0_11->unk5D8;
                            if (temp_v1_4->unk8F != 0) {
                                case6_active_rules = &D_801462C8.counters;
                                temp_v0_11->unk5E4 = (s32) case6_active_rules->mask;
                                temp_v0_11->unk174 = (s32) case6_active_rules->mask;
                            } else {
                                if ((D_80146938 != 0) && (temp_v1_4->unk94 != 0)) {
                                    temp_v1_5 = temp_v1_4->unk80;
                                    if (temp_v1_5 == 11) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_5 == 12) {
                                    var_a0 = 0x19000;
                                    } else if (temp_v1_5 == 14) {
                                    var_a0 = 0x12C00;
                                    } else if (temp_v1_5 == 13) {
                                    var_a0 = 0x12C00;
                                    } else {
                                        var_a0 = temp_v0_11->unk18->unk18 << 8;
                                    }
                                } else {
                                    var_a0 = temp_v0_11->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (temp_v0_11->unk1450 == 0)) {
                                    var_a0 += D_800FEB10[temp_v0_11->unk5D4].value;
                                }
                                temp_v0_11->unk5E4 = var_a0;
                                temp_v0_11->unk174 = var_a0;
                            }
                        }
                        var_s2 += 1;
                    } while ((s32) var_s2 < 8);
                    D_80146914 = 7;
                    return;
                }
                goto state_end;
            case 7:
                D_80142848 = 0;
                goto state_end;
            }
state_end:;
        }
    }
}

static inline void Weapons_CountRelease(s16 *counter) {
    (*counter)++;
}
static inline s32 Weapons_CountPlayersIn(Round *round) {
    ActorNode *node;
    s32 count = 0;
    for (node = round->players; node != 0; node = node->next) {
        if (node->scores->unk90 == 0) {
            count += 1;
        }
    }
    return count;
}
static inline ActorNode *Weapons_FindWaitingPlayer(Round *round) {
    ActorNode *node;
    for (node = round->players; node != 0; node = node->next) {
        if ((node->scores->unk8F == 1) || (node->scores->unk90 == 1)) {
            break;
        }
    }
    return node;
}
void Weapons_ReleaseWaitingPlayer(Round *round) {
    s32 count;
    ActorNode *node;
    CGameStatus *state;
    s32 waiting;
    if ((D_80146918 != 0) && (func_80245784_de() == 0) && (func_80245798_de() == 0)) {
        count = Weapons_CountPlayersIn(round);
        if (count > 0) {
            waiting = Weapons_FindWaitingPlayer(round) != 0;
            if (waiting) {
                D_800F7D10 = 0;
            }
            state = &D_801462C8.counters;
            switch (state->unk84) {
            case 0:
            default:
                if (count > 0) {
                    node = Weapons_FindWaitingPlayer(round);
                    if (node != 0) {
                        node->scores->unk90 = 0;
                        D_80146924 = 3;
                    }
                } else {
                    state->unk84 = 2;
                }
                break;
            case 1:
                state->unk84 = 2;
                node = Weapons_FindWaitingPlayer(round);
                if (node != 0) {
                    node->scores->unk90 = 0;
                    Weapons_CountRelease(&node->scores->score);
                    D_800F7D10 = 0;
                }
                break;
            case 2:
            case 3:
                break;
            }
            if ((func_802282EC_de(round) != 0) && (D_801427FC == 0)) {
                func_8022A748_de(round);
            }
        }
    }
}

/* The round settings and counters, read through fresh getters so each block rebuilds the address. */
static inline Shared_Game *currentGame(void) {
    return &D_801462C8;
}
static inline CGameStatus *gameStatus(void) {
    return &D_801462C8.counters;
}
/* Returns 1 when a team (team rounds) or a player has reached the score limit. With a controller
   mode set, humanWon records whether the human team or a human player got there; in mode 1 a
   computer winner does not end the round. */
s32 Weapons_CheckScoreLimit(Round *round) {
    Shared_Game *game;
    ActorNode *player;
    u32 team, i;
    u32 slot;
    u8 mode;
    if (func_80245784_de() || func_80245798_de()
#if !defined(VERSION_US)
        || gameStatus()->mode == 0
#endif
    ) {
        return 0;
    }
    if (gameStatus()->teams != 0) {
#if defined(VERSION_US)
        if (gameStatus()->mode == 0) {
            return 0;
        }
#endif
        team = 0xFF;
        game = currentGame();
        if (game->controllerMode != 0) {
            slot = 0;
            while (game->slots[slot].enabled == 0) {
                slot++;
            }
            team = D_801462C8.slots[slot].team;
        }
        for (i = 0; (s32)i < 5; i++) {
            if (gameStatus()->mode <= gameStatus()->scores[i]) {
                mode = currentGame()->controllerMode;
                if (mode == 0) {
                    return 1;
                }
                if (i == team) {
                    gameStatus()->humanWon = 1;
                    return 1;
                }
                gameStatus()->humanWon = 0;
                if (mode != 1) {
                    return 1;
                }
            }
        }
    } else {
        for (player = round->players; player != 0; player = player->next) {
            if (gameStatus()->mode <= player->scores->score) {
                mode = currentGame()->controllerMode;
                if (mode != 0) {
                    if (player->kind < 4) {
                        gameStatus()->humanWon = 1;
                        return 1;
                    }
                    gameStatus()->humanWon = 0;
                    if (mode == 1) {
                        continue;
                    }
                }
                return 1;
            }
        }
    }
    return 0;
}
