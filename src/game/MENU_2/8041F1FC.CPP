#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"
#include "include_asm.h"

#if defined(VERSION_US_REV1)
s32 func_8041F2A0_us_rev1(s32 screen)
{
  CVector3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = Cache_AllocateMemory(0x1358);
  D_800E42D0->screen = (void *) screen;
  D_800E42D0->unk4 = SmpOverlay_CreateOverlayNode(screen, 4);
  SmpOverlay_ShowSlotById(screen, 0, 0x7A);
  SmpOverlay_ShowSlotById(screen, 1, 0x7A);
  SmpOverlay_ShowSlotById(screen, 2, 0x7A);
  SmpOverlay_ShowSlotById(screen, 3, 0x7A);
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
    Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = Frontend_FindWidgetByResourceId((void *) screen, 0xAC);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = Frontend_FindWidgetByResourceId((void *) screen, 0x93);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  Frontend_FindWidgetByResourceId((void *) screen, 0x76)->alpha = 0x6E;
  Frontend_FindWidgetByResourceId((void *) screen, 0x79)->alpha = 0x19;
  D_800E42D0->prompt = SmpFlicker_CreateFlickerWidget(0x74, 0xFF);
  item = Frontend_FindWidgetByResourceId((void *) screen, 0x74);
  D_800E42D0->promptItem = item;
  Frontend_SetWidgetFlag08(item, 0);
  D_800E42D0->pulse = Frontend_FindWidgetByResourceId((void *) screen, 0x7B);
  Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  Menu_RefreshCharacterUnlocks();
  config = g_playerSettings;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      Menu_ShowPlayerCharacterSelection(i);
    }
  }

  Tsmos_DeactivateControllerState();
  D_800E42D0->result = -1;
  return 0;
}
#endif

#if defined(VERSION_US)
extern float D_800E1570;
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"

s32 func_8041F2A0_us(void *screen)
{
  CVector3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = Cache_AllocateMemory(0x1358);
  D_800E42D0->screen = screen;
  D_800E42D0->unk4 = SmpOverlay_CreateOverlayNode((s32) screen, 4);
  SmpOverlay_ShowSlotById((s32) screen, 0, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 1, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 2, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 3, 0x7a);
  func_8042E9A0_de(0, 0);
  D_800E42D0->clock = 0;
  scale.x = D_800E1570;
  scale.y = D_800E1570;
  scale.z = D_800E1570;
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
    Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = Frontend_FindWidgetByResourceId(screen, 0xac);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = Frontend_FindWidgetByResourceId(screen, 0x93);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  Frontend_FindWidgetByResourceId(screen, 0x76)->alpha = 0x6E;
  Frontend_FindWidgetByResourceId(screen, 0x79)->alpha = 0x19;
  D_800E42D0->prompt = SmpFlicker_CreateFlickerWidget(0x74, 0xFF);
  item = Frontend_FindWidgetByResourceId(screen, 0x74);
  D_800E42D0->promptItem = item;
  Frontend_SetWidgetFlag08(item, 0);
  D_800E42D0->pulse = Frontend_FindWidgetByResourceId(screen, 0x7b);
  Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  Menu_RefreshCharacterUnlocks();
  config = g_playerSettings;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      Menu_ShowPlayerCharacterSelection(i);
    }
  }

  Tsmos_DeactivateControllerState();
  D_800E42D0->result = -1;
  return 0;
}
#endif

#if defined(VERSION_EU)
extern float D_800E1570;
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"

s32 func_8041F6E0_eu(void *screen)
{
  CVector3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = Cache_AllocateMemory(0x1358);
  D_800E42D0->screen = screen;
  D_800E42D0->unk4 = SmpOverlay_CreateOverlayNode((s32) screen, 4);
  SmpOverlay_ShowSlotById((s32) screen, 0, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 1, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 2, 0x7a);
  SmpOverlay_ShowSlotById((s32) screen, 3, 0x7a);
  func_8042E9A0_de(0, 0);
  D_800E42D0->clock = 0;
  scale.x = D_800E1570;
  scale.y = D_800E1570;
  scale.z = D_800E1570;
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
    Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = Frontend_FindWidgetByResourceId(screen, 0xac);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = Frontend_FindWidgetByResourceId(screen, 0x93);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  Frontend_FindWidgetByResourceId(screen, 0x76)->alpha = 0x6E;
  Frontend_FindWidgetByResourceId(screen, 0x79)->alpha = 0x19;
  D_800E42D0->prompt = SmpFlicker_CreateFlickerWidget(0x74, 0xFF);
  item = Frontend_FindWidgetByResourceId(screen, 0x74);
  D_800E42D0->promptItem = item;
  Frontend_SetWidgetFlag08(item, 0);
  D_800E42D0->pulse = Frontend_FindWidgetByResourceId(screen, 0x7b);
  Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  Menu_RefreshCharacterUnlocks();
  config = g_playerSettings;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      Menu_ShowPlayerCharacterSelection(i);
    }
  }

  Tsmos_DeactivateControllerState();
  D_800E42D0->result = -1;
  return 0;
}
#endif

