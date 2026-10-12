#include "span_1000/code_802B0388.h"
#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802AE028.h"
#include "types.h"



extern void func_802AE6BC_de(s32 arg0, Message_func_802AF150_de *arg1);
extern s32 func_802AE9B0_de(s32 arg0, s32 *arg1);
extern void func_802AFB6C_de(void *arg0, Message_func_802AF150_de *arg1);
extern void func_802B00D4_de(ALEventQueue *, Message_func_802AF150_de *, s32);
extern void func_802BAC50_de(void *arg0, void *arg1, s32 arg2);
extern char D_800C7350_de[];
extern char D_800C7354_de[];





/** Dispatch the current object message and forward any resulting value. */
void func_802AF150_de(void *rawPlayer) {
    struct ALSeqPlayer_func_802B0C94_de *arg0 = rawPlayer;
    Message_func_802AF150_de message;
    Message_func_802AF150_de output;
    s32 value1;
    s32 value2;
    s32 value3;
    s32 field18;
    s32 value;

    field18 = (s32)arg0->target;
    if (field18 != 0) {
        func_802AE6BC_de(field18, &message);
        {
        s32 sw_message_value = (s16)((u16)message.type - 1);
        if ((unsigned int)sw_message_value > 19) {
            goto sw_message_default;
        }
        switch (sw_message_value) {
        case 0: goto sw_message_0;
        case 1: goto sw_message_default;
        case 2: goto sw_message_2;
        case 3: goto sw_message_3;
        case 4: goto sw_message_default;
        case 5: goto sw_message_default;
        case 6: goto sw_message_default;
        case 7: goto sw_message_default;
        case 8: goto sw_message_default;
        case 9: goto sw_message_default;
        case 10: goto sw_message_default;
        case 11: goto sw_message_default;
        case 12: goto sw_message_default;
        case 13: goto sw_message_default;
        case 14: goto sw_message_default;
        case 15: goto sw_message_default;
        case 16: goto sw_message_default;
        case 17: goto sw_message_17;
        case 18: goto sw_message_17;
        case 19: goto sw_message_17;
        }
    }
    do {
        sw_message_0:
            func_802AF2E0_de(arg0, &message);
            if (arg0->state == 1) {
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value1) & 0xFF)) {
                    output.type = 0;
                    value = value1;
                    goto send_value;
                }
            }
            break;
        sw_message_2:
            func_802AFB6C_de(arg0, &message);
            if (arg0->state == 1) {
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value2) & 0xFF)) {
                    output.type = 0;
                    value = value2;
                    goto send_value;
                }
            }
            break;
        sw_message_3:
            arg0->state = 2;
            message.type = 0x10;
            func_802B00D4_de(&arg0->evtq, &message, 0x7FFFFFFF);
            break;
        sw_message_17:
        sw_message_18:
        sw_message_19:
            if (arg0->state == 1) {
                field18 = (s32)arg0->target;
                if (field18 != 0 && (func_802AE9B0_de(field18, &value3) & 0xFF)) {
                    output.type = 0;
                    value = value3;
send_value:
                    func_802B00D4_de(&arg0->evtq, &output,
                                  value * arg0->uspt);
                }
            }
            break;
        sw_message_default:
            func_802BAC50_de(D_800C7350_de, D_800C7354_de, 0x190);
            break;
        
    } while (0);
    }
}
