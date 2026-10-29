#include "include_asm.h"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/VIEWFLAGS.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "TYPES.H"
#include "COMMON/MENU_ABBDC_VERSIONS.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "COMMON/OBJRECV5.H"
#include "COMMON/ENTRYRECATE.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "COMMON/CHANNEL.H"

/* 802ABDBC_9.CPP */
extern u8 *g_pickupFlagCarriedText[];
extern u8 *g_pickupReactionOneText[];
extern u8 *g_pickupReactionTwoText[];
extern u8 *g_pickupReactionFourText[];
extern u8 *g_pickupReactionEightText[];
extern u8 *g_pickupReactionSixteenText[];
extern u8 *g_pickupReactionThirtyTwoText[];
extern u8 *g_pickupReactionSixtyFourText[];
extern u8 *g_pickupReactionOneTwentyEightText[];
extern u8 *g_pickupReactionTwoFiftySixText[];
extern u8 *g_pickupReactionFiveTwelveText[];
extern u8 *g_pickupReactionOneThousandTwentyFourText[];
extern u8 *g_pickupReactionTwoThousandFortyEightText[];
extern u8 *g_pickupReactionFourThousandNinetySixText[];
extern u8 *g_pickupReactionDefaultText[];
extern u8 *g_pickupEffectClearedText[];

typedef struct CPersistentPlayerData_t CPersistentPlayerData;
struct CPersistentPlayerData_t {
    u8 pad0[16]; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    s32 m_PowerOfViper; /* +0x10: src/Pickup_ApplySpecialPickup.c */
    s8 m_PowerOfBear; /* +0x14: src/Pickup_ApplySpecialPickup.c */
    s8 m_SpiritOfCoyote; /* +0x15: src/Pickup_ApplySpecialPickup.c */
    s8 m_SpiritOfCougar; /* +0x16: src/Pickup_ApplySpecialPickup.c */
    s8 m_FragFestTimeTrialIcons; /* +0x17: src/Pickup_ApplySpecialPickup.c */
    u8 pad18[376]; /* +0x18: src/Pickup_ApplySpecialPickup.c */
};

typedef struct Shared_MenuBonusColumn Shared_MenuBonusColumn;
struct Shared_MenuBonusColumn {
    u8 value; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 rest[399]; /* +0x1: src/Pickup_ApplySpecialPickup.c */
};

typedef struct Shared_MenuAmountColumn Shared_MenuAmountColumn;
struct Shared_MenuAmountColumn {
    s32 value; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    u8 rest[396]; /* +0x4: src/Pickup_ApplySpecialPickup.c */
};

typedef struct SpecialPickupRecipientView SpecialPickupRecipientView;
struct SpecialPickupRecipientView {
    char pad0[0x8];
    CVector3 position; /* +0x8: passed by value to SoundElement_PlaySoundAtPosition */
    char pad14[0x4];
    struct SpecialPickupActorDefinitionView * definition; /* +0x18: src/Pickup_ApplySpecialPickup.c */
    char pad1C[0x5B8];
    s32 playerIndex; /* +0x5D4: src/Pickup_ApplySpecialPickup.c */
    struct SpecialPickupPlayerOptions * options; /* +0x5D8: src/Pickup_ApplySpecialPickup.c */
    void * messageCamera; /* +0x5DC: src/Pickup_ApplySpecialPickup.c */
    char pad5E0[0x4];
    s32 health; /* +0x5E4: src/Pickup_ApplySpecialPickup.c */
    char pad5E8[0xC];
    u16 firstBonusCount; /* +0x5F4: src/Pickup_ApplySpecialPickup.c */
    u16 secondBonusCount; /* +0x5F6: src/Pickup_ApplySpecialPickup.c */
    u16 ammoBonusCount; /* +0x5F8: src/Pickup_ApplySpecialPickup.c */
    char pad5FA[0xBEA];
    f32 pickupDelay; /* +0x11E4: src/Pickup_ApplySpecialPickup.c */
    char pad11E8[0x44];
    s32 reactionFlags; /* +0x122C: src/Pickup_ApplySpecialPickup.c */
    f32 reactionDuration; /* +0x1230: src/Pickup_ApplySpecialPickup.c */
    char pad1234[0x4];
    s32 reactionTarget; /* +0x1238: src/Pickup_ApplySpecialPickup.c */
    u8 tintRed; /* +0x123C: src/Pickup_ApplySpecialPickup.c */
    u8 tintGreen; /* +0x123D: src/Pickup_ApplySpecialPickup.c */
    u8 tintBlue; /* +0x123E: src/Pickup_ApplySpecialPickup.c */
    char pad123F[0x1];
    f32 tintAlpha; /* +0x1240: src/Pickup_ApplySpecialPickup.c */
    f32 rightAxisValue; /* +0x1244: src/Pickup_ApplySpecialPickup.c */
    char pad1248[0x198];
    s32 pickupExpiryKind; /* +0x13E0: src/Pickup_ApplySpecialPickup.c */
};

