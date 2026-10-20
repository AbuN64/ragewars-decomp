#ifndef COMMON_SHARED_OPTIONSSCREEN_H
#define COMMON_SHARED_OPTIONSSCREEN_H
#include "COMMON/GAMEPLAY_SETTINGS.H"
#include "COMMON/SHARED_GAMESLOT.H"

#include "COMMON/ITEMRECAT20V1.H"
#include "TYPES.H"
typedef struct Shared_OptionsScreen Shared_OptionsScreen;
struct Shared_OptionsScreen {
    u32 unknown00[7];
    s32 cursor;
    MenuWidget *leftTab;
    s32 leftStep;
    MenuWidget *rightTab;
    s32 rightStep;
    s32 page;
    s32 pages;
    void *title;
    MenuWidget *marker;
    MenuWidget *header;
    MenuWidget *footer;
    MenuWidget *pakIcon;
    MenuWidget *rumbleIcon;
    void *slider;
    struct MenuListWidget *firstList;
    struct MenuListWidget *secondList;
    s32 state;
    s32 selection;
    s32 sound;
    MenuWidget *prompt;
};
typedef struct Shared_MenuReply Shared_MenuReply;
struct Shared_MenuReply {
    s32 value;
    s32 ready;
};
typedef struct Shared_MenuObject Shared_MenuObject;
struct Shared_MenuObject {
    u8 unknown00[0x1310];
    Shared_PlayerSettingsRecord playerSettings[8];
    u8 unknown17C0;
    u8 language;
    u8 unknown17C2[0x2E];
};
typedef struct Shared_MenuData Shared_MenuData;
struct Shared_MenuData {
    union {
        struct {
            u32 unknown00[18];
            Shared_MenuObject object;
            s32 stage;
            u32 unknown183C[6];
            s32 pause;
        };
        struct {
            u8 reserved0000[0x5DC];
            struct func_8025E5B0_S1 dialogOwner; /* D_8014561C */
            u8 reserved05F2[0x1288 - 0x5DC - sizeof(struct func_8025E5B0_S1)];
            Shared_Game game; /* D_801462C8; language at root + 0x1809 */
        };
    };
};

#include "COMMON/SHAREDPLAYER.H"
typedef void (*Shared_ContextCallback)(void *);
typedef void (*Shared_MenuVoidCallback)(void);
struct SharedTrackObject;
#include "COMMON/KEYRECAT1C.H"
typedef struct Shared_MenuContext Shared_MenuContext;
struct Shared_MenuContext {
    void *owner;
    void *resource;
    u32 unknown08;
    Shared_MenuVoidCallback onClose;
    Shared_MenuVoidCallback callback10;
    u32 unknown14;
    struct SharedTrackObject *target;
    f32 time;
    f32 time20;
    f32 time24;
    f32 clipStart;
    f32 clipEnd;
    f32 start;
    f32 end;
    s32 active;
    s32 state3C;
    u32 unknown40;
    s32 initialized44;
    s32 closed;
    s32 field4C;
    s32 field50;
    s32 pending;
    s32 field58;
    u32 unknown5C;
    u32 unknown60;
    f32 fade;
    EntryRecAt48 spec; /* 0x68..0xB3 */
    s32 fieldB4;
    s32 mode; /* 0xB8 */
    u32 unknownBC[7];
    s32 targetD8;
    s32 resourceDC;
    s32 requestE0;
    Shared_ContextCallback callbackE4;
    Shared_MenuVoidCallback callbackE8;
    u32 unknownEC;
    CVector3 position;
    f32 yaw;
    f32 response; /* 0x100 */
    s32 unknown104[5];
    char messages[5][0x28];
    s32 messageCount;
};
/* The context the camera and menu code works on. */
extern Shared_MenuContext *D_800E2830;
#endif
