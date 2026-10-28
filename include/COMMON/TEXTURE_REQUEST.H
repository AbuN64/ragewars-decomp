#ifndef COMMON_TEXTURE_REQUEST_H
#define COMMON_TEXTURE_REQUEST_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#if defined(VERSION_US_REV1)
extern s32 D_800D2AE0;
extern char D_auto_00295B90;
extern char s_textureText[];
#else
extern char D_00294C90;
extern char D_800C54F0_de[];
#endif
/* Request the texture resource for this bank and variation. */
static __inline__ void *rw_request_texture(s32 *resource, s32 variation, s32 wait)
{
#if defined(VERSION_US_REV1)
    if (D_800D2AE0 == 0) {
        return Cache_RequestResource(0, resource[0] + variation + D_800CD894_de * 128,
                              resource[0], resource[1], 0, variation,
                              &D_auto_00295B90, s_textureText, wait);
    }
    return Cache_RequestResource(0, resource[0] - 1, resource[0], resource[1],
                          0, -1, &D_auto_00295B90, s_textureText, wait);
#else
    return Cache_RequestResource(0, resource[0] + variation + D_800CD894_de * 128,
                          resource[0], resource[1], 0, variation,
                          &D_00294C90, D_800C54F0_de, wait);
#endif
}

/* Request and wait for this texture resource. */
static __inline__ void **rw_request_texture_sync(s32 *resource, s32 variation)
{
#if defined(VERSION_US_REV1)
    if (D_800D2AE0 == 0) {
        return Cache_RequestResource(0, resource[0] + variation + D_800CD894_de * 128,
                              resource[0], resource[1], 0, variation,
                              &D_auto_00295B90, s_textureText, 1);
    }
    return Cache_RequestResource(0, resource[0] - 1, resource[0], resource[1],
                          0, -1, &D_auto_00295B90, s_textureText, 1);
#else
    return Cache_RequestResource(0, resource[0] + variation + D_800CD894_de * 128,
                          resource[0], resource[1], 0, variation,
                          &D_00294C90, D_800C54F0_de, 1);
#endif
}
#endif
