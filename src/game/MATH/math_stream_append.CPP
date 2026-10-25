#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CALLBACK.H"

struct Record;
extern struct Record *Scene_AllocateMemory(s32 arg0);


void StreamBufferAppend(StreamBuffer *streamBuffer, const void *arg1, s32 arg2) {
    if ((streamBuffer->data) == 0) {
        void *allocation = Scene_AllocateMemory(arg2);
        streamBuffer->data = allocation;
        streamBuffer->writePosition = 0;
        streamBuffer->capacity = arg2;
    }
    {
        s32 t_c = streamBuffer->writePosition;
        u8 *t_0 = streamBuffer->data;
        Resmgr_CopyBytes(t_0 + t_c, arg1, arg2);
    }
    streamBuffer->writePosition = (streamBuffer->writePosition) + arg2;
}
