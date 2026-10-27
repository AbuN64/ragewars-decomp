#ifndef SCENARIOSETUPSCREEN_SCENARIOSETUPSCREEN_H
#define SCENARIOSETUPSCREEN_SCENARIOSETUPSCREEN_H
#include "COMMON/UNUSED.H"
extern void ScenarioSetup_SetCatalogueAlpha(s32 alpha);
extern void ScenarioSetup_RefreshSelectedArenaLabel(void);
extern void ScenarioSetup_StartSelectedScenario(void);
extern s32 ScenarioSetup_IsCupSelected(void);
extern s32 ScenarioSetup_IsCupComplete(void);
extern s32 ScenarioSetup_ReturnResultsGateTrue(void);
extern void ScenarioSetup_SetCupStageCount(s32 value);
extern void ScenarioSetup_LoadSetupArenaLabel(void);
extern void ScenarioSetup_HideSetupCatalogue(void);
extern void ScenarioSetup_HideArenaCatalogueWidgets(void);
extern int ScenarioSetup_GetCategoryEntryCount(int index);
extern s32 ScenarioSetup_ResolveArenaFromSelection(s32, s32);
extern s32 ScenarioSetup_CategoryToList(s32 category);
extern s32 ScenarioSetup_ReturnSetupEventZero(void);
extern void ScenarioSetup_ClearFlagBits(void);
extern s32 ScenarioSetup_CloseSetupScreen(void);
extern s32 ScenarioSetup_ReturnSetupEventZeroAlt(void);
extern s32 ScenarioSetup_BeginSetupConfirmation(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 ScenarioSetup_SelectPreviousCatalogueItem(void *unused0, void *unused1, void *unused2, s32 event);
extern s32 ScenarioSetup_SelectNextSetupItem(void *unused0, void *unused1, void *unused2, s32 event);
extern s32 ScenarioSetup_SelectPreviousCatalogueCategory(void *unused0, void *unused1, void *unused2, s32 event);
extern s32 ScenarioSetup_SelectNextCatalogueCategory(void *unused0, void *unused1, void *unused2, s32 event);
extern s32 ScenarioSetup_EndSetupInput(void);
extern s32 ScenarioSetup_RefreshSetupScreen(void);
extern s32 ScenarioSetup_DispatchCatalogueEvent(void *, s32, s32, s32, s32);
extern s32 ScenarioSetup_OpenResultsScreen(void *root);
extern void ScenarioSetup_FillResultRows(void);
extern void ScenarioSetup_SortResultsPlayers(void);
extern void ScenarioSetup_HideResultCatalogueWidgets(void);
extern void ScenarioSetup_InitResultModelPreview(void);
#endif
