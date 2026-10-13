#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80299DB4.h"
#include "types.h"

extern s32 func_802A0724_de(s32, s32, s32);
void func_80299BEC_de(StreamBuffer *arg0, s32 arg1, s32 arg2)
{
  long new_var;
  int new_var2;
  new_var2 = arg0->data;
  new_var2 = new_var2 + arg0->readPosition;
  new_var = new_var2;
  func_802A0724_de(arg1, new_var, arg2);
  arg0->readPosition = arg0->readPosition + arg2;
}

void func_80299C38_de(StreamBuffer *arg0, s32 arg1) {
    if (arg0->data == 0) {
        arg0->data = func_8025305C_de(arg1);
        arg0->writePosition = 0;
        arg0->capacity = arg1;
    }
}

void func_80299C80_de(StreamBuffer *arg0) {
    s32 temp_a0;
    temp_a0 = arg0->data;
    if (temp_a0 != 0) {
        func_802547E4_de(temp_a0);
        arg0->data = 0;
    }
    arg0->writePosition = 0;
    arg0->readPosition = 0;
    arg0->capacity = 0;
}
