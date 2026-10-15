#include "types.h"
#include "common/types_8a8189af7b05.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_8021CD70.h"
#include "resident_event_handler.h"
#include "shared/func_80214624_de_closed.h"
#include "shared/func_8021E2A0_de_closed.h"
#include "shared/func_8027AD4C_de_closed.h"
#include "span_1000/code_80225D10.h"
extern void func_802231D4_de(void *,void *,void *);
extern s32 func_80214178_de(void *,void *,s32);
extern void func_80274870_de(f32 *value, f32 target, f32 rate);
extern f32 D_800C9514_de;
extern f32 D_800C9FE8;
extern Triple D_800C94DC_de;
extern f32 D_800C2AF4_de,D_800C2AF8_de,D_800C2AFC_de,D_800C2B00_de,D_800C2B04_de,D_800C2B08_de,D_800C2B0C_de,D_800C2B10_de,D_800C2B14_de,D_800C2B18_de,D_800C2B1C_de,D_800C2B20_de,D_800C2B24_de,D_800C2B28_de,D_800C2B2C_de,D_800C2B30_de;
void func_80225F44_de(SharedPlayer_func_802233F0_de *player,func_802165F8_S1 *body) {
    Matrix rotation;
    struct Mount *mount;
    Vec3 *offset;
    SharedMovement *movement;
    f32 wave,yaw,unit,forward,side,bump,result,force,absolute,sway,rawForward,rawSide,time;
    mount=player->views5E8.view80C_108.mount;
    wave=func_802B6560_de(player->views5E8.view838_114.rideTime*D_800C2AF4_de);
    wave=(((wave+D_800C2AF8_de)*D_800C2AFC_de+D_800C2B00_de)*D_800C2B04_de);
    time=player->views5E8.view838_114.rideTime;
    sway=player->views5E8.view69C_40.stick; sway*=wave;
    time+=D_800D2988;player->views5E8.view838_114.rideTime=time;
    unit=D_800C2B08_de;
    yaw=body->unk6C;
    sway*=unit;force=yaw+sway;
    func_80274870_de(&body->unk6C,force,0.9f);
    yaw=((yaw-body->unk6C)+player->views5E8.view69C_40.stick*D_800C2B0C_de)*unit;
    func_80274870_de(&player->views5E8.view72C_76.kickRoll,yaw,0.1f);
    func_802231D4_de(player,body,&D_800C95D0);
    offset=0;
    if(player->views5E8.view6B8_50.input&8) {
        func_80214178_de(mount,&mount->animation,0x2e);
        player->views5E8.view704_68.lift=D_800C2B10_de;
        player->views5E8.view6C0_51.unk6C0=D_800C9514_de+D_800C9514_de;
    }
    absolute=player->views5E8.view6C0_51.unk6C0;
    bump=player->views5E8.view83C_116.bump;
    if(absolute<0.0f)absolute=-absolute;
    side=2.0f*player->views5E8.view6C4_54.unk6C4;
    if(side<0.0f ? -side<absolute : side<absolute) {
        rawForward=player->views5E8.view6C0_51.unk6C0;
        if(rawForward<0.0f)result=bump-rawForward;
        else result=bump+rawForward;
    } else {
        rawSide=2.0f*player->views5E8.view6C4_54.unk6C4;
        if(rawSide<0.0f)result=bump-rawSide;
        else result=bump+rawSide;
    }
    player->views5E8.view83C_116.bump=result;
    if(D_800C9FE8<result) {
        player->views5E8.view83C_116.bump=result-D_800C9FE8;
        if(mount->animationId!=0x2e) {
            player->views5E8.view6C0_51.unk6C0*=D_800C2B14_de;
            player->views5E8.view6C4_54.unk6C4*=D_800C2B14_de;
        }
        forward=player->views5E8.view6C0_51.unk6C0;
        if(forward<0.0f)force=-forward*D_800C2B18_de;
        else force=forward*D_800C2B1C_de;
        if(D_800C2B20_de<force)force=D_800C2B20_de;
        if(player->views5DC.view5DC_6.storage)func_80239324_de(player->views5DC.view5DC_6.storage,0.0f,force,0.0f,D_800C2B24_de,1,body->unk8);
    }
    if(0.0f<player->views5E8.view6C0_51.unk6C0)func_802233F0_de(player,body,&D_800C9510_de[0]);
    else func_802233F0_de(player,body,&D_800C9510_de[1]);
    forward=player->views5E8.view6C0_51.unk6C0;
    if(forward<0.0f ? D_800C2B28_de < -forward : D_800C2B2C_de < forward)player->views5E8.view704_68.lift=D_800C2B30_de;
    if(player->views5E8.view810_110.kind==0x136) {
        offset=&D_800C94D0_de;
        player->views5E8.view814_112.offset=D_800C94DC_de;
    }
    if(offset) {
        func_802736D4_de(&rotation,body->unk6C);
        func_80272898_de(&rotation,offset,&player->views5E8.view73C_82.weapon);
        func_80271F9C_de(&player->views5E8.view73C_82.weapon,&player->views5E8.view73C_82.weapon,10.24f);
    }
}
