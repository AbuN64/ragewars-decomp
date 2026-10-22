#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/SHARED_OPTIONSSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "COMMON/TRIPLE.H"
#include "MENU_2/80400000_15.H"
#include "MENU_2/80400000_5.H"
#include "MENU_2/80400000_6.H"

#include "COMMON/GAME_SESSION.H"
extern void func_8029311C_de(void *,u8 *,s32,s32,s32,s32);
static inline u32 toUnsigned(f32 v,f32 limit) { u32 result; if(!(limit<=v)) result=(u32)(s32)v; else { v-=limit; result=(u32)(s32)v; result|=0x80000000; } return result; }
static inline f32 unsignedWidth(u32 v) { f64 d=(s32)v; if((s32)v<0)d+=D_800DCC30; return (f32)d; }
static inline f32 unsignedHeight(u32 v) { f64 d=(s32)v; if((s32)v<0)d+=D_800DCC40_de; return (f32)d; }
void func_80402BA0_de(ScreenRectangle *rectangle) {
    CVector3 color,baseColor;
    u8 rgba[4];
    u32 width,height,right,bottom;
    f32 alpha,scale,value;
    if(D_800E2830->active) {
        value=rectangle->width;
        if(!(((f32 *)&D_800DCC28)[-1]<=value)) width=(u32)(s32)value;
        else {value-=((f32 *)&D_800DCC28)[-1]; width=(u32)(s32)value; width|=0x80000000;}
        value=rectangle->height;
        if(!(D_800DCC28<=value)) height=(u32)(s32)value;
        else {value-=D_800DCC28; height=(u32)(s32)value; height|=0x80000000;}
        value=unsignedWidth(width)+rectangle->x;
        if(!(((f32 *)&D_800DCC30)[2]<=value)) right=(u32)(s32)value;
        else {value-=((f32 *)&D_800DCC30)[2]; right=(u32)(s32)value; right|=0x80000000;}
        value=unsignedHeight(height)+rectangle->y;
        if(!(D_800DCC48_de<=value)) bottom=(u32)(s32)value;
        else {value-=D_800DCC48_de; bottom=(u32)(s32)value; bottom|=0x80000000;}
        baseColor=func_80401564_de(D_800E2830->time);
        alpha=func_8040170C_de(D_800E2830->time);
        color=baseColor;
        if(D_800E2830->unknown60) {
            scale=D_800E2830->fade;
            if(scale<0.0f)scale=0.0f;
            color.x=baseColor.x*scale;
            color.y=baseColor.y*scale;
            color.z=baseColor.z*scale;
            alpha+=D_800DCC4C_de-scale;
        }
        value=color.x*((f32 *)&D_800DCC4C_de)[1];
        if(!(value<=((f32 *)&D_800DCC4C_de)[1]))value=((f32 *)&D_800DCC4C_de)[1];
        if(!(0.0f<=value))value=0.0f;
        rgba[0]=(u8)toUnsigned(value,((f32 *)&D_800DCC58_de)[-1]);
        value=color.y*D_800DCC58_de;
        if(!(value<=D_800DCC58_de))value=D_800DCC58_de;
        if(!(0.0f<=value))value=0.0f;
        rgba[1]=(u8)toUnsigned(value,((f32 *)&D_800DCC58_de)[1]);
        value=color.z*D_800DCC60;
        if(!(value<=D_800DCC60))value=D_800DCC60;
        if(!(0.0f<=value))value=0.0f;
        rgba[2]=(u8)toUnsigned(value,((f32 *)&D_800DCC60)[1]);
        value=alpha*((f32 *)&D_800DCC60)[2];
        if(!(value<=((f32 *)&D_800DCC60)[2]))value=((f32 *)&D_800DCC60)[2];
        if(!(0.0f<=value))value=0.0f;
        rgba[3]=(u8)toUnsigned(value,((f32 *)&D_800DCC4C_de)[8]);
        value=0.0f;
        func_8029311C_de(&D_8011FAC0,rgba,width,height,right,bottom);
    }
    if(D_800DE7F4_de)func_8040293C_de();
}
