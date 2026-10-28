#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/GFX_INITIALIZEFRONTENDSERVICES.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/TEXTURE.H"
#include "FRONTEND/FRONTEND_OPENRESOURCEARCHIVE.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/NODE_FINDWIDGETBYRESOURCEID.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "include_asm.h"

extern RecordN64EngCreateNumericWidget *Cache_AllocateMemory(s32);


void N64Eng_SetNumericWidgetValue(RecordN64EngCreateNumericWidget *widget, s32 arg1);


extern void Node_ReplaceNodeRefs(s32 arg0, RecordN64EngCreateNumericWidget *arg1, RecordN64EngCreateNumericWidget *arg2);

RecordN64EngCreateNumericWidget *N64Eng_CreateNumericWidget(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    RecordN64EngCreateNumericWidget *source;
    s32 context;
    RecordN64EngCreateNumericWidget *result;
    RecordN64EngCreateNumericWidget *child;

    source = Node_FindWidgetByResourceId(Node_GetScreenData(GetMenuScreenOwner()), arg0 & 0xFFFF);
    context = Node_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x6C);
    XPlus_FillBytes(result, 0, 0x6C);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB65;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = Node_FindWidgetByResourceId((void*)context, arg1 & 0xFFFF);
    result->field_44 = child;
    child->fields_2C[3] = (s32)&result->field_60;
    result->field_4C = arg3;
    result->field_50 = arg2;
    result->field_58 = 0;
    result->field_48 = 0;
    result->field_54 = arg4;
    N64Eng_SetNumericWidgetValue(result, arg2);
    result->field_5C = 2;
    Node_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Node_ReplaceNodeRefs(context, source, result);
    return result;
}

/** Return the word at offset 0x58 in the supplied object. */
int N64Eng_GetNumericWidgetValue(void *object) {
    RecordN64EngCreateNumericWidget *record = object;
    return record->field_58;
}

extern s32 XStdio_FormatBuffer(void *, const char *, ...);

/* Format the stream count into its existing inline state buffer. */
void N64Eng_SetNumericWidgetValue(RecordN64EngCreateNumericWidget *widget, s32 arg1) {
    widget->field_58 = arg1;
    XStdio_FormatBuffer(widget->field_60, D_800CAF20, arg1);
}

#if !(defined(VERSION_US_REV1))
#if defined(VERSION_DE)
const unsigned int D_802A1B24_CBB20[1] = {
    0x25640044,
};
#endif
#if defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US)
const unsigned char D_802A1B24_CBB20[3] = {
    0x25, 0x64, 0x00,
};
#endif
#endif

#if defined(VERSION_US)
unsigned char rodata_unresolved_800C5CC3[13] = {
    0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x73, 0x5F, 0x43, 0x43,
};
#endif

#if defined(VERSION_US)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU_X)
char rodata_unresolved_800C6073[13] =
    "WE - PURLIN\000\000";
#endif

#if defined(VERSION_EU_X)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_EU)
unsigned char rodata_unresolved_800C6033[13] = {
    0x08, 0x27, 0xBD, 0x00, 0x18, 0x44, 0x00, 0x00, 0x00, 0xBF, 0x80, 0x00, 0x00,
};
#endif

#if defined(VERSION_EU)
/* bytes live in the preceding array */
#endif

#if defined(VERSION_US_REV1)
/* ROM-grounded data: src/rw_formats_802A1B24_CBB20_us_rev1.c */
const unsigned char D_blob_66a5e2efda41fe7042e8[] = {
    0x25, 0x64, 0x00,
#if defined(VERSION_US_REV1)
    0x52,
#endif
};
#endif
