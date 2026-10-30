#include "TYPES.H"

extern char g_weaponFireStateCallbackTable[];

#include "DATA/WEAPON_EVENT_TRANSLATION/WEAPONAI_INITIALIZESWITCHANDREQUESTIDLE_DATA.H"

#if defined(VERSION_US_REV1)
#if defined(VERSION_US_REV1)
struct {
    void * reserved0;
    void * reserved1;
    f32 scale;
    f32 speed;
    void * states;
    void * enter;
    void * update;
} g_WeaponaiInitializeswitchandrequestidleWords1 __attribute__((aligned(4))) = {
    0,
    0,
    1.0f,
    1.0f,
    (void *)&g_weaponFireStateCallbackTable,
    0,
    0
};
typedef char g_WeaponaiInitializeswitchandrequestidleWords1SizeCheck[(sizeof(g_WeaponaiInitializeswitchandrequestidleWords1) == 28) ? 1 : -1];
#endif

extern char g_weaponPresentationResource1219[];
extern char g_weaponSlot2PresentationUsRev1[];
extern char g_weaponSlot3PresentationUsRev1[];
extern char g_weaponSlot4PresentationUsRev1[];
extern char g_weaponSlot5PresentationUsRev1[];
extern char g_weaponSlot6PresentationUsRev1[];
extern char g_weaponSlot7PresentationUsRev1[];
extern char g_weaponSlot8PresentationUsRev1[];
extern char g_weaponPresentation6_us_rev1[];
extern char g_weaponPresentation1_us_rev1[];
extern char g_weaponPresentation2_us_rev1[];
extern char g_weaponPresentation3_us_rev1[];
extern char g_weaponPresentation4_us_rev1[];
extern char g_weaponPresentation5_us_rev1[];
extern char g_weaponPresentation7_us_rev1[];
extern char g_weaponPresentation8_us_rev1[];
extern char g_weaponPresentationResource1235[];
extern char g_weaponSlot1PresentationUsRev1[];
extern char g_weaponPresentationDescriptor0Rev1[];
extern char g_weaponPresentationDescriptor1Rev1[];
extern char g_weaponPresentationDescriptor2Rev1[];
extern char g_weaponPresentationDescriptor3Rev1[];
void * g_WeaponResourceDirectoryWords1[22] = {
    (void *)&g_weaponPresentationResource1219, (void *)&g_weaponSlot2PresentationUsRev1, (void *)&g_weaponSlot3PresentationUsRev1, (void *)&g_weaponSlot4PresentationUsRev1,
    (void *)&g_weaponSlot5PresentationUsRev1, (void *)&g_weaponSlot6PresentationUsRev1, (void *)&g_weaponSlot7PresentationUsRev1, (void *)&g_weaponSlot8PresentationUsRev1,
    (void *)&g_weaponPresentation6_us_rev1, (void *)&g_weaponPresentation1_us_rev1, (void *)&g_weaponPresentation2_us_rev1, (void *)&g_weaponPresentation3_us_rev1,
    (void *)&g_weaponPresentation4_us_rev1, (void *)&g_weaponPresentation5_us_rev1, (void *)&g_weaponPresentation7_us_rev1, (void *)&g_weaponPresentation8_us_rev1,
    (void *)&g_weaponPresentationResource1235, (void *)&g_weaponSlot1PresentationUsRev1, (void *)&g_weaponPresentationDescriptor0Rev1, (void *)&g_weaponPresentationDescriptor1Rev1,
    (void *)&g_weaponPresentationDescriptor2Rev1, (void *)&g_weaponPresentationDescriptor3Rev1,
};

unsigned int g_WeaponaiInitializeswitchandrequestidlePointerWords1[17] = {
    0x00000000, 0x0BEA0BEB, 0x0BECFFFF, 0x0BED0BEE, 0x0BEF0BF0, 0x800D720C, 0x800D7210, 0x800D7214,
    0x800D7218, 0x800D721C, 0x800D7220, 0x800D7224, 0xFFFFFFFF, 0x00000001, 0x00000001, 0x00000000,
    (unsigned int)g_Gsky_FloorSurfaceNoOpAddress,
};
#endif
