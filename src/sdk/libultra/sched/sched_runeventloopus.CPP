#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "TYPES.H"
#include "sdk/SCHED/sched_runeventloopus.H"
#include "sdk/os.h"
#include "RENDER/SETN64_GETPACKSECTION.H"
#if defined(VERSION_US)
#include "COMMON/EXTERNS_18.H"
extern s32 D_800CD70C;
extern void osViBlack(s32);
extern void Sched_HandleRetrace(OSSched *);
extern void Frontend_UpdateScreenMode(void);
extern void Sched_HandleRdpCompletion(OSSched *);
extern void SoundElement_FadeOutMusic(void);
extern void *func_8025CC6C_de(void);
extern void func_8025CBEC_de(void *);
extern void Sched_HandleTaskCommands(OSSched *);

void Sched_RunEventLoopUs(OSSched *sc) {
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
            Sched_HandleRetrace(sc);
            Frontend_UpdateScreenMode();
            break;
        case 0x29B: Sched_HandleRspCompletion(sc); break;
        case 0x29C: Sched_HandleRdpCompletion(sc); break;
        case 0x29D:
            SoundElement_FadeOutMusic();
            SoundElement_StopAudioExceptKey(-1);
            func_8025CBEC_de(func_8025CC6C_de());
            client = sc->clientList;
            D_800CD708 = 1;
            D_800CD70C = 20;
            while (client) {
                osSendMesg(client->queue, &sc->retraceMessage, 0);
                client = client->next;
            }
            break;
        case 6: Sched_HandleTaskCommands(sc); break;
        }
    }
}
#endif
#if defined(VERSION_US)
char rodata_unresolved_800C5274[12] =
    "bAdvanceCame";
#endif
