#ifndef COMMON_EXTERNS_13_H
#define COMMON_EXTERNS_13_H
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/SHARED_DEBUGFIELD.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/SHARED_MENUSELECTION.H"
#include "COMMON/UNUSED.H"
#include "TYPES.H"



struct PlayerRankInner;


#include "COMMON/ITEMRECAT20V1.H"









#include "COMMON/BALLISTICPARAMS.H"




#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern char D_800EED80[];
#else
extern char D_800DE700[];
#endif
extern s32 Weapons_GetPlayerIndex(void *, void *);
extern s32 func_80441FE8_de(Shared_DebugWidget *);
#endif
