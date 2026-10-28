#include "include_asm.h"
#include "COMMON/STATEPAIR.H"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "FRONTEND/8040B45C_36.H"
#include "MENU/GFX/804143E0.H"
#include "RESMGR/802A2230_9.H"
#include "RESMGR/802A23A4_6.H"

void Tsmos_ShutdownFrontend(void) {
    extern struct Triple D_800D2C90;
    s32 *selected;
    Menu_DestroyScreenManager();
    Node_CloseResourceArchive();
    ESmem_FreeFrameHeaps();
    Gfx_ShutdownFrontendServices();
    selected = &D_800D2C90.z;
    *selected = 0;
    Tsmos_DeactivateControllerState();
    D_800D2C90.x = 0;
}

extern f32 D_800C5DB8_de, D_800C5DBC_de;

void Tsmos_ScaleWidgetTree(Widget *widget, Widget *parent) {
    if (widget != 0) {
        if (widget->next != 0) Tsmos_ScaleWidgetTree(widget->next, parent);
        if (widget->child != 0) Tsmos_ScaleWidgetTree(widget->child, widget);
        if (widget->kind == 8) {
            if (widget->links[0] != 0) Tsmos_ScaleWidgetTree(widget->links[0], widget);
            if (widget->links[2] != 0) Tsmos_ScaleWidgetTree(widget->links[2], widget);
            if (widget->links[1] != 0) Tsmos_ScaleWidgetTree(widget->links[1], widget);
        }
        if (widget->scaled == 0) {
            f32 factorX = D_800C5DB8_de;
            f32 factorY = D_800C5DBC_de;
            if (widget->kind == 4) {
                widget->scaleX = factorX;
                widget->scaleY = factorY;
            } else {
                f32 value;
                s32 x, y, width, height;
                value = (f32)widget->x * factorX;
                x = (s32)value;
                value = (f32)widget->y * factorY;
                y = (s32)value;
                value = (f32)widget->width * factorX;
                width = (s32)value;
                value = (f32)widget->height * factorY;
                height = (s32)value;
                widget->x = x;
                widget->y = y;
                widget->width = width;
                widget->height = height;
            }
            widget->scaled = 1;
        }
    }
}

#if defined(VERSION_US)
unsigned int rodata_unresolved_802A24FC[1] = {
    0x41445F52,
};
#endif