typedef struct SpecialPickupDefinition SpecialPickupDefinition;
struct SpecialPickupDefinition {
    u8 ** text; /* +0x0: src/Pickup_ApplySpecialPickup.c */
    s16 id; /* +0x4: src/Pickup_ApplySpecialPickup.c */
    s16 sound; /* +0x6: src/Pickup_ApplySpecialPickup.c */
    s16 event; /* +0x8: src/Pickup_ApplySpecialPickup.c */
    char padA[0x2];
};

typedef struct SpecialPickupActorDefinitionView SpecialPickupActorDefinitionView;
struct SpecialPickupActorDefinitionView {
    char pad0[0xC];
    s16 levelProgressId; /* +0xC: src/Pickup_ApplySpecialPickup.c */
};

typedef struct SpecialPickupMatchModeView SpecialPickupMatchModeView;
struct SpecialPickupMatchModeView {
    char pad0[0x24];
    s32 teamMode; /* +0x24: src/Pickup_ApplySpecialPickup.c */
    char pad28[0x2C];
    s32 flagPickupEnabled; /* +0x54: src/Pickup_ApplySpecialPickup.c */
    char pad58[0x1C];
    s32 flagReturnState; /* +0x74: src/Pickup_ApplySpecialPickup.c */
    char pad78[0x8];
    s32 flagCarried; /* +0x80: src/Pickup_ApplySpecialPickup.c */
    s32 flagDropped; /* +0x84: src/Pickup_ApplySpecialPickup.c */
};

typedef struct SpecialPickupPlayerOptions SpecialPickupPlayerOptions;
struct SpecialPickupPlayerOptions {
    char pad0[0x8F];
    u8 carryingFlag; /* +0x8F: src/Pickup_ApplySpecialPickup.c */
    u8 flagReturned; /* +0x90: src/Pickup_ApplySpecialPickup.c */
    char pad91[0x1];
    u8 team; /* +0x92: src/Pickup_ApplySpecialPickup.c */
};

typedef struct SpecialPickupLinkedPlayerView SpecialPickupLinkedPlayerView;
struct SpecialPickupLinkedPlayerView {
    char pad0[0x5D8];
    struct SpecialPickupLinkedPlayerOptions * options; /* +0x5D8: src/Pickup_ApplySpecialPickup.c */
    void * messageCamera; /* +0x5DC: src/Pickup_ApplySpecialPickup.c */
    char pad5E0[0xBFC];
    f32 bonusDuration; /* +0x11DC: src/Pickup_ApplySpecialPickup.c */
    char pad11E0[0x4C];
    s32 reactionFlags; /* +0x122C: src/Pickup_ApplySpecialPickup.c */
    char pad1230[0x4B0];
    struct SpecialPickupLinkedPlayerView * nextPlayer; /* +0x16E0: src/Pickup_ApplySpecialPickup.c */
    char pad16E4[0x4];
};

typedef struct SpecialPickupLinkedPlayerOptions SpecialPickupLinkedPlayerOptions;
struct SpecialPickupLinkedPlayerOptions {
    char pad0[0x92];
    u8 team; /* +0x92: src/Pickup_ApplySpecialPickup.c */
};

/* g_gamePlayerAndMenuState is the game root: the player records, the list of active players, then the match globals
   g_frontendScreenStatus at +0x44, whose modes block g_matchRoundCounters (+0x185C) the pickup commands write. */
