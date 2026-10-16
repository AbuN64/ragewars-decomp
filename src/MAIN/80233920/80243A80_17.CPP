#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80245980.h"
#include "TYPES.H"
























extern s32 func_8028FE28_de(s32 *arg0, s32 arg1, s32 arg2);
extern void * *func_8025193C_de(s32, s32, s32, s32, s32, s32, void *, void *, s32);
extern void func_80253754_de(s32, void *);
extern s32 func_8028FE3C_de(s32, s32, s32, s32 *);
extern void *func_8028FDB4_de(void *, s32);
extern void func_8026EE20_de(void *, s32, void *);
extern void func_80262480_de(void *);
extern s32 func_80246A08_de(void *, s32, s32);
extern char D_800C389C_de;
extern char D_800C38B0_de;
extern char D_800C38C4_de;





void func_80246BE8_de(void *arg0, s32 *arg1, s32 arg2, s32 arg3) {
    s32 *sp28;
    void **resource1;
    void **resource2;
    s32 *entry;
    void *temp;
    void *node;
    s32 key;
    s32 found;

    ((LevelActor *)arg0)->resourceHandle = -1;
    ((LevelActor *)arg0)->resourceState = 0;
    ((LevelActor *)arg0)->resourceWindow = 0;
    ((LevelActor *)arg0)->flags &= 0xFFFBFFFF;
    key = func_8028FE28_de(arg1, arg2, (u16)((LevelActor *)arg0)->modelIndex);
    resource1 = func_8025193C_de(0, key, key, 0x18, 0, 0, 0, &D_800C389C_de, 1);
    if (resource1 != 0) {
        entry = *resource1;
        ((LevelActor *)arg0)->animationKey = func_8028FE28_de(entry, key, 1);
        found = func_802540F4_de(0, &sp28, ((LevelActor *)arg0)->animationKey, &D_800C38B0_de, 1);
        if (found != 0) {
            ((LevelActor *)arg0)->stateE7 = (u8)*sp28;
            ((LevelActor *)arg0)->resourceAlignment = ((*sp28 * 4) + 0xF) & ~7;
            func_80253754_de(0, (void *)found);
        }
        ((LevelActor *)arg0)->resource = func_8028FE3C_de((s32)entry, key, 0, &((LevelActor *)arg0)->resourceFlags);
        ((LevelActor *)arg0)->resourceKey = func_8028FE28_de(entry, key, 2);
        resource2 = func_8025193C_de(0, ((LevelActor *)arg0)->resource,
                                 ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resourceFlags,
                                 0, 0, 0, &D_800C38C4_de, 1);
        if (resource2 != 0) {
            node = *resource2;
            temp = func_8028FDB4_de(node, 0);
            ((LevelActor *)arg0)->controllerUpdate(arg0, (char *)arg0 + 0x170);
            func_8026EE20_de(&((LevelActor *)arg0)->transform, (s32)temp, (char *)arg0 + 0xE8);
            func_80262480_de((char *)arg0 + 0x104);
            func_80262480_de((char *)arg0 + 0x118);
            ((LevelActor *)arg0)->stateE6 = (u8)((ResourceManagerState *)func_8028FDB4_de(node, 1))->count;
            ((LevelActor *)arg0)->flags |= 0x40000;
            if (arg3 > 0) {
                arg3 = func_80246A08_de(arg0, arg3, -1);
            } else {
                arg3 = -arg3;
            }
            if (arg3 == -1) {
                arg3 = 0;
            }
            ((LevelActor *)arg0)->nextAnimation = arg3;
            ((LevelActor *)arg0)->animationPending = 0;
            if (((LevelActor *)arg0)->animation != arg3) {
                ((LevelActor *)arg0)->animationChanged = 1;
            }
            ((LevelActor *)arg0)->animationState = -1;
            ((LevelActor *)arg0)->lean = arg3;
            func_80253754_de(0, resource2);
        }
        func_80253754_de(0, resource1);
    }
}
