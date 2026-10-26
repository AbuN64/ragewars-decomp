#include "COMMON/WORLD.H"
#include "COMMON/ENTRYRECAT8V4.H"
#include "TYPES.H"
#include "MENU_2/80400000_7.H"
#include "RENDER_4/8028FD2C_6.H"

/* Releases the current record's track-2 timed items whose time has come (or all live ones once the
   record's end time has passed): special items (kind and subkind 1 and 5, 9 and 4, 10 and 3) go to
   func_80402FB4_de and clear the record's pending flag, others to Link_ActivateTrigger, then each entry is
   marked spent and its item is flagged and refreshed through Scene_SetTriggerStateBit. Adapted from Menu_HasNoTrackRequestItems: indexed entry
   access and the table base taken inside the loop. */









extern RecordMenuProcessTrackItemEvents *D_800E2830;

extern s32 Cinema_IsSequenceActive(void);
extern void Menu_RequestTrackByIds(s32 mode, ItemRecAt12 *item);
extern void Link_ActivateTrigger(ItemRecAt12 *item);
extern void Scene_SetTriggerStateBit(Shared_World *world, ItemRecAt12 *item, s32 mode);

void Menu_ProcessTrackItemEvents(void) {
    f32 time;
    s32 late;
    s32 *track;
    EntryRecAt8V4 *entry;
    Shared_World *tables;
    ItemRecAt12 *item;
    s32 n;
    s32 i;
    s32 hit;

    time = D_800E2830->time;
    late = 0;
    if (Cinema_IsSequenceActive() == 0) {
        return;
    }
    if (D_800E2830->active == 0) {
        return;
    }
    track = SetN64_GetPackSection(D_800E2830->resource, 2);
    n = track[1];
    entry = (EntryRecAt8V4 *)(track + 2);
    if (n == 0) {
        return;
    }
    if (D_800E2830->endTime <= time) {
        late = 1;
    }
    for (i = 0; i < n; i++) {
        tables = &g_world;
        if (entry[i].time <= -10000.0f) {
            continue;
        }
        if (time < entry[i].time && late == 0) {
            continue;
        }
        if (entry[i].side == 0) {
            item = &((ItemRecAt12 *)tables->recordArray)[entry[i].index];
        } else {
            item = &((ItemRecAt12 *)tables->alternateRecordArray)[entry[i].index];
        }
        hit = 0;
        switch (item->kind) {
            case 1:
                if (item->subkind == 5) {
                    hit = 1;
                }
                break;
            case 9:
                if (item->subkind == 4) {
                    hit = 1;
                }
                break;
            case 10:
                if (item->subkind == 3) {
                    hit = 1;
                }
                break;
            default:
                hit = 0;
                break;
        }
        if (hit) {
            Menu_RequestTrackByIds(0, item);
            D_800E2830->pending = 0;
        } else {
            Link_ActivateTrigger(item);
        }
        entry[i].time = -20000.0f;
        item->flags = (item->flags | 1) & 0xEF;
        Scene_SetTriggerStateBit(&g_world, item, 0);
    }
}
