#include "COMMON/EXTERNS_18.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/MANAGER.H"
#include "SCENE/802508E0.H"
#include "TYPES.H"
#include "SCENE/802508E0_2.H"
#include "SCENE/802508E0_7.H"
#include "sdk/os.h"

extern OSMesgQueue D_80101140;
extern s32 s_allocText;

extern u32 __osDisableInt(void);
extern struct Shape_func_802BC570_de *func_802548B8_de(s32, s32, u32, s32 *);
extern void func_802511AC_de(s32);
extern s32 func_80254B58_de(s32, s32, s32);

/* Allocates size bytes (plus a 16-byte heap header) from the scene heap under the heap lock; when the
   heap is full it purges unused resources and retries. The game uses it as its malloc. */
Record *Cache_AllocateMemory(s32 size) {
    struct Shape_func_802BC570_de *node;
    struct Shape_func_802BC570_de *current;
    s32 allocation_size;
    s32 counter;
    s32 counter2;
    s32 counter3;
    s32 counter4;
    s32 payload;
    Record *result;
    u32 token;
    u32 token2;
    u32 token3;
    u32 token4;

    allocation_size = size + 0x10;
    token = __osDisableInt();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        osRecvMesg(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token);
    }
    node = func_802548B8_de(0, allocation_size, 0x33U, &s_allocText);
    token2 = __osDisableInt();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        osSendMesg(&D_80101140, 0, 1);
        current = node;
    } else {
        __osRestoreInt(token2);
        current = node;
    }
    if (current == 0) {
        token3 = __osDisableInt();
        counter3 = D_8010515C + 1;
        D_8010515C = counter3;
        if (counter3 != 1) {
            __osRestoreInt(token3);
            osRecvMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token3);
        }
        func_802511AC_de(0);
        do {
        } while (func_80254B58_de(0, 0, 0) != 0);
        func_802515F0_de(0, 1);
        token4 = __osDisableInt();
        counter4 = D_8010515C - 1;
        D_8010515C = counter4;
        if (counter4 != 0) {
            __osRestoreInt(token4);
            osSendMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token4);
        }
        token3 = __osDisableInt();
        counter3 = D_8010515C + 1;
        D_8010515C = counter3;
        if (counter3 != 1) {
            __osRestoreInt(token3);
            osRecvMesg(&D_80101140, 0, 1);
        } else {
            __osRestoreInt(token3);
        }
        node = func_802548B8_de(0, allocation_size, 0x33U, &s_allocText);
        token2 = __osDisableInt();
        counter2 = D_8010515C - 1;
        D_8010515C = counter2;
        if (counter2 != 0) {
            __osRestoreInt(token2);
            osSendMesg(&D_80101140, 0, 1);
            current = node;
        } else {
            __osRestoreInt(token2);
            current = node;
        }
    }
    if (current != 0) {
        payload = current->field_0;
        result = (Record *)(payload + 0x10);
        *(struct Shape_func_802BC570_de **)payload = current;
        return result;
    }
    return 0;
}

int func_802532F4_de(void *resource) {
    return ((Node80253610 *)resource)->flags & 0x100;
}

void func_80253300_de(Node80253610 *resource) {
    resource->references = resource->references + 1;
    resource->flags = resource->flags | 0x100;
}

void func_8025331C_de(Node80253610 *resource) {
    s32 remainingReferences;
    remainingReferences = resource->references - 1;
    resource->references = remainingReferences;
    if (remainingReferences == 0) {
        resource->flags = (s32) (resource->flags & ~0x100);
    }
}
