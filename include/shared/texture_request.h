#ifndef RW_TEXTURE_REQUEST_H
#define RW_TEXTURE_REQUEST_H
#include "types.h"
extern u32 D_800CD894_de;
extern void *func_8025193C_de(s32, u32, u32, u32, u32, s32, void *, const char *, u32);
#if defined(VERSION_US_REV1)
extern s32 D_800D2AE0;
extern char D_auto_00295B90;
extern char D_auto_800CA680[];
#else
extern char D_00294C90;
extern char D_800C54F0_de[];
#endif
/* Request the texture resource for this bank and variation. */
static __inline__ void **rw_request_texture(s32 *resource, s32 variation, s32 wait)
{
#if defined(VERSION_US_REV1)
    if (D_800D2AE0 != 0) {
        return func_8025193C_de(0, resource[0] - 1, resource[0], resource[1],
                              0, -1, &D_auto_00295B90, D_auto_800CA680, wait);
    }
    return func_8025193C_de(0, resource[0] + variation + D_800CD894_de * 128,
                          resource[0], resource[1], 0, variation,
                          &D_auto_00295B90, D_auto_800CA680, wait);
#else
    return func_8025193C_de(0, resource[0] + variation + D_800CD894_de * 128,
                          resource[0], resource[1], 0, variation,
                          &D_00294C90, D_800C54F0_de, wait);
#endif
}

#endif
