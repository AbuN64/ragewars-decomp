#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_80293A04.h"
#include "types.h"

/* Requests a switch of the session into mode 0x14: when the pending 0x1000 flag is set outside modes 0xB and 0xC and a target is given it records that target with phase 2 and clears the flags; otherwise, once func_80245814_de accepts the flags, it saves the current mode, enters mode 0x14 with the given argument at phase 1, and sets the timer when func_80264B6C_de allows. */



extern s32 D_8010B194_de;
extern s32 func_80245814_de(s32 *flags);
extern s32 func_80264B6C_de(void);

void func_80293A20_de(GameSession *session, s32 arg1, s32 target) {
    s32 pending;
    s32 *flags;

    flags = &D_8010B194_de;
    pending = *flags & 0x1000;
    if ((unsigned)(session->mode - 0xB) < 2) {
        pending = 0;
    }
    if (pending != 0 && target != -1) {
        session->phase = 2;
        session->target = target;
        *flags = 0;
        return;
    }
    if (func_80245814_de(flags) != 0) {
        s32 mode = session->mode;

        session->phase = 1;
        session->timer = 0;
        session->mode = 0x14;
        session->target = arg1;
        session->previousMode = mode;
        if (func_80264B6C_de() != 0) {
            session->timer = (1.0f);
        }
    }
}

/* Calls cleanup functions on a game state and optionally transitions control state when conditions change. */



extern s32 D_8010F190;
extern s32 D_8014288C;

#if defined(VERSION_EU)
extern void func_802A2344_eu(void);
#elif defined(VERSION_EU_X)
extern void func_802A2374_eu_x(void);
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_802A2164_us(void);
#else
extern void func_802A2224_de(void);
#endif
extern void func_80298368_de(s32 arg0);
extern void func_8040C428_de(s32 arg0);
extern void func_80293790_de(void *arg0, s32 arg1);
extern void func_80286080_de(void *arg0);
extern void func_802394B4_de(void *arg0);
extern void func_802AA7A4_de(void *arg0);
extern void func_80294F1C_us_rev1(void);
extern void func_80293394_de(void *arg0);





void func_80293B28_de(void *arg0) {
    void *state;
    f32 value;

    state = arg0;
    if (D_8014288C == 1) {
        value = ((GameSession *)state)->transitionTime;
        if (D_800C54A4_de < value) {
            if (D_800C54A8_de < value) {
                D_8014288C = 0;
                
#if defined(VERSION_EU)
func_802A2344_eu
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
func_802A2164_us
#else
func_802A2224_de
#endif
();
                func_80298368_de(2);
                func_8040C428_de(0);
                func_80293790_de(state, 1);
                ((GameSession *)state)->transitionTime = 0;
            } else if (D_8010F190 != 0) {
                D_8014288C = 0;
                
#if defined(VERSION_EU)
func_802A2344_eu
#elif defined(VERSION_EU_X)
func_802A2374_eu_x
#elif defined(VERSION_US) || defined(VERSION_US_REV1)
func_802A2164_us
#else
func_802A2224_de
#endif
();
                func_80298368_de(2);
                func_80293790_de(state, 8);
                ((GameSession *)state)->transitionTime = 0;
            }
        }
    }
    func_80286080_de((char *)state + 0x3C8);
    func_802394B4_de((char *)state + 0x255C8);
    func_802AA7A4_de((char *)state + 0x1BCF8);
    /* Only us-rev1 makes this call: us, eu, eu-x and de go straight on to func_80293394_de, two
       instructions shorter, as each cartridge's own bytes show. */
#ifdef VERSION_US_REV1
    func_80294F1C_us_rev1();
#endif
    func_80293394_de(state);
}

extern Vector4f D_801468A0;
extern f32 D_800D2988;








void func_80293C34_de(void *arg0) {
    f32 t1;
    f32 t2;
    f32 t3;

    if (((GameSession *)arg0)->clockPaused == 0) {
        t1 = D_801468A0.x + D_800D2988;
        D_801468A0.x = t1;
        if (D_800C54AC_de <= t1) {
            t2 = D_801468A0.y + D_800C54B0_de;
            D_801468A0.x = t1 - D_800C54AC_de;
            D_801468A0.y = t2;
            if (D_800C54B4_de <= t2) {
                t3 = D_801468A0.z + D_800C54B0_de;
                D_801468A0.y = t2 - D_800C54B4_de;
                D_801468A0.z = t3;
                if (D_800C54B4_de <= t3) {
                    D_801468A0.z = t3 - D_800C54B4_de;
                    D_801468A0.w = D_801468A0.w + D_800C54B0_de;
                }
            }
        }
    }
}
