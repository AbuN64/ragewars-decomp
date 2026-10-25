#ifndef COMMON_REQUESTRECAT10_H
#define COMMON_REQUESTRECAT10_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
extern s32 func_8041EAC4_de();

struct Player_func_8041EAC4_de;
typedef struct Player_func_8041EAC4_de Player_func_8041EAC4_de;


extern s32 Frontend_FindKeyIndex(s32 key);

extern void Frontend_SeatJoinRequests(void);


extern s32 func_8041EBBC_de(void);

struct RequestRecAt10;
struct RequestRecAt10 {
    s32 id;
    s32 variant;
    s32 word8;
    s32 variantC;
    char name[28 - 0x10];
};
/* D_80153F80: the three join requests the request menus edit and Frontend_SeatJoinRequests seats. */
extern struct RequestRecAt10 D_80153F80[3];



extern s32 Frontend_CountUsedSlots();

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

struct CourseOptionsScreen {
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
