#include "COMMON/EXTERNS_18.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "sdk/os.h"

/* 802C0390_9.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BB5AC_de_padding_BC1AC[4] = { 0x0C, 0x0A, 0xF3, 0xC8 };
#endif

/* seteventmesg.c */
extern struct IntPair D_80149B10[];

void osSetEventMesg(s32 arg0, s32 arg1, s32 arg2) {
    u32 mask;
    struct IntPair *e;

    mask = __osDisableInt();
    ;
    (&D_80149B10[arg0])->field_0 = arg1;
    (*(&D_80149B10[arg0])).field_4 = arg2;
    __osRestoreInt(mask);
}
