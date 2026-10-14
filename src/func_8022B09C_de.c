#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8022AE90.h"
#include "types.h"





extern void func_80226DD0_de(char *, MatrixF *);
extern void func_80272898_de(void *, void *, void *);






void func_8022B09C_de(void *arg0, Vec3 *arg1) {
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
