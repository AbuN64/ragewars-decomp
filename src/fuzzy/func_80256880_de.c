#include "shared/audio_initialize.h"
extern u8 D_80107DF0;
extern u32 D_80107E98, D_80107E9C;
extern s32 D_80107DFC;
extern ALHeap *D_80107EA0;
extern AudioCacheEntry D_80107928[60];
extern AudioWork *D_80107E28[3];
extern s16 *D_80107E20[2];
extern AudioQueue D_80107E80, D_80107E00, D_80107DD8;
extern u32 D_801076D0[10], D_801076A8[10], D_80107EA8[60];
extern u8 D_80107E34[], D_801076F8[], D_800E5400[0x2800];
extern u8 D_800D8C10[0xD0], D_800DB200[0x1000], D_800DC830_de[0x800];
extern f32 D_800C3EB8_de;
s32 *func_80256E6C_de(s32 **);
void func_80256C90_de(void);
s32 func_802B72E0_de(u32);
void func_802B24A0_de(void *, void *);
void func_802B2480_de(void *, void *);
void *func_802B0340_de(s32, s32, void *, s32, u32);
void osCreateMesgQueue(void *, void *, s32);
void func_802BB550_de(s32, void *, s32);
void *func_802A001C_de(void *, s32, u32);
void func_802BAC90_de(void *, s32, void (*)(void), void *, void *, s32);
void func_802BB750_de(void *);
s32 func_802BB420_de(void *, AudioQueueMessage, s32);

void func_80256880_de(AudioInitializeConfig *config, s32 priority, AudioInitializeTiming *timing) {
    u32 count, i;
    s32 integral;
    f32 samples, rounded;
    AudioWork *work;
    AudioQueueMessage signal;
    D_80107DF0 = 0;
    config->callback = func_80256E6C_de;
    config->frequency = func_802B72E0_de(timing->frequency);
    samples = timing->frameTime;
    samples = samples * config->frequency * D_800C3EB8_de;
    integral = samples;
    count = integral;
    rounded = count;
    if (rounded < samples) count++;
    if (count & 15) count = (count & ~15U) + 16;
    D_80107E98 = count;
    func_802B24A0_de(D_80107E34, config);
    D_80107928[0].next = 0; D_80107928[0].prev = 0;
    for (i = 0; i < 59; i++) {
        func_802B2480_de(&D_80107928[i+1], &D_80107928[i]);
        D_80107928[i].buffer = func_802B0340_de(0, 0, config->heap, 1, 0x300);
    }
    D_80107928[i].buffer = func_802B0340_de(0, 0, config->heap, 1, 0x300);
    for (i = 0; i < 2; i++) D_80107E20[i] = func_802B0340_de(0, 0, config->heap, 1, timing->samples * 8);
    D_80107E9C = timing->samples;
    for (i = 0; i < 3; i++) {
        D_80107E28[i] = func_802B0340_de(0, 0, config->heap, 1, sizeof(AudioWork));
        work = D_80107E28[i];
        work->samples = func_802B0340_de(0, 0, config->heap, 1, D_80107E98 * 4);
        work->queue = &D_80107E80;
        work->message = work;
        work->task.type = 2;
        work->task.boot = D_800D8C10; work->task.bootSize = sizeof(D_800D8C10);
        work->task.flags = 0;
        work->task.code = D_800DB200; work->task.codeSize = sizeof(D_800DB200);
        work->task.codeData = D_800DC830_de; work->task.codeDataSize = sizeof(D_800DC830_de);
        work->task.yield = 0; work->task.yieldSize = 0;
        work->task.stack = 0; work->task.stackSize = 0;
        work->task.output = 0; work->task.outputSize = 0;
    }
    osCreateMesgQueue(&D_80107E80, D_801076D0, 10);
    osCreateMesgQueue(&D_80107E00, D_801076A8, 10);
    osCreateMesgQueue(&D_80107DD8, D_80107EA8, 60);
    func_802BB550_de(6, &D_80107E00, 7);
    D_80107DFC = 0;
    D_80107EA0 = config->heap;
    func_802A001C_de(D_800E5400, 8, sizeof(D_800E5400));
    func_802BAC90_de(D_801076F8, 8, func_80256C90_de, 0, D_800E5400 + sizeof(D_800E5400), priority);
    func_802BB750_de(D_801076F8);
    signal.signal = 7;
    func_802BB420_de(&D_80107E00, signal, 0);
}
