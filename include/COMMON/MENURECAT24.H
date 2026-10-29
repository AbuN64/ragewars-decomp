#ifndef COMMON_MENURECAT24_H
#define COMMON_MENURECAT24_H
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
extern s32 D_8014AD94;

extern char D_0044EB70[];

extern int g_pakScoreAtLeast9999Title;


struct PakPromptContext;
typedef struct PakPromptContext PakPromptContext;


extern s32 D_80153760;


struct Messages;
struct Messages {
    char pad0[0x554];
    char text[1];
};
struct Messages;
struct PlayerMessageMenuView;
struct PlayerMessageMenuView {
    char pad0[0x5DC];
    struct Messages *messages;
    char pad5E0[0xC];
    s32 menu;
};

extern s32 D_80153784;

extern s32 D_8014D4C0_de;

extern int g_pakScoreBelow150Title;

extern s32 D_80146D60;

extern int g_pakScoreBelow300Title;

struct PakPromptContext;
struct PlayerMessageMenuView;

struct PakPromptContext;

struct PakNoteTextEntry;
typedef struct PakNoteTextEntry PakNoteTextEntry;

struct PakNoteBrowserContext;

extern char *g_pakSnapshotGameNameFixed;

struct PakPromptContext;

struct PakPromptContext;


extern int g_pakScoreBelow500Title;

extern int g_pakScoreBelow50Title;

extern int g_pakScoreBelow800Title;

extern int g_pakScoreBelow1300Title;

extern int g_pakScoreBelow3000Title;

extern s32 D_8014D4EC_de;

struct PakNoteBrowserContext;
typedef struct PakNoteBrowserContext PakNoteBrowserContext;


extern int g_pakAlternatePromptEnabled;

extern int g_pakScoreBelow6500Title;

struct PlayerMessageMenuView;
typedef struct PlayerMessageMenuView PlayerMessageMenuView;

extern s32 D_8014AD9C;

extern s32 D_8014D4DC;

extern int g_controllerPakOverwriteNoteIndex;

extern char D_0044EBDC[];

extern int g_pakScoreBelow2000Title;


extern s32 g_introSelectedItem;

struct PlayerPakTimerView;
typedef struct PlayerPakTimerView PlayerPakTimerView;


struct PlayerPakTimerView;


extern s32 D_800DE874;



extern int g_pakScoreBelow9999Title;

struct PakNoteTextEntry;

extern char *g_pakProfileGameNameFixed;

extern int g_pakScoreBelow4500Title;

extern s32 D_80142CAC;



struct PlayerSavedProfileOwner;

struct PakStatusPakSaveMenu;
struct PakNotesMenu;
#endif
