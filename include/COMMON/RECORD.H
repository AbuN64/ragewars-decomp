#ifndef COMMON_RECORD_H
#define COMMON_RECORD_H
#include "TYPES.H"
#include "COMMON/FRUSTUM.H"
struct Tree;



extern int D_801470A8;






struct RecordN64EngCreateNumericWidget;
typedef struct RecordN64EngCreateNumericWidget RecordN64EngCreateNumericWidget;

extern int D_80147060[16];


extern int D_800D2C18;

struct RecordN64EngCreateNumericWidget;
struct RecordN64EngCreateNumericWidget {
    s32 words_00[3];
    s16 field_0C;
    s16 field_0E;
    s32 words_10[7];
    s32 fields_2C[5];
    s32 field_40;
    struct RecordN64EngCreateNumericWidget *field_44;
    s32 field_48;
    s32 field_4C;
    s32 field_50;
    s32 field_54;
    s32 field_58;
    s32 field_5C;
    s32 field_60[3];
};








extern const char D_800CAF20[];
#endif
