#include "span_1000/code_80245980.h"
#include "shared/func_804235A8_eu_layout.h"
extern void *D_800E2830;
extern void func_802A025C_de(void *arg0, int arg1);




void func_80245A78_de(int arg0) {
    void *record = D_800E2830;
    int idx = ((Shared_MenuContext *)record)->messageCount;
    func_802A025C_de((char *)record + ((idx * 0x28) + 0x118), arg0);
    record = D_800E2830;
    ((Shared_MenuContext *)record)->messageCount = ((Shared_MenuContext *)record)->messageCount + 1;
}
