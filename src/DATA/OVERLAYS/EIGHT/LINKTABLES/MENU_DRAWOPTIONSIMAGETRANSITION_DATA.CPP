#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "TYPES.H"

extern char Menu_ConsumeOptionsTransitionEvent[];
extern char Menu_CreateOptionsImageTransition[];
extern char Menu_DestroyOptionsImageTransition[];
extern char Menu_DrawOptionsImageTransition[];
extern char Menu_HandleOptionsTransitionRequest[];
extern char Menu_RequestOptionsImageTransition[];
extern char Menu_StartOptionsImageTransition[];
extern char PAKInterface_HandlePlayerPanelBack[];
extern char g_Menu_ConsumeOptionsTransitionEventPackedAddress24[];
extern char g_Menu_CreateOptionsImageTransitionPackedAddress24[];
extern char g_Menu_DestroyOptionsImageTransitionPackedAddress24[];
extern char g_Menu_DrawOptionsImageTransitionPackedAddress24[];
extern char g_Menu_HandleOptionsTransitionRequestPackedAddress24[];
extern char g_Menu_RequestOptionsImageTransitionPackedAddress24[];
extern char g_Menu_StartOptionsImageTransitionPackedAddress24[];

#include "include_asm.h"
#include "DATA/OVLTBL/MENU_DRAWOPTIONSIMAGETRANSITION_DATA.H"

/* 800E449C_2.CPP */
/* ROM-grounded data: rodata/writable/800E44A0 */
#if defined(VERSION_DE)
struct {
    void * g_optionsImageTransition;
} k_MenuDrawoptionsimagetransitionZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuDrawoptionsimagetransitionZeroWordsSizeCheck[(sizeof(k_MenuDrawoptionsimagetransitionZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_EU)
struct {
    void * g_optionsImageTransition;
} k_MenuDrawoptionsimagetransitionZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuDrawoptionsimagetransitionZeroWordsSizeCheck[(sizeof(k_MenuDrawoptionsimagetransitionZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_EU_X)
struct {
    void * g_optionsImageTransition;
} k_MenuDrawoptionsimagetransitionZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuDrawoptionsimagetransitionZeroWordsSizeCheck[(sizeof(k_MenuDrawoptionsimagetransitionZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_US)
struct {
    void * g_optionsImageTransition;
} k_MenuDrawoptionsimagetransitionZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuDrawoptionsimagetransitionZeroWordsSizeCheck[(sizeof(k_MenuDrawoptionsimagetransitionZeroWords) == 4) ? 1 : -1];
#endif
#if defined(VERSION_US_REV1)
struct {
    void * g_optionsImageTransition;
} k_MenuDrawoptionsimagetransitionZeroWords __attribute__((aligned(4))) = {
    0
};
typedef char k_MenuDrawoptionsimagetransitionZeroWordsSizeCheck[(sizeof(k_MenuDrawoptionsimagetransitionZeroWords) == 4) ? 1 : -1];
#endif

/* 800E44A4.CPP */
#if !(defined(VERSION_US) || defined(VERSION_US_REV1))
#if defined(VERSION_DE)
extern char g_Menu_DispatchSixChoiceEventAddress[];
#if defined(VERSION_DE)
struct {
    ResidentEventHandlerEntry handlers[8];
    u32 alignmentFill[3];
} D_src_d9561b8a __attribute__((aligned(4))) = {
    { { 3590, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1120) }, { 3587, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1192) }, { 2, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1628) }, { 1, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1604) }, { 3594, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1240) }, { 3592, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1392) }, { 10, 25, (ResidentEventHandler)(void *)(g_Menu_DispatchSixChoiceEventAddress + 1532) }, { 0, 0, (ResidentEventHandler)0 } },
    { 0x00000000, 0x00000000, 0x00000E08 }
};
#endif
#endif
#if defined(VERSION_EU)
#if defined(VERSION_EU)
struct {
    ResidentEventHandlerEntry handlers[8];
    u32 alignmentFill[3];
} D_src_d9561b8a __attribute__((aligned(4))) = {
    { { 3590, 25, (ResidentEventHandler)(void *)&g_Menu_CreateOptionsImageTransitionPackedAddress24 }, { 3587, 25, (ResidentEventHandler)(void *)&g_Menu_DestroyOptionsImageTransitionPackedAddress24 }, { 2, 25, (ResidentEventHandler)(void *)&g_Menu_ConsumeOptionsTransitionEventPackedAddress24 }, { 1, 25, (ResidentEventHandler)(void *)&g_Menu_RequestOptionsImageTransitionPackedAddress24 }, { 3594, 25, (ResidentEventHandler)(void *)&g_Menu_DrawOptionsImageTransitionPackedAddress24 }, { 3592, 25, (ResidentEventHandler)(void *)&g_Menu_StartOptionsImageTransitionPackedAddress24 }, { 10, 25, (ResidentEventHandler)(void *)&g_Menu_HandleOptionsTransitionRequestPackedAddress24 }, { 0, 0, (ResidentEventHandler)0 } },
    { 0xA702000C, 0x001A1402, 0x30410008 }
};
#endif
#endif
#if defined(VERSION_EU_X)
#if defined(VERSION_EU_X)
ResidentEventHandlerEntry D_src_d9561b8a[9] = {
    { 3590, 25, (ResidentEventHandler)(void *)((char *)&Menu_CreateOptionsImageTransition - 0x80000000U) }, { 3587, 25, (ResidentEventHandler)(void *)((char *)&Menu_DestroyOptionsImageTransition - 0x80000000U) }, { 2, 25, (ResidentEventHandler)(void *)((char *)&Menu_ConsumeOptionsTransitionEvent - 0x80000000U) }, { 1, 25, (ResidentEventHandler)(void *)((char *)&Menu_RequestOptionsImageTransition - 0x80000000U) }, { 3594, 25, (ResidentEventHandler)(void *)((char *)&Menu_DrawOptionsImageTransition - 0x80000000U) }, { 3592, 25, (ResidentEventHandler)(void *)((char *)&Menu_StartOptionsImageTransition - 0x80000000U) }, { 10, 25, (ResidentEventHandler)(void *)((char *)&Menu_HandleOptionsTransitionRequest - 0x80000000U) }, { 0, 0, (ResidentEventHandler)0 },
    { 2, 19, (ResidentEventHandler)(void *)((char *)&PAKInterface_HandlePlayerPanelBack - 0x80000000U) }
};
#endif
#endif
#endif

