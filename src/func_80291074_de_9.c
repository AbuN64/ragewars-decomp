#include "span_1000/code_80291054.h"
#include "common/unused.h"
#include "span_1000/code_80293A04.h"
#include "span_C76B0/data.h"
#include "types.h"
#include "video_dimensions.h"

extern s32 D_800E28D0;

extern s32 D_800E28D4;

extern void func_8029311C_de(void *arg0, s8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

extern int D_80146878;

s32 func_80292FC0_de(s32 *, s32);

extern s32 D_8011FAC0;

extern void func_802BD320_de(void *a, void *b, void *c, void *d);

extern s32 func_802BCF10_de(void);

extern void func_802BD160_de(s32 arg0);

extern void func_80291404(void *arg0);

extern int D_80146CE8;

extern int D_800C5400_de;

extern int D_800C5408_de;

extern int D_800C5414_de;

extern int D_8011FAC0;

void func_80293394_de(struct GameSession *arg0) {
    s8 color[4];
    f32 value;
    s32 alpha;

    color[0] = 0;
    color[1] = 0;
    color[2] = 0;
    value = arg0->timer;
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
    func_8029311C_de(arg0, color, 0, 0, SCREEN_WD, SCREEN_HT);
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
    func_802BD320_de(&D_80146CE8, &D_800C5400_de, &D_800C5408_de, &D_800C5414_de);
    func_802BD160_de(func_802BCF10_de() | 0x400);
    func_80291404(&D_8011FAC0);
}

/** Reset three large-offset fields and mark the record active. */
void func_80293590_de(void *arg0) {
    struct GameSession *session = arg0;
    session->phase = 1;
    session->timer = 0;
    session->pad26DC0 = 0;
}
