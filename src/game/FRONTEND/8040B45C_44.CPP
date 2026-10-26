#include "COMMON/NODERECAT2A8.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/FORMAT.H"
#include "TYPES.H"
#include "FRONTEND/8040B45C_44.H"

/* Reads the pixel at (x, y) of the current image D_80153D54 as a 0xAARRGGBB colour: seeks to
   x + y * width through the format's seek hook D_80153CD8, fetches through D_80153CD0 and converts
   the value with the format's channel masks and shifts like Frontend_ReadSourceColorEntry. */





extern s32 D_80153C78;

extern u32 D_8014DA00;

extern u32 D_8014DA04;

extern u32 D_8014DA08;

extern u32 D_8014DA0C;

extern void (*D_80153CD0)(void);

/* Sets the read position D_80153C78 to row y of column x, the row stride being the halfword at
   offset 8 of the structure D_80153D54 points to, calls the reader D_80153CD8 points to, and
   returns the value it left in D_80153C80. */




extern s32 D_80153C80;

/* Reads the pixel at index as a 0xAARRGGBB colour: stores the index for the current format's fetch
   hook D_80153CD0, then extracts each channel of the fetched value with the format's channel mask
   and signed shift (a negative shift scales up) and packs alpha, red, green and blue, using 0xFF
   for alpha when the format has no alpha mask. */

extern s32 D_80153C60;

/* Writes a 0xAARRGGBB colour to the pixel at (x, y) of the current target image D_80153D58:
   converts the colour to the format's packed value like Frontend_WriteDestinationColorEntry, then stores it and the
   index x + y * width for the format's store hook D_80153CD4 and calls it. */





extern s32 D_80153C6C;

extern u32 D_8014DA10;

extern u32 D_8014DA14;

extern u32 D_8014DA18;

extern u32 D_8014DA1C;

extern void (*D_80153CD4)(void);

/* Stores a value in D_80153C8C, sets the write position D_80153C84 to row y of column x, the row
   stride being the halfword at offset 8 of the structure D_80153D58 points to, and calls the
   writer D_80153CDC points to. */




extern void (*D_80153CDC)(void);

extern s32 D_80153C84;

/* Encodes an 0xAARRGGBB color into a packed pixel value of entry `format` of the format table D_800E2B20, shifting each channel by its signed shift and masking it. */




static inline u32 encode(u32 color, Format *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (format->shift[0] < 0) {
        r = (r >> -format->shift[0]) & format->mask[0];
    } else {
        r = (r << format->shift[0]) & format->mask[0];
    }
    if (format->shift[1] < 0) {
        g = (g >> -format->shift[1]) & format->mask[1];
    } else {
        g = (g << format->shift[1]) & format->mask[1];
    }
    if (format->shift[2] < 0) {
        b = (b >> -format->shift[2]) & format->mask[2];
    } else {
        b = (b << format->shift[2]) & format->mask[2];
    }
    if (format->shift[3] < 0) {
        a = (a >> -format->shift[3]) & format->mask[3];
    } else {
        a = (a << format->shift[3]) & format->mask[3];
    }
    return r | g | b | a;
}

