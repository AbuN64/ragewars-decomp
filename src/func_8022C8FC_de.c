#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_8022C894.h"
#include "types.h"
/* Runs a player's grounded movement state: updates it through func_8022404C_de, eases the value at
   0x72C to zero by a quarter, applies the movement tables D_800CE7FC and D_800CE7C0, then leaves for
   state 2 when not on the ground (animation 0x5E24 for the D_800CED30 state table, otherwise 1), or
   picks the animation from the stick at 0x6C0 and 0x6C4: 0xA64 at rest, 0xA67 or 0xA66 when the
   second axis dominates and 0xA65 or 0xA68 otherwise, by the sign of the dominant axis. */

extern void func_8022404C_de(void *, void *);
extern void func_80274870_de(f32 *, f32, f32);
extern void func_802231D4_de(void *, void *, void *);
extern void func_802233F0_de(void *, void *, void *);
extern s32 func_802227F4_de(void *, void *, s32);
extern char D_800CE7FC;
extern char D_800CE7C0;
extern s32 D_800CED30;




void func_8022C8FC_de(struct SharedPlayer *arg0, void *arg1) {
    f32 x;
    f32 y;
    f32 zero;

    func_8022404C_de(arg0, arg1);
    zero = 0.0f;
    func_80274870_de(&arg0->views5E8.view72C_75.unk72C, zero, 0.25f);
    func_802231D4_de(arg0, arg1, &D_800CE7FC);
    func_802233F0_de(arg0, arg1, &D_800CE7C0);
    if (!(arg0->views5E8.view6AC_45.unk6AC & 0x10)) {
        func_802227F4_de(arg0, arg1, 2);
        if (arg0->views13B4.view13B4_3.character == &D_800CED30) {
            arg0->views5E8.view86C_125.unk86C = 0x5E24;
        } else {
            arg0->views5E8.view86C_125.unk86C = 1;
        }
    } else {
        x = arg0->views5E8.view6C0_51.unk6C0;
        if (x != zero || arg0->views5E8.view6C4_54.unk6C4 != zero) {
            y = arg0->views5E8.view6C4_54.unk6C4;
            if (x < y) {
                if (zero < y) {
                    arg0->views5E8.view86C_125.unk86C = 0xA67;
                } else {
                    arg0->views5E8.view86C_125.unk86C = 0xA66;
                }
            } else if (zero < x) {
                arg0->views5E8.view86C_125.unk86C = 0xA65;
            } else {
                arg0->views5E8.view86C_125.unk86C = 0xA68;
            }
        } else {
            arg0->views5E8.view86C_125.unk86C = 0xA64;
        }
    }
}
