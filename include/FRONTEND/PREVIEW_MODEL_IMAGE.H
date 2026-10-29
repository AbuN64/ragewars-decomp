#ifndef FRONTEND_PREVIEW_MODEL_IMAGE_H
#define FRONTEND_PREVIEW_MODEL_IMAGE_H
#include "TYPES.H"
#include "COMMON/LONE/G_LANGUAGEINDEX.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#else
#endif
static inline s32 previewModelImage(void) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
return (s32)g_matchResult5052TextEu[g_languageIndex];
#else
return g_matchResult5052TextDe;
#endif
}
#endif
