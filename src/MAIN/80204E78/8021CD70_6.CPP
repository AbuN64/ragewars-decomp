#include "TYPES.H"
#include "common/types_1dc8418c21db.h"
#include "resident_event_handler.h"
#include "shared/func_802453D4_de_closed.h"
#include "span_1000/code_8021CD70.h"
#include "span_C76B0/data.h"
extern s32 func_802AAC28_de(s32,s32,s16,s16,f32,f32,s32);

void func_8021EA54_de(PowerHudPlayer *player, Shared_HudView *view) {
    f32 sx,sy,numberScale,offset,halfWidth,x,y;
    sx=view->width/(f32)D_800E28D0;
    sy=view->height/(f32)D_800E28D4;
    if (func_8040C474_de()==0) {
        numberScale=D_800C25C4_de;
        offset=D_800C25C8_de;
    } else {
        numberScale=D_800C25CC_de;
        offset=D_800C25D0_de;
    }
    halfWidth=sx*D_800C25D4_de;
    if(player->first!=player->a.last || player->refreshA) {
        if(func_8040C474_de()==0) func_802AA70C_de(&player->a,D_800C9288_de);
        else func_802AA70C_de(&player->a,D_800C9288_de+12);
        player->refreshA=0;
        player->a.last=player->first;
    }
    if(player->second!=player->b.last || player->refreshB) {
        if(func_8040C474_de()==0) func_802AA70C_de(&player->b,D_800C9328_de-12);
        else func_802AA70C_de(&player->b,D_800C9328_de);
        player->refreshB=0;
        player->b.last=player->second;
    }
    if(player->third!=player->c.last || player->refreshC) {
        if(func_8040C474_de()==0) func_802AA70C_de(&player->c,D_800C9368);
        else func_802AA70C_de(&player->c,D_800C9398_de);
        player->refreshC=0;
        player->c.last=player->third;
    }
    if(func_8022AB9C_de(player)!=-1) {
        if(player->a.object && player->a.state && player->weapon<18) {
            x=player->a.x*sx+view->x;
            y=player->a.y*sy+view->y+view->height;
            x+=offset;
            func_802AAC28_de(0xBEA,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25D8_de),sx,sy,1);
            x-=sx*D_800C25DC_de;
            y-=sy*D_800C25E0_de;
            func_802A822C_de(player->first,x,y,sx*numberScale,sy,1,0,0);
        }
        if(player->b.object && player->b.state && player->weapon<18) {
            x=player->b.x*sx+view->x;
            y=player->b.y*sy+view->y+view->height;
            x+=offset;
            func_802AAC28_de(0xBEB,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25E4_de),sx,sy,1);
            x-=sx*D_800C25E8_de;
            y-=sy*D_800C25EC_de;
            func_802A822C_de(player->second,x,y,sx*numberScale,sy,1,0,0);
        }
        if(player->c.object && player->c.state && player->weapon<18) {
            x=player->c.x*sx+view->x;
            y=player->c.y*sy+view->y+view->height;
            x+=offset;
            func_802AAC28_de(0xBEC,0,(s16)(x-halfWidth),(s16)(y-sy*D_800C25F0_de),sx,sy,1);
            x-=sx*D_800C25F4_de;
            y-=sy*D_800C25F8_de;
            func_802A822C_de(player->third,x,y,sx*numberScale,sy,1,0,0);
        }
    }
}
