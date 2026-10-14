#include "types.h"
#include "span_1000/code_8022BA90.h"
#include "span_C76B0/data.h"
/* Initialises an object: clears the words at 0x8, 0x9C, 0xA4, 0xA8, 0xB4 and 0xB8, sets the words at
   0x0 and 0x4 to -1, writes the two constants at D_800C2D48_de into the floats at 0xAC and 0xB0, the two
   at D_800C2D50_de into the floats at 0x90, 0x94 and 0x98 (the first of them twice) and D_800C2D58_de into
   the float at 0xA0. */


float func_8022C67C_de(void *arg0) {
    ObjRecAtB8 *obj = arg0;
    float f1 = D_800C2D48_de;
    float f2 = *(float *)((char *)&D_800C2D48_de + 4);
    float f0 = D_800C2D50_de;
    float f3 = *(float *)((char *)&D_800C2D50_de + 4);
    float f4 = D_800C2D58_de;

    obj->unkB4 = 0;
    obj->unk8 = 0;
    obj->unkB8 = 0;
    obj->unk4 = -1;
    obj->unk0 = -1;
    obj->unkA8 = 0;
    obj->unk9C = 0;
    obj->unkA4 = 0;
    obj->unkAC = f1;
    obj->unkB0 = f2;
    obj->unk90 = f0;
    obj->unk94 = f3;
    obj->unk98 = f0;
    obj->unkA0 = f4;
}
