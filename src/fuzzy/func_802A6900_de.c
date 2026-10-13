#include "types.h"
#include "gfx.h"

#include "gbi.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802A6AC0.h"

extern Gfx *D_80110634;
extern f32 D_800C5ED0_de, D_800C5ED4_de, D_800C5ED8_de, D_800C5EDC_de;
extern f32 D_800C5EE0_de, D_800C5EE4_de, D_800C5EE8_de, D_800C5EEC_de;
extern f32 D_800C5EF0_de, D_800C5EF4_de, D_800C5EF8_de, D_800C5EFC_de;
extern f32 D_800C5F00_de, D_800C5F04_de, D_800C5F08_de, D_800C5F0C_de;
extern s32 func_802AAC28_de(s32, s32, s16, s16, f32, f32, s32);

void func_802A6900_de(Menu_func_802A65E0_de *panel, Input_func_802A65E0_de *player) {
    MenuItem *sorted[4];
    s32 width;
    s32 height;
    MenuItem *slot;
    MenuItem *temp;
    MenuItem *first;
    MenuItem *second;
    f32 *view;
    s32 i;
    s32 swapped;
    s32 n;
    s16 magnitude;
    s32 pulse;
    s32 r,g,b;
    f32 spacing;
    f32 opacity;
    f32 sx,sy;
    f32 x,y;
    f32 unit;
    f32 colorScale;
    f32 quarter;
    f32 grid;
    f32 origin;
    f32 alpha;
    s32 row;
    f32 factor;

    spacing = 0.0f;
    for (i=0;i<4;i++) sorted[i]=&panel->items[i];
    do {
        swapped=0;
        for (i=0;i<3;i++) {
            first=sorted[i]; second=sorted[i+1];
            if ((u32)first->startFrame > (u32)second->startFrame) {
                swapped=1;
                sorted[i]=second;
                sorted[i+1]=first;
            }
        }
    } while (swapped);
    r=g=b=255;
    i=0; n=i;
    colorScale=D_800C5ED0_de;
    quarter=D_800C5ED4_de;
    grid=D_800C5ED8_de;
    origin=D_800C5EDC_de;
    unit=D_800C5EE4_de;

    view=player->view->viewport;
    sx=view[0] * D_800C5EE0_de;
    sy=view[1] * D_800C5EE8_de;
    for (i=0;i<4;i++) {
        slot=sorted[i];
        magnitude=slot->bounce;
        if ((f32)magnitude<0.0f) magnitude=-magnitude;
        if (slot->active && (slot->on || magnitude!=0)) {
            func_802AA950_de(slot->image,slot->imageFrame,&width,&height);
            if (width != 0) {
                if (magnitude != slot->bounce) factor=(f32)magnitude;
                else factor=(f32)(5-magnitude);
                opacity = factor * quarter;
                row=n/4;
                x=view[2] + view[0]*unit + ((origin - (f32)(n-row*4)*grid)+spacing)*unit*view[0];
                y=view[3] + view[1]*unit + (origin - (f32)(row))*unit*view[1];
                alpha=opacity*colorScale;
                gDPSetEnvColor(D_80110634++,r,g,b,alpha);
                func_802AAC28_de(slot->image,slot->imageFrame,
                    (s16)(s32)(x-(f32)width*sx*unit),
                    (s16)(s32)(y-(f32)height*sy*unit),sx,sy,1);
                n++;
                if (magnitude!=slot->bounce && opacity<grid) spacing += grid-opacity;
            }
        }
    }
    if (panel->state) {
        n=0;
        unit=D_800C5EF0_de;

        sx=view[0]*D_800C5EF8_de;
        colorScale=(f32)(panel->timer*51);
        sy=view[1]*D_800C5EFC_de;
        for(i=0;i<4;i++) {
            slot=&panel->items[i];
            if(slot->active) {
                func_802AA950_de(slot->image,slot->imageFrame,&width,&height);
                if(width!=0) {
                    row=n/4;
                x=view[2]+view[0]*unit+((2.0f*(f32)(n%4)*D_800C5F00_de)+D_800C5F04_de)*unit*view[0];
                    y=view[3]+view[1]*unit+((2.0f*(f32)(n/4))+D_800C5F08_de)*unit*view[1];
                    if(i==panel->selected) {
                        pulse=panel->blink;
                        if((f32)pulse<0.0f) pulse=-pulse;
                        r=255; g=255; b=255;
                        opacity=(f32)((pulse*191)/5+64)*D_800C5F0C_de;
                    } else {
                        r=128; g=128; b=128;
                        opacity=unit;
                    }
                    alpha=opacity*colorScale;
                gDPSetEnvColor(D_80110634++,r,g,b,alpha);
                    n++;
                    func_802AAC28_de(slot->image,slot->imageFrame,
                        (s16)(s32)(x-(f32)width*sx*unit),
                        (s16)(s32)(y-(f32)height*sy*unit),sx,sy,1);
                }
            }
        }
    }
}
