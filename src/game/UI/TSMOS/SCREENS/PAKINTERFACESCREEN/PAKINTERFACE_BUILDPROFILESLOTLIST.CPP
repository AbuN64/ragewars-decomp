#include "TYPES.H" /* the draft_fields struct headers below spell s32/u16/u8; types.h must precede them */
#include "FRONTEND/PAKMENU.H"
#include "COMMON/MEASUREDRECAT0V1.H"
#include "COMMON/MEASURED.H"
#include "COMMON/MEASUREDRECAT14V4.H"
#include "COMMON/MEASUREDRECAT14V2.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/GFX.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/LOADOUT.H"
#include "COMMON/OWNERRECAT8V2.H"
#include "COMMON/GROUP.H"
#include "COMMON/OBJECTLINKS180_2.H"
#include "COMMON/MANAGER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/LIGHTDATA.H"
#include "COMMON/OBJECTSTATE18.H"
#include "COMMON/MTX.H"
#include "COMMON/OBJECTLINKS1E8.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/RESULTS.H"
#include "COMMON/OBJRECAT26DD8.H"
#include "COMMON/INTEGERSTATE530.H"
#include "COMMON/OBJRECAT18V6.H"
#include "COMMON/ALBANK_S.H"
#include "COMMON/OBJRECAT18V1.H"
#include "COMMON/ALPARAM_S.H"
#include "COMMON/ALDELAY28.H"
#include "COMMON/OSPIHANDLE_S.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/CTX.H"
#include "COMMON/ALLOADFILTER48_2.H"
#include "COMMON/CHEATCODE.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/NODERECAT2A8.H"
#include "COMMON/SLOTRECATCV1.H"
#include "COMMON/TEXTURE.H"
#include "COMMON/LABEL.H"
#include "COMMON/CHARACTERSELECTIONROOT.H"
#include "COMMON/STATERECAT91.H"
#include "COMMON/RESULTSOPTIONSSCREEN.H"
#include "COMMON/SETTINGSRECAT24.H"
#include "COMMON/OBJB.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARGB_COLOR.H"
#include "COMMON/REQUESTRECAT10.H"
#include "COMMON/S1_5.H"
#include "COMMON/OBJECTRECAT28.H"
#include "COMMON/PLAYERRECAT64E.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SELECTIONSCREENSTATE.H"
#include "COMMON/NAME.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_62.H"

/* Initializes four player-menu slots and selects the first available child node. */

#if defined(VERSION_DE)
enum { PAK_SLOT_RESOURCE_688 = 716, PAK_SLOT_RESOURCE_689 = 713, PAK_SLOT_RESOURCE_690 = 714, PAK_SLOT_RESOURCE_691 = 715, PAK_SLOT_RESOURCE_692 = 712, PAK_SLOT_RESOURCE_694 = 718 };
#elif defined(VERSION_EU)
enum { PAK_SLOT_RESOURCE_688 = 688, PAK_SLOT_RESOURCE_689 = 689, PAK_SLOT_RESOURCE_690 = 690, PAK_SLOT_RESOURCE_691 = 691, PAK_SLOT_RESOURCE_692 = 692, PAK_SLOT_RESOURCE_694 = 694 };

extern void *D_800E1394[];
extern void *D_800DD124[];

#elif defined(VERSION_EU_X)
enum { PAK_SLOT_RESOURCE_688 = 764, PAK_SLOT_RESOURCE_689 = 761, PAK_SLOT_RESOURCE_690 = 762, PAK_SLOT_RESOURCE_691 = 760, PAK_SLOT_RESOURCE_692 = 763, PAK_SLOT_RESOURCE_694 = 766 };

extern void *D_800E1394[];
extern void *D_800DD124[];

#else
enum { PAK_SLOT_RESOURCE_688 = 688, PAK_SLOT_RESOURCE_689 = 689, PAK_SLOT_RESOURCE_690 = 690, PAK_SLOT_RESOURCE_691 = 691, PAK_SLOT_RESOURCE_692 = 692, PAK_SLOT_RESOURCE_694 = 694 };

#endif
extern void Widget_SetWidgetFlag100(MenuWidget *record, int enable);
extern void SmpOverlay_ShowSlotNode(s32,s32,MenuWidget *);
extern MenuWidget *SmpOverlay_GetSlotValue(s32,s32);
extern s32 Widget_ListHasFlag100(MenuWidget *);
void PAKInterface_BuildProfileSlotList(s32 player) {
 s32 i;
 MenuWidget *label,*value;
 D_800E54A4->players[player].chosen=0;
 /* the hub EC30 returns the item view; nodes[] hold this unit's MenuWidget storage */
 D_800E54A4->players[player].nodes[0]=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_694);
 D_800E54A4->players[player].nodes[1]=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_691);
 D_800E54A4->players[player].nodes[2]=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_688);
 D_800E54A4->players[player].nodes[3]=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].menuWidget,PAK_SLOT_RESOURCE_692);
 for(i=0;i<4;i++) {
  D_800E54A4->players[player].used[i]=2;
  D_800E54A4->players[player].nodes[i]->alpha=255;
  label=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689);
  Widget_SetWidgetFlag100(D_800E54A4->players[player].nodes[i],0);
  value=(MenuWidget *)Frontend_FindWidgetByResourceId(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_690);
  if(D_800E54A4->players[player].records[i].player!=-1) {
   value->text=D_800E54A4->players[player].records[i].name;
   D_800E54A4->players[player].used[i]=1;
   if(D_800E54A4->phase==1) {
    Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689),0);
    if(Frontend_FindProfileOwner(D_800E54A4->players[player].profile,D_800E54A4->players[player].records[i].owner)!=-1) {
     D_800E54A4->players[player].used[i]=0;
     Widget_SetWidgetFlag100(D_800E54A4->players[player].nodes[i],1);
     Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId(D_800E54A4->players[player].nodes[i],PAK_SLOT_RESOURCE_689),1);
    }
   }
#if defined(VERSION_EU)
  } else {value->text=((D_800E1394)[g_languageIndex]);Frontend_SetWidgetFlag08((func_8041F2A0_Item *)label,0);}
#elif defined(VERSION_EU_X)
  } else {value->text=((D_800DD124)[g_languageIndex]);Frontend_SetWidgetFlag08((func_8041F2A0_Item *)label,0);}
#else
  } else {value->text=(D_800D3250[0]);Frontend_SetWidgetFlag08((func_8041F2A0_Item *)label,0);}
#endif
 }
 label=SmpOverlay_GetSlotValue(D_800E54A4->root,player);
 while(Widget_ListHasFlag100(label))label=label->next;
 SmpOverlay_ShowSlotNode(D_800E54A4->root,player,label);
}
