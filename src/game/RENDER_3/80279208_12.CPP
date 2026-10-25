#include "COMMON/TRIPLE.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/EXTERNS_6.H"

/* Advance the two measured oscillator phases and apply their velocity deltas. */






extern void Particle_CrossVectors(CVector3 *, CVector3 *, CVector3 *);


void func_80279DD0_de(void *particle, f32 arg1) {
    CVector3 sp10;
    CVector3 sp20;
    Triple sp30;
    CVector3 sp40;
    CVector3 sp50;
    CVector3 sp60;
    f32 temp_f0;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f1;
    f32 var_f20;
    s8 temp_v0;

    temp_v0 = ((Shared_Particle *)particle)->desc->sineWave->fadeInFrames;
    var_f20 = D_800C4B40_de;
    if (temp_v0 != 0) {
        temp_f1 = ((Shared_Particle *)particle)->time;
        temp_f0 = (f32) temp_v0;
        if (temp_f1 < temp_f0) {
            var_f20 = temp_f1 / temp_f0;
        }
    }
    var_f20 *= arg1;
    sp30 = *(Triple *)&((Shared_Particle *)particle)->direction;
    if (((Shared_Particle *)particle)->sineAmplitudeX > 0.0f) {
        CVector3 *temp_s0;

        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = D_800C4B44_de;
        Particle_CrossVectors(&sp20, &sp10, (CVector3 *)&sp30);
        Particle_ScaleVector(&sp40, &sp20, Math_Sinf(((Shared_Particle *)particle)->sineAngleX) * ((Shared_Particle *)particle)->sineAmplitudeX * var_f20);
        temp_f12 = ((Shared_Particle *)particle)->sineAngleX + (((Shared_Particle *)particle)->sineAngleSpeedX * var_f20 * D_800D2988);
        ((Shared_Particle *)particle)->sineAngleX = temp_f12;
        Particle_ScaleVector(&sp50, &sp20, Math_Sinf(temp_f12) * ((Shared_Particle *)particle)->sineAmplitudeX * var_f20);
        temp_s0 = &((Shared_Particle *)particle)->inst.velocity;
        Particle_SubtractVectors(temp_s0, temp_s0, &sp40);
        Particle_AddVec3((CVector3 *) temp_s0, (CVector3 *) temp_s0, (CVector3 *) &sp50);
    } else {
        ((Shared_Particle *)particle)->sineAngleX = (f32) (((Shared_Particle *)particle)->sineAngleX + (((Shared_Particle *)particle)->sineAngleSpeedX * var_f20 * D_800D2988));
    }
    if (((Shared_Particle *)particle)->sineAmplitudeY > 0.0f) {
        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = D_800C4B48_de;
        Particle_CrossVectors(&sp60, &sp10, (CVector3 *)&sp30);
        Particle_CrossVectors(&sp20, &sp60, (CVector3 *)&sp30);
        Particle_ScaleVector(&sp40, &sp20, Math_Sinf(((Shared_Particle *)particle)->sineAngleY) * ((Shared_Particle *)particle)->sineAmplitudeY * var_f20);
        temp_f12_2 = ((Shared_Particle *)particle)->sineAngleY + (((Shared_Particle *)particle)->sineAngleSpeedY * var_f20 * D_800D2988);
        ((Shared_Particle *)particle)->sineAngleY = temp_f12_2;
        Particle_ScaleVector(&sp50, &sp20, Math_Sinf(temp_f12_2) * ((Shared_Particle *)particle)->sineAmplitudeY * var_f20);
        Particle_SubtractVectors(&((Shared_Particle *)particle)->inst.velocity, &((Shared_Particle *)particle)->inst.velocity, &sp40);
        Particle_AddVec3(&((Shared_Particle *)particle)->inst.velocity, &((Shared_Particle *)particle)->inst.velocity, &sp50);
        return;
    }
    ((Shared_Particle *)particle)->sineAngleY = (f32) (((Shared_Particle *)particle)->sineAngleY + (((Shared_Particle *)particle)->sineAngleSpeedY * var_f20 * D_800D2988));
}
