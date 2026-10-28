#include "TYPES.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/TRIPLE.H"
#include "GFX/TEXT/ONSCREEN_DRAWSCALEDMASKEDTILEGRID.H"

void func_8021EA54_de(PowerHudPlayer *player, Shared_HudView *view) {
    f32 sx,sy,numberScale,offset,halfWidth,x,y;
    sx=view->width/(f32)D_800E28D0;
    sy=view->height/(f32)D_800E28D4;
    if (Frontend_GetScreenMode()==0) {
        numberScale=D_800C25C4_de;
        offset=D_800C25C8_de;
    } else {
        numberScale=D_800C25CC_de;
        offset=D_800C25D0_de;
    }
    halfWidth=sx*D_800C25D4_de;
    if(player->first!=player->a.last || player->refreshA) {
        if(Frontend_GetScreenMode()==0) OnScreen_StartMoverScript(&player->a,D_800C9288_de);
        else OnScreen_StartMoverScript(&player->a,D_800C9288_de+12);
        player->refreshA=0;
        player->a.last=player->first;
    }
    if(player->second!=player->b.last || player->refreshB) {
        if(Frontend_GetScreenMode()==0) OnScreen_StartMoverScript(&player->b,D_800C9328_de-12);
        else OnScreen_StartMoverScript(&player->b,D_800C9328_de);
        player->refreshB=0;
        player->b.last=player->second;
    }
    if(player->third!=player->c.last || player->refreshC) {
        if(Frontend_GetScreenMode()==0) OnScreen_StartMoverScript(&player->c,D_800C9368);
        else OnScreen_StartMoverScript(&player->c,D_800C9398_de);
        player->refreshC=0;
        player->c.last=player->third;
    }
    if(func_8022AB9C_de(player)!=-1) {
        if(player->a.object && player->a.state && player->weapon<18) {
            x=player->a.x*sx+view->x;
            y=player->a.y*sy+view->y+view->height;
            x+=offset;
            OnScreen_DrawSpriteResource(0xBEA,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25D8_de),sx,sy,1);
            x-=sx*D_800C25DC_de;
            y-=sy*D_800C25E0_de;
            OnScreen_DrawSpriteNumber(player->first,x,y,sx*numberScale,sy,1,0,0);
        }
        if(player->b.object && player->b.state && player->weapon<18) {
            x=player->b.x*sx+view->x;
            y=player->b.y*sy+view->y+view->height;
            x+=offset;
            OnScreen_DrawSpriteResource(0xBEB,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25E4_de),sx,sy,1);
            x-=sx*D_800C25E8_de;
            y-=sy*D_800C25EC_de;
            OnScreen_DrawSpriteNumber(player->second,x,y,sx*numberScale,sy,1,0,0);
        }
        if(player->c.object && player->c.state && player->weapon<18) {
            x=player->c.x*sx+view->x;
            y=player->c.y*sy+view->y+view->height;
            x+=offset;
            OnScreen_DrawSpriteResource(0xBEC,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25F0_de),sx,sy,1);
            x-=sx*D_800C25F4_de;
            y-=sy*D_800C25F8_de;
            OnScreen_DrawSpriteNumber(player->third,x,y,sx*numberScale,sy,1,0,0);
        }
    }
}
