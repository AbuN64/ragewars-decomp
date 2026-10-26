#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CALLBACK.H"

struct Record;
extern struct Record *Cache_AllocateMemory(s32 arg0);


void StreamBufferAppend(StreamBuffer *streamBuffer, const void *sourceData, s32 byteCount) {
    if ((streamBuffer->data) == 0) {
        void *allocation = Cache_AllocateMemory(byteCount);
        streamBuffer->data = allocation;
        streamBuffer->writePosition = 0;
        streamBuffer->capacity = byteCount;
    }
    {
        s32 t_c = streamBuffer->writePosition;
        u8 *t_0 = streamBuffer->data;
        XPlus_CopyBytes(t_0 + t_c, sourceData, byteCount);
    }
    streamBuffer->writePosition = (streamBuffer->writePosition) + byteCount;
}
