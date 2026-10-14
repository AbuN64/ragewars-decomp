#include "shared/controller_request.h"
extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern s32 func_802BB420_de(OSMesgQueue *, s32, s32);
extern s32 func_802BB2A0_de(OSMesgQueue *, void **, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern s32 func_802017E8_de(s32, s32, u32, s32);
extern void func_80200D18_de(u32, const void *, u32);
extern s32 func_802016DC_de(u8 *);

s32 func_80202018_de(s32 channel, u8 *source, u32 remaining) {
    ControllerRequest request;
    ControllerResponse response;
    s32 total = 0;
    s32 saved;
    u32 chunk;
    if (D_800C8144_de == 2) {
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) chunk = 0x8000;
            request.header = (u32)source;
            request.status = chunk;
            request.reserved = 1;
            request.command = 0x80000606;
            request.argument0 = channel;
            request.argument1 = chunk;
            request.argument2 = 0;
            request.reply = &D_800F3110;
            func_802BB420_de(&D_800F2F40, (s32)&request, 1);
            func_802BB2A0_de(&D_800F3110, &response.message, 1);
            if (response.status == 0) return total;
            source += response.status;
            total += response.status;
            remaining -= response.status;
        }
    } else {
        saved = func_80200500_de();
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) chunk = 0x8000;
            func_80200D18_de(0xB1FF0000, source, chunk);
            response.status = func_802017E8_de(0x606, channel, chunk, 0);
            if (response.status == 0) break;
            source += response.status;
            total += response.status;
            remaining -= response.status;
        }
        func_80200538_de(saved);
    }
    return total;
}
