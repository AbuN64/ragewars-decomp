#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80405DC0.h"
#include "types.h"

/* Saves the settings the object at offset 0x5D8 of an owner holds into the block D_80153738: the
   flag byte, the four halfwords, three cleared bytes after the flag and the eight bytes at 0x84. */






extern struct Saved D_80153738;

void func_804099EC_de(struct OwnerRecAt5D8V1 *owner) {
    struct ProfileRecAt84 *settings = owner->settings;
    s32 i;

    D_80153738.flag = settings->flags;
    D_80153738.values[0] = settings->words[0];
    D_80153738.values[1] = settings->words[1];
    D_80153738.values[2] = settings->words[2];
    D_80153738.values[3] = settings->words[3];
    D_80153738.pad[0] = 0;
    D_80153738.pad[1] = 0;
    D_80153738.pad[2] = 0;
    for (i = 0; i < 8; i++) {
        D_80153738.bytes[i] = settings->name[i];
    }
}
