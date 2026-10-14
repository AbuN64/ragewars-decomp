#include "span_1000/code_802B0388.h"
#include "common/types_8fd754e1e915.h"
#include "span_1000/code_802AE028.h"
#include "types.h"






extern void *D_800D4070;
extern char D_002AEC20;

extern s32 func_802B0340_de(s32, s32, void *, s32, s32);
extern void func_802B1990_de(void *);
extern void func_802AFFC0_de(void *, void *, s32);
extern void func_802B2FB0_de(s32, void *);







void func_802AEAB0_de(void *arg0, InitParams *arg1) {
    ALSeqPlayer *obj = arg0;
    InitParams *params = arg1;
    s32 context = params->context;
    s32 global = D_800D4070;
    s32 allocation;
    s32 i;

    obj->chanMask = 0xFF;
    obj->uspt = 0x1E8;
    obj->vol = 0x7FFF;
    obj->bank = 0;
    obj->target = 0;
    obj->nextDelta = 0;
    obj->state = 0;
    obj->frameTime = 0x3E80;
    obj->curTime = 0;
    obj->drvr = global;
    obj->initOsc = params->value10;
    obj->updateOsc = params->value14;
    obj->stopOsc = params->value18;
    obj->nextEvent.type = 9;
    obj->maxChannels = params->kind;
    obj->chanState = func_802B0340_de(0, 0, (void *)context, params->kind, 0x10);
    func_802B1990_de(obj);

    allocation = func_802B0340_de(0, 0, (void *)context, params->count38, 0x38);
    obj->vFreeList = 0;
    i = 0;
    if (params->count38 > 0) {
        {
            ALVoiceState *records = (ALVoiceState *)allocation;
            do {
                records->next = obj->vFreeList;
                obj->vFreeList = records;
                i++;
                records++;
            } while (i < params->count38);
        }
    }

    obj->vAllocHead = 0;
    obj->vAllocTail = 0;
    allocation = func_802B0340_de(0, 0, (void *)context, params->count1C, 0x1C);
    func_802AFFC0_de(&obj->evtq, (void *)allocation, params->count1C);
    {
        ALPlayer_s *node = &obj->node;
        node->next = 0;
        node->handler = &D_002AEC20;
        node->clientData = node;
        func_802B2FB0_de(D_800D4070, node);
    }
}
