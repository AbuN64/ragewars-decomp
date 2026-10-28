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
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/SELF.H"
#include "COMMON/VIEWFLAGS.H"
#include "WEAPONS/ACTOR_REQUESTACTORSTATE.H"
#include "RENDER/802192C0_3.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/PARTICLE_LIGHTING.H"
#include "COMMON/WORLD.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/OBJECTLINKSC_2.H"
#include "COMMON/OBJECTLINKS14C.H"
#include "WEAPONS/WEAPONAI_DRAWREDMARKERQUAD.H"
#include "COMMON/GAME_SESSION.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "RENDER/SETN64_GETPACKSECTION.H"
#include "COMMON/TRIPLE.H"
#include "FX/GRAPHU64_NORMALIZEVEC3.H"

extern void Playerai_EndRound(void *);
s32 Player_CheckTotalScoreWin(Root *);
s32 Player_CheckTeamPointWin(struct World *);

/* 80225D10_4.CPP */

/* Updates round state, player health and round-start presentation. */

typedef struct Shared_func_80227014_S2 func_80227014_S2;

typedef struct Shared_func_80227014_S3 func_80227014_S3;

typedef struct Shared_func_80227014_S8 func_80227014_S8;

typedef struct Shared_func_80227014_S9 SharedRecAt564V3;

typedef struct Shared_func_80227014_S11 func_80227014_S11;

typedef struct Shared_func_80227014_S19 func_80227014_S19;

void func_80218464_de(void *);

void Playerai_InitializePlayerHealth(void *);

void * Playerai_GetPlayerByIndex(void *, u32);

void * func_8022C55C_de(void *, u32);

 /* extern */
/* Provider passes the position identity as a 32-bit address; see func_8025DE54_de
 * and the published Weapon_UpdateIdleWeaponSelection caller. */

/* Advances an elimination round when rule D_80146918 is on and not paused (Cinema_IsSequenceActive,
   Cinema_IsSequenceInWindow): counts the players still in, clears D_800F7D10 while one is waiting, then by the
   round state at 0x84 of D_801468A0 revives the first waiting player (crediting a point in state 1,
   scheduling D_80146924 = 3 otherwise) or moves to state 2, and ends the round through Playerai_EndRound
   when func_802282EC_de reports it over. */

