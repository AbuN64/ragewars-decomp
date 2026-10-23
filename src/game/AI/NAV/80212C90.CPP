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
    func_80209988_de(controller);
    controller->unk2FC = 0;
}

extern s32 func_80209874_de(void *, s32);
extern void func_80211020_de(void *);
extern void func_80209948_de(s32 *, s32);
extern void Nav_SteerAlongRoute(void *);
extern void func_80208EB0_de(s32 *);
extern char D_80145040;






void func_80212CC4_de(AiTarget *aiTarget) {
    AiController *controller;
    void *v0;

    controller = aiTarget->player->controller;
    v0 = func_8022A83C_de(&D_80145040);
    if (v0 == 0 || v0 != (void *)controller->player) {
        func_80209874_de(controller, 2);
        return;
    }
    controller = aiTarget->player->controller;
    func_80211020_de(controller);
    func_80209948_de(controller, controller->mode);
    Nav_SteerAlongRoute(controller);
    func_80208EB0_de(controller);
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
