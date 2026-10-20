#ifndef COMMON_MESSAGESEMAPHORE_H
#define COMMON_MESSAGESEMAPHORE_H
#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"

/* Single-message queue used by the acquire/release helpers. */
typedef struct MessageSemaphore {
    OSMesgQueue queue;
    s32 message;
} MessageSemaphore;

struct func_802A1A48_S1;
typedef struct func_802A1A48_S1 func_802A1A48_S1;



extern int D_8014D0C4;



extern int D_800CD900;



extern int D_8014D0C8;

struct func_802A1A48_S1;
struct func_802A1A48_S1 {
    char pad0[0x18];
    char unk18;
};



extern int D_8014D0C0;



extern signed int ( *D_8014D0CC)(char *, char *);
#endif
