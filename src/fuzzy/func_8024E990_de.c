#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "resident_event_handler.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "shared/world.h"
#include "span_C76B0/data.h"
#include "TYPES.H"
void *func_8028CF6C_de(void *arg0, s32 arg1);
void func_8024E990_de(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    ((s8 *) arg0)[0 / sizeof(s8)] = 3;
    ((u16 *) arg0)[4 / sizeof(u16)] = (u16) ((u16 *) arg1)[20 / sizeof(u16)];
    ((s32 *) arg0)[448 / sizeof(s32)] = (s32) ((s32 *) arg1)[0 / sizeof(s32)];
    ((f32 *) arg0)[8 / sizeof(f32)] = (f32) ((f32 *) arg1)[4 / sizeof(f32)];
    ((f32 *) arg0)[12 / sizeof(f32)] = (f32) ((f32 *) arg1)[8 / sizeof(f32)];
    ((f32 *) arg0)[16 / sizeof(f32)] = (f32) ((f32 *) arg1)[12 / sizeof(f32)];
    ((f32 *) arg0)[12 / sizeof(f32)] = (f32) (((f32 *) arg0)[12 / sizeof(f32)] + D_800C3D80_de);
    ((s32 *) arg0)[408 / sizeof(s32)] = 0;
    ((f32 *) arg0)[404 / sizeof(f32)] = (f32) D_800C3D88_de;
    ((f32 *) arg0)[372 / sizeof(f32)] = (f32) ((f32) ((s8 *) arg1)[30 / sizeof(s8)] * D_800C3D84_de);
    ((f32 *) arg0)[380 / sizeof(f32)] = (f32) (((f32 *) arg1)[4 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[384 / sizeof(f32)] = (f32) (((f32 *) arg1)[8 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[388 / sizeof(f32)] = (f32) (((f32 *) arg1)[12 / sizeof(f32)] - ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[392 / sizeof(f32)] = (f32) (((f32 *) arg1)[4 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((f32 *) arg0)[396 / sizeof(f32)] = (f32) (((f32 *) arg1)[8 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((s32 *) arg0)[80 / sizeof(s32)] = arg2;
    ((s32 *) arg0)[84 / sizeof(s32)] = -1;
    ((f32 *) arg0)[400 / sizeof(f32)] = (f32) (((f32 *) arg1)[12 / sizeof(f32)] + ((f32 *) arg1)[16 / sizeof(f32)]);
    ((s32 *) arg0)[88 / sizeof(s32)] = 0;
    ((s32 *) arg0)[92 / sizeof(s32)] = 0;
    if (((u16 *) arg1)[28 / sizeof(u16)] == 0xFFFF) {
        ((s8 **) arg0)[24 / sizeof(s8 *)] = &D_8011B388;
    } else {
        ((s8 **) arg0)[24 / sizeof(s8 *)] = func_8028CF6C_de(&D_8011FE88, (s32) ((u16 *) arg1)[28 / sizeof(u16)]);
    }
    if (((u16 *) arg1)[22 / sizeof(u16)] == 0xFFFF) {
        ((s32 *) arg0)[20 / sizeof(s32)] = 0;
    } else {
        ((s32 *) arg0)[20 / sizeof(s32)] = (s32) (arg3 + (((u16 *) arg1)[22 / sizeof(u16)] << 5));
    }
    ((s32 *) arg0)[416 / sizeof(s32)] = 0;
    ((s32 *) arg0)[420 / sizeof(s32)] = 0;
    ((s16 *) arg0)[412 / sizeof(s16)] = (s16) (((u16 *) arg1)[24 / sizeof(u16)] | 2);
    ((u16 *) arg0)[414 / sizeof(u16)] = (u16) ((u16 *) arg1)[26 / sizeof(u16)];
    func_8024D284_de(arg0);
    ((s32 *) arg0)[424 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[0 / sizeof(s32)];
    ((s32 *) arg0)[428 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[4 / sizeof(s32)];
    ((s32 *) arg0)[432 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[8 / sizeof(s32)];
    ((s32 *) arg0)[436 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[12 / sizeof(s32)];
    ((s32 *) arg0)[440 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[16 / sizeof(s32)];
    ((s32 *) arg0)[444 / sizeof(s32)] = (s32) ((s32 *) D_800CBC90)[20 / sizeof(s32)];
    ((s32 *) arg0)[452 / sizeof(s32)] = 0;
}
