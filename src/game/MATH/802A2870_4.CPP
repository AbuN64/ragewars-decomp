#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/RECORD.H"
#include "COMMON/WIDGETRECAT1A.H"

extern s32 XStdio_FormatBuffer(void *, const char *, ...);

/* Format the stream count into its existing inline state buffer. */
void N64Eng_SetNumericWidgetValue(RecordN64EngCreateNumericWidget *widget, s32 arg1) {
    widget->field_58 = arg1;
    XStdio_FormatBuffer(widget->field_60, D_800CAF20, arg1);
}
