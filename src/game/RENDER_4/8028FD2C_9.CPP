#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESULTS.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_9.H"

int SetN64_GetRecordBlockSize(int *recordHeader) {
    return recordHeader[0] * recordHeader[1] + 8;
}

void SetN64_GetChunkStorage(void *arg0, void **arg1, s32 *arg2) {
    *arg1 = arg0;
    *arg2 = ((((struct Shape_typemap_13 *) ((s8 *) arg0))->field_0) * (((struct Shape_typemap_13 *) ((s8 *) arg0))->field_4)) + 8;
}
