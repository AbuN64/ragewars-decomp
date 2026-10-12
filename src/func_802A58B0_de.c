#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A25C4.h"
#include "types.h"
#include "span_1000/code_8027A0F4.h"



extern void func_80270910_de(f32 *, PackedMatrixWords *);
extern void func_8027347C_de(void *arg0, f32 sx, f32 sy, f32 sz);
extern void func_80272828_de(f32 *arg0);
extern void func_802A25D0_de(void *arg0, void *arg1, f32 *arg2);










void func_802A58B0_de(func_802A67D0_S1 *arg0, Shared_Particle *arg1, PackedMatrixWords *arg2) {
    f32 local[16];
    f32 scale;
    f32 zero;
    func_802A68A0_S2 *node;

    node = arg0->unk7528;
    if (node != 0) {
        zero = 0.0f;
        do {
            if (node->unk1C == arg1 &&
                node->unk24 > zero &&
                node->unk24 > zero) {
                func_80270910_de(local, arg2);
                scale = D_800C5E98_de;
                if (arg1->desc->renderModel != 0) {
                    scale = D_800C5E9C_de;
                }
                func_8027347C_de(local, scale, scale, scale);
                func_80272828_de(local);
                func_802A25D0_de(arg0, node, local);
            }
            node = node->unk4;
        } while (node != 0);
    }
}
