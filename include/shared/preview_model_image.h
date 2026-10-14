#ifndef RW_PREVIEW_MODEL_IMAGE_H
#define RW_PREVIEW_MODEL_IMAGE_H
#include "types.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern s32 D_800E1E54[];
extern u8 D_80152789;
#else
extern s32 D_800D3500;
#endif
static inline s32 previewModelImage(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
return D_800E1E54[D_80152789];
#else
return D_800D3500;
#endif
}

#endif
