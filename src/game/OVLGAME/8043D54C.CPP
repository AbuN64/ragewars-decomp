#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "OVLGAME/SHAREDRECAT224.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"

/* Toggles bit 4 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit2(void) {
    D_801462C8 ^= 4;
    return 0;
}

/* Refreshes option item arg0 from bit 0x4 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B1C when the bit is
   set in D_801462C8 and D_800D3B20 otherwise; returns zero. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit2Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x4) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x4) {
        item->unk14 = D_800D3B1C;
    } else {
        item->unk14 = D_800D3B20;
    }
    return 0;
}

/* Toggles bit 8 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit3(void) {
    D_801462C8 ^= 8;
    return 0;
}

/* Refreshes option item arg0 from bit 0x8 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B24 when the bit is
   set in D_801462C8 and D_800D3B28 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit3Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x8) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x8) {
        item->unk14 = D_800D3B24;
    } else {
        item->unk14 = D_800D3B28;
    }
    return 0;
}

/* Toggles bit 0x10 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit4(void) {
    D_801462C8 ^= 0x10;
    return 0;
}

/* Refreshes option item arg0 from bit 0x10 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B2C when the bit is
   set in D_801462C8 and D_800D3B30 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit4Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x10) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x10) {
        item->unk14 = D_800D3B2C;
    } else {
        item->unk14 = D_800D3B30;
    }
    return 0;
}

/* Toggles bit 0x20 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit5(void) {
    D_801462C8 ^= 0x20;
    return 0;
}

/* Refreshes option item arg0 from bit 0x20 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B34 when the bit is
   set in D_801462C8 and D_800D3B38 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit5Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x20) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x20) {
        item->unk14 = D_800D3B34;
    } else {
        item->unk14 = D_800D3B38;
    }
    return 0;
}

/* Toggles bit 0x40 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit6(void) {
    D_801462C8 ^= 0x40;
    return 0;
}

/* Refreshes option item arg0 from bit 0x40 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B3C when the bit is
   set in D_801462C8 and D_800D3B40 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit6Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x40) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x40) {
        item->unk14 = D_800D3B3C;
    } else {
        item->unk14 = D_800D3B40;
    }
    return 0;
}

/* Toggles bit 0x80 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit7(void) {
    D_801462C8 ^= 0x80;
    return 0;
}

/* Refreshes option item arg0 from bit 0x80 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B44 when the bit is
   set in D_801462C8 and D_800D3B48 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit7Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x80) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x80) {
        item->unk14 = D_800D3B44;
    } else {
        item->unk14 = D_800D3B48;
    }
    return 0;
}

/* Toggles bit 0x100 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit8(void) {
    D_801462C8 ^= 0x100;
    return 0;
}

/* Refreshes option item arg0 from bit 0x100 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B4C when the bit is
   set in D_801462C8 and D_800D3B50 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit8Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x100) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x100) {
        item->unk14 = D_800D3B4C;
    } else {
        item->unk14 = D_800D3B50;
    }
    return 0;
}

/* Toggles bit 0x200 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit9(void) {
    D_801462C8 ^= 0x200;
    return 0;
}

/* Refreshes option item arg0 from bit 0x200 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B54 when the bit is
   set in D_801462C8 and D_800D3B58 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit9Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x200) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x200) {
        item->unk14 = D_800D3B54;
    } else {
        item->unk14 = D_800D3B58;
    }
    return 0;
}

/* Toggles bit 0x400 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit10(void) {
    D_801462C8 ^= 0x400;
    return 0;
}

/* Refreshes option item arg0 from bit 0x400 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B5C when the bit is
   set in D_801462C8 and D_800D3B60 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit10Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x400) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x400) {
        item->unk14 = D_800D3B5C;
    } else {
        item->unk14 = D_800D3B60;
    }
    return 0;
}

/* Toggles bit 0x800 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit11(void) {
    D_801462C8 ^= 0x800;
    return 0;
}

/* Refreshes option item arg0 from bit 0x800 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B64 when the bit is
   set in D_801462C8 and D_800D3B68 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit11Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x800) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x800) {
        item->unk14 = D_800D3B64;
    } else {
        item->unk14 = D_800D3B68;
    }
    return 0;
}

/* Toggles bit 0x1000 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit12(void) {
    D_801462C8 ^= 0x1000;
    return 0;
}

/* Refreshes option item arg0 from bit 0x1000 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B6C when the bit is
   set in D_801462C8 and D_800D3B70 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit12Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x1000) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x1000) {
        item->unk14 = D_800D3B6C;
    } else {
        item->unk14 = D_800D3B70;
    }
    return 0;
}

/* Toggles bit 0x2000 of the option word D_801462C8 and returns zero; the functions after it in this
   run each toggle the next bit. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit13(void) {
    D_801462C8 ^= 0x2000;
    return 0;
}

/* Refreshes option item arg0 from bit 0x2000 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B74 when the bit is
   set in D_801462C8 and D_800D3B78 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit13Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x2000) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x2000) {
        item->unk14 = D_800D3B74;
    } else {
        item->unk14 = D_800D3B78;
    }
    return 0;
}

/* Toggles bit 0x4000 of the option word D_801462C8 and returns zero; it is one of a run of
   functions that each toggle one bit of that word. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit14(void) {
    D_801462C8 ^= 0x4000;
    return 0;
}

/* Refreshes option item arg0 from bit 0x4000 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B7C when the bit is
   set in D_801462C8 and D_800D3B80 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit14Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x4000) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x4000) {
        item->unk14 = D_800D3B7C;
    } else {
        item->unk14 = D_800D3B80;
    }
    return 0;
}

/* Toggles bit 0x8000 of the option word D_801462C8 and returns zero; it is one of a run of
   functions that each toggle one bit of that word. */
extern s32 D_801462C8;

s32 Items_ToggleOptionBit15(void) {
    D_801462C8 ^= 0x8000;
    return 0;
}

/* Refreshes option item arg0 from bit 0x8000 of the option words: the item's flag 0x1000000 at 0x8
   follows the bit in D_801462CC, and its text pointer at 0x14 becomes D_800D3B84 when the bit is
   set in D_801462C8 and D_800D3B88 otherwise; returns zero. Adapted from Items_UpdateOptionBit2Item with the bit changed. */


extern s32 D_801462C8;
extern s32 D_801462CC;

s32 Items_UpdateOptionBit15Item(struct StateRecAt14 *item) {
    if (D_801462CC & 0x8000) {
        item->unk8 |= 0x1000000;
    } else {
        item->unk8 &= ~0x1000000;
    }
    if (D_801462C8 & 0x8000) {
        item->unk14 = D_800D3B84;
    } else {
        item->unk14 = D_800D3B88;
    }
    return 0;
}

#if defined(VERSION_DE)
unsigned int func_8043DADC_de_padding_1A3ADC[1] = {
    0x3C048012,
};
#endif

#if defined(VERSION_US_REV1)
unsigned int func_8043DADC_de_padding_1ABCBC[1] = {
    0x8FBF0024,
};
#endif

#if defined(VERSION_US)
unsigned int func_8043DADC_de_padding_1A1CBC[1] = {
    0x6153697A,
};
#endif

#if defined(VERSION_EU_X)
unsigned int func_8043DADC_de_padding_12EAFC[1] = {
    0x2A020004,
};
#endif

#if defined(VERSION_EU)
unsigned int func_8043E9CC_eu_padding_1B49CC[1] = {
    0x1622005B,
};
#endif
