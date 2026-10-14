#include "span_16E000/code_80405DC0.h"
#include "types.h"

/* Frees the block a handle holds through func_80253908_de and func_80253838_de, allocates a new one through func_8025343C_de sized 256 bytes per requested unit or D_8011FECC plus 0x610 when none are requested, stores the block in the handle and its data pointer in the second argument, and zeroes the data with func_802A001C_de. */

extern char *D_8011FECC;
extern char D_800DCD60[];
extern void func_80253908_de(s32 a);
extern void func_80253838_de(s32, void *);
extern void **func_8025343C_de(s32, s32, s32, char *);
extern void func_802A001C_de(void *, s32, s32);

void func_804098CC_de(void ***handle, void **data, s32 units) {
    void **block;
    void *first;

    if (*handle != 0) {
        func_80253908_de(0);
        func_80253838_de(0, *handle);
    }
    if (units != 0) {
        units <<= 8;
    } else {
        units = (s32)(D_8011FECC + 0x610);
    }
    block = func_8025343C_de(0, units, 0x33, D_800DCD60);
    *handle = block;
    first = *block;
    *data = first;
    func_802A001C_de(first, 0, units);
}
