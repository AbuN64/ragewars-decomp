#include "types.h"
#include "common/unused.h"

void func_80253670_de(void *, void *);
void func_80253754_de(void *, void *);
void **func_802540F4_de(s32, void **, s32, void *, s32);
void func_8026BC60_de(void);
char * func_8028FDB4_de(int *, int);
int func_8028FE28_de(int *, int, int);
s32 func_8028FE3C_de(s32, s32, s32, s32 *);
s32 **func_8025193C_de(); /* extern */

extern s32 **D_8011064C;

extern func_8026C484_S2 D_801157D8[];
extern s32 D_800C466C_de;                          /* unable to generate initializer: unknown type */
extern s32 D_800C4680_de;                          /* unable to generate initializer: unknown type */
extern s32 D_800C4694_de;                          
void func_8026C484_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
        s32 *sp28;
        s32 sp2C;
        s32 **temp_v0;
        s32 **temp_v0_4;
        s32 temp_s0;
        s32 temp_s1;
        s32 temp_v0_2;
        s32 temp_v0_3;
        s32 temp_v1;
        s8 *temp_s1_2;
        func_8026C484_S2 *temp_v1_2;
        temp_v0 = func_8025193C_de(0, arg0, arg0, 0x18, 0, 0, 0, &D_800C466C_de, 1);
        if (temp_v0 != 0) {
                temp_s1 = func_8028FE28_de(*temp_v0, arg0, 1);
                func_80253754_de(0, temp_v0);
                temp_v0_2 = func_802540F4_de(0, (void **) &sp28, temp_s1, &D_800C4680_de, 1);
                if (temp_v0_2 != 0) {
                        temp_v0_3 = *sp28;
                        temp_s0 = func_8028FE3C_de((s32) sp28, temp_s1, arg3 % temp_v0_3, &sp2C);
                        func_80253754_de(0, (void *) temp_v0_2);
                        temp_v0_4 = func_8025193C_de(0, temp_s0, temp_s0, sp2C, 0, 0, &D_0026D7F4, &D_800C4694_de, arg5);
                        if (temp_v0_4 != 0) {
                                temp_s1_2 = func_8028FDB4_de(*temp_v0_4, 0);
                                if (D_8011064C != temp_v0_4 || D_8010C564 != arg4 || D_80110640 == 0x20) {
                                        func_8026BC60_de();
                                        if (D_80111310 != 0x100) {
                                                func_80253670_de(0, temp_v0_4);
                                                D_80111318[D_80111310] = temp_v0_4;
                                                D_80111310 += 1;
                                                goto block_11;
                                        }
                                } else {
                                        block_11:
                                        D_8011064C = temp_v0_4;

                                        D_8010C564 = arg4;
                                        temp_v1 = D_80110640;
                                        temp_v1_2 = &D_801157D8[temp_v1++];
                                        D_80110640 = temp_v1;
                                        temp_v1_2->unk0 = arg1;
                                        temp_v1_2->unkC = 0;
                                        temp_v1_2->unk4 = arg2;
                                        temp_v1_2->unk8 = temp_s1_2;
                                }
                                func_80253754_de(0, temp_v0_4);
                        }
                }
        }
}
