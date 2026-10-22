#include "include_asm.h"

#ifdef NON_MATCHING
#include "TYPES.H"
#include "COMMON/BOX_CONTACT.H"
#ifndef FIELD
#define FIELD(type, base, off) (*(type *)((char *)(base) + (off)))
#endif
typedef void (*ContactEffectHandler)(void *, void *, s32, CVector3, ContactEffectStyle);
typedef struct ContactEffectEntry { ContactEffectHandler handler; u32 flags; } ContactEffectEntry;
extern ContactEffectEntry D_800CC130[];
extern char D_8011FE88[];
extern void *D_80145060;
/* Delivers a contact effect to objects: when the scene is in mode 4 or the effect's flags allow it, the effect's
 * handler (D_800CC130 table, flags in the second word: 2 = broadcast, 8 = scene object array) is called either
 * on the target alone or on every other object -- the scene's object array (0x138, count 0x140, stride 0x2E8)
 * or its pointer list (0xC50, count 0xE50) and then the player list chained at 0x16E0 -- skipping the target. */
void func_80265E10_de(void *target, void *source, s32 effect, s32 unused, CVector3 position, ContactEffectStyle style) {
    ContactEffectEntry *entry = &D_800CC130[effect];
    s32 i;
    s32 count;
    void *other;
    if (FIELD(s32, D_8011FE88, 0) != 4 && (entry->flags & 0x10) == 0) {
        return;
    }
    if ((entry->flags & 2) == 0) {
        if (entry->handler != 0) {
            entry->handler(target, source, effect, position, style);
        }
        return;
    }
    if ((entry->flags & 8) != 0) {
        char *objects = FIELD(char *, D_8011FE88, 0x138);
        count = FIELD(s32, D_8011FE88, 0x140);
        for (i = 0; i < count; i++, objects += 0x2E8) {
            if (objects != target && entry->handler != 0) {
                entry->handler(objects, source, effect, position, style);
            }
        }
    } else {
        count = FIELD(s32, D_8011FE88, 0xE50);
        for (i = 0; i < count; i++) {
            other = FIELD(void *, D_8011FE88, 0xC50 + i * 4);
            if (other != target && entry->handler != 0) {
                entry->handler(other, source, effect, position, style);
            }
        }
    }
    for (other = D_80145060; other != 0; other = FIELD(void *, other, 0x16E0)) {
        if (other != target && (char *)other + 0x2E8 != target && entry->handler != 0) {
            entry->handler(other, source, effect, position, style);
        }
    }
}
#else
INCLUDE_ASM("span_1000", func_80265E10_de);
#endif
