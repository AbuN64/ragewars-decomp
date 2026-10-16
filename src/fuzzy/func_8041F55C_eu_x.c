#include "TYPES.H"

typedef struct MenuEventObject {
    u8 pad[0xC];
    s16 kind;
} MenuEventObject;

typedef s32 (*MenuHandler)(void *, s32, s32, s32, s32);
typedef struct MenuHandlerEntry {
    s32 event;
    s32 kind;
    MenuHandler handler;
} MenuHandlerEntry;

extern MenuHandlerEntry D_800EB1A4[11];

s32 func_8041F55C_eu_x(MenuEventObject *object, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    MenuHandlerEntry *entry = D_800EB1A4;

    if (entry->handler != 0) {
        do {
            if (entry->event == event && (entry->kind == object->kind || entry->kind == 30000)) {
                return entry->handler(object, event, arg2, arg3, arg4);
            }
            entry++;
        } while (entry->handler != 0);
    }
    return 0;
}
