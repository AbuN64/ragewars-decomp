#include "include_asm.h"

#if defined(VERSION_EU_X)
extern void SmpButton_WrapButtonWidget(int id);

int Frontend_ClearEuxLoadingHints(void) { SmpButton_WrapButtonWidget(0x1DD); SmpButton_WrapButtonWidget(0x1DE); return 0; }
#endif
