#include "span_C76B0/data.h"
#include "span_1000/code_8027A0F4.h"

/* Advance the two measured oscillator phases and apply their velocity deltas. */






extern f32 D_800D2988;
extern void func_80272018_de(Vec3 *, Vec3 *, Vec3 *);


void func_80279DD0_de(void *arg0, f32 arg1) {
    Vec3 sp10;
    Vec3 sp20;
    Triple sp30;
    Vec3 sp40;
    Vec3 sp50;
    Vec3 sp60;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f1;
    f32 var_f20;
    s8 temp_v0;

    temp_v0 = ((Shared_Particle *)arg0)->desc->oscillation->ramp;
    var_f20 = D_800C4B40_de;
    if (temp_v0 != 0) {
        temp_f1 = ((Shared_Particle *)arg0)->time;
        temp_f0 = (f32) temp_v0;
        if (temp_f1 < temp_f0) {
            var_f20 = temp_f1 / temp_f0;
        }
    }
    var_f20 *= arg1;
    sp30 = *(Triple *)&((Shared_Particle *)arg0)->unk174;
    if (((Shared_Particle *)arg0)->amplitudeA > 0.0f) {
        Vec3 *temp_s0;

        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = D_800C4B44_de;
        func_80272018_de(&sp20, &sp10, (Vec3 *)&sp30);
        func_80271F9C_de(&sp40, &sp20, func_802B7130_de(((Shared_Particle *)arg0)->phaseA) * ((Shared_Particle *)arg0)->amplitudeA * var_f20);
        temp_f12 = ((Shared_Particle *)arg0)->phaseA + (((Shared_Particle *)arg0)->phaseSpeedA * var_f20 * D_800D2988);
        ((Shared_Particle *)arg0)->phaseA = temp_f12;
        func_80271F9C_de(&sp50, &sp20, func_802B7130_de(temp_f12) * ((Shared_Particle *)arg0)->amplitudeA * var_f20);
        temp_s0 = &((Shared_Particle *)arg0)->inst.velocity;
        func_80271F68_de(temp_s0, temp_s0, &sp40);
        func_80271F34_de((Vec3 *) temp_s0, (Vec3 *) temp_s0, (Vec3 *) &sp50);
    } else {
        ((Shared_Particle *)arg0)->phaseA = (f32) (((Shared_Particle *)arg0)->phaseA + (((Shared_Particle *)arg0)->phaseSpeedA * var_f20 * D_800D2988));
    }
    if (((Shared_Particle *)arg0)->amplitudeB > 0.0f) {
        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = D_800C4B48_de;
        func_80272018_de(&sp60, &sp10, (Vec3 *)&sp30);
        func_80272018_de(&sp20, &sp60, (Vec3 *)&sp30);
        func_80271F9C_de(&sp40, &sp20, func_802B7130_de(((Shared_Particle *)arg0)->phaseB) * ((Shared_Particle *)arg0)->amplitudeB * var_f20);
        temp_f12_2 = ((Shared_Particle *)arg0)->phaseB + (((Shared_Particle *)arg0)->phaseSpeedB * var_f20 * D_800D2988);
        ((Shared_Particle *)arg0)->phaseB = temp_f12_2;
        func_80271F9C_de(&sp50, &sp20, func_802B7130_de(temp_f12_2) * ((Shared_Particle *)arg0)->amplitudeB * var_f20);
        func_80271F68_de(&((Shared_Particle *)arg0)->inst.velocity, &((Shared_Particle *)arg0)->inst.velocity, &sp40);
        func_80271F34_de(&((Shared_Particle *)arg0)->inst.velocity, &((Shared_Particle *)arg0)->inst.velocity, &sp50);
        return;
    }
    ((Shared_Particle *)arg0)->phaseB = (f32) (((Shared_Particle *)arg0)->phaseB + (((Shared_Particle *)arg0)->phaseSpeedB * var_f20 * D_800D2988));
}

