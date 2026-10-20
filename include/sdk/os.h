#ifndef SDK_OS_H
#define SDK_OS_H
#include "TYPES.H"
/* libultra OS calls the game makes by name. */
typedef void *OSMesg;
typedef u32 OSIntMask;
extern void __osRestoreInt(OSIntMask mask);
extern void osCreateMesgQueue(OSMesgQueue *mq, OSMesg *msg, s32 msgCount);
extern s32 __osSiRawStartDma(s32 direction, void *dramAddr);
extern OSIntMask func_802BCF30_de(void); /* osSetIntMask, returns the previous mask */
extern s32 func_802BB2A0_de(OSMesgQueue *mq, OSMesg *msg, s32 flag); /* osRecvMesg */
extern s32 func_802BB420_de(OSMesgQueue *mq, OSMesg msg, s32 flag); /* osSendMesg */
#endif
