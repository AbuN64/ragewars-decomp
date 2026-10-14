#ifndef UNBAKE_SPAN_16E000_CODE_8041DF04_H
#define UNBAKE_SPAN_16E000_CODE_8041DF04_H
#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
extern s32 func_8041EAC4_de();

struct Player_func_8041EAC4_de;
typedef struct Player_func_8041EAC4_de Player_func_8041EAC4_de;

struct Screen_func_8041ECB4_de;
struct Screen_func_8041ECB4_de {
    char pad0[8];
    void *roots[3];
    s32 request;
    s32 timer;
};

extern s32 func_8041F140_de(s32 key);

extern void func_8041E5F8_de();

struct Menu_func_8041EE08_de;
typedef struct Menu_func_8041EE08_de Menu_func_8041EE08_de;

extern s32 func_8041EBBC_de(void);

struct RequestRecAt10;
struct RequestRecAt10 {
    s32 id;
    s32 variant;
    s32 word8;
    s32 variantC;
    char name[28 - 0x10];
};

extern s32 func_8041DEB4_de(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

struct Menu_func_8041EE08_de;
struct Menu_func_8041EE08_de {
    char pad[8];
    int items[3];
    int unk14;
    int unk18;
    int unk1C;
};

extern s32 func_8041EB50_de();

typedef struct RequestDrawScreen {
    char pad0[8];
    void *roots[3];
    s32 selected;
    s32 timer;
    s32 count;
} RequestDrawScreen;
typedef struct RequestDrawPair { s32 first, second; } RequestDrawPair;
extern s32 func_8041EC44_de(s32, s32);
extern RequestDrawPair D_800DF740[];

struct Screen_func_8041DFC0_us_rev1 {
    void *handle;        /* +0x00 the course-tree handle this screen was built for */
    s32 mode;            /* +0x04 what func_8041B610_de reports for that handle */
    void *rows[3];       /* +0x08 the three option rows, addressed as block + (row << 2) + 8 */
    s32 selection;       /* +0x14 the row a join request edits */
    s32 timer;           /* +0x18 */
    s32 step;            /* +0x1C */
};
extern s32 func_802999A0_de(s32);
extern void func_8041E408_de(s32);

#endif
