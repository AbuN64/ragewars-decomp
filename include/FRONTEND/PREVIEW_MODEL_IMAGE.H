#ifndef FRONTEND_PREVIEW_MODEL_IMAGE_H
#define FRONTEND_PREVIEW_MODEL_IMAGE_H
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1E54[];
extern u8 D_80152789;
#else
#endif
static inline s32 previewModelImage(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
return D_800E1E54[D_80152789];
#else
return D_800D3500;
#endif
}
#endif
