#include "include_asm.h"

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80211120_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80211470_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80211A7C_de);
#endif

#if defined(VERSION_DE)
INCLUDE_ASM("span_1000", func_80212088_de);
#endif

#if defined(VERSION_DE)
#include "COMMON/SELF.H"
extern void func_80209988_de(void *);
extern s32 func_802744D4_de(void);

void func_802123DC_de(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    func_80209988_de(brain);
    brain->timer = func_802744D4_de() % 4 + 12;
    brain->pattern = func_802744D4_de() % 2;
}
#endif

#if defined(VERSION_DE)
void func_80212450_de(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    func_80209988_de(brain);
    brain->timer = func_802744D4_de() % 4 + 12;
    brain->pattern = func_802744D4_de() % 2;
    brain->distance = func_802744D4_de() % 250000 + 360000;
    brain->fireTimer = -1;
    brain->frames = 0;
    brain->visible = 0;
}
#endif

#if defined(VERSION_DE)
void func_80212524_de(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    brain->timer = func_802744D4_de() % 4 + 2;
    brain->pattern = func_802744D4_de() % 2;
    brain->distance = func_802744D4_de() % 32400 + 10000;
    func_80209988_de(brain);
    brain->frames = 0;
    brain->visible = 0;
    brain->fireTimer = -1;
}
#endif

#if defined(VERSION_DE)
void func_802125F0_de(CloseAttackActor *actor) {
    CloseAttackBrain *brain = actor->self->brain;
    brain->state = 0;
    func_80209988_de(brain);
    brain->timer = func_802744D4_de() % 4 + 12;
    brain->pattern = func_802744D4_de() % 2;
}
#endif

#if defined(VERSION_DE)
unsigned char D_auto_func_80211120_de_padding_13264[12] = { 0xAD, 0x20, 0x00, 0x08, 0x8C, 0xE5, 0x00, 0x00, 0x24, 0xE7, 0x00, 0x04 };
#endif
