#include "RESMGR/resmgr_string_memory.H"
#include "COMMON/OBJRECAT3CV2.H"
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CALLBACK.H"

struct Record;
extern struct Record *func_8025305C_de(s32 arg0);


void StreamBufferAppend(StreamBuffer *arg0, const void *arg1, s32 arg2) {
    if ((arg0->data) == 0) {
        void *allocation = func_8025305C_de(arg2);
        arg0->data = allocation;
        arg0->writePosition = 0;
        arg0->capacity = arg2;
    }
    {
        s32 t_c = arg0->writePosition;
        u8 *t_0 = arg0->data;
        Resmgr_CopyBytes(t_0 + t_c, arg1, arg2);
    }
    arg0->writePosition = (arg0->writePosition) + arg2;
}
