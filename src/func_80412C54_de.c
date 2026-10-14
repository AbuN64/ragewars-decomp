#include "span_16E000/code_80412270.h"
#include "types.h"

/* When the fourth argument is set, raises the byte at offset 0x4D of an entry by one while it is
   below one less than the count at 0x4B; then calls func_804121F0_de and func_8029973C_de. Returns
   zero. */
extern void func_804121F0_de();
extern void func_8029973C_de();

s32 func_80412C54_de(u8 *entry, void *second, void *third, s32 active) {
    u8 value = entry[0x4D];

    if (active && value < entry[0x4B] - 1) {
        entry[0x4D] = value + 1;
    }
    func_804121F0_de();
    func_8029973C_de();
    return 0;
}
