#ifndef RESMGR_802A0888_4_H
#define RESMGR_802A0888_4_H
#include "COMMON/MESSAGESEMAPHORE.H"
/* Single-message queue used by the acquire/release helpers. */
typedef struct MessageSemaphore {
    OSMesgQueue queue;
    s32 message;
} MessageSemaphore;
extern s32 XPlus_CompareStringsIgnoreCase(u8 *arg0, u8 *arg1);
extern u8 *XPlus_CopyStringBounded(u8 *arg0, u8 *arg1, s32 arg2);
extern void XPlus_SeedRandomGenerator(int arg0);
extern int XPlus_LowercaseCharacter(int arg0);
extern u8 *XPlus_FindByte(u8 *arg0, s32 arg1, s32 arg2);
extern void XPlus_BuildPath(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern u32 XPlus_UpdateCrc32(u8 *arg0, u32 arg1, u32 arg2);
extern u8 *XPlus_AppendStringBounded(u8 *destination, u8 *source, s32 count);
extern void XPlus_FormatDecimalInteger(s32 n, char *s);
extern u8 *XPlus_FindLastCharacter(u8 *s, int c);
extern s32 XPlus_CompareMemory(u8 *arg0, u8 *arg1, s32 arg2);
extern void *XPlus_FillBytes(void *arg0, int arg1, u32 arg2);
extern void *XPlus_CopyBytes(void *destination, const void *source, s32 bytes);
extern s32 XPlus_CompareStrings(const void *a, const void *b);
#endif
