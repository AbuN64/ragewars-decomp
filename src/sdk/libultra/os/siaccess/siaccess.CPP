#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/CONTREADFORMAT.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/CONTROLLER_MOTOR_STATE.H"
#include "COMMON/BOOT_MEMORY_AND_THREAD_BOUNDARIES.H"
#include "sdk/OS/siaccess.H"
#include "sdk/os.h"
#include "COMMON/LONE/siaccess.H"

/* 802BECB0.CPP */
void __osSiCreateAccessQueue(void) {
    extern OSMesgQueue g_serialInterfaceAccessQueue;
    extern OSMesg g_serialInterfaceAccessMessage;
    g_serialInterfaceAccessQueueInitialized[0] = 1;
    osCreateMesgQueue(&g_serialInterfaceAccessQueue, &g_serialInterfaceAccessMessage, 1);
    osSendMesg(&g_serialInterfaceAccessQueue, 0, 0);
}

/* 802BECB0_2.CPP */
/* Takes the access token from the message queue g_serialInterfaceAccessQueue, first creating that one-message queue
   over D_8014EA70 with osCreateMesgQueue and seeding it with a null message through func_802BB420_de
   when g_serialInterfaceAccessQueueInitialized says it does not exist yet. Adapted from __osPiGetAccess with the queue, its buffer and its flag changed. */

static inline void create_access_queue(void) {
    extern OSMesgQueue g_serialInterfaceAccessQueue;
    extern OSMesg g_serialInterfaceAccessMessage;
    g_serialInterfaceAccessQueueInitialized[0] = 1;
    osCreateMesgQueue(&g_serialInterfaceAccessQueue, &g_serialInterfaceAccessMessage, 1);
    osSendMesg(&g_serialInterfaceAccessQueue, 0, 0);
}

void __osSiGetAccess(void) {
    extern OSMesgQueue g_serialInterfaceAccessQueue;
    OSMesg token;

    if (!g_serialInterfaceAccessQueueInitialized[0]) {
        create_access_queue();
    }
    osRecvMesg(&g_serialInterfaceAccessQueue, &token, 1);
}