extern u8 D_801462D5; /* MIXED Player_UpdateFragTagSelection */
extern u8 D_801462DE; /* MIXED Player_UpdateFragTagSelection */
void Player_UpdateFragTagSelection(s8 *world) {
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
    func_80227014_S11 *chosenPlayerProfile;
    SharedRecAt564V1 *allPlayersView;
    SharedRecAt564V3 *rotatingView;
    SharedRecAt564V3 *chosenView;
    SharedRecAt564V3 *flippedView;
    func_80227014_S8 *flippedPlayer;
    func_80227014_S2 *player;
    func_80227014_S8 *rotatingPlayer;
    func_80227014_S8 *chosenPlayer;
    func_80227014_S3 *playerProfile;
    func_80227014_S19 *priorFlipProfile;
    func_80227014_S11 *flippedProfile;

    if ((Cinema_IsSequenceActive() == 0) && (Cinema_IsSequenceInWindow() == 0) && ((initial_rules = &D_801462C8.counters)->m_bFragTagOn != 0)) {
        if ((Player_CheckTotalScoreWin(world) != 0) && (initial_rules->elapsed == 0)) {
            Playerai_EndRound(world);
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
                        ruleOrRandomValue = Graphu64_NextRandom();
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
                        player = Playerai_GetPlayerByIndex(world, playerIndex);
                        if (player != 0) {
                            playerProfile = player->unk5D8;
                            if (playerProfile->unk90 == 0) {
                                allPlayersView = player->unk5DC;
                                if ((allPlayersView != 0) && (allPlayersView->unk564 == 0)) {
                                    Onscrn_SetupSpriteMode((s32) D_801462DE);
                                    allPlayersViewWidth = allPlayersView->unk29C;
                                    allPlayersViewHeight = allPlayersView->unk2A0;
                                    scaled5x = allPlayersViewWidth * banner_half;
                                    scaled5y = allPlayersViewHeight * banner_half;
                                    allPlayersScaleX = allPlayersViewWidth / (f32) D_800E28D0;
                                    allPlayersScaleY = allPlayersViewHeight / (f32) D_800E28D4;
                                    OnScreen_DrawSpriteResource(0x1FB, 0, (s16) (s32) ((allPlayersView->unk2A4 + scaled5x) - (allPlayersScaleX * banner_size)), (s16) (s32) ((allPlayersView->unk2A8 + scaled5y) - (allPlayersScaleY * banner_size)), allPlayersScaleX, allPlayersScaleY, 1);
                                }
                                player->unk5D8->unk8F = 1;
                                switch (D_80142850) {
                                case 0:
                                    SoundElement_PlaySoundAtPosition(0x18A1, player->position, (s32)&player->position, -1);
                                    break;
                                case 1:
                                    SoundElement_PlaySoundAtPosition(0x1969, player->position, (s32)&player->position, -1);
                                    break;
                                case 2:
                                    SoundElement_PlaySoundAtPosition(0x1905, player->position, (s32)&player->position, -1);
                                    break;
                                }
                                func_80218464_de(&player->unk938);
                                player->unk11B4 = 0;
                                Actor_RequestActorState(&player->unk2E8, &player->unk458, 1);
                                Player_PlacePlayerAtSpawnPoint(player, player->unk5EC, 0, 1);
                                Playerai_InitializePlayerHealth(player);
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
                    Onscrn_SetupSpriteMode((s32) D_801462DE);
                    rotatingViewWidth = rotatingView->unk29C;
                    rotatingViewHeight = rotatingView->unk2A0;
                    scaled_x = rotatingViewWidth * D_800C2BA8_de;
                    scaled_y = rotatingViewHeight * D_800C2BA8_de;
                    rotatingScaleY = rotatingViewHeight / (f32) D_800E28D4;
                    OnScreen_DrawSpriteResource(0x1FB, 0, (s16) (s32) ((rotatingView->unk2A4 + scaled_x) - ((rotatingViewWidth / (f32) D_800E28D0) * D_800C2BAC_de)), (s16) (s32) ((rotatingView->unk2A8 + scaled_y) - (rotatingScaleY * D_800C2BAC_de)), (rotatingViewWidth / (f32) D_800E28D0), rotatingScaleY, 1);
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
                        SoundElement_PlaySoundAtPosition(0x18A1, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    case 1:
                        SoundElement_PlaySoundAtPosition(0x1969, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    case 2:
                        SoundElement_PlaySoundAtPosition(0x1905, rotatingPlayer->position, (s32)&rotatingPlayer->position, -1);
                        break;
                    }
                    func_80218464_de(&rotatingPlayer->unk938);
                    rotatingPlayer->unk11B4 = 0;
                    Actor_RequestActorState(&rotatingPlayer->unk2E8, &rotatingPlayer->unk458, 1);
                    Player_PlacePlayerAtSpawnPoint(rotatingPlayer, rotatingPlayer->unk5EC, 0, 1);
                    Playerai_InitializePlayerHealth(rotatingPlayer);
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
                    Onscrn_SetupSpriteMode((s32) D_801462DE);
                    chosenViewWidth = chosenView->unk29C;
                    chosenViewHeight = chosenView->unk2A0;
                    scaled_x4 = chosenViewWidth * D_800C2BB0_de;
                    scaled_y4 = chosenViewHeight * D_800C2BB0_de;
                    chosenScaleY = chosenViewHeight / (f32) D_800E28D4;
                    OnScreen_DrawSpriteResource(0x1FB, 0, (s16) (s32) ((chosenView->unk2A4 + scaled_x4) - ((chosenViewWidth / (f32) D_800E28D0) * D_800C2BB4_de)), (s16) (s32) ((chosenView->unk2A8 + scaled_y4) - (chosenScaleY * D_800C2BB4_de)), (chosenViewWidth / (f32) D_800E28D0), chosenScaleY, 1);
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
                        SoundElement_PlaySoundAtPosition(0x18A1, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    case 1:
                        SoundElement_PlaySoundAtPosition(0x1969, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    case 2:
                        SoundElement_PlaySoundAtPosition(0x1905, chosenPlayer->position, (s32)&chosenPlayer->position, -1);
                        break;
                    }
                    func_80218464_de(&chosenPlayer->unk938);
                    chosenPlayer->unk11B4 = 0;
                    Actor_RequestActorState(&chosenPlayer->unk2E8, &chosenPlayer->unk458, 1);
                    Player_PlacePlayerAtSpawnPoint(chosenPlayer, chosenPlayer->unk5EC, 0, 1);
                    Playerai_InitializePlayerHealth(chosenPlayer);
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
                        flippedPlayer = Playerai_GetPlayerByIndex(world, playerIndex);
                        if (flippedPlayer != 0) {
                            priorFlipProfile = flippedPlayer->unk5D8;
                            if (priorFlipProfile->unk8F == 0) {
                                flippedView = flippedPlayer->unk5DC;
                                if ((flippedView != 0) && (flippedView->unk564 == 0)) {
                                    Onscrn_SetupSpriteMode((s32) D_801462DE);
                                    flippedViewWidth = flippedView->unk29C;
                                    flippedViewHeight = flippedView->unk2A0;
                                    scaled6x = flippedViewWidth * banner_half;
                                    scaled6y = flippedViewHeight * banner_half;
                                    flippedScaleX = flippedViewWidth / (f32) D_800E28D0;
                                    flippedScaleY = flippedViewHeight / (f32) D_800E28D4;
                                    OnScreen_DrawSpriteResource(0x1FB, 0, (s16) (s32) ((flippedView->unk2A4 + scaled6x) - (flippedScaleX * banner_size)), (s16) (s32) ((flippedView->unk2A8 + scaled6y) - (flippedScaleY * banner_size)), flippedScaleX, flippedScaleY, 1);
                                }
                                flippedPlayer->unk5D8->unk8F = 1U;
                                switch (D_80142850) {
                                case 0:
                                    SoundElement_PlaySoundAtPosition(0x18A1, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                case 1:
                                    SoundElement_PlaySoundAtPosition(0x1969, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                case 2:
                                    SoundElement_PlaySoundAtPosition(0x1905, flippedPlayer->position, (s32)&flippedPlayer->position, -1);
                                    break;
                                }
                                func_80218464_de(&flippedPlayer->unk938);
                                flippedPlayer->unk11B4 = 0;
                                Actor_RequestActorState(&flippedPlayer->unk2E8, &flippedPlayer->unk458, 1);
                                Player_PlacePlayerAtSpawnPoint(flippedPlayer, flippedPlayer->unk5EC, 0, 1);
                                Playerai_InitializePlayerHealth(flippedPlayer);
                            } else {
                                priorFlipProfile->unk90 = 0;
                                flippedPlayer->unk5D8->unk8F = 0U;
                                Player_PlacePlayerAtSpawnPoint(flippedPlayer, flippedPlayer->unk5EC, 0, 1);
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
void Player_ReleaseWaitingPlayer(Round *round) {
    s32 count;
    ActorNode *node;
    CGameStatus *state;
    s32 waiting;
    if ((D_801462C8.counters.m_bCTFOn != 0) && (Cinema_IsSequenceActive() == 0) && (Cinema_IsSequenceInWindow() == 0)) {
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
            if ((Player_CheckTeamPointWin(round) != 0) && (D_801462C8.counters.elapsed == 0)) {
                Playerai_EndRound(round);
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
s32 Player_CheckScoreLimit(Round *round) {
    Shared_Game *game;
    ActorNode *player;
    u32 team, i;
    u32 slot;
    u8 mode;
    if (Cinema_IsSequenceActive() || Cinema_IsSequenceInWindow()
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

/* 80225D10_5.CPP */
/* Checks accumulated opponent scores and updates the completion flag. */

extern int Player_GetPlayerIndex(Root *,ObjRecAt16E0V1 *);

/* Reports whether a team's points reached the point target (none when it is 0); in a trial it records
   in humanWon whether that team is the human side's and, when it is not, keeps looking. */

/* Ends a match when its conditions are met, unless a menu or pause is up (Cinema_IsSequenceActive,
   Cinema_IsSequenceInWindow), the match is locked at 0x1C of the rules D_801468A0 or the game D_8014561C disallows
   it at 0xCC9: outside a cutscene (func_80442A28_de) the time limit at 0x14 of the rules counts down by
   the frame time while func_8022C650_de says the clock runs and ends the match when it expires (clearing
   humanWon at 0xA8 of the rules in trial kind 3); outside a cutscene a score limit reached through Player_CheckScoreLimit
   ends it while the rules' limit at 0x18 is set and 0x54 is clear; and when D_80146938 asks, it counts
   the active players among the first eight and how many of them are out, ending the match once all
   are out, directly or, when a mode 14 player takes part, only after the rules' round count at 0x9C
   reaches 3, marking humanWon. */

extern s32 Menu_CountLiveNodes(struct CMenu_t **);

extern s32 func_8022C650_de(World_func_802283B8_de *);

static inline SharedPlayer *player_at(World_func_802283B8_de *world, u32 index) {
    SharedPlayer *player;
    s32 count;

    player = 0;
    count = 0;
    if (index < 8U) {
        player = world->players;
        if (player != 0) {
            do {
                if (count == (s32) index) {
                    return player;
                }
                player = player->views16E0.view16E0_2.next;
                count += 1;
            } while (player != 0);
        }
    }
    return player;
}

extern s32 D_8014687C;

extern void *func_8025CC6C_de(void);

extern s32 func_8025CA24_de(void *, void *);

extern void func_8024BE3C_de(void *arg0);

extern void func_80246E44_de(char *);

extern void GameObject_DrawBlobShadow(void *arg0, CVector3 *arg1, s32 arg2);

extern void Cache_UnlockResource(s32 arg0, s32 arg1);

/* Draws the per-player overlays for one view between Geometry_BeginModelBatch and Geometry_FlushModelBatch: for each player
   in the list from 0x20 it draws the scope model 0xC84 or 0xC85 (by the zoom mode at 0x120C) at the
   player's view matrix while zoomed in at 0x11FC, the player's display through Weaponai_DrawRedMarkerQuad when it
   belongs to this view and is enabled at 0x1210, and in team games (0x24 or 0x78 of D_801468A0) a
   teammate marker through func_80229D28_de for every other player on the viewing player's team. */

extern void *Gsky_FindScreenMessage(s32);

extern s32 Scene_FindModelIdIndex(struct Shared_World *, s32);

extern void *Scene_GetIndexedModelResource(char *, s32);

extern void Geometry_QueueDirectModel(void *, void *, char *, s32, s32);

extern void func_80229D28_de(void *);

extern s32 D_800CD730;

extern s32 D_80140FF8;

s32 Player_CheckTotalScoreWin(Root *root) {
    GameRules *initial=D_8011FAC0.match.rules; GameRules *state;
 ObjRecAt16E0V1 *node; int i,sum,skip; unsigned char *settings;
 if(initial->totalScoreTarget==0) return 0;
 node=root->unk20; state=initial;
 if(node) { settings=(unsigned char *)state-0x5D8; }
 for(;node;node=node->unk16E0) {
  skip=Player_GetPlayerIndex(root,node);
  sum=0;
  for(i=0;i<8;i++) {
   if(i!=skip) {
    sum+=node->unk5D8->score[i];
    if(sum>=state->totalScoreTarget) {
     { unsigned char trialKind=settings[0xD]; if(trialKind) {
      if(node->unk5D4<4) {state->humanWon=1;return 1;}
      state->humanWon=0;
      if(trialKind==1) continue;
     }
     } return 1;
    }
   }
  }
 }
 return 0;
}

s32 Player_CheckTeamPointWin(struct World *world) {
    GameRules *target;
    GameRules *rules;
    Settings580 *settings;
    Settings580 *trial;
    s32 humanTeam;
    s32 i;
    s32 team;
    s32 kind;

    target = D_8011FAC0.match.rules;
    if (target->pointTarget == 0) {
        return 0;
    }
    i = 0;
    settings = &D_8011FAC0.match.settings;
    humanTeam = 0xFF;
    if (settings->trialKind != 0) {
        for (; settings->roster[i].active == 0; i++) {
        }
        humanTeam = D_8011FAC0.match.settings.roster[i].team;
    }
    for (team = 0; team < 5; team++) {
        rules = D_8011FAC0.match.rules;
        if (rules->teamPoints[team] >= rules->pointTarget) {
            if (team == humanTeam) {
                rules->humanWon = 1;
                return 1;
            }
            trial = &D_8011FAC0.match.settings;
            kind = trial->trialKind;
            rules->humanWon = 0;
            if (kind == 0) {
                return 1;
            }
        }
    }
    return 0;
}

void func_802283B8_de(World_func_802283B8_de *world) {
    SharedPlayer *player;
    GameRules *rules;
    GameSessionState *game;
    GameRules *limits;
    s32 i;
    s32 active;
    s32 out;
    s32 special;

    if (Cinema_IsSequenceActive() == 0 && Cinema_IsSequenceInWindow() == 0) {
        rules = D_8011FAC0.match.rules;
        if (rules->locked != 0 || D_8011FAC0.match.settings.allowed == 0) {
            return;
        }
        if (Menu_CountLiveNodes(&D_8011FAC0.match.messages.head) == 0 && rules->timeLimit > 0.0f && D_8011FAC0.clockPaused == 0) {
            if (func_8022C650_de(world) != 0) {
                rules->timeLimit -= D_800D2988;
            }
            if (rules->timeLimit <= 0.0f && rules->locked == 0) {
                rules->timeLimit = 0.0f;
                if (D_8011FAC0.match.settings.trialKind == 3) {
                    rules->humanWon = 0;
                }
                Playerai_EndRound(world);
            }
        }
        game = &D_8011FAC0.match;
        if (Menu_CountLiveNodes(&game->messages.head) == 0 && Player_CheckScoreLimit(world) != 0) {
            limits = game->rules;
            if (limits->locked == 0 && D_8011FAC0.clockPaused == 0 && limits->scoreLimit > 0 && limits->sudden == 0) {
                Playerai_EndRound(world);
            }
        }
        if (D_801462C8.counters.enabled != 0) {
            active = 0;
            out = 0;
            special = 0;
            for (i = 0; i < 8; i++) {
                player = player_at(world, i);
                if (player != 0 && player->views5D8.view5D8_1.record->display != 0) {
                    active++;
                    if (player->views5E4.view5E4_3.alive == 0) {
                        out++;
                    }
                    if (player->views5D8.view5D8_1.record->unk80 == 0xE) {
                        special = 1;
                    }
                }
            }
            if (out == active) {
                if (special) {
                    limits = D_8011FAC0.match.rules;
                    if (limits->rounds >= 3) {
                        limits->humanWon = 1;
                        Playerai_EndRound(world);
                    }
                } else {
                    D_801462C8.counters.humanWon = 1;
                    Playerai_EndRound(world);
                }
            }
        }
    }
}

void func_802285E8_de(char *game) {
    char *actor;

    if (D_8014687C == 11 || D_8014687C == 8) {
        return;
    }
    actor = ((ObjRecAt20V2 *)(game))->unk20;
    while (actor != 0) {
        if (Cinema_IsSequenceInWindow() != 0 || ((ObjRecV5 *)(actor))->unk5EA == 0) {
            void *work;

            work = func_8025CC6C_de();
            func_8025CA24_de(work, ((ObjRecV5 *)(actor))->unk11BC.v0);
            ((ObjRecV5 *)(actor))->unk11BC.v1 = 0;
            work = func_8025CC6C_de();
            func_8025CA24_de(work, ((ObjRecV5 *)(actor))->unk11C0.v0);
            ((ObjRecV5 *)(actor))->unk11C0.v1 = 0;
        } else if (D_80145088.status[7] == 0) {
            void *owner = ((ObjRecV5 *)(actor))->unk5DC;
            s32 blocked;

            if (owner == 0) {
                blocked = 0;
            } else {
                blocked = ((View *)(owner))->unk564 != 0;
            }
            if (blocked == 0) {
                Block *base;
                s32 old_value;
                s32 new_value;
                f32 saved_value;

                base = &((ObjRecV5 *)(actor))->unk2E8;
                old_value = ((ActorRecAt86C *)actor)->value86C;
                saved_value = D_800D2988;
                ((ActorRecAt86C *)actor)->flags |= 0x200;
                base->value = 0x10;
                base->flags &= 0xFFFDFFFF;
                func_8024BE3C_de(base);
                if (((ObjRecV5 *)(actor))->unk11D8 <= 0.0f) {
                    func_80246E44_de((char *)base);
                }
                new_value = ((ObjRecV5 *)(actor))->unk86C;
                D_800D2988 = saved_value;
                if (old_value != new_value) {
                    ((ObjRecV5 *)(actor))->unk10E = 0;
                }
                ((ObjRecV6 *)(actor))->unk2F0 = ((ObjRecV5 *)(actor))->unk8;
                ((ObjRecV6 *)(actor))->unk354 = ((ObjRecV5 *)(actor))->unk6C;
                ((ObjRecV6 *)(actor))->unk2FC = ((ObjRecV5 *)(actor))->unk14;
                ((ObjRecV6 *)(actor))->unk344 = ((ObjRecV5 *)(actor))->unk5C;
                ((ObjRecV6 *)(actor))->unk3E8 &= ~0x200;
            }
        }
        actor = ((ObjRecV5 *)(actor))->unk16E0;
    }
}

void func_80228798_de(void *game, void *view) {
    void *node;

    node = ((func_80228774_S1 *)(game))->unk20;
    if (node != 0) {
        do {
            void *owner;

            owner = ((ObjRecAt16E0V2 *)(node))->unk5DC;
            if (owner != 0) {
                if (owner == view) {
                    void *actor;

                    actor = &((ObjRecAt16E0V2 *)(node))->unk2E8;
                    if (((func_80207B5C_S2 *)(owner))->unk24 == 0) {
                        if (((ObjRecAt1D8V3 *)(actor))->unk100 & 0x40000) {
                            void *resource;

                            resource = Cache_RequestResource(
                                0, ((ObjRecAt1D8V3 *)(actor))->unkC4,
                                ((ObjRecAt1D8V3 *)(actor))->unkC4,
                                ((ObjRecAt1D8V3 *)(actor))->unkD0,
                                4, 0, 0, D_800C2BC0_de, 1);
                            if (resource != 0) {
                                void *linked;
                                void *temp;

                                linked = ((ObjRecAt1D8V3 *)(actor))->unk1D8;
                                Gobjinst_UpdateModelBounds(actor, (s32)SetN64_GetPackSection(*(void **)resource, 0));
                                temp = ((func_80228774_S5 *)(linked))->unk5DC;
                                if (temp != 0) {
                                    CVector3 delta;

                                    delta.x = ((ObjRecAt128 *)(temp))->unk128 -
                                              ((ObjRecAt1D8V3 *)(actor))->unk8;
                                    delta.y = 0.0f;
                                    delta.z = ((ObjRecAt130 *)(((func_80228774_S5 *)(linked))->unk5DC))->unk130 -
                                              ((ObjRecAt1D8V3 *)(actor))->unk10;
                                    GameObject_DrawBlobShadow(actor, &delta, 1);
                                }
                                Cache_UnlockResource(0, (s32)resource);
                            }
                        }
                    } else {
                        goto generic;
                    }
                } else if (owner != 0) {
generic:
                    if (((ObjRecAt16E0V2 *)(node))->unk100 & 0x40000) {
                        void *resource;

                        resource = Cache_RequestResource(
                            0, ((ObjRecAt16E0V2 *)(node))->unkC4,
                            ((ObjRecAt16E0V2 *)(node))->unkC4,
                            ((ObjRecAt16E0V2 *)(node))->unkD0,
                            4, 0, 0, D_800C2BC0_de, 1);
                        if (resource != 0) {
                            Gobjinst_UpdateModelBounds(node, (s32)SetN64_GetPackSection(*(void **)resource, 0));
                            Cache_UnlockResource(0, (s32)resource);
                        }
                    }
                }
            }
            node = ((ObjRecAt16E0V2 *)(node))->unk16E0;
        } while (node != 0);
    }
}

void func_80228958_de(ObjRecAt20V2 *game, s32 view) {
    char *player;
    GameRules *match;
    s32 team;
    s32 zoomed;
    s32 model;

    match = D_8011FAC0.match.rules;
    team = -1;
    if (match->teams != 0 || match->teamRule != 0) {
        team = ((struct Record *) ((struct OwnerRecAt5D8V2 *) Gsky_FindScreenMessage(view))->settings)->team;
    }
    Geometry_BeginModelBatch();
    for (player = game->unk20; player != 0; player = ((ObjectLinks16E4 *)(player))->unk_16E0) {
        zoomed = 0;
        if (((ObjectLinks16E4 *)(player))->unk_11FC > 0.0f) {
            zoomed = 1;
        }
        if (zoomed) {
            if (((ObjectLinks16E4 *)(player))->unk_120C != 0) {
                model = Scene_FindModelIdIndex(&g_world, 0xC84);
            } else {
                model = Scene_FindModelIdIndex(&g_world, 0xC85);
            }
            if (model != -1) {
                Geometry_QueueDirectModel(Scene_GetIndexedModelResource(&g_world, model), player + 0x1600, &D_800D0EF8, 0, -1);
            }
        }
        if (((ObjectLinks16E4 *)(player))->unk_5DC != 0 && ((ObjectLinks16E4 *)(player))->unk_1210 != 0 && ((ObjectLinks16E4 *)(player))->unk_5DC == view) {
            Weaponai_DrawRedMarkerQuad(player + 0x2E8, (char *)player + 0x458);
        }
        if ((D_8011FAC0.match.rules->teams != 0 || D_8011FAC0.match.rules->teamRule != 0)
            && ((struct Record *) ((ObjectLinks16E4 *) player)->unk_5D8)->team == team && Gsky_FindScreenMessage(view) != player) {
            func_80229D28_de(player);
        }
    }
    Geometry_FlushModelBatch();
}

void Player_DrawMatchCountdown(void *arg0, ViewState *viewState) {
    f32 x;
    f32 y;
    f32 center_x;
    f32 center_y;
    f32 scale_x;
    f32 scale_y;
    f32 position;
    HudGlobals *hud;

    if (Cinema_IsSequenceActive() != 0) {
        return;
    }
    if (Cinema_IsSequenceInWindow() != 0) {
        return;
    }
    hud = (HudGlobals *)&D_801462DE;
    Onscrn_SetupSpriteMode(hud->fade);
    if (((HudState *)&hud->state)->timer <= 0.0f) {
        return;
    }

    position = ((HudState *)&hud->state)->timer * D_800C2BDC_de;
    x = (f32)(s32)(position * D_800C2BE0_de);
    scale_x = viewState->width / (f32)D_800E28D0;
    position -= x * ((D_800C7470_Pair *)&D_800C2BE0_de)->second;
    scale_y = viewState->height / (f32)((struct IntPair *)&D_800E28D0)->field_4;
    if ((x < D_800C2BE8_de) && (position < D_800C2BEC_de) &&
        ((D_800CD730 % 15U) < 5U)) {
        return;
    }

    if (D_80140FF8 == 1) {
        if (D_800E28D8 == 0) {
            center_x = (f32)D_800E28D0 * D_800C2BF0_de;
            scale_x *= D_800C2BF4_de;
            center_y = D_800C2BF8_de[0];
            scale_y *= D_800C2BF4_de;
        } else {
            center_y = D_800C2C00_de[0];
            center_x = (f32)D_800E28D0 * D_800C2BF8_de[1];
        }
    } else {
        center_x = (f32)D_800E28D0 * D_800C2C00_de[1];
        center_y = (f32)(((struct IntPair *)&D_800E28D0)->field_4 - 10) * D_800C2C00_de[1];
    }

    OnScreen_DrawSpriteNumber((s32)x, center_x - (scale_x * D_800C2C08_de),
                   center_y, scale_x, scale_y, 1, 1, 0);
    OnScreen_DrawSpriteNumber((s32)position, center_x + (2.0f * scale_x),
                   center_y, scale_x, scale_y, 1, 0, 2);
    OnScreen_SetupTextRendering();
    Onscrn_DrawText(&D_800C2BD8_de,
                  (s32)(center_x - (scale_x * ((D_800C7470_Pair *)&D_800C2C08_de)->second)),
                  (s32)(center_y - (scale_y * D_800C2C10_de[0])),
                  0xFF, 0, 0, scale_x, scale_y);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#ifdef NON_MATCHING
#define EUF(p, t, o) (*(t *)((u8 *)(p) + (o)))
extern void SoundElement_PlayFlatSound(s32);
extern void BuildDirectionMatrix(void *, void *);
extern void TranslateMatrix(void *, f32, f32, f32), SwapMatrixUpForward(void *), Graphu64_ConvertMatrixToFixed(void *, void *);
/* Pulse of the player's ring effect: with the timer at 0x11FC running it only plays sound 0x578 and re-shows the text of the
   active language, otherwise it rebuilds the ring matrix at 0x1600 from the vectors at 0x1458/0x1470/0x1200 first. */
void func_80228E60_eu(u8 *player, s32 flag) {
    u8 mtx[0x40];
    f32 vec[3];
    void *ui;
    char *text;

    if (EUF(player, s32, 0x147C) == 0) {
        return;
    }
    if (EUF(player, f32, 0x11FC) > 0.0f) {
        EUF(player, f32, 0x11FC) = 0.0f;
        SoundElement_PlayFlatSound(0x578);
        ui = EUF(player, void *, 0x5DC);
        if (ui == 0) {
            return;
        }
        text = D_800E0EC4[((u8 *)&D_80145088)[0x17C1]];
    } else {
        EUF(player, s32, 0x1200) = EUF(player, s32, 0x1458);
        EUF(player, s32, 0x1204) = EUF(player, s32, 0x145C);
        EUF(player, s32, 0x1208) = EUF(player, s32, 0x1460);
        EUF(player, s32, 0x120C) = flag;
        EUF(player, f32, 0x11FC) = 150.0f;
        BuildDirectionMatrix(mtx, player + 0x1470);
        Graphu64_ScaleVector((void *)vec, (void *)(player + 0x1470), 5.12f);
        Graphu64_AddVec3((CVector3 *)vec, (CVector3 *)vec, (CVector3 *)(player + 0x1200));
        TranslateMatrix(mtx, vec[0], vec[1], vec[2]);
        SwapMatrixUpForward(mtx);
        Graphu64_ConvertMatrixToFixed(mtx, player + 0x1600);
        SoundElement_PlayFlatSound(0x578);
        ui = EUF(player, void *, 0x5DC);
        if (ui == 0) {
            return;
        }
        text = flag ? D_800E0ED4[((u8 *)&D_80145088)[0x17C1]] : D_800E0EE4[((u8 *)&D_80145088)[0x17C1]];
    }
    Camera_PostScreenMessage(&D_80145088, ui, text);
}
#else
INCLUDE_ASM("span_1000", func_80228E60_eu);
#endif
#endif

/* 80225D10_6.CPP */
static inline s32 playerHasForce(ForcePlayer *player, f32 zero) { s32 value = 0; if (zero < player->strength) value = 1; return value; }
void Playerai_ApplyPlayerForces(void *listObject, void *bodyObject) {
    ForcePlayerList *list = listObject;
    ForceBody *body = bodyObject;
    ForcePlayer *player;
    s32 changed;
    CVector3 delta, direction;
    f32 distance, force, dot;
    f32 one, zero;
    player = list->head;
    changed = 0;
    if (player != 0) {
        zero = 0.0f;
        one = D_800C2C14_de;
    do {
        if (player->active != 0 && playerHasForce(player, zero)) {
            Graphu64_SubtractVectors(&delta, &player->origin, &body->position);
            distance = (delta.x * delta.x + delta.y * delta.y) + delta.z * delta.z;
            Graphu64_NormalizeVec3(&delta);
            changed = 1;
            if (D_800C2C18_de < distance) {
                force = D_800C2C1C_de / distance;
                if (D_800D2988 < one) force *= D_800D2988;
                if (player->attract == 0) force = -force;
                direction = body->velocity;
                Graphu64_NormalizeVec3(&direction);
                dot = delta.x * direction.x + delta.y * direction.y;
                dot += delta.z * direction.z;
                if (dot < zero) dot = -dot;
                dot += one;
                dot *= D_800C2C20_de;
                force *= dot;
                Graphu64_ScaleVector(&delta, &delta, force);
            }
            Graphu64_AddVec3(&body->velocity, &body->velocity, &delta);
        }
        player = player->next;
    } while (player != 0);
    }
    if (changed != 0) {
        delta = body->velocity;
        Graphu64_NormalizeVec3(&delta);
        body->direction = delta;
    }
}

/* 800C7C90.CPP */
const unsigned int D_auto_src_rw_tail_80227038_C8890_us_rev1[8] = {
    0x3F000000, 0x42000000, 0x3F000000, 0x42000000, 0x3F000000, 0x42000000, 0x3F000000, 0x42000000,
};

/* 800C7CB0.CPP */
const char D_auto_src_ragewars_resident_strings_C88B0_us_rev1[24] = "player anim object info";
