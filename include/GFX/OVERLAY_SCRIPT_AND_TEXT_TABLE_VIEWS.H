#ifndef GFX_OVERLAY_SCRIPT_AND_TEXT_TABLE_VIEWS_H
#define GFX_OVERLAY_SCRIPT_AND_TEXT_TABLE_VIEWS_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
struct OverlayScriptTableView {
    unsigned char padding_0[4];
    s32 *script;
    s32 state;
};
struct OverlayScriptPrimaryRangeView {
    unsigned char padding_0[60];
    s32 target;
    s32 owner;
    s32 initialPercent;
};
struct OverlayScriptSecondaryRangeView {
    unsigned char padding_0[132];
    s32 target;
    s32 owner;
    s32 initialPercent;
};
struct COverlay {
    s32 active;
    s32 *script;
    s32 state;
    s32 wait;
    f32 x;
    f32 y;
    f32 targetX;
    f32 targetY;
    f32 velX;
    f32 velY;
    f32 accelX;
    f32 accelY;
    f32 rate;
    u8 pad34[4];
    s32 handle; /* 0x38: resource handle initialized by the mover constructor */
};
struct OnScreenImageTableView {
    s16 count;
    u8 pad2[6];
    ImageTableEntry entries[1];
};
#endif
