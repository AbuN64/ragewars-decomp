#ifndef COMMON_MENUSELECTIONMESSAGE_H
#define COMMON_MENUSELECTIONMESSAGE_H
#include "TYPES.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/INTEGERSTATEB0.H"
#include "COMMON/MENULISTSCREEN.H"
#include "COMMON/ITEMRECAT20V1.H"

/* The selection-message screen D_800E5830: its menu rules block, then its item and reply state. */
struct SelectionMessageScreen;
struct SelectionMessageScreen {
    MenuRules rules;
    char pad20[0x24 - 0x20];
    void *item;
    char pad28[0x90 - 0x28];
    s32 started;
    char pad94[0x9C - 0x94];
    s32 first;
    char padA0[0xB0 - 0xA0];
    s32 second;
    char padB4[0x188 - 0xB4];
    s32 third;
    char pad18C[0x1C0 - 0x18C];
    s32 busy;
};
struct MenuSelectionMessage;
struct MenuSelectionMessage {
    void *first;
    s32 pad4[3];
    s32 value;
};

struct SoundOptionsScreen;
struct SoundOptionsScreen {
    void *menu;
    char pad4[0x8 - 0x4];
    void *music;
    void *effects;
    char pad10[0x14 - 0x10];
    s32 target;
};


struct MenuSelectionMessage;
typedef struct MenuSelectionMessage MenuSelectionMessage;


struct ActorDefinitionHeader;


#endif
