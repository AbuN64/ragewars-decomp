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

INCLUDE_ASM("span_1000", func_802016FC_de);

INCLUDE_ASM("span_1000", func_802017E8_de);

INCLUDE_ASM("span_1000", func_802018A0_de);

#ifdef NON_MATCHING
#include "TYPES.H"
extern s32 func_80200500_de(void);
extern s32 func_802017E8_de(s32, s32, s32, s32);
extern s32 D_800C8144_de;
/* Issue the monitor command with interrupts disabled, then restore them. */
s32 func_80201A74_de(void)
{
    s32 previous;
    s32 result;
    previous = func_80200500_de();
    D_800C8144_de = 1;
    result = func_802017E8_de(0x101, 0, 0, 0);
    func_80200538_de(previous);
    return result;
}
#else
INCLUDE_ASM("span_1000", func_80201A80_de);
#endif

#ifdef NON_MATCHING
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
#else
INCLUDE_ASM("span_1000", func_80201AD0_de);
#endif

#ifdef NON_MATCHING
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
extern s32 func_80200500_de(void);
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
#else
INCLUDE_ASM("span_1000", func_80201B50_de);
#endif

#ifdef NON_MATCHING
#include "IO/CONTROLLER_REQUEST.H"
extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern s32 func_80200500_de(void);
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
#else
INCLUDE_ASM("span_1000", func_80201C80_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"

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
extern s32 func_80200500_de(void);
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
#else
INCLUDE_ASM("span_1000", func_80201DB0_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
typedef struct { void *destination; s32 command,unused; u32 address; s32 channel; u32 count; s32 zero; void *reply; } DraftRequest;
extern s32 D_800C8144_de;
extern u8 D_800F2F40[], D_800F3110[];
extern s32 func_80200500_de(void);
extern s32 func_802017E8_de(s32,s32,u32,s32);
extern void func_80200880_de(u32,void *,s32);
s32 func_80201E94_de(s32 channel, u8 *destination, u32 remaining)
{
  DraftRequest request;
  s32 received[2];
  s32 total = 0;
  s32 saved;
  u32 chunk;
  if (D_800C8144_de == 2)
  {
    while (remaining != 0)
    {
      chunk = remaining;
      if (saved = chunk > 0x8000)
      {
        chunk = 0x8000;
      }
      request.destination = destination;
      request.command = 1;
      request.unused = 0;
      request.address = 0x80000505;
      request.channel = channel;
      request.count = chunk;
      request.zero = 0;
      request.reply = D_800F3110;
      func_802BB420_de(D_800F2F40, &request, 1);
      func_802BB2A0_de(D_800F3110, received, 1);
      if (received[0] == 0)
      {
        return total;
      }
      destination += received[0];
      total += received[0];
      remaining -= received[0];
    }

  }
  else
  {
    saved = func_80200500_de();
    while (remaining != 0)
    {
      chunk = remaining;
      if (chunk > 0x8000)
      {
        chunk = 0x8000;
      }
      received[0] = func_802017E8_de(0x505, channel, chunk, 0);
      if (received[0] == 0)
      {
        break;
      }
      func_80200880_de(0xb1ff0000, destination, received[0]);
      destination += received[0];
      total += received[0];
      remaining -= received[0];
    }

    func_80200538_de(saved);
  }
  return total;
}
#else
INCLUDE_ASM("span_1000", func_80201E94_de);
#endif

#ifdef NON_MATCHING
#include "IO/CONTROLLER_REQUEST.H"
extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern s32 func_80200500_de(void);
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
#else
INCLUDE_ASM("span_1000", func_80202018_de);
#endif

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/EXTERNS_18.H"

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
    s32 status;
} ControllerResponse;

extern s32 D_800C8144_de;
extern OSMesgQueue D_800F2F40;
extern OSMesgQueue D_800F3110;
extern s32 func_80200500_de(void);
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
#else
INCLUDE_ASM("span_1000", func_80202198_de);
#endif
