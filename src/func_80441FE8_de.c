#include "span_16E000/code_8043F69C.h"
#include "types.h"
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif
#include "types.h"
/* Returns the length of the first line of a text item's string, taken from func_8043F290 for type 5 items and from the string pointer at 0x14 otherwise, counting until a newline, the end of the string or a null pointer. */



extern u8 *func_8043F290(Item_func_80441FE8_de *item);

int func_80441FE8_de(Item_func_80441FE8_de *item) {
    u8 *p;
    int len;

    len = 0;
    if (item->type == 5) {
        p = func_8043F290(item);
    } else {
        
#if defined(VERSION_EU) || defined(VERSION_EU_X)
p = item->text[D_80152789];
#else
p = *item->text;
#endif

    }
    while (p != 0 && *p != 0 && *p != '\n') {
        p++;
        len++;
    }
    return len;
}
