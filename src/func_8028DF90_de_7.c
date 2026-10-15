#include "span_1000/code_8028DF6C.h"
#include "common/types_06e4f7ef1f9e.h"
#include "common/types_1dc8418c21db.h"
#include "common/unused.h"
#include "span_1000/code_802B9ED8.h"
#include "span_1000/code_802BA23C.h"
#include "span_1000/code_802BB15C.h"
#include "span_1000/code_802BD1A8.h"
#include "types.h"

extern s32 D_80142C30;

extern s32 D_80142C38;

/* Initialises a panel: marks it active, clears its counters, lays out its two eight-slot rows, binds text 0x29B to 0x29D and 0x29A with the given style byte to the first row, and builds its element list from the D_28E910 template. */



extern void osCreateMesgQueue(char *row, char *slots, s32 count);

extern void func_802BB550_de(s32 slot, char *row, s32 text);

extern void func_802BA650_de(char *row, s32 text, s32 style);

extern void func_802BAC90_de(char *list, s32 count, void *template, Panel *owner, s32 arg4, s32 arg5);

extern void func_802BB750_de(char *list);

s32 func_802BD170_de(s32);

extern s32 func_802BD170_de(s32);

/* Switches a view to a new current and next scene: stamps the time of a pending next scene, starts the current scene (resetting its timer for mode 2, and stamping its start and, unless flagged 0x10, its first-start time for flag 0x20), clears its flags 0x30, runs its start and update hooks and records it, then when the next scene differs starts its music at its time and records it. */





extern u64 D_8011B1D0;

extern f32 D_8011B1D8;

extern u64 D_8011B1E0;

extern s64 D_8011B1E8;

extern s64 D_8011B1F0;

extern s32 D_800CD714;

extern s64 func_802BADC0_de(void);

extern void func_802B9E78_de(s32 *mode);

extern void osSpTaskStartGo(s32 *mode);

extern void func_802B7B90_de(s32 music, s64 time);

extern void func_802BB5F0_de(void *arg0, s32 arg1);

extern s32 D_800CD704;

extern s32 D_80106248;

