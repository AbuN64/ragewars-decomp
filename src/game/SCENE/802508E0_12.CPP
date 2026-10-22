#include "COMMON/MANAGER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESOURCELOCKSTATE.H"
#include "COMMON/EXTERNS_18.H"
#include "TYPES.H"
#include "sdk/os.h"

extern OSMesgQueue D_80101140;

extern u32 func_802BCF30_de(void);


extern struct Shape_typemap_165 *func_802514A8_de(s32, u32);

extern void func_80254C70_de(s32 unused, void *object);

extern void func_80254AD0_de(s32 arg0, s32 arg1);


/** Read the global word at VRAM 0x8010517C. */


/** Read the global word at VRAM 0x8010513C. */

struct Shape_typemap_165 *func_80254480_de(s32 arg0, void *arg1, s32 arg2) {
    struct Shape_typemap_165 *node;
    s32 result;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;
    u32 flags;

    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token);
    }
    flags = ((ResourceLoadRequest *)arg1)->mode;
    node = func_802514A8_de(0, flags);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, arg2, (flags >> 5) & 1, flags);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = arg2;
            node->field_C |= flags;
            func_80254C70_de(0, node);
        } else {
            node->field_8--;
            if (node->field_8 == 0) {
                node->field_C &= ~0x100;
            }
            func_80254AD0_de(0, node);
            node = 0;
        }
    }
    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    return node;
}

struct Shape_typemap_165 *func_80254600_de(s32 arg0, s32 arg1, s32 arg2) {
    struct Shape_typemap_165 *node;
    s32 result;
    s32 counter;
    s32 counter2;
    u32 token;
    u32 token2;

    token = func_802BCF30_de();
    counter = D_8010515C + 1;
    D_8010515C = counter;
    if (counter != 1) {
        __osRestoreInt(token);
        func_802BB2A0_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token);
    }
    node = func_802514A8_de(0, 0x22U);
    if (node != 0) {
        node->field_8++;
        node->field_C |= 0x100;
        result = ((s32 (*)(s32, s32, s32, u32))func_80254B8C_de)(0, arg2, 1, 0x22U);
        node->field_0 = result;
        if (result != 0) {
            node->field_4 = arg2;
            node->field_C |= 0x22;
            func_80254C70_de(0, node);
        } else {
            node->field_8--;
            if (node->field_8 == 0) {
                node->field_C &= ~0x100;
            }
            func_80254AD0_de(0, node);
            node = 0;
        }
    }
    token2 = func_802BCF30_de();
    counter2 = D_8010515C - 1;
    D_8010515C = counter2;
    if (counter2 != 0) {
        __osRestoreInt(token2);
        func_802BB420_de(&D_80101140, 0, 1);
    } else {
        __osRestoreInt(token2);
    }
    return node;
}

/** Replace the global object word. */
void func_8025476C_de(unsigned int value) {
    extern unsigned int D_8010117C;
    D_8010117C = value;
}

int func_8025477C_de(void) {
    extern unsigned int D_8010117C;
    return D_8010117C;
}

/** Read the global word at VRAM 0x80105108. */


int func_8025478C_de(void) {
    return D_80101108;
}

int func_8025479C_de(void) {
    return D_8010513C;
}

/** Return the global word at D_80104580. */


int func_802547AC_de(void) {
    return D_80104580;
}

/** Read the global word at VRAM 0x80104580. */


int func_802547BC_de(void) {
    return D_80104580;
}

int func_802547CC_de(void) {
    return D_80104580;
}

int func_802547DC_de(void) {
    return 0;
}
