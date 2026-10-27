#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "MENU/EXTERNS.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "MATH/802A2870.H"

#if defined(VERSION_US)
extern s32 Frontend_ComputeWidgetBounds(QuadN64EngDrawNumericWidgetChildren *, QuadN64EngDrawNumericWidgetChildren *, void *, Args *);

extern void N64Eng_GetClipBounds(u32 *, u32 *, u32 *, u32 *);

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void Frontend_DrawVisibleSiblings(void *, Args);

s32 func_8040C638_us(s32 arg0) {
    arg0 << 0;
    return 0;
}

void Event_DrawClippedWidgetChildren(void *arg0, Args args) {
    func_802A2BE0_S1 *record = arg0;
    QuadN64EngDrawNumericWidgetChildren first;
    QuadN64EngDrawNumericWidgetChildren basis;
    QuadN64EngDrawNumericWidgetChildren value;
    QuadN64EngDrawNumericWidgetChildren transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, arg0, &args) != 0) {
        if ((record->unk12 & 0x200) != 0) {
            N64Eng_GetClipBounds(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            N64Eng_SetClipBounds(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(record->unk8, args);
        if (changed != 0) {
            N64Eng_SetClipBounds(value.x, value.z, value.y, value.w);
        }
    }
}
#endif

#if defined(VERSION_US)
unsigned int s_prefText[1] = {
    0x50726566,
};
#endif
