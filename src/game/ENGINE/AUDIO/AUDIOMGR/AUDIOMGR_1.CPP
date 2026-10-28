#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TEXTURE/80256220.H"
#include "COMMON/EFFECTRENDER.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "COMMON/ARG.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/SOUNDINFO.H"
#include "COMMON/SESSIONHANDLERROW.H"
#include "COMMON/GUMTXL2F.H"
#include "COMMON/EXTERNS_18.H"
#include "COMMON/LLDIVRESULT.H"
#include "TYPES.H"
#include "TYPES.H"
#include "SYSTEM/8025E280.H"
#include "SYSTEM/8025E280_3.H"
#include "TEXTURE/80256220_13.H"
#include "sdk/MATH/aigetlen.H"
#include "sdk/libgultra/OSWRITEBACKDCACHEALL.H"
#include "sdk/libgultra/part_800C7F20/alunlink.h"
#include "sdk/OSINT/osyieldthread.H"
#include "sdk/os.h"


extern u32 D_800CB710;









extern void Sound_RetireCompletedSampleWindows(Work56EC8 *arg0);


extern void *alAudioFrame(void *arg0, s32 *arg1, s32 arg2, s16 arg3);

extern void Sched_SendSchedulerTask(void *arg0, void *arg1);

extern void osAiSetNextBuffer(void *arg0, s32 arg1);

void Audiomgr_RunAudioWorker(void) {
    u32 stop, argument, frame;
    u64 previous;
    OSScClientWork client;
    union { void *message; u32 words[2]; } event;
    CacheCountdownEntry *entry;
    void *entryObject;
    stop = 0;
    argument = stop;
    frame = stop;
    previous = 0;
    osScAddClient(&D_80142928, &client, &D_80107E00);
    do {
        D_800CB710 = ((Audio_ReadSystemTime() - previous) << 6) / 3000ULL;
        osRecvMesg(&D_80107E00, &event.message, 1);
        previous = Audio_ReadSystemTime();
        switch (event.words[0]) {
        case 1:
            frame++;
            if (frame < 21) break;
            frame = 0;
        case 7:
            D_800CB70C_de++;
            while (!(osAiGetStatus() & 0x80000000)) {
                Audiomgr_RenderAudioFrame(D_80107E28[D_800CB700_de % 3], argument);
            }
            entryObject = D_80107DFC;
            for (entry = entryObject; entry; entry = entry->next) {
                if (entry->state) entry->state--;
            }
            break;
        case 4:
            break;
        }
    } while (stop == 0);
    alClose(&D_80107E34);
}

s32 *Audiomgr_InitializeDmaState(s32 **arg0) {
    if (D_80107DF0.initialized == 0) {
        D_80107DF0.firstFree = (struct Window *)&D_80107928;
        D_80107DF0.firstUsed = 0;
        D_80107DF0.initialized = 1U;
    }
    *arg0 = (s32 *)&D_80107DF0;
    return &D_002571F0;
}

s32 Audiomgr_RenderAudioFrame(Work56EC8 *audioTask, u32 unused)
{
  s32 completed;
  s32 event;
  s32 value;
  void *item;
  Sound_RetireCompletedSampleWindows(audioTask);
  value = osVirtualToPhysical(audioTask->owner);
  audioTask->id = (u16)D_80107E98;
  func_8025E48C_de();
  item = alAudioFrame(D_80107E20[D_800CB708], &completed, value, audioTask->id);
  func_8025E4B0_de();
  if (completed != 0)
  {
    audioTask->base = D_80107E20[D_800CB708];
    audioTask->offset = ((((s32) item) - ((s32) D_80107E20[D_800CB708])) >> 3) << 3;
    osWritebackDCacheAll();
    Sched_SendSchedulerTask(&D_80142928, audioTask->payload);
    D_800CB708 ^= 1;
    func_8025E23C_de();
    osRecvMesg(&D_80107E80, &event, 1);
    osAiSetNextBuffer(audioTask->owner, audioTask->id << 2);
    return 1;
  }
  if (completed || audioTask->id)
  {
    return 0;
  }
  else
  {
    return 0;
  }
}
