#include "span_1000/code_8028DF6C.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"

/* Switches a view to a new current and next scene: stamps the time of a pending next scene, starts the current scene (resetting its timer for mode 2, and stamping its start and, unless flagged 0x10, its first-start time for flag 0x20), clears its flags 0x30, runs its start and update hooks and records it, then when the next scene differs starts its music at its time and records it. */





extern u64 D_8011B1D0;
extern f32 D_8011B1D8;
extern u64 D_8011B1E0;
extern s64 D_8011B1E8;
extern s64 D_8011B1F0;

extern s32 D_800CD714;
extern s64 func_802BADC0_de(void);

extern void func_802B9E78_de(s32 *mode);
extern void func_802B9F7C_de(s32 *mode);
extern void func_802B7B90_de(s32 music, s64 time);

void func_8028FA60_de(View_func_8028FA60_de *view, Scene_func_8028FA60_de *current, Scene_func_8028FA60_de *next) {
    s64 now;

    if (next != 0 && (next->options & 0x20) && !(next->flags & 0x10)) {
        D_8011B1E8 = func_802BADC0_de();
    }
    if (current != 0) {
        if (current->mode == 2) {
            func_802BD2F0_de();
            D_8011B1D0 = func_802BADC0_de();
        } else if (current->options & 0x20) {
            now = func_802BADC0_de();
            D_8011B1E0 = now;
            if (!(current->flags & 0x10)) {
                D_8011B1F0 = now;
                D_8011B1D8 = 0;
            }
        }
        current->flags &= ~0x30;
        func_802B9E78_de(&current->mode);
        func_802B9F7C_de(&current->mode);
        view->current = current;
        if (current == next) {
            view->next = next;
        }
    }
    if (next != 0 && next != current) {
        func_802B7B90_de(next->music, *next->time);
        D_800CD710 = 1;
        D_800CD714 = 0;
        view->next = next;
    }
}
