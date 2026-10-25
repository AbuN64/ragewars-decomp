#include "IO/80200568.H"
#include "include_asm.h"
#include "COMMON/EXTERNS_15.H"
#include "TYPES.H"
#include "sdk/os.h"

/** Return strlen(arg0) + 1 (byte count including the terminating NUL). */
s32 func_802016DC_de(u8 *arg0) {
    u8 *var_v1;
    u8 temp;

    var_v1 = arg0 + 1;
    if (*arg0 != 0) {
        do {
            temp = *var_v1;
            var_v1 += 1;
        } while (temp != 0);
    }
    return var_v1 - arg0;
}

/* Shared declarations of the drafts below (one place, so every draft compiles together under -DNON_MATCHING). */
#include "IO/CONTROLLER_REQUEST.H"
#include "COMMON/OSTHREAD_S.H"
extern void D_002018A0(void *); /* host request thread entry, as the ROM stores its address */
extern volatile s32 D_800C8140_de; /* host link ready: the request thread clears it around each cart transfer */
extern s32 D_800C8144_de;
extern void *D_800F1C84;
extern OSMesgQueue D_800F1C90;
extern void *D_800F2CB0;
extern u8 D_800F2CE0[];
extern void *D_800F2CB4;
extern OSMesgQueue D_800F2CC0;
extern OSMesgQueue D_800F2F40;
extern void *D_800F2F58;
extern OSThread_s D_800F2F60; /* host request thread */
extern OSMesgQueue D_800F3110;
void osCreateThread(OSThread_s *thread, s32 id, void (*entry)(void *), void *arg, void *stackTop, s32 priority); /* osCreateThread */
void osSetEventMesg(s32 event, OSMesgQueue *queue, void *message); /* osSetEventMesg */
void osStartThread(OSThread_s *thread); /* osStartThread */
extern s32 func_80200500_de(void);
extern s32 func_802017E8_de(s32, s32, s32, s32);
extern void func_80200880_de(u32, void *, s32);
extern void func_80200D18_de(u32, const void *, u32);
extern void func_80200E04_de(u32, u8 *, u32);
extern void func_8020095C_de(u32, u8 *, u32);
/* Create the host request queues and start the request thread once (thread id FS). */
void Libsn_InitializeHostRequestThread(s32 threadPriority) {
    if (D_800C8140_de == 0) {
        D_800C8140_de = 1;
        osCreateMesgQueue(&D_800F2CC0, &D_800F2CB4, 1);
        osCreateMesgQueue(&D_800F2F40, &D_800F2CB0, 1);
        osCreateMesgQueue(&D_800F3110, &D_800F2F58, 1);
        osCreateMesgQueue(&D_800F1C90, &D_800F1C84, 1);
        osSetEventMesg(0, &D_800F1C90, (void *)1);
        osCreateThread(&D_800F2F60, 0x4653, D_002018A0, 0, D_800F2CE0 - 0x30, threadPriority);
        osStartThread(&D_800F2F60);
    }
}
#ifdef NON_MATCHING
/* 46/46 words; the ROM's `break 1` in the poll loop's failure arm is inline asm (cc1 has no trap builtin), so no ROM-path C */
s32 func_802017E8_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80200568_de(0xB1FFFFE4, arg1);
    func_80200568_de(0xB1FFFFE8, arg2);
    func_80200568_de(0xB1FFFFEC, arg3);
    func_80200568_de(0xB1FFFFE0, arg0);
    do {
        func_802005DC_de(0x3E8);
        if (func_802005A0_de(0xB1FFFFF0) != 0) {
#if defined(__i386__) || defined(__x86_64__)
            __builtin_trap();
#else
            __asm__ volatile ("break 1");
#endif
        }
    } while (func_802005A0_de(0xB1FFFFE0) != 0);
    return func_802005A0_de(0xB1FFFFDC);
}
#else
INCLUDE_ASM("span_1000", func_802017E8_de);
#endif
void func_802018A0_de(void) {
    ControllerRequest *request;
    for (;;) {
        osRecvMesg(&D_800F2F40, (OSMesg *)&request, 1);
        if (request->status != 0 && request->reserved == 1) {
            if (request->command & 0x80000000) {
                D_800C8140_de = 0;
            }
            func_80200E04_de(0xB1FF0000, (u8 *)request->header, request->status);
            if (request->command & 0x80000000) {
                D_800C8140_de = 1;
            }
        }
        osRecvMesg(&D_800F1C90, 0, 0);
        func_80200568_de(0xB1FFFFE4, request->argument0);
        func_80200568_de(0xB1FFFFE8, request->argument1);
        func_80200568_de(0xB1FFFFEC, request->argument2);
        func_80200568_de(0xB1FFFFD8, 0x01010101);
        func_80200568_de(0xB1FFFFE0, (u16)request->command);
        osRecvMesg(&D_800F1C90, 0, 1);
        if (request->status != 0 && request->reserved == 0) {
            s32 length = func_802005A0_de(0xB1FFFFDC);
            if (length != 0) {
                if (request->command & 0x80000000) {
                    D_800C8140_de = 0;
                }
                func_8020095C_de(0xB1FF0000, (u8 *)request->header, length);
                if (request->command & 0x80000000) {
                    D_800C8140_de = 1;
                }
            }
        }
        if (request->reply != 0) {
            osSendMesg(request->reply, (OSMesg)func_802005A0_de(0xB1FFFFDC), 1);
        }
    }
}
/* Issue the monitor command with interrupts disabled, then restore them. */
s32 func_80201A80_de(void)
{
    s32 previous;
    s32 result;
    previous = func_80200500_de();
    D_800C8144_de = 1;
    result = func_802017E8_de(0x101, 0, 0, 0);
    func_80200538_de(previous);
    return result;
}
void *func_80201AD0_de(void) {
    ControllerRequest request;
    ControllerResponse response;
    D_800C8144_de = 2;
    Libsn_InitializeHostRequestThread(0xFF);
    request.status = 0;
    request.command = 0x80000101;
    request.argument0 = 0;
    request.argument1 = 0;
    request.argument2 = 0;
    request.reply = &D_800F3110;
    osSendMesg(&D_800F2F40, &request, 1);
    osRecvMesg(&D_800F3110, &response.message, 1);
    return response.message;
}
u32 func_80201B50_de(u8 *buffer, s32 argument) {
    ControllerRequest request;
    ControllerResponse response;
    s32 length;
    s32 saved;
    length = func_802016DC_de(buffer);
    if (D_800C8144_de == 2) {
        request.status = length;
        request.argument0 = length;
        request.header = (u32)buffer;
        request.reserved = 1;
        request.command = 0x80000202;
        request.argument1 = argument;
        request.argument2 = 0;
        request.reply = &D_800F3110;
        osSendMesg(&D_800F2F40, &request, 1);
        osRecvMesg(&D_800F3110, &response.message, 1);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
    } else {
        saved = func_80200500_de();
        length = func_802016DC_de(buffer);
        func_80200D18_de(0xB1FF0000, buffer, length);
        response.status = func_802017E8_de(0x202, length, argument, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        func_80200538_de(saved);
    }
    return response.status;
}
s32 func_80201C80_de(u8 *name, u32 flags) {
    ControllerRequest request;
    ControllerResponse response;
    s32 length;
    s32 saved;
    length = func_802016DC_de(name);
    if (D_800C8144_de == 2) {
        request.status = length;
        request.argument0 = length;
        request.header = (u32)name;
        request.reserved = 1;
        request.command = 0x80000303;
        request.argument1 = flags;
        request.argument2 = 0;
        request.reply = &D_800F3110;
        osSendMesg(&D_800F2F40, &request, 1);
        osRecvMesg(&D_800F3110, &response.message, 1);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
    } else {
        saved = func_80200500_de();
        length = func_802016DC_de(name);
        func_80200D18_de(0xB1FF0000, name, length);
        response.status = func_802017E8_de(0x303, length, flags, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        func_80200538_de(saved);
    }
    return response.status;
}
s32 func_80201DB0_de(s32 arg0) {
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
        osSendMesg(&D_800F2F40, &request, 1);
        osRecvMesg(&D_800F3110, &response.message, 1);
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
s32 func_80201E94_de(s32 channel, u8 *destination, u32 remaining) {
    ControllerRequest request;
    ControllerResponse response;
    s32 total = 0;
    s32 saved;
    u32 chunk;
    if (D_800C8144_de == 2) {
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) {
                chunk = 0x8000;
            }
            request.header = (u32)destination;
            request.status = 1;
            request.reserved = 0;
            request.command = 0x80000505;
            request.argument0 = channel;
            request.argument1 = chunk;
            request.argument2 = 0;
            request.reply = &D_800F3110;
            osSendMesg(&D_800F2F40, &request, 1);
            osRecvMesg(&D_800F3110, &response.message, 1);
            if (response.status == 0) {
                return total;
            }
            destination += response.status;
            total += response.status;
            remaining -= response.status;
        }
    } else {
        saved = func_80200500_de();
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) {
                chunk = 0x8000;
            }
            response.status = func_802017E8_de(0x505, channel, chunk, 0);
            if (response.status == 0) {
                break;
            }
            func_80200880_de(0xB1FF0000, destination, response.status);
            destination += response.status;
            total += response.status;
            remaining -= response.status;
        }
        func_80200538_de(saved);
    }
    return total;
}
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
            osSendMesg(&D_800F2F40, &request, 1);
            osRecvMesg(&D_800F3110, &response.message, 1);
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
        osSendMesg(&D_800F2F40, &request, 1);
        osRecvMesg(&D_800F3110, &response.message, 1);
    } else {
        saved = func_80200500_de();
        response.status = func_802017E8_de(0x707, arg0, arg1, arg2);
        func_80200538_de(saved);
    }
    return response.status;
}
