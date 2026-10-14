#include "gfx.h"
#include "common/unused.h"
#include "span_1000/code_80254CE4.h"
#include "n64sdk.h"
#include "gbi.h"
#include "types.h"

extern Gfx *D_80110634;
extern struct Shape_func_8021A2D4_de_2 D_80105180;
extern char D_80101140[];

extern u32 func_802BCF30_de(void);
extern void func_802BCF50_de(u32 mask);
extern void func_802BB2A0_de(void *queue, s32 msg, s32 flag);
extern s32 func_802BB420_de(void *queue, s32 msg, s32 flag);
extern void func_80268CE0_de(s32);
extern void func_8026925C_de(s32);

extern struct BlockRecAt20 *D_801011B0;

/* Draws the heap usage bar: a bordered box with one coloured band per tracked allocation, scaled to the
 * total heap size. */
void func_80252A44_de(s32 unused, s32 left, s32 top, s32 right, s32 bottom) {
    struct BlockRecAt20 *span;
    Node80254C10 *node;
    u32 total;
    u32 lock;
    s32 height;
    s32 pass;
    s32 select;
    s32 lo;
    s32 hi;
    s32 r;
    s32 g;
    s32 b;
    s32 full;
    s32 bright;
    u32 base;
    Gfx *cmd;

    gDPPipeSync(D_80110634++);
    gDPSetCycleType(D_80110634++, G_CYC_1CYCLE);
    func_80268CE0_de(0x19);
    func_8026925C_de(0x15);

    gDPSetPrimColor(D_80110634++, 0, 0, 0xA0, 0xA0, 0xA0, 0x00);
    gDPFillRectangle(D_80110634++, left - 1, top - 1, right + 1, bottom + 1);
    func_8026925C_de(0x1B);

    gDPSetPrimColor(D_80110634++, 0, 0, 0xA0, 0xA0, 0xA0, 0xFF);
    gDPFillRectangle(D_80110634++, left, top, right, bottom);

    lock = func_802BCF30_de();
    D_8010515C++;
    if (D_8010515C != 1) {
        func_802BCF50_de(lock);
        func_802BB2A0_de(D_80101140, 0, 1);
    } else {
        func_802BCF50_de(lock);
    }

    base = 0x80000000;
    span = D_801011B0;
    total = (u32)span - base;
    for (; span != 0; span = span->next) {
        total += span->size + span->free;
    }

    cmd = D_80110634++;
    gDPSetPrimColor(cmd, 0, 0, 0x64, 0x64, 0x00, 0xFF);
    height = bottom - top;
    hi = bottom - ((u32)(((u32)D_801011B0 - base) * height) / total) - 1;
    gDPFillRectangle(D_80110634++, left, hi, right, bottom + 1);

    for (pass = 0; pass < 2; pass++) {
        for (node = D_80100584.head; node != 0; node = node->next) {
            if (pass != 0) {
                select = (node->flags & 0x101) == 0x100;
            } else {
                select = (node->flags & 0x101) != 0x100;
            }
            if (select == 0) {
                continue;
            }

            if (node->flags & 1) { r = 255; g = 255; b = 0; }
            else if (node->flags & 0x100) { r = 255; g = 0; b = 0; }
            else if (node->flags & 0x600) { r = 0; g = 0; b = 255; }
            else { r = 0; g = 255; b = 0; }

            cmd = D_80110634++;
            gDPSetPrimColor(cmd, 0, 0, r, g, b, 0xFF);
            hi = bottom - ((u32)(((node->start + node->end) - base) * height) / total) - 1;
            lo = bottom - ((u32)(((node->start - base) - 0x20) * height) / total) - 1;
                    if (hi < lo) {
                gDPFillRectangle(D_80110634++, left, hi, right, lo);
            }

            gDPSetPrimColor(D_80110634++, 0, 0, ((s32)((u32)r >> 1)) < 0x100 ? ((s32)((u32)r >> 1)) : 0xFF, ((s32)((u32)g >> 1)) < 0x100 ? ((s32)((u32)g >> 1)) : 0xFF,
                            ((s32)((u32)b >> 1)) < 0x100 ? ((s32)((u32)b >> 1)) : 0xFF, 0xFF);
            gDPFillRectangle(D_80110634++, left, lo - 1, right, lo);

            if (!(node->flags & 0x702) && (u32)(D_80105180.field_0 - node->stamp) >= 5U) {
                b = 0xFF;
                gDPSetPrimColor(D_80110634++, 0, 0, 255, 255, 255, 255);
                for (;;) {
                    if (hi >= lo) break;
                    gDPFillRectangle(D_80110634++, left + 8, hi, right, lo);
                    break;
                }
                bright = (b * 3) >> 1;
                gDPSetPrimColor(D_80110634++, 0, 0, 255, 255, bright < 256 ? bright : 255, 255);
                gDPFillRectangle(D_80110634++, left + 8, lo - 1, right, lo);
            }
        }
    }

    lock = func_802BCF30_de();
    D_8010515C--;
    if (D_8010515C != 0) {
        func_802BCF50_de(lock);
        func_802BB420_de(D_80101140, 0, 1);
        return;
    }
    func_802BCF50_de(lock);
}
