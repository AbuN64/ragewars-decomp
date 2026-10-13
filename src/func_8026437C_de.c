#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802636D0.h"



/** Return the high bit of the byte at object offset 0xB6. */
unsigned int func_8026437C_de(struct ControllerProfile *arg0) {
    return arg0->connection.connectionStatus >> 7;
}
