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

extern void Player_InitializeProfile(void *arg0);
extern void XStdio_FormatBuffer(void *arg0, s32 arg1, s32 arg2);

void Player_InitializeProfileSlot(s32 arg0) {
    s32 offset;
    u8 *entry;
    u8 *config;

    offset = arg0 * 0x190;
    entry = D_80102B00 + offset;
    Player_InitializeProfile(entry);
    *(s32 *)(D_80102B08 + offset) = 0;
    D_80102B0D[offset] = arg0;
    D_800FEB0C[offset] = 0;
    D_800FEB0E[offset] = 1;
    XStdio_FormatBuffer(entry, D_800D34E0, arg0 + 1);
    config = g_playerSettings + arg0 * 0x96;
    D_80102C89[offset] = config[0x7B];
    D_800FEC8A[offset] = config[0x7D];
    D_800FEC8B[offset] = config[0x79];
    D_800FEC8C[offset] = config[0x7A];
    D_800FEC8D[offset] = config[0x82];
}

void Player_SetProfileValue14(void *arg0, unsigned char arg1) {
    ((ObjCode8022E938 *)arg0)->value14 = arg1;
}

/** Advance the byte at offset 0x14 by ten. */
void Player_AddTenToProfileValue14(void *object) {
    ((ObjCode8022E938 *)object)->value14 += 10;
}

/** Read the byte at object offset 0x14. */
unsigned char Player_GetProfileValue14(ObjCode8022E938 *arg0) {
    return arg0->value14;
}

/** Store a byte in the object field at offset 0x15. */
void Player_SetProfileValue15(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value15 = value;
}

int Player_AddFiftyToProfileValue15(void *player) {
    int v = ((ObjCode8022E938 *)player)->value15 + 0x32;
    ((ObjCode8022E938 *)player)->value15 = (unsigned char)v;
    return v;
}

unsigned char Player_GetProfileValue15(ObjCode8022E938 *arg0) {
    return arg0->value15;
}

/** Store the supplied byte at offset 0x16. */
void Player_SetProfileValue16(void *object, unsigned char value) {
    ((ObjCode8022E938 *)object)->value16 = value;
}

int Player_AddFiftyToProfileValue16(void *player) {
    int v = ((ObjCode8022E938 *)player)->value16 + 0x32;
    ((ObjCode8022E938 *)player)->value16 = (unsigned char)v;
    return v;
}

/** Read the object byte at offset 0x16. */
unsigned char Player_GetProfileValue16(ObjCode8022E938 *object) {
    return object->value16;
}

void Player_SetProfileProgress(void *arg0, int arg1) {
    ((ObjCode8022E938 *)arg0)->progress = arg1;
}

/** Advance the word at offset 0x10 by 0x500. */
void Player_AdvanceProfileProgress(void *object) {
    ((ObjCode8022E938 *)object)->progress += 0x500;
}

/** Return the word stored at offset 0x10. */
unsigned int Player_GetProfileProgress(ObjCode8022E938 *object) {
    return object->progress;
}

/* Stores a byte into the object's slot table at 0x18: indices 0 to 10 directly, 17 and 18 into
   slots 11 and 12, and other indices are ignored. */


void Player_SetProfileSlotValue(ObjCode8022E938 *obj, int index, char value) {
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
