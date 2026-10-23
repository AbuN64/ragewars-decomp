#include "COMMON/GAMEPLAY_TRANSITION.H"
#include "COMMON/WORLD.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/OBJB.H"
#include "TYPES.H"
#include "COMMON/OBJECTSTATE18.H"
#include "ENGINE/SCENE_6.H"

/* Releases the two handles at offsets 0x11BC and 0x11C0 of an object: each goes to func_8025CA24_de
   with what func_8025CC6C_de returns, and each is then cleared. */


extern void *func_8025CC6C_de();
extern void func_8025CA24_de(void *, s32);

void func_8044A07C_de(struct Object_func_8044A07C_de *object) {
    func_8025CA24_de(func_8025CC6C_de(), object->first);
    object->first = 0;
    func_8025CA24_de(func_8025CC6C_de(), object->second);
    object->second = 0;
}

/* Stores the second argument at 0x5E0 of the actor, calls func_80226708_de and Render_ResetPlayerWeapons on it, then starts sound D_8011FE88 for it through func_8028B274_de with 0x66, D_800CE47C or its type's entry of D_800CE430 chosen by the options D_801462E5 and D_801468F4.
   Adapted from func_8022BB80_de with a leading field store and two calls added and the D_801462C8 offsets changed to the symbols D_801462E5 and D_801468F4. */


extern void func_80226708_de(void *);
extern void Render_ResetPlayerWeapons(void *);
extern u8 D_801462E5;
extern s32 D_801468F4;











void func_8044A0C4_de(Player *arg0, s32 arg1) {
    s32 var_a2;

    arg0->state = arg1;
    func_80226708_de(arg0);
    Render_ResetPlayerWeapons(arg0);
    if (D_801462E5 == 0) {
        var_a2 = 0x66;
    } else if (D_801468F4 != 0 && ((Shared_ControlView *)arg0->profile)->transientFlag != 0) {
        var_a2 = D_800CE47C;
    } else {
        var_a2 = D_800CE430[((Shared__struct_D_800D34C0_0x18 *)arg0->definition)->unkC];
        arg0->playerId = ((Shared_ControlView *)arg0->profile)->playerId;
    }
    ((void (*)(void *, void *, s32, s32))func_8028B274_de)(&D_8011FE88, arg0, var_a2, arg0->animation);
}
