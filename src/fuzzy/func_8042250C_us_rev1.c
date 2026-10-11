#include "span_16E000/code_8041A4B0.h"
#include "span_16E000/code_8041B020.h"
#include "span_16E000/code_80423280.h"
#include "types.h"

/* Builds the options-commit state: allocates its 0x28 bytes through func_8025305C_de and keeps the
   record at D_800E4510, creates the fade widget 0x4D/0x4E and the title object 0x4F/0x6E, then builds
   the three option lists 0x59/0x5A, 0x55/0x56 and 0x51/0x52, appends their localized labels, and
   selects the entry named by the game settings D_801462C8 bytes 0x1B, 0x1F and 0x580 - the third list
   gains the labels at 0x800D74B8 and 0x800D74BC only when func_80265350_de does not return 0x400000.
   The 0x80-step slider 0x53/0x54 is created and positioned at the settings' position byte, menu nodes
   0x57, 0x58 and 0x50 are released, and the record is finally armed with a selection value of -1 and
   commit state 3, returning zero. */

/* The 0x28-byte options-commit record D_800E4510 points at; built here and read back by
   func_80422FC0_de through OptionsCommitContext. Field comments give each offset. */
struct OptionsCommitBlock_func_8042250C_us_rev1 {
    s32 unk0;                        /* 0x00 fade widget record (func_8041A280_de 0x4D/0x4E) */
    s32 unk4;                        /* 0x04 title object (func_80419E54_de 0x4F/0x6E) */
    s32 unk8;                        /* 0x08 slider record (func_8041A580_de 0x53/0x54/0x80) */
    Record_func_8041ABC0_de *unkC;  /* 0x0C first option list (0x59/0x5A) */
    Record_func_8041ABC0_de *unk10; /* 0x10 second option list (0x55/0x56) */
    Record_func_8041ABC0_de *unk14; /* 0x14 third option list (0x51/0x52) */
    s32 pad18[2];                    /* 0x18 unused gap */
    s32 unk20;                       /* 0x20 selected option value; -1 while nothing is picked */
    s32 unk24;                       /* 0x24 commit state; 3 once built */
};

extern struct OptionsCommitBlock_func_8042250C_us_rev1 *D_800E4510;
extern OptionsBuildSettings D_801462C8;

/* Localized label words handed to func_8041AD34_de. D_800D3470_de is spelled as in
   include/common/unused.h:3447. The label strings run consecutively from 0x800D74A4 through
   0x800D74B0; only 0x800D74A4 (D_800D2124) and 0x800D74A8 (D_800D2128) carry their own symbol, so
   the unlabelled pair at 0x800D74AC and 0x800D74B0 is reached through the D_800D2124 array
   (same convention as func_80422728_us_rev1.c, which arrays the consecutive run at
   0x800D74B4..0x800D74BC). */
extern s32 D_800D3470_de[];
extern char *D_800D2124[4];
extern char *D_800D2128;
extern char *D_800D2134;
extern char *D_800D2138;
extern char *D_800D213C;

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
    func_8041AD34_de(firstList, D_800D3470_de[0]);
    func_8041AD34_de(D_800E4510->unkC, D_800D2124[0]);
    func_8041AD34_de(D_800E4510->unkC, D_800D2128);
    settings = &D_801462C8;
    func_8041AD10_de(D_800E4510->unkC, settings->first);
    secondList = func_8041ABC0_de(0x55, 0x56);
    D_800E4510->unk10 = secondList;
    func_8041AD34_de(secondList, D_800D2124[2]);
    func_8041AD34_de(D_800E4510->unk10, D_800D2124[3]);
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
