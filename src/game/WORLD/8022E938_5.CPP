#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "WORLD/8022E938.H"
#include "TYPES.H"
#include "WORLD/8022E938_5.H"

extern u8 D_80102B00[];
extern u8 D_80102B08[];
extern s8 D_800FEB0C[];
extern s8 D_80102B0D[];
extern s8 D_800FEB0E[];
extern s8 D_80102C89[];
extern s8 D_800FEC8A[];
extern s8 D_800FEC8B[];
extern s8 D_800FEC8C[];
extern s8 D_800FEC8D[];
extern u8 g_playerSettings[];
extern s32 D_800D34E0;

extern void func_8022EF30_de(void *arg0);
extern void func_802A0C08_de(void *arg0, s32 arg1, s32 arg2);

void func_8022F204_de(s32 arg0) {
    s32 offset;
    u8 *entry;
    u8 *config;

    offset = arg0 * 0x190;
    entry = D_80102B00 + offset;
    func_8022EF30_de(entry);
    *(s32 *)(D_80102B08 + offset) = 0;
    D_80102B0D[offset] = arg0;
    D_800FEB0C[offset] = 0;
    D_800FEB0E[offset] = 1;
    func_802A0C08_de(entry, D_800D34E0, arg0 + 1);
    config = g_playerSettings + arg0 * 0x96;
    D_80102C89[offset] = config[0x7B];
    D_800FEC8A[offset] = config[0x7D];
    D_800FEC8B[offset] = config[0x79];
    D_800FEC8C[offset] = config[0x7A];
    D_800FEC8D[offset] = config[0x82];
}

void func_8022F314_de(void *arg0, unsigned char arg1) {
    ((ObjCode8022E938 *)arg0)->value14 = arg1;
}

/** Advance the byte at offset 0x14 by ten. */
void func_8022F31C_de(void *object) {
    ((ObjCode8022E938 *)object)->value14 += 10;
}

/** Read the byte at object offset 0x14. */
unsigned char func_8022F32C_de(ObjCode8022E938 *arg0) {
    return arg0->value14;
}

/** Store a byte in the object field at offset 0x15. */
void func_8022F338_de(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value15 = value;
}

int func_8022F340_de(void *player) {
    int v = ((ObjCode8022E938 *)player)->value15 + 0x32;
    ((ObjCode8022E938 *)player)->value15 = (unsigned char)v;
    return v;
}

unsigned char func_8022F350_de(ObjCode8022E938 *arg0) {
    return arg0->value15;
}

/** Store the supplied byte at offset 0x16. */
void func_8022F35C_de(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value16 = value;
}

int func_8022F364_de(void *player) {
    int v = ((ObjCode8022E938 *)player)->value16 + 0x32;
    ((ObjCode8022E938 *)player)->value16 = (unsigned char)v;
    return v;
}

/** Read the object byte at offset 0x16. */
unsigned char func_8022F374_de(ObjCode8022E938 *object) {
    return object->value16;
}

void func_8022F380_de(void *arg0, int arg1) {
    ((ObjCode8022E938 *)arg0)->progress = arg1;
}

/** Advance the word at offset 0x10 by 0x500. */
void func_8022F388_de(void *object) {
    ((ObjCode8022E938 *)object)->progress += 0x500;
}

/** Return the word stored at offset 0x10. */
unsigned int func_8022F398_de(ObjCode8022E938 *object) {
    return object->progress;
}

/* Stores a byte into the object's slot table at 0x18: indices 0 to 10 directly, 17 and 18 into
   slots 11 and 12, and other indices are ignored. */


void func_8022F3A4_de(ObjCode8022E938 *obj, int index, char value) {
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
    obj->slots[index] = value;
}
