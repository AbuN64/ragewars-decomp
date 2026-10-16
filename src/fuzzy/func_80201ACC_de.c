#include "TYPES.H"

typedef struct ControllerRequest {
    u32 header;
    u32 status;
    u32 reserved;
    u32 command;
    u32 argument0;
    u32 argument1;
    u32 argument2;
    OSMesgQueue *reply;
} ControllerRequest;

extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern void func_802016FC_de(u32 mask);
extern s32 func_802BB420_de(OSMesgQueue *, void *, s32);
extern s32 func_802BB2A0_de(OSMesgQueue *, void **, s32);

void *func_80201ACC_de(void) {
    ControllerRequest request;
    void *response;

    D_800C8144_de = 2;
    func_802016FC_de(0xFF);
    request.status = 0;
    request.command = 0x80000101;
    request.argument0 = 0;
    request.argument1 = 0;
    request.argument2 = 0;
    request.reply = &D_800F3110;
    func_802BB420_de(&D_800F2F40, &request, 1);
    func_802BB2A0_de(&D_800F3110, &response, 1);
    return response;
}
