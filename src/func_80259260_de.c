#include "common/types_1dc8418c21db.h"
#include "span_1000/code_802591C0.h"
#include "types.h"
#include "common/unused.h"
/* Starts a sound instance from a description: when the scene's free node list is not empty it takes the
 * first node under the audio lock (func_80258740_de/func_802587A4_de), unlinks it, gives it the next handle, the
 * volume, sample, priority, pan and pitch fields decoded from the description, full gain, the scene frame
 * and the position, prepares its channel through func_8025BB7C_de and func_8025BB84_de and inserts it into the
 * active list ahead of the first lower-priority node; returns the handle or -1 when no node is free. */









extern void func_80258740_de(s32 *);
extern void func_802587A4_de(s32 *);

extern void func_8025BB84_de(void *, void *, s32);
extern s16 func_8025E500_de(void *);
extern s8 func_8025E518_de(void *);
extern s16 func_8025E50C_de(void *);
extern u8 func_8025E548_de(void *);
extern s16 func_8025E578_de(void *);
extern s8 func_8025E554_de(void *);




s32 func_80259260_de(Manager_func_80259260_de *manager, void *desc, Vec3Words *position, s32 volume, s32 extra) {
    Node_func_80259260_de *node;
    Node_func_80259260_de *first;
    Node_func_80259260_de *at;
    s32 *scene;
    s32 priority;

    if (manager->free.next != (Node_func_80259260_de *)&manager->free) {
        func_80258740_de(manager->scene);
        first = manager->free.next;
        first->prev->next = first->next;
        first->next->prev = first->prev;
        scene = manager->scene;
        node = first;
        node->handle = scene[0x108 / 4];
        scene[0x108 / 4] = node->handle + 1;
        node->volume = volume;
        node->voice = -1;
        node->volume16 = volume;
        node->group = func_8025E500_de(desc);
        node->priority = func_8025E518_de(desc);
        node->sample = func_8025E50C_de(desc);
        node->pan = func_8025E548_de(desc);
        node->flags = func_8025E578_de(desc);
        node->pitch = func_8025E554_de(desc);
        node->gainB = 0x7D00;
        node->gainA = 0x7D00;
        node->time = 0;
        node->frame = manager->scene[0x104 / 4];
        node->position = *position;
        node->pad58 = 0;
        node->padB4 = 0;
        func_8025BB7C_de(node->channel, ((struct Context_func_80257360_de *)manager->scene)->field2B8C);
        node->mix = manager->scene[0x2BAC / 4];
        func_8025BB84_de(node->channel, desc, extra);
        at = manager->active.next;
        priority = node->priority;
        while (at != (Node_func_80259260_de *)&manager->active) {
            if (at->priority < priority) {
                break;
            }
            at = at->next;
        }
        node->prev = at->prev;
        node->next = at;
        at->prev->next = node;
        at->prev = node;
        func_802587A4_de(manager->scene);
        return node->handle;
    }
    return -1;
}
