#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "include_asm.h"
#include "COMMON/LEVEL_GOAL.H"
#include "RENDER/MATERIAL_COLOR_AND_FOG_VIEWS.H"
#include "ACHIEVE/ACHIEVE.H"
#include "ACHIEVE/MATCH_GETRESULTTEXT.H"
#include "COMMON/PLAYERPROFILES.H"
#include "RESMGR/X_PLUS.H"

const unsigned int g_resultPreviewTransformConstants[6] = {
    0x3E99999A, 0x3C1374BC, 0x40400000, 0xC0A00000, 0xC2C80000, 0xC1F00000,
};

#include "COMMON/MENU_TEXT.H"
#include "COMMON/SHARED_WORLDFUNC.H"
#include "FRONTEND/RESULTS_SETUP_TEXT.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/RENDERCOUNTERS.H"
#include "COMMON/ACTIVE.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/WORLD.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
extern Active *g_currentStagePreset;
extern struct ResultsHeadingCharacter g_resultCharacterHeadings[];
#if !defined(VERSION_EU) && !defined(VERSION_EU_X)
extern f32 g_resultTimeToSeconds;
#endif
extern char *g_resultCharacterUnlockFormat, *g_resultUnavailableText, *g_resultPreviouslyCompletedText, *g_resultModeHeadingText, *g_resultTrialModeText, *g_resultChallengeModeText, *g_resultCampaignCompleteText, *g_resultTrialsCompleteText;
extern void Frontend_InitMenuImage(void *, s32, s32, s32, s32);
extern void Frontend_StartMenuImageTransition(void *);
extern void CPlayerPreview_ResetSelectionMessageState(void);
extern void Achieve_MarkLevelPlayed(s32);
extern s32 Defs_TestBit(u8 *, s32);
extern void Defs_SetBitValue(u8 *, s32, s32);
extern s32 Match_ApplyLevelCompletionReward(s32);
extern s32 Achieve_AwardCharacterCompletionUnlock(s32);
extern s32 Key_FindKeyIndex(s32);
extern void XStdio_FormatBuffer(char *, char *, ...);
extern void XPlus_CopyString(char *, char *);
extern void Widget_SetWidgetFlag100(MenuWidget *, s32);
extern void Scene_CopyLevelName(Shared_World *, s32, char *, s32);
extern char *XPlus_UppercaseString(char *);
extern void Achieve_UpdatePlayerPreviewStats(void);
extern void Achieve_ConfigureResultModelPreview(void);
/* Opens the level results screen: allocates the preview state, records the finished level for the winning
   player, unlocks the level-end achievements and fills the level name and status lines. */
