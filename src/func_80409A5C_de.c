#include "common/types_8a8189af7b05.h"
#include "span_16E000/code_80409A88.h"
#include "types.h"

/* Copies the saved controller settings block D_80153738 into the settings the object at offset 0x5D8
   of an owner holds: the four halfwords, the flag byte into offset 0x80 and the eight bytes after it
   into offset 0x84. */






extern struct Saved D_80153738;

void func_80409A5C_de(struct OwnerRecAt5D8V1 *owner) {
    struct ProfileRecAt84 *settings = owner->settings;
    s32 i;

    settings->flags = D_80153738.flag;
    settings->words[0] = D_80153738.values[0];
    settings->words[1] = D_80153738.values[1];
    settings->words[2] = D_80153738.values[2];
    settings->words[3] = D_80153738.values[3];
    for (i = 0; i < 8; i++) {
        settings->name[i] = D_80153738.bytes[i];
    }
}
