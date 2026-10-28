#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/UNUSED.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "FRONTEND/8041BEA8_6.H"
#include "COMMON/ANIMATION.H"
#include "include_asm.h"
#include "MENU/CHARACTER_SELECTION_IDS.H"
#include "COMMON/WIDGETRECAT1A.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SCREEN.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "RENDER/8025DE50_5.H"

/* 8041F1FC.CPP */
#if defined(VERSION_US_REV1)
s32 CCharacterSelection_OpenCharacterSelectionScreen(s32 screen)
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
  Random_SetSelectedStage(0, 0);
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
    model = Key_GetCharacterPreviewModel(D_800E42D0->players[i].kind);
    row = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
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
  Random_SetSelectedStage(0, 0);
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
    model = Key_GetCharacterPreviewModel(D_800E42D0->players[i].kind);
    row = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
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
  Random_SetSelectedStage(0, 0);
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
    model = Key_GetCharacterPreviewModel(D_800E42D0->players[i].kind);
    row = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
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
  Random_SetSelectedStage(0, 0);
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
    model = Key_GetCharacterPreviewModel(D_800E42D0->players[i].kind);
    row = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
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
  Random_SetSelectedStage(0, 0);
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
    model = Key_GetCharacterPreviewModel(D_800E42D0->players[i].kind);
    row = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
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

/* 8041F1FC_2.CPP */
extern s32 Widget_ListHasFlag100(struct WidgetNode *);
extern struct WidgetNode *SmpOverlay_GetSlotValue(struct SlotsCode804196C0 *, s32);

