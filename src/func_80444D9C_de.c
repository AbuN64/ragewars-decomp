#include "span_16E000/code_8043F69C.h"
#include "span_16E000/code_80444EC0.h"
#include "types.h"

extern u32 D_80142218;
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 *D_800E22E4_eu[];
extern u8 *D_800E22F4[];
extern u8 D_80152789;
#else
extern u8 *D_800D3624;
extern u8 *D_800D3628;
#endif
extern char D_800DE758_de[];
extern s32 func_8025477C_de(void);
extern void func_8025476C_de(u32);
extern s32 func_80441FE8_de(Item_func_80441FE8_de *);
extern void func_802658E4_de(char *, char *, s32);

s32 func_80444D9C_de(Item_func_80441FE8_de *item) {
    u32 code;
    u8 *text;
    s32 length;

    code = D_80142218 >> 4;
    func_8025476C_de((u32)func_8025477C_de() + 2U);
    if (code == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22E4_eu;
#else
        item->text = &D_800D3624;
#endif
    } else {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        item->text = D_800E22F4;
        text = item->text[D_80152789];
#else
        item->text = &D_800D3628;
        text = *item->text;
#endif
        length = func_80441FE8_de(item);
        func_802658E4_de((char *)text + (length - 4), D_800DE758_de, code);
    }
    return 0;
}
