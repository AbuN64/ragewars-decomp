#include "span_16E000/code_80429C10.h"
#include "types.h"
/* Looks up entry arg1 of the table chosen by arg0 and returns field 0xC of the first of the forty records at D_800E4F64 whose first word equals it, or zero. */




extern RecordRecAtCV2 D_800E4F64[];
extern s32 D_800E51E4[];
extern s32 D_800E51F8[];
extern s32 D_800E5214[];
extern s32 D_800E5240[];

s32 func_8042B1B8_de(s32 arg0, s32 arg1) {
    s32 result = 0;
    s32 *table;
    s32 key;
    s32 found;
    s32 i;

    if (arg1 == 0) {
        arg1 = 1;
    }
    switch (arg0) {
    case 0:
        table = D_800E51E4;
        break;
    case 1:
        table = D_800E51F8;
        break;
    case 3:
        table = D_800E5214;
        break;
    case 2:
        table = D_800E5240;
        break;
    default:
        return 0;
    }
    key = table[arg1];
    found = 0;
    i = 0;
    do {
        if (key == D_800E4F64[i].key) {
            found = 1;
            result = D_800E4F64[i].value;
        }
        i++;
    } while ((i < 0x28) && (found == 0));
    return result;
}
