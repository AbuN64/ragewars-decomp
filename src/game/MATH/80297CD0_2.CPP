#include "MATH/802A2870.H"
#include "MATH/SHARED_WIDGETIDE.H"
#include "COMMON/INTEGERSTATE530.H"
#include "TYPES.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHARED_MENUREPLY.H"
#include "COMMON/TRIPLE.H"
#include "MATH/80297CD0.H"
#include "FRONTEND/8040B45C_32.H"

static inline s32 menuCategory(s32 event) {
    s32 category;
    if ((u32)event < 0xE00) category=0;
    else if ((u32)(event-0x1000)<0x1000) category=1;
    else if ((u32)(event-0xE00)<0x200) category=2;
    else if ((u32)(event-0x4000)<0x4000) category=3;
    else category=0;
    return category;
}
s32 func_80297A34_de(s32 event,s32 value,s32 amount,s32 context) {
    s32 *handled;
    Element *element;
    Element *focus;
    s32 result;
    s32 category;
    s32 saved;
    s32 focusId;
    s32 ticks;
    MenuElementHandler handler;
    handled=&D_8014D080->handled;
    element=D_8014D080->screens[D_8014D080->current].primary;
    result=0;
    func_80299958_de();
    category=menuCategory(event);
    switch(category) {
    case 0:
        focus=D_8014D080->screens[D_8014D080->current].focus;
        focusId=focus ? focus->id : -1;
        result=DispatchElementEvent(focusId,event,value,amount,context);
        break;
    case 2:
        if(event==0xE08) {
            ticks=(s32)(func_802A18CC_de()*D_800C5620_de);
            value=ticks-D_8014D080->frames;
            amount=ticks;
            D_8014D080->frames=amount;
        }
        saved=*handled;
        *handled=0;
        /* This dispatch passes a scalar event word as its fourth ABI argument. */
        ((void (*)(s32,s32,s32,s32,s32))func_8029764C_de)(1,event,value,amount,context);
        *handled=saved;
        break;
    case 1:
    case 3:
        saved=*handled;
        *handled=0;
        handler=D_8014D080->screens[D_8014D080->current].primary->handler;
        if(handler != 0)
            result=handler(element,event,value,amount,context);
        if(*handled==0) {
            value=0;
            category=menuCategory(event);
            switch(category) {
            case 0:
                switch(event) {
                case 5: case 6: case 7: case 8:
                    if(amount==1) func_80296CD0_de(event);
                    result=value;
                    break;
                case 1:
                    result=value;
                    if(element->flags & 0x10) {
                        if(element->linked_id) {
                            func_8029973C_de();
                            func_80298368_de(element->linked_id);
                        }
                    }
                    break;
                case 2:
                    result=value;
                    if(D_8014D080->current>0) func_802998A8_de();
                    break;
                case 15:
                    value=0;
                    func_8040E928_de(element,1);
                    result=value;
                    break;
                case 16:
                    value=0;
                    func_8040E928_de(element,value);
                    result=value;
                    break;
                case 3: case 4: case 9: case 10: case 11: case 12: case 13: case 14:
                    value=0;
                    break;
                default:
                    value=0;
                    result=value;
                    break;
                }
                break;
            case 1: value=0; break;
            case 2: value=0; break;
            case 3: value=0; break;
            default: break;
            }
            result=value;
        }
        *handled=saved;
        break;
    }
    return result;
}
