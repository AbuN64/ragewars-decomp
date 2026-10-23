#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/ALAUXBUS_S.H"
#include "TYPES.H"
#include "sdk/libgultra_inferred/802B975C_5.H"

extern s32 D_002B5400;

extern s32 D_002B5540;

extern s32 D_002B3E00;

extern s32 D_002B3EDC;

void alMainBusNew(void *arg0, s32 arg1, s32 arg2) {
    alFilterNew(arg0, (s32) &D_002B5400, (s32) &D_002B5540, 7);
    (((struct TextLayerRect *) ((s8 *) arg0))->x) = 0;
    (((struct TextLayerRect *) ((s8 *) arg0))->right) = arg2;
    (((struct TextLayerRect *) ((s8 *) arg0))->y) = arg1;
}

void alAuxBusNew(void *arg0, s32 arg1, s32 arg2) {
    alFilterNew(arg0, (s32) &D_002B3E00, (s32) &D_002B3EDC, 6);
    (((struct TextLayerRect *) ((s8 *) arg0))->x) = 0;
    (((struct TextLayerRect *) ((s8 *) arg0))->right) = arg2;
    (((struct TextLayerRect *) ((s8 *) arg0))->y) = arg1;
}
