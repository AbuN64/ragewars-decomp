#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"

/* 800DE794.CPP */
#if defined(VERSION_DE)
unsigned int g_itemsConstantWords[3] = {
    0x64000000, 0x20253364, 0x00000000,
};
#endif

/* 8043EA40.CPP */
#if defined(VERSION_EU)
#ifdef NON_MATCHING
extern u8 g_europeanMenuToggleRow2;
extern u8 g_europeanMenuToggleRow3;
extern u8 g_europeanMenuToggleRow4;
extern u8 g_europeanMenuToggleRow5;
extern u8 g_europeanMenuToggleRow6;
extern u8 g_europeanMenuToggleRow7;
extern u8 g_europeanMenuToggleRow8;
extern u8 g_europeanMenuToggleRow9;
extern char *g_europeanMenuToggleRow2EnabledText[];
extern char *g_europeanMenuToggleRow2DisabledText[];
extern char *g_europeanMenuToggleRow3EnabledText[];
extern char *g_europeanMenuToggleRow3DisabledText[];
extern char *g_europeanMenuToggleRow4EnabledText[];
extern char *g_europeanMenuToggleRow4DisabledText[];
extern char *g_europeanMenuToggleRow5EnabledText[];
extern char *g_europeanMenuToggleRow5DisabledText[];
extern char *g_europeanMenuToggleRow6EnabledText[];
extern char *g_europeanMenuToggleRow6DisabledText[];
extern char *g_europeanMenuToggleRow7EnabledText[];
extern char *g_europeanMenuToggleRow7DisabledText[];
extern char *g_europeanMenuToggleRow8EnabledText[];
extern char *g_europeanMenuToggleRow8DisabledText[];
extern char *g_europeanMenuToggleRow9EnabledText[];
extern char *g_europeanMenuToggleRow9DisabledText[];
/* Picks the label for each of the eight option rows (ids 2..9): the first text when the row's flag is set, else the second. */
typedef struct { s32 id; u8 pad4[0x10]; char ***text; } OptionRowEu;
s32 Items_SelectOptionRowLabel(OptionRowEu *row) {
    switch (row->id) {
    case 2: row->text = g_europeanMenuToggleRow2 ? g_europeanMenuToggleRow2EnabledText : g_europeanMenuToggleRow2DisabledText; break;
    case 3: row->text = g_europeanMenuToggleRow3 ? g_europeanMenuToggleRow3EnabledText : g_europeanMenuToggleRow3DisabledText; break;
    case 4: row->text = g_europeanMenuToggleRow4 ? g_europeanMenuToggleRow4EnabledText : g_europeanMenuToggleRow4DisabledText; break;
    case 5: row->text = g_europeanMenuToggleRow5 ? g_europeanMenuToggleRow5EnabledText : g_europeanMenuToggleRow5DisabledText; break;
    case 6: row->text = g_europeanMenuToggleRow6 ? g_europeanMenuToggleRow6EnabledText : g_europeanMenuToggleRow6DisabledText; break;
    case 7: row->text = g_europeanMenuToggleRow7 ? g_europeanMenuToggleRow7EnabledText : g_europeanMenuToggleRow7DisabledText; break;
    case 8: row->text = g_europeanMenuToggleRow8 ? g_europeanMenuToggleRow8EnabledText : g_europeanMenuToggleRow8DisabledText; break;
    case 9: row->text = g_europeanMenuToggleRow9 ? g_europeanMenuToggleRow9EnabledText : g_europeanMenuToggleRow9DisabledText; break;
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", Items_SelectOptionRowLabel);
#endif
#endif

/* 80443530.CPP */
#if defined(VERSION_EU_X)
#include "TYPES.H"
extern s32 g_activeActorKind;
extern s32 Menu_ClassifyResourceRange(s32);

void Items_PrepareMenuReturnEuX(void) {
    g_controllerReturnResourceRange = Menu_ClassifyResourceRange(g_activeActorKind);
    g_controllerReturnPending = 1;
}
#endif
