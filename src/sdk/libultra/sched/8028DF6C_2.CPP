#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "sdk/SCHED/8028DF6C_2.H"
#include "sdk/os.h"
#include "RENDER_4/8028FD2C_6.H"
#if defined(VERSION_US)
#include "COMMON/EXTERNS_18.H"
extern s32 D_800CD708, D_800CD70C, D_800E28D8;
extern f32 D_800C5350_de;
extern char D_800D47B0[], D_800D4530[];
extern void osViSetYScale(f32);
extern void osViSetMode(void *);
extern void osViBlack(s32);
extern void func_802BA700_de(s32);
extern void func_8028EACC_de(OSSched *);
extern void Frontend_UpdateScreenMode(void);
extern void func_8028EDA0_de(void *);
extern void func_8028F278_de(OSSched *);
extern void func_8025E318_de(void);
extern void func_8025E214_de(s32);
extern void *func_8025CC6C_de(void);
extern void func_8025CBEC_de(void *);
extern void func_8028FC10_de(OSSched *);

void func_8028E880_us(OSSched *sc) {
    void *msg;
    OSScClientWork *client;
    for (;;) {
        osRecvMesg(&sc->interruptQueue, &msg, 1);
        switch ((s32)msg) {
        case 0x29A:
            if (D_800CD708 && --D_800CD70C <= 0) {
                osViBlack(1);
                for (;;) {}
            }
            func_8028EACC_de(sc);
            Frontend_UpdateScreenMode();
            break;
        case 0x29B: func_8028EDA0_de(sc); break;
        case 0x29C: func_8028F278_de(sc); break;
        case 0x29D:
            func_8025E318_de();
            func_8025E214_de(-1);
            func_8025CBEC_de(func_8025CC6C_de());
            client = sc->clientList;
            D_800CD708 = 1;
            D_800CD70C = 20;
            while (client) {
                osSendMesg(client->queue, &sc->retraceMessage, 0);
                client = client->next;
            }
            break;
        case 6: func_8028FC10_de(sc); break;
        }
    }
}
#endif
#if defined(VERSION_US)
char rodata_unresolved_800C5274[12] =
    "bAdvanceCame";
#endif
