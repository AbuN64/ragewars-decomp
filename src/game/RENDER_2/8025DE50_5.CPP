#include "COMMON/STATERECAT34.H"
#include "COMMON/GAME_SESSION.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "TYPES.H"
#include "AUDIO_2/802591C0.H"
#include "TEXTURE/80256220_15.H"
#include "RENDER_2/8025DE50_5.H"
#include "COMMON/AUDIO_CONTEXT.H"
#include "TEXTURE/80256220_14.H"

/** Calls func_80257360_de with &D_8010C080 as its argument. */





struct ContextRecAt2BC0;
extern s32 func_80258A7C_de(struct ContextRecAt2BC0 *arg0, s32 arg1, CVector3 arg2,
                         s32 arg3, s32 arg4, f32 arg5);







void func_8025DE30_de(void) {
    func_80257360_de(&D_8010C080);
}

s32 Render_PlaySoundAtPosition(s16 track, CVector3 arg1, s32 position, s32 arg5) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Texture_PlaySoundAtPosition(&D_8010C080, track, arg1, position, arg5);
}

s32 func_8025DEC0_de(s32 arg0, CVector3 arg1, s32 arg4, s32 arg5, f32 arg6) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return func_80258A7C_de(&D_8010C080, (s16)arg0, arg1, arg4, arg5, arg6);
}

s32 func_8025DF34_de(s32 track) {
    s32 temp_s0;
    s32 temp_s1;

    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    {
        CVector3 vec;
        register f32 zero = 0.0f;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        temp_s1 = func_80258D10_de(&D_8010C080);
        func_80258D08_de(&D_8010C080, 1);
        temp_s0 = Texture_PlaySoundAtPosition(&D_8010C080, (s16)track, vec, 0, -1);
        func_80258D08_de(&D_8010C080, temp_s1);
    }
    return temp_s0;
}

s32 func_8025DFE8_de(s32 index, CVector3 position, s32 arg2) {
    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    return Texture_PlayInstrumentAtPosition(&D_8010C080, index, position, arg2);
}

int func_8025E04C_de(int index) {
    int temp_s0;
    int temp_s1;

    if (D_8011FAC0.transitionBlocked != 0) {
        return -1;
    }
    {
        CVector3 vec;
        register float zero = (float)0;

        vec.z = zero;
        vec.y = zero;
        vec.x = zero;
        temp_s1 = func_80258D10_de(&D_8010C080);
        func_80258D08_de(&D_8010C080, 1);
        temp_s0 = Texture_PlayInstrumentAtPosition(&D_8010C080, index, vec, 0);
        func_80258D08_de(&D_8010C080, temp_s1);
    }
    return temp_s0;
}
