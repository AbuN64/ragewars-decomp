#include "span_1000/code_8028FC98.h"







/** Unlink an active node and return it to the container's free list. */
void func_80290950_de(void *container, ListNode80290528 *node) {
    World_func_80290238_de *world = container;
    struct Actor_func_80290238_de *actor = (struct Actor_func_80290238_de *)node;
    struct Actor_func_80290238_de *free_node;

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
