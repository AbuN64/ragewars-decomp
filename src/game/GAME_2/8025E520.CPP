#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/BOX_CONTACT.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/UNUSED.H"
#include "COMMON/S1_2.H"
#include "COMMON/STREAM.H"
#include "GAME_2/8025E520.H"

short func_8025E500_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->group;
}

short func_8025E50C_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->sample;
}

/** Return the signed byte at offset four in the supplied object. */
int func_8025E518_de(void *object) {
    return ((ControllerCode802591C0 *)object)->priority;
}

/** Return the signed byte at offset five. */
int func_8025E524_de(ControllerCode802591C0 *arg0) {
    return arg0->mode;
}

/** Return the signed halfword at offset eight. */
int func_8025E530_de(char *object) {
    return ((ControllerCode802591C0 *)object)->field8;
}

short func_8025E53C_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->preset;
}

/** Return the upper two bits of the halfword at object offset 6. */
unsigned int func_8025E548_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->flags >> 14;
}

signed char func_8025E554_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->pitch;
}

/** Read the signed object byte at offset 0xF. */
signed char func_8025E560_de(void *object) {
    return ((ControllerCode802591C0 *)object)->fieldF;
}

/** Return the signed halfword stored at offset 0x10. */
int func_8025E56C_de(void *object) {
    return ((ControllerCode802591C0 *)object)->yaw;
}

unsigned short func_8025E578_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->flags & 0x3FFF;
}

short func_8025E584_de(ControllerCode802591C0 *arg0) {
    return arg0->x;
}

/** Return the signed halfword at offset 0x14 in the supplied object. */
int func_8025E590_de(ControllerCode802591C0 *object) {
    return object->y;
}

/** Return the signed halfword at offset twelve. */
int func_8025E59C_de(void *arg0) {
    return ((ControllerCode802591C0 *)arg0)->fieldC;
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", func_8025E59C_de_padding_5F148);
#endif

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_8025E54C);
#endif