s32 func_8028F544_de(Ctx_func_8028F544_de *arg0, Node_func_8028F544_de **arg1, Node_func_8028F544_de **arg2, s32 arg3) {
    Node_func_8028F544_de *temp_s0;
    Node_func_8028F544_de *temp_v1_0;
    Node_func_8028F544_de *temp_v0;
    Node_func_8028F544_de *var_v1;
    s32 temp_s5;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 var_s1;

    var_s1 = arg3;
    temp_s0 = arg0->unk2E8;
    temp_v1_0 = arg0->unk2E4;
    temp_s5 = var_s1;
    if ((arg0->unk300 != 0) && (var_s1 & 2)) {
        if ((temp_s0 == 0) || !(temp_s0->unk8 & 0x10)) {
            *arg1 = temp_v1_0;
            arg0->unk300 = 0;
            temp_v0 = arg0->unk2E4->unk0;
            var_s1 &= ~2;
            arg0->unk2E4 = temp_v0;
            if (temp_v0 == 0) {
                arg0->unk2EC = 0;
            }
        } else {
            *arg1 = temp_s0;
            var_s1 &= ~2;
        }
    } else {
        if (temp_s0 == 0) {
            var_v1 = 0;
        } else if (temp_s0->unkC == D_80142C38) {
            var_v1 = 0;
        } else if (temp_s0->unkC == func_802BA310_de()) {
            var_v1 = 0;
        } else if (temp_s0->unkC == D_80142C30) {
            var_v1 = 0;
        } else {
            var_v1 = temp_s0;
        }
        if (var_v1 != 0) {
            temp_v0_2 = temp_s0->unk8 & 7;
            switch (temp_v0_2) {
            case 1:
            case 4:
            case 5:
                break;
            case 3:
                if (temp_s0->unk4 & 0x20) {
                    if (var_s1 & 2) {
                        *arg1 = temp_s0;
                        var_s1 &= ~2;
                        if (temp_s0->unk4 & 1) {
                            *arg2 = temp_s0;
                            var_s1 &= ~1;
                        }
                        arg0->unk2E8 = arg0->unk2E8->unk0;
                        if (arg0->unk2E8 == 0) {
                            arg0->unk2F0 = 0;
                        }
                    }
                } else if (var_s1 == 3) {
                    *arg2 = temp_s0;
                    *arg1 = temp_s0;
                    arg0->unk2E8 = arg0->unk2E8->unk0;
                    var_s1 = 0;
                    if (arg0->unk2E8 == 0) {
                        arg0->unk2F0 = 0;
                    }
                }
                break;
            case 2:
            case 6:
            case 7:
                temp_v1 = temp_s0->unk4;
                if (temp_v1 & 2) {
                    if (var_s1 & 2) {
                        *arg1 = temp_s0;
                        var_s1 &= ~2;
                    }
                } else if ((temp_v1 & 1) && (var_s1 & 1)) {
                    *arg2 = temp_s0;
                    arg0->unk2E8 = arg0->unk2E8->unk0;
                    var_s1 &= ~1;
                    if (arg0->unk2E8 == 0) {
                        arg0->unk2F0 = 0;
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

void osScAddClient(void *arg0, void *arg1, s32 arg2) {
    s32 temp_v0;
    temp_v0 = func_802BD170_de(1);
    (((struct ObjRecAt4V3 *) ((s8 *) arg1))->unk4) = arg2;
    (((struct ObjRecAt4V3 *) ((s8 *) arg1))->unk0) = (void *) (((struct ObjectLinks2E4 *) ((s8 *) arg0))->unk_2E0);
    (((struct ObjectLinks2E4 *) ((s8 *) arg0))->unk_2E0) = arg1;
    func_802BD170_de(temp_v0);
}

void func_8028F8BC_de(void *arg0, void *arg1) {
    s32 saved;
    OSScClientWork *cur;
    OSScClientWork *prev;

    prev = 0;
    cur = ((OSSched *)arg0)->clientList;
    saved = func_802BD170_de(1);
    while (cur != 0) {
        if (cur == arg1) {
            if (prev != 0) {
                prev->next = cur->next;
            } else {
                ((OSSched *)arg0)->clientList = cur->next;
            }
            break;
        }
        prev = cur;
        cur = cur->next;
    }
    func_802BD170_de(saved);
}

/** Return the address 0x78 bytes into the supplied object. */
void *func_8028F94C_de(void *object) {
    ObjRecAt78V2 *record = object;
    return &record->unk78;
}

void __scAppendList(void *arg0, void *arg1) {
    void *temp_v0;

    if ((((struct OSScTask_s *)arg1)->list.type) == 2) {
        temp_v0 = ((OSSched *)arg0)->audioListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            ((OSSched *)arg0)->audioListHead = arg1;
        }
        ((OSSched *)arg0)->audioListTail = arg1;
        ((OSSched *)arg0)->doAudio = 1;
    } else {
        temp_v0 = ((OSSched *)arg0)->gfxListTail;
        if (temp_v0 != 0) {
            ((struct OSScTask_s *)temp_v0)->next = arg1;
        } else {
            ((OSSched *)arg0)->gfxListHead = arg1;
        }
        ((OSSched *)arg0)->gfxListTail = arg1;
    }
    ((struct OSScTask_s *)arg1)->next = 0;
    ((struct OSScTask_s *)arg1)->state = (((struct OSScTask_s *)arg1)->flags) & 3;
}

void *func_8028F9AC_de(void *arg0) {
    s32 f1a;
    s32 f1b;
    void *v2;

    if (arg0 == 0) {
        return 0;
    }
    f1a = (s32)((struct OSScTask_s *)arg0)->framebuffer;
    if (f1a == D_80142C38) {
        return 0;
    }
    v2 = func_802BA310_de();
    f1b = (s32)((struct OSScTask_s *)arg0)->framebuffer;
    if (f1b == (s32)v2) {
        return 0;
    }
    if (f1b != D_80142C30) {
        return arg0;
    }
    return 0;
}

s32 func_8028FA0C_de(void *arg0, void *arg1) {
    if ((((s32)((struct OSScTask_s *)arg1)->state)) & 3) {
        return 0;
    }
    if ((((struct OSScTask_s *)arg1)->list.type) != 1) {
        return 1;
    }
    if (((((s32)((struct OSScTask_s *)arg1)->flags)) & 0x60) != 0x60) {
        return 1;
    }
    osViSwapBuffer(((s32)((struct OSScTask_s *)arg1)->framebuffer));
    return 1;
}

void func_8028FA60_de(View_func_8028FA60_de *view, Scene_func_8028FA60_de *current, Scene_func_8028FA60_de *next) {
    s64 now;

    if (next != 0 && (next->options & 0x20) && !(next->flags & 0x10)) {
        D_8011B1E8 = func_802BADC0_de();
    }
    if (current != 0) {
        if (current->mode == 2) {
            osWritebackDCacheAll();
            D_8011B1D0 = func_802BADC0_de();
        } else if (current->options & 0x20) {
            now = func_802BADC0_de();
            D_8011B1E0 = now;
            if (!(current->flags & 0x10)) {
                D_8011B1F0 = now;
                D_8011B1D8 = 0;
            }
        }
        current->flags &= ~0x30;
        func_802B9E78_de(&current->mode);
        osSpTaskStartGo(&current->mode);
        view->current = current;
        if (current == next) {
            view->next = next;
        }
    }
    if (next != 0 && next != current) {
        func_802B7B90_de(next->music, *next->time);
        D_800CD710 = 1;
        D_800CD714 = 0;
        view->next = next;
    }
}

void __scYield(void *arg0) {
    void *temp_a0;
    temp_a0 = (((struct ObjectLinks2F8 *) ((s8 *) arg0))->unk_2F4);
    if ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_10) == 1) {
        (((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) = (s32) ((((struct IntegerState14 *) ((s8 *) temp_a0))->unk_4) | 0x10);
        func_802BA120_de();
    }
}

void func_8028FC10_de(void *arg0) {
    Node_func_8028FC10_de *node = 0;
    s32 value1 = 0;
    s32 value2 = 0;
    s32 flags;

    while (func_802BB2A0_de(&((View_func_8028FA60_de *)arg0)->messages, &node, 0) != -1) {
        if (node->type == 1 && (node->flags & 0x20) && D_800CD704 == 0) {
            D_800CD704 = 2;
            func_802BB5F0_de(&D_80106248, D_800CD8B8_de);
        }
        __scAppendList(arg0, node);
    }

    if (((View_func_8028FA60_de *)arg0)->pending != 0 &&
        ((View_func_8028FA60_de *)arg0)->current != 0) {
        __scYield(arg0);
        return;
    }

    flags = (((View_func_8028FA60_de *)arg0)->current == 0) * 2 |
            (((View_func_8028FA60_de *)arg0)->next == 0);
    if (((s32 (*)(void *, s32 *, s32 *, s32))func_8028F544_de)(arg0, &value1, &value2, flags) != flags) {
        ((void (*)(void *, s32, s32))func_8028FA60_de)(arg0, value1, value2);
    }
}

int func_8028FD44_de(int arg0) {
    return arg0 + 0x40;
}
