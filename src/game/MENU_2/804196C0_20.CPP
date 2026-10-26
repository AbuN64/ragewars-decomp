#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/ANIMATION.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_20.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"

/* Creates a 0x7C-byte fading widget: finds the frame the low half of the first argument names and
   the item the second names in the current context through GetMenuScreenOwner, Frontend_GetScreenData and
   Frontend_FindWidgetByResourceId, allocates and zeroes the widget, tags it 0xB60 with kind 8, links the frame at
   0x44 (clearing its word at 0x20 and setting 0x24 to D_800E1474) and the item at 0x48, sets both
   scales at 0x4C and 0x50 to D_800E1470, copies the item's two colours at 0x2C and 0x30 to 0x60,
   stores the green and red differences between them over 75 steps at 0x70 and 0x74, marks it
   active at 0x78, starts it through func_8041A47C_de and func_8041A430_de(1) and attaches it to the
   frame through Frontend_InsertWidgetBefore. Returns the widget. */







extern s32 GetMenuScreenOwner(void);
extern void *Frontend_GetScreenData(s32 index);
extern MenuFadeWidget *Cache_AllocateMemory(s32);
extern void func_8041A47C_de(MenuFadeWidget *);
extern void func_8041A430_de(MenuFadeWidget *, s32);
extern void Frontend_InsertWidgetBefore(MenuFadeWidget *, MenuFadeWidget *);

MenuFadeWidget *func_8041A280_de(s32 frameId, s32 itemId) {
    MenuFadeWidget *frame;
    s32 context;
    MenuFadeWidget *result;

    frame = Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), frameId & 0xFFFF);
    context = Frontend_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x7C);
    XPlus_FillBytes(result, 0, 0x7C);
    result->field_0E = 0xB60;
    result->field_12 = 8;
    result->field_0C = 0xB60;
    result->frame = frame;
    result->item = Frontend_FindWidgetByResourceId((void*)context, itemId & 0xFFFF);
    result->scaleX = D_800E1470;
    result->scaleY = D_800E1470;
    result->frame->field_20 = 0;
    result->frame->field_24 = D_800E1474;
    result->copies[0] = result->item->colours[0];
    result->copies[1] = result->item->colours[1];
    result->copies[2] = result->item->colours[2];
    result->copies[3] = result->item->colours[3];
    result->greenStep = (((result->item->colours[1] & 0xFF0000) >> 16) -
                         ((result->item->colours[0] & 0xFF0000) >> 16)) / 75;
    result->redStep = (((u8 *)result->item->colours)[0] - ((u8 *)result->item->colours)[4]) / 75U;
    result->active = 1;
    func_8041A47C_de(result);
    func_8041A430_de(result, 1);
    Frontend_InsertWidgetBefore(frame, result);
    return result;
}


void SmpFade_RegisterFadeClass(void) {
    func_802982C4_de(0xB60, D_0041A490, D_0041A520, 3);
}
