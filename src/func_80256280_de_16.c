#include "span_1000/code_802BB15C.h"
#include "shared/gameplay_round_rules.h"
#include "common/unused.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_80256220.h"
#include "span_1000/code_8025A3EC.h"
#include "span_1000/code_8025D948.h"
#include "types.h"

extern u8 D_801462E1;
extern f32 D_800C3EE0_de;

#include "shared/menu_match_globals.h"

extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);

extern void func_80259440_de(void *arg0);
extern void func_8025CC90_de(void *arg0);

extern void func_8025D450_de(void *arg0);
extern s32 func_802934F8_de(void);
extern void *func_802395A4_de(MenuMatchGlobals *arg0, Vec3 *arg1);
extern s32 func_80257DD4_de(void *, s32, Vec3, s32, s32);










s32 func_8025842C_de(void *arg0) {
    char *object = arg0;
    u8 *bytes = &D_801462E1;
    char *queue;
    u32 mask;
    s32 count;

    ((struct ContextRecAt2BC0 *)(object))->red = (f32)bytes[0] * D_800C3EE0_de;
    ((struct ContextRecAt2BC0 *)(object))->green = (f32)bytes[-1] * D_800C3EE0_de;
    ((struct ContextRecAt2BC0 *)(object))->blue = (f32)bytes[1] * D_800C3EE0_de;
    queue = object + 0x110;
    ((struct ContextRecAt2BC0 *)(object))->field2BB0 = bytes[-2];
    mask = func_802BCF30_de();
    count = ((MenuRules *)(queue))->locked + 1;
    ((MenuRules *)(queue))->locked = count;
    if (count != 1) {
        __osRestoreInt(mask);
        func_802BB2A0_de(queue, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    func_8025BD00_de(&((struct ContextRecAt2BC0 *)(object))->menu[0]);
    {
        char *queue2 = object + 0x110;
        u32 mask2 = func_802BCF30_de();
        s32 count2 = ((MenuRules *)(queue2))->locked - 1;

        ((MenuRules *)(queue2))->locked = count2;
        if (count2 != 0) {
            __osRestoreInt(mask2);
            func_802BB420_de(queue2, 0, 1);
        } else {
            __osRestoreInt(mask2);
        }
    }

    func_80259440_de((char *)object + 0x138);
    func_8025CC90_de((char *)object + 0x2BC0);
    queue = object + 0x1D64;
    func_8025D928_de(queue);
    func_8025D450_de(queue);

    if (D_800CB720 != 0 &&
        ((struct ContextRecAt2BC0 *)(object))->field2BB4 != 0 &&
        func_802934F8_de() != 0 &&
        ((struct ContextRecAt2BC0 *)(object))->track > 0) {
        Vec3 zero;
        void *result;
        Vec3 *vec;

        zero.z = 0.0f;
        zero.y = 0.0f;
        zero.x = 0.0f;
        result = func_802395A4_de(&D_80145088, &zero);
        vec = &((struct SharedRecAt564V1 *)(result))->position;
        if ((((struct ContextRecAt2BC0 *)(object))->frame & 3) == 0) {
            func_80257DD4_de(object, ((struct ContextRecAt2BC0 *)(object))->track, *vec, 0, -1);
        }
    }
    return ++((struct ContextRecAt2BC0 *)(object))->frame;
}

extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);
extern s32 func_8025C17C_de(void *arg0, s32 arg1);
extern s32 func_80259AB8_de(void *arg0, s32 arg1);






s32 func_802585F4_de(struct ContextRecAt2BC0 *arg0, s32 arg1) {
    {
        MenuRules *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &arg0->lock;
        temp_a0 = func_802BCF30_de();
        temp_v1 = temp_s0->locked + 1;
        temp_s0->locked = temp_v1;
        if (temp_v1 != 1) {
            __osRestoreInt(temp_a0);
            func_802BB2A0_de(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_a0);
        }
    }
    if (func_8025C17C_de(&arg0->menu[0], arg1) != 0) {
        MenuRules *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &arg0->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = temp_s0->locked - 1;
        temp_s0->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
        return 1;
    }
    if (func_80259AB8_de(&arg0->view[0], arg1) != 0) {
        MenuRules *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &arg0->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = temp_s0->locked - 1;
        temp_s0->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
        return 1;
    }
    {
        MenuRules *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &arg0->lock;
        temp_v0 = func_802BCF30_de();
        temp_v1 = temp_s0->locked - 1;
        temp_s0->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            func_802BB420_de(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
    }
    return 0;
}

extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);






void func_80258740_de(s32 *arg0) {
    MenuRules *temp_s0;
    s32 temp_v1;
    u32 temp_a0;

    temp_s0 = &((struct ContextRecAt2BC0 *)(arg0))->lock;
    temp_a0 = func_802BCF30_de();
    temp_v1 = temp_s0->locked + 1;
    temp_s0->locked = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(temp_a0);
        func_802BB2A0_de(temp_s0, 0, 1);
        return;
    }
    __osRestoreInt(temp_a0);
}

extern u32 func_802BCF30_de(void);
extern void __osRestoreInt(u32);
extern void func_802BB420_de(void *arg0, s32 arg1, s32 arg2);






void func_802587A4_de(s32 *arg0) {
    MenuRules *temp_s0;
    s32 temp_v1;
    u32 temp_v0;

    temp_s0 = &((struct ContextRecAt2BC0 *)(arg0))->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = temp_s0->locked - 1;
    temp_s0->locked = temp_v1;
    if (temp_v1 != 0) {
        __osRestoreInt(temp_v0);
        func_802BB420_de(temp_s0, 0, 1);
        return;
    }
    __osRestoreInt(temp_v0);
}
