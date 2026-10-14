#include "span_16E000/code_80412270.h"
#include "types.h"

/* When the fourth argument is set, lowers the byte at offset 0x4D of an entry by one while it is
   above the minimum at 0x51; then calls func_804121F0_de and func_8029973C_de. Returns zero. */
extern void func_804121F0_de();
extern void func_8029973C_de();

s32 func_80412C0C_de(u8 *entry, void *second, void *third, s32 active) {
    s32 value = entry[0x4D];

    if (active && entry[0x51] < value) {
        entry[0x4D] = value - 1;
    }
    func_804121F0_de();
    func_8029973C_de();
    return 0;
}