typedef struct Shared_FullPlayerMenuGlobals Shared_FullPlayerMenuGlobals;
struct Shared_FullPlayerMenuGlobals {
    struct SpecialPickupLinkedPlayerView * entries; /* +0x0: player records */
    s32 count; /* +0x4 */
    u8 pad8[0x14];
    struct SpecialPickupLinkedPlayerView * players; /* +0x1C: active players, linked through nextPlayer */
    u8 pad20[0x24];
    union {
        MenuMatchGlobals match; /* +0x44: g_frontendScreenStatus */
        struct {
            u8 pad0[0x1818];
            SpecialPickupMatchModeView modes; /* +0x185C: g_matchRoundCounters */
        } view;
    } game;
};
void Player_IncrementLevelProgress(void *, int);

s32 XPlus_NextRandomInteger(void);
s32 Track_RequestTrackByKey(s32);
typedef CPersistentPlayerData PlayerMenuData;
extern PlayerMenuData g_localPlayerProfiles[];
typedef Shared_MenuBonusColumn MenuBonusColumn;

extern MenuBonusColumn g_playerFirstBonusProfileCounters[];
extern MenuBonusColumn g_playerSecondBonusProfileCounters[];
extern MenuBonusColumn g_playerPickupProfileCounters[];
typedef Shared_MenuAmountColumn MenuAmountColumn;
extern MenuAmountColumn g_characterHealthBonuses[];
extern MenuBonusColumn g_playerAmmoBonusProfileCounters[];
extern Shared_FullPlayerMenuGlobals g_gamePlayerAndMenuState;

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

 /* const */

           /* const */

           /* const */

           /* const */

           /* const */

           /* const */

typedef SpecialPickupRecipientView ObjRecV4;
typedef SpecialPickupDefinition ObjRecV9;
typedef SpecialPickupMatchModeView ObjRecV12;
typedef SpecialPickupPlayerOptions ObjRecV13;
typedef SpecialPickupLinkedPlayerView ObjRecV3;

typedef Shared_FullPlayerMenuGlobals FullPlayerMenuGlobals;

/* PAL builds declare the match globals inside the game root, so their message context and language
   come from g_gamePlayerAndMenuState; the other builds post through g_frontendScreenStatus with the one language. */
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#define PICKUP_CONTEXT (&g_gamePlayerAndMenuState.game.match)
#define PICKUP_TEXT(table) ((table)[PICKUP_CONTEXT->settings.language])
#else
#define PICKUP_CONTEXT (&g_frontendScreenStatus)
#define PICKUP_TEXT(table) ((table)[0])
#endif
/* Special pickup handler; pickupRow is the pickup row (text per language, id, sound, event). The id selects the effect:
   match-mode switches (0xBD6, 0xBD7, which tells every other player), a random reaction (0xBD8: one of 13 flags
   with its tint, duration and message), level progress (0x1389, 0x138A) and health or ammunition bonuses
   (0x1398..0x13C1). A handled pickup then flashes the view, posts the row text, plays its sound and raises its
   event. Returns 1 when handled. */

