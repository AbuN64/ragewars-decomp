#include "COMMON/RECRECAT4.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "TYPES.H"
#include "FRONTEND/80423280_25.H"

/* Refreshes the option block D_801462C8 from the menu g_optionsPage points to: the bytes at 0x1B, 0x1F
   and 0x580 from the selections SmpButton_GetListSelection reports for its items at 0xC, 0x10 and 0x14, and the
   word at 0x10 from the position SmpSlider_GetSliderItem reports for its item at 8. */





extern OptionsCommitContext *g_optionsPage;

extern s32 SmpButton_GetListSelection(void *);

extern s32 SmpSlider_GetSliderItem(void *);

/* Refreshes the option block D_801462C8 from the menu D_800E4514 points to: the bytes at 0x1B and 0x580
   from the selections SmpButton_GetListSelection reports for its items at 4 and 8, and the word at 0x10 from
   the position SmpSlider_GetSliderItem reports for its item at 0. */







extern CompactOptionsCommitContext *D_800E4514;

/* Refreshes the option block D_801462C8 from the menu D_800E4518 points to: the bytes at 0x1B and 0x580
   from the selections SmpButton_GetListSelection reports for its items at 0x54 and 0x58, and the word at 0x10 from
   the position SmpSlider_GetSliderItem reports for its item at 0x50. */







extern TabOptionsCommitContext *D_800E4518;

void Menu_CommitOptionsPage(void) {
    Shared_Game *options;
    s32 value;

#if defined(VERSION_DE)
    value = SmpButton_GetListSelection(g_optionsPage->unk_10);
    options = &D_801462C8;
    options->unknown1F = value;
#else
    value = SmpButton_GetListSelection(g_optionsPage->unk_C);
    options = &D_801462C8;
    options->firstListMode = value;
    options->unknown1F = SmpButton_GetListSelection(g_optionsPage->unk_10);
#endif
    options->reserved580 = SmpButton_GetListSelection(g_optionsPage->unk_14);
    options->buttons = SmpSlider_GetSliderItem(g_optionsPage->unk_8);
}

void Menu_CommitCompactOptionsPage(void) {
    Shared_Game *options;
    s32 value;

#if defined(VERSION_DE)
    value = SmpButton_GetListSelection(D_800E4514->unk_8);
    options = &D_801462C8;
    options->reserved580 = value;
#else
    value = SmpButton_GetListSelection(D_800E4514->unk_4);
    options = &D_801462C8;
    options->firstListMode = value;
    options->reserved580 = SmpButton_GetListSelection(D_800E4514->unk_8);
#endif
    options->buttons = SmpSlider_GetSliderItem(D_800E4514->unk_0);
}

void Menu_CommitTabOptionsPage(void) {
    Shared_Game *options;
    s32 value;

#if defined(VERSION_DE)
    value = SmpButton_GetListSelection(D_800E4518->unk_58);
    options = &D_801462C8;
    options->reserved580 = value;
#else
    value = SmpButton_GetListSelection(D_800E4518->unk_54);
    options = &D_801462C8;
    options->firstListMode = value;
    options->reserved580 = SmpButton_GetListSelection(D_800E4518->unk_58);
#endif
    options->buttons = SmpSlider_GetSliderItem(D_800E4518->unk_50);
}
