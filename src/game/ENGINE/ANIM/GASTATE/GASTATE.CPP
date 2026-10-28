#include "COMMON/LOCALDECODERANGE.H"
#include "SYSTEM/802609CC.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/PPDECOM_UNPACKRESOURCE.H"
#include "COMMON/MTX.H"
#include "TYPES.H"
#include "ENGINE/INSTANCE/GASTATE_ADVANCEROOTMOTION_DATA.H"
#include "GAME/BUILDDIRECTIONMATRIX.H"
#include "SCENE/CACHE_REQUESTRESOURCE.H"
#include "SYSTEM/POLYTRAK2_INTERPOLATEJOINTQUATERNION.H"
#include "RENDER/SETN64_GETPACKSECTION.H"

/* Switches an animation track to its pending clip when asked and the clip differs: keeps a copy of the track, loads the pending clip's resource and, when it is ready, reads its frame count and length, hands the old state to the previous track slot, restarts the track on the new clip and reports the switch; otherwise, or when not switching, it reloads the current clip and reports no switch. */




extern char g_animationText;

extern s32 SetN64_LocatePackSection(s32, s32, s32, s32 *);


extern s32 func_802624D8_de(Anim *);


static inline s32 load(Anim *anim, s32 table, s32 key, s32 id) {
    s32 size;
    s32 clip;
    void *header;

    if (id == -1) {
        anim->resource = 0;
        return 0;
    }
    clip = SetN64_LocatePackSection(table, key, id, &size);
    anim->resource = Cache_RequestResource(0, clip, clip, size, 4, anim, &D_0025F56C, &g_animationText, 0);
    if (func_802624D8_de(anim) == 0) {
        return 0;
    }
    header = Polytrak2_GetResidentResource(anim);
    anim->frames = ((u16 *)SetN64_GetPackSection(header, 0))[3];
    anim->current = id;
    anim->length = ((u16 *)SetN64_GetPackSection(SetN64_GetPackSection(header, 3), 0))[1];
    return 1;
}

extern void Polytrak2_SampleVectorTrack(void *,s32,f32,CVector3 *);

extern f32 D_800C41BC_de;

extern f32 D_800C41C0_de;

extern f32 D_800C41F0_de;

extern f32 D_800C41F4_de;

extern f64 D_800C41C8_de,D_800C41D0_de,D_800C41D8_de,D_800C41E0_de,D_800C41E8_de;

static __inline__ f64 unsignedDouble(u32 value,const f64 *bias) {
    f64 result=(f64)(s32)value;
    if ((s32)value<0) result+=*bias;
    return result;
}

static __inline__ f32 wrapAngle(CGameAnimateState_t *anim,f32 time) {
    s16 *keys;
    s32 first,next,last;
    keys=((AngleKeys *)SetN64_GetPackSection(Polytrak2_GetResidentResource(anim),0))->keys;
    first=(s32)time;
    next=first+1;
    last=anim->frames-1;
    if(next<last) last=next;
    return Graphu64_InterpolateWrappedValue(time-(f32)first,(f32)keys[first]*D_800C41F0_de,(f32)keys[last]*D_800C41F0_de);
}

void Gastate_SwitchRequestedAnimation(Anim *anim, s32 table, s32 key, s32 blend, s32 *switched, Anim *previous) {
    s32 current;
    s32 next;
    Anim saved;

    current = anim->current;
    next = anim->next;
    if (next != current && blend != 0) {
        anim->active = 1;
        saved = *anim;
        if (load(anim, table, key, next)) {
            if (previous != 0) {
                *previous = saved;
                previous->current = current;
                previous->next = current;
                previous->active = 1;
            }
            anim->current = next;
            anim->next = next;
            anim->time = 0;
            anim->blending = 0;
            anim->active = 1;
            if (switched != 0) {
                *switched = 1;
            }
            return;
        }
        if (switched != 0) {
            *switched = 0;
        }
        load(anim, table, key, current);
        return;
    }
    if (switched != 0) {
        *switched = 0;
    }
    load(anim, table, key, current);
}

