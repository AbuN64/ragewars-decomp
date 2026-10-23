#include "include_asm.h"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/UNUSED.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/80256220.H"
#include "COMMON/LISTNODE.H"
#include "TYPES.H"
#include "sdk/os.h"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"
extern void func_802598B4_de(ChannelSet *arg0, s32 arg1);

/* Stops every voice playing a sound id while holding the manager's recursive lock at 0x110: tells
 * func_802598B4_de about the id, then for each of the 17 voice records whose sound matches it counts the voice
 * and either resets the spare record 16 or clears the voice's pending flag and stops its channel through
 * func_8025BA9C_de when it has a handle; returns the number of voices found (0 for id -1). Lock handling
 * adapted from func_802588D4_de; the voice records are addressed by offset from the manager.
 */





extern u32 func_802BCF30_de(void);

extern void func_8025BA9C_de(void *, s16);






s32 func_80257A14_de(void *arg0, s32 id) {
    void *temp_s0;
    void *var_a0;
    s32 temp_v1;
    u32 temp_a0;
    u32 temp_v0;
    s32 found;
    s32 i;
    Voice *voice;

    found = 0;
    if (id == -1) {
        return found;
    }
    temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
    temp_a0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 1) {
        __osRestoreInt(temp_a0);
        func_802BB2A0_de(temp_s0, 0, 1);
        var_a0 = &((ContextRecAt2BC0 *)(arg0))->view[0];
    } else {
        __osRestoreInt(temp_a0);
        var_a0 = &((ContextRecAt2BC0 *)(arg0))->view[0];
    }
    func_802598B4_de(var_a0, id);
    for (i = 0; i < 17; i++) {
        if (((ContextRecAt2BC0 *)arg0)->voices[i].sound == id) {
            found++;
            voice = &((ContextRecAt2BC0 *)arg0)->voices[i];
            if (i == 16) {
                voice->sound = -1;
                voice->priority = 0;
                voice->channel = -1;
                voice->unkC = -1;
                voice->unk8 = -1;
            } else {
                if (voice->pending > 0) {
                    voice->pending = 0;
                    voice->flags &= ~0x10;
                }
                if ((&((ContextCode8025A3EC *)arg0)->slots)[0].ids[i] != -1) {
                    func_8025BA9C_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], i);
                }
            }
        }
    }
    temp_s0 = &((ContextRecAt2BC0 *)(arg0))->lock;
    temp_v0 = func_802BCF30_de();
    temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
    ((MenuRules *)(temp_s0))->locked = temp_v1;
    if (temp_v1 != 0) {
        __osRestoreInt(temp_v0);
        func_802BB420_de(temp_s0, 0, 1);
    } else {
        __osRestoreInt(temp_v0);
    }
    return found;
}

#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "AUDIO/80259280_5.H"

extern void *func_802395A4_de(MenuMatchGlobals *, CVector3 *);
extern s32 func_8025BA4C_de(void *, s32);
extern f32 func_8025C10C_de(CVector3 *, void *);
extern s32 func_8025BDAC_de(void *, s32, s32);
extern s32 func_80259260_de(void *, Item57BD4 *, CVector3 *, s32, s32);

extern void *func_8025B1C8_de(void *, Item57BD4 *, s32, s32);
extern void func_8025BB5C_de(void *, CVector3 *, s32);

extern void func_8025BB84_de(void *, Item57BD4 *, s32);
extern void func_802577F4_de(void *, void *, s32, CVector3 *);
extern u32 func_802BCF30_de(void);








