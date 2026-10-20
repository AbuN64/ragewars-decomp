#ifndef COMMON_INTEGERSTATE14_2_H
#define COMMON_INTEGERSTATE14_2_H
#include "TYPES.H"

/* Memory stream buffer, byte cursor, size, open state, and ready flag. */


struct IntegerState14_2;
typedef struct IntegerState14_2 IntegerState14_2;


struct IntegerState14_2 {
    u8 *data;
    s32 cursor;
    s32 size;
    s32 opened;
    s32 ready;
};
extern IntegerState14_2 D_800CD940_de;


extern int D_800CD918;



extern int D_800CD920_de;


extern int D_800CD91C;



extern int D_800CD930_de;




extern int D_800D2B80;
#endif
