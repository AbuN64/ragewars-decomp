#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "MATH/802A2870.H"
extern s32 func_8040E0D4_de(Shared_Quad *, Shared_Quad *, MenuWidget *, DrawArgs *);
extern void func_802A1898_de(s32 *, s32 *, s32 *, s32 *);
extern s32 func_8040F488_de(Shared_Quad *, Shared_Quad *);
extern void func_8040E7FC_de(MenuWidget *, DrawArgs);

#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
s32 func_8040C9F8_eu_x(void) {
    return 0;
}

#if defined(VERSION_EU_X)
void func_8040CA08(MenuWidget *widget, DrawArgs args) {
    Shared_Quad area;
    Shared_Quad basis;
    Shared_Quad saved;
    Shared_Quad clip;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&area, &basis, widget, &args) != 0) {
        if (widget->flags & 0x200) {
            func_802A1898_de(&saved.w[0], &saved.w[2], &saved.w[1], &saved.w[3]);
            clip = saved;
            func_8040F488_de(&clip, &basis);
            func_802A1870_de(clip.w[0], clip.w[2], clip.w[1], clip.w[3]);
            changed = 1;
        }
        func_8040E7FC_de(widget->child, args);
        if (changed != 0) {
            func_802A1870_de(saved.w[0], saved.w[2], saved.w[1], saved.w[3]);
        }
    }
}
#endif
#if defined(VERSION_US_REV1)
void func_8040C648(MenuWidget *widget, DrawArgs args) {
    Shared_Quad area;
    Shared_Quad basis;
    Shared_Quad saved;
    Shared_Quad clip;
    s32 changed;

    changed = 0;
    if (func_8040E0D4_de(&area, &basis, widget, &args) != 0) {
        if (widget->flags & 0x200) {
            func_802A1898_de(&saved.w[0], &saved.w[2], &saved.w[1], &saved.w[3]);
            clip = saved;
            func_8040F488_de(&clip, &basis);
            func_802A1870_de(clip.w[0], clip.w[2], clip.w[1], clip.w[3]);
            changed = 1;
        }
        func_8040E7FC_de(widget->child, args);
        if (changed != 0) {
            func_802A1870_de(saved.w[0], saved.w[2], saved.w[1], saved.w[3]);
        }
    }
}
#endif
#endif

#if defined(VERSION_EU_X)
INCLUDE_DATA("ovl_80400000", func_8040CB3C_eu_x_padding_FCB3C);
#endif
