#include "include_asm.h"

#if defined(VERSION_US)
#ifdef NON_MATCHING
typedef struct { char pad0[0x10]; u8 value; } Func_80419B90_us_Widget;
typedef struct {
    char pad0[0x44];
    s32 active;
    s32 count;
    char pad4C[3];
    u8 values[0x2C];
    s32 counters[5];
    s32 index;
    Func_80419B90_us_Widget *widget;
    s32 timer;
    char pad80[3];
    u8 rest;
    s32 state;
} Func_80419B90_us_Obj;
extern s32 func_802744D4_de(void);
extern void func_80419C84_de(void *obj, s32 arg);
extern void func_8025DF34_de(s32 id);
/* Per-frame step of a timed flasher: while state is 1 the timer at 0x7C counts down to 0 (capped at 0x32); at 0 a roll below 2 in 100 starts the flash (flag at 0x44, value of the current entry shown in the widget at 0x78 with sound 0xE75); while flashing each frame spends one count of the current entry and moves to the next entry (or ends through func_80419C84_de and rewinds the timer to 0x32) once it runs out. Returns zero. */
s32 func_80419B90_us(Func_80419B90_us_Obj *self) {
    s32 t;
    s32 next;
    if (self->state == 1) {
        if (self->active == 0) {
            t = self->timer - 1;
            if (t < 0) {
                t = 0;
            } else if (t >= 0x33) {
                t = 0x32;
            }
            self->timer = t;
            if (t <= 0 && func_802744D4_de() % 100 < 2) {
                self->active = 1;
                self->widget->value = self->pad4C[3 + self->index * 4];
                func_8025DF34_de(0xE75);
            }
        } else {
            self->widget->value = self->rest;
            self->counters[self->index]--;
            if (self->counters[self->index] > 0 && self->index + 1 < self->count) {
                return 0;
            }
            next = self->index + 1;
            self->index = next;
            if (next < self->count) {
                self->widget->value = self->pad4C[3 + next * 4];
                func_8025DF34_de(0xE75);
            } else {
                func_80419C84_de(self, -1);
                self->widget->value = self->rest;
                self->timer = 0x32;
            }
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_80400000", func_80419B90_us);
#endif
#endif
