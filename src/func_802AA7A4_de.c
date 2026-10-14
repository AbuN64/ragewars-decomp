#include "span_1000/code_802A6AC0.h"
#include "span_1000/code_8026AC38.h"
#include "span_1000/code_80296014.h"
#include "span_1000/code_802A208C.h"
#include "span_1000/code_802A8A94.h"
#include "types.h"

extern int func_802A23B4_de(void);







extern void func_802A9234_de(s32);
extern void func_802A7660_de(void *arg0, int arg1);

extern u8 D_801462DE;




void func_802AA7A4_de(void *arg0) {
    char pad[256];
    (void)pad;

    if (func_802A23B4_de() == 1) {
        func_802A2090_de();
        func_8026D8F8_de();
        func_80295FF4_de();
    }
    func_802A84F8_de();
    func_802A8710_de();
    func_802AAB68_de(D_800C61F0_de, D_800C61F0_de);
    func_802AAB3C_de(0xFF, 0xFF, 0xFF, 0xC8, 0xC8, 0xC8);
    func_802A9234_de(D_801462DE);
    if (((Hud *)arg0)->bars[0].enabled != 0) {
        func_802A7660_de(arg0, 1);
    }
    if (((Hud *)arg0)->bars[1].enabled != 0) {
        func_802A7660_de(arg0, 2);
    }
}
