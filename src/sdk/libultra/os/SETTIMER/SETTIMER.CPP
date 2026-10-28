#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"

/* 802C07B0.CPP */
/* 802C07B0.CPP */
int osSetTimer(Node802C07B0 *node, u64 initialDelay, u64 repeatInterval, void *messageQueue, void *message) {
    u64 value;

    node->field10 = initialDelay;
    node->field0 = 0;
    node->field4 = 0;
    node->field8 = repeatInterval;
    if (initialDelay == 0) {
        node->field10 = repeatInterval;
    }
    node->field18 = messageQueue;
    node->field1C = message;
    value = __osInsertTimer(node);
    if (*(void **)D_800D5280 == node) {
        Util_SetTimerInterrupt(value);
    }
    return 0;
}

/* 802C0840_2.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BB74C_de_padding_BC34C[4] = { 0xAF, 0xBF, 0x00, 0x1C };
#endif

/* 802C0840.CPP */
#if defined(VERSION_US)
unsigned char D_auto_func_802BB67C_us_padding_BC27C[4] = { 0x6C, 0x54, 0x00, 0x00 };
#endif

/* 802C0840_12.CPP */
#if defined(VERSION_EU_X) || defined(VERSION_US_REV1)
/* Data separated from executable functions by the legacy split layout. */
unsigned int func_802BBA2C_eu_x[1] = { 0x3C1AA430U };
#endif

/* 802C0840_5.CPP */
#if defined(VERSION_EU)
unsigned char D_auto_func_802BB9EC_eu_padding_BC5EC[4] = { 0x46, 0x1B, 0xCE, 0x42 };
#endif
