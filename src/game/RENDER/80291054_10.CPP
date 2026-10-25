#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PAKQUEUESTATE.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "RENDER/80291054.H"
#include "RENDER/802909E0.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/TRIPLE.H"

void Render_BeginModeTransition(GameSession *session, s32 arg1) {
    s32 saved;

    saved = session->mode;
    session->phase = 1;
    session->timer = 0;
    session->mode = 0x14;
    session->target = arg1;
    session->previousMode = saved;
    if (func_80264B6C_de() != 0) {
        session->timer = D_800C5494.unk4;
    }
}

/** Set the state byte and linked value in a large object. */
void Render_SetTransitionTarget(GameSession *object, int value) {
    object->phase = 2;
    object->target = value;
}

typedef void (*Handler8029382C)(void *);


extern void Render_UpdateFrameTiming(void *arg0);






void Render_UpdateGameMode(void *session) {
    s32 field;
    Handler8029382C fn;

    if (D_800CD724 != 0) {
        D_800CD724 = 0;
    }
    func_80264CB8_de();
    field = ((GameSession *)session)->mode;
    fn = ((SessionHandlerRow *)D_800CD78C)[field].update;
    if (fn != 0) {
        fn(session);
        field = ((GameSession *)session)->mode;
    }
    if (field != 0x14 && D_80142CA8 != 0) {
        D_80142CA8 -= 1;
        Render_UpdateFrameTiming(session);
    }
    D_800CD734 += 1;
}

s32 func_80293904_de(ObjRecAt26DC1 *arg0, f32 arg1, s32 eight, s32 arg3) {
    s32 *flag = (s32 *)&D_8010B0E0.pressedButtons;

    if ((*flag != 0) && (arg3 != -1)) {
        arg0->unk26DC1 = 2;
        arg0->unk26DBC = arg3;
        *flag = 0;
        return 1;
    }
    if ((arg1 * D_800C549C) < arg0->unk26DB0) {
        arg0->unk26DC1 = 2;
        arg0->unk26DBC = eight;
        return 1;
    }
    return 0;
}
