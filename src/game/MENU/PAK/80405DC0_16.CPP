#include "COMMON/MENURECAT24.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
#include "MENU/80405DC0.H"
#include "COMMON/SHAREDPLAYER.H"
#include "stddef.h"
#include "TYPES.H"
#include "MENU/PAK/80405DC0_16.H"
#include "RESMGR/802A0888.H"
extern void Scene_ReleaseResource(void *arg0, void *arg1);

/* Returns the address of block n, n times 256; block zero is the area 0x610 bytes into the
   buffer D_8011FECC points to. */
extern char *D_8011FECC;

extern char g_pakSingleSaveBlockName[];

extern void func_80253908_de(s32 a);


extern void **Scene_AllocateResource(s32, s32, s32, char *);


/* Releases the two active resources and clears their associated state. */
void Scene_ReleaseResource(void *, void *);

 /* extern */
void func_80253908_de(s32);

 /* extern */
extern void *D_800DE860_de;

extern struct Shape_typemap_165 *D_800DE864_de;


extern s32 D_800E28BC;

/* Saves the settings the object at offset 0x5D8 of an owner holds into the block D_80153738: the
   flag byte, the four halfwords, three cleared bytes after the flag and the eight bytes at 0x84. */






extern struct Saved D_80153738;

char *func_80409884_de(s32 block) {
    if (block == 0) {
        return D_8011FECC + 0x610;
    }
    return (char *) (block << 8);
}

void func_804098A4_de(s32 offset, s32 value) {
    ((struct IntegerState610 *) (D_8011FECC + offset))->unk_60C = value;
}

/* Returns the last word of a self-sized block: the first word holds the block's byte length and
   the result is the word just before that many bytes from the start. */
s32 func_804098B8_de(s32 *block) {
    return ((struct Shape_typemap_3 *) (block[0] + (s32) block))[-1].field_0;
}

void func_804098CC_de(void ***handle, void **data, s32 units) {
    void **block;
    void *first;

    if (*handle != 0) {
        func_80253908_de(0);
        Scene_ReleaseResource(0, *handle);
    }
    if (units != 0) {
        units <<= 8;
    } else {
        units = (s32)(D_8011FECC + 0x610);
    }
    block = Scene_AllocateResource(0, units, 0x33, g_pakSingleSaveBlockName);
    *handle = block;
    first = *block;
    *data = first;
    Resmgr_FillMemory(first, 0, units);
}

void func_80409964_de(void) {
    if ((D_800DE860_de != 0) || (D_800DE864_de != 0)) {
        func_80253908_de(0);
    }
    if (D_800DE860_de != 0) {
        Scene_ReleaseResource(0, D_800DE860_de);
    }
    if (D_800DE864_de != 0) {
        Scene_ReleaseResource(0, D_800DE864_de);
    }
    D_800DE860_de = 0;
    D_800DE864_de = 0;
    D_800DE868 = 0;
    D_800E28BC = 0;
}

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
