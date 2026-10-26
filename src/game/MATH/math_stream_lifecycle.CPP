#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/LONE/D_80106248.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CALLBACK.H"
#include "MATH/math_stream_lifecycle.H"
#include "SCENE/802508E0_13.H"
struct Record;
extern struct Record *Cache_AllocateMemory(s32 size);


s32 func_80253908_de(s32);

s32 func_80255228_de(s32 *);


void StreamBufferRead(StreamBuffer *readStream, void *destination, s32 byteCount)
{
  const u8 *new_var;
  const u8 *new_var2;
  new_var2 = readStream->data;
  new_var2 = new_var2 + readStream->readPosition;
  new_var = new_var2;
  XPlus_CopyBytes(destination, new_var, byteCount);
  readStream->readPosition = readStream->readPosition + byteCount;
}

void StreamBufferAllocate(StreamBuffer *streamBuffer, s32 capacityBytes) {
    if (streamBuffer->data == 0) {
        void *allocation = Cache_AllocateMemory(capacityBytes);
        streamBuffer->data = allocation;
        streamBuffer->writePosition = 0;
        streamBuffer->capacity = capacityBytes;
    }
}

void StreamBufferFree(StreamBuffer *streamBuffer) {
    void *bufferData;
    bufferData = streamBuffer->data;
    if (bufferData != 0) {
        Cache_FreeMemory(bufferData);
        streamBuffer->data = 0;
    }
    streamBuffer->writePosition = 0;
    streamBuffer->readPosition = 0;
    streamBuffer->capacity = 0;
}

void Smos_DrainResourceWork(void) {
    func_80255228_de(&D_80106248);
    func_80253908_de(0);
}
