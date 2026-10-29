#include "COMMON/TRIPLE.H"
#include "COMMON/SHARED_PARTICLEINSTANCE.H"
#include "COMMON/WEAPON_SCREEN_MESSAGE_OPERATIONS.H"

/* Advance the two measured oscillator phases and apply their velocity deltas. */






extern void Graphu64_CrossVectors(CVector3 *, CVector3 *, CVector3 *);


void Particle_UpdateSineMotion(void *particle, f32 amplitudeScale) {
    CVector3 sp10;
    CVector3 sp20;
    Triple sp30;
    CVector3 sp40;
    CVector3 sp50;
    CVector3 sp60;
    f32 fadeInDuration;
    f32 nextSineAngleX;
    f32 nextSineAngleY;
    f32 particleAge;
    f32 motionAmplitude;
    s8 fadeInFrames;

    fadeInFrames = ((Shared_Particle *)particle)->desc->sineWave->fadeInFrames;
    motionAmplitude = g_particleSineMotionAmplitude;
    if (fadeInFrames != 0) {
        particleAge = ((Shared_Particle *)particle)->time;
        fadeInDuration = (f32) fadeInFrames;
        if (particleAge < fadeInDuration) {
            motionAmplitude = particleAge / fadeInDuration;
        }
    }
    motionAmplitude *= amplitudeScale;
    sp30 = *(Triple *)&((Shared_Particle *)particle)->direction;
    if (((Shared_Particle *)particle)->sineAmplitudeX > 0.0f) {
        CVector3 *velocity;

        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = g_particleSineMotionOffsetY;
        Graphu64_CrossVectors(&sp20, &sp10, (CVector3 *)&sp30);
        Graphu64_ScaleVector(&sp40, &sp20, Gu_Sinf(((Shared_Particle *)particle)->sineAngleX) * ((Shared_Particle *)particle)->sineAmplitudeX * motionAmplitude);
        nextSineAngleX = ((Shared_Particle *)particle)->sineAngleX + (((Shared_Particle *)particle)->sineAngleSpeedX * motionAmplitude * g_frameElapsedTime);
        ((Shared_Particle *)particle)->sineAngleX = nextSineAngleX;
        Graphu64_ScaleVector(&sp50, &sp20, Gu_Sinf(nextSineAngleX) * ((Shared_Particle *)particle)->sineAmplitudeX * motionAmplitude);
        velocity = &((Shared_Particle *)particle)->inst.velocity;
        Graphu64_SubtractVectors(velocity, velocity, &sp40);
        Graphu64_AddVec3((CVector3 *) velocity, (CVector3 *) velocity, (CVector3 *) &sp50);
    } else {
        ((Shared_Particle *)particle)->sineAngleX = (f32) (((Shared_Particle *)particle)->sineAngleX + (((Shared_Particle *)particle)->sineAngleSpeedX * motionAmplitude * g_frameElapsedTime));
    }
    if (((Shared_Particle *)particle)->sineAmplitudeY > 0.0f) {
        sp10.x = 0.0f;
        sp10.z = 0.0f;
        sp10.y = g_particleSineMotionTargetY;
        Graphu64_CrossVectors(&sp60, &sp10, (CVector3 *)&sp30);
        Graphu64_CrossVectors(&sp20, &sp60, (CVector3 *)&sp30);
        Graphu64_ScaleVector(&sp40, &sp20, Gu_Sinf(((Shared_Particle *)particle)->sineAngleY) * ((Shared_Particle *)particle)->sineAmplitudeY * motionAmplitude);
        nextSineAngleY = ((Shared_Particle *)particle)->sineAngleY + (((Shared_Particle *)particle)->sineAngleSpeedY * motionAmplitude * g_frameElapsedTime);
        ((Shared_Particle *)particle)->sineAngleY = nextSineAngleY;
        Graphu64_ScaleVector(&sp50, &sp20, Gu_Sinf(nextSineAngleY) * ((Shared_Particle *)particle)->sineAmplitudeY * motionAmplitude);
        Graphu64_SubtractVectors(&((Shared_Particle *)particle)->inst.velocity, &((Shared_Particle *)particle)->inst.velocity, &sp40);
        Graphu64_AddVec3(&((Shared_Particle *)particle)->inst.velocity, &((Shared_Particle *)particle)->inst.velocity, &sp50);
        return;
    }
    ((Shared_Particle *)particle)->sineAngleY = (f32) (((Shared_Particle *)particle)->sineAngleY + (((Shared_Particle *)particle)->sineAngleSpeedY * motionAmplitude * g_frameElapsedTime));
}