static inline Shared_Game *Results_CurrentGame(void) { return &g_gameSettings; }
s32 Achieve_CreateResultsScreen(MenuWidget *menu) {
    char levelName[0x40];
    MenuWidget *item;
    Active *preset;
    SlotSelectionPlayerConfig *config;
    Shared_Game *game;
    CGameStatus *counters;
    s32 achievement;
    s32 time;
    s32 slot;
    s32 character;
    Shared_Game *nameGame;
    s32 *level;
    s32 i;

    g_resultsModelPreviewScreen = (ModelPreviewScreen *)Cache_AllocateMemory(sizeof(ModelPreviewScreen));
    g_resultsModelPreviewScreen->window = menu;
    Widget_SetWidgetFlag08(menu, 0);
    Frontend_InitMenuImage(g_resultsModelPreviewScreen, 0x67, 0, 0, 0);
    Frontend_StartMenuImageTransition(g_resultsModelPreviewScreen);
    g_resultsModelPreviewScreen->cursor = 1;
    Node_FindWidgetByResourceId(menu, 0x26B + PREVIEW_ID_SHIFT)->alpha = 0x6E;
    Node_FindWidgetByResourceId(menu, 0x270 + PREVIEW_ID_SHIFT)->alpha = 0x14;
    Node_FindWidgetByResourceId(menu, 0x26D + PREVIEW_ID_SHIFT)->alpha = 0x14;
    Node_FindWidgetByResourceId(menu, 0x280 + PREVIEW_ID_SHIFT)->alpha = 0x19;
    config = g_playerSettings;
    g_resultsModelPreviewScreen->player = 0;
    for (i = 0; i < 4; i++) {
        if (config[i].active == 1) {
            g_resultsModelPreviewScreen->player = i;
            break;
        }
    }
    CPlayerPreview_ResetSelectionMessageState();
    g_resultsModelPreviewScreen->badge = -1;
    game = &g_gameSettings;
    switch (game->controllerMode) {
    case 1:
        if (game->humanWon == 1) {
            Achieve_MarkLevelPlayed(g_resultsModelPreviewScreen->player);
            g_resultsModelPreviewScreen->rows[0].model = -1;
            if (g_currentStagePreset->recorded != 0) {
                slot = g_localPlayerProfiles[g_resultsModelPreviewScreen->player].slot;
                if (Defs_TestBit(g_localPlayerProfiles[g_resultsModelPreviewScreen->player].slotLevels[slot], g_selectedLevelId) == 1) {
                    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27E + PREVIEW_ID_SHIFT);
                    Widget_SetWidgetFlag08(item, 1);
                    item->alpha = 0xAF;
                    item->text = RW_LOCALIZED_TEXT(g_resultPreviouslyCompletedText, g_resultPreviouslyCompletedTranslations, g_resultPreviouslyCompletedTranslations, Results_CurrentGame()->language);
                    goto done;
                }
            }
            g_resultsModelPreviewScreen->rows[0].model = Match_ApplyLevelCompletionReward(g_resultsModelPreviewScreen->player);
            g_resultsModelPreviewScreen->rows[0].image = Match_GetResultText(g_resultsModelPreviewScreen->rows[0].model);
done:
            g_resultsModelPreviewScreen->badge = -1;
            switch (g_selectedLevelId) {
            case 4:
                achievement = 0x2D;
                break;
            case 9:
                achievement = 0x2E;
                break;
            case 0x16:
                achievement = 0x2F;
                break;
            case 0x23:
                achievement = 0x30;
                break;
            default:
                achievement = -1;
                break;
            }
            if (achievement != -1 && Defs_TestBit(g_localPlayerProfiles[g_resultsModelPreviewScreen->player].achievementFlags, achievement) == 0) {
                Defs_SetBitValue(g_localPlayerProfiles[g_resultsModelPreviewScreen->player].achievementFlags, achievement, 1);
                g_resultsModelPreviewScreen->badge = achievement;
                Achieve_UpdateUnlockTiers(g_resultsModelPreviewScreen->player);
            }
            if (g_localPlayerProfiles[g_resultsModelPreviewScreen->player].count >= 18) {
                Defs_SetBitValue(&g_localPlayerProfiles[g_resultsModelPreviewScreen->player].groupFlags, 1, 1);
            }
            if (g_localPlayerProfiles[g_resultsModelPreviewScreen->player].count >= 36) {
                Defs_SetBitValue(&g_localPlayerProfiles[g_resultsModelPreviewScreen->player].groupFlags, 2, 1);
            }
            if (g_selectedLevelId >= 0x23) {
                Defs_SetBitValue(g_localPlayerProfiles[g_resultsModelPreviewScreen->player].kindFlags, g_playerSettings[g_resultsModelPreviewScreen->player].kind, 1);
                XPlus_FillMemory(g_localPlayerProfiles[g_resultsModelPreviewScreen->player].levelFlags[0], 0, 5);
                character = Achieve_AwardCharacterCompletionUnlock(g_resultsModelPreviewScreen->player);
                nameGame = Results_CurrentGame();
                if (character >= 0) {
                    character = Key_FindKeyIndex(character);
                    XStdio_FormatBuffer(g_resultsModelPreviewScreen->resultText, RW_LOCALIZED_TEXT(g_resultCharacterUnlockFormat, g_resultCharacterUnlockTranslations, g_resultCharacterUnlockTranslations, nameGame->language), RW_LOCALIZED_TEXT(g_resultCharacterHeadings[character].name[0], g_resultCharacterHeadingTranslations[character].name, g_resultCharacterHeadingTranslations[character].name, nameGame->language));
                    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
                    item->alpha = 0xAF;
                    Widget_SetWidgetFlag08(item, 1);
                    item->text = g_resultsModelPreviewScreen->resultText;
                }
            }
        } else {
            nameGame = Results_CurrentGame();
            XPlus_CopyString(g_resultsModelPreviewScreen->resultText, resultsUnavailable(nameGame));
            item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            Widget_SetWidgetFlag08(item, 1);
            item->text = g_resultsModelPreviewScreen->resultText;
        }
        break;
    case 3:
        counters = &game->counters;
        if (counters->humanWon == 1) {
            Achieve_MarkLevelPlayed(g_resultsModelPreviewScreen->player);
            level = &g_selectedLevelId;
            preset = Achieve_CopyPreset(*level, 3, 0);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
            time = counters->timeLimit * 0.06666667f;
#else
            time = counters->timeLimit * g_resultTimeToSeconds;
#endif
            if (g_localPlayerProfiles[g_resultsModelPreviewScreen->player].times[*level] == 0) {
                g_localPlayerProfiles[g_resultsModelPreviewScreen->player].times[*level] = preset->time - time;
            } else if (preset->time - time < g_localPlayerProfiles[g_resultsModelPreviewScreen->player].times[*level]) {
                g_localPlayerProfiles[g_resultsModelPreviewScreen->player].times[*level] = preset->time - time;
            }
            if (g_selectedLevelId == 0x23) {
                item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
                item->alpha = 0xAF;
                Widget_SetWidgetFlag08(item, 1);
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                item->text = RW_LOCALIZED_TEXT(g_resultTrialsCompleteText, g_resultTrialsCompleteTranslations, g_resultTrialsCompleteTranslations, g_languageIndex);
#else
                item->text = g_resultTrialsCompleteText;
#endif
            }
        } else {
            nameGame = Results_CurrentGame();
            XPlus_CopyString(g_resultsModelPreviewScreen->resultText, resultsUnavailable(nameGame));
            item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            Widget_SetWidgetFlag08(item, 1);
            item->text = g_resultsModelPreviewScreen->resultText;
        }
        break;
    case 4:
        if (game->humanWon == 1) {
            Achieve_MarkLevelPlayed(g_resultsModelPreviewScreen->player);
            if (g_selectedLevelId == 0x23) {
                item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
                item->alpha = 0xAF;
                Widget_SetWidgetFlag08(item, 1);
                item->text = RW_LOCALIZED_TEXT(g_resultCampaignCompleteText, g_resultCampaignCompleteTranslations, g_resultCampaignCompleteTranslations, Results_CurrentGame()->language);
            }
        } else {
            nameGame = Results_CurrentGame();
            XPlus_CopyString(g_resultsModelPreviewScreen->resultText, resultsUnavailable(nameGame));
            item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x27F + PREVIEW_ID_SHIFT);
            item->alpha = 0xAF;
            Widget_SetWidgetFlag08(item, 1);
            item->text = g_resultsModelPreviewScreen->resultText;
        }
        break;
    }
    Achieve_UpdatePlayerPreviewStats();
    Achieve_ConfigureResultModelPreview();
    SmpButton_WrapButtonWidget(0x26E + PREVIEW_ID_SHIFT);
    SmpButton_WrapButtonWidget(0x26F + PREVIEW_ID_SHIFT);
    SmpButton_WrapButtonWidget(0x273 + PREVIEW_ID_SHIFT);
    Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(menu, 0x26F + PREVIEW_ID_SHIFT), 1);
    for (i = 0; i < 4; i++) {
        if (g_localPlayerProfiles[i].player >= 0 && g_localPlayerProfiles[i].fresh == 0) {
            Widget_SetWidgetFlag100(Node_FindWidgetByResourceId(menu, 0x26F + PREVIEW_ID_SHIFT), 0);
            break;
        }
    }
    Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x271 + PREVIEW_ID_SHIFT)->text = RW_LOCALIZED_TEXT(g_resultModeHeadingText, g_resultModeHeadingTranslations, g_resultModeHeadingTranslations, Results_CurrentGame()->language);
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, 0x272 + PREVIEW_ID_SHIFT);
    switch (g_currentResultMode.kind) {
    case 0:
        item->text = RW_LOCALIZED_TEXT(g_resultChallengeModeText, g_resultChallengeModeTranslations, g_resultChallengeModeTranslations, Results_CurrentGame()->language);
        break;
    case 1:
        item->text = RW_LOCALIZED_TEXT(g_resultTrialModeText, g_resultTrialModeTranslations, g_resultTrialModeTranslations, Results_CurrentGame()->language);
        break;
    default:
        item->text = RW_LOCALIZED_TEXT(g_resultTrialModeText, g_resultTrialModeTranslations, g_resultTrialModeTranslations, g_languageIndex);
        break;
    }
    item = Node_FindWidgetByResourceId(menu, 0x26C + PREVIEW_ID_SHIFT);
    Scene_CopyLevelName(&g_world, g_selectedLevelId, levelName, 0x3F);
    XPlus_CopyString(g_resultsModelPreviewScreen->nameText, XPlus_UppercaseString(levelName));
    item->text = g_resultsModelPreviewScreen->nameText;
    g_resultsModelPreviewScreen->item24 = Node_FindWidgetByResourceId(menu, 0x274 + PREVIEW_ID_SHIFT);
    g_resultsModelPreviewScreen->ready = 1;
    g_frontendScreenStatus.status[7] = 1;
    g_resultsModelPreviewScreen->started = 0;
    Tsmos_DeactivateControllerState();
    return 0;
}


