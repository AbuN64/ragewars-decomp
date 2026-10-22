#include "include_asm.h"
#include "COMMON/RESULTS.H"

/** Unlink an active node and return it to the container's free list. */
void func_80290950_de(void *container, ListNode80290528 *node) {
    WorldRecAt3C08 *world = container;
    struct SceneEffect *actor = (struct SceneEffect *)node;
    struct SceneEffect *free_node;

    if (actor->state & 1) {
        actor->state &= ~1;
        if (actor->counter != 0) {
            (*actor->counter)--;
        }
        if (actor->prev != 0) {
            actor->prev->next = actor->next;
        }
        if (actor->next != 0) {
            actor->next->prev = actor->prev;
        }
        if (world->head == actor) {
            world->head = actor->next;
        }
        if (world->tail == actor) {
            world->tail = actor->prev;
        }
        free_node = world->free;
        actor->prev = 0;
        actor->next = free_node;
        world->free = actor;
    }
}

#if defined(VERSION_US)
INCLUDE_DATA("span_1000", rodata_unresolved_802908F4);
#endif
