#include "span_16E000/code_8042F988.h"
#include "span_C76B0/data.h"
#include "TYPES.H"
#include "common/unused.h"

/* Text metric records reuse current canonical TextBounds declarations. */
u32 func_80265350_de(void);
int func_802934F8_de(void);

u8 *func_8043F290(void *);
f32 func_804422F0_de(u8 *, f32, f32);
char * func_80442A58_de(char *);
extern s32 D_800E28D4;
extern s32 D_800E28D0; /* unable to generate initializer: unknown type */

extern f32 D_800DE448;
extern f32 D_800E247C;
#if defined(VERSION_EU)
extern f32 D_800EEAD0;
#else
extern f32 D_800DE450_de;
#endif
extern f32 D_800E2484;
#if defined(VERSION_EU)
extern f32 D_800EEAD8;
#else
extern f32 D_800DE458;
#endif
extern f32 D_800E248C;

extern TextBoundsFont D_800E1E24_de[];

void func_8043F52C_de(TextBoundsText *arg0, TextBoundsMetrics *arg1) {
    TextBoundsText current;
    TextBoundsMetrics first, second, third;
    s32 sp3C;
    s32 sp40;
    s32 sp64;
    s32 sp68;
    s32 sp8C;
    s32 sp90;
    s32 sp10;
    s16 sp14;
    s32 sp24;
    s32 sp38;
    s32 sp60;
    s32 sp88;
    s32 *var_v0_10;
    s32 *var_v0_12;
    s32 *var_v0_8;
    s32 *var_v1_3;
    s32 *var_v1_5;
    s32 *var_v1_7;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    f32 var_f0_4;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f3;
    s16 temp_v1;
    s32 *var_v0_11;
    s32 *var_v0_7;
    s32 *var_v0_9;
    s32 *var_v1_2;
    s32 *var_v1_4;
    s32 *var_v1_6;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 var_a0;
    s32 var_a0_2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_5;
    s32 var_v0_6;
    s32 var_v1_8;
    TextBoundsData *temp_v0;
    u8 *var_v0_3;
    u8 *var_v0_4;
    u32 temp_v1_2;
    u32 temp_v1_3;
    u8 var_v1;
    TextBoundsFont *temp_s1;
    TextBoundsRecord23 *temp_v0_2;

    u32 language;

    temp_v0 = (TextBoundsData *)func_80442A58_de((((TextBoundsDescriptor *)(((TextBoundsContext *)(arg0))->unk_24))->unk_44));
    (((TextBoundsState *)(arg1))->unk_10) = D_800DE428;
    (((TextBoundsState *)(arg1))->unk_C) = D_800DE428;
    temp_v1 = (((TextBoundsContext *)(arg0))->unk_4);
    switch (temp_v1) {
    case 0:
    case 5:
        var_a0 = 0;
        switch ((u32)arg0->flags & 0x3FE0) {
        case 0x20: var_a0 = 0; break;
        case 0x40: var_a0 = 1; break;
        case 0x80: var_a0 = 2; break;
        case 0x100: var_a0 = 3; break;
        case 0x200: var_a0 = 4; break;
        case 0x400: var_a0 = 5; break;
        case 0x800: var_a0 = 6; break;
        case 0x1000: var_a0 = 7; break;
        case 0x2000: var_a0 = 8; break;
        default: var_a0 = 0; break;
        }

#if defined(VERSION_EU)
        language = D_80152789;
        temp_s1 = &D_800E1E24_de[var_a0 + language * 9];
#else
        temp_s1 = &D_800E1E24_de[var_a0];
#endif

        if (temp_s1->kind == 0) {
            temp_f20 = temp_s1->width;
            if ((((TextBoundsContext *)(arg0))->unk_4) == 5) {
                var_v0_3 = func_8043F290(arg0);
            } else {
#if defined(VERSION_EU)
                var_v0_3 = ((u8 **)(arg0)->text)[language];
#else
                var_v0_3 = ((u8 **)(arg0)->text)[0];
#endif
            }
            var_f0 = func_804422F0_de((u8 *) var_v0_3, temp_f20, temp_f20);
        } else {
            var_s0 = 0;
            if ((((TextBoundsContext *)(arg0))->unk_4) == 5) {
                var_v0_4 = func_8043F290(arg0);
            } else {
#if defined(VERSION_EU)
                var_v0_4 = ((u8 **)(arg0)->text)[language];
#else
                var_v0_4 = ((u8 **)(arg0)->text)[0];
#endif
            }
            while (var_v0_4 != 0 && *var_v0_4 != 0 && *var_v0_4 != '\n') {
                var_v0_4++;
                var_s0++;
            }
            var_f0 = (f32) var_s0 * temp_s1->width;
        }
        (((TextBoundsState *)(arg1))->unk_4.v0) = (s32) var_f0;
        if (arg0->flags & 0x08000000) {
            arg1->height = (s32) ((f32) D_800E28D4 * D_800DE448);
        } else if ((temp_s1->kind == 2) && (D_800E28D4 >= 0xDF)) {
#if defined(VERSION_EU)
            arg1->height = (s32) ((temp_s1->height + D_800E247C) * (f32) D_800E28D4 * D_800EEAD0);
#else
            arg1->height = (s32) ((temp_s1->height + D_800E247C) * (f32) D_800E28D4 * D_800DE450_de);
#endif
        } else {
#if defined(VERSION_EU)
            arg1->height = (s32) (temp_s1->height * (f32) D_800E28D4 * D_800EEAD0);
#else
            arg1->height = (s32) (temp_s1->height * (f32) D_800E28D4 * D_800DE450_de);
#endif
        }
        (((TextBoundsState *)(arg1))->unk_4.v0) = (s32) (((((TextBoundsState *)(arg1))->unk_4.v0) * D_800E28D0) / 284);
        break;
    case 4:
        var_a0_2 = 0;
        switch ((u32)arg0->flags & 0x3FE0) {
        case 0x20: var_a0_2 = 0; break;
        case 0x40: var_a0_2 = 1; break;
        case 0x80: var_a0_2 = 2; break;
        case 0x100: var_a0_2 = 3; break;
        case 0x200: var_a0_2 = 4; break;
        case 0x400: var_a0_2 = 5; break;
        case 0x800: var_a0_2 = 6; break;
        case 0x1000: var_a0_2 = 7; break;
        case 0x2000: var_a0_2 = 8; break;
        default: var_a0_2 = 0; break;
        }

#if defined(VERSION_EU)
        language = D_80152789;
        temp_s1 = &D_800E1E24_de[var_a0_2 + language * 9];
#else
        temp_s1 = &D_800E1E24_de[var_a0_2];
#endif

        (((TextBoundsState *)(arg1))->unk_4.v0) = (s32) temp_s1->width;
        (((TextBoundsState *)(arg1))->unk_8) = (s32) (temp_s1->height * (f32) D_800E28D4 * D_800E2484);
        break;
    case 1:
        if (((func_802934F8_de() != 0) && ((((TextBoundsContext *)(arg0))->unk_8) & 0x40000000)) || ((D_801462E5 != 0) && ((((TextBoundsContext *)(arg0))->unk_8) < 0) && (func_80265350_de() == 0x400000))) {
            (((TextBoundsState *)(arg1))->unk_4.v0) = 0x11C;
            (((TextBoundsState *)(arg1))->unk_8) = 0xDE;
        } else {
            func_802AA950_de((s32) (((TextBoundsContext *)(arg0))->unk_14), 0, &((TextBoundsState *)(arg1))->unk_4.v0, &((TextBoundsState *)(arg1))->unk_8);
        }
        if (((((TextBoundsContext *)(arg0))->unk_8) & 0x10000000) && (temp_f3 = (f32) (((TextBoundsState *)(arg1))->unk_4.v0), (temp_f3 != 0.0f)) && (temp_f2 = (f32) (((TextBoundsState *)(arg1))->unk_8), (temp_f2 != 0.0f))) {
            var_f3 = temp_v0->unk_29C / temp_f3;
            var_f0_4 = temp_v0->unk_2A0 / temp_f2;
        } else {
#if defined(VERSION_EU)
            var_f3 = (f32) D_800E28D0 * D_800EEAD8;
#else
            var_f3 = (f32) D_800E28D0 * D_800DE458;
#endif
            var_f0_4 = (f32) D_800E28D4 * D_800E248C;
        }
        (((TextBoundsState *)(arg1))->unk_C) = var_f3;
        (((TextBoundsState *)(arg1))->unk_10) = var_f0_4;
        break;
    case 2:
        first = *arg1;
        current = *arg0;
        current.mode = 0;
        func_8043F52C_de(&current, &first);
        second = *arg1;
        current = *arg0;
        current.mode = 1;
        current.text = 0;
        func_8043F52C_de(&current, &second);
        third = *arg1;
        current = *arg0;
        current.mode = 1;
        current.text = 0;
        func_8043F52C_de(&current, &third);
        var_v1_8 = second.width + third.width;
        if (var_v1_8 < first.width) {
            var_v1_8 = first.width;
        }
        (((TextBoundsState *)(arg1))->unk_4.v0) = var_v1_8;
        (((TextBoundsState *)(arg1))->unk_8) = first.height + second.height + ((third.height - second.height) / 2);
        break;
    case 3:
        temp_v0_2 = (TextBoundsRecord23 *)(((TextBoundsContext *)(arg0))->unk_14);
        (((TextBoundsState *)(arg1))->unk_4.v0) = (s32) (((f32) temp_v0_2->unk_24 * temp_v0->unk_29C) / (f32) D_800E28D0);
        (((TextBoundsState *)(arg1))->unk_8) = (s32) (((f32) temp_v0_2->unk_28 * temp_v0->unk_2A0) / (f32) D_800E28D4);
        break;
    default:
        (((TextBoundsState *)(arg1))->unk_4.v0) = 1;
        (((TextBoundsState *)(arg1))->unk_8) = 1;
        break;
    }
    temp_a0 = (((TextBoundsContext *)(arg0))->unk_8);
    temp_f1 = (f32) (((((TextBoundsContext *)(arg0))->unk_C) * D_800E28D0) / 284);
    if (!(temp_a0 & 0x8000)) {
        if (temp_a0 & 0x4000) {
            (((TextBoundsState *)(arg1))->unk_14) = (s32) ((f32) (((TextBoundsState *)(arg1))->unk_18) + temp_f1);
        } else {
            (((TextBoundsState *)(arg1))->unk_14) = (s32) temp_f1;
        }
    }
    (((TextBoundsState *)(arg1))->unk_18) = (s32) ((f32) (((TextBoundsState *)(arg1))->unk_14) + ((f32) (((TextBoundsState *)(arg1))->unk_4.v0) * (((TextBoundsState *)(arg1))->unk_C)));
    temp_a0_2 = (((TextBoundsContext *)(arg0))->unk_8);
    temp_f1_2 = (f32) (((((TextBoundsContext *)(arg0))->unk_E) * D_800E28D4) / 222);
    if (!(temp_a0_2 & 0x20000)) {
        if (temp_a0_2 & 0x10000) {
            (((TextBoundsState *)(arg1))->unk_1C) = (s32) ((f32) (((TextBoundsState *)(arg1))->unk_20) + temp_f1_2);
        } else {
            (((TextBoundsState *)(arg1))->unk_1C) = (s32) temp_f1_2;
        }
    }
    (((TextBoundsState *)(arg1))->unk_20) = (s32) ((f32) (((TextBoundsState *)(arg1))->unk_1C) + ((f32) (((TextBoundsState *)(arg1))->unk_8) * (((TextBoundsState *)(arg1))->unk_10)));
}
