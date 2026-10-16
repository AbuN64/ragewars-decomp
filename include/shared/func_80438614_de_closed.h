#ifndef FUNC_80438614_DE_CLOSED_H
#define FUNC_80438614_DE_CLOSED_H
#include "TYPES.H"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/menu_screen_setup.h"



extern ModelPreviewScreen *D_800E5830;

extern s32 func_80439C80_de(void *,s32);


#if defined(VERSION_DE)
enum { MENU_804387F4_642 = 638 };
#elif defined(VERSION_EU_X)
enum { MENU_804387F4_642 = 647 };
#else
enum { MENU_804387F4_642 = 642 };
#endif


#endif
