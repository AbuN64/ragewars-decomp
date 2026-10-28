#ifndef FRONTEND_PREVIEW_MODEL_IMAGE_H
#define FRONTEND_PREVIEW_MODEL_IMAGE_H
#include "TYPES.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/UNUSED.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#else
#endif
static inline s32 previewModelImage(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
return (s32)D_800E1E54[g_languageIndex];
#else
return D_800D3500;
#endif
}
#endif
