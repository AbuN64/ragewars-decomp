#include "include_asm.h"

#if defined(VERSION_EU)
#include "COMMON/SHAREDCALLBACK5.H"

void func_80212D80_eu(AiTarget *pThis) {
    AiController *controller = pThis->player->controller;
    controller->handlerIndex = 0;
    func_80209988_de(controller);
    controller->unk2FC = 0;
}
#endif

#if defined(VERSION_EU)
extern void func_80211020_de(AiController *);
extern void Nav_SteerAlongRoute(AiController *);
extern void func_80208AAC_de(AiController *);

void func_80212DB4_eu(AiTarget *pThis) {
    AiController *controller = pThis->player->controller;
    s32 current;
    if (controller->target == 0) {
        func_80211020_de(controller);
    } else {
        current = controller->target->player->controller->current;
        if (current != controller->fallback) {
            controller->fallback = current;
        }
        Nav_SteerAlongRoute(controller);
        func_80211020_de(controller);
        func_80208AAC_de(controller);
    }
}
#endif
