#ifndef COMMON_WIDGETRECAT34_H
#define COMMON_WIDGETRECAT34_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
extern void func_80411EEC_de();

struct WidgetRecAt34;
typedef struct WidgetRecAt34 WidgetRecAt34;

extern s16 func_80411D94_de(void);


extern void func_80412038_de(void);

extern void func_80411F28_de();


extern short func_80411C98_de(int index);

extern int func_80411AE8_de(void);

struct BufferPool;

struct BufferPool;

extern int func_80411D08_de(void);

extern void func_80411F48_de(void);



extern short func_80411CD0_de(int index);

struct Manager_func_80411D18_de;
typedef struct Manager_func_80411D18_de Manager_func_80411D18_de;

extern void Frontend_LoadLanguageStringsIfAny(s32);

extern short func_80411C28_de(int index);

extern int func_80411D10_de(void);

extern signed char func_80411BE8_de(int entry, int index);

extern short D_80153C2C;


extern short Frontend_GetFontLetterSpacing(int index);

struct Manager_func_80411D18_de;
struct Manager_func_80411D18_de {
    short count;
    char pad2[0x32];
    int mode;
};

extern signed char func_80411BA8_de(int entry, int index);

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
