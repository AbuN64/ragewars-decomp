#include "span_16E000/code_8041A4B0.h"
#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_80423280.h"
#include "types.h"

struct OptionsCommitBlock_func_8042250C_us_rev1 {
    s32 unk0;                        
    s32 unk4;                        
    s32 unk8;                        
    Record_func_8041ABC0_de *unkC;  
    Record_func_8041ABC0_de *unk10; 
    Record_func_8041ABC0_de *unk14; 
    s32 pad18[2];                    
    s32 unk20;                       
    s32 unk24;                       
};

extern struct OptionsCommitBlock_func_8042250C_us_rev1 *D_800E4510;
extern OptionsBuildSettings D_801462C8;

extern char *D_800D3470_de;
extern char *D_auto_800D74AC;
extern char *D_800D2124;
extern char *D_800D2128;

extern char *D_800D2134;
extern char *D_800D2138;
extern char *D_800D213C;
extern char *D_auto_800D74B0;

extern void *func_8025305C_de(s32);
extern s32 func_8041A280_de(s32, s32);
extern s32 func_80419E54_de(s32, s32);
extern s32 func_80265350_de(void);
extern Record_func_8041ABC0_de *func_8041ABC0_de(s32, s32);
extern void func_8041AD34_de(Record_func_8041ABC0_de *, char *);
extern void func_8041AD10_de(Record_func_8041ABC0_de *, s32);
extern s32 func_8041A580_de(s32, s32, s32);
extern void func_8041A6EC_de(s32, s32);

s32 func_8042250C_us_rev1(void) {
    OptionsBuildSettings *settings;
    Record_func_8041ABC0_de *firstList;
    Record_func_8041ABC0_de *secondList;
    Record_func_8041ABC0_de *thirdList;
    s32 title;
    s32 slider;

    D_800E4510 = func_8025305C_de(0x28);
    D_800E4510->unk0 = func_8041A280_de(0x4D, 0x4E);
    func_8041B110_de(0x57);
    func_8041B110_de(0x58);
    firstList = func_8041ABC0_de(0x59, 0x5A);
    D_800E4510->unkC = firstList;
    func_8041AD34_de(firstList, D_800D3470_de);
    func_8041AD34_de(D_800E4510->unkC, D_800D2124);
    func_8041AD34_de(D_800E4510->unkC, D_800D2128);
    settings = &D_801462C8;
    func_8041AD10_de(D_800E4510->unkC, settings->first);
    secondList = func_8041ABC0_de(0x55, 0x56);
    D_800E4510->unk10 = secondList;
    func_8041AD34_de(secondList, D_auto_800D74AC);
    func_8041AD34_de(D_800E4510->unk10, D_auto_800D74B0);
    func_8041AD10_de(D_800E4510->unk10, settings->second);
    thirdList = func_8041ABC0_de(0x51, 0x52);
    D_800E4510->unk14 = thirdList;
    func_8041AD34_de(thirdList, D_800D2134);
    if (func_80265350_de() != 0x400000) {
        func_8041AD34_de(D_800E4510->unk14, D_800D2138);
        func_8041AD34_de(D_800E4510->unk14, D_800D213C);
    }
    func_8041AD10_de(D_800E4510->unk14, settings->third);
    slider = func_8041A580_de(0x53, 0x54, 0x80);
    D_800E4510->unk8 = slider;
    func_8041A6EC_de(slider, settings->position);
    func_8041B110_de(0x50);
    title = func_80419E54_de(0x4F, 0x6E);
    D_800E4510->unk24 = 3;
    D_800E4510->unk4 = title;
    D_800E4510->unk20 = -1;
    return 0;
}
