#include "LISTS/EXTERNS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/LISTHEADER.H"
#include "TYPES.H"
#include "COMMON/SELF.H"
#include "LISTS/80279520.H"

/* Initializes an empty linked-list header by clearing its two links and count. */
void Lists_ClearHeader(ListHeader *list) {
    list->head = 0;
    list->tail = 0;
    list->count = 0;
}
/** Push a node onto the front of a doubly-linked list. */
void func_802794C0_de(void *listHeader, void *arg1) {
    if ((((struct ListHeader *) ((s8 *) listHeader))->count) == 0) {
        (((struct ListHeader *) ((s8 *) listHeader))->head) = arg1;
        (((struct ListHeader *) ((s8 *) listHeader))->tail) = arg1;
        (((struct Shape_typemap_3 *) ((s8 *) arg1))->field_0) = 0;
        (((struct func_80203E78_S1 *) ((s8 *) arg1))->unk4) = 0;
    } else {
        (((struct Field_void_4 *) ((s8 *) arg1))->value) = (((struct ListHeader *) ((s8 *) listHeader))->head);
        (((struct Shape_typemap_3 *) ((s8 *) arg1))->field_0) = 0;
        (((struct func_80284AF4_G2 *) ((s8 *) ((struct ListHeader *) ((s8 *) listHeader))->head))->unk0) = arg1;
        (((struct ListHeader *) ((s8 *) listHeader))->head) = arg1;
    }
    (((struct ListHeader *) ((s8 *) listHeader))->count) = (((struct ListHeader *) ((s8 *) listHeader))->count) + 1;
}
/** Push a node onto the tail of a doubly-linked list; returns new count. */
s32 Lists_Append(void *listHeader, void *arg1) {
    s32 count;
    if ((((struct ListHeader *) ((s8 *) listHeader))->count) == 0) {
        (((struct ListHeader *) ((s8 *) listHeader))->head) = arg1;
        (((struct ListHeader *) ((s8 *) listHeader))->tail) = arg1;
        (((struct Shape_typemap_3 *) ((s8 *) arg1))->field_0) = 0;
        (((struct func_80203E78_S1 *) ((s8 *) arg1))->unk4) = 0;
    } else {
        (((struct func_80284AF4_G2 *) ((s8 *) arg1))->unk0) = (((struct ListHeader *) ((s8 *) listHeader))->tail);
        (((struct func_80203E78_S1 *) ((s8 *) arg1))->unk4) = 0;
        (((struct Field_void_4 *) ((s8 *) ((struct ListHeader *) ((s8 *) listHeader))->tail))->value) = arg1;
        (((struct ListHeader *) ((s8 *) listHeader))->tail) = arg1;
    }
    count = (((struct ListHeader *) ((s8 *) listHeader))->count) + 1;
    (((struct ListHeader *) ((s8 *) listHeader))->count) = count;
    return count;
}
int Lists_Remove(List802795C0 *arg0, ListLink *listLink) {
    if (listLink->prev != 0) {
        listLink->prev->next = listLink->next;
    }
    if (listLink->next != 0) {
        listLink->next->prev = listLink->prev;
    }
    if (arg0->head == listLink) {
        arg0->head = listLink->prev;
    }
    if (arg0->tail == listLink) {
        arg0->tail = listLink->next;
    }
    arg0->count -= 1;
    return arg0->count;
}
/* Reset a pool list header. */
static inline void clear_list(ListHeader *list) {
    list->head = 0;
    list->tail = 0;
    list->count = 0;
}
/* Append a free node and return the new list length. */
static inline s32 append(ListHeader *list, ListLink *node) {
    s32 count;
    if (list->count == 0) {
        list->head = node;
        list->tail = node;
        node->next = 0;
        node->prev = 0;
    } else {
        node->next = list->tail;
        node->prev = 0;
        ((ListLink *)list->tail)->prev = node;
        list->tail = node;
    }
    count = list->count + 1;
    list->count = count;
    return count;
}
/* Reset the free and active headers and link every fixed-size pool node. */
void Lists_InitFromPool(ListHeader *lists, void *pool, s32 stride, s32 count) {
    s32 remaining;
    clear_list(lists);
    clear_list(lists + 1);
    for (remaining = count - 1; remaining != -1; remaining--) {
        append(lists, (ListLink *)pool);
        pool = (char *)pool + stride;
    }
}
ListLink *func_8027963C_de(Lists18 *arg0) {
    ListLink *node;
    ListLink *tail;
    List802795C0 *inactive;
    node = arg0->active.head;
    if (node != 0) {
        if (node->prev != 0) {
            node->prev->next = node->next;
        }
        if (node->next != 0) {
            node->next->prev = node->prev;
        }
        if (arg0->active.head == node) {
            arg0->active.head = node->prev;
        }
        if (arg0->active.tail == node) {
            arg0->active.tail = node->next;
        }
        arg0->active.count -= 1;
        inactive = &arg0->inactive;
        if (inactive->count == 0) {
            inactive->head = node;
            inactive->tail = node;
            node->next = 0;
            node->prev = 0;
        } else {
            tail = inactive->tail;
            node->prev = 0;
            node->next = tail;
            inactive->tail->prev = node;
            inactive->tail = node;
        }
        inactive->count += 1;
    }
    return node;
}
void func_802796F4_de(Lists18 *arg0, ListLink *arg1) {
    List802795C0 *inactive;
    ListLink *tail;
    inactive = &arg0->inactive;
    if (arg1->prev != 0) {
        arg1->prev->next = arg1->next;
    }
    if (arg1->next != 0) {
        arg1->next->prev = arg1->prev;
    }
    if (inactive->head == arg1) {
        inactive->head = arg1->prev;
    }
    if (inactive->tail == arg1) {
        inactive->tail = arg1->next;
    }
    inactive->count -= 1;
    if (arg0->active.count == 0) {
        arg0->active.head = arg1;
        arg0->active.tail = arg1;
        arg1->next = 0;
        arg1->prev = 0;
    } else {
        tail = arg0->active.tail;
        arg1->prev = 0;
        arg1->next = tail;
        arg0->active.tail->prev = arg1;
        arg0->active.tail = arg1;
    }
    arg0->active.count += 1;
}
s16 func_80279798_de(s16 *arg0) {
    s16 *entry;
    s16 *start;
    s32 random;
    s32 total;
    s32 value;
    entry = arg0;
    total = 0;
    start = entry;
    if (*entry != -1) {
        do {
            total += entry[1];
            entry += 2;
        } while (*entry != -1);
    }
    random = GraphU64_NextRandom();
    entry = start;
    value = random % total;
    total = 0;
    while (*entry != -1) {
        total += entry[1];
        if (total >= value) {
            break;
        }
        entry += 2;
    }
    return *entry;
}
/** Clear the leading halfword of the supplied object. */
void func_8027985C_de(WeightedTable *object) {
    object->count = 0;
}
s32 func_80279864_de(WeightedTable *arg0, s16 arg1, s16 arg2)
{
  s16 temp_v1;
  temp_v1 = arg0->count;
  if (temp_v1 == 0x18)
  {
    return 0;
  }
  arg0->entries[temp_v1][0] = arg1;
  arg0->entries[arg0->count][1] = arg2;
  arg0->count = ((u16) arg0->count) + 1;
  return 1;
}
s16 func_802798A8_de(WeightedTable *weightedTable) {
    s16 *entry;
    s16 *start;
    s32 random;
    s32 total;
    s32 value;
    if (weightedTable->count == 0) {
        return -1;
    }
    weightedTable->entries[weightedTable->count][0] = -1;
    entry = &weightedTable->entries[0][0];
    total = 0;
    start = entry;
    if (*entry != -1) {
        do {
            total += entry[1];
            entry += 2;
        } while (*entry != -1);
    }
    random = GraphU64_NextRandom();
    entry = start;
    value = random % total;
    total = 0;
    while (*entry != -1) {
        total += entry[1];
        if (total >= value) {
            break;
        }
        entry += 2;
    }
    return *entry;
}
