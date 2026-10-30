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
typedef struct PAKInterfacePlayer {
    s32 m_State;
    s32 m_Mode;
    s32 m_Step;
    void *m_pWidget;
    u8 pad10[4];
    s32 m_Panel;
    u8 m_MiddleRecords[PAK_USERS][PAK_PLAYER_RECORD_SIZE];
    u8 pad65C[2864 - 24 - PAK_USERS * PAK_PLAYER_RECORD_SIZE];
    s32 m_NameTarget;
    PAKNameChar m_Name[PAK_NAME_LENGTH];
    s32 m_NameCursor;
    u8 padB48[2916 - 2888];
    s32 m_Marker;
} PAKInterfacePlayer;
typedef struct PAKSlotState {
    s32 m_State;
    s32 pad4;
    s32 pad8;
} PAKSlotState;
typedef struct PAKInterfaceScreen {
    s32 m_Unread0;
    void *m_pUserList;
    u8 pad8[44 - 8];
    s32 m_UserBusy[PAK_USERS];
    u8 pad3C[88 - 60];
    PAKInterfacePlayer m_PAKInterfacePlayer[PAK_USERS];
    s32 m_CopyUser;
    s32 m_Unread2EF4;
    PAKSlotState m_Slot[PAK_USERS];
} PAKInterfaceScreen;
/* One 400-byte "global" player record; only the fields the update code tests are named. */
typedef struct PAKGlobalPlayer {
    u8 pad0[8];
    s32 m_Marker;
    s8 m_Slot;
    s8 m_User;
    s8 m_Quick;
    u8 pad0F[PAK_PLAYER_RECORD_SIZE - 15];
} PAKGlobalPlayer;
extern PAKInterfaceScreen *g_pakInterfaceScreen;
extern PAKGlobalPlayer g_pakGlobalPlayers[PAK_USERS];
/* Per-global-player update flags, 150 bytes apart: the active flag at +0, the pending flag at +25. */
#define PAK_UPDATE_INFO_SIZE 150
#define PAK_UPDATE_ACTIVE 0
#define PAK_UPDATE_PENDING 25
extern u8 g_pakUpdateInfo[PAK_USERS][PAK_UPDATE_INFO_SIZE];
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
extern char s_pakAssertUserObject[];
extern void *memcpy(void *apDst, const void *apSrc, u32 anSize);
extern void CPersistentPlayerData_Initialize(PAKGlobalPlayer *apPlayer);
extern void PAKInterface_RefreshMiddleList(s32 anUser);
extern void PAKInterface_InitPlayerMode(s32 anUser);
extern void PAKInterface_RefreshMiddleNamesForCopy(s32 anUser);
extern void *PAKInterface_GetUserObject(void *apUserList, s32 anUser);
extern void PAKInterface_SetControlOwner(void *apUserList, s32 anUser, s32 anFlag);
/* A list widget row: the widget's own 14 words, then the global player the row stands for. */
typedef struct PAKListItem {
    s32 m_Widget[14];
    PAKGlobalPlayer *m_pPlayer;
} PAKListItem;
extern PAKListItem *PAKInterface_AddListItem(void *apList, u16 anStringId);


#endif
