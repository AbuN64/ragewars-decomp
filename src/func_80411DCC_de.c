#include "span_16E000/code_80411B68.h"
#include "types.h"

/* Twelve bytes of stride and a load at offset 8. The debugger showed the global holding
   0x80697F80 and the results being 0, 0x8067E570, 0x8067F870 and 0x80697E00, so the third word is
   a pointer that may be absent. The largest index seen was 0x1D, which is inside the bound of 36
   that func_80411DF0_de checks against D_80153C40, so this is an accessor over the same table. */
extern struct EntryRecAt8V2 {
    s32 unk_0;
    s32 unk_4;
    void *unk_8;
} *D_8014D9B4;

void *func_80411DCC_de(s32 index) {
    return D_8014D9B4[index].unk_8;
}
