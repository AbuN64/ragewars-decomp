#ifndef COMMON_SHARED_MENUREPLY_H
#define COMMON_SHARED_MENUREPLY_H
#include "COMMON/WORLD.H"
#include "TYPES.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/SCREEN.H"
#include "COMMON/GLOBALS.H"
#include "COMMON/ANIMATION.H"

int func_80245798_de(void);
void func_8025476C_de(unsigned int);
void func_802991D4_de(s32);
void func_802A2360_de(void);
void func_80419F58_de(void *, int);
s32 func_8043C308_de(Shared_OptionsScreen *);
void func_804499B0_de(void *, s32, s32);
void func_8044A370_de(void *, s32);
void func_80286AA8_de(void *, s32, s32);
void func_80298368_de(s32);

extern Shared_MenuReply D_80154020;

extern Shared_OptionsScreen *D_800E4518;

/* Advances the menu transition and dispatches the selected level once its animations finish. */
#endif
