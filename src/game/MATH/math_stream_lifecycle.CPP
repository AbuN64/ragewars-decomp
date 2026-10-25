#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/math_stream_lifecycle.H"
#include "SCENE/802508E0_13.H"
struct Record;
extern struct Record *func_8025305C_de(s32 size);


s32 func_80253908_de(s32);

s32 func_80255228_de(s32 *);


void StreamBufferRead(StreamBuffer *arg0, void *arg1, s32 arg2)
{
  const u8 *new_var;
  const u8 *new_var2;
  new_var2 = arg0->data;
  new_var2 = new_var2 + arg0->readPosition;
  new_var = new_var2;
  Resmgr_CopyBytes(arg1, new_var, arg2);
  arg0->readPosition = arg0->readPosition + arg2;
}

void StreamBufferAllocate(StreamBuffer *streamBuffer, s32 arg1) {
    if (streamBuffer->data == 0) {
        void *allocation = func_8025305C_de(arg1);
        streamBuffer->data = allocation;
        streamBuffer->writePosition = 0;
        streamBuffer->capacity = arg1;
    }
}

void StreamBufferFree(StreamBuffer *streamBuffer) {
    void *temp_a0;
    temp_a0 = streamBuffer->data;
    if (temp_a0 != 0) {
        func_802547E4_de(temp_a0);
        streamBuffer->data = 0;
    }
    streamBuffer->writePosition = 0;
    streamBuffer->readPosition = 0;
    streamBuffer->capacity = 0;
}

void func_80299CC4_de(void) {
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
}