s32 func_80257BB4_de(void *arg0, Item57BD4 *arg1, CVector3 *arg2, s32 arg3,
                  s32 arg4, s32 arg5, s32 arg6) {
    void *node;

    ((ContextRecAt2BC0 *)(arg0))->field2B98 = func_802395A4_de(&D_80145088, arg2);
    if (arg1->flags & 1) {
        if (func_8025BA4C_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C) != 0) {
            return -1;
        }
        if (func_8025C10C_de(arg2, (char *)((ContextRecAt2BC0 *)(arg0))->field2B98 + 0x128) == 0.0f) {
            return -1;
        }
    }
    if ((arg1->flags & 0x1000) && ((ContextRecAt2BC0 *)(arg0))->field2B90 != -1) {
        if (func_8025BDAC_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C,
                         ((ContextRecAt2BC0 *)(arg0))->field2B90) != -1) {
            return -1;
        }
    }
    if (arg1->field2 != 0) {
        return func_80259260_de(&((ContextRecAt2BC0 *)(arg0))->view[0], arg1, arg2, arg3, arg5);
    }
    if (arg1->flags & 0x40) {
        func_8025B920_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], ((ContextRecAt2BC0 *)(arg0))->field2B8C, arg1->field0);
    }
    node = func_8025B1C8_de(&((ContextRecAt2BC0 *)(arg0))->menu[0], arg1, arg3, arg4);
    if (node == 0) {
        return -1;
    }
    func_8025BB5C_de(node, arg2, arg6);
    func_8025BB7C_de(node, ((ContextRecAt2BC0 *)(arg0))->field2B8C);
    func_8025BB84_de(node, arg1, arg5);

    {
        char *queue = &((ContextRecAt2BC0 *)(arg0))->lock;
        u32 token = func_802BCF30_de();
        s32 count = ((MenuRules *)(queue))->locked + 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 1) {
            __osRestoreInt(token);
            func_802BB2A0_de(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    func_802577F4_de(arg0, ((Draw *)(node))->model, 0, arg2);
    {
        char *queue = &((ContextRecAt2BC0 *)(arg0))->lock;
        u32 token = func_802BCF30_de();
        s32 count = ((MenuRules *)(queue))->locked - 1;
        ((MenuRules *)(queue))->locked = count;
        if (count != 0) {
            __osRestoreInt(token);
            func_802BB420_de(queue, 0, 1);
        } else {
            __osRestoreInt(token);
        }
    }
    return 0;
}

#ifdef NON_MATCHING
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/ARG.H"
#include "COMMON/EXTERNS_11.H"
#include "COMMON/EXTERNS_14.H"
#include "COMMON/SELF.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/TRIPLE.H"
#include "stddef.h"
#include "TYPES.H"
s32 func_80257BB4_de(void *arg0, Item57BD4 *arg1, CVector3 *arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
s32 func_80257DD4_de(void *arg0, s32 arg1, u32 arg2, u32 arg3, u32 arg4, s32 arg5, s32 arg6) {
    union { u32 word; f32 value; } xbits, ybits, zbits;
    CVector3 position;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    OSMesgQueue *temp_s0;
    OSMesgQueue *temp_s0_2;
    s32 *var_a0_2;
    s32 *var_a0_3;
    s32 *var_a0_4;
    s32 *var_a0_5;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_lo;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a0;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_a3_3;
    s32 var_s0;
    s32 var_s0_2;
    s32 var_s0_3;
    s32 var_s0_4;
    s32 var_s1;
    s32 var_s2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    s32 var_v1;
    s8 *temp_v0_3;
    u16 temp_s1;
    u32 temp_a0;
    u32 temp_s5;
    u32 temp_v0_4;
    u32 var_s0_5;
    void *var_v1_2;

    xbits.word = arg2; ybits.word = arg3; zbits.word = arg4;
    position.x = xbits.value; position.y = ybits.value; position.z = zbits.value;

    if (((s16 *) arg0)[258 / sizeof(s16)] != -1) {
        var_v1 = 1;
    } else {
        var_a1 = 0;
        if (arg1 < 0x100) {
            var_a0 = 0;
            var_v1_2 = arg0;
            do {
                if (((s32 *) var_v1_2)[7780 / sizeof(s32)] == arg1) {
                    var_a1 += 1;
                }
                var_a0 += 1;
                var_v1_2 += 0xCC;
            } while (var_a0 < 0x11);
            var_v1 = 1;
            if (var_a1 < 6) {
                goto block_8;
            }
        } else {
block_8:
            var_v1 = 0;
        }
    }
    var_v0 = -1;
    if (var_v1 == 0) {
        if (arg1 < 0x100) {
            temp_s1 = ((u16 *) arg0)[306 / sizeof(u16)];
            var_s0 = 0;
            if ((((s32 *) arg0)[11092 / sizeof(s32)] != 0) && (func_80265550_de(((u32 **) arg0)[11096 / sizeof(u32 *)], ((s32 *) arg0)[11092 / sizeof(s32)], (u32) (s16) arg1, &sp20, &sp24) != 0)) {
                var_a3 = sp20;
                if (var_a3 != sp24) {
                    var_a1_2 = var_a3;
                    if (sp24 >= var_a3) {
                        var_a0_2 = (var_a3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
                        do {
                            temp_v0 = *var_a0_2;
                            var_a0_2 += 4;
                            var_a1_2 += 1;
                            var_s0 += temp_v0 * 0xA;
                        } while (sp24 >= var_a1_2);
                    }
                    temp_a2 = func_802744D4_de() % var_s0;
                    var_a3_2 = sp20;
                    var_s0_2 = 0;
                    if (var_a3_2 < sp24) {
                        var_a0_3 = (var_a3_2 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
loop_19:
                        var_s0_2 += *var_a0_3 * 0xA;
                        var_v0_2 = temp_s1 << 0x10;
                        if (var_s0_2 < temp_a2) {
                            var_a3_2 += 1;
                            var_a0_3 += 4;
                            if (var_a3_2 >= sp24) {
                                goto block_21;
                            }
                            goto loop_19;
                        }
                    } else {
block_21:
                        var_v0_2 = temp_s1 << 0x10;
                    }
                    var_s1 = var_a3_2;
                    if ((var_v0_2 != 0) && (var_a3_2 == ((s32 *) arg0)[304 / sizeof(s32)])) {
                        if (var_a3_2 != sp24) {
                            var_a3 = var_a3_2 + 1;
                        } else {
                            var_a3 = var_a3_2 - 1;
                        }
                        goto block_28;
                    }
                } else {
block_28:
                    var_s1 = var_a3;
                }
            } else {
                var_s1 = -1;
            }
            ((s8 *) arg0)[11156 / sizeof(s8)] = (s8) (s32) func_80274564_de(D_800C3EDC_de);
        } else {
            var_s0_3 = 0;
            if (((s32 *) arg0)[11092 / sizeof(s32)] != 0) {
                var_s1 = -1;
                if (func_80265550_de(((u32 **) arg0)[11096 / sizeof(u32 *)], ((s32 *) arg0)[11092 / sizeof(s32)], (u32) (s16) arg1, &sp28, &sp2C) != 0) {
                    var_a3_3 = sp28;
                    if (var_a3_3 != sp2C) {
                        var_a1_3 = var_a3_3;
                        if (sp2C >= var_a3_3) {
                            var_a0_4 = (var_a3_3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
                            do {
                                temp_v0_2 = *var_a0_4;
                                var_a0_4 += 4;
                                var_a1_3 += 1;
                                var_s0_3 += temp_v0_2 * 0xA;
                            } while (sp2C >= var_a1_3);
                        }
                        temp_a2_2 = func_802744D4_de() % var_s0_3;
                        var_a3_3 = sp28;
                        var_s0_4 = 0;
                        if (var_a3_3 < sp2C) {
                            var_a0_5 = (var_a3_3 * 4) + ((s32 *) arg0)[11100 / sizeof(s32)];
loop_39:
                            var_s0_4 += *var_a0_5 * 0xA;
                            var_s1 = var_a3_3;
                            if (var_s0_4 < temp_a2_2) {
                                var_a3_3 += 1;
                                var_a0_5 += 4;
                                if (var_a3_3 >= sp2C) {
                                    goto block_41;
                                }
                                goto loop_39;
                            }
                        } else {
                            goto block_41;
                        }
                    } else {
block_41:
                        var_s1 = var_a3_3;
                    }
                }
            } else {
                var_s1 = -1;
            }
        }
        var_v0 = -1;
        if (var_s1 != -1) {
            ((s8 **) arg0)[11144 / sizeof(s8 *)] = func_8028FDB4_de(func_8028FDB4_de(((s32 **) arg0)[11084 / sizeof(s32 *)], (s32) (s16) var_s1), 0);
            ((s16 *) arg0)[11148 / sizeof(s16)] = (s16) arg1;
            ((s32 *) arg0)[11152 / sizeof(s32)] = arg6;
            temp_v0_3 = func_8028FDB4_de(func_8028FDB4_de(((s32 **) arg0)[11084 / sizeof(s32 *)], (s32) (s16) var_s1), 1);
            temp_s5 = ((u32 *) temp_v0_3)[4 / sizeof(u32)];
            var_s2 = -1;
            if (temp_s5 != 0) {
                temp_s0 = arg0 + 0x110;
                temp_a0 = func_802BCF30_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_v1 = *((s32 *) ((u8 *) (temp_s0) + 28)) + 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0) + 28)) = temp_v1;
                if (temp_v1 != 1) {
                    __osRestoreInt(temp_a0);
                    func_802BB2A0_de(temp_s0, NULL, 1);
                } else {
                    __osRestoreInt(temp_a0);
                }
                temp_s0_2 = arg0 + 0x110;
                var_s2 = ((s32 *) arg0)[268 / sizeof(s32)] + 1;
                ((s32 *) arg0)[268 / sizeof(s32)] = var_s2;
                temp_v0_4 = func_802BCF30_de();
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                temp_v1_2 = *((s32 *) ((u8 *) (temp_s0_2) + 28)) - 1;
    /* FAKEMATCH: Fuzzy draft preserves native scalar offsets absent from shared fields. */
                *((s32 *) ((u8 *) (temp_s0_2) + 28)) = temp_v1_2;
                if (temp_v1_2 != 0) {
                    __osRestoreInt(temp_v0_4);
                    func_802BB420_de(temp_s0_2, 0, 1);
                    var_v0_3 = arg1 < 0x100;
                } else {
                    __osRestoreInt(temp_v0_4);
                    var_v0_3 = arg1 < 0x100;
                }
                if (var_v0_3 != 0) {
                    ((s32 *) arg0)[304 / sizeof(s32)] = var_s1;
                    goto block_55;
                }
                var_s0_5 = 0;
            } else {
block_55:
                var_s0_5 = 0;
            }
            if (temp_s5 != 0) {
                do {
                    temp_lo = var_s0_5 * ((s32 *) temp_v0_3)[0 / sizeof(s32)];
                    var_s0_5 += 1;
                    func_80257BB4_de(arg0, (void *)(temp_v0_3 + temp_lo + 8), &position, var_s1, var_s2, 0, arg5);
                } while (var_s0_5 < temp_s5);
            }
            ((s32 *) arg0)[11152 / sizeof(s32)] = -1;
            var_v0 = var_s2;
        }
    }
    return var_v0;
}
#else
INCLUDE_ASM("span_1000", func_80257DD4_de);
#endif

#ifdef NON_MATCHING
/* Starts a sound-bank entry: looks up the entry's record in the bank table at 0x2B4C, resets the current
 * selection (0x2B88/0x2B8C/0x2B90), takes the recursive lock at 0x110 to hand out a new play id (counter
 * at 0x10C), then starts every voice record of the entry through func_80257BB4_de at the given position;
 * returns the play id, or -1 for an out-of-range index or an empty entry. */
s32 func_8025826C_de(ContextRecAt2BC0 *self, s32 index, CVector3 position, s32 arg3) {
    u32 *entry;
    u32 count;
    u32 i;
    s32 playId = -1;
    if (index >= self->instrumentCount) {
        return -1;
    }
    self->field2B88 = func_8028FDB4_de(func_8028FDB4_de(self->instrumentIndex, (s16)index), 0);
    self->field2B8C = 0x100;
    self->field2B90 = -1;
    entry = func_8028FDB4_de(func_8028FDB4_de(self->instrumentIndex, (s16)index), 1);
    count = entry[1];
    if (count != 0) {
        {
            char *queue = &self->lock;
            u32 token = func_802BCF30_de();
            s32 held = ((MenuRules *)(queue))->locked + 1;
            ((MenuRules *)(queue))->locked = held;
            if (held != 1) {
                __osRestoreInt(token);
                func_802BB2A0_de(queue, 0, 1);
            } else {
                __osRestoreInt(token);
            }
        }
        playId = *(s32 *)((char *)self + 0x10C) + 1;
        {
            char *queue = &self->lock;
            u32 token;
            s32 held;
            *(s32 *)((char *)self + 0x10C) = playId;
            token = func_802BCF30_de();
            held = ((MenuRules *)(queue))->locked - 1;
            ((MenuRules *)(queue))->locked = held;
            if (held != 0) {
                __osRestoreInt(token);
                func_802BB420_de(queue, 0, 1);
            } else {
                __osRestoreInt(token);
            }
        }
    }
    if (count != 0) {
        for (i = 0; i < count; i++) {
            func_80257BB4_de(self, (Item57BD4 *)((char *)entry + 8 + i * entry[0]), &position, index, playId, 0, arg3);
        }
    }
    return playId;
}
#else
INCLUDE_ASM("span_1000", func_8025826C_de);
#endif
