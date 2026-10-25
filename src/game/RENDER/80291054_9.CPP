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

extern int D_80146878;

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
    return D_80146878 == 0xD;
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
    session->pad26DC0 = 0;
}

#ifdef NON_MATCHING
extern f32 D_800C5480_de, D_800C5484_de, D_800C5488_de, D_800C5490_de;
extern f32 D_800C548C, literals_Engine_GetPlatformRoutePoint;
typedef struct FadeState {
    char pad0[0x26DB4];
    s32 previous;  /* 0x26DB4 */
    s32 current;   /* 0x26DB8 */
    char pad26DBC[4];
    u8 reverse;    /* 0x26DC0 */
    u8 mode;       /* 0x26DC1: 0 idle, 1 fading up, 2 fading down */
    char pad26DC2[2];
    f32 timer;     /* 0x26DC4 */
} FadeState;
/* 90.5%: mode switch (2 before 1) and fresh locals match the ROM layout; remaining: step is copied to f3 for mode 2 in the ROM.
 * Steps the fade timer of a screen state by a step that depends on the direction flag: mode 1 raises it until
 * it reaches the limit, mode 2 lowers it to zero (or below) and then switches to the next screen. */
void Render_UpdateFadeTransition(FadeState *state) {
    f32 step;
    f32 timer;
    f32 next;
    f32 limit;
    if (state->mode == 0) {
        return;
    }
    step = D_800C5480_de;
    if (state->reverse != 0) {
        step = D_800C5484_de;
    }
    switch (state->mode) {
    case 2:
        timer = state->timer;
        if (timer > 0.0f) {
            next = timer - step * literals_Engine_GetPlatformRoutePoint;
            state->timer = next;
            if (next < 0.0f) {
                state->timer = 0.0f;
            }
        } else {
            state->timer = timer - D_800C5488_de;
        }
        if (state->timer < D_800C548C) {
            s32 old = state->current;
            state->current = 0x14;
            state->timer = 0.0f;
            state->mode = 1;
            state->previous = old;
        }
        break;
    case 1:
        timer = state->timer;
        if (literals_Engine_GetPlatformRoutePoint < D_800C5490_de) {
            next = timer + step * D_800C5490_de;
        } else {
            next = timer + step * literals_Engine_GetPlatformRoutePoint;
        }
        state->timer = next;
        limit = *(f32 *)&D_800C5494;
        if (limit <= next) {
            state->mode = 0;
            state->timer = limit;
            state->reverse = 0;
        }
        break;
    }
}
#else
INCLUDE_ASM("span_1000", Render_UpdateFadeTransition);
#endif
