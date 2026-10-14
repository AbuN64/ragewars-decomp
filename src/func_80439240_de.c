#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_804379C8.h"
#include "types.h"
/* Builds a two-slider menu: allocates eight bytes into D_800E58A4 through func_8025305C_de, creates the
   sliders VALUE_1D5/VALUE_1D5+1 and VALUE_1D5+2/VALUE_1D5+3 through func_8041A580_de, stores them in the block and sets them
   to the option bytes D_801462E0[0] and [1] through func_8041A6EC_de, then calls func_8041B110_de with
   VV_01D3. Returns zero. */
extern void **D_800E58A4;
extern u8 D_801462E0[];
extern void **func_8025305C_de(s32);
extern void *func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(void *, s32);
s32 func_80439240_de(void) {
    u8 *options;
    void *slider;
    D_800E58A4 = func_8025305C_de(8);
#if defined(VERSION_DE)
    slider = func_8041A580_de(0x1D1, 0x1D1 + 1, 0xFF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    slider = func_8041A580_de(0x1D5, 0x1D5 + 1, 0xFF);
#elif defined(VERSION_EU_X)
    slider = func_8041A580_de(0x1D8, 0x1D8 + 1, 0xFF);
#endif
    options = D_801462E0;
    D_800E58A4[0] = slider;
    func_8041A6EC_de(slider, options[0]);
#if defined(VERSION_DE)
    slider = func_8041A580_de(0x1D1 + 2, 0x1D1 + 3, 0xFF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    slider = func_8041A580_de(0x1D5 + 2, 0x1D5 + 3, 0xFF);
#elif defined(VERSION_EU_X)
    slider = func_8041A580_de(0x1D8 + 2, 0x1D8 + 3, 0xFF);
#endif
    D_800E58A4[1] = slider;
    func_8041A6EC_de(slider, options[1]);
#if defined(VERSION_DE)
    func_8041B110_de(0x1CF);
#elif defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
    func_8041B110_de(0x1D3);
#elif defined(VERSION_EU_X)
    func_8041B110_de(0x1DC);
#endif
    return 0;
}
