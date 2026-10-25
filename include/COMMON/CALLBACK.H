#ifndef COMMON_CALLBACK_H
#define COMMON_CALLBACK_H
#include "TYPES.H"
struct Callback;
typedef struct Callback Callback;


typedef struct ControllerAxisState {
    s16 oldX, oldY, oldZ;
    s16 x, y, z;
} ControllerAxisState;

struct Callback;
struct Callback {
    s32 (*callback)(void);
    /* 8029A324: base + 4 + device * 0xC0 + axis * 12. */
    ControllerAxisState axes[16][16];
    u8 flags[64]; /* 0xC04: 16 groups of four dispatch flags; allocation is 0xC44 */
};


struct NodeRecAt12;
typedef struct NodeRecAt12 NodeRecAt12;

extern float D_800C5688_de;




struct StreamBuffer;



struct NodeRecAt12;
struct NodeRecAt12 {
    s32 unk0;
    struct NodeRecAt12 *left;
    struct NodeRecAt12 *right;
    s16 value;
    u16 type;
    u16 unk10;
    u16 flags;
};








/* Sequential read/write buffer, allocated by StreamBufferAllocate and freed by
 * StreamBufferFree; read and append cursors are independent. */
typedef struct StreamBuffer {
    u8 *data;
    s32 capacity;
    s32 readPosition;
    s32 writePosition;
} StreamBuffer;
extern Callback *D_8014D0B0;
#endif
