#include "types.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802BB15C.h"

typedef struct ControllerRequest {
    u32 header;
    u32 status;
    u32 reserved;
    u32 command;
    s32 argument0;
    u32 argument1;
    s32 argument2;
    Queue_func_802BB2A0_de *reply;
} ControllerRequest;

typedef union ControllerResponse {
    void *message;
    s32 status;
} ControllerResponse;

extern s32 D_800C8144_de;
extern RingQueue D_800F2F40;
extern Queue_func_802BB2A0_de D_800F3110;
extern s32 func_802BB420_de(RingQueue *, s32, s32);
extern s32 func_802BB2A0_de(Queue_func_802BB2A0_de *, void **, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32, s32, u32, s32);

s32 func_80202198_de(s32 arg0, u32 arg1, s32 arg2) {
    ControllerRequest request;
    ControllerResponse response;
    s32 saved;
    if (D_800C8144_de == 2) {
        request.argument0 = arg0;
        request.status = 0;
        request.command = 0x80000707;
        request.argument1 = arg1;
        request.argument2 = arg2;
        request.reply = &D_800F3110;
        func_802BB420_de(&D_800F2F40, (s32)&request, 1);
        func_802BB2A0_de(&D_800F3110, &response.message, 1);
    } else {
        saved = func_80200500_de();
        response.status = func_802017E8_de(0x707, arg0, arg1, arg2);
        func_80200538_de(saved);
    }
    return response.status;
}
