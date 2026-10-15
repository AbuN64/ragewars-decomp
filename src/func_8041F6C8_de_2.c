#include "span_1000/code_8025A3EC.h"
#include "span_16E000/code_804264F0.h"
#include "common/unused.h"
#include "span_16E000/code_8041F1FC.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"

s32 func_8041F2A0_us_rev1(s32 screen)
{
  Vec3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = func_8025305C_de(0x1358);
  D_800E42D0->screen = (void *) screen;
  D_800E42D0->unk4 = func_8041B610_de(screen, 4);
  func_8041B6E8_de(screen, 0, 0x7A);
  func_8041B6E8_de(screen, 1, 0x7A);
  func_8041B6E8_de(screen, 2, 0x7A);
  func_8041B6E8_de(screen, 3, 0x7A);
  func_8042E9A0_de(0, 0);
  D_800E42D0->clock = 0;
  scale.x = 1.0f;
  scale.y = 1.0f;
  scale.z = 1.0f;
  for (i = 0; i < 4; i++)
  {
    D_800E42D0->players[i].unk4 = 0;
    D_800E42D0->players[i].kind = D_800E42D4[i].kind;
    D_800E42D0->players[i].highlight = 0;
    D_800E42D0->players[i].unkC = 0;
    D_800E42D0->players[i].choice = 0;
    D_800E42D0->players[i].unk4C0 = 0;
    model = func_8041F1D8_de(D_800E42D0->players[i].kind);
    row = func_8041F18C_de(D_800E42D0->players[i].kind);
    scale.x = D_800E3A58[row].scale[i];
    scale.y = D_800E3A58[row].scale[i];
    scale.z = D_800E3A58[row].scale[i];
    func_8041CAD8_de(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    func_8040EC30_de(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      func_8040EC30_de(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      func_8040E8D8_de(func_8040EC30_de(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = func_8040EC30_de((void *) screen, 0xAC);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = func_8040EC30_de((void *) screen, 0x93);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  func_8040EC30_de((void *) screen, 0x76)->alpha = 0x6E;
  func_8040EC30_de((void *) screen, 0x79)->alpha = 0x19;
  D_800E42D0->prompt = func_80419E54_de(0x74, 0xFF);
  item = func_8040EC30_de((void *) screen, 0x74);
  D_800E42D0->promptItem = item;
  func_8040E8D8_de(item, 0);
  D_800E42D0->pulse = func_8040EC30_de((void *) screen, 0x7B);
  func_8040E8D8_de(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  func_8041FF2C_de();
  config = D_80146398;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      func_80420308_de(i);
    }
  }

  func_802A2394_de();
  D_800E42D0->result = -1;
  return 0;
}
