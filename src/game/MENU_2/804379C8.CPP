#include "COMMON/MENUSELECTIONMESSAGE.H"
#include "TYPES.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU_X))
/* Calls SmpButton_WrapButtonWidget with 0x3D0 and then 0x3D1, and returns zero. */
extern void SmpButton_WrapButtonWidget(s32);

s32 Menu_WrapTitleButtonScreenNodes(void) {
    SmpButton_WrapButtonWidget(0x3D0);
    SmpButton_WrapButtonWidget(0x3D1);
    return 0;
}
#endif