/* Advances the selection panels, cursor highlight and character previews. */
s32 Character_UpdateCharacterPreview(s32 unusedFirst,s32 unusedSecond,s32 elapsedTicks) {
    CVector3 scale;
    f32 highlightAlpha;
    s16 resource;
    s32 previewModelOffset;
    s32 phase;
    s32 enterTicksRemaining;
    s32 exitTicksRemaining;
    s32 fadeTicksRemaining;
    s32 entryIndex;
    s32 i;
    s32 empty_slot;
    MenuWidget *highlight;
    MenuWidget *highlightWidget;
    MenuWidget *headerWidget;
    MenuWidget *footerWidget;
    MenuWidget *pulse;
    MenuWidget *header;
    MenuWidget *footer;
    struct WidgetNode *widgetNode;

    phase = D_800E42D0->phase;
    switch (phase) {
    case 1:
        header = D_800E42D0->header;
        header->x = (u16) (header->x + (u16)D_800E42D0->headerStep);
        footer = D_800E42D0->footer;
        footer->x = (u16) (footer->x - (u16)D_800E42D0->footerStep);
        enterTicksRemaining = D_800E42D0->timer - 1;
        D_800E42D0->timer = enterTicksRemaining;
        if (enterTicksRemaining <= 0) {
            SoundElement_PlayFlatSound(0xE79);
            Frontend_SetWidgetFlag08(D_800E42D0->promptItem, 1);
            SmpFlicker_StartFlicker(D_800E42D0->prompt, 4);
            D_800E42D0->phase = 4;
            D_800E42D0->timer = 4;
        }
        break;
    case 2:
        headerWidget = D_800E42D0->header;
        headerWidget->x = (u16) (headerWidget->x - (u16)D_800E42D0->headerStep);
        footerWidget = D_800E42D0->footer;
        footerWidget->x = (u16) (footerWidget->x + (u16)D_800E42D0->footerStep);
        exitTicksRemaining = D_800E42D0->timer - 1;
        D_800E42D0->timer = exitTicksRemaining;
        if (exitTicksRemaining <= 0) {
            D_800E42D0->phase = 3;
            MarkMenuEventHandled();
            SmXlate_SwitchScreen(D_800E42D0->result);
            return 0;
        }
        break;
    case 3:
        Tsmos_ActivateControllerState();
        break;
    case 4:
        D_800E42D0->timer = D_800E42D0->timer - 1 < 0 ? 0 :
            D_800E42D0->timer - 1 > D_800E42D0->timer ? D_800E42D0->timer : D_800E42D0->timer - 1;
        if ((D_800E42D0->timer <= 0) && (SmpFlicker_IsFlickerIdle(D_800E42D0->prompt) != 0)) {
            SmpFlicker_RestoreFlickerValue(D_800E42D0->prompt);
            D_800E42D0->phase = 6;
            D_800E42D0->timer = 4;
            Frontend_SetWidgetFlag08(D_800E42D0->pulse, 1);
        }
        break;
    case 5:
        SoundElement_PlayFlatSound(0xE78);
        D_800E42D0->phase = 2;
        D_800E42D0->timer = 4;
        Frontend_SetWidgetFlag08(D_800E42D0->promptItem, 0);
        Frontend_SetWidgetFlag08(D_800E42D0->pulse, 0);
        break;
    case 7: break;
    case 6:
        pulse = D_800E42D0->pulse;
        pulse->alpha = (u8) (pulse->alpha + (u8)D_800E42D0->pulseStep);
        fadeTicksRemaining = D_800E42D0->timer - 1;
        D_800E42D0->timer = fadeTicksRemaining;
        if (fadeTicksRemaining <= 0) {
            D_800E42D0->pulse->alpha = 0xC8;
            D_800E42D0->phase = 3;
        }
        break;
    }
        if (D_800E42D0->phase == 3) {
            i = 0;
            empty_slot = CHARACTER_EMPTY_SLOT;
            D_800E42D0->clock = (s32) (D_800E42D0->clock + elapsedTicks);
            do {
                if (D_800E42D0->players[i].unkC == 1) {
                    if (D_800E42D0->players[i].highlight != 0) {
                        highlightAlpha = (Math_Cosf((f32) i + ((f32) D_800E42D0->clock * 0.0033333334f)) * 70.0f) + 170.0f;
                        highlight = D_800E42D0->players[i].highlight;
                        highlight->alpha=(unsigned int)highlightAlpha;
                    }
                    widgetNode = SmpOverlay_GetSlotValue(D_800E42D0->unk4, i);
                    highlightWidget = D_800E42D0->players[i].highlight;
                    if ((highlightWidget->x != (widgetNode->x - 2)) || (highlightWidget->y != (widgetNode->y - 2))) {
                        SoundElement_PlayFlatSound(0xE7F);
                        if (Widget_ListHasFlag100(widgetNode) == 0) {
                            resource = widgetNode->resource;
                            if (resource != empty_slot) {
                                D_800E42D0->players[i].kind = (s32) resource;
                                previewModelOffset = Key_GetCharacterPreviewModel(resource);
                                entryIndex = Key_FindCharacterPreviewRow(D_800E42D0->players[i].kind);
                                scale.x = D_800E3A58[entryIndex].scale[i];
                                scale.y = D_800E3A58[entryIndex].scale[i];
                                scale.z = D_800E3A58[entryIndex].scale[i];
                                Frontend_InitModelPreview(D_800E42D0->players[i].model, 9, previewModelOffset + 0x38F, 0x4B, 0x5DC0, scale, D_800E3A58[entryIndex].position[i], D_800E3A58[entryIndex].distance[i], D_800E3A58[entryIndex].light[i]);
                            } else {
                                Menu_RandomizeCharacterPreview(i);
                            }
                        } else {
                            D_800E42D0->players[i].kind = -1;
                        }
                        Menu_RefreshPlayerCharacterVariants(i);
                    } else if (widgetNode->resource == empty_slot) {
                        Menu_RandomizeCharacterPreview(i);
                    }
                    D_800E42D0->players[i].highlight->x = (s16) ((u16) widgetNode->x - 2);
                    D_800E42D0->players[i].highlight->y = (s16) ((u16) widgetNode->y - 2);
                }
                i += 1;
            } while (i < 4);
        }
        return 0;
}
