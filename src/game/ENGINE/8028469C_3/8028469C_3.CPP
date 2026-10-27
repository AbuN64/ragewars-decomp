#include "include_asm.h"

#include "COMMON/PACKEDMESHMATERIAL.H"
#include "TYPES.H"
#include "RENDER/8028469C_3.H"

s32 PpDecom_UnpackResource(s32, s32);
/* A resource request's dispatch callback: unpacks the loaded request, its second argument. */
void func_80285100_eu(s32 argument, s32 request)
{
  PpDecom_UnpackResource(request, 0);
}
