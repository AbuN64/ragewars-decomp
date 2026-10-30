#ifndef DATA_OVERLAY_LAYOUTS_H
#define DATA_OVERLAY_LAYOUTS_H
#include "TYPES.H"
typedef struct OverlayScissorRect { s32 left, top, right, bottom; } OverlayScissorRect;
typedef struct OverlayTrialWidgetGroup { s32 firstResource, secondResource, optionalResource; } OverlayTrialWidgetGroup;
typedef struct OverlayDisplayCommand { u32 command, argument; } OverlayDisplayCommand;
#endif
