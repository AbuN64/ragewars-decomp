#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/EXTERNS_4.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/RECORD.H"
#include "COMMON/TEXTURE.H"
#include "FRONTEND/8040B45C_35.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"

extern Record_func_802A1990_de *Cache_AllocateMemory(s32);


extern void func_802A1B24_de(void *arg0, s32 arg1);


extern void Frontend_ReplaceNodeRefs(s32 arg0, Record_func_802A1990_de *arg1, Record_func_802A1990_de *arg2);

Record_func_802A1990_de *func_802A1990_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    Record_func_802A1990_de *source;
    s32 context;
    Record_func_802A1990_de *result;
    Record_func_802A1990_de *child;

    source = Frontend_FindWidgetByResourceId(Frontend_GetScreenData(GetMenuScreenOwner()), arg0 & 0xFFFF);
    context = Frontend_GetScreenData(GetMenuScreenOwner());
    result = Cache_AllocateMemory(0x6C);
    XPlus_FillBytes(result, 0, 0x6C);
    *(Header44 *)result = *(Header44 *)source;
    result->field_0E = 0xB65;
    *(InstanceHdr *)&result->fields_2C = *(InstanceHdr *)&source->fields_2C;
    child = Frontend_FindWidgetByResourceId((void*)context, arg1 & 0xFFFF);
    result->field_44 = child;
    child->fields_2C[3] = (s32)&result->field_60;
    result->field_4C = arg3;
    result->field_50 = arg2;
    result->field_58 = 0;
    result->field_48 = 0;
    result->field_54 = arg4;
    func_802A1B24_de(result, arg2);
    result->field_5C = 2;
    Frontend_WrapNodeInParent(source, result);
    source->field_0C = -1;
    Frontend_ReplaceNodeRefs(context, source, result);
    return result;
}

/** Return the word at offset 0x58 in the supplied object. */
int func_802A1B18_de(void *object) {
    Record_func_802A1990_de *record = object;
    return record->field_58;
}
