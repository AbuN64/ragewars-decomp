#include "AI/SOURCE.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "AI/NAV/80212C90_3.H"

#if !(defined(VERSION_DE) || defined(VERSION_EU))
void func_80212D80_eu_x(struct ActorRecAt1D8V2 *arg0) {
    Brain_func_80212D78_eu_x *brain = arg0->player->brain;

    brain->unk220 = 0;
    func_80209988_de(brain);
    brain->unk2FC = 0;
}
#endif
