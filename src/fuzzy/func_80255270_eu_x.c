#include "types.h"

typedef struct RendererMessage RendererMessage;
struct RendererMessage {
    char pad0[0x14];
    void (*callback)(s32, RendererMessage *);
    s32 argument;
    char pad1C[4];
    void *replyQueue;
};
typedef struct RendererThread {
    char pad0[0x230];
    char queue[0x1448 - 0x230];
    s32 timestamp;
} RendererThread;
extern s32 D_800D2978;
extern void func_802BB2A0_de(void *, RendererMessage **, s32);
extern void func_802BB420_de(void *, RendererMessage *, s32);

void func_80255270_eu_x(RendererThread *thread) {
    RendererMessage *message;
    for (;;) {
        func_802BB2A0_de(thread->queue, &message, 1);
        thread->timestamp = D_800D2978;
        message->callback(message->argument, message);
        func_802BB420_de(message->replyQueue, message, 1);
    }
}
