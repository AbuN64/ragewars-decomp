#include "COMMON/CALLBACK.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "RESMGR/STREAM.H"
#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "COMMON/LONE/RESOURCE_REQUEST_QUEUE.H"
#include "SCENE/CACHE_FREEMEMORY.H"

/** Copy the same global float to two destinations. */
void Stream_SetFloatPairToNegativeOne(float *first, float *second) {
    float value = g_streamFloatPairInitialValue;
    *first = value;
    *second = value;
}

struct Record;
extern struct Record *Cache_AllocateMemory(s32 byteCount);


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

extern struct Record *Cache_AllocateMemory(s32 size);


void Cache_DrainAndCompactResources(s32);

s32 Cache_WaitForResourceLoads(s32 *);


void StreamBufferRead(StreamBuffer *readStream, void *destination, s32 byteCount)
{
  const u8 *sourceBytes;
  const u8 *readCursor;
  readCursor = readStream->data;
  readCursor = readCursor + readStream->readPosition;
  sourceBytes = readCursor;
  XPlus_CopyBytes(destination, sourceBytes, byteCount);
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

void Stream_DrainResourceWork(void) {
    Cache_WaitForResourceLoads(&g_resourceCacheWorker);
    Cache_DrainAndCompactResources(0);
}
