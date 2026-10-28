#include "MATH/N64_ENG.H"
#include "COMMON/CALLBACK.H"
#include "TYPES.H"
#include "COMMON/AUDIO_INITIALIZE.H"
#include "COMMON/FRUSTUM.H"
#include "COMMON/INTEGERSTATE530.H"
#include "MATH/SMSMNGR_INITIALIZESCREENMANAGER.H"
#include "RESMGR/STREAM.H"
#include "MATH/SM_SMNGR.H"

typedef struct Shared_MenuDefinition Shared_MenuDefinition;
struct Shared_MenuDefinition {
    u32 unknown00[3];
    s16 unkC;
    u16 unknown0E;
    u16 unknown10;
    u16 unk12;
    u32 unknown14[11];
    s32 unk40;
    Shared_MenuDefinition *unk44;
};
void SmSmngr_InitializeCurrentScreen(void);
void Menu_PopScreen(void);
void StreamBufferFree(StreamBuffer *);
void Stream_DrainResourceWork(void);
void Node_AcquireArchiveEntry(s32);
void Node_ReleaseReferencedBuffer(s32);

 


extern Shared_MenuDefinition *g_screenDefaultFocus;

void SmXlate_SwitchScreen(s32 index) {
    s32 (*temp_v0_10)(s32, s32, s32, s32);
    s32 (*temp_v0_11)(s32, s32, s32, s32);
    s32 (*temp_v0_14)(s32, s32, s32, s32);
    s32 (*temp_v0_15)(s32, s32, s32, s32);
    s32 (*temp_v0_16)(s32, s32, s32, s32);
    s32 (*temp_v0_17)(s32, s32, s32, s32);
    s32 (*callback)(s32, s32, s32, s32);
    s32 (*temp_v0_5)(s32, s32, s32, s32);
    s32 (*temp_v0_8)(s32, s32, s32, s32);
    s32 (*temp_v0_9)(s32, s32, s32, s32);
    s32 temp_s1;
    s32 temp_s1_2;
    s32 (*temp_a2)(s32);
    s32 (*temp_v0_7)(s32);
    s32 temp_a1;
    Shared_MenuDefinition *temp_a1_2;
    s32 argument;
    s32 e03_arg_copy; 
    s32 focus_index_final; 
    s32 focus_index; 
    s32 callback_status; 
    s32 callback_status_5; 
    s32 temp_s0_10;
    s32 temp_s0_11;
    s32 temp_s0_12;
    s32 owner;
    s32 handled;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 temp_s0_7;
    s32 temp_s0_8;
    s32 temp_s0_9;
    s32 current;
    s32 load_flag;
    s32 *transition_state;
    s32 menuScreenOwnerResult;
    s32 temp_v0_2;
    Shared_MenuDefinition *priorDefaultFocus; 
    s32 temp_v1;
    s32 search_bound; 
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_s1_2;
    s32 var_s2;
    ScreenEntry *search_entries;
    s32 var_s5;
    s32 var_v0;
    s32 var_v1_3;
    ScreenManager *temp_a0;
    ScreenEntry *temp_a0_2;
    ScreenEntry *temp_a0_3;
    Shared_MenuDefinition *focus;
    ScreenEntry *temp_a0_5;
    ScreenEntry *temp_a0_6;
    Shared_MenuDefinition *temp_a0_7;
    void *screens;
    Shared_MenuDefinition *temp_v0;
    Shared_MenuDefinition *temp_v0_13;
    Shared_MenuDefinition *temp_v0_3;
    Shared_MenuDefinition *temp_v0_6;
    ScreenManager *temp_v1_2;
    Shared_MenuDefinition *var_s1;
    struct MenuHandlerEntry *var_v0_2;
    ScreenEntry *var_v1;
    ScreenEntry *var_v1_2;

    Stream_DrainResourceWork();
    var_s2 = 0;
    var_s5 = 1;
    if (D_8014D080->current >= 0) {
        GetMenuScreenOwner();
    }
    temp_v1 = D_8014D080->current;
    screens = D_8014D080->screens;
    var_a0 = 0;
    if (temp_v1 >= 0) {
        search_bound = temp_v1;
        var_v1 = (void *)screens;
loop_4:
        var_a0 += 1;
        if (var_v1->owner == index) {
            goto block_found_trampoline;
        }
        var_v1++;
        if (search_bound >= var_a0) {
            goto loop_4;
        }
    }
    var_v0 = 0;
block_search_check:
    if (var_v0 == 0) {
        goto block_not_found;
    }
    {
        menuScreenOwnerResult = GetMenuScreenOwner();
        var_a0_2 = D_8014D080->lowIndex;
        temp_a1 = D_8014D080->current;
        if (temp_a1 >= var_a0_2) {
            search_entries = D_8014D080->screens;
            do {
                if (search_entries[var_a0_2].owner == index) {
                    var_s2 = 1;
                }
                var_a0_2 += 1;
            } while (temp_a1 >= var_a0_2);
        }
        temp_a0 = D_8014D080;
        if (((ScreenEntry *)screens)[temp_a0->current].owner != index) {
            do {
                temp_a0->field530 = 1;
                Menu_PopScreen();
                
                temp_a0 = D_8014D080;
            } while (((ScreenEntry *)screens)[D_8014D080->current].owner != index);
        }
        D_8014D080->cacheCount = 0;
        D_8014D080->focus = menuScreenOwnerResult;
        if (var_s2 == 0) {
            Node_AcquireArchiveEntry(index);
            temp_v0 = Node_GetScreenData(index);
            temp_a0_2 = ((void *)&D_8014D080->screens[D_8014D080->current]);
            temp_a0_2->primary = temp_v0;
            temp_a0_2->owner = index;
            temp_a0_2->focus = temp_v0->unk44;
            g_screenDefaultFocus = temp_v0->unk44;
            var_s1 = temp_v0;
            SmSmngr_InitializeCurrentScreen();
            if (((u16) var_s1->unk12 >> 0xC) & 1) {
                
                load_flag = 1;
                current = D_8014D080->current;
loop_18:
                if ((((u16) var_s1->unk12 >> 0xC) & 1) == load_flag) {
                    temp_v0_2 = --D_8014D080->current;
                    D_8014D080->lowIndex = temp_v0_2;
                    
                    var_a0 = D_8014D080->current;
                    Node_AcquireArchiveEntry(D_8014D080->screens[var_a0].owner);
                    owner = D_8014D080->screens[D_8014D080->current].owner;
                    temp_v0_3 = Node_GetScreenData(owner);
                    temp_a0_3 = ((void *)&D_8014D080->screens[D_8014D080->current]);
                    temp_a0_3->primary = temp_v0_3;
                    temp_a0_3->owner = owner;
                    temp_a0_3->focus = temp_v0_3->unk44;
                    g_screenDefaultFocus = temp_v0_3->unk44;
                    D_8014D080->cacheCount = 0;
                    var_s1 = temp_v0_3;
                    SmSmngr_InitializeCurrentScreen();
                    goto loop_18;
                }
                D_8014D080->current = current;
            }
            goto block_78;
block_found_trampoline:
            var_v0 = 1;
            goto block_search_check;
        } else {
            var_s1 = D_8014D080->screens[D_8014D080->current].primary;
            D_8014D080->cacheCount = 0;
            if (((ScreenManager *)D_8014D080)->current != -1) {
                callback = D_8014D080->callback;
                if (callback != 0) {
                    handled = D_8014D080->handled;
                    D_8014D080->handled = 0;
                    callback(0xE07, 0, 0, 0);
                    callback_status = D_8014D080->handled;
                    if (callback_status == 1) {
                        var_s5 = 0;
                        D_8014D080->handled = handled;
                        goto after_found_callback;
                    }
                    D_8014D080->handled = handled;
                }
                DispatchCurrentScreenEvent(1, 0xE07, 0, 0, 0);
                goto block_27;
            } else {
block_27:
                var_s5 = 0;
            }
        }
after_found_callback:
        goto block_78;
    }
block_not_found:
    Node_AcquireArchiveEntry(index);
    if (((u16) (((Shared_MenuDefinition *)(Node_GetScreenData(index)))->unk12) >> 0xC) & 1) {
        focus = D_8014D080->screens[D_8014D080->current].focus;
        if ((focus != 0) && ((temp_s1 = focus->unkC, (Node_IsValidScreenIndex((s32) temp_s1) == 0)) || (temp_s1 == D_8014D080->screens[D_8014D080->current].owner)) && ((focus_index = D_8014D080->current), (temp_s1 != D_8014D080->focus)) && ((temp_a1 = -1), (focus_index != temp_a1))) {
            temp_v0_5 = D_8014D080->callback;
            if (temp_v0_5 != 0) {
                temp_s0_4 = D_8014D080->handled;
                D_8014D080->handled = 0;
                temp_v0_5(0x10, 0, 0, 0);
                callback_status = D_8014D080->handled;
                if (callback_status == 1) {
                    D_8014D080->handled = temp_s0_4;
                    goto after_focus10;
                }
                D_8014D080->handled = temp_s0_4;
            }
            if (temp_s1 == (((Shared_MenuDefinition *)(D_8014D080->screens[D_8014D080->current].primary))->unkC)) {
                SmSmngr_DispatchPrimaryScreenEvent(0x10, 0, 0, 0);
            } else {
                DispatchElementEvent(temp_s1, 0x10, 0, 0, 0);
            }
        }
after_focus10:
        D_8014D080->focus = GetMenuScreenOwner();
        D_8014D080->current = (s32) (D_8014D080->current + 1);
        temp_v0_6 = Node_GetScreenData(index);
        temp_a0_5 = ((void *)&D_8014D080->screens[D_8014D080->current]);
        temp_a0_5->primary = temp_v0_6;
        temp_a0_5->owner = index;
        temp_a0_5->focus = temp_v0_6->unk44;
        var_s1 = temp_v0_6;
        g_screenDefaultFocus = var_s1->unk44;
        StreamBufferFree(&D_8014D080->screens[D_8014D080->current].data);
        temp_v0_7 = D_8014D080->callback2;
        if (temp_v0_7 != 0) {
            (((Shared_MenuDefinition *)(D_8014D080->screens[D_8014D080->current].primary))->unk40) = temp_v0_7(index);
        }
        D_8014D080->cacheCount = 0;
        if (D_8014D080->current != -1) {
            temp_v0_8 = D_8014D080->callback;
            if (temp_v0_8 != 0) {
                temp_s0_5 = D_8014D080->handled;
                D_8014D080->handled = 0;
                temp_v0_8(0xE06, 0, 0, 0);
                callback_status_5 = D_8014D080->handled;
                if (callback_status_5 == 1) {
                    D_8014D080->handled = temp_s0_5;
                    goto after_e06;
                }
                D_8014D080->handled = temp_s0_5;
            }
            DispatchCurrentScreenEvent(1, 0xE06, 0, 0, 0);
        }
after_e06:
        if (((ScreenManager *)D_8014D080)->current != -1) {
            temp_v0_9 = D_8014D080->callback;
            if (temp_v0_9 != 0) {
                temp_s0_6 = D_8014D080->handled;
                D_8014D080->handled = 0;
                temp_v0_9(0xE07, 0, 0, 0);
                callback_status = D_8014D080->handled;
                if (callback_status == 1) {
                    D_8014D080->handled = temp_s0_6;
                    goto block_78;
                }
                D_8014D080->handled = temp_s0_6;
            }
            DispatchCurrentScreenEvent(1, 0xE07, 0, 0, 0);
        }
        goto block_78;
    }
    if (D_8014D080->current != -1) {
        temp_v0_10 = D_8014D080->callback;
        if (temp_v0_10 != 0) {
            temp_s0_7 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_10(0xE01, 0, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_7;
                goto after_e01;
            }
            D_8014D080->handled = temp_s0_7;
        }
        SmSmngr_DispatchPrimaryScreenEvent(0xE01, 0, 0, 0);
    }
after_e01:
    Stream_DrainResourceWork();
    e03_arg_copy = index;
    if (D_8014D080->current != -1) {
        temp_v0_11 = D_8014D080->callback;
        if (temp_v0_11 != 0) {
            temp_s0_8 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_11(0xE03, index, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_8;
                goto after_e03;
            }
            D_8014D080->handled = temp_s0_8;
        }
        SmSmngr_DispatchPrimaryScreenEvent(0xE03, e03_arg_copy, 0, 0);
    }
after_e03:
    temp_v1_2 = D_8014D080;
    temp_v0_2 = temp_v1_2->current;
    var_s1_2 = temp_v1_2->lowIndex;
    if (temp_v0_2 >= 0) {
        if (temp_v0_2 >= var_s1_2) {
            var_s0 = var_s1_2;
            do {
                var_s1_2 += 1;
                Node_ReleaseReferencedBuffer(temp_v1_2->screens[var_s0].owner);
                temp_v1_2 = D_8014D080;
                D_8014D080->screens[var_s0].primary = 0;
                D_8014D080->screens[var_s0].focus = 0;
                var_s0 += 1;
            } while (D_8014D080->current >= var_s1_2);
        }
        var_v1_3 = 0x3F;
        var_v0_2 = D_8014D080->handlers;
        do {
            var_v0_2->override_handler = 0;
            var_v1_3 -= 1;
            var_v0_2++;
        } while (var_v1_3 >= 0);
        
        temp_v1_2 = D_8014D080;
    }
    temp_v1_2->lowIndex = temp_v1_2->current;
    D_8014D080->focus = GetMenuScreenOwner();
    D_8014D080->current = (s32) (D_8014D080->current + 1);
    temp_v0_13 = Node_GetScreenData(index);
    temp_a0_6 = ((void *)&D_8014D080->screens[D_8014D080->current]);
    temp_a0_6->primary = temp_v0_13;
    temp_a0_6->owner = index;
    temp_a0_6->focus = temp_v0_13->unk44;
    g_screenDefaultFocus = temp_v0_13->unk44;
    D_8014D080->lowIndex = (s32) D_8014D080->current;
    temp_a2 = D_8014D080->callback2;
    var_s1 = temp_v0_13;
    if (temp_a2 != 0) {
        (((Shared_MenuDefinition *)(D_8014D080->screens[D_8014D080->current].primary))->unk40) = temp_a2(index);
    }
    D_8014D080->cacheCount = 0;
    if (D_8014D080->current != -1) {
        temp_v0_14 = D_8014D080->callback;
        if (temp_v0_14 != 0) {
            temp_s0_9 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_14(0xE06, 0, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_9;
                goto after_e06_second;
            }
            D_8014D080->handled = temp_s0_9;
        }
        DispatchCurrentScreenEvent(1, 0xE06, 0, 0, 0);
    }
after_e06_second:
    if (((ScreenManager *)D_8014D080)->current != -1) {
        temp_v0_15 = D_8014D080->callback;
        if (temp_v0_15 != 0) {
            temp_s0_10 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_15(0xE07, 0, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_10;
                goto after_e07_second;
            }
            D_8014D080->handled = temp_s0_10;
        }
        DispatchCurrentScreenEvent(1, 0xE07, 0, 0, 0);
    }
after_e07_second:
    if (GetMenuScreenOwner() != index) {
        D_8014D080->cacheCount = 0;
        return;
    }
block_78:
    transition_state = &D_8014D080->field530;
    *transition_state = 1;
    while (var_s5 != 0) {
        var_s5 = 0;
        priorDefaultFocus = g_screenDefaultFocus;
        temp_a1_2 = var_s1->unk44;
        if (priorDefaultFocus != temp_a1_2) {
            
            temp_a0 = D_8014D080;
            temp_v1 = temp_a0->current;
            temp_a0->screens[temp_v1].focus = temp_a1_2;
        }
    }
    temp_a0_7 = D_8014D080->screens[D_8014D080->current].focus;
    if ((temp_a0_7 != 0) && ((temp_s1_2 = temp_a0_7->unkC, (Node_IsValidScreenIndex((s32) temp_s1_2) == 0)) || (temp_s1_2 == D_8014D080->screens[D_8014D080->current].owner)) && ((focus_index_final = D_8014D080->current), (temp_s1_2 != D_8014D080->focus)) && ((temp_a1 = -1), (focus_index_final != temp_a1))) {
        temp_v0_16 = D_8014D080->callback;
        if (temp_v0_16 != 0) {
            temp_s0_11 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_16(0xF, 0, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_11;
                goto after_focus;
            }
            D_8014D080->handled = temp_s0_11;
        }
        if (temp_s1_2 == (((Shared_MenuDefinition *)(D_8014D080->screens[D_8014D080->current].primary))->unkC)) {
            SmSmngr_DispatchPrimaryScreenEvent(0xF, 0, 0, 0);
        } else {
            DispatchElementEvent(temp_s1_2, 0xF, 0, 0, 0);
        }
    }
after_focus:
    if (D_8014D080->current != -1) {
        temp_v0_17 = D_8014D080->callback;
        if (temp_v0_17 != 0) {
            temp_s0_12 = D_8014D080->handled;
            D_8014D080->handled = 0;
            temp_v0_17(0xE08, 0, 0, 0);
            callback_status = D_8014D080->handled;
            if (callback_status == 1) {
                D_8014D080->handled = temp_s0_12;
                goto after_e08;
            }
            D_8014D080->handled = temp_s0_12;
        }
        argument = (s32)(N64Eng_GetTimeSeconds() * 1000.0);
        DispatchCurrentScreenEvent(1, 0xE08, argument - D_8014D080->frames, argument, 0);
    }
after_e08:
}
