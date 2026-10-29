#include "include_asm.h"
#include "MENU/OBJECT1C8.H"
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/SOUNDINFO.H"
#include "COMMON/ACTORRECAT5E0.H"
#include "SYSTEM/SOUND_CONTEXT_MUSIC_AND_VOICE_CONTROL.H"
#include "sdk/AUDIO/sprintf.H"

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookOne(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookTwo(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookThree(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookFour(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookFive(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookSix(void) {
    return 0;
}

/* Returns zero. Nothing in the cartridge image calls it or stores its address as a word, so it is
   either reached through a pointer built at run time or never used. */
s32 Player_PartnerStatusZeroHookSeven(void) {
    return 0;
}

/* Calls SoundElement_DisableMusicGainOverride and passes what SoundVoicePool_GetGlobalState returns to SoundVoicePool_Resume; then, when g_controllerReturnPending
   is set, calls Menu_TryCreateMenu with the three arguments, otherwise Control_RestoreControllerSetup_FrontendDestroypausemenu. Returns one. */
extern s32 SoundVoicePool_GetGlobalState();
struct SoundVoicePool;
extern void SoundVoicePool_Resume(struct SoundVoicePool *);
extern void Menu_TryCreateMenu(void *, void *, void *);

s32 Player_RestoreControlsOrCreateMenu(void *first, void *second, void *third) {
    SoundElement_DisableMusicGainOverride();
    SoundVoicePool_Resume(SoundVoicePool_GetGlobalState());
    if (g_controllerReturnPending == 0) {
        Control_RestoreControllerSetup();
        return 1;
    }
    Menu_TryCreateMenu(first, second, third);
    return 1;
}

#if defined(VERSION_DE) || defined(VERSION_US_REV1) || defined(NON_MATCHING)
/* US, EU and EU-X keep their asm: US and EU share the jump table rodata with other tables, EU-X formats a different line. */
#include "MENU/PLAYER_STATUS_TEXT.H"
#include "TYPES.H"

/* Formats a player's status line into a menu field's text through Libc_FormatString (sprintf): one message when the player is its own partner, otherwise a message chosen by the player's mode at 0x12F0 (0 to 6), naming the partner's character from 0x84 of its record at 0x5D8 when there is a partner. */
typedef struct StatusPlayer {
    char pad0[0x5D8];
    char *record;
    char pad5DC[0x12EC - 0x5DC];
    struct StatusPlayer *partner;
    unsigned int mode;
} StatusPlayer;

typedef struct {
    char pad0[0x10];
    char **text;
} Field;

typedef struct {
    char pad0[0x18];
    Field *field;
} Item;

typedef struct {
    char pad0[0x1C];
    StatusPlayer *player;
} Owner;


s32 Player_FormatPlayerPartnerStatus(Item *item, Owner *owner) {
    StatusPlayer *player = owner->player;
    char *text = *item->field->text;
    if (player->partner == player) {
        Libc_FormatString(text, playerStatusText0());
    } else if (player->partner != 0) {
        switch (player->mode) {
        case 0: Libc_FormatString(text, playerStatusText1(), player->partner->record + 0x84); break;
        case 1: Libc_FormatString(text, playerStatusText2(), player->partner->record + 0x84); break;
        case 2: Libc_FormatString(text, playerStatusText3(), player->partner->record + 0x84); break;
        case 3: Libc_FormatString(text, playerStatusText4(), player->partner->record + 0x84); break;
        case 4: Libc_FormatString(text, playerStatusText5(), player->partner->record + 0x84); break;
        case 5: Libc_FormatString(text, playerStatusText6(), player->partner->record + 0x84); break;
        case 6: Libc_FormatString(text, playerStatusText7(), player->partner->record + 0x84); break;
        }
    } else {
        switch (player->mode) {
        case 0: Libc_FormatString(text, playerStatusText8()); break;
        case 1: Libc_FormatString(text, playerStatusText9()); break;
        case 2: Libc_FormatString(text, playerStatusText10()); break;
        case 3: Libc_FormatString(text, playerStatusText11()); break;
        case 4: Libc_FormatString(text, playerStatusText12()); break;
        case 5: Libc_FormatString(text, playerStatusText13()); break;
        case 6: Libc_FormatString(text, playerStatusText14()); break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("ovl_frontendMenu", Player_FormatPlayerPartnerStatus);
#endif
