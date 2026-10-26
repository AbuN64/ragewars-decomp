#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "MENU/EXTERNS.H"
#include "COMMON/OWNERRECAT8V1.H"
#include "MATH/802A2870.H"

#if defined(VERSION_US)
extern s32 Frontend_ComputeWidgetBounds(Quad_func_802A1BE0_de *, Quad_func_802A1BE0_de *, void *, Args *);

extern void func_802A1898_de(u32 *, u32 *, u32 *, u32 *);

extern s32 Frontend_ClampRectToClip(struct Shape_typemap_165 *rect, struct Shape_typemap_165 *clip);


extern void Frontend_DrawVisibleSiblings(void *, Args);

s32 func_8040C638_us(s32 arg0) {
    arg0 << 0;
    return 0;
}

void Event_DrawClippedWidgetChildren(void *arg0, Args args) {
    func_802A2BE0_S1 *record = arg0;
    Quad_func_802A1BE0_de first;
    Quad_func_802A1BE0_de basis;
    Quad_func_802A1BE0_de value;
    Quad_func_802A1BE0_de transformed;
    s32 changed;

    changed = 0;
    if (Frontend_ComputeWidgetBounds(&first, &basis, arg0, &args) != 0) {
        if ((record->unk12 & 0x200) != 0) {
            func_802A1898_de(&value.x, &value.z, &value.y, &value.w);
            transformed = value;
            Frontend_ClampRectToClip(&transformed, &basis);
            func_802A1870_de(transformed.x, transformed.z,
                          transformed.y, transformed.w);
            changed = 1;
        }
        Frontend_DrawVisibleSiblings(record->unk8, args);
        if (changed != 0) {
            func_802A1870_de(value.x, value.z, value.y, value.w);
        }
    }
}
#endif

#if defined(VERSION_US)
unsigned int s_prefText[1] = {
    0x50726566,
};
#endif
