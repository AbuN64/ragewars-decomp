#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"

extern s32 D_801371D4;




s32 Link_CheckTriggerMessage(void *trigger, struct Player *player) {
    func_80279490_S1 *object = trigger;
    NavigationPlatform *platform;

    if (object->unkA == D_801371D4) {
        if (player != 0) {
            platform = &D_8011BF00[object->unk4];
            if ((object->unk11 == 0xA) && (object->unk12 == 1)) {
                return Action_ShowTriggerMessage(platform, &platform->motion, player);
            }
        }
        return 1;
    }
    return 1;
}
