#ifndef PREVIEW_STATISTICS_H
#define PREVIEW_STATISTICS_H
#include "types.h"
extern const char D_800E1F48[];
#if defined(VERSION_DE)
extern const char D_auto_800DDF14[];
static inline const char *previewNumberFormat(void) { return D_auto_800DDF14; }
enum { PREVIEW_ID_SHIFT=-4 };
#elif defined(VERSION_EU)
extern const char D_auto_800EE594[];
static inline const char *previewNumberFormat(void) { return D_auto_800EE594; }
enum { PREVIEW_ID_SHIFT=0 };
#elif defined(VERSION_EU_X)
extern const char D_auto_800E9754[];
static inline const char *previewNumberFormat(void) { return D_auto_800E9754; }
enum { PREVIEW_ID_SHIFT=5 };
#elif defined(VERSION_US)
extern const char D_auto_800DCBC4[];
static inline const char *previewNumberFormat(void) { return D_auto_800DCBC4; }
enum { PREVIEW_ID_SHIFT=0 };
#elif defined(VERSION_US_REV1)
extern const char D_auto_800E1F44[];
static inline const char *previewNumberFormat(void) { return D_auto_800E1F44; }
enum { PREVIEW_ID_SHIFT=0 };
#endif
#endif
