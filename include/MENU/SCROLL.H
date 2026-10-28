#ifndef MENU_2_SCROLL_H
#define MENU_2_SCROLL_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"




struct OwnerRecAt38;
struct MenuListWidget;
struct MenuListWidget {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct OwnerRecAt38 *owner;
    struct Key entries[10];
    s32 index;
    s32 count;
};


extern s32 SmpButton_DispatchListEvent(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct ObjRecAt18V1;
struct Scroll;
struct Scroll {
    char pad[0x44];
    struct ObjRecAt18V1 *bar;
    s32 length;
    s32 count;
    s32 item;
};
typedef struct Scroll Scroll;

struct MenuSliderWidget;
struct MenuSliderWidget {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[2];
    s16 field_18;
    s16 field_1A;
    s32 words_1C[4];
    s32 fields_2C[5];
    s32 field_40;
    struct MenuSliderWidget *field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
};

struct MenuListWidget;
typedef struct MenuListWidget MenuListWidget;


struct Scroll;

struct MenuSliderWidget;
typedef struct MenuSliderWidget MenuSliderWidget;
#endif
