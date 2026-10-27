#include "COMMON/NODERECAT1C.H"
#include "TYPES.H"

/* 802C07B0.CPP */
int func_802BB6C0_de(Node802C07B0 *node, u64 initialDelay, u64 repeatInterval, void *messageQueue, void *message) {
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
        func_802BBA4C_de(value);
    }
    return 0;
}

/* 802C0840_2.CPP */
#if defined(VERSION_DE)
unsigned char D_auto_func_802BB74C_de_padding_BC34C[4] = { 0xAF, 0xBF, 0x00, 0x1C };
#endif
