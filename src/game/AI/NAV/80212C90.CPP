#include "include_asm.h"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/SELF.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "AI/SOURCE.H"
#include "TYPES.H"
#include "AI/NAV/80212C90.H"

void func_80212C90_de(AiTarget *aiTarget) {
    AiController *controller;
    controller = aiTarget->player->controller;
    ((CloseAttackBrain *)controller)->state = 0;
    Nav_ResetBehaviorState(controller);
    controller->unk2FC = 0;
}

extern s32 Nav_SetBehaviourState(void *, s32);
extern void func_80211020_de(void *);
extern f32 Nav_DistanceToNode(s32 *, s32);
extern void Nav_SteerAlongRoute(void *);
extern void Nav_UpdateTargetSteering(s32 *);
extern char D_80145040;






void func_80212CC4_de(AiTarget *aiTarget) {
    AiController *controller;
    void *v0;

    controller = aiTarget->player->controller;
    v0 = Weapons_FindPlayerWithMarker(&D_80145040);
    if (v0 == 0 || v0 != (void *)controller->player) {
        Nav_SetBehaviourState(controller, 2);
        return;
    }
    controller = aiTarget->player->controller;
    func_80211020_de(controller);
    Nav_DistanceToNode(controller, controller->mode);
    Nav_SteerAlongRoute(controller);
    Nav_UpdateTargetSteering(controller);
}

#if defined(VERSION_EU_X)
unsigned int func_80212D78_eu_x_padding_13978[2] = {
    0xAFAA0030, 0x0C0939C6,
};
#endif

#if defined(VERSION_EU)
unsigned int func_80212D78_eu_padding_13978[2] = {
    0x00448021, 0x12000017,
};
#endif

#if defined(VERSION_DE)
unsigned int func_80212D58_de_padding_13958[2] = {
    0x26520001, 0x2610FFFF,
};
#endif
