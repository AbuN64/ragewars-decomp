#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/80299ECC_6.H"
#include "SCENE/802508E0_13.H"
struct Record;
extern struct Record *func_8025305C_de(s32 size);

extern s32 func_802A0724_de(s32, s32, s32);

s32 func_80253908_de(s32);

s32 func_80255228_de(s32 *);

extern s32 D_80106248;

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
        arg0->data = (s32)func_8025305C_de(arg1);
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

void func_80299CC4_de(void) {
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
}
