#include "include_asm.h"

#if defined(VERSION_DE)
typedef struct Func_8042D9F0_State {
    void *list;
    void *resourceWidget;
    void *item;
    s32 unkC;
    char pad10[4];
    char text14[0xC];
    s32 unk20;
} Func_8042D9F0_State;
typedef struct { char pad0[0x10]; u8 unk10; char pad11[0x27]; void *unk38; } Func_8042D9F0_Part;
extern Func_8042D9F0_State *D_800E5430;
extern char D_800E1B60[];
extern void *Cache_AllocateMemory(s32 size);
extern void Tsmos_ActivateControllerState(void);
extern void *SmpFade_CreateFadeWidget(s32 a, s32 b);
extern void SmpSlider_EnableTransition(void *p);
extern void SmpButton_WrapButtonWidget(s32 a);
extern void *Node_FindWidgetByResourceId(s32 owner, s32 id);
extern void *SmpFlicker_CreateFlickerWidget(s32 a, s32 b);
extern void XStdio_FormatBuffer(void *a, void *b, s32 c);
/* Builds the 0x24-byte state D_800E5430 from the resources 0x392 to 0x397, hooks its list at 0x14 into the part Node_FindWidgetByResourceId returns for 0x397 and registers it with XStdio_FormatBuffer; returns zero. */
s32 Frontend_CreatePlayerCountScreenDe(s32 root) {
    Func_8042D9F0_Part *part;
    D_800E5430 = (Func_8042D9F0_State *)Cache_AllocateMemory(0x24);
    Tsmos_ActivateControllerState();
    D_800E5430->list = SmpFade_CreateFadeWidget(0x392, 0x393);
    SmpSlider_EnableTransition(D_800E5430->list);
    SmpButton_WrapButtonWidget(0x396);
    part = (Func_8042D9F0_Part *)Node_FindWidgetByResourceId(root, 0x394);
    D_800E5430->item = part;
    part->unk10 = 0xF;
    D_800E5430->resourceWidget = SmpFlicker_CreateFlickerWidget(0x395, 0x6E);
    D_800E5430->unkC = 3;
    part = (Func_8042D9F0_Part *)Node_FindWidgetByResourceId(root, 0x397);
    part->unk38 = D_800E5430->text14;
    D_800E5430->unk20 = 1;
    XStdio_FormatBuffer(D_800E5430->text14, D_800E1B60, 1);
    return 0;
}
#endif
