#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "include_asm.h"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "TYPES.H"

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "RENDER_4/8028FD2C_6.H"
extern f32 D_800DCC78;
extern void func_80400E50_de(CVector3 *,void *,s32,s32);
extern void func_80271F68_de(CVector3 *,CVector3 *,CVector3 *);
extern f32 func_802725FC_de(CVector3 *),func_80271AA8_de(CVector3 *);
CVector3 func_80403660_de(void) {
    CVector3 first,second,delta,result,temp,fallback;
    StridedTable *table;
    if (D_800E2830->active == 0) {
        result.x = 0;
        result.y = 0;
    } else {
        table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource,0),0),0);
        func_80400E50_de(&temp,table->data,table->count,0);
        first = temp;
        if (D_800E2830->active == 0) {
            fallback.x = D_800DCC78;
            fallback.y = 0;
            fallback.z = 0;
            second = fallback;
        } else {
            table = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource,0),0),1);
            func_80400E50_de(&temp,table->data,table->count,0);
            second = temp;
        }
        func_80271F68_de(&delta,&second,&first);
        result.x = -func_802725FC_de(&delta);
        result.y = func_80271AA8_de(&delta);
    }
    result.z = 0;
    return result;
}
#else
INCLUDE_ASM("ovl_80400000", func_80403660_de);
#endif

/* Sets the word at offset 0xB4 of the object D_800E2830 points to. */




extern int D_800DE7E8;

extern unsigned char *D_80145060;

extern void func_804030E0_de(int);

static inline int test_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    return *bits & (mask << index);
}

static inline void set_bit(unsigned char *bits, int index) {
    int offset = index >> 3;
    int mask;
    index &= 7;
    mask = 1;
    bits += offset;
    *bits |= mask << index;
}

/* Returns the initial track vector or the configured fallback when no track is active. */


 /* extern */
void func_80400E50_de(CVector3 *, void *, s32, s32);

 /* extern */


/* Sums the duration values from the active resource tracks. */



/* Returns the first word of what func_8028FDB4_de gives for the object at offset 4 of the structure
   D_800E2830 points to, asked with zero. */




/* Walks three lookups through func_8028FDB4_de from the object at offset 4 of the structure
   D_800E2830 points to: first with zero, then with the argument, and returns the third lookup, with 0. */




/* Calls func_8028FDB4_de on the object at offset 4 of the structure D_800E2830 points to, with 1. */




/* Returns the byte size of a block holding a 0x30-byte header and a 36-byte record for every entry
   counted at offset 4 of the two lists func_8028FDB4_de returns for an object with zero and with
   two. */




void func_804037D4_de(void) {
    D_800E2830->fieldB4 = 1;
}

void func_804037E8_de(int event) {
    unsigned char *bits = D_80145060;
    int index;
    if (D_800DE7E8 != 0) {
        index = event - 0x259;
        if ((unsigned int)index < 6 && bits != 0) {
            if (test_bit(bits + 0x638, index)) return;
            set_bit(bits + 0x638, index);
        }
        func_804030E0_de(event);
    }
}

CVector3 func_8040385C_de(void) {
    CVector3 sp10;
    CVector3 sp20;
    StridedTable *temp_v0;
    if (D_800E2830->active == 0) {
        sp20.x = 0;
        sp20.y = 0;
        sp20.z = 0;
        return sp20;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource, 0), 0), 0);
    func_80400E50_de(&sp10, temp_v0->data, temp_v0->count, 0);
    return sp10;
}

CVector3 func_8040390C_de(void) {
    CVector3 sp10;
    CVector3 sp20;
    StridedTable *temp_v0;
    if (D_800E2830->active == 0) {
        sp20.y = 0;
        sp20.z = 0;
        sp20.x = D_800DCC7C_de;
        return sp20;
    }
    temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource, 0), 0), 1);
    func_80400E50_de(&sp10, temp_v0->data, temp_v0->count, 0);
    return sp10;
}

f32 func_804039C4_de(void) {
    f32 temp_f0;
    f32 var_f20;
    s32 *temp_v0;
    s32 var_s0;

    var_f20 = 0.0f;
    var_s0 = 0;
loop_1:
    if (var_s0 < *((s32 *)func_8028FDB4_de(D_800E2830->resource, 0))) {
        temp_v0 = func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource, 0), var_s0), 0);
        temp_v0 = (s32 *)((char *)temp_v0 + temp_v0[1] * 0x24);
        temp_f0 = *(f32 *)temp_v0;
        var_s0 += 1;
        var_f20 += temp_f0;
        goto loop_1;
    }
    return var_f20;
}

s32 func_80403A64_de(void) {
    return *((s32 *)func_8028FDB4_de(D_800E2830->resource, 0));
}

void *func_80403A90_de(s32 key) {
    return func_8028FDB4_de(func_8028FDB4_de(func_8028FDB4_de(D_800E2830->resource, 0), key), 0);
}

void *func_80403ADC_de(void) {
    return func_8028FDB4_de(D_800E2830->resource, 1);
}

/** Advance a byte pointer by eight bytes. */
void *func_80403B04_de(void *value) {
    ObjRecAt8V2 *record = value;
    return &record->unk8;
}

/** Return the selected bit from a packed byte array. */
u32 func_80403B0C_de(u8 *bits, s32 index)
{
    s32 byte = index >> 3;
    u32 mask;

    index &= 7;
    mask = 1;
    bits += byte;
    return *bits & (mask << index);
}

/* Sets or clears bit n of a bitmap according to the third argument. */
void func_80403B2C_de(u8 *bits, s32 n, s32 set) {
    s32 index = n >> 3;
    s32 mask = 1 << (n & 7);

    if (set) {
        bits[index] |= mask;
    } else {
        bits[index] &= ~mask;
    }
}

s32 func_80403B70_de(void *object) {
    struct IntPair *first = func_8028FDB4_de(object, 0);
    struct IntPair *second = func_8028FDB4_de(object, 2);
    s32 size = first->field_4 * 36;

    return size + second->field_4 * 36 + 0x30;
}
