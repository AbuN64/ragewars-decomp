#include "COMMON/ANIMATION.H"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "MATH/80297CD0_3.H"
#include "MENU_2/804196C0_13.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"

/* Creates a frame animation for widget id of the current screen: finds the widget through
   func_8040EC30_de, allocates and clears a 0x64-byte animation, sets its type fields, widget and
   -1-terminated frame list, counts the frames, initialises its playback state through
   func_80419A18_de, func_804199DC_de, func_804199E4_de and func_80419A04_de, attaches it to the widget through
   func_8040EDE4_de and returns it. */



extern s32 GetMenuScreenOwner(void);

extern void *Frontend_GetScreenData(s32 index);


extern Animation *Scene_AllocateMemory(s32 size);


extern void func_80419A18_de(Animation *anim, s32 value);

extern void func_804199DC_de(Animation *anim, s32 value);

extern void func_804199E4_de(Animation *anim, s32 value);

extern void func_80419A04_de(Animation *anim, s32 value);

extern void func_8040EDE4_de(s32 widget, Animation *anim);

void Menu_RegisterFrameAnimClass(void) {
    func_802982C4_de(0xB5F, D_00419A4C, D_00419ADC, 3);
}

Animation *func_804198CC_de(s32 id, s32 *frames) {
    s32 widget;
    Animation *anim;

    widget = (s32)func_8040EC30_de(Frontend_GetScreenData(GetMenuScreenOwner()), (u16)id);
    Frontend_GetScreenData(GetMenuScreenOwner());
    anim = Scene_AllocateMemory(0x64);
    Resmgr_FillBytes(anim, 0, 0x64);
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
    func_804199DC_de(anim, 0);
    func_804199E4_de(anim, 0);
    func_80419A04_de(anim, 0);
    func_8040EDE4_de(widget, anim);
    return anim;
}
