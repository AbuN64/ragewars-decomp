#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
extern struct Menu_func_80437718_de *D_800E5784;
#include "SCENE/802508E0_13.H"

/* Builds a three-item menu: allocates 0x14 bytes into D_800E5784 through Cache_AllocateMemory, creates the
   title 0x3CC/0x3CD through SmpFade_CreateFadeWidget and the button 0x3CF through SmpFlicker_CreateFlickerWidget with 0x6E,
   finds entry 0x3CE of the list through Frontend_FindWidgetByResourceId and sets its byte at 0x10 to 0xF, and stores
   the three with 3 and -1 in the block. Returns zero. */


extern struct Menu_func_80437718_de *Cache_AllocateMemory(s32);

extern void *SmpFade_CreateFadeWidget(s32, s32);

extern void *SmpFlicker_CreateFlickerWidget(s32, s32);

extern struct ResourceSmpFlickerCreateFlickerWidget *Frontend_FindWidgetByResourceId(void *, s32);

/* Releases the object D_800E5784 holds through Cache_FreeMemory, clears D_800E5784 and returns zero. */



s32 func_80437718_de(void *list) {
    struct ResourceSmpFlickerCreateFlickerWidget *item;
    D_800E5784 = Cache_AllocateMemory(0x14);
#if defined(VERSION_DE)
    D_800E5784->title = SmpFade_CreateFadeWidget(0x3C6, 0x3C6 + 1);
    D_800E5784->button = SmpFlicker_CreateFlickerWidget(0x3C6 + 3, 0x6E);
    item = Frontend_FindWidgetByResourceId(list, 0x3C6 + 2);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    D_800E5784->title = SmpFade_CreateFadeWidget(0x3CC, 0x3CC + 1);
    D_800E5784->button = SmpFlicker_CreateFlickerWidget(0x3CC + 3, 0x6E);
    item = Frontend_FindWidgetByResourceId(list, 0x3CC + 2);
#elif defined(VERSION_EU_X)
    D_800E5784->title = SmpFade_CreateFadeWidget(0x3D0, 0x3D0 + 1);
    D_800E5784->button = SmpFlicker_CreateFlickerWidget(0x3D0 + 3, 0x6E);
    item = Frontend_FindWidgetByResourceId(list, 0x3D0 + 2);
#endif
    D_800E5784->item = item;
    item->value = 0xF;
    D_800E5784->count = 3;
    D_800E5784->selection = -1;
    return 0;
}

s32 func_804377B8_de(void) {
    Cache_FreeMemory(D_800E5784);
    D_800E5784 = 0;
    return 0;
}
