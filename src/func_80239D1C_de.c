#include "span_1000/code_802393F4.h"
#include "types.h"

/* Evaluates a wave: kind 1 returns func_802B7130_de of the phase at 0x10 scaled by D_800C865C, times
   the amplitude at 0xC; kind 0 returns func_80274A90_de over minus to plus the amplitude; any other
   kind returns zero. */






f32 func_80239D1C_de(struct Wave *wave) {
    switch (wave->kind) {
    case 1:
        return func_802B7130_de(wave->phase * D_800C865C) * wave->amplitude;
    case 0:
        return func_80274A90_de(-wave->amplitude, wave->amplitude);
    }
    return 0.0f;
}
