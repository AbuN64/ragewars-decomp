#include "include_asm.h"
#include "COMMON/OBJECTLINKS1458.H"
#include "TYPES.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "AI/NAV/8020EAE0.H"

/* Commits a pending selection to the controller D_8013B364: returns at once when nothing is
   requested at 0xC, the request is already active at 0x4, or it continues the committed request at
   0x28 through valid links at 0x14 and 0x18 that are already current or that func_8020CC0C_de joins;
   otherwise it resets the controller, runs the pending release passes flagged at 0x2F4, 0x2F8 and
   0x2FC, rebuilds through func_8020EC14_de, loads the request, clears the controller's link word,
   reselects the active entry, copies the four link words from 0x14 and records the request as
   committed. Always returns 1. Written from its own assembly with early returns. */

extern s32 D_8013B364;
extern s32 func_8020CC0C_de(s32 *, s32, s32);
extern void func_8020D014_de(s32 *);
extern void func_8020EDCC_de(void *);
extern void func_8020EE50_de(void *);
extern void func_8020EEA4_de(void *);
extern void func_8020D1FC_de(s32 *);
extern void func_8020D220_de(s32 *, s32);
extern void func_8020D0CC_de(s32 *, s32);
extern void func_8020D114_de(s32 *, s32 *, s32);




s32 func_8020EAE0_de(void *arg0) {
    s32 *base;
    s32 requested;
    s32 current;
    s32 link;

    base = &D_8013B364;
    if (base == 0) {
        return 1;
    }
    requested = ((Func8020ED50Arg *)arg0)->fieldC;
    if (requested == -1) {
        return 1;
    }
    current = ((Func8020ED50Arg *)arg0)->field4;
    if (current == requested) {
        return 1;
    }
    if (((Func8020ED50Arg *)arg0)->committed == requested) {
        link = ((Func8020ED50Arg *)arg0)->links[0];
        if (link != -1 && ((Func8020ED50Arg *)arg0)->links[1] != -1) {
            if (current == link) {
                return 1;
            }
            if (func_8020CC0C_de(base, current, link) != -1) {
                return 1;
            }
        }
    }
    func_8020D014_de(base);
    if (((Func8020ED50Arg *)arg0)->releaseFlags[0] != 0) {
        func_8020EDCC_de(arg0);
    }
    if (((Func8020ED50Arg *)arg0)->releaseFlags[1] != 0) {
        func_8020EE50_de(arg0);
    }
    if (((Func8020ED50Arg *)arg0)->releaseFlags[2] != 0) {
        func_8020EEA4_de(arg0);
    }
    func_8020EC14_de(arg0);
    func_8020D1FC_de(base);
    func_8020D220_de(base, ((Func8020ED50Arg *)arg0)->fieldC);
    base[6] = -1;
    func_8020D0CC_de(base, ((Func8020ED50Arg *)arg0)->field4);
    func_8020D114_de(base, &((Func8020ED50Arg *)arg0)->links[0], 4);
    ((Func8020ED50Arg *)arg0)->linkState = 0;
    ((Func8020ED50Arg *)arg0)->selection = -1;
    ((Func8020ED50Arg *)arg0)->committed = ((Func8020ED50Arg *)arg0)->fieldC;
    return 1;
}

INCLUDE_ASM("span_1000", func_8020EC14_de);
