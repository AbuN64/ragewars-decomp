#include "COMMON/FRUSTUM.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/ANIMATION.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU/SMPFADE_REGISTERFADECLASS.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "include_asm.h"

/* 804196C0_20.CPP */
/* Creates a 0x7C-byte fading widget: finds the frame the low half of the first argument names and
   the item the second names in the current context through GetMenuScreenOwner, Node_GetScreenData and
   Node_FindWidgetByResourceId, allocates and zeroes the widget, tags it 0xB60 with kind 8, links the frame at
   0x44 (clearing its word at 0x20 and setting 0x24 to D_800E1474) and the item at 0x48, sets both
   scales at 0x4C and 0x50 to D_800E1470, copies the item's two colours at 0x2C and 0x30 to 0x60,
   stores the green and red differences between them over 75 steps at 0x70 and 0x74, marks it
   active at 0x78, starts it through SmpSlider_EnableTransition and SmpSlider_SetTransitionMode(1) and attaches it to the
   frame through Node_InsertWidgetBefore. Returns the widget. */

extern MenuFadeWidget *Cache_AllocateMemory(s32);
extern void SmpSlider_EnableTransition(MenuFadeWidget *);
extern void SmpSlider_SetTransitionMode(MenuFadeWidget *, s32);
extern void Node_InsertWidgetBefore(MenuFadeWidget *, MenuFadeWidget *);

MenuFadeWidget *SmpFade_CreateFadeWidget(s32 frameId, s32 itemId) {
    MenuFadeWidget *frame;
    s32 context;
    MenuFadeWidget *result;

    frame = Node_FindWidgetByResourceId(Node_GetScreenData(GetMenuScreenOwner()), frameId & 0xFFFF);
    context = Node_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x7C);
    XPlus_FillBytes(result, 0, 0x7C);
    result->field_0E = 0xB60;
    result->field_12 = 8;
    result->field_0C = 0xB60;
    result->frame = frame;
    result->item = Node_FindWidgetByResourceId((void*)context, itemId & 0xFFFF);
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
    SmpSlider_EnableTransition(result);
    SmpSlider_SetTransitionMode(result, 1);
    Node_InsertWidgetBefore(frame, result);
    return result;
}

void SmpFade_RegisterFadeClass(void) {
    SmSmngr_RegisterElementHandlers(0xB60, D_0041A490, D_0041A520, 3);
}

/* 800E1470.CPP */
#if !(defined(VERSION_US_REV1))
const unsigned int D_8041A280_E2070[2] = {
    0x3EAAAAAB, 0x3D4CCCCD,
};
#endif

#if defined(VERSION_US)
unsigned int rodata_unresolved_800DC0F8[2] = {
    0x00000000, 0x00164D55,
};
#endif

#if defined(VERSION_EU_X)
unsigned int rodata_unresolved_800E8C88[2] = {
    0x3DDD67C9, 0x3F000000,
};
#endif

#if defined(VERSION_EU)
unsigned int rodata_unresolved_800EDAC8[2] = {
    0x0800FFE0, 0x01270134,
};
#endif

#if defined(VERSION_DE)
#if defined(VERSION_DE)
unsigned int rodata_unresolved_800DD448[2] = {
    (unsigned int)&D_800C8380_de + 0x70, (unsigned int)&D_800C8420_de + 0x90,
};
#endif
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_pool_8041A280_E2070_us_rev1.c */
const unsigned int D_blob_1466e2b8289b860d4bb9[2] = {
    0x3EAAAAAB, 0x3D4CCCCD,
};
#endif
