#include "COMMON/ANIMATION.H"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_13.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"

/* Creates a frame animation for widget id of the current screen: finds the widget through
   Frontend_FindWidgetByResourceId, allocates and clears a 0x64-byte animation, sets its type fields, widget and
   -1-terminated frame list, counts the frames, initialises its playback state through
   func_80419A18_de, SmpFrameAnim_SetSequenceFrame, SmpFrameAnim_SetSequenceDuration and func_80419A04_de, attaches it to the widget through
   Frontend_InsertWidgetBefore and returns it. */




extern void *Frontend_GetScreenData(s32 index);


extern Animation *Cache_AllocateMemory(s32 size);


extern void func_80419A18_de(Animation *anim, s32 value);

extern void SmpFrameAnim_SetSequenceFrame(Animation *anim, s32 value);

extern void SmpFrameAnim_SetSequenceDuration(Animation *anim, s32 value);

extern void func_80419A04_de(Animation *anim, s32 value);

extern void Frontend_InsertWidgetBefore(s32 widget, Animation *anim);

void SmpFrameAnim_RegisterFrameAnimClass(void) {
    func_802982C4_de(0xB5F, D_00419A4C, D_00419ADC, 3);
}

Animation *func_804198CC_de(s32 id, s32 *frames) {
    s32 widget;
    Animation *anim;

    widget = (s32)Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), (u16)id);
    Frontend_GetScreenData(GetMenuScreenOwner());
    anim = Cache_AllocateMemory(0x64);
    XPlus_FillBytes(anim, 0, 0x64);
    anim->kindB = 0xB5F;
    anim->flags = 8;
    anim->kindA = 0xB5F;
    anim->widget = widget;
    anim->unk54 = 0;
    anim->frames = frames;
    anim->unk5C = 0;
    anim->count = 0;
    while (frames[anim->count] != -1) {
        anim->count++;
    }
    func_80419A18_de(anim, 1);
    SmpFrameAnim_SetSequenceFrame(anim, 0);
    SmpFrameAnim_SetSequenceDuration(anim, 0);
    func_80419A04_de(anim, 0);
    Frontend_InsertWidgetBefore(widget, anim);
    return anim;
}
