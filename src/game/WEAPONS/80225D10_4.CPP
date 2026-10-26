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
extern void Weapons_EndRound(void *);
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

s32 Weapons_CheckTotalScoreWin(void *);

void * Weapons_GetPlayerByIndex(void *, u32);

void * func_8022C55C_de(void *, u32);









 /* extern */
/* Provider passes the position identity as a 32-bit address; see func_8025DE54_de
 * and the published Weapon_UpdateIdleWeaponSelection caller. */













/* Advances an elimination round when rule D_80146918 is on and not paused (Camera_IsSequenceActive,
   Camera_IsSequenceInWindow): counts the players still in, clears D_800F7D10 while one is waiting, then by the
   round state at 0x84 of D_801468A0 revives the first waiting player (crediting a point in state 1,
   scheduling D_80146924 = 3 otherwise) or moves to state 2, and ends the round through Weapons_EndRound
   when func_802282EC_de reports it over. */





s32 Weapons_CheckTeamPointWin(Round *arg0);



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
    s32 restoredHealth;
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
    f32 allPlayersViewWidth;
    f32 allPlayersScaleX;
    f32 rotatingViewHeight;
    f32 rotatingScaleY;
    f32 chosenViewHeight;
    f32 chosenScaleY;
    f32 flippedViewWidth;
    f32 flippedScaleX;
    f32 allPlayersViewHeight;
    f32 allPlayersScaleY;
    f32 rotatingViewWidth;
    f32 chosenViewWidth;
    f32 flippedViewHeight;
    f32 flippedScaleY;
    s32 nextRotatingPosition;
    s32 nextChosenPosition;
    s32 selectionMode;
    s32 eligiblePlayerCount;
    s32 remainingFlipTicks;
    s32 ruleOrRandomValue; /* Reused for each initialized rule and actor-kind result in the health loops. */
    s32 randomPlayerQuotient;
    s32 nextChosenIndex;
    s32 selectedPlayerIndex;
    s8 temp_v0_7;
    s8 temp_v0_9;
    s8 initialCharacter;
    s8 flippedCharacter;
    s32 playerIndex;
    func_80227014_S11 *rotatingPlayerProfile;
    func_80227014_S16 *chosenPlayerProfile;
    SharedRecAt564V1 *allPlayersView;
    SharedRecAt564V3 *rotatingView;
    SharedRecAt564V2 *chosenView;
    SharedRecAt564V4 *flippedView;
    func_80227014_S18 *flippedPlayer;
    func_80227014_S2 *player;
    func_80227014_S8 *rotatingPlayer;
    func_80227014_S13 *chosenPlayer;
    func_80227014_S3 *playerProfile;
    func_80227014_S19 *priorFlipProfile;
    func_80227014_S22 *flippedProfile;

    if ((Camera_IsSequenceActive() == 0) && (Camera_IsSequenceInWindow() == 0) && ((initial_rules = &D_801462C8.counters)->m_bFragTagOn != 0)) {
        if ((Weapons_CheckTotalScoreWin(world) != 0) && (initial_rules->elapsed == 0)) {
            Weapons_EndRound(world);
            return;
        }
        eligiblePlayerCount = func_8022C620_de(world);
        if (eligiblePlayerCount > 0) {
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
                if (eligiblePlayerCount > 0) {
                    selectionMode = (select_rules = &D_801462C8.counters)->m_FragTagSelectionType;
                    if (selectionMode == 3) {
                        ruleOrRandomValue = Nav_NextRandom();
                        randomPlayerQuotient = ruleOrRandomValue / eligiblePlayerCount;
                        if (eligiblePlayerCount == 0) {

                        }
                        if ((eligiblePlayerCount == -1) && (randomPlayerQuotient == 0x80000000)) {

                        }
                        selectedPlayerIndex = ruleOrRandomValue % eligiblePlayerCount;
                        select_rules->m_FragTagMode = selectionMode;
                        select_rules->m_FragTagPlayerChosen = selectedPlayerIndex;
                        select_rules->m_FragTagPlayerPos = selectedPlayerIndex;
                        return;
                    } else {
                        nextChosenIndex = select_rules->m_FragTagPlayerChosen + 1;
                        if (eligiblePlayerCount == 0) {

                        }
                        if ((eligiblePlayerCount == -1) && ((nextChosenIndex / eligiblePlayerCount) == 0x80000000)) {

                        }
                        selectedPlayerIndex = nextChosenIndex % eligiblePlayerCount;
                        select_rules->m_FragTagMode = 4;
                        select_rules->m_FragTagPlayerChosen = selectedPlayerIndex;
                        select_rules->m_FragTagPlayerPos = selectedPlayerIndex;
                        return;
                    }
                }
                goto state_end;
            case 2:
                if (eligiblePlayerCount > 0) {
                    (case2_rules = &D_801462C8.counters)->m_FragTagMode = 5;
                    case2_rules->m_FragTagFlipTimer = 0xE1;
                    case2_rules->m_FragTagPlayerPos = (s32) case2_rules->m_FragTagPlayerChosen;
                }
                func_8022C5DC_de(world);
                return;
            case 5:                                 /* switch 1 */
                playerIndex = 0;
                if (eligiblePlayerCount >= 0) {
                    banner_half = D_800C2BA0_de;
                    banner_size = D_800C2BA4_de;
                    do {
                        player = Weapons_GetPlayerByIndex(world, playerIndex);
                        if (player != 0) {
                            playerProfile = player->unk5D8;
                            if (playerProfile->unk90 == 0) {
                                allPlayersView = player->unk5DC;
                                if ((allPlayersView != 0) && (allPlayersView->unk564 == 0)) {
                                    Text_SetupSpriteMode((s32) D_801462DE);
                                    allPlayersViewWidth = allPlayersView->unk29C;
                                    allPlayersViewHeight = allPlayersView->unk2A0;
                                    scaled5x = allPlayersViewWidth * banner_half;
                                    scaled5y = allPlayersViewHeight * banner_half;
                                    allPlayersScaleX = allPlayersViewWidth / (f32) D_800E28D0;
                                    allPlayersScaleY = allPlayersViewHeight / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((allPlayersView->unk2A4 + scaled5x) - (allPlayersScaleX * banner_size)), (s16) (s32) ((allPlayersView->unk2A8 + scaled5y) - (allPlayersScaleY * banner_size)), allPlayersScaleX, allPlayersScaleY, 1);
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
                                if ((D_80146938 != 0) && (playerProfile->unk94 != 0)) {
                                    initialCharacter = playerProfile->unk80;
                                    if (initialCharacter == 11) {
                                    restoredHealth = 0x19000;
                                    } else if (initialCharacter == 12) {
                                    restoredHealth = 0x19000;
                                    } else if (initialCharacter == 14) {
                                    restoredHealth = 0x12C00;
                                    } else if (initialCharacter == 13) {
                                    restoredHealth = 0x12C00;
                                    } else {
                                        restoredHealth = player->unk18->unk18 << 8;
                                    }
                                } else {
                                    restoredHealth = player->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (player->unk1450 == 0)) {
                                    restoredHealth += D_800FEB10[player->unk5D4].value;
                                }
                                player->unk5E4 = restoredHealth;
                                player->unk174 = restoredHealth;
                            }
                        }
                        playerIndex += 1;
                    } while (eligiblePlayerCount >= (s32) playerIndex);
                }
                func_8022C5AC_de(world);
                D_80146914 = 6;
                return;
            case 3:
                case3_entry = &D_801462C8.counters;
                if (eligiblePlayerCount == 0) {

                }
                if ((eligiblePlayerCount == -1) && (((s32) case3_entry->m_FragTagPlayerPos / eligiblePlayerCount) == 0x80000000)) {

                }
                case3_entry->m_FragTagFlipTimer = 0;
                rotatingPlayer = func_8022C55C_de(world, (u32) ((s32) case3_entry->m_FragTagPlayerPos % eligiblePlayerCount));
                rotatingView = rotatingPlayer->unk5DC;
                if ((rotatingView != 0) && (rotatingView->unk564 == 0)) {
                    Text_SetupSpriteMode((s32) D_801462DE);
                    rotatingViewWidth = rotatingView->unk29C;
                    rotatingViewHeight = rotatingView->unk2A0;
                    scaled_x = rotatingViewWidth * D_800C2BA8_de;
                    scaled_y = rotatingViewHeight * D_800C2BA8_de;
                    rotatingScaleY = rotatingViewHeight / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((rotatingView->unk2A4 + scaled_x) - ((rotatingViewWidth / (f32) D_800E28D0) * D_800C2BAC_de)), (s16) (s32) ((rotatingView->unk2A8 + scaled_y) - (rotatingScaleY * D_800C2BAC_de)), (rotatingViewWidth / (f32) D_800E28D0), rotatingScaleY, 1);
                }
                rules = &D_801462C8.counters;
                nextRotatingPosition = rules->m_FragTagPlayerPos + 1;
                rules->m_FragTagPlayerPos = nextRotatingPosition;
                if (nextRotatingPosition >= (((5 - eligiblePlayerCount) * 0x14) - rules->m_FragTagPlayerChosen)) {
                    func_8022C5AC_de(world);
                    rules->m_FragTagMode = 7;
                    rotatingPlayer->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        Render_PlaySoundAtPosition(0x18A1, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    case 1:
                        Render_PlaySoundAtPosition(0x1969, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    case 2:
                        Render_PlaySoundAtPosition(0x1905, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    }
                    func_80218464_de(&rotatingPlayer->unk938);
                    rotatingPlayer->unk11B4 = 0;
                    Weapons_RequestActorState(&rotatingPlayer->unk2E8, &rotatingPlayer->unk458, 1);
                    Render_PlacePlayerAtSpawnPoint(rotatingPlayer, rotatingPlayer->unk5EC, 0, 1);
                    Weapons_InitializePlayerHealth(rotatingPlayer);
                }
                playerIndex = 0;
                if (eligiblePlayerCount >= 0) {
                    rotatingPlayerProfile = rotatingPlayer->unk5D8;
                    case3_loop = &D_801462C8.counters;
                    do {
                        if (rotatingPlayerProfile->unk8F != 0) {
                            rotatingPlayer->unk5E4 = (s32) case3_loop->mask;
                        } else {
                            ruleOrRandomValue = D_80146938;
                            if ((ruleOrRandomValue != 0) && (rotatingPlayerProfile->unk94 != 0)) {
                                ruleOrRandomValue = rotatingPlayerProfile->unk80;
                                if (ruleOrRandomValue == 11) {
                                    restoredHealth = 0x19000;
                                    } else if (ruleOrRandomValue == 12) {
                                    restoredHealth = 0x19000;
                                    } else if (ruleOrRandomValue == 14) {
                                    restoredHealth = 0x12C00;
                                    } else if (ruleOrRandomValue == 13) {
                                    restoredHealth = 0x12C00;
                                    } else {
                                        restoredHealth = rotatingPlayer->unk18->unk18 << 8;
                                    }
                            } else {
                                restoredHealth = rotatingPlayer->unk18->unk18 << 8;
                            }
                            ruleOrRandomValue = D_801462D5;
                            if ((ruleOrRandomValue == 1) && (rotatingPlayer->unk1450 == 0)) {
                                restoredHealth += D_800FEB10[rotatingPlayer->unk5D4].value;
                            }
                            rotatingPlayer->unk5E4 = restoredHealth;
                            rotatingPlayer->unk174 = restoredHealth;
                        }
                        playerIndex += 1;
                    } while (eligiblePlayerCount >= playerIndex);
                    return;
                }
                goto state_end;
            case 4:
                case4_entry = &D_801462C8.counters;
                if (eligiblePlayerCount == 0) {

                }
                if ((eligiblePlayerCount == -1) && (((s32) case4_entry->m_FragTagPlayerPos / eligiblePlayerCount) == 0x80000000)) {

                }
                case4_entry->m_FragTagFlipTimer = 0;
                chosenPlayer = func_8022C55C_de(world, (u32) ((s32) case4_entry->m_FragTagPlayerPos % eligiblePlayerCount));
                chosenView = chosenPlayer->unk5DC;
                if ((chosenView != 0) && (chosenView->unk564 == 0)) {
                    Text_SetupSpriteMode((s32) D_801462DE);
                    chosenViewWidth = chosenView->unk29C;
                    chosenViewHeight = chosenView->unk2A0;
                    scaled_x4 = chosenViewWidth * D_800C2BB0_de;
                    scaled_y4 = chosenViewHeight * D_800C2BB0_de;
                    chosenScaleY = chosenViewHeight / (f32) D_800E28D4;
                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((chosenView->unk2A4 + scaled_x4) - ((chosenViewWidth / (f32) D_800E28D0) * D_800C2BB4_de)), (s16) (s32) ((chosenView->unk2A8 + scaled_y4) - (chosenScaleY * D_800C2BB4_de)), (chosenViewWidth / (f32) D_800E28D0), chosenScaleY, 1);
                }
                rules = &D_801462C8.counters;
                nextChosenPosition = rules->m_FragTagPlayerPos + 1;
                rules->m_FragTagPlayerPos = nextChosenPosition;
                if (nextChosenPosition >= (((5 - eligiblePlayerCount) * 0x14) - rules->m_FragTagPlayerChosen)) {
                    func_8022C5AC_de(world);
                    rules->m_FragTagMode = 7;
                    chosenPlayer->unk5D8->unk8F = 1U;
                    switch (D_80142850) {
                    case 0:
                        Render_PlaySoundAtPosition(0x18A1, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    case 1:
                        Render_PlaySoundAtPosition(0x1969, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    case 2:
                        Render_PlaySoundAtPosition(0x1905, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    }
                    func_80218464_de(&chosenPlayer->unk938);
                    chosenPlayer->unk11B4 = 0;
                    Weapons_RequestActorState(&chosenPlayer->unk2E8, &chosenPlayer->unk458, 1);
                    Render_PlacePlayerAtSpawnPoint(chosenPlayer, chosenPlayer->unk5EC, 0, 1);
                    Weapons_InitializePlayerHealth(chosenPlayer);
                }
                playerIndex = 0;
                if (eligiblePlayerCount >= 0) {
                    chosenPlayerProfile = chosenPlayer->unk5D8;
                    case4_loop = &D_801462C8.counters;
                    do {
                        if (chosenPlayerProfile->unk8F != 0) {
                            chosenPlayer->unk5E4 = (s32) case4_loop->mask;
                        } else {
                            ruleOrRandomValue = D_80146938;
                            if ((ruleOrRandomValue != 0) && (chosenPlayerProfile->unk94 != 0)) {
                                ruleOrRandomValue = chosenPlayerProfile->unk80;
                                if (ruleOrRandomValue == 11) {
                                    restoredHealth = 0x19000;
                                    } else if (ruleOrRandomValue == 12) {
                                    restoredHealth = 0x19000;
                                    } else if (ruleOrRandomValue == 14) {
                                    restoredHealth = 0x12C00;
                                    } else if (ruleOrRandomValue == 13) {
                                    restoredHealth = 0x12C00;
                                    } else {
                                        restoredHealth = chosenPlayer->unk18->unk18 << 8;
                                    }
                            } else {
                                restoredHealth = chosenPlayer->unk18->unk18 << 8;
                            }
                            ruleOrRandomValue = D_801462D5;
                            if ((ruleOrRandomValue == 1) && (chosenPlayer->unk1450 == 0)) {
                                restoredHealth += D_800FEB10[chosenPlayer->unk5D4].value;
                            }
                            chosenPlayer->unk5E4 = restoredHealth;
                            chosenPlayer->unk174 = restoredHealth;
                        }
                        playerIndex += 1;
                    } while (eligiblePlayerCount >= playerIndex);
                    return;
                }
                goto state_end;
            case 6:
                case6_entry = &D_801462C8.counters;
                remainingFlipTicks = case6_entry->m_FragTagFlipTimer - 1;
                case6_entry->m_FragTagFlipTimer = remainingFlipTicks;
                if (remainingFlipTicks <= 0) {
                    case6_entry->m_FragTagFlipTimer = 0;
                    if (D_800C91B8_de != 0) {
                        func_8025E2D4_de(D_800C91B8_de);
                    }
                    playerIndex = 0;
                    banner_half = D_800C2BB8_de;
                    banner_size = D_800C2BBC_de;
                    do {
                        flippedPlayer = Weapons_GetPlayerByIndex(world, playerIndex);
                        if (flippedPlayer != 0) {
                            priorFlipProfile = flippedPlayer->unk5D8;
                            if (priorFlipProfile->unk8F == 0) {
                                flippedView = flippedPlayer->unk5DC;
                                if ((flippedView != 0) && (flippedView->unk564 == 0)) {
                                    Text_SetupSpriteMode((s32) D_801462DE);
                                    flippedViewWidth = flippedView->unk29C;
                                    flippedViewHeight = flippedView->unk2A0;
                                    scaled6x = flippedViewWidth * banner_half;
                                    scaled6y = flippedViewHeight * banner_half;
                                    flippedScaleX = flippedViewWidth / (f32) D_800E28D0;
                                    flippedScaleY = flippedViewHeight / (f32) D_800E28D4;
                                    func_802AAC28_de(0x1FB, 0, (s16) (s32) ((flippedView->unk2A4 + scaled6x) - (flippedScaleX * banner_size)), (s16) (s32) ((flippedView->unk2A8 + scaled6y) - (flippedScaleY * banner_size)), flippedScaleX, flippedScaleY, 1);
                                }
                                flippedPlayer->unk5D8->unk8F = 1U;
                                switch (D_80142850) {
                                case 0:
                                    Render_PlaySoundAtPosition(0x18A1, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                case 1:
                                    Render_PlaySoundAtPosition(0x1969, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                case 2:
                                    Render_PlaySoundAtPosition(0x1905, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                }
                                func_80218464_de(&flippedPlayer->unk938);
                                flippedPlayer->unk11B4 = 0;
                                Weapons_RequestActorState(&flippedPlayer->unk2E8, &flippedPlayer->unk458, 1);
                                Render_PlacePlayerAtSpawnPoint(flippedPlayer, flippedPlayer->unk5EC, 0, 1);
                                Weapons_InitializePlayerHealth(flippedPlayer);
                            } else {
                                priorFlipProfile->unk90 = 0;
                                flippedPlayer->unk5D8->unk8F = 0U;
                                Render_PlacePlayerAtSpawnPoint(flippedPlayer, flippedPlayer->unk5EC, 0, 1);
                            }
                            flippedProfile = flippedPlayer->unk5D8;
                            if (flippedProfile->unk8F != 0) {
                                case6_active_rules = &D_801462C8.counters;
                                flippedPlayer->unk5E4 = (s32) case6_active_rules->mask;
                                flippedPlayer->unk174 = (s32) case6_active_rules->mask;
                            } else {
                                if ((D_80146938 != 0) && (flippedProfile->unk94 != 0)) {
                                    flippedCharacter = flippedProfile->unk80;
                                    if (flippedCharacter == 11) {
                                    restoredHealth = 0x19000;
                                    } else if (flippedCharacter == 12) {
                                    restoredHealth = 0x19000;
                                    } else if (flippedCharacter == 14) {
                                    restoredHealth = 0x12C00;
                                    } else if (flippedCharacter == 13) {
                                    restoredHealth = 0x12C00;
                                    } else {
                                        restoredHealth = flippedPlayer->unk18->unk18 << 8;
                                    }
                                } else {
                                    restoredHealth = flippedPlayer->unk18->unk18 << 8;
                                }
                                if ((D_801462D5 == 1) && (flippedPlayer->unk1450 == 0)) {
                                    restoredHealth += D_800FEB10[flippedPlayer->unk5D4].value;
                                }
                                flippedPlayer->unk5E4 = restoredHealth;
                                flippedPlayer->unk174 = restoredHealth;
                            }
                        }
                        playerIndex += 1;
                    } while ((s32) playerIndex < 8);
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
    if ((D_801462C8.counters.m_bCTFOn != 0) && (Camera_IsSequenceActive() == 0) && (Camera_IsSequenceInWindow() == 0)) {
        count = Weapons_CountPlayersIn(round);
        if (count > 0) {
            waiting = Weapons_FindWaitingPlayer(round) != 0;
            if (waiting) {
                D_800F7D10 = 0;
            }
            state = &D_801462C8.counters;
            switch (state->m_CTFMode) {
            case 0:
            default:
                if (count > 0) {
                    node = Weapons_FindWaitingPlayer(round);
                    if (node != 0) {
                        node->scores->unk90 = 0;
                        D_801462C8.counters.m_CTFMode = 3;
                    }
                } else {
                    state->m_CTFMode = 2;
                }
                break;
            case 1:
                state->m_CTFMode = 2;
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
            if ((Weapons_CheckTeamPointWin(round) != 0) && (D_801462C8.counters.elapsed == 0)) {
                Weapons_EndRound(round);
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
    if (Camera_IsSequenceActive() || Camera_IsSequenceInWindow()
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
