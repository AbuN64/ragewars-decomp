#include "COMMON/MODEL_RENDER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/INTEGERSTATE244.H"
#include "COMMON/VECTOR4F.H"
#include "WEAPONS/PLAYERRECAT1450V1.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
#include "COMMON/OBJECTLINKS14C.H"

extern u8 D_801462E5;

extern s32 func_80442A28_de(void *arg0);
extern s32 func_8022AB20_de(void *arg0, s16 arg1);

void func_8023293C_de(void *arg0, Dest *arg1, Lookup *arg2) {
    void *actor;
    void *resource;
    s32 result;
    s32 one;
    s16 state;

    actor = ((LevelActor *)arg0)->controller;
    resource = ((Actor_func_8022D290_de *)actor)->unk_0x05DC;
    result = -1;
    if (resource == 0) {
        return;
    }
    if (D_801462E5 != 0) {
        if (func_80442A28_de((char *)resource + 0x554) != 0) {
            return;
        }
    }
    state = ((Actor_func_8022D290_de *)actor)->unk_0x062E;
    one = 1;
    if ((state == one) && (arg1->field144 == 0)) {
        return;
    }
    if ((state >= 0x12) && (func_8022AB20_de(actor, state) <= 0)) {
        return;
    }
    state = ((Actor_func_8022D290_de *)actor)->unk_0x062E;
    if ((state == 0xE) || (state == one) || (state == 0)) {
        result = ((Actor_func_8022D290_de *)actor)->unk_0x11F8;
    }
    func_8026DA4C_de(arg2->value,
                  ((LevelActor *)arg0)->fieldB4, 1,
                  (char *)arg0 + (D_800D297C * 0x18 + 0x140), 0, result);
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern void func_80232878_eu(void *arg0, void *arg1);
#else
#endif







void func_80232A48_de(void *arg0, void *arg1) {
    f32 k = D_800C3018_de;

    ((Dest *)arg1)->table = &D_800CA058;
    ((Dest *)arg1)->enter = &D_0022FC20;
    ((Dest *)arg1)->draw = &D_0023293C;
    ((Dest *)arg1)->field124 = 0;
    ((Dest *)arg1)->charge = 0;
    ((Dest *)arg1)->field130 = 0;
    ((Dest *)arg1)->field138 = 0;
    ((Dest *)arg1)->field13C = 1;
    ((Dest *)arg1)->field12C = k;
    ((LevelActor *)arg0)->team = 0;
    ((Dest *)arg1)->field148 = 0;
    ((Dest *)arg1)->field144 = 1;
    ((Dest *)arg1)->field14C = 0;
    ((Dest *)arg1)->field150 = 0;
    
#if defined(VERSION_EU) || defined(VERSION_EU_X)
func_80232878_eu
#else
func_8022FDAC_de
#endif
(arg0, arg1);
}

extern s32 func_8022EB0C_de(void *arg0, s32 arg1);




s32 func_80232ABC_de(void *arg0) {
    s32 var_s1;
    s32 var_s0;

    var_s1 = ((Shared_ActorView *)arg0)->selectedAction;
    var_s0 = func_802744D4_de() % 22;
    if (var_s0 >= 0) {
        do {
            var_s1 += 1;
            if (var_s1 >= 0x10) {
                var_s1 = 0;
            }
            if (func_8022EB0C_de(arg0, var_s1) != 0) {
                var_s0 -= 1;
            }
        } while (var_s0 >= 0);
    }
    return var_s1;
}
