#include "COMMON/VIEWFLAGS.H"

void func_80239194_de(Racer *racer, signed char effectMode, signed char delay) {
    if (racer != 0) {
        racer->mode548 = effectMode;
        racer->mode549 = delay;
    }
}