s32 Pickup_ApplySpecialPickup(ObjRecV4 *recipientActor, ObjRecV9 *pickupActor) {
    f32 zeroReactionValue;
    f32 loopBonus;
    f32 old_unk11E4;
    f32 flashAlpha;
    f32 flashDuration;
    s32 soundId;
    s32 feedbackDialogId;
    s16 pickupId;
    s32 preservedReactionFlags;
    s32 selectedReaction;
    s32 unusedAmmoProfileOffset;
    s32 unusedSecondBonusProfileOffset;
    s32 unusedFirstBonusProfileOffset;
    s32 unusedHealthProfileOffset;
    s32 reactionFlags;
    s32 unusedCounterProfileOffset;
    register s32 playerIndex;
    s32 unusedPickupScratch;
    s32 handled;
    u8 **feedbackText;
    u8 previousFlagState;
    void *messageCamera;
    void *messageCamera10;
    void *messageCamera11;
    void *messageCamera2;
    void *messageCamera3;
    void *messageCamera4;
    void *messageCamera5;
    void *messageCamera6;
    void *messageCamera7;
    void *messageCamera8;
    void *messageCamera9;
    ObjRecV3 *linkedPlayer;
    ObjRecV3 **loopEntries;
    FullPlayerMenuGlobals *menuGlobals;
    ObjRecV12 *loopMenuData;
    ObjRecV12 *commandMenuData;
    ObjRecV13 *playerOptions;

    handled = 0;
    if (recipientActor->health > 0) {
        pickupId = pickupActor->id;
        {
            if (pickupId < 0x139F) {
                if (pickupId < 0x1399) {
                    if (pickupId == 0x1389) goto case_1389;
                    if (pickupId < 0x138A) {
                        if (pickupId == 0xBD7) goto case_BD7;
                        if (pickupId < 0xBD8) {
                            if (pickupId == 0xBD6) goto case_BD6;
                            goto command_done;
                        }
                        if (pickupId == 0xBD8) goto case_BD8;
                        if (pickupId == 0x1388) goto mark_handled;
                        goto command_done;
                    }
                    if (pickupId < 0x1398) {
                        handled = 1;
                        if (pickupId >= 0x138B) goto mark_handled;
                        goto block_126;
                    }
                    goto case_1398;
                }
                handled = 1;
                goto command_done;
            }
            if (pickupId < 0x13AB) {
                if (pickupId < 0x13A9) {
                    if (pickupId == 0x13A0) goto case_13A0;
                    if (pickupId < 0x13A0) goto case_139F;
                    if (pickupId < 0x13A8) handled = 1;
                    goto command_done;
                }
                goto mark_handled;
            }
            if (pickupId == 0x13BC) { handled = 1; goto command_done; }
            if (pickupId < 0x13BD) {
                if (pickupId == 0x13AD) goto mark_handled;
                goto command_done;
            }
            if (pickupId == 0x13BD) goto case_13BD;
            if (pickupId == 0x13C1) goto case_13C1;
            goto command_done;
case_BD6:
                playerOptions = recipientActor->options;
                previousFlagState = playerOptions->carryingFlag;
                if ((previousFlagState == 1) && ((commandMenuData = &g_gamePlayerAndMenuState.game.view.modes)->flagPickupEnabled != 0)) {
                    playerOptions->carryingFlag = 0U;
                    recipientActor->options->flagReturned = previousFlagState;
                    commandMenuData->flagReturnState = 2;
                    g_pickupSavedMusicPlaybackEnabled = SoundElement_GetMusicPlaybackEnabled();
                    if (SoundElement_GetMusicPlaybackEnabled() != 0) {
                        SoundElement_SetMusicPlaybackEnabled(0x3D);
                    }
                    handled = 1;
                }
                goto command_done;
case_BD7:
            {
                ObjRecV12 *listMenuData = &g_gamePlayerAndMenuState.game.view.modes;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                MenuSettings *settings;
                MenuMatchGlobals *game;
#endif
                listMenuData->flagDropped = 0;
                listMenuData->flagCarried = 1;
                recipientActor->options->carryingFlag = 1U;
                linkedPlayer = g_gamePlayerAndMenuState.players;
                handled = 1;
                if (linkedPlayer != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                    game = PICKUP_CONTEXT;
                    settings = &game->settings;
#endif
                    do {
                    if (linkedPlayer != recipientActor) {
                        messageCamera = linkedPlayer->messageCamera;
                        if (messageCamera != 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                            Camera_PostScreenMessage(game, messageCamera, g_pickupFlagCarriedText[settings->language]);
#else
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera, PICKUP_TEXT(g_pickupFlagCarriedText));
#endif
                        }
                    }
                    linkedPlayer = linkedPlayer->nextPlayer;
                    } while (linkedPlayer != 0);
                }
                goto command_done;
            }
case_BD8:
                old_unk11E4 = recipientActor->pickupDelay;
                recipientActor->tintAlpha = 0.0f;
                zeroReactionValue = recipientActor->tintAlpha;
                handled = 1;
                recipientActor->tintRed = 0;
                recipientActor->tintGreen = 0;
                recipientActor->tintBlue = 0;
                if (old_unk11E4 != zeroReactionValue) {
                    messageCamera2 = recipientActor->messageCamera;
                    recipientActor->pickupDelay = zeroReactionValue;
                    recipientActor->pickupExpiryKind = 0;
                    if (messageCamera2 != 0) {
                        Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera2, PICKUP_TEXT(g_pickupEffectClearedText));
                    }
                } else {
                    preservedReactionFlags = recipientActor->reactionFlags & 0x6000;
                    selectedReaction = 1 << (XPlus_NextRandomInteger() % 13);
                    recipientActor->reactionFlags = selectedReaction;
                    if (selectedReaction & 0x20) {
                        recipientActor->reactionTarget = -1;
                        recipientActor->reactionDuration = zeroReactionValue;
                    } else {
                        recipientActor->reactionDuration = 105.0f;
                    }
                    reactionFlags = recipientActor->reactionFlags;
                    switch (reactionFlags) {            /* switch 3; irregular */
                    case 0x1:                       /* switch 3 */
                        SoundElement_PlayDialogGroup(0x15E);
                        playerIndex = 0;
                        if (playerIndex < g_gamePlayerAndMenuState.count) {
                            menuGlobals = &g_gamePlayerAndMenuState;
                            loopEntries = &menuGlobals->entries;
                            loopMenuData = &menuGlobals->game.view.modes;
                            loopBonus = 195.0f;
                            do {
                                linkedPlayer = &(*loopEntries)[playerIndex];
                                if ((linkedPlayer != 0) && (linkedPlayer != recipientActor) && (((loopMenuData->teamMode) == 0) || (linkedPlayer->options->team != recipientActor->options->team))) {
                                    linkedPlayer->reactionFlags = (s32) (linkedPlayer->reactionFlags | 0x2000);
                                    linkedPlayer->bonusDuration = (f32) (linkedPlayer->bonusDuration + loopBonus);
                                }
                                messageCamera3 = linkedPlayer->messageCamera;
                                if (messageCamera3 != 0) {
                                    Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera3, PICKUP_TEXT(g_pickupReactionOneText));
                                }
                            } while (++playerIndex < g_gamePlayerAndMenuState.count);
                        }
                        break;
                    case 0x2:                       /* switch 3 */
                        recipientActor->reactionDuration = 300.0f;
                        SoundElement_PlayDialogGroup(0x164);
                        messageCamera4 = recipientActor->messageCamera;
                        if (messageCamera4 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera4, PICKUP_TEXT(g_pickupReactionTwoText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintRed = 0xFF;
                        goto block_115;
                    case 0x4:                       /* switch 3 */
                        recipientActor->reactionDuration = 225.0f;
                        SoundElement_PlayDialogGroup(0x15F);
                        messageCamera11 = recipientActor->messageCamera;
                        if (messageCamera11 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionFourText));
                        }
                        break;
                    case 0x8:                       /* switch 3 */
                        recipientActor->reactionDuration = 150.0f;
                        SoundElement_PlayDialogGroup(0x165);
                        messageCamera5 = recipientActor->messageCamera;
                        if (messageCamera5 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera5, PICKUP_TEXT(g_pickupReactionEightText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintRed = 0xFF;
block_114:
                        recipientActor->tintGreen = 0xFF;
                        goto block_115;
                    case 0x10:                      /* switch 3 */
                        recipientActor->reactionDuration = 150.0f;
                        SoundElement_PlayDialogGroup(0x160);
                        messageCamera6 = recipientActor->messageCamera;
                        if (messageCamera6 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera6, PICKUP_TEXT(g_pickupReactionSixteenText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintRed = 0xFF;
                        recipientActor->tintBlue = 0xFF;
                        goto block_115;
                    case 0x20:                      /* switch 3 */
                        recipientActor->reactionDuration = 180.0f;
                        SoundElement_PlayDialogGroup(0x166);
                        messageCamera11 = recipientActor->messageCamera;
                        if (messageCamera11 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionThirtyTwoText));
                        }
                        break;
                    case 0x40:                      /* switch 3 */
                        recipientActor->reactionDuration = 225.0f;
                        SoundElement_PlayDialogGroup(0x161);
                        messageCamera11 = recipientActor->messageCamera;
                        if (messageCamera11 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionSixtyFourText));
                        }
                        break;
                    case 0x80:                      /* switch 3 */
                        recipientActor->reactionDuration = 225.0f;
                        SoundElement_PlayDialogGroup(0x169);
                        messageCamera11 = recipientActor->messageCamera;
                        if (messageCamera11 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionOneTwentyEightText));
                        }
                        break;
                    case 0x100:                     /* switch 3 */
                        recipientActor->reactionDuration = 450.0f;
                        SoundElement_PlayDialogGroup(0x162);
                        messageCamera11 = recipientActor->messageCamera;
                        if (messageCamera11 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionTwoFiftySixText));
                        }
                        break;
                    case 0x200:                     /* switch 3 */
                        recipientActor->reactionDuration = 270.0f;
                        SoundElement_PlayDialogGroup(0x16A);
                        messageCamera7 = recipientActor->messageCamera;
                        if (messageCamera7 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera7, PICKUP_TEXT(g_pickupReactionFiveTwelveText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintAlpha = flashAlpha;
                        goto block_116;
                    case 0x400:                     /* switch 3 */
                        recipientActor->reactionDuration = 180.0f;
                        SoundElement_PlayDialogGroup(0x163);
                        messageCamera8 = recipientActor->messageCamera;
                        if (messageCamera8 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera8, PICKUP_TEXT(g_pickupReactionOneThousandTwentyFourText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintRed = 0xFF;
                        recipientActor->tintGreen = 0xFF;
                        recipientActor->tintBlue = 0xFF;
                        goto block_115;
                    case 0x800:                     /* switch 3 */
                        recipientActor->reactionDuration = 300.0f;
                        SoundElement_PlayDialogGroup(0x168);
                        messageCamera9 = recipientActor->messageCamera;
                        if (messageCamera9 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera9, PICKUP_TEXT(g_pickupReactionTwoThousandFortyEightText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintBlue = 0xFF;
                        goto block_115;
                    case 0x1000:                    /* switch 3 */
                        recipientActor->reactionDuration = 300.0f;
                        SoundElement_PlayDialogGroup(0x15F);
                        messageCamera10 = recipientActor->messageCamera;
                        if (messageCamera10 != 0) {
                            Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera10, PICKUP_TEXT(g_pickupReactionFourThousandNinetySixText));
                        }
                        flashAlpha = 255.0f;
                        flashDuration = recipientActor->reactionDuration;
                        recipientActor->tintGreen = 0xFF;
                        goto block_115;
                    default:                        /* switch 3 */
                        goto block_default;
                    }
                    goto block_after_alpha;
block_115:
                    recipientActor->tintAlpha = flashAlpha;
block_116:
                    recipientActor->rightAxisValue = (f32) (flashAlpha / flashDuration);
                    goto block_after_alpha;
block_default:
                    messageCamera11 = recipientActor->messageCamera;
                    if (messageCamera11 != 0) {
                        Camera_PostScreenMessage(PICKUP_CONTEXT, messageCamera11, PICKUP_TEXT(g_pickupReactionDefaultText));
                    }
block_after_alpha:
                    recipientActor->reactionFlags = (s32) (recipientActor->reactionFlags | preservedReactionFlags);
                }
                goto command_done;
case_1398:
                unusedAmmoProfileOffset = recipientActor->playerIndex * 0x190;
                handled = 1;
                g_playerAmmoBonusProfileCounters[recipientActor->playerIndex].value += 0xA;
                recipientActor->ammoBonusCount = (u16) (recipientActor->ammoBonusCount + 0xA);
                Track_RequestTrackByKey(0x1F5);
                goto command_done;
case_13A0:
            unusedFirstBonusProfileOffset = recipientActor->playerIndex * 0x190;
            handled = 1;
            g_playerFirstBonusProfileCounters[recipientActor->playerIndex].value += 0x32;
            recipientActor->firstBonusCount = (u16) (recipientActor->firstBonusCount + 0x32);
            Track_RequestTrackByKey(0x1F7);
            goto command_done;
case_139F:
            handled = 1;
            unusedSecondBonusProfileOffset = recipientActor->playerIndex * 0x190;
            g_playerSecondBonusProfileCounters[recipientActor->playerIndex].value += 0x32;
            recipientActor->secondBonusCount = (u16) (recipientActor->secondBonusCount + 0x32);
            Track_RequestTrackByKey(0x1F6);
            goto command_done;
case_13C1:
            handled = 1;
            unusedHealthProfileOffset = recipientActor->playerIndex * 0x190;
            g_characterHealthBonuses[recipientActor->playerIndex].value += 0x500;
            recipientActor->health = (s32) (recipientActor->health + 0x500);
            Track_RequestTrackByKey(0x1F8);
            goto command_done;
case_1389:
                Player_IncrementLevelProgress(&g_localPlayerProfiles[recipientActor->playerIndex], (s32) recipientActor->definition->levelProgressId);
block_126:
                handled = 1;
                Player_IncrementLevelProgress(&g_localPlayerProfiles[recipientActor->playerIndex], (s32) recipientActor->definition->levelProgressId);
                Track_RequestTrackByKey(0x1F4);
                goto command_done;
case_13BD:
            unusedCounterProfileOffset = recipientActor->playerIndex * 0x190;
            handled = 1;
            g_playerPickupProfileCounters[recipientActor->playerIndex].value += 1;
            goto command_done;
mark_handled:
            handled = 1;
            goto command_done;
        }
command_done:
        ;
    }
    if (handled != 0) {
        feedbackText = pickupActor->text;
        soundId = pickupActor->sound;
        feedbackDialogId = pickupActor->event;
        if (recipientActor->messageCamera != 0) {
            Gsky_StartFade(recipientActor->messageCamera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
            if (feedbackText != 0) {
                Camera_PostScreenMessage(&g_frontendScreenStatus, recipientActor->messageCamera, feedbackText[MENU_LANGUAGE]);
            }
        }
        if (soundId != 0) {
            SoundElement_PlaySoundAtPosition(soundId, recipientActor->position, 0, -1);
        }
        if (feedbackDialogId != 0) {
            SoundElement_PlayDialogGroup((s32) feedbackDialogId);
        }
    }
    return handled;
}

/* A g_pickupPowerupDefinitions powerup row (0x18 bytes, three rows): the item entry head shared with the other item tables,
   the action slot the powerup fills, the ammunition it grants and its pickup handler. */
typedef struct PowerupEntry {
    u8 **text; /* 0x0: pickup message, one per language */
    s16 id; /* 0x4: item id looked up by Pickup_DispatchHandler */
    s16 sound; /* 0x6 */
    s16 event; /* 0x8 */
    s16 reservedA; /* 0xA */
    s16 slot; /* 0xC: row in Player.actions */
    s16 ammoSlot; /* 0xE: Player.ammo index for Player_AddAmmo_PickupApplyspecialpickup */
    s16 ammoCount; /* 0x10 */
    s32 (*handle)(struct Player *player, struct PowerupEntry *entry); /* 0x14 */
} PowerupEntry;
/* Team ids that may always pick up items (Pickup_CanCollect reads the same pair). */
extern s32 g_playerSpecialModelIds[2];
extern void Player_AddAmmo(void *, s16, s16);
/* Pickup feedback: flash the player's view, post the entry's message in the current language,
   play its sound at the player and raise its event. */
static inline void announcePowerup(struct Player *player, PowerupEntry *entry)
{
    u8 **text = entry->text;
    s32 sound = entry->sound;
    s32 event = entry->event;
    if (player->camera) {
        Gsky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&g_frontendScreenStatus, player->camera, text[MENU_LANGUAGE]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) SoundElement_PlayDialogGroup(event);
}
/* Powerup pickup handler (g_pickupPowerupDefinitions rows). A powerup the player already holds, or any pickup in a tag match by a
   player not on one of the g_playerSpecialModelIds teams, only gives the pickup feedback. Otherwise the powerup takes weapon key
   3 or 7, whichever no action slot uses yet (none free: refused, returns 0); outside tag matches it becomes the
   pending weapon. Then the feedback plays and the entry's ammunition is added. Returns 1 when taken. */
s32 Pickup_HandlePowerWeaponPickup(struct Player *player, PowerupEntry *entry)
{
    s32 key3Free = 1, key7Free = 1, i;
    s32 skipAmmo = 0;
    if (player->actions[entry->slot][1] != -1 &&
        (!player->profile->bonus || !g_frontendScreenStatus.modes.tag || player->objectId == g_playerSpecialModelIds[0] ||
         player->objectId == g_playerSpecialModelIds[1])) {
        announcePowerup(player, entry);
    } else {
        for (i = 0; i < 22; i++) {
            if (player->actions[i][1] == 3) key3Free = 0;
            else if (player->actions[i][1] == 7) key7Free = 0;
        }
        player->actions[entry->slot][0] = 1;
        if (key3Free || key7Free) {
            if (!player->profile->bonus || !g_frontendScreenStatus.modes.tag) {
                player->pendingWeapon = key3Free ? 3 : 7;
                player->actions[entry->slot][1] = key3Free ? 3 : 7;
            }
        } else {
            return 0;
        }
        announcePowerup(player, entry);
        if (!skipAmmo) Player_AddAmmo(player, entry->ammoSlot, entry->ammoCount);
    }
    return 1;
}

#if defined(VERSION_EU_X)
#ifdef NON_MATCHING
/* Pickup effect handler: applies the pickup's effect id (0x708..0x70F) to the player (two float settings, an accumulated float
   or a sound/effect spawn through ItemMenu_SetEntry) then shows the pickup text in the current language, plays its sound and
   raises its event. Returns one. */
extern f32 g_specialPickupShieldDurationEu, k_pickupEuropeanSecondEffectValue;
extern char g_pickupEuropeanEffectUpdateRomEntry[], g_pickupEuropeanEffectDrawRomEntry[];
extern void ItemMenu_SetEntry();
s32 Pickup_ApplyEuropeanExtendedPowerup(struct Player *player, PowerupEntry *pickup, void *obj) {
    u8 **text = pickup->text;
    s16 sound = pickup->sound;
    s16 event = pickup->event;
    f32 *data = (f32 *)(*(u8 **)((u8 *)obj + 0x18) + 0x14);

    switch ((s16)(pickup->id - 0x708)) {
    case 0: *(f32 *)((u8 *)player + 0x670) = g_specialPickupShieldDurationEu; break;
    case 1: *(f32 *)((u8 *)player + 0x674) = k_pickupEuropeanSecondEffectValue; break;
    case 2: *(f32 *)((u8 *)player + 0x678) += data[3]; break;
    case 3: ItemMenu_SetEntry((u8 *)player + 0xD40, 1, 0, 0x7FD, 0, 0, 0, g_pickupEuropeanEffectUpdateRomEntry, g_pickupEuropeanEffectDrawRomEntry); break;
    }
    if (*(void **)((u8 *)player + 0x5DC) != 0) {
        Gsky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&g_frontendScreenStatus, player->camera, ((char **)text)[g_languageIndex]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) SoundElement_PlayDialogGroup(event);
    return 1;
}
#else
INCLUDE_ASM("span_1000", Pickup_ApplyEuropeanExtendedPowerup);
#endif
#endif

#if defined(VERSION_EU)
#ifdef NON_MATCHING
/* Pickup effect handler: applies the pickup's effect id (0x708..0x70F) to the player (two float settings, an accumulated float
   or a sound/effect spawn through ItemMenu_SetEntry) then shows the pickup text in the current language, plays its sound and
   raises its event. Returns one. */
extern f32 g_specialPickupShieldDurationEu, k_pickupEuropeanSecondEffectValue;
extern char g_pickupEuropeanEffectUpdateRomEntry[], g_pickupEuropeanEffectDrawRomEntry[];
extern void ItemMenu_SetEntry();
s32 Pickup_ApplyEuropeanPowerup(struct Player *player, PowerupEntry *pickup, void *obj) {
    u8 **text = pickup->text;
    s16 sound = pickup->sound;
    s16 event = pickup->event;
    f32 *data = (f32 *)(*(u8 **)((u8 *)obj + 0x18) + 0x14);

    switch ((s16)(pickup->id - 0x708)) {
    case 0: *(f32 *)((u8 *)player + 0x670) = g_specialPickupShieldDurationEu; break;
    case 1: *(f32 *)((u8 *)player + 0x674) = k_pickupEuropeanSecondEffectValue; break;
    case 2: *(f32 *)((u8 *)player + 0x678) += data[3]; break;
    case 3: ItemMenu_SetEntry((u8 *)player + 0xD40, 1, 0, 0x7FD, 0, 0, 0, g_pickupEuropeanEffectUpdateRomEntry, g_pickupEuropeanEffectDrawRomEntry); break;
    }
    if (*(void **)((u8 *)player + 0x5DC) != 0) {
        Gsky_StartFade(player->camera, 0x80, 0x32, 0x32, 0x4B, 0, 0, 2);
        if (text) Camera_PostScreenMessage(&g_frontendScreenStatus, player->camera, ((char **)text)[g_languageIndex]);
    }
    if (sound) SoundElement_PlaySoundAtPosition(sound, player->pos, 0, -1);
    if (event) SoundElement_PlayDialogGroup(event);
    return 1;
}
#else
INCLUDE_ASM("span_1000", Pickup_ApplyEuropeanPowerup);
#endif
#endif

/* PICKUP_APPLYSPECIALPICKUP_DATA.CPP */

