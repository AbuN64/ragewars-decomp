#include "span_16E000/code_804143D8.h"
#include "types.h"

extern void *func_802A15E4_de(int);
extern void func_802B6CBC_de(void *, void *);
extern struct Command *D_80110634;

void func_80419430_de(void *source) {
    void *allocation = func_802A15E4_de(0x40);
    struct Command *command;

    func_802B6CBC_de(source, allocation);
    command = D_80110634++;
    command->words[0] = 0xDA380003;
    command->words[1] = (unsigned)allocation;
}

/* Rewrites an image's pixel rows in place when row fixing is enabled (D_800E32F0): the row length
   in 8-byte pixel groups comes from the image width and the bit depth reported by func_80413608_de
   (4, 8 or 16 bits), odd rows swap the two words of each group and even rows are copied to the
   write position through func_802A0724_de when source and destination differ. */



extern s32 D_800E32F0;

extern s32 func_80413608_de(void);
extern void func_802A0724_de(s32 *dst, s32 *src, s32 size);

void func_80419490_de(Image_func_80419490_de *image) {
    s32 *src;
    s32 *dst;
    s32 groups;
    s32 row;
    s32 i;
    s32 first;
    s32 second;

    if (D_800E32F0 == 0 || image->width == 0 || image->height == 0) {
        return;
    }
    switch (func_80413608_de()) {
        case 4:
            groups = image->width / 16;
            break;
        case 8:
            groups = image->width / 8;
            break;
        case 16:
            groups = image->width / 4;
            break;
        default:
            groups = 0;
            break;
    }
    src = image->pixels;
    dst = src;
    for (row = 0; row < image->height; row++) {
        if (row & 1) {
            for (i = 0; i < groups; i++) {
                first = *src++;
                second = *src++;
                *dst++ = second;
                *dst++ = first;
            }
        } else {
            if (src != dst) {
                func_802A0724_de(dst, src, groups * 8);
            }
            dst += groups * 2;
            src += groups * 2;
        }
    }
}

extern void func_804133E4_de(void);

void func_80419608_de(void) {
    func_804133E4_de();
}

extern void func_80413404_de(void);

void func_80419624_de(void) {
    func_80413404_de();
}
