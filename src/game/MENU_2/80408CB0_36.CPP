#include "include_asm.h"

#if defined(VERSION_EU)
#include "TYPES.H"
typedef struct { void *list; s32 resourceWidget; void *item; s32 unkC; s32 unk10; char text14[12]; s32 unk20; } SliderPopupEu;
typedef struct { u8 pad0[0x10]; u8 alpha; u8 pad11[0x27]; void *text; } SliderItemEu;
extern SliderPopupEu *D_800E5430;
extern char D_800E1B60[];
extern void *Scene_AllocateMemory(s32);
extern void func_802A2360_de(void);
extern void *func_8041A280_de(s32, s32);
extern void func_8041A47C_de(void *);
extern void func_8041B110_de(s32);
extern void *func_8040EC30_de(void *, s32);
extern void *func_80419E54_de(s32, s32);
extern void func_802A0C08_de(char *, char *, ...);
/* Builds a three-row slider popup in its 0x24-byte state D_800E5430: title/list from the ids at 0x398, the numeric
   readout item at 0x39D showing the text at +0x14 formatted with D_800E1B60. Returns 0. */
s32 func_8042E640_eu(void *window) {
    SliderItemEu *item;
    void *title;

    D_800E5430 = Scene_AllocateMemory(0x24);
    func_802A2360_de();
    title = func_8041A280_de(0x398, 0x399);
    D_800E5430->list = title;
    func_8041A47C_de(title);
    func_8041B110_de(0x39C);
    item = func_8040EC30_de(window, 0x39A);
    D_800E5430->item = item;
    item->alpha = 0xF;
    D_800E5430->resourceWidget = func_80419E54_de(0x39B, 0x6E);
    D_800E5430->unkC = 3;
    item = func_8040EC30_de(window, 0x39D);
    item->text = D_800E5430->text14;
    D_800E5430->unk20 = 1;
    func_802A0C08_de(D_800E5430->text14, D_800E1B60, 1);
    return 0;
}
#endif
