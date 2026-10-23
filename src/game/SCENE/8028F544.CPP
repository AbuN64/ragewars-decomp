#include "include_asm.h"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OSTASK_T.H"
#include "COMMON/OSVISCALE.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "COMMON/EXTERNS_3.H"
#include "SDK/AUDIO_2/802BF400.H"
#include "SDK/SCHED/8028DF6C_7.H"
#include "sdk/libgultra/libasm_802BD1A8_3.h"
#include "sdk/libgultra/sptaskyield.h"
#include "sdk/os.h"
extern s32 D_80142C30;
extern s32 D_80142C38;
/* Initialises a panel: marks it active, clears its counters, lays out its two eight-slot rows, binds text 0x29B to 0x29D and 0x29A with the given style byte to the first row, and builds its element list from the D_28E910 template. */




extern void func_802BB550_de(s32 slot, char *row, s32 text);

extern void func_802BA650_de(char *row, s32 text, s32 style);

extern void func_802BAC90_de(char *list, s32 count, void *template, Panel *owner, s32 arg4, s32 arg5);

extern void func_802BB750_de(char *list);

s32 func_8028F544_de(OSSched *arg0, OSScTask_s **arg1, OSScTask_s **arg2, s32 arg3) {
    OSScTask_s *temp_s0;
    OSScTask_s *temp_v1_0;
    OSScTask_s *temp_v0;
    OSScTask_s *var_v1;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s1;

    var_s1 = arg3;
    temp_s0 = arg0->gfxListHead;
    temp_v1_0 = arg0->audioListHead;
    temp_s5 = var_s1;
    if ((arg0->doAudio != 0) && (var_s1 & 2)) {
        if ((temp_s0 == 0) || !(temp_s0->flags & 0x10)) {
            *arg1 = temp_v1_0;
            arg0->doAudio = 0;
            temp_v0 = arg0->audioListHead->next;
            var_s1 &= ~2;
            arg0->audioListHead = temp_v0;
            if (temp_v0 == 0) {
                arg0->audioListTail = 0;
            }
        } else {
            *arg1 = temp_s0;
            var_s1 &= ~2;
        }
    } else {
        if (temp_s0 == 0) {
            var_v1 = 0;
        } else if ((s32)temp_s0->framebuffer == D_80142C38) {
            var_v1 = 0;
        } else if (temp_s0->framebuffer == osViGetCurrentFramebuffer()) {
            var_v1 = 0;
        } else if ((s32)temp_s0->framebuffer == D_80142C30) {
            var_v1 = 0;
        } else {
            var_v1 = temp_s0;
        }
        if (var_v1 != 0) {
            temp_v0_2 = temp_s0->flags & 7;
            switch (temp_v0_2) {
            case 1:
            case 4:
            case 5:
                break;
            case 3:
                if (temp_s0->state & 0x20) {
                    if (var_s1 & 2) {
                        *arg1 = temp_s0;
                        var_s1 &= ~2;
                        if (temp_s0->state & 1) {
                            *arg2 = temp_s0;
                            var_s1 &= ~1;
                        }
                        arg0->gfxListHead = arg0->gfxListHead->next;
                        if (arg0->gfxListHead == 0) {
                            arg0->gfxListTail = 0;
                        }
                    }
                } else if (var_s1 == 3) {
                    *arg2 = temp_s0;
                    *arg1 = temp_s0;
                    arg0->gfxListHead = arg0->gfxListHead->next;
                    var_s1 = 0;
                    if (arg0->gfxListHead == 0) {
                        arg0->gfxListTail = 0;
                    }
                }
                break;
            case 2:
            case 6:
            case 7:
                temp_v1 = temp_s0->state;
                if (temp_v1 & 2) {
                    if (var_s1 & 2) {
                        *arg1 = temp_s0;
                        var_s1 &= ~2;
                    }
                } else if ((temp_v1 & 1) && (var_s1 & 1)) {
                    *arg2 = temp_s0;
                    arg0->gfxListHead = arg0->gfxListHead->next;
                    var_s1 &= ~1;
                    if (arg0->gfxListHead == 0) {
                        arg0->gfxListTail = 0;
                    }
                }
                break;
            }
        }
    }
    if (var_s1 != temp_s5) {
        var_s1 = func_8028F544_de(arg0, arg1, arg2, var_s1);
    }
    return var_s1;
}

void func_8028F754_de(Panel *panel, s32 arg1, s32 arg2, s32 arg3, unsigned char style) {
    panel->active = 1;
    panel->field2F4 = 0;
    panel->field2F8 = 0;
    panel->field2E0 = 0;
    panel->field2FC = 0;
    panel->field2E4 = 0;
    panel->field2E8 = 0;
    panel->field2EC = 0;
    panel->field2F0 = 0;
    panel->field300 = 0;
    panel->mode = 4;
    osCreateMesgQueue(panel->row0, panel->row0Slots, 8);
    osCreateMesgQueue(panel->row1, panel->row1Slots, 8);
    func_802BB550_de(4, panel->row0, 0x29B);
    func_802BB550_de(9, panel->row0, 0x29C);
    func_802BB550_de(0xE, panel->row0, 0x29D);
    func_802BA650_de(panel->row0, 0x29A, style);
    func_802BAC90_de(panel->elements, 7, &D_0028E930, panel, arg1, arg2);
    func_802BB750_de(panel->elements);
}
