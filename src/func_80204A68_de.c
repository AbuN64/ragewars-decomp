#include "common/unused.h"
#include "shared/world.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80203F04.h"
#include "types.h"

/* Destroys a breakable object after a hit: when its descriptor has a damage factor at 0x1D, scaled
   by D_800C6B74, and the object is forced at 0xE6, or the hit's team byte at 0xCA matches both ids at
   0x108 and 0x10A and either the hit at 0xCB bypasses an object without flag 0x400 or the scaled count
   reaches its limit (the count at 0x12C against 0x134 while flagged 0x400 below three hits at 0x10C,
   otherwise the hits against 0x104), it raises event 7 at its position through func_80267198_de and
   releases it through func_80285DB0_de. Written from its own assembly with the destroy decision as an
   if/else chain on a byte-sized damage factor. */







extern void func_80267198_de(void *, void *, s32, Triple, struct Shape_typemap_13);
extern void func_80285DB0_de(void *, void *, s32);






void func_80204A68_de(void *arg0, void *arg1) {
    struct Shape_typemap_13 local;
    s8 factor;
    f32 scale;
    s32 destroy;
    s8 team;

    factor = ((struct ObjectState1E *) ((BreakableHitContext *) arg0)->unk_18)->unk_1D;
    if (factor == -1) {
        return;
    }
    scale = factor * D_800C6B74;
    if (((BreakableHitContext *)(arg0))->unk_E6 == 1) {
        destroy = 1;
    } else {
        team = ((ObjectStateCC *)(arg1))->unk_CA;
        if (((BreakableHitContext *)(arg0))->unk_108 != team || ((BreakableHitContext *)(arg0))->unk_10A != team) {
            destroy = 0;
        } else if (((ObjectStateCC *)(arg1))->unk_CB != 0 && !(((BreakableHitContext *)(arg0))->unk_100 & 0x400)) {
            destroy = 1;
        } else if (((BreakableHitContext *)(arg0))->unk_10C < 3 && (((BreakableHitContext *)(arg0))->unk_100 & 0x400)) {
            destroy = ((BreakableHitContext *)(arg0))->unk_12C * scale <= ((BreakableHitContext *)(arg0))->unk_134;
        } else {
            destroy = ((BreakableHitContext *)(arg0))->unk_10C * scale <= ((BreakableHitContext *)(arg0))->unk_104;
        }
    }
    if (destroy) {
        local.field_0 = 0;
        func_80267198_de(arg0, arg0, 7, ((BreakableHitContext *)(arg0))->unk_8, local);
        func_80285DB0_de(&D_8011FE88, arg0, 0);
    }
}





void func_80204BB4_de(void *arg0, void *arg1) {
    ((Dest *)arg1)->table = &D_800C8380_de;
    ((Dest *)arg1)->enter = &D_00204C34;
}

extern s32 func_80285F58_de(void *, void *);
extern s32 func_80214178_de(void *, void *, s32);


void func_80204BD0_de(void *arg0, void *arg1) {
    s32 different = func_80285F58_de(&D_8011FE88, arg0) != 1;

    if (different == 0) {
        func_80214178_de(arg0, arg1, 0);
    } else {
        func_80214178_de(arg0, arg1, 1);
    }
}