static inline u32 decode(u32 value, Format *format) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    if (format->shift[0] < 0) {
        r = (value & format->mask[0]) << -format->shift[0];
    } else {
        r = (value & format->mask[0]) >> format->shift[0];
    }
    if (format->shift[1] < 0) {
        g = (value & format->mask[1]) << -format->shift[1];
    } else {
        g = (value & format->mask[1]) >> format->shift[1];
    }
    if (format->shift[2] < 0) {
        b = (value & format->mask[2]) << -format->shift[2];
    } else {
        b = (value & format->mask[2]) >> format->shift[2];
    }
    if (format->shift[3] < 0) {
        a = (value & format->mask[3]) << -format->shift[3];
    } else {
        a = (value & format->mask[3]) >> format->shift[3];
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

/* Loads the byte at offset D_80153C78 of the buffer D_80153C7C points to into both D_80153C80 and
   D_80153C60. */
/* The pixel buffers the format hooks read from (D_80153C64) and write to (D_80153C70); each hook reads
   them as the 16-bit, 32-bit or packed 24-bit pixels of its format. */
extern void *D_80153C64;
extern void *D_80153C70;
extern u32 D_80153C68; /* the fetched pixel */
extern u32 D_80153C74; /* the pixel to store */
extern u8 D_80153C76; /* the third byte of D_80153C74 */
extern void (*D_80153CD8)();
extern u8 *D_80153C7C;

/* Stores the byte (u8)D_80153C8C at the offset D_80153C84 within the buffer D_80153C88 points to. */
extern u8 *D_80153C88;


u32 Frontend_ReadSourcePixelColor(s32 x, s32 y) {
    extern ShapeCode802B54A0 *D_80153D54;
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    D_80153C78 = x + y * D_80153D54->unk8;
    D_80153CD8(D_80153C78);
    D_80153CD0();
    if (D_8014DA20 < 0) {
        r = (D_80153C68 & D_8014DA00) << -D_8014DA20;
    } else {
        r = (D_80153C68 & D_8014DA00) >> D_8014DA20;
    }
    if (D_8014DA24 < 0) {
        g = (D_80153C68 & D_8014DA04) << -D_8014DA24;
    } else {
        g = (D_80153C68 & D_8014DA04) >> D_8014DA24;
    }
    if (D_8014DA28 < 0) {
        b = (D_80153C68 & D_8014DA08) << -D_8014DA28;
    } else {
        b = (D_80153C68 & D_8014DA08) >> D_8014DA28;
    }
    if (D_8014DA2C < 0) {
        a = (D_80153C68 & D_8014DA0C) << -D_8014DA2C;
    } else {
        a = (D_80153C68 & D_8014DA0C) >> D_8014DA2C;
    }
    if (D_8014DA0C == 0) {
        a = 0xFF;
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

s32 Frontend_ReadSourcePixelIndex(s32 x, s32 y) {
    extern struct ShapeCode802B54A0 *D_80153D54;
    D_80153C78 = x + y * D_80153D54->unk8;
    D_80153CD8();
    return D_80153C80;
}

u32 Frontend_ReadSourceColorEntry(s32 index) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    D_80153C60 = index;
    D_80153CD0();
    if (D_8014DA20 < 0) {
        r = (D_80153C68 & D_8014DA00) << -D_8014DA20;
    } else {
        r = (D_80153C68 & D_8014DA00) >> D_8014DA20;
    }
    if (D_8014DA24 < 0) {
        g = (D_80153C68 & D_8014DA04) << -D_8014DA24;
    } else {
        g = (D_80153C68 & D_8014DA04) >> D_8014DA24;
    }
    if (D_8014DA28 < 0) {
        b = (D_80153C68 & D_8014DA08) << -D_8014DA28;
    } else {
        b = (D_80153C68 & D_8014DA08) >> D_8014DA28;
    }
    if (D_8014DA2C < 0) {
        a = (D_80153C68 & D_8014DA0C) << -D_8014DA2C;
    } else {
        a = (D_80153C68 & D_8014DA0C) >> D_8014DA2C;
    }
    if (D_8014DA0C == 0) {
        a = 0xFF;
    }
    return (a << 24) | (r << 16) | (g << 8) | b;
}

void Frontend_WriteDestinationPixelColor(s32 x, s32 y, u32 color) {
    extern ShapeCode802B54A0 *D_80153D58;
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (D_8014DA1C == 0) {
        a = 0xFF;
    }
    if (D_8014DA30 < 0) {
        r = (r >> -D_8014DA30) & D_8014DA10;
    } else {
        r = (r << D_8014DA30) & D_8014DA10;
    }
    if (D_8014DA34 < 0) {
        g = (g >> -D_8014DA34) & D_8014DA14;
    } else {
        g = (g << D_8014DA34) & D_8014DA14;
    }
    if (D_8014DA38 < 0) {
        b = (b >> -D_8014DA38) & D_8014DA18;
    } else {
        b = (b << D_8014DA38) & D_8014DA18;
    }
    if (D_8014DA3C < 0) {
        a = (a >> -D_8014DA3C) & D_8014DA1C;
    } else {
        a = (a << D_8014DA3C) & D_8014DA1C;
    }
    D_80153C74 = r | g | b | a;
    D_80153C6C = x + y * D_80153D58->unk8;
    D_80153CD4();
}

void Frontend_WriteDestinationPixelIndex(s32 x, s32 y, s32 value) {
    extern struct ShapeCode802B54A0 *D_80153D58;
    D_80153C8C = value;
    D_80153C84 = x + y * D_80153D58->unk8;
    D_80153CDC();
}

void Frontend_WriteDestinationColorEntry(s32 index, u32 color) {
    u32 r;
    u32 g;
    u32 b;
    u32 a;

    r = (color >> 16) & 0xFF;
    g = (color & 0xFF00) >> 8;
    b = color & 0xFF;
    a = color >> 24;
    if (D_8014DA1C == 0) {
        a = 0xFF;
    }
    if (D_8014DA30 < 0) {
        r = (r >> -D_8014DA30) & D_8014DA10;
    } else {
        r = (r << D_8014DA30) & D_8014DA10;
    }
    if (D_8014DA34 < 0) {
        g = (g >> -D_8014DA34) & D_8014DA14;
    } else {
        g = (g << D_8014DA34) & D_8014DA14;
    }
    if (D_8014DA38 < 0) {
        b = (b >> -D_8014DA38) & D_8014DA18;
    } else {
        b = (b << D_8014DA38) & D_8014DA18;
    }
    if (D_8014DA3C < 0) {
        a = (a >> -D_8014DA3C) & D_8014DA1C;
    } else {
        a = (a << D_8014DA3C) & D_8014DA1C;
    }
    D_80153C6C = index;
    D_80153C74 = r | g | b | a;
    D_80153CD4();
}

u32 Frontend_EncodePixelColor(u32 color, s32 format) {
    return encode(color, &D_800E2B20[format]);
}

u32 Frontend_DecodePixelColor(u32 value, s32 format) {
    return decode(value, &D_800E2B20[format]);
}

void Frontend_ReadSourceHalfwordPixel(void) {
    D_80153C68 = ((u16 *)D_80153C64)[D_80153C60];
}

void Frontend_ReadSourceWordPixel(void) {
    D_80153C68 = ((s32 *)D_80153C64)[D_80153C60];
}

void Frontend_ReadSourceThreeBytePixel(void) {
    D_80153C68 = (((u8 *)D_80153C64)[D_80153C60 * 3] << 16) | (((u8 *)D_80153C64)[D_80153C60 * 3 + 1] << 8) |
                 ((u8 *)D_80153C64)[D_80153C60 * 3 + 2];
}

void Frontend_WriteDestinationHalfwordPixel(void) {
    ((u16 *)D_80153C70)[D_80153C6C] = (u16)D_80153C74;
}

void Frontend_WriteDestinationWordPixel(void) {
    ((s32 *)D_80153C70)[D_80153C6C] = D_80153C74;
}

void Frontend_WriteDestinationThreeBytePixel(void) {
    ((u8 *)D_80153C70)[D_80153C6C * 3] = D_80153C75;
    ((u8 *)D_80153C70)[D_80153C6C * 3 + 1] = D_80153C76;
    ((u8 *)D_80153C70)[D_80153C6C * 3 + 2] = D_80153C77;
}

void Frontend_ReadSourceByteIndex(void) {
    s32 value = D_80153C7C[D_80153C78];

    D_80153C80 = value;
    D_80153C60 = value;
}

void Frontend_ReadSourceNibbleIndex(void) {
    s32 index = D_80153C78;
    s32 value;

    if (index & 1) {
        value = D_80153C7C[index >> 1] & 0xF;
    } else {
        value = D_80153C7C[index >> 1] >> 4;
    }
    D_80153C80 = value;
    D_80153C60 = value;
}

void Frontend_UseHalfwordPixelOffset(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void Frontend_UseThreeBytePixelOffset(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void Frontend_UseWordPixelOffset(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void Frontend_WriteDestinationByteIndex(void) {
    D_80153C88[D_80153C84] = (u8)D_80153C8C;
}

void Frontend_WriteDestinationNibbleIndex(void) {
    s32 index = D_80153C84;

    if (index & 1) {
        D_80153C88[index >> 1] = (D_80153C88[index >> 1] & 0xF0) | ((u8)D_80153C8C & 0xF);
    } else {
        D_80153C88[index >> 1] = (D_80153C88[index >> 1] & 0xF) | (((u8)D_80153C8C & 0xF) << 4);
    }
}