#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
#include "COMMON/OBJECTRECAT28.H"
extern char g_resultPercentFormat[];

#if !defined(VERSION_US) && !defined(VERSION_US_REV1)
extern void XStdio_FormatBuffer(char *, char *, ...);
#endif

#if defined(VERSION_DE)
extern char g_resultPreviewNumberFormatDe[];
#define PREVIEW_NUMBER_FORMAT g_resultPreviewNumberFormatDe
#elif defined(VERSION_US)
extern char g_resultPreviewNumberFormatUs[];
#define PREVIEW_NUMBER_FORMAT g_resultPreviewNumberFormatUs
#elif defined(VERSION_US_REV1)
extern char k_AchieveEncodedBytes[];
#define PREVIEW_NUMBER_FORMAT k_AchieveEncodedBytes
#elif defined(VERSION_EU)
extern char g_resultPreviewNumberFormatEu[];
#define PREVIEW_NUMBER_FORMAT g_resultPreviewNumberFormatEu
#elif defined(VERSION_EU_X)
extern char g_resultPreviewNumberFormatEuX[];
#define PREVIEW_NUMBER_FORMAT g_resultPreviewNumberFormatEuX
#endif

/* Fill the selected player's preview statistics and optional rank badge. */
void Achieve_UpdatePlayerPreviewStats(void) {
    MenuWidget *item, *lastItem;
    SlotSelectionPlayerConfig *record;
    s32 denominator;
    s32 player;
    s32 statIndex;
    s32 percent;

    player = g_resultsModelPreviewScreen->player;
    statIndex = player;
    record = &g_playerSettings[player];
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x275 + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0x96;
    item->value = g_characterPortraitRecords[Key_FindKeyIndex((s32) record->kind)].portrait;
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x276 + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0xAF;
    item->text = g_localPlayerProfiles[player].name;
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x277 + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0x73;
    item->text = Match_UpdateRankText(player);
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x278 + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0xAF;
    XStdio_FormatBuffer(g_resultsModelPreviewScreen->killsText, PREVIEW_NUMBER_FORMAT, record->kills);
    item->text = g_resultsModelPreviewScreen->killsText;
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x279 + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0xAF;
    XStdio_FormatBuffer(g_resultsModelPreviewScreen->scoreText, PREVIEW_NUMBER_FORMAT, record->score + record->total);
    item->text = g_resultsModelPreviewScreen->scoreText;
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x27a + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0xAF;
    denominator = g_playerCountedShots[statIndex];
    percent = 0;
    if (denominator > 0) {
        percent = (s32) (g_playerHitCounts[statIndex] * 0x64) / denominator;
    }
    XStdio_FormatBuffer(g_resultsModelPreviewScreen->ratioText, g_resultPercentFormat, percent);
    item->text = g_resultsModelPreviewScreen->ratioText;
    item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x27b + PREVIEW_ID_SHIFT));
    Widget_SetWidgetFlag08(item, 1);
    item->alpha = 0xAF;
    lastItem=item;
    switch (g_currentResultMode.kind) {
    case 0: XStdio_FormatBuffer(g_resultsModelPreviewScreen->otherText, PREVIEW_NUMBER_FORMAT, record->other); break;
    case 1: XStdio_FormatBuffer(g_resultsModelPreviewScreen->otherText, PREVIEW_NUMBER_FORMAT, record->selected); break;
    default: XStdio_FormatBuffer(g_resultsModelPreviewScreen->otherText, PREVIEW_NUMBER_FORMAT, 0); break;
    }
    lastItem->text = g_resultsModelPreviewScreen->otherText;
    if (g_resultsModelPreviewScreen->badge != -1) {
        item = Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window, (0x27c + PREVIEW_ID_SHIFT));
        item->alpha = 0x96;
        Widget_SetWidgetFlag08(item, 1);
        item->value = g_resultAchievementBadgeImages[g_resultsModelPreviewScreen->badge];
    }
}

