#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "sdk/SCHED/8028DF6C_2.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a table through the given
   nibble table. */





extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E390_de(void *unused0, void *table, u8 *remap) {
    s32 i;
    void *data;
    u8 tag;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    i = 0;
    end = -1;
    for (; i < 256; i++) {
        end = -1;
        func_802AA8EC_de(table, i, &data, &tag);
        rows = data == 0;
        if (rows) {
            continue;
        }
        set = data;
        rows = set->rows;
        rows--;
        image = (struct IntPair *)(set + 1);
        while (1) {
            if (rows == end) {
                break;
            }
            columns = set->columns;
            columns--;
            for (; columns != end; columns--) {
                width = image->field_0;
                height = image->field_4;
                count = (u32)(width * height) >> 1;
                pixel = (u8 *)(image + 1);
                while (count--) {
                    hi = *pixel >> 4;
                    lo = *pixel & 0xF;
                    hi = remap[hi];
                    lo = remap[lo];
                    *pixel = (hi << 4) | lo;
                    pixel++;
                }
                image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                image++;
            }
            rows--;
        }
    }
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2910, once the resource has been loaded by func_80285180_de. */





extern u8 D_800D2910[];
extern s32 Render_UnpackResource(void *resource, s32 flags);
extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E4A4_de(void *unused0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = Render_UnpackResource(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2910;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            func_802AA8EC_de(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct IntPair *)(set + 1);
            while (1) {
                if (rows == end) {
                    break;
                }
                columns = set->columns;
                columns--;
                for (; columns != end; columns--) {
                    width = image->field_0;
                    height = image->field_4;
                    count = (u32)(width * height) >> 1;
                    pixel = (u8 *)(image + 1);
                    while (count--) {
                        hi = *pixel >> 4;
                        lo = *pixel & 0xF;
                        hi = remap[hi];
                        lo = remap[lo];
                        *pixel = (hi << 4) | lo;
                        pixel++;
                    }
                    image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}

/* Remaps every 4-bit pixel of every image in each of the 256 entries of a resource through the nibble table D_800D2920, once the resource has been loaded by func_80285180_de. Adapted from func_8028E4A4_de with the nibble table changed to D_800D2920. */





extern u8 D_800D2920[];
extern s32 Render_UnpackResource(void *resource, s32 flags);
extern void func_802AA8EC_de(void *table, s32 index, void **out, u8 *tag);

void func_8028E5D0_de(void *unused0, void **resource) {
    s32 i;
    void *data;
    u8 tag;
    void *table;
    u8 *remap;
    ImageSet *set;
    struct IntPair *image;
    s32 rows;
    s32 columns;
    u32 count;
    u8 *pixel;
    s32 hi;
    s32 lo;
    s32 end;
    s32 width;
    s32 height;

    end = Render_UnpackResource(resource, 0) == 0;
    if (end) {
        return;
    }
    table = *resource;
    remap = D_800D2920;
    do {
        for (i = 0; i < 256; i++) {
            end = -1;
            func_802AA8EC_de(table, i, &data, &tag);
            if (data == 0) {
                continue;
            }
            set = data;
            rows = set->rows;
            rows--;
            image = (struct IntPair *)(set + 1);
            while (1) {
                if (rows == end) {
                    break;
                }
                columns = set->columns;
                columns--;
                for (; columns != end; columns--) {
                    width = image->field_0;
                    height = image->field_4;
                    count = (u32)(width * height) >> 1;
                    pixel = (u8 *)(image + 1);
                    while (count--) {
                        hi = *pixel >> 4;
                        lo = *pixel & 0xF;
                        hi = remap[hi];
                        lo = remap[lo];
                        *pixel = (hi << 4) | lo;
                        pixel++;
                    }
                    image = (struct IntPair *)((u8 *)image + ((u32)(width * height) >> 1));
                    image++;
                }
                rows--;
            }
        }
    } while (0);
}
