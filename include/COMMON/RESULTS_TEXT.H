#ifndef COMMON_RESULTS_TEXT_H
#define COMMON_RESULTS_TEXT_H
/* Results-screen texts: one per language in PAL builds, chosen by the game settings. */
#include "TYPES.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/MENU_TEXT.H"
/* The game settings record. */
static inline Shared_Game *currentGame(void) {
    return &g_gameSettings;
}
#if defined(VERSION_EU) || defined(VERSION_EU_X)
/* PAL builds keep one text per language, chosen by the game settings. */
#define RESULTS_LANGUAGE (currentGame()->language)
extern ResultsHeadingCharacter g_resultCharacterHeadingTranslations[];
extern char g_resultsHeadingText[];
extern char *g_characterPreviewTextReferenceEu1[], *g_characterPreviewTextReferenceShared6[], *g_characterPreviewTextReferenceEu3[], *g_characterPreviewTextReferenceShared7[], *g_characterPreviewTextReferenceShared8[], *g_resultsRoundsOneFormatLocalized[],
    *g_resultsRoundsTwoFormatLocalized[], *g_resultsRoundsThreeFormatLocalized[], *g_resultsLapsOneFormatLocalized[], *g_resultsLapsTwoFormatLocalized[], *g_resultsLapsThreeFormatLocalized[], *g_resultsLapsFourFormatLocalized[],
    *g_resultsLapsFiveFormatLocalized[], *g_resultsGoalOneFormatLocalized[], *g_resultsGoalTwoFormatLocalized[], *g_resultsTimeLimitFormatLocalized[], *g_resultsMinutesSecondsOneFormatLocalized[], *g_resultsMinutesSecondsTwoFormatLocalized[],
    *g_resultsMinutesOneFormatLocalized[], *g_resultsMinutesTwoFormatLocalized[], *g_resultsPlayerOrLivesOneFormatLocalized[], *g_resultsPlayerOrLivesTwoFormatLocalized[], *g_resultsGoalLabelFormatLocalized[], *g_resultsGoalValueFormatLocalized[],
    *g_slotSelectionTextReferenceEu7[];
#define RESULTS_CHARACTERS g_resultCharacterHeadingTranslations
#define RESULTS_NAME_FORMAT g_resultsHeadingText
#else
#define RESULTS_LANGUAGE 0
#define RESULTS_CHARACTERS g_resultCharacterHeadings
#define RESULTS_NAME_FORMAT g_resultsNameFormat_de
#endif
/* A results text in the language the game settings select. */
#define RESULTS_TEXT(fixed, table) RW_LOCALIZED_TEXT(fixed, table, table, RESULTS_LANGUAGE)
#endif
