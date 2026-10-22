#include "COMMON/WORLD.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "TYPES.H"

extern void func_8044A370_de(void *arg0, s32 arg1);
extern void func_804499B0_de(void *arg0, void *arg1, void *arg2);
extern s32 func_804030E0_de(s32);
extern void func_8044D528_de(void *arg0, s32 arg1, s32 arg2);
extern void func_8044D054_de(void *arg0);
extern void func_8044D0F0_de(void *arg0);





void func_80293998_de(s32 arg0, s32 arg1) {
    ObjRecAt255C8 *object = (void *)arg0;
    func_8044A370_de(&object->unk255C8, 1);
    func_804499B0_de(&object->unk25580, (void *)1, 0);
    func_8044D528_de(&D_8011FE88, ~func_804030E0_de(arg1), 0);
    func_8044D054_de(&D_8011FE88);
    func_8044D0F0_de(&D_8011FE88);
}
