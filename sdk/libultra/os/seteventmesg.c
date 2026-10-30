#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
#include <ultra64.h>
#include <PR/os_internal_reg.h>
#include <PR/os_internal_si.h>

/* 802C0390_9.CPP */
#if defined(VERSION_DE)
unsigned char g_SeteventmesgTrailingBytes[4] = { 0x0C, 0x0A, 0xF3, 0xC8 };
#endif

/* seteventmesg.c */
extern struct IntPair g_osEventMessageBindings[];

void osSetEventMesg(OSEvent eventId, OSMesgQueue *messageQueue, OSMesg message) {
    u32 mask;
    struct IntPair *e;

    mask = __osDisableInt();
    ;
    (&g_osEventMessageBindings[eventId])->first = messageQueue;
    (*(&g_osEventMessageBindings[eventId])).second = message;
    __osRestoreInt(mask);
}
