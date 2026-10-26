#ifndef COMMON_WIDGETRECAT34_H
#define COMMON_WIDGETRECAT34_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
extern void Frontend_InitializeResourceState();

struct WidgetRecAt34;
typedef struct WidgetRecAt34 WidgetRecAt34;

extern s16 Frontend_GetResourceLanguageCount(void);


extern void Frontend_ReleaseUnretainedTextureEntries(void);

extern void Frontend_ClearResourceInitializationFlag();


extern short Frontend_GetFontMetricAtA(int index);

extern int Frontend_ReturnOne(void);

struct BufferPool;

struct BufferPool;

extern int Frontend_ReturnConstantOne(void);

extern void Frontend_AcquireAllResourceTextures(void);



extern short Frontend_GetFontMetricAtC(int index);

struct ManagerFrontendReleaseAllChunkImages;
typedef struct ManagerFrontendReleaseAllChunkImages ManagerFrontendReleaseAllChunkImages;

extern void Frontend_LoadLanguageStringsIfAny(s32);

extern short Frontend_GetFontBitmapCount(int index);

extern int Frontend_ReturnUnitValue(void);

extern signed char Frontend_GetFontCharacterPhysicalWidth(int entry, int index);

extern short D_80153C2C;


extern short Frontend_GetFontLetterSpacing(int index);

struct ManagerFrontendReleaseAllChunkImages;
struct ManagerFrontendReleaseAllChunkImages {
    short count;
    char pad2[0x32];
    int mode;
};

extern signed char Frontend_GetFontCharacterHeight(int entry, int index);

struct WidgetRecAt34;
struct WidgetRecAt34 {
    char pad0[4];
    struct WidgetRecAt34 *next;
    struct WidgetRecAt34 *child;
    char padC[2];
    u16 type;
    char pad10[0x1C];
    struct WidgetRecAt34 *normal;
    struct WidgetRecAt34 *highlighted;
    struct WidgetRecAt34 *pressed;
};

#endif
