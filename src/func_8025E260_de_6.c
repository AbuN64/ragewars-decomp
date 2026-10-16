#include "common/unused.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_8025E280.h"

short func_8025E500_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->group;
}

short func_8025E50C_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->sample;
}

/** Return the signed byte at offset four in the supplied object. */
int func_8025E518_de(void *object) {
    return ((Controller_func_80259C5C_de *)object)->priority;
}

/** Return the signed byte at offset five. */
int func_8025E524_de(Controller_func_80259C5C_de *arg0) {
    return arg0->mode;
}

/** Return the signed halfword at offset eight. */
int func_8025E530_de(char *object) {
    return ((Controller_func_80259C5C_de *)object)->field8;
}

short func_8025E53C_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->preset;
}

/** Return the upper two bits of the halfword at object offset 6. */
unsigned int func_8025E548_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->flags >> 14;
}

signed char func_8025E554_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->pitch;
}

/** Read the signed object byte at offset 0xF. */
signed char func_8025E560_de(void *object) {
    return ((Controller_func_80259C5C_de *)object)->fieldF;
}

/** Return the signed halfword stored at offset 0x10. */
int func_8025E56C_de(void *object) {
    return ((Controller_func_80259C5C_de *)object)->yaw;
}

unsigned short func_8025E578_de(void *arg0) {
    return ((Controller_func_80259C5C_de *)arg0)->flags & 0x3FFF;
}

short func_8025E584_de(Controller_func_80259C5C_de *arg0) {
    return arg0->x;
}
