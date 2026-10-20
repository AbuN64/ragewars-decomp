#include "include_asm.h"
#include "COMMON/OBJECTLINKS14C.H"

/* Increments the object's byte counter for a slot in the table at 0x18: indices 0 to 10 directly,
   17 and 18 as slots 11 and 12, and other indices are ignored. */


void func_8022F3F8_de(Profile *obj, int index) {
    if (index == 17) {
        goto is17;
    }
    if (index < 18) {
        goto below18;
    }
    if (index == 18) {
        goto is18;
    }
    return;
below18:
    if (index >= 11) {
        return;
    }
    if (index < 0) {
        return;
    }
    goto store;
is18:
    index = 12;
    goto store;
is17:
    index = 11;
store:
    obj->levelProgress[index]++;
}

#include "COMMON/SHAREDPLAYER.H"

s32 func_8022F454_de(Profile *obj, s32 index) {
    if (index == 17) {
        goto slot17;
    }
    if (index < 18) {
        goto lower;
    }
    if (index == 18) {
        goto slot18;
    }
    goto invalid;
lower:
    if (index >= 11) { goto invalid; }
    if (index < 0) { goto invalid; }
    goto load;
slot17:
    index = 11;
    goto load;
slot18:
    index = 12;
    goto load;
invalid:
    return 2;
load:
    return obj->levelProgress[index];
}
