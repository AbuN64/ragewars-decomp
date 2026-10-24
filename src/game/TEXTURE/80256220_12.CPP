#include "include_asm.h"
#include "TEXTURE/80256220.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "TYPES.H"
#include "TEXTURE/80256220_12.H"
#include "TEXTURE/80256220_13.H"
#include "sdk/os.h"
#include "RESMGR/802A0888.H"
#include "sdk/libgultra/part_800C7F20/code_802B7520.h"

/* Clears and sizes the 0x8016E000 heap region against the detected RAM size, then initialises the
   five dependent subsystems over it. */

extern u8 D_80166000[];
extern u8 D_801051A0[];
extern u8 D_80106248[];
extern u8 D_801011B8[];

extern s32 func_80265350_de(void);
extern void func_802558B4_de(void *, void *, s32);
extern void func_802550F0_de(void *, s32);
extern void func_80256280_de(void *, s32);
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
extern void func_8023B9C0_eu(s32, s32);
#elif defined(VERSION_EU_X)
extern void func_8023B9F0_eu_x(s32, s32);
#else
extern void func_8023B9B0_de(s32, s32);
#endif
extern void Scene_InitializeResourceCache(s32, s32);

void func_802567D0_de(void) {
    u8 *heapStart;
    s32 heapEnd;
    s32 size;

    heapEnd = 0x80400000;
    heapStart = D_80166000;
    if (func_80265350_de() != 0x400000) {
        heapEnd = func_80265350_de() | 0x80000000;
    }

    size = heapEnd - (s32)heapStart;
    func_802A001C_de(heapStart, 0, size);
    func_802558B4_de(D_801051A0, heapStart, size);
    func_802550F0_de(D_80106248, 3);
    func_80256280_de(D_801011B8, 4);
    
#if defined(VERSION_EU) || defined(VERSION_US) || defined(VERSION_US_REV1)
func_8023B9C0_eu
#elif defined(VERSION_EU_X)
func_8023B9F0_eu_x
#else
func_8023B9B0_de
#endif
(0, 0);
    Scene_InitializeResourceCache(0, 5);
}

#include "COMMON/AUDIO_INITIALIZE.H"
#include "COMMON/ALAUXBUS_S.H"
extern ObjectLinksC D_80107DF0;
extern u32 D_80107E98, D_80107E9C;
extern s32 D_80107DFC;
extern ALHeap *D_80107EA0;
extern AudioCacheEntry D_80107928[60];
extern AudioWork *D_80107E28[3];
extern s16 *D_80107E20[2];
extern u32 D_801076D0[10], D_801076A8[10], D_80107EA8[60];
extern u8 D_801076F8[], D_800E5400[0x2800];
extern u8 D_800D8C10[0xD0], D_800DB200[0x1000], D_800DC830_de[0x800];
extern u8 D_800D8CE0[];
extern char D_00256E6C, D_00256C90;
s32 *func_80256E6C_de(s32 **);
void func_80256C90_de(void);
s32 func_802B72E0_de(u32);
void func_802B24A0_de(void *, void *);
void *func_802B0340_de(s32, s32, void *, s32, u32);
void func_802BB550_de(s32, void *, s32);
void func_802BAC90_de(void *, s32, void (*)(void), void *, void *, s32);
void func_802BB750_de(void *);

/* Reset the DMA cache, allocate sample/task buffers, then start the audio worker. */
void Texture_InitializeAudioWorker(ALSynConfig *config, s32 priority, AudioInitializeTiming *timing) {
    u32 i;
    f32 samplesPerFrame;
    D_80107DF0.unk_0 = 0;
    config->dmaproc = (void *)&D_00256E6C;
    config->outputRate = func_802B72E0_de(timing->frequency);
    samplesPerFrame = (f32)timing->frameTime * config->outputRate * (1.0f / 60.0f);
    D_80107E98 = (s32)samplesPerFrame;
    if ((f32)D_80107E98 < samplesPerFrame) D_80107E98++;
    if (D_80107E98 & 15) D_80107E98 = (D_80107E98 & ~15U) + 16;
    func_802B24A0_de(&D_80107E34, config);
    D_80107928[0].prev = 0;
    D_80107928[0].next = 0;
    for (i = 0; i < 59; i++) {
        func_802B2480_de(&D_80107928[i+1], &D_80107928[i]);
        D_80107928[i].buffer = func_802B0340_de(0, 0, config->heap, 1, 0x300);
    }
    D_80107928[i].buffer = func_802B0340_de(0, 0, config->heap, 1, 0x300);
    for (i = 0; i < 2; i++) D_80107E20[i] = func_802B0340_de(0, 0, config->heap, 1, timing->samples * 8);
    D_80107E9C = timing->samples;
    for (i = 0; i < 3; i++) {
        D_80107E28[i] = func_802B0340_de(0, 0, config->heap, 1, sizeof(AudioWork));
        D_80107E28[i]->samples = func_802B0340_de(0, 0, config->heap, 1, D_80107E98 * 4);
        D_80107E28[i]->queue = &D_80107E80;
        D_80107E28[i]->message = D_80107E28[i];
        D_80107E28[i]->task.type = 2;
        D_80107E28[i]->task.boot = D_800D8C10; D_80107E28[i]->task.bootSize = (u32)D_800D8CE0 - (u32)D_800D8C10;
        D_80107E28[i]->task.flags = 0;
        D_80107E28[i]->task.code = D_800DB200; D_80107E28[i]->task.codeSize = sizeof(D_800DB200);
        D_80107E28[i]->task.codeData = D_800DC830_de; D_80107E28[i]->task.codeDataSize = sizeof(D_800DC830_de);
        D_80107E28[i]->task.yield = 0; D_80107E28[i]->task.yieldSize = 0;
        D_80107E28[i]->task.stack = 0; D_80107E28[i]->task.stackSize = 0;
        D_80107E28[i]->task.output = 0; D_80107E28[i]->task.outputSize = 0;
    }
    osCreateMesgQueue(&D_80107E80, D_801076D0, 10);
    osCreateMesgQueue(&D_80107E00, D_801076A8, 10);
    osCreateMesgQueue(&D_80107DD8, D_80107EA8, 60);
    func_802BB550_de(6, &D_80107E00, 7);
    D_80107DFC = 0;
    D_80107EA0 = config->heap;
    func_802A001C_de(D_800E5400, 8, sizeof(D_800E5400));
    func_802BAC90_de(D_801076F8, 8, (void (*)(void))&D_00256C90, 0, D_800E5400 + sizeof(D_800E5400), priority);
    func_802BB750_de(D_801076F8);
    func_802BB420_de(&D_80107E00, (OSMesg)7, 0);
}