#if defined(VERSION_US) || defined(VERSION_US_REV1)
/* ROM-grounded us-rev1 data; explicit withholding in other holders. */
#if defined(VERSION_US)
ResidentEventHandlerEntry g_MenuDrawoptionsimagetransitionEncodedWords[8] = {
    { 3590, 25, (ResidentEventHandler)(void *)g_menu_CreateOptionsImageTransitionEntry }, { 3587, 25, (ResidentEventHandler)(void *)g_menu_DestroyOptionsImageTransitionEntry }, { 2, 25, (ResidentEventHandler)(void *)g_menu_ConsumeOptionsTransitionEventEntry }, { 1, 25, (ResidentEventHandler)(void *)g_menu_RequestOptionsImageTransitionEntry }, { 3594, 25, (ResidentEventHandler)(void *)g_menu_DrawOptionsImageTransitionEntry }, { 3592, 25, (ResidentEventHandler)(void *)g_menu_StartOptionsImageTransitionEntry }, { 10, 25, (ResidentEventHandler)(void *)g_menu_HandleOptionsTransitionRequestEntry }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#if defined(VERSION_US_REV1)
ResidentEventHandlerEntry g_MenuDrawoptionsimagetransitionEncodedWords[8] = {
    { 3590, 25, (ResidentEventHandler)(void *)g_menu_CreateOptionsImageTransitionEntry }, { 3587, 25, (ResidentEventHandler)(void *)g_menu_DestroyOptionsImageTransitionEntry }, { 2, 25, (ResidentEventHandler)(void *)g_menu_ConsumeOptionsTransitionEventEntry }, { 1, 25, (ResidentEventHandler)(void *)g_menu_RequestOptionsImageTransitionEntry }, { 3594, 25, (ResidentEventHandler)(void *)g_menu_DrawOptionsImageTransitionEntry }, { 3592, 25, (ResidentEventHandler)(void *)g_menu_StartOptionsImageTransitionEntry }, { 10, 25, (ResidentEventHandler)(void *)g_menu_HandleOptionsTransitionRequestEntry }, { 0, 0, (ResidentEventHandler)0 }
};
#endif
#endif

#if defined(VERSION_US)
char g_MenuDrawoptionsimagetransitionTrailingBytes[12] =
    "IFLEequ\004.eos";
#endif