void Gastate_AdvanceRootMotion(CGameAnimateState_t *animationChannel, CVector3 *translationDeltaOut, f32 *angleDeltaOut, RootActor *rootMotionActor) {
    CVector3 startRootPosition;
    CVector3 endRootPosition;
    f32 angleSample;
    f32 lastFramePosition;
    f32 angleScale;
    f32 forcedEndFrame;
    f32 wrappedFramePosition;
    f32 previousFramePosition;
    f32 startRootAngle;
    f64 var_fa0;
    f64 clampedLoopStart;
    f64 eventLoopStart;
    f64 positionLoopStart;
    f64 loopStartDouble;
    s32 followingAngleFrame;
    s32 followingEndAngleFrame;
    s32 temp_a0_3;
    s32 followingCurrentAngleFrame;
    s16 *startAngleKeys;
    s16 *endAngleKeys;
    s16 *temp_a2_3;
    s16 *currentAngleKeys;
    s32 startAngleFrame;
    s32 endAngleFrame;
    s32 temp_fv1f_3;
    s32 currentAngleFrame;
    s32 nextStartAngleFrame;
    s32 nextEndAngleFrame;
    s32 var_v1_3;
    s32 nextCurrentAngleFrame;
    RootClip *rootMotionClip;
    u16 loopStartFrame;
    u32 restartFrame;
    s32 lastFrameIndex;

    void *header;
    header = Polytrak2_GetResidentResource(animationChannel);
    translationDeltaOut->x = 0.0f;
    translationDeltaOut->y = 0.0f;
    translationDeltaOut->z = 0.0f;
    *angleDeltaOut = 0.0f;
    if (rootMotionActor->flags & 0x08000000) {
        forcedEndFrame = (f32) (animationChannel->frames - 1);
        animationChannel->time = forcedEndFrame;
        func_802476C8_de((char *)rootMotionActor, animationChannel, 0.0f, forcedEndFrame);
        rootMotionActor->flags = (s32) (rootMotionActor->flags & 0xF7FFFFFF);
    }
    rootMotionClip = SetN64_GetPackSection(header,3);
    rootMotionClip = SetN64_GetPackSection(rootMotionClip,0);
    Polytrak2_SampleVectorTrack(animationChannel, 0, animationChannel->time, &startRootPosition);
    angleSample = animationChannel->time;
    startAngleKeys = ((AngleKeys *)SetN64_GetPackSection(Polytrak2_GetResidentResource(animationChannel), 0))->keys;
    nextStartAngleFrame = animationChannel->frames - 1;
    startAngleFrame = (s32) angleSample;
    followingAngleFrame = startAngleFrame + 1;
    if (followingAngleFrame < nextStartAngleFrame) {
        nextStartAngleFrame = followingAngleFrame;
    }
    angleScale = D_800C41BC_de;
    startRootAngle = Graphu64_InterpolateWrappedValue(angleSample - (f32) startAngleFrame, (f32) startAngleKeys[startAngleFrame] * angleScale, (f32) startAngleKeys[nextStartAngleFrame] * angleScale);
    previousFramePosition = animationChannel->time;
    if (!(rootMotionActor->flags & 0x08000000)) {
        animationChannel->time = (f32) (previousFramePosition + (D_800D2988 * rootMotionClip->rate * D_800C41C0_de));
    }
    func_802476C8_de((char *)rootMotionActor, animationChannel, previousFramePosition, animationChannel->time);
    lastFrameIndex = animationChannel->frames - 1;
    lastFramePosition = (f32) lastFrameIndex;
    if (lastFramePosition < animationChannel->time) {
        Polytrak2_SampleVectorTrack(animationChannel, 0, lastFramePosition, &endRootPosition);
        endAngleKeys = ((AngleKeys *)SetN64_GetPackSection(Polytrak2_GetResidentResource(animationChannel), 0))->keys;
        endAngleFrame = (s32) lastFramePosition;
        followingEndAngleFrame = endAngleFrame + 1;
        nextEndAngleFrame = animationChannel->frames - 1;
        if (followingEndAngleFrame < nextEndAngleFrame) {
            nextEndAngleFrame = followingEndAngleFrame;
        }
        angleSample = Graphu64_InterpolateWrappedValue(lastFramePosition - (f32) endAngleFrame, (f32) endAngleKeys[endAngleFrame] * angleScale, (f32) endAngleKeys[nextEndAngleFrame] * angleScale);
        Graphu64_AddVec3(translationDeltaOut, translationDeltaOut, &endRootPosition);
        Graphu64_SubtractVectors(translationDeltaOut, translationDeltaOut, &startRootPosition);
        *angleDeltaOut += Graphu64_GetWrappedDifference(angleSample, startRootAngle);
        loopStartFrame = rootMotionClip->loopStart;
        restartFrame = 0;
        if (loopStartFrame != 0xFFFF) {
            restartFrame = loopStartFrame;
        }
        loopStartDouble = unsignedDouble(restartFrame, &D_800C41C8_de);
        wrappedFramePosition = ((f32) loopStartDouble + animationChannel->time) - lastFramePosition;
        animationChannel->time = wrappedFramePosition;
        if (lastFramePosition < wrappedFramePosition) {
            clampedLoopStart = unsignedDouble(restartFrame, &D_800C41D0_de);
            animationChannel->time = (f32) clampedLoopStart;
        }
        if ((restartFrame >= (u32)lastFrameIndex) && (animationChannel->current == animationChannel->next) && (func_802625C4_de(animationChannel) == 0)) {
            animationChannel->blending = 0;
        }
        eventLoopStart = unsignedDouble(restartFrame, &D_800C41D8_de);
        func_802476C8_de((char *)rootMotionActor, animationChannel, (f32) eventLoopStart, animationChannel->time);
        positionLoopStart = unsignedDouble(restartFrame, &D_800C41E0_de);
        Polytrak2_SampleVectorTrack(animationChannel, 0, (f32) positionLoopStart, &startRootPosition);
        startRootAngle = wrapAngle(animationChannel,(f32)unsignedDouble(restartFrame,&D_800C41E8_de));
        animationChannel->active = 1;
    }
    Polytrak2_SampleVectorTrack(animationChannel, 0, animationChannel->time, &endRootPosition);
    angleSample = animationChannel->time;
    currentAngleKeys = ((AngleKeys *)SetN64_GetPackSection(Polytrak2_GetResidentResource(animationChannel), 0))->keys;
    nextCurrentAngleFrame = animationChannel->frames - 1;
    currentAngleFrame = (s32) angleSample;
    followingCurrentAngleFrame = currentAngleFrame + 1;
    if (followingCurrentAngleFrame < nextCurrentAngleFrame) {
        nextCurrentAngleFrame = followingCurrentAngleFrame;
    }
    angleSample = Graphu64_InterpolateWrappedValue(angleSample - (f32) currentAngleFrame, (f32) currentAngleKeys[currentAngleFrame] * D_800C41F4_de, (f32) currentAngleKeys[nextCurrentAngleFrame] * D_800C41F4_de);
    Graphu64_AddVec3(translationDeltaOut, translationDeltaOut, &endRootPosition);
    Graphu64_SubtractVectors(translationDeltaOut, translationDeltaOut, &startRootPosition);
    *angleDeltaOut += Graphu64_GetWrappedDifference(angleSample, startRootAngle);
}