#undef PREVIEW_NUMBER_FORMAT

/* This function's literal pool (retained rodata): 0.3, 0.009, 3.0, -5.0, -100.0, -30.0. */
extern f32 g_resultPreviewSmallScale;
extern f32 g_resultPreviewCameraZ;
/* Shows the selected preview row's model: sets its image widget, scales the model (0.3 for the listed models,
   0.009 otherwise; 0.3 with a lower camera for 0x1390/0x1392), places it and resets the row's fade. */
void Achieve_ConfigureResultModelPreview(void) {
 SetupModelVector scale,offset,angle,position;
 s32 index, displacement, model;
 MenuWidget *item;
 ModelPreviewScreen *slot;
 index=g_resultsModelPreviewScreen->selected;
 displacement=index*20;
 model=g_resultsModelPreviewScreen->rows[index].model;
 if(model>=0) {
  /* the hub's Item view shares the MenuWidget prefix; this unit writes alpha and image through its own view */
  item=(MenuWidget *)Node_FindWidgetByResourceId(g_resultsModelPreviewScreen->window,RESULTS_MODEL_PREVIEW_IMAGE_WIDGET_ID);
  Widget_SetWidgetFlag08(item,1);
  item->alpha=0xAF;
  item->image=g_resultsModelPreviewScreen->rows[index].image;
  if ((u32)(model-0x1389)<2U || model==0x139F || model==0x13A0 || model==0x13C1 || model==0x1398 || model==0x13BD) {
   scale.value.x=g_resultPreviewLargeScale; scale.value.y=g_resultPreviewLargeScale; scale.value.z=g_resultPreviewLargeScale;
  } else { scale.value.x=g_resultPreviewSmallScale; scale.value.y=g_resultPreviewSmallScale; scale.value.z=g_resultPreviewSmallScale; }
  angle.value.x=0;angle.value.y=0;angle.value.z=0;
  position.value.x=0;position.value.y=g_resultPreviewRotationSpeedY;position.value.z=0;
  offset.value.x=0;offset.value.y=(&g_resultPreviewRotationSpeedY)[1];offset.value.z=g_resultPreviewCameraZ;
  if (model==0x1390 || model==0x1392) {
   offset.value.x=0;offset.value.y=(&g_resultPreviewCameraZ)[1];offset.value.z=g_resultPreviewCameraZ;
   scale.value.x=g_resultPreviewLowerCameraScale;scale.value.y=g_resultPreviewLowerCameraScale;scale.value.z=g_resultPreviewLowerCameraScale;
  }
  Frontend_InitModelPreviewTransform(&g_resultsModelPreviewScreen->modelWorkspace,0,scale.words,offset.words);
  Frontend_SetPreviewRotation(&g_resultsModelPreviewScreen->modelWorkspace,angle.words);
  Frontend_SetPreviewRotationSpeed(&g_resultsModelPreviewScreen->modelWorkspace,position.words);
  Model_SetPreviewModel(&g_resultsModelPreviewScreen->modelWorkspace,model);
  g_resultsModelPreviewScreen->rows[index].state=0;
  g_resultsModelPreviewScreen->rows[index].fade=10;
 }
}

