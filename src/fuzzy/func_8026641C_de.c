#include "TYPES.H"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/world.h"
#include "span_1000/code_80204E78.h"
#include "span_1000/code_8021CD70.h"
#include "span_C76B0/data.h"

void func_8022B09C_de(s32, f32 *);
void func_802800C0_de(s32 *, void *, void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32,
                      f32, f32, f32, s32, s32, s32);
void func_8028CE94_de(Shared_World *, s32, s32, s32, s32, s32, struct NodeCode8028469C **,
                      f32);
extern s32 D_8011D8D0;
extern float D_800C43D8_de;

void func_8026641C_de(s32 param_1, char *param_2, s32 param_3, f32 param_4, f32 param_5,
                      f32 param_6, f32 param_7, f32 param_8, f32 param_9, s32 param_10,
                      s32 param_11, u32 param_12) {
    char cVar1;
    s32 iVar2;
    f32 uVar3;
    s32 iVar4;
    f32 fVar5;
    f32 uVar6;
    f32 uVar7;
    f32 local_68;
    f32 local_64;
    f32 local_60;
    f32 local_58;
    f32 local_54;
    f32 local_50;
    f32 local_48;
    f32 local_44;
    f32 local_40;
    f32 local_38;
    f32 local_34;
    f32 local_30;
    f32 local_2c;
    s32 auStack_28[2];
    s32 doCall;
    Vec3 vec;

    iVar4 = param_11;
    iVar2 = param_10;
    if (*param_2 == '\x01') {
        *(u32 *)(param_2 + 0x170) = *(u32 *)(param_2 + 0x170) | 0x8000;
        if (((*(u32 *)(param_1 + 0x100) & 0x300000) != 0) &&
            (*(s32 *)(*(s32 *)(param_1 + 0x1d8) + 0x5dc) != 0)) {
            doCall = 0;
            uVar3 = 0.0f;
            uVar6 = 0.0f;
            uVar7 = 0.0f;
            if ((*(u32 *)(param_2 + 0x1ac) & 0x4000) == 0) {
                if ((*(u32 *)(param_2 + 0x1ac) & 0x2000) != 0) {
                    uVar3 = 50.0f;
                    uVar7 = D_800C43CC_de;
                    uVar6 = D_800C43C8_de;
                    doCall = 1;
                }
            } else {
                uVar3 = 100.0f;
                uVar7 = D_800C43C4_de;
                uVar6 = D_800C43C0_de;
                doCall = 1;
            }
            if (doCall) {
                vec.x = param_4;
                vec.y = param_5;
                vec.z = param_6;
                func_80239324_de(*(char **)(*(s32 *)(param_1 + 0x1d8) + 0x5dc), uVar7, uVar3, uVar7,
                                 uVar6, 1, vec);
            }
        }
        if (param_3 != 0) {
            if (((iVar4 != 0) && ((*(u32 *)(param_2 + 0x100) & 0x300000) != 0)) &&
    /* FAKEMATCH: Fuzzy draft keeps native byte reads from opaque actor storage. */
                (((u32)(u8)*(char *)(iVar4 + 0x66) - 4) < 2)) {
    /* FAKEMATCH: Fuzzy draft keeps native byte reads from opaque actor storage. */
                cVar1 = *(char *)(iVar4 + 0x66);
                if (*(s32 *)(*(s32 *)(param_2 + 0x1d8) + 0x5dc) != 0) {
                    iVar4 = *(s32 *)(param_2 + 0x1d8);
                    local_68 = -param_7;
                    local_64 = param_8;
                    local_60 = param_9;
                    func_8022B09C_de(iVar4, &local_68);
                    local_68 = local_68 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x128);
                    local_64 = local_64 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x12c);
                    local_60 = local_60 - *(f32 *)(*(s32 *)(iVar4 + 0x5dc) + 0x130);
                    func_80271818_de(&local_38, &local_68);
                    vec.x = param_4;
                    vec.y = param_5;
                    vec.z = param_6;
                    func_8024E79C_de((Actor_func_80214624_de *)param_2, vec, &local_58, auStack_28,
                                     0, 1);
                    local_50 = param_6;
                    local_48 = 0.0f;
                    local_54 = param_5 + D_800C43D0_de;
                    local_44 = 0.0f;
                    local_40 = 0.0f;
                    if (cVar1 == '\x05') {
                        uVar7 = 3;
                    } else {
                        uVar7 = 1;
                    }
                    local_58 = param_4;
                    func_802800C0_de(&D_8011D8D0, param_2, param_2, 0, 0, 0xe9, 0, 0, 0, local_38,
                                     local_34, local_30, local_2c, param_4, local_54, param_6, 0,
                                     -1, uVar7);
                    local_58 = 0.0f;
                    local_54 = 0.0f;
                    local_50 = 0.0f;
                    func_8028CE94_de(&D_8011FE88, *(s32 *)(iVar4 + 0x698) + 0x140, 3, 0, 0, 0,
                                     D_800C43D4_de, D_800C43D8_de);
                }
            }
            param_7 = 0.0f;
            param_8 = 0.0f;
            param_9 = 0.0f;
        }
        if (((*(u32 *)(param_2 + 0x100) & 0x300000) != 0) && ((param_12 & 0x200) != 0)) {
            func_80278D78_de((void *)param_1, 0x10, param_2);
        }
    }
    if (((**(s32 **)(param_1 + 0x18) == 1) || (**(s32 **)(param_1 + 0x18) == 0xb)) &&
        (func_80271F34_de((void *)(param_1 + 0x1c), (void *)(param_1 + 0x1c), &param_7),
         iVar2 != 0)) {
        vec.x = *(f32 *)(param_2 + 8);
        vec.y = *(f32 *)(param_2 + 0xc);
        vec.z = *(f32 *)(param_2 + 0x10);
        fVar5 = func_80216F44_de((Actor_func_80214624_de *)param_1, vec);
        *(f32 *)(param_1 + 0x6c) = *(f32 *)(param_1 + 0x6c) + fVar5 * D_800C43DC_de;
    }
}
