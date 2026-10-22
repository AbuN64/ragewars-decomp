#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"

extern s32 D_801371D4;




s32 func_80279420_de(void *arg0, struct Player *arg1) {
    func_80279490_S1 *object = arg0;
    NavigationPlatform *platform;

    if (object->unkA == D_801371D4) {
        if (arg1 != 0) {
            platform = &D_8011BF00[object->unk4];
            if ((object->unk11 == 0xA) && (object->unk12 == 1)) {
                return func_80204308_de(platform, &platform->motion, arg1);
            }
        }
        return 1;
    }
    return 1;
}
