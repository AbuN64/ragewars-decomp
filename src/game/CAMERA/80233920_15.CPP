#include "COMMON/VIEWFLAGS.H"

void func_80239194_de(Racer *racer, signed char arg1, signed char delay) {
    if (racer != 0) {
        racer->mode548 = arg1;
        racer->mode549 = delay;
    }
}
