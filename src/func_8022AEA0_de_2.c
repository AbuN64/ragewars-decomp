#include "span_1000/code_8022AE90.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_8fd754e1e915.h"
#include "shared/gameplay_transition.h"
#include "types.h"

extern unsigned int func_802227F4_de(void *arg0, void *arg1, s32 arg2);

extern void func_80272898_de(void *, void *, void *);

extern void func_802732D0_de(char *, f32 *);

extern char D_8011D8D0;

extern void func_802827C8_de(void *arg0, s32 arg1);

void func_8022B064_de(void *arg0, Vec3 *arg1)
{
  Shared_ActorView *player = arg0;
  void *new_var;
  player->resetPosition = *arg1;
  new_var = arg0;
  func_802227F4_de(new_var, new_var, 0x11);
}

void func_8022B09C_de(void *arg0, Vec3 *arg1) {
    extern void func_80226DD0_de(char *, MatrixF *);
    Vec3 input;
    MatrixF matrix;
    Vec3 *input_ptr;
    MatrixF *matrix_ptr;

    func_8022B08C_S1 *object = arg0;
    func_8022B08C_S2 *owner;

    input = *arg1;
    input_ptr = &input;
    matrix_ptr = object->unk5DC;

    if (matrix_ptr != 0) {
        owner = (void *)matrix_ptr;
        matrix_ptr = &owner->unk160;
    } else {
        func_80226DD0_de(arg0, &matrix);
        matrix_ptr = &matrix;
    }
    func_80272898_de(matrix_ptr, input_ptr, arg1);
}

void func_8022B11C_de(void *arg0, s32 arg1) {
    u16 temp_v0;
    u16 var_v1;
    temp_v0 = (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) + arg1;
    var_v1 = temp_v0;
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = temp_v0;
    if ((u32) (var_v1 & 0xFFFF) >= 0x65U) {
        var_v1 = 0x64;
    }
    (((struct ObjectState16DA *) ((s8 *) arg0))->unk_16D8) = var_v1;
}

void func_8022B144_de(void *arg0, f32 *arg1) {
    extern void func_80226DD0_de(void *arg0, s8 *arg1);
    s8 sp10[0x40];
    func_80226DD0_de(arg0, sp10);
    func_802732D0_de(sp10, arg1);
}

/** Report whether the word at offset 0x5E4 is zero. */
int func_8022B178_de(struct SharedPlayer *arg0) {
    return arg0->views5E4.view5E4_0.unk5E4 == 0;
}

/** Return the word at offset 0x1210. */
int func_8022B184_de(struct SharedPlayer *object) {
    return object->views5E8.view1210_152.unk1210;
}

void func_8022B190_de(s32 arg0) {
    func_802827C8_de(&D_8011D8D0, arg0);
}
