#ifndef RESMGR_N64ENG_DRAWNUMERICWIDGETCHILDREN_H
#define RESMGR_N64ENG_DRAWNUMERICWIDGETCHILDREN_H
#include "COMMON/RECORD.H"
#include "COMMON/STATEPAIR.H"

extern s32 N64Eng_DispatchNumericWidgetEvent(struct Tree *widget, s32 event, s32 eventData, s32 eventValue, s32 eventContext);

extern void N64Eng_DecrementNumericWidget(void *widget);
#endif
