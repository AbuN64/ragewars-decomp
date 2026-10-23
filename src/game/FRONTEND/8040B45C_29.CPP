#include "include_asm.h"
#include "COMMON/WIDGETRECAT1A.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_29.H"

/* Lays out a slider from its value: scales value - min over max - min onto the track span, then
   for a vertical slider (flag 1) sets the fill's y and height and centres the thumb vertically on
   that edge, and for a horizontal slider sets the fill's width and moves the thumb from the fill's
   x by that edge less half its width. */





void func_8040C950_de(Slider *slider) {
    s32 pos;

    if (slider->flags & 1) {
        pos = (slider->bottom - slider->top) * (slider->value - slider->min) / (slider->max - slider->min);
        slider->fill->y = pos;
        slider->fill->height = slider->bottom - pos;
        if (slider->thumb != 0) {
            slider->thumb->y = pos - slider->thumb->height / 2;
        }
    } else {
        pos = (slider->right - slider->left) * (slider->value - slider->min) / (slider->max - slider->min);
        slider->fill->width = pos;
        if (slider->thumb != 0) {
            slider->thumb->x = slider->fill->x - (pos - slider->thumb->width / 2);
        }
    }
}

#if defined(VERSION_US)
char rodata_unresolved_8040CB24[12] =
    "MULTI_WEAPON";
#endif

#if defined(VERSION_DE)
unsigned int rodata_unresolved_8040CAA4[3] = {
    0x05DF0113, 0x2D04EFEF, 0xC10DD311,
};
#endif
