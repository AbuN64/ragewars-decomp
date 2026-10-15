#include "span_16E000/code_8042BD40.h"
#include "types.h"




extern func_8042CE54_S1 *D_800E53C0;

extern ResourceBank D_800E12D2[];

extern void *func_8040EC30_de(void *arg0, u16 arg1);
extern void func_8040E8D8_de(void *arg0, s32 arg1);


/** Load four banks of ten resources, then activate the two resources used by the set. */
void func_8042CC74_de(void)
{
    s32 bank;
    s32 offset;
    void *resource;

    bank = 0;
    offset = 0;
    do {
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[0]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[2]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[4]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[6]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[8]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[10]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[12]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[14]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[16]);
        func_8040E8D8_de(resource, 0);
        resource = func_8040EC30_de(D_800E53C0->unkE0, D_800E12D2[bank].ids[18]);
        func_8040E8D8_de(resource, 0);
        offset += 0x28;
        bank++;
    } while (bank < 4);

#if defined(VERSION_DE)
    func_8042D418_de(0x264);
    func_8042D418_de(0x269);
#elif defined(VERSION_EU_X)
    func_8042D418_de(0x26D);
    func_8042D418_de(0x272);
#else
    func_8042D418_de(0x269);
    func_8042D418_de(0x26E);
#endif
}
