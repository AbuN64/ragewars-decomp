#include "WEAPONS/PLAYER_MOVEMENT_INTERFACES.H"
#include "include_asm.h"
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/APPROACHLOCATION.H"
#include "COMMON/EXTERNS_6.H"
#include "COMMON/BALLISTICPARAMS.H"
#include "COMMON/OBJRECV5.H"
#include "GAME/CODE_8027302C.H"
extern s32 Actor_RequestActorState(void *arg0, void *arg1, s32 arg2);
extern void Graphu64_TransformPoint(void *arg0, void *arg1, void *arg2);

#include "TYPES.H"
#include "WEAPONS/80213ED4.H"
#include "particle/80271B18_3.H"

typedef struct { f32 x, y, z; } Position;
typedef struct { u8 pad0[0x34]; Position pos; f32 height; u8 pad44[0x1A]; u8 duration; } TravelTarget;
typedef struct { u8 pad0[0x6C]; f32 yaw; u8 pad70[0x2E4]; f32 bodyYaw; u8 pad358[0x390]; Position pos; u8 pad6F4[0x100]; f32 elapsed, targetYaw; TravelTarget *target; Position start; } TravelPlayer;
extern f32 D_800C2AE0_de, D_800C2AE4_de, D_800C2AE8_de, D_800C2AEC_de, D_800C2AF0_de;

extern void Player_UpdateViewAngles(void *, void *, void *);

void func_80225D34_de(TravelPlayer *player, void *body) {
    f32 yaw, targetYaw, distance, otherDistance, alternate, duration, t;
    Position pos;
    Player_UpdateViewAngles(player, body, &D_800CE7E4);
    if (player->target != 0) {
        player->elapsed += D_800D2988;
        yaw = player->yaw;
        targetYaw = player->targetYaw;
        if (targetYaw != yaw) {
            Graphu64_WrapPeriodicValue(&yaw);
            Graphu64_WrapPeriodicValue(&targetYaw);
            if (yaw > targetYaw) {
                alternate = targetYaw + D_800C2AE0_de;
                if (alternate - yaw < yaw - targetYaw) targetYaw = alternate;
            } else {
                alternate = targetYaw - D_800C2AE4_de;
                if (yaw - alternate < targetYaw - yaw) targetYaw = alternate;
            }
            if (targetYaw > yaw) {
                yaw += (targetYaw - yaw) * D_800C2AE8_de;
                if (targetYaw < yaw) yaw = targetYaw;
            } else {
                yaw -= (yaw - targetYaw) * D_800C2AEC_de;
                if (yaw < targetYaw) yaw = targetYaw;
            }
            Graphu64_WrapPeriodicValue(&yaw);
        }
        player->bodyYaw = yaw;
        player->yaw = yaw;
        duration = (f32)(player->target->duration * 15);
        if (player->elapsed < duration) {
            t = player->elapsed / duration;
            pos.x = player->start.x + (player->target->pos.x - player->start.x) * t;
            pos.z = player->start.z + (player->target->pos.z - player->start.z) * t;
            pos.y = player->start.y + (player->target->pos.y - player->start.y) * t + player->target->height * ((t - t * t) * D_800C2AF0_de);
            player->pos = pos;
            return;
        }
    }
    Player_SetPlayerState(player, body, 2);
}

extern void Player_UpdateViewAngles(void *,void *,void *);
extern void Graphu64_EaseValueToward(f32 *value, f32 target, f32 rate);
extern f32 D_800C9514_de;
extern f32 D_800C9FE8;
extern Triple D_800C94DC_de;
extern f32 D_800C2AF4_de,D_800C2AF8_de,D_800C2AFC_de,D_800C2B00_de,D_800C2B04_de,D_800C2B08_de,D_800C2B0C_de,D_800C2B10_de,D_800C2B14_de,D_800C2B18_de,D_800C2B1C_de,D_800C2B20_de,D_800C2B24_de,D_800C2B28_de,D_800C2B2C_de,D_800C2B30_de;
void func_80225F44_de(SharedPlayer *player,func_802165F8_S1 *body) {
    Matrix rotation;
    struct Mount *mount;
    CVector3 *offset;
    SharedMovement *movement;
    f32 wave,yaw,unit,forward,side,bump,result,force,absolute,sway,rawForward,rawSide,time;
    mount=player->views5E8.view80C_108.mount;
    wave=Math_Cosf(player->views5E8.view838_114.rideTime*D_800C2AF4_de);
    wave=(((wave+D_800C2AF8_de)*D_800C2AFC_de+D_800C2B00_de)*D_800C2B04_de);
    time=player->views5E8.view838_114.rideTime;
    sway=player->views5E8.view69C_40.stick; sway*=wave;
    time+=D_800D2988;player->views5E8.view838_114.rideTime=time;
    unit=D_800C2B08_de;
    yaw=body->unk6C;
    sway*=unit;force=yaw+sway;
    Graphu64_EaseValueToward(&body->unk6C,force,0.9f);
    yaw=((yaw-body->unk6C)+player->views5E8.view69C_40.stick*D_800C2B0C_de)*unit;
    Graphu64_EaseValueToward(&player->views5E8.view72C_76.kickRoll,yaw,0.1f);
    Player_UpdateViewAngles(player,body,&D_800C95D0);
    offset=0;
    if(player->views5E8.view6B8_50.input&8) {
        Actor_RequestActorState(mount,&mount->animation,0x2e);
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
        if(player->views5DC.view5DC_6.storage)Gsky_StartScaledShake(player->views5DC.view5DC_6.storage,0.0f,force,0.0f,D_800C2B24_de,1,body->unk8);
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
        BuildYawMatrix(&rotation,body->unk6C);
        Graphu64_TransformPoint(&rotation,offset,&player->views5E8.view73C_82.weapon);
        GraphU64_ScaleVector(&player->views5E8.view73C_82.weapon,&player->views5E8.view73C_82.weapon,10.24f);
    }
}
