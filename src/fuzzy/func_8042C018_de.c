#include "span_16E000/code_8042BD40.h"
#include "shared/results_screen_text.h"
#include "shared/func_8041F2A0_us_rev1_closed.h"
#include "span_16E000/code_804264F0.h"
extern func_8042CE54_S1 *D_800E53C0;
extern ResourceBank D_800E12D2[],D_800E12D6[],D_800E12DA[],D_800E12DE[],D_800E12E2[],D_800E12E6[],D_800E12EA[],D_800E12EE[],D_800E12F2[],D_800E12F6[];
extern struct RowRecAt54 D_800E3A58[];
extern Profile D_80102B00[];
extern s32 D_800E01B0_de[],D_800FF140_de[],D_800FEAE0[],D_8014DD98;
extern s32 func_8041F140_de(s32);
extern char *func_802A0494_de(char *);
extern char *func_802A025C_de(char *,char *);
extern char *func_80424DE8_de(s32);
extern s32 func_802A0C08_de(void *,const char *,...);
extern void func_8042D304_de(s32,s32,u16);
/* Update four player rows, their text fields, percentages, and optional badges. */
void func_8042C018_de(void) {
    s32 scoreOffset;
    s32 killOffset;
    s32 valueOffset;
    s32 row;
    s32 bank;
    s32 player;
    ResourceBank *iconBank;
    s32 textRow;
    s32 denom,percent,ratioOffset,iconIndex;
    s16 value;
    func_8041F2A0_Config *record;
    MenuWidget *item,*frameItem;
    char *name;
    func_8042CC74_de();
    row=0;iconBank=D_800E12F2;bank=0;valueOffset=0x27C;scoreOffset=0x1B4;killOffset=0x150;textRow=0;
    do {
        if(row>=D_800E53C0->count)return;
        player=D_800E53C0->players[D_800E53C0->first+row];
        record=&D_80146398[player];
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12D2+bank));
        func_8040E8D8_de(item,1);item->alpha=0x96;
        frameItem=item;
        frameItem->value=D_800E3A58[func_8041F140_de(record->kind)].pad0;
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12D6+bank));
        func_8040E8D8_de(item,1);item->alpha=0x19;
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12DA+bank));
        item->alpha=0xAF;func_8040E8D8_de(item,1);
        if(record->out==0)item->text=D_80102B00[player].name;
        else {name=record->name;func_802A025C_de(name,func_802A0494_de(name));item->text=name;}
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12DE+bank));
        item->alpha=0x73;func_8040E8D8_de(item,1);
        if(record->out==0)item->text=func_80424DE8_de(player);
        else item->text=resultsRankText(record->rank);
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12E2+bank));
        item->alpha=0xAF;func_8040E8D8_de(item,1);
        func_802A0C08_de((char *)D_800E53C0+killOffset,resultsNumberFormat(),record->kills);
        item->text=(char *)D_800E53C0+killOffset;
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12E6+bank));
        item->alpha=0xAF;func_8040E8D8_de(item,1);
        func_802A0C08_de((char *)D_800E53C0+scoreOffset,resultsNumberFormat(),record->score+record->total);
        {void **text=&item->text;*text=(char *)D_800E53C0+scoreOffset;}
        if(D_8014DD98==0) {
            func_8040E8D8_de(func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12EA+bank)),0);
            func_8042D304_de(player,row,RESULTS_RANK_GROUP);
        } else {
            item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12EA+bank));
            item->alpha=0xAF;func_8040E8D8_de(item,1);
            denom=D_800FF140_de[player];percent=0;
            if(denom>0)percent=D_800FEAE0[player]*100/denom;
            ratioOffset=textRow+0x218;
            func_802A0C08_de((char *)D_800E53C0+ratioOffset,resultsPercentFormat(),percent);
            item->text=(char *)D_800E53C0+ratioOffset;
        }
        if(D_8014DD98==3) {
            func_8040E8D8_de(func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12EE+bank)),0);
            func_8042D304_de(player,row,RESULTS_SECONDARY_GROUP);
        } else {
            item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12EE+bank));
            item->alpha=0xAF;func_8040E8D8_de(item,1);
            frameItem=item;
            if(D_8014DD98==0)goto other_value;
            if(D_8014DD98==1)goto selected_value;
            goto zero_value;
other_value:
            func_802A0C08_de((char *)D_800E53C0+valueOffset,resultsNumberFormat(),record->other);goto formatted;
selected_value:
            func_802A0C08_de((char *)D_800E53C0+valueOffset,resultsNumberFormat(),record->selected);goto formatted;
zero_value:
            func_802A0C08_de((char *)D_800E53C0+valueOffset,resultsNumberFormat(),0);
formatted: ;
            frameItem->text=(char *)D_800E53C0+valueOffset;
        }
        item=func_8040EC30_de(D_800E53C0->unkE0,iconBank->ids[0]);
        func_8040E8D8_de(item,0);item->alpha=0x96;
        item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12F6+bank));
        func_8040E8D8_de(item,0);item->alpha=0x96;
        if(record->out==0) {
            iconIndex=player;
            if(D_800E53C0->icons[iconIndex][0]!=-1) {
                item=func_8040EC30_de(D_800E53C0->unkE0,iconBank->ids[0]);
                func_8040E8D8_de(item,1);
                item->value=D_800E01B0_de[D_800E53C0->icons[iconIndex][0]];
            }
            if(D_800E53C0->icons[iconIndex][1]!=-1) {
                item=func_8040EC30_de(D_800E53C0->unkE0,*(u16 *)((char *)D_800E12F6+bank));
                func_8040E8D8_de(item,1);
                item->value=D_800E01B0_de[D_800E53C0->icons[iconIndex][1]];
            }
        }
        bank+=40;valueOffset+=25;scoreOffset+=25;killOffset+=25;row++;iconBank++;textRow+=25;
    }while(row<4);
}
