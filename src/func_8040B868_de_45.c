#include "span_16E000/code_8040B45C.h"
#include "common/types_1dc8418c21db.h"
#include "span_16E000/code_80413728.h"
#include "types.h"

/* Reads the pixel at (x, y) of the current image D_80153D54 as a 0xAARRGGBB colour: seeks to
   x + y * width through the format's seek hook D_80153CD8, fetches through D_80153CD0 and converts
   the value with the format's channel masks and shifts like func_804139E0_de. */





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
   converts the colour to the format's packed value like func_80413CE0_de, then stores it and the
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



extern PixelFormat D_800E2B20[];

static inline u32 encode(u32 color, PixelFormat *format) {
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

static inline u32 decode(u32 value, PixelFormat *format) {
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
extern u8 *D_80153C7C;

/* Stores the byte D_80153C8F at the offset D_80153C84 within the buffer D_80153C88 points to. */
extern u8 *D_80153C88;

extern u8 D_80153C8F;

u32 func_804137F8_de(s32 x, s32 y) {
    extern func_8022BECC_S2 *D_80153D54;
    extern void (*D_80153CD8)(s32 offset);
    extern u32 D_80153C68;
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

s32 func_80413994_de(s32 x, s32 y) {
    extern struct func_8022BECC_S2 *D_80153D54;
    extern void (*D_80153CD8)(void);
    D_80153C78 = x + y * D_80153D54->unk8;
    D_80153CD8();
    return D_80153C80;
}

u32 func_804139E0_de(s32 index) {
    extern u32 D_80153C68;
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

void func_80413B54_de(s32 x, s32 y, u32 color) {
    extern func_8022BECC_S2 *D_80153D58;
    extern u32 D_80153C74;
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

void func_80413C94_de(s32 x, s32 y, s32 value) {
    extern struct func_8022BECC_S2 *D_80153D58;
    D_80153C8C = value;
    D_80153C84 = x + y * D_80153D58->unk8;
    D_80153CDC();
}

void func_80413CE0_de(s32 index, u32 color) {
    extern u32 D_80153C74;
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

u32 func_80413E08_de(u32 color, s32 format) {
    return encode(color, &D_800E2B20[format]);
}

u32 func_80413EE0_de(u32 value, s32 format) {
    return decode(value, &D_800E2B20[format]);
}

void func_80413FCC_de(void) {
    extern s32 D_80153C68;
    extern u16 *D_80153C64;
    D_80153C68 = D_80153C64[D_80153C60];
}

void func_80413FF8_de(void) {
    extern s32 D_80153C68;
    extern s32 *D_80153C64;
    D_80153C68 = D_80153C64[D_80153C60];
}

void func_80414024_de(void) {
    extern s32 D_80153C68;
    extern u8 *D_80153C64;
    D_80153C68 = (D_80153C64[D_80153C60 * 3] << 16) | (D_80153C64[D_80153C60 * 3 + 1] << 8) |
                 D_80153C64[D_80153C60 * 3 + 2];
}

void func_8041406C_de(void) {
    extern u16 D_80153C76;
    extern u16 *D_80153C70;
    D_80153C70[D_80153C6C] = D_80153C76;
}

void func_80414094_de(void) {
    extern s32 D_80153C74;
    extern s32 *D_80153C70;
    D_80153C70[D_80153C6C] = D_80153C74;
}

void func_804140BC_de(void) {
    extern u8 D_80153C76;
    extern u8 *D_80153C70;
    D_80153C70[D_80153C6C * 3] = D_80153C75;
    D_80153C70[D_80153C6C * 3 + 1] = D_80153C76;
    D_80153C70[D_80153C6C * 3 + 2] = D_80153C77;
}

void func_80414138_de(void) {
    s32 value = D_80153C7C[D_80153C78];

    D_80153C80 = value;
    D_80153C60 = value;
}

void func_80414168_de(void) {
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

void func_804141C0_de(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void func_804141E0_de(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void func_80414200_de(void) {
    s32 value = D_80153C78;

    D_80153C80 = value;
    D_80153C60 = value;
}

void func_80414220_de(void) {
    D_80153C88[D_80153C84] = D_80153C8F;
}

void func_80414244_de(void) {
    s32 index = D_80153C84;

    if (index & 1) {
        D_80153C88[index >> 1] = (D_80153C88[index >> 1] & 0xF0) | (D_80153C8F & 0xF);
    } else {
        D_80153C88[index >> 1] = (D_80153C88[index >> 1] & 0xF) | ((D_80153C8F & 0xF) << 4);
    }
}
