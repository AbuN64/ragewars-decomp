#ifndef SDK_OBJECTSTATE2_H
#define SDK_OBJECTSTATE2_H
#include "TYPES.H"






struct ObjectState2;
typedef struct ObjectState2 ObjectState2;





struct ReadWordByte;
typedef struct ReadWordByte ReadWordByte;






struct ReadWordByte;
struct ReadWordByte {
    s32 word;
    u8 byte;
    u8 value;
};




struct ObjectState2;
struct ObjectState2 {
    unsigned char padding_0[1];
    u8 unk_1;
};
#endif
