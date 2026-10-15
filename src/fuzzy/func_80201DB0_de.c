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
    OSMesgQueue *reply;
} ControllerRequest;

typedef union ControllerResponse {
    void *message;
    u32 status;
} ControllerResponse;

extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
extern s32 func_802BB2A0_de(OSMesgQueue *, void **, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32, s32, u32, s32);

u32 func_80201DB0_de(s32 arg0) {
    ControllerRequest request;
    ControllerResponse response;
    s32 saved;
    if (D_800C8144_de == 2) {
        request.argument0 = arg0;
        request.status = 0;
        request.command = 0x80000404;
        request.argument1 = 0;
        request.argument2 = 0;
        request.reply = &D_800F3110;
        func_802BB420_de(&D_800F2F40, (s32)&request, 1);
        func_802BB2A0_de(&D_800F3110, &response.message, 1);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
    } else {
        saved = func_80200500_de();
        response.status = func_802017E8_de(0x404, arg0, 0, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        func_80200538_de(saved);
    }
    return response.status;
}
