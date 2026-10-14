#include "shared/controller_request.h"
extern s32 D_800C8144_de;
extern RingQueue D_800F2F40;
extern Queue_func_802BB2A0_de D_800F3110;
extern s32 func_802BB420_de(RingQueue *, s32, s32);
extern s32 func_802BB2A0_de(Queue_func_802BB2A0_de *, void **, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32, s32, u32, s32);
extern void func_80200D18_de(u32, const void *, u32);
extern s32 func_802016DC_de(u8 *);

s32 func_80201C80_de(u8 *name, u32 flags) {
    ControllerRequest request;
    ControllerResponse response;
    s32 saved;
    s32 length;
    request.status = func_802016DC_de(name);
    if (D_800C8144_de == 2) {
        request.header = (u32)name;
        request.reserved = 1;
        request.command = 0x80000303;
        request.argument0 = request.status;
        request.argument1 = flags;
        request.argument2 = 0;
        request.reply = &D_800F3110;
        func_802BB420_de(&D_800F2F40, (s32)&request, 1);
        func_802BB2A0_de(&D_800F3110, &response.message, 1);
        if (response.status & 0x8000) response.status |= 0xFFFF0000;
    } else {
        saved = func_80200500_de();
        length = func_802016DC_de(name);
        func_80200D18_de(0xB1FF0000, name, length);
        response.status = func_802017E8_de(0x303, length, flags, 0);
        if (response.status & 0x8000) response.status |= 0xFFFF0000;
        func_80200538_de(saved);
    }
    return response.status;
}
