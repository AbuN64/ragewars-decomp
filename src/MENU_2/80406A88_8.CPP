#include "include_asm.h"
#include "SCENE/802508E0_13.H"

#if defined(VERSION_EU_X)
extern void func_80411DA4_de(int);
extern unsigned char D_80152789;
extern void *g_optionsPage;

int func_80423B70_eu_x(void *arg0) {
    func_802547E4_de(arg0);
    g_optionsPage = 0;
    func_80411DA4_de(D_80152789);
    return 0;
}
#endif
