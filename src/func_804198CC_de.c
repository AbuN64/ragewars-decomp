#include "span_16E000/code_804196C0.h"
#include "types.h"
/* Creates a frame animation for widget id of the current screen: finds the widget through
   func_8040EC30_de, allocates and clears a 0x64-byte animation, sets its type fields, widget and
   -1-terminated frame list, counts the frames, initialises its playback state through
   func_80419A18_de, func_804199DC_de, func_804199E4_de and func_80419A04_de, attaches it to the widget through
   func_8040EDE4_de and returns it. */



extern s32 func_80299958_de(void);
extern s32 func_80411DCC_de(s32);
extern s32 func_8040EC30_de(s32 screen, u16 id);
extern Animation *func_8025305C_de(s32 size);
extern void func_802A0748_de(void *p, s32 c, s32 n);
extern void func_80419A18_de(Animation *anim, s32 value);
extern void func_804199DC_de(Animation *anim, s32 value);
extern void func_804199E4_de(Animation *anim, s32 value);
extern void func_80419A04_de(Animation *anim, s32 value);
extern void func_8040EDE4_de(s32 widget, Animation *anim);

Animation *func_804198CC_de(s32 id, s32 *frames) {
    s32 widget;
    Animation *anim;

    widget = func_8040EC30_de(func_80411DCC_de(func_80299958_de()), id);
    func_80411DCC_de(func_80299958_de());
    anim = func_8025305C_de(0x64);
    func_802A0748_de(anim, 0, 0x64);
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
