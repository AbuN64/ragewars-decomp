#ifndef UI_TSMOS_SCREENS_PAKINTERFACESCREEN_H
#define UI_TSMOS_SCREENS_PAKINTERFACESCREEN_H
#include "TYPES.H"
/* The PAK interface screen (frontend "PAKInterface"): a header, then four per-user records
   (m_PAKInterfacePlayer[anUser]), each holding four 400-byte player records and the name being typed.
   Only the fields the ROM code reads are named; the rest is padding of the measured size. */
#define PAK_USERS 4
#define PAK_PLAYER_RECORD_SIZE 400
#define PAK_NAME_LENGTH 8
typedef struct PAKNameChar {
    u8 ch;
    u8 attr;
} PAKNameChar;
/* One 400-byte "global" player record; only the fields the update code tests are named. */
typedef struct PAKGlobalPlayer {
    u8 m_Name[8];
    s32 m_Marker;
    s8 m_Slot;
    s8 m_User;
    s8 m_Quick;
    u8 pad0F[393 - 15];
    u8 m_Field189;
    u8 m_Field18A;
    u8 m_Field18B;
    u8 m_Field18C;
    u8 m_Field18D;
    u8 pad18E[PAK_PLAYER_RECORD_SIZE - 398];
} PAKGlobalPlayer;
/* A widget of the screen's user list: the display-list node with the item it draws, its alpha, its x and width, and the previous and next widget. */
struct PAKListItem;
typedef struct PAKUserWidget {
    u8 pad0[8];
    struct PAKListItem *m_pItem;
    u8 padC[4];
    u8 m_Alpha;
    u8 pad11[3];
    u16 m_X;
    u8 pad16[2];
    s16 m_Width;
    u8 pad1A[44 - 26];
    struct PAKUserWidget *m_pPrev;
    struct PAKUserWidget *m_pNext;
    u8 pad34[4];
    char *m_pText;
} PAKUserWidget;
/* One row of the Controller Pak management list: the line shown, the note name and the pages it takes. */
#define PAK_NOTE_ROWS 16
#define PAK_PLAYER(user) (g_pakInterfaceScreen->m_PAKInterfacePlayer[user])
typedef struct PAKNoteRow {
    char m_Line[40];
    char m_Name[20];
    char m_Size[10];
} PAKNoteRow;
/* A name-entry character widget of the display list: the label holding the typed character, its flags and the next widget. */
typedef struct PAKNameWidget {
    u8 pad0[8];
    struct PAKLabel *m_pLabel;
    u8 padC[18 - 12];
    u16 m_Flags;
    u8 pad14[56 - 20];
    struct PAKNameWidget *m_pNext;
} PAKNameWidget;
/* A list row widget; only its alpha byte and its text pointer are used. */
typedef struct PAKLabel {
    u8 m_Unread0[16];
    u8 m_Alpha;
    u8 m_Unread11[56 - 17];
    char *m_pText;
} PAKLabel;
typedef struct PAKInterfacePlayer {
    s32 m_State;
    s32 m_Mode;
    s32 m_Step;
    void *m_pWidget;
    PAKUserWidget *m_pObject;
    s32 m_Panel;
    PAKGlobalPlayer m_MiddleRecords[PAK_USERS];
    PAKNoteRow m_Notes[PAK_NOTE_ROWS];
    char m_TextAB8[2754 - 1624 - PAK_NOTE_ROWS * 70];
    char m_BlocksText[10];
    char m_PagesFreeText[12];
    s32 m_ListCursor;
    s32 m_ListTop;
    PAKLabel *m_ListRows[3];
    s32 m_QuickRecord;
    s32 m_RecordState[PAK_USERS];
    s32 m_RecordField2816[PAK_USERS];
    u8 padB40[2856 - 2816 - PAK_USERS * 4];
    s32 m_SelectedRecord;
    s32 m_FieldB3C;
    s32 m_NameTarget;
    PAKNameChar m_Name[PAK_NAME_LENGTH];
    s32 m_NameCursor;
    s32 m_FieldB48;
    s32 m_FieldB4C;
    u8 padB50[2916 - 2896];
    s32 m_Marker;
} PAKInterfacePlayer;
/* One of the four slots: which user list and which of its four middle records hold the slot's player (-1 for none). */
typedef struct PAKSlotState {
    s32 m_User;
    s32 m_Record;
    s32 m_State;
} PAKSlotState;
/* What the Controller Pak holds for one user: the four middle-list player records, then the marker and a checksum. */
#define PAK_SAVE_DATA_SIZE 1600
#define PAK_CHECKSUM_SEED 7
typedef struct PAKSaveBlock {
    PAKGlobalPlayer m_Records[PAK_USERS];
    s32 m_Marker;
    s32 m_Checksum;
} PAKSaveBlock;
typedef struct PAKInterfaceScreen {
    void *m_pDisplayList;
    void *m_pUserList;
    u8 m_Wipe[28];
    void *m_pFlicker;
    PAKUserWidget *m_pFlickerWidget;
    s32 m_UserBusy[PAK_USERS];
    PAKUserWidget *m_pBarA;
    s32 m_BarStepA;
    PAKUserWidget *m_pBarB;
    s32 m_BarStepB;
    s32 m_ExitPhase;
    s32 m_ExitStep;
    s32 m_Mode;
    PAKInterfacePlayer m_PAKInterfacePlayer[PAK_USERS];
    PAKSlotState m_Slot[PAK_USERS];
    PAKSaveBlock m_SaveBlock;
    s32 m_ExitTarget;
} PAKInterfaceScreen;
#define PAKINTERFACE_MAX_USERS PAK_USERS
extern PAKInterfaceScreen *g_pakInterfaceScreen;
extern s32 PAKInterface_OnInitialUpdate(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnDestroy(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnButtonUp(s32 a, s32 b, s32 c, s32 d);
extern s32 PAKInterface_OnRight(s32 a, s32 b, s32 c, s32 d);
extern PAKGlobalPlayer g_pakGlobalPlayers[PAK_USERS];
/* Per-global-player update flags, 150 bytes apart: the active flag at +0, the pending flag at +25. */
#define PAK_UPDATE_INFO_SIZE 150
#define PAK_UPDATE_ACTIVE 0
#define PAK_UPDATE_PENDING 25
#define PAK_UPDATE_START_PRESSED 120
extern u8 g_pakUpdateInfo[PAK_USERS][PAK_UPDATE_INFO_SIZE];
/* The same record by field: the active and pending flags the update code tests, and the start-pressed flag at +120. */
typedef struct PAKUpdateInfo {
    u8 m_Active;
    u8 m_Unread1[PAK_UPDATE_PENDING - 1];
    u8 m_Pending;
    u8 m_Unread1A[PAK_UPDATE_START_PRESSED - PAK_UPDATE_PENDING - 1];
    u8 m_StartPressed;
    u8 m_Unread79[PAK_UPDATE_INFO_SIZE - PAK_UPDATE_START_PRESSED - 1];
} PAKUpdateInfo;
extern char s_pakInterfaceSourceFile[];
extern s32 AssertFailed(char *file, s32 line, char *expr);
#define PAK_ASSERT(line, cond, expr) \
    if (!(cond)) { \
        if (AssertFailed(s_pakInterfaceSourceFile, line, expr)) { \
            *(char *)0 = 0; \
        } \
    }
extern char s_pakAssertSlotRange[];
extern char s_pakAssertUserRange[];
extern char s_pakAssertIndexRange[];
extern char s_pakAssertUserObject[];
extern char s_pakAssertNoEmptySlot[];
extern char s_pakAssertExitMode[];
extern void TSMOS_InputDisable(void);
extern char s_pakFmtDecimal[];
extern char s_pakFmtLineNamed[];
extern char s_pakFmtLine[];
extern char s_pakAssertNullObject[];
extern char s_pakAssertRow0[];
extern char s_pakAssertRow1[];
extern char s_pakAssertRow2[];
extern char *pText_PAK_Empty[];
extern char *pText_PAK_UnnamedNote[];
extern s32 PAK_GetNoteInfo(s32 anUser, s32 anNote, s32 *apState, char *apName, u8 *apExt, s32 *apPages, s32 *apInfoA, s32 *apInfoB);
extern s32 IsJapName(char *apName, s32 anLength);
extern char *x_sprintf(char *apDst, const char *apFormat, ...);
extern void *SM_DLFindObjectByID(void *apList, u16 anId);
extern s32 PAKInterface_CalcSaveGameSize(void);
extern void PAKInterface_ScrollManagementList(s32 anUser, s32 anDirection);
extern s32 PAKInterface_FindEmptyGlobalSlot(void);
extern void PAKInterface_InitGlobalSlot(s32 anFlag, s32 anSlot);
extern s32 PAKInterface_FindEmptyMiddleSlot(void);
extern s32 PAK_GetPagesFree(s32 anUser, s32 *apPages);
extern s32 PAK_GetNotesFree(s32 anUser, s32 *apNotes);
extern s32 PAK_PagesForBytes(s32 anBytes);
extern s32 Chksum(void *apData, s32 anSize, s32 anSeed);
extern void *memcpy(void *apDst, const void *apSrc, u32 anSize);
extern void CPersistentPlayerData_Initialize(PAKGlobalPlayer *apPlayer);
extern void PAKInterface_RefreshMiddleList(s32 anUser);
extern void PAKInterface_InitPlayerMode(s32 anUser);
extern void PAKInterface_RefreshMiddleNamesForCopy(s32 anUser);
struct WidgetLayout;
/* The screen manager's widget of one user, from the screen's user list. */
extern struct WidgetLayout *PAKInterface_GetUserObject(void *apUserList, s32 anUser);
extern void PAKInterface_SetControlOwner(void *apUserList, s32 anUser, s32 anFlag);
/* A list widget row: the widget's own 14 words, then the global player the row stands for. */
typedef struct PAKListItem {
    u8 m_WidgetHead[14];
    u16 m_WidgetType;
    u8 m_WidgetTail[40];
    PAKGlobalPlayer *m_pPlayer;
} PAKListItem;
/* The engine application record; only the bytes the pak screens read are named: the frontend mode and the language the text tables are indexed with. */
#define ENGINE_APP_FRONTEND_MODE_OFFSET 157725
#define ENGINE_APP_LANGUAGE_OFFSET 159121
#define ENGINE_APP_PLAYER_SETUP_OFFSET 157920
/* The setup bytes of the player being created that a quick-play name entry copies into its record. */
typedef struct PAKPlayerSetup {
    u8 pad0[121];
    u8 m_Field121;
    u8 m_Field122;
    u8 m_Field123;
    u8 pad7C;
    u8 m_Field125;
    u8 pad7E[130 - 126];
    u8 m_Field130;
} PAKPlayerSetup;
typedef struct EngineApp {
    u8 pad0[ENGINE_APP_FRONTEND_MODE_OFFSET];
    u8 m_FrontendMode;
    u8 pad1[ENGINE_APP_PLAYER_SETUP_OFFSET - ENGINE_APP_FRONTEND_MODE_OFFSET - 1];
    PAKPlayerSetup m_PlayerSetup;
    u8 pad2[ENGINE_APP_LANGUAGE_OFFSET - ENGINE_APP_PLAYER_SETUP_OFFSET - sizeof(PAKPlayerSetup)];
    u8 m_Language;
} EngineApp;
extern EngineApp g_engineApp;
extern char *pText_MultiFileName[];
extern char *pText_GameCode[];
extern char *x_strcpy(char *apDst, const char *apSrc);
extern s32 PAK_AnySavesOnPak(char *apFileName, s32 anUser, s32 *apNote);
extern s32 PAK_DeleteNote(s32 anUser, s32 anNote);
extern s32 PAK_FindFirstAvailableExt(s32 anUser, s32 *apExt);
extern s32 PAK_WriteNote(s32 anUser, s32 anSize, void *apData, char *apName, s32 *apExt, char *apGameCode);
extern s32 PAK_ReadNote(s32 anUser, s32 anNote, void *apData, s32 anSize);
extern s32 PAKInterface_CheckForRoomOnPak(s32 anUser, s32 *apResult);
extern void PAKInterface_PrepareSaveBlockForSave(s32 anUser);
extern void PAKInterface_PrepareDataAfterLoad(s32 anUser);
extern PAKListItem *PAKInterface_AddListItem(void *apList, u16 anStringId);


extern char s_pakAssertNextMode[];
extern char s_pakAssertScreenMode[];
extern char s_pakAssertCheckStatus[];
extern s32 PAK_CheckStatus(s32 anUser);
extern s32 PAKInterface_LoadGame(s32 anUser, s32 anNote);
extern s32 PAKInterface_FindEmptyPlayerDataSlot(s32 anUser);
extern s32 PAKInterface_IsPlayerDataListEmpty(s32 anUser);
extern s32 PAKInterface_ValidatePAKAgainstGlobal(s32 anUser);
extern s32 RandomSwapWord(void);
/* The same row when it carries a text string instead of a player. */
typedef struct PAKListTextItem {
    u8 m_WidgetHead[56];
    char *m_pText;
} PAKListTextItem;
extern void SM_DLSetDisabled(PAKUserWidget *apObject, s32 anDisabled);
extern void SM_DLSetVisible(PAKUserWidget *apObject, s32 anVisible);
extern s32 SM_DLIsDisabled(PAKUserWidget *apObject);
extern void SMMU_SwitchUserControlFocusByObject(void *apUserList, s32 anUser, PAKUserWidget *apObject);
extern PAKUserWidget *SMMU_GetActiveControl(void *apUserList, s32 anUser);
extern s32 PAKInterface_GetGlobalPlayerByMarker(s32 anMarker, s32 anSlot);
extern s32 ControllerConnected(s32 anController);
extern s32 PAKInterface_AddPlayerToMiddle(s32 anUser, s32 anSlot);
extern char s_pakAssertSlotObject[];
extern char s_pakAssertListObject[];
extern char s_pakAssertListObjectType[];
extern char s_pakAssertListItem[];
#endif
