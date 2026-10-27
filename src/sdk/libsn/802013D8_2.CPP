#include "IO/80200568.H"
#include "include_asm.h"
#include "COMMON/EXTERNS_15.H"
#include "TYPES.H"
#include "sdk/os.h"

/** Return strlen(arg0) + 1 (byte count including the terminating NUL). */
s32 Libsn_MeasureTerminatedString(u8 *arg0) {
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
void osSetEventMesg(s32 event, OSMesgQueue *queue, void *message); /* osSetEventMesg */
void osStartThread(OSThread_s *thread); /* osStartThread */
extern s32 Libsn_SendHostCommand(s32, s32, s32, s32);
extern void Libsn_ReadPortBuffer(u32, void *, s32);
extern void Libsn_WritePortBuffer(u32, const void *, u32);
extern void Libsn_WritePortBufferWithDma(u32, u8 *, u32);
extern void Libsn_ReadPortBufferWithDma(u32, u8 *, u32);
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
/* Host monitor call: writes the three arguments and then the command word to the SN cart port, polls until
   the host clears the command (a set error word raises SN's debugger trap `break 1`; cc1 has no construct
   for it, SN wrote it inline in their runtime: the only `break 1` in the ROM) and returns the host's reply. */
s32 Libsn_SendHostCommand(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    Libsn_WritePortWord(0xB1FFFFE4, arg1);
    Libsn_WritePortWord(0xB1FFFFE8, arg2);
    Libsn_WritePortWord(0xB1FFFFEC, arg3);
    Libsn_WritePortWord(0xB1FFFFE0, arg0);
    do {
        Libsn_SpinDelay(0x3E8);
        if (Libsn_ReadPortWord(0xB1FFFFF0) != 0) {
#if defined(__i386__) || defined(__x86_64__)
            __builtin_trap();
#else
            __asm__ volatile ("break 1");
#endif
        }
    } while (Libsn_ReadPortWord(0xB1FFFFE0) != 0);
    return Libsn_ReadPortWord(0xB1FFFFDC);
}
void Libsn_RunHostRequestThread(void) {
    ControllerRequest *request;
    for (;;) {
        osRecvMesg(&D_800F2F40, (OSMesg *)&request, 1);
        if (request->status != 0 && request->reserved == 1) {
            if (request->command & 0x80000000) {
                D_800C8140_de = 0;
            }
            Libsn_WritePortBufferWithDma(0xB1FF0000, (u8 *)request->header, request->status);
            if (request->command & 0x80000000) {
                D_800C8140_de = 1;
            }
        }
        osRecvMesg(&D_800F1C90, 0, 0);
        Libsn_WritePortWord(0xB1FFFFE4, request->argument0);
        Libsn_WritePortWord(0xB1FFFFE8, request->argument1);
        Libsn_WritePortWord(0xB1FFFFEC, request->argument2);
        Libsn_WritePortWord(0xB1FFFFD8, 0x01010101);
        Libsn_WritePortWord(0xB1FFFFE0, (u16)request->command);
        osRecvMesg(&D_800F1C90, 0, 1);
        if (request->status != 0 && request->reserved == 0) {
            s32 length = Libsn_ReadPortWord(0xB1FFFFDC);
            if (length != 0) {
                if (request->command & 0x80000000) {
                    D_800C8140_de = 0;
                }
                Libsn_ReadPortBufferWithDma(0xB1FF0000, (u8 *)request->header, length);
                if (request->command & 0x80000000) {
                    D_800C8140_de = 1;
                }
            }
        }
        if (request->reply != 0) {
            osSendMesg(request->reply, (OSMesg)Libsn_ReadPortWord(0xB1FFFFDC), 1);
        }
    }
}
/* Issue the monitor command with interrupts disabled, then restore them. */
s32 Libsn_InitializePollingHost(void)
{
    s32 previous;
    s32 result;
    previous = Libsn_DisableInterrupts();
    D_800C8144_de = 1;
    result = Libsn_SendHostCommand(0x101, 0, 0, 0);
    Libsn_RestoreInterruptEnable(previous);
    return result;
}
void *Libsn_InitializeQueuedHost(void) {
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
u32 Libsn_SendHostStringRequest(u8 *buffer, s32 argument) {
    ControllerRequest request;
    ControllerResponse response;
    s32 length;
    s32 saved;
    length = Libsn_MeasureTerminatedString(buffer);
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
        saved = Libsn_DisableInterrupts();
        length = Libsn_MeasureTerminatedString(buffer);
        Libsn_WritePortBuffer(0xB1FF0000, buffer, length);
        response.status = Libsn_SendHostCommand(0x202, length, argument, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        Libsn_RestoreInterruptEnable(saved);
    }
    return response.status;
}
s32 Libsn_SendHostNameFlags(u8 *name, u32 flags) {
    ControllerRequest request;
    ControllerResponse response;
    s32 length;
    s32 saved;
    length = Libsn_MeasureTerminatedString(name);
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
        saved = Libsn_DisableInterrupts();
        length = Libsn_MeasureTerminatedString(name);
        Libsn_WritePortBuffer(0xB1FF0000, name, length);
        response.status = Libsn_SendHostCommand(0x303, length, flags, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        Libsn_RestoreInterruptEnable(saved);
    }
    return response.status;
}
s32 Libsn_SendHostScalarRequest(s32 arg0) {
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
        saved = Libsn_DisableInterrupts();
        response.status = Libsn_SendHostCommand(0x404, arg0, 0, 0);
        if (response.status & 0x8000) {
            response.status |= 0xFFFF0000;
        }
        Libsn_RestoreInterruptEnable(saved);
    }
    return response.status;
}
s32 Libsn_ReadHostChannel(s32 channel, u8 *destination, u32 remaining) {
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
        saved = Libsn_DisableInterrupts();
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) {
                chunk = 0x8000;
            }
            response.status = Libsn_SendHostCommand(0x505, channel, chunk, 0);
            if (response.status == 0) {
                break;
            }
            Libsn_ReadPortBuffer(0xB1FF0000, destination, response.status);
            destination += response.status;
            total += response.status;
            remaining -= response.status;
        }
        Libsn_RestoreInterruptEnable(saved);
    }
    return total;
}
s32 Libsn_WriteHostChannel(s32 channel, u8 *source, u32 remaining) {
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
        saved = Libsn_DisableInterrupts();
        while (remaining != 0) {
            chunk = remaining;
            if (chunk > 0x8000) chunk = 0x8000;
            Libsn_WritePortBuffer(0xB1FF0000, source, chunk);
            response.status = Libsn_SendHostCommand(0x606, channel, chunk, 0);
            if (response.status == 0) break;
            source += response.status;
            total += response.status;
            remaining -= response.status;
        }
        Libsn_RestoreInterruptEnable(saved);
    }
    return total;
}
s32 Libsn_SendHostTripleRequest(s32 arg0, u32 arg1, s32 arg2) {
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
        saved = Libsn_DisableInterrupts();
        response.status = Libsn_SendHostCommand(0x707, arg0, arg1, arg2);
        Libsn_RestoreInterruptEnable(saved);
    }
    return response.status;
}