#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "ACHIEVE/MODELPREVIEWSCREEN.H"
#include "COMMON/OBJECTRECAT28.H"
#include "TYPES.H"
#if defined(VERSION_DE)
#define Preview_DrawMenuModelItem Frontend_DrawResultModelPreviewDe
#else
void Preview_DrawMenuModelItem(MenuModelItem *item);
#endif
void Achieve_ConfigureResultModelPreview(void);
extern f32 g_resultPreviewDefaultAlpha;

/* Advances the selected row's model preview animation one step: the preview scale (unk8) ramps up by 2
   toward 0x96 in state 0, holds in state 2 while the countdown (unkC) runs, and ramps back down to 10 in
   state 1, then moves the selection on. */
void Achieve_AdvanceResultModelPreview(void) {
    s32 selected;
    s32 nextFadeScale;
    s32 nextHoldTicks;
    s32 nextFadeOutScale;
    s32 previewState;
    s32 holdTicks;
    s32 selectedWordOffset;

    selected = g_resultsModelPreviewScreen->selected;
    /* The word at +0x1C0 of the screen state has no shared field name yet. */
    if ((g_resultsModelPreviewScreen->rows[selected].model >= 0) && (*((s32 *) ((u8 *) (g_resultsModelPreviewScreen) + 448)) != 0)) {
        g_menuModelFillEnabled = 1;
        g_menuModelFillColor[3] = (f32) g_resultsModelPreviewScreen->rows[selected].fade;
        Preview_DrawMenuModelItem((void *)&g_resultsModelPreviewScreen->modelWorkspace);
        g_menuModelFillColor[3] = g_resultPreviewDefaultAlpha;
        previewState = g_resultsModelPreviewScreen->rows[selected].state;
        g_menuModelFillEnabled = 0;
        switch (previewState) {                          /* irregular */
        case 0:
            nextFadeScale = g_resultsModelPreviewScreen->rows[selected].fade + 2;
            g_resultsModelPreviewScreen->rows[selected].fade = nextFadeScale;
            if (nextFadeScale >= 0x97) {
                g_resultsModelPreviewScreen->rows[selected].fade = 0x96;
                g_resultsModelPreviewScreen->rows[selected].state = 2;
                if (selected <= 0) {
                    selectedWordOffset = selected * 4;
                    if (g_resultsModelPreviewScreen->rows[selected + 1].model > 0) {
                        g_resultsModelPreviewScreen->rows[selected].holdTicks = 0x96;
                        return;
                    }
                    goto block_15;
                }
                selectedWordOffset = selected * 4;
block_15:
                g_resultsModelPreviewScreen->rows[selected].holdTicks = 0x38F;
                return;
            }
            break;
        case 2:
            holdTicks = g_resultsModelPreviewScreen->rows[selected].holdTicks;
            if (holdTicks != 0x38F) {
                nextHoldTicks = holdTicks - 1;
                g_resultsModelPreviewScreen->rows[selected].holdTicks = nextHoldTicks;
                if (nextHoldTicks <= 0) {
                    g_resultsModelPreviewScreen->rows[selected].state = 1;
                    return;
                }
            }
            break;
        case 1:
            nextFadeOutScale = g_resultsModelPreviewScreen->rows[selected].fade - 2;
            g_resultsModelPreviewScreen->rows[selected].fade = nextFadeOutScale;
            if (nextFadeOutScale < 0xA) {
                g_resultsModelPreviewScreen->rows[selected].fade = 0xA;
                g_resultsModelPreviewScreen->selected += 1;
                Achieve_ConfigureResultModelPreview();
            }
            break;
        }
    }
}
