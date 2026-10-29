#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include "sdk/os.h"

/* 802C0390_9.CPP */
#if defined(VERSION_DE)
unsigned char g_SeteventmesgTrailingBytes[4] = { 0x0C, 0x0A, 0xF3, 0xC8 };
#endif

/* seteventmesg.c */
extern struct IntPair g_osEventMessageBindings[];

void osSetEventMesg(s32 eventId, s32 messageQueue, s32 message) {
    u32 mask;
    struct IntPair *e;

    mask = __osDisableInt();
    ;
    (&g_osEventMessageBindings[eventId])->first = messageQueue;
    (*(&g_osEventMessageBindings[eventId])).second = message;
    __osRestoreInt(mask);
}
