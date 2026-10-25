#include "include_asm.h"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/UNUSED.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "COMMON/VIDEO_DIMENSIONS.H"
#include "RENDER/80291054_2.H"
#include "RENDER/80291054_9.H"
#include "sdk/AUDIO/802BD1A8_19.H"

extern void func_8029311C_de(void *arg0, s8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

extern f32 D_800D2988; /* frame time scale (Particle code saves and rescales it) */

s32 func_80292FC0_de(s32 *, s32);

#include "COMMON/GAME_SESSION.H"



extern void func_802BD160_de(s32 arg0);







void func_80293394_de(struct GameSession *session) {
    s8 color[4];
    f32 value;
    s32 alpha;

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    value = session->timer;
    alpha = 0xFF;
    if (!(value < 0)) {
        alpha = 0;
        if (!((&D_800CA560)[1] < value)) {
            alpha = 0xFF;
            if (!(value < 0)) {
                alpha = ~(s32)(value * D_800C547C);
            }
        }
    }
    color[3] = alpha;
    func_8029311C_de(session, color, 0, 0, SCREEN_WD, SCREEN_HT);
}

/* Compares two byte strings lexicographically, returning -1 for either null pointer. */
int func_80293440_de(u8 *a, u8 *b) {
 if (!a || !b) return -1;
 while (*a && *b) {
  if (*a < *b) return -1;
  if (*a > *b) return 1;
  a++; b++;
 }
 if (*a) return 1;
 if (*b) return -1;
 return 0;
}

u8 *func_802934C0_de(u8 *arg0, u8 *arg1)
{
  u8 *var_a1;
  u8 *var_v1;
  u8 temp_v0;
  u8 temp_v0_2;
 do { temp_v0 = *arg1; var_a1 = arg1 + 1; } while (0);
  *arg0 = temp_v0;
  var_v1 = arg0 - -1;
  if (temp_v0 & 0xFF)
  {
    do
    {
      temp_v0_2 = *var_a1;
      var_a1 += 1;
      *var_v1 = temp_v0_2;
      var_v1 += 1;
    }
    while (temp_v0_2 & 0xFF);
  }
  return arg0;
}

int func_802934F8_de(void) {
    return D_8011FAC0.mode == 0xD;
}

void func_8029350C_de(s32 arg0) {
    func_80292FC0_de(&D_8011FAC0, arg0);
}

void func_80293534_de(void) {
    func_802BD320_de(D_80146CE8, D_800C5400_de, D_800C5408_de, D_800C5414_de);
    func_802BD160_de(func_802BCF10_de() | 0x400);
    Render_RunGameLoop(&D_8011FAC0);
}

/** Reset three large-offset fields and mark the record active. */
void func_80293590_de(void *gameSession) {
    struct GameSession *session = gameSession;
    session->phase = 1;
    session->timer = 0;
    session->fastFade = 0;
}

/* Steps the session's screen fade by the frame time D_800D2988 (fastFade picks the fast rate). Phase 2 fades out: the
 * timer falls to zero, then keeps counting below it until -4 before the session switches to mode 0x14 and fades back
 * in. Phase 1 fades in, at least half the rate per frame, until the timer reaches one. */
void Render_UpdateFadeTransition(GameSession *session) {
    f32 step;
    f32 rate;
    f32 timer;
    f32 next;

    if (session->phase == 0) {
        return;
    }
    step = 0.1f;
    if (session->fastFade != 0) {
        step = 0.5f;
    }
    rate = step;
    switch (session->phase) {
    case 2:
        timer = session->timer;
        if (timer > 0.0f) {
            step = D_800D2988;
            next = timer - rate * step;
            session->timer = next;
            if (next < 0.0f) {
                session->timer = 0.0f;
            }
        } else {
            session->timer = timer - 1.0f;
        }
        if (session->timer < -4.0f) {
            s32 saved = session->mode;
            session->mode = 0x14;
            session->timer = 0.0f;
            session->phase = 1;
            session->previousMode = saved;
        }
        break;
    case 1:
        timer = session->timer;
        if (D_800D2988 < 0.5f) {
            next = timer + step * 0.5f;
        } else {
            next = timer + step * D_800D2988;
        }
        session->timer = next;
        if (next >= 1.0f) {
            session->phase = 0;
            session->timer = 1.0f;
            session->fastFade = 0;
        }
        break;
    }
}
