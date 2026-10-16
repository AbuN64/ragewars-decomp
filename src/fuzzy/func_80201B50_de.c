#include "TYPES.H"

struct IOQueue1B50;
typedef struct IORequest1B50 {
    u8 *buffer;
    s32 length;
    s32 count;
    u32 operation;
    s32 transferLength;
    s32 argument;
    u32 flags;
    struct IOQueue1B50 *replyQueue;
} IORequest1B50;
typedef union IOReply1B50 {
    void *message;
    u32 status;
} IOReply1B50;
extern s32 D_800C8144_de;
extern struct IOQueue1B50 D_800F2F40, D_800F3110;
extern s32 func_802016DC_de(u8 *);
extern s32 func_802BB420_de(struct IOQueue1B50 *, void *, s32);
extern s32 func_802BB2A0_de(struct IOQueue1B50 *, void **, s32);
extern s32 func_80200500_de(void);
extern void func_80200538_de(s32);
extern void func_80200D18_de(s32, u8 *, s32);
extern u32 func_802017E8_de(s32, s32, s32, s32);

u32 func_80201B50_de(u8 *buffer, s32 argument) {
    IORequest1B50 request;
    IOReply1B50 reply;
    s32 length;
    s32 saved;
    length = func_802016DC_de(buffer);
    if (D_800C8144_de == 2) {
        request.length = length;
        request.transferLength = length;
        request.buffer = buffer;
        request.count = 1;
        request.operation = 0x80000202;
        request.argument = argument;
        request.flags = 0;
        request.replyQueue = &D_800F3110;
        func_802BB420_de(&D_800F2F40, &request, 1);
        func_802BB2A0_de(&D_800F3110, &reply.message, 1);
        if (reply.status & 0x8000) {
            reply.status |= 0xFFFF0000;
        }
    } else {
        saved = func_80200500_de();
        length = func_802016DC_de(buffer);
        func_80200D18_de(0xB1FF0000, buffer, length);
        reply.status = func_802017E8_de(0x202, length, argument, 0);
        if (reply.status & 0x8000) {
            reply.status |= 0xFFFF0000;
        }
        func_80200538_de(saved);
    }
    return reply.status;
}