#if defined(VERSION_EU_X)
extern float D_800E1570;
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"

s32 func_8041F6E0_eu_x(void *screen)
{
  CVector3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = Cache_AllocateMemory(0x1358);
  D_800E42D0->screen = screen;
  D_800E42D0->unk4 = SmpOverlay_CreateOverlayNode((s32) screen, 4);
  SmpOverlay_ShowSlotById((s32) screen, 0, 0x7e);
  SmpOverlay_ShowSlotById((s32) screen, 1, 0x7e);
  SmpOverlay_ShowSlotById((s32) screen, 2, 0x7e);
  SmpOverlay_ShowSlotById((s32) screen, 3, 0x7e);
  func_8042E9A0_de(0, 0);
  D_800E42D0->clock = 0;
  scale.x = D_800E1570;
  scale.y = D_800E1570;
  scale.z = D_800E1570;
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
    Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = Frontend_FindWidgetByResourceId(screen, 0xb0);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = Frontend_FindWidgetByResourceId(screen, 0x97);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  Frontend_FindWidgetByResourceId(screen, 0x7a)->alpha = 0x6E;
  Frontend_FindWidgetByResourceId(screen, 0x7d)->alpha = 0x19;
  D_800E42D0->prompt = SmpFlicker_CreateFlickerWidget(0x78, 0xFF);
  item = Frontend_FindWidgetByResourceId(screen, 0x78);
  D_800E42D0->promptItem = item;
  Frontend_SetWidgetFlag08(item, 0);
  D_800E42D0->pulse = Frontend_FindWidgetByResourceId(screen, 0x7f);
  Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  Menu_RefreshCharacterUnlocks();
  config = g_playerSettings;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      Menu_ShowPlayerCharacterSelection(i);
    }
  }

  Tsmos_DeactivateControllerState();
  D_800E42D0->result = -1;
  return 0;
}
#endif

#if defined(VERSION_DE)
extern float D_800E1570;
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"

s32 func_8041F230_de(void *screen)
{
  CVector3 scale;
  s32 j;
  s32 i;
  s32 model;
  s32 row;
  func_8041F2A0_Config *config;
  func_8041F2A0_Item *item;
  s32 rest;
  D_800E42D0 = Cache_AllocateMemory(0x1358);
  D_800E42D0->screen = screen;
  D_800E42D0->unk4 = SmpOverlay_CreateOverlayNode((s32) screen, 4);
  SmpOverlay_ShowSlotById((s32) screen, 0, 0x78);
  SmpOverlay_ShowSlotById((s32) screen, 1, 0x78);
  SmpOverlay_ShowSlotById((s32) screen, 2, 0x78);
  SmpOverlay_ShowSlotById((s32) screen, 3, 0x78);
  func_8042E9A0_de(0, 0);
  D_800E42D0->clock = 0;
  scale.x = D_800E1570;
  scale.y = D_800E1570;
  scale.z = D_800E1570;
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
    Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, model + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[row].position[i], D_800E3A58[row].distance[i], D_800E3A58[row].light[i]);
    Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].title)->alpha = 0x6E;
    for (j = 0; j < 3; j++)
    {
      Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].cells[j].id)->alpha = 0x50;
      Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E42D0->screen, D_800E42D4[i].options[j].id), 1);
    }

  }

  D_800E42D0->phase = 1;
  D_800E42D0->timer = 4;
  D_800E42D0->header = Frontend_FindWidgetByResourceId(screen, 0xaa);
  D_800E42D0->header->x -= D_800E42D0->header->w;
  D_800E42D0->headerStep = D_800E42D0->header->w / 4;
  rest = D_800E42D0->header->w - (D_800E42D0->headerStep * 4);
  D_800E42D0->header->x += rest;
  D_800E42D0->footer = Frontend_FindWidgetByResourceId(screen, 0x91);
  D_800E42D0->footer->x += D_800E42D0->footer->w;
  D_800E42D0->footerStep = D_800E42D0->footer->w / 4;
  rest = D_800E42D0->footer->w - (D_800E42D0->footerStep * 4);
  D_800E42D0->footer->x -= rest;
  Frontend_FindWidgetByResourceId(screen, 0x74)->alpha = 0x6E;
  Frontend_FindWidgetByResourceId(screen, 0x77)->alpha = 0x19;
  D_800E42D0->prompt = SmpFlicker_CreateFlickerWidget(0x72, 0xFF);
  item = Frontend_FindWidgetByResourceId(screen, 0x72);
  D_800E42D0->promptItem = item;
  Frontend_SetWidgetFlag08(item, 0);
  D_800E42D0->pulse = Frontend_FindWidgetByResourceId(screen, 0x79);
  Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
  D_800E42D0->pulse->alpha = 0;
  D_800E42D0->pulseStep = 0x32;
  Menu_RefreshCharacterUnlocks();
  config = g_playerSettings;
  for (i = 0; i < 4; i++)
  {
    if (config[i].active == 1)
    {
      Menu_ShowPlayerCharacterSelection(i);
    }
  }

  Tsmos_DeactivateControllerState();
  D_800E42D0->result = -1;
  return 0;
}
#endif
