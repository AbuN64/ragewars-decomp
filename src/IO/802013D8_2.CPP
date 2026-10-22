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

#ifdef NON_MATCHING
/* Shared declarations of the drafts below (one place, so every draft compiles together under -DNON_MATCHING). */
#include "IO/CONTROLLER_REQUEST.H"
extern s32 D_002018A0;
extern s32 D_800C8140_de;
extern s32 D_800C8144_de;
extern void *D_800F1C84;
extern OSMesgQueue D_800F1C90;
extern void *D_800F2CB0;
extern void *D_800F2CB4;
extern OSMesgQueue D_800F2CC0;
extern OSMesgQueue D_800F2F40;
extern void *D_800F2F58;
extern s32 D_800F2F60;
extern OSMesgQueue D_800F3110;
s32 func_802BAC90_de(s32 *, s32, s32 *, s32, void **, s32);
s32 func_802BB550_de(s32, OSMesgQueue *, s32);
s32 func_802BB750_de(s32 *);
extern s32 func_80200500_de(void);
extern s32 func_802017E8_de(s32, s32, s32, s32);
extern void func_80200880_de(u32, void *, s32);
extern void func_80200D18_de(u32, const void *, u32);
#endif
#ifdef NON_MATCHING
void func_802016FC_de(s32 arg0) {
    if (D_800C8140_de == 0) {
        D_800C8140_de = 1;
        osCreateMesgQueue(&D_800F2CC0, &D_800F2CB4, 1);
        osCreateMesgQueue(&D_800F2F40, &D_800F2CB0, 1);
        osCreateMesgQueue(&D_800F3110, &D_800F2F58, 1);
        osCreateMesgQueue(&D_800F1C90, &D_800F1C84, 1);
        func_802BB550_de(0, &D_800F1C90, 1);
        func_802BAC90_de(&D_800F2F60, 0x4653, &D_002018A0, 0, &D_800F2CB0, arg0);
        func_802BB750_de(&D_800F2F60);
    }
}
#else
INCLUDE_ASM("span_1000", func_802016FC_de);
#endif
#ifdef NON_MATCHING
/* 29/59 words; remaining: the ROM's `break 1` in the poll loop's failure arm, which plain C cannot express */
s32 func_802017E8_de(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_80200568_de(0xB1FFFFE4, arg1);
    func_80200568_de(0xB1FFFFE8, arg2);
    func_80200568_de(0xB1FFFFEC, arg3);
    func_80200568_de(0xB1FFFFE0, arg0);
    do {
        func_802005DC_de(0x3E8);
        if (func_802005A0_de(0xB1FFFFF0) != 0) {
            /* the ROM executes break 1 here */
        }
    } while (func_802005A0_de(0xB1FFFFE0) != 0);
    return func_802005A0_de(0xB1FFFFDC);
}
#else
INCLUDE_ASM("span_1000", func_802017E8_de);
#endif
INCLUDE_ASM("span_1000", func_802018A0_de);
#ifdef NON_MATCHING
/* Issue the monitor command with interrupts disabled, then restore them. */
/* 13/22 words; remaining: this unit's gcc 2.8.1 stores D_800C8144_de through $at; the ROM splits %hi into $a0 and ends jr/addiu like the kmc gcc 2.7.2 IO units */
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
#else
INCLUDE_ASM("span_1000", func_80201A80_de);
#endif
#ifdef NON_MATCHING
/* 43/43 words, ~10 differ; remaining: the ROM stores D_800C8144_de through an explicit %hi register ($v1) scheduled early, kmc cc1 stores through $at */
void *func_80201AD0_de(void) {
    ControllerRequest request;
    ControllerResponse response;
    D_800C8144_de = 2;
    func_802016FC_de(0xFF);
    request.status = 0;
    request.command = 0x80000101;
    request.argument0 = 0;
    request.argument1 = 0;
    request.argument2 = 0;
    request.reply = &D_800F3110;
    func_802BB420_de(&D_800F2F40, &request, 1);
    func_802BB2A0_de(&D_800F3110, &response.message, 1);
    return response.message;
}
#else
INCLUDE_ASM("span_1000", func_80201AD0_de);
#endif
#ifdef NON_MATCHING
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
        func_802BB420_de(&D_800F2F40, &request, 1);
        func_802BB2A0_de(&D_800F3110, &response.message, 1);
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
#else
INCLUDE_ASM("span_1000", func_80201B50_de);
#endif
#ifdef NON_MATCHING
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
        func_802BB420_de(&D_800F2F40, &request, 1);
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
        func_802BB420_de(&D_800F2F40, &request, 1);
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
            func_802BB420_de(&D_800F2F40, &request, 1);
            func_802BB2A0_de(&D_800F3110, &response.message, 1);
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
#else
INCLUDE_ASM("span_1000", func_80201E94_de);
#endif
#ifdef NON_MATCHING
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
            func_802BB420_de(&D_800F2F40, &request, 1);
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
/* 64/64 words, 2 differ; remaining: the ROM loads D_800C8144_de as lui $v0 / lw $v1,%lo($v0) (explicit %hi register), kmc cc1 expands the lw through its destination register */
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
        func_802BB420_de(&D_800F2F40, &request, 1);
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
