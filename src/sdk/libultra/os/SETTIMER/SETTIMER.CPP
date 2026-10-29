#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"

/* 802C07B0.CPP */
/* 802C07B0.CPP */
int osSetTimer(Node802C07B0 *node, u64 initialDelay, u64 repeatInterval, void *messageQueue, void *message) {
    u64 value;

    node->value = initialDelay;
    node->next = 0;
    node->prev = 0;
    node->interval = repeatInterval;
    if (initialDelay == 0) {
        node->value = repeatInterval;
    }
    node->mq = messageQueue;
    node->msg = message;
    value = __osInsertTimer(node);
    if (*(void **)g_timerListSentinel == node) {
        Util_SetTimerInterrupt(value);
    }
    return 0;
}

/* 802C0840_2.CPP */
#if defined(VERSION_DE)
unsigned char g_SettimerTrailingBytesBlock1[4] = { 0xAF, 0xBF, 0x00, 0x1C };
#endif

/* 802C0840.CPP */
#if defined(VERSION_US)
unsigned char g_SettimerTrailingBytes[4] = { 0x6C, 0x54, 0x00, 0x00 };
#endif

/* 802C0840_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BBA2C_eu_x[1] = { 0x3C1AA430U };
#endif

/* 802C0840_5.CPP */
#if defined(VERSION_EU)
unsigned char g_SettimerTrailingBytesBlock2[4] = { 0x46, 0x1B, 0xCE, 0x42 };
#endif
