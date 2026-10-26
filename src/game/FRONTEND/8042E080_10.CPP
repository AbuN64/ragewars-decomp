#include "COMMON/SCREEN.H"
#include "COMMON/NAME.H"
#include "FRONTEND/PAKMENU.H"
#include "COMMON/RESOURCELOADSTATE.H"
#include "COMMON/ENTRYRECAT6C.H"
#include "COMMON/MESSAGESEMAPHORE.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/MENURECAT24.H"
#include "TYPES.H"
#include "FRONTEND/8042E080_15.H"
#include "FRONTEND/8042E080_34.H"
#include "FRONTEND/8042E080_37.H"
#include "FRONTEND/8042E080_39.H"
#include "FRONTEND/8042E080_45.H"
#include "FRONTEND/8042E080_59.H"
#include "FRONTEND/8042E080_62.H"
#include "FRONTEND/8042E080_64.H"
#include "RESMGR/resmgr_string_memory.H"
#include "FRONTEND/8040B45C_33.H"

/* Steps player arg2's menu state machine at 0x58 of its 0xB68-byte record in the block D_800E54A4 points to
   on the event SmpOverlay_GetSlotNodeId reports: each state accepts its events, moves to the next state (by the game
   mode at 0x54 where it matters), updates the player's name records, and refreshes the player through
   func_804322AC_de. Returns zero. */
extern u8 D_80102B00[];
extern u8 g_playerSettings[];

extern s32 SmpOverlay_GetSlotNodeId(s32, s32);
extern void SmpOverlay_SetSlotValue(s32, s32, s32);
extern void PAKInterface_RefreshPlayerPanel(s32);
extern s32 PAKInterface_CheckRecordsNoteCapacity(s32, s32 *);
extern s32 PAKInterface_SavePlayerRecords(s32);
extern void Frontend_SetWidgetFlag08(void *, s32);

extern s32 Pak_DeleteNote(s32, s32);

extern void Player_InitializeProfile(void *);
extern void Pak_ProbeStatus(s32);
extern void PAKInterface_ResolvePlayerPakState(s32);
extern void PAKInterface_RelabelSlotRows(s32);


extern s32 Pak_RepairId(s32);

s32 PAKInterface_ActivatePlayerPanelAction(s32 unused0, s32 unused1, s32 arg2) {
    s32 answer;
    s32 i;
    s32 j;
    s32 p;
    s32 event;
    s32 slot;
    s32 other;
    s32 q;
    s32 found;
    u8 *node;
    u8 *next;
    u8 *settings;
    u8 c;
    s32 sub;
    s32 mode;

    MarkMenuEventHandled();
    i = 0;
    p = arg2 & 0xFFFF;
    event = SmpOverlay_GetSlotNodeId(D_800E54A4->root, p);
    switch (D_800E54A4->players[p].state) {
    case 1:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2D0:
#elif defined(VERSION_EU_X)
        case 0x2E9:
#else
        case 0x2ED:
#endif
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2D1:
#elif defined(VERSION_EU_X)
        case 0x2EA:
#else
        case 0x2EE:
#endif
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    PAKInterface_BeginLinkedProfileTransfer(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 1;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            }
            break;
        }
        break;
    case 3:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2D8:
#elif defined(VERSION_EU_X)
        case 0x2DF:
#else
        case 0x2BD:
#endif
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 1;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    PAKInterface_BeginLinkedProfileTransfer(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                PAKInterface_RefreshPlayerPanel(p);
                break;
            }
            break;
#if defined(VERSION_DE)
        case 0x2D7:
#elif defined(VERSION_EU_X)
        case 0x2DD:
#else
        case 0x2BC:
#endif
            D_800E54A4->players[p].state = 0x1C;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2D6:
#elif defined(VERSION_EU_X)
        case 0x2DE:
#else
        case 0x2BE:
#endif
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 15:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2C4:
#elif defined(VERSION_EU_X)
        case 0x2EC:
#else
        case 0x2F0:
#endif
            if (PAKInterface_CheckRecordsNoteCapacity(p, &answer) == 0) {
                if (answer == 1) {
                    D_800E54A4->players[p].state = 0xC;
                } else {
                    D_800E54A4->players[p].state = 0xB;
                }
            } else {
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2C5:
#elif defined(VERSION_EU_X)
        case 0x2ED:
#else
        case 0x2F1:
#endif
            if (D_800E54A4->phase == 7) {
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0xF;
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 16:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2B6:
#elif defined(VERSION_EU_X)
        case 0x2C4:
#else
        case 0x2B8:
#endif
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].owner = (u8) D_800E54A4->players[p].record;
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].player = p;
            D_800E54A4->players[p].records[D_800E54A4->players[p].record].time = D_800E54A4->players[p].profile;
            if (D_800E54A4->phase == 7) {
                settings = g_playerSettings;
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[0] = settings[0x7B];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[1] = settings[0x7D];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[2] = settings[0x79];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[3] = settings[0x7A];
                D_800E54A4->players[p].records[D_800E54A4->players[p].record].setting[4] = settings[0x82];
            }
            if (PAKInterface_SavePlayerRecords(p) == 1) {
                switch (D_800E54A4->phase) {
                case 0:
                    if (PAKInterface_FindEmptyProfileSlot(p) >= 0) {
                        D_800E54A4->players[p].state = 0x17;
                    } else {
                        D_800E54A4->players[p].state = 0xE;
                    }
                    break;
                case 7:
                    Frontend_SetPlayerProfileLink(p, 0, 0);
                    PAKInterface_LoadLinkedPlayerProfile(0);
                    MarkMenuEventHandled();
                    PAKInterface_BeginScreenExit(9);
                    return 0;
                default:
                    D_800E54A4->players[p].state = 0xD;
                    break;
                }
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
#if defined(VERSION_DE)
        case 0x2B5:
#elif defined(VERSION_EU_X)
        case 0x2C3:
#else
        case 0x2B9:
#endif
            switch (D_800E54A4->phase) {
            case 0:
                D_800E54A4->players[p].state = 0x17;
                break;
            case 1:
                D_800E54A4->players[p].state = 0x17;
                break;
            case 7:
                D_800E54A4->players[p].state = 0x17;
                break;
            default:
                D_800E54A4->players[p].state = 0xD;
                break;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 12:
        slot = PAKInterface_FindEmptyProfileSlot(p);
        if (slot >= 0) {
#if defined(VERSION_DE)
            node = Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].menu, 0x2DA);
#elif defined(VERSION_EU_X)
            node = Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].menu, 0x2B2);
#else
            node = Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].menu, 0x2F3);
#endif
            for (j = 0; ((Shared_Item *) node)->flags & 0x10; j++) {
                D_800E54A4->players[p].records[slot].name[j] = *(u8 *) ((Shared_Item *) node)->label->unk38;
                next = (u8 *) ((Shared_Item *) node)->next;
                if (next == 0) {
                    break;
                }
                node = next;
            }
            for (j = 6; j > 0; j--) {
                c = D_800E54A4->players[p].records[slot].name[j];
                if (c != 0 && c != ' ') {
                    break;
                }
                D_800E54A4->players[p].records[slot].name[j] = 0;
            }
            D_800E54A4->players[p].state = 0x10;
            D_800E54A4->players[p].record = slot;
        } else {
            D_800E54A4->players[p].state = 3;
        }
        PAKInterface_RefreshPlayerPanel(p);
        break;
    case 11:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2D3:
#elif defined(VERSION_EU_X)
        case 0x2D8:
#else
        case 0x2D2:
#endif
            D_800E54A4->players[p].state = 4;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2D4:
#elif defined(VERSION_EU_X)
        case 0x2D7:
#else
        case 0x2D3:
#endif
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 3:
            case 4:
            case 5:
                D_800E54A4->players[p].state = 0xE;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 2:
                if (D_800E54A4->players[p].host == 1) {
                    PAKInterface_BeginLinkedProfileTransfer(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
                PAKInterface_RefreshPlayerPanel(p);
                break;
            case 7:
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0xB;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            }
            break;
        }
        break;
    case 4:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2E8:
#elif defined(VERSION_EU_X)
        case 0x2F5:
#else
        case 0x2DA:
#endif
            switch (D_800E54A4->phase) {
            case 0:
                D_800E54A4->players[p].state = 0xF;
                break;
            case 2:
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                break;
            case 7:
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                break;
            case 1:
            case 4:
            case 6:
                D_800E54A4->players[p].state = 0xE;
                break;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2E7:
#elif defined(VERSION_EU_X)
        case 0x2F6:
#else
        case 0x2D9:
#endif
            i = D_800E54A4->players[p].slot;
            if (XPlus_ParseDecimalInteger(D_800E54A4->players[p].names[i].text) > 0) {
                D_800E54A4->players[p].state = 8;
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
        }
        break;
    case 8:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2F4:
#elif defined(VERSION_EU_X)
        case 0x2E2:
#else
        case 0x2D0:
#endif
            if (Pak_DeleteNote(p, D_800E54A4->players[p].slot) == 0) {
#if defined(VERSION_EU) || defined(VERSION_EU_X)
                if (XPlus_CompareStringsIgnoreCase((u8 *)D_800E25A4[g_languageIndex],
#else
                if (XPlus_CompareStringsIgnoreCase((u8 *)D_800D36D4,
#endif
                                     D_800E54A4->players[p].names[D_800E54A4->players[p].slot].code) == 0) {
                    for (j = 0; j < 4; j++) {
                        found = Frontend_FindProfileOwner(D_800E54A4->players[p].profile, D_800E54A4->players[p].records[j].owner);
                        if (found != -1) {
                            Player_InitializeProfile(&((Profile *) D_80102B00)[found]);
                        }
                    }
                }
                D_800E54A4->players[p].state = 4;
                PAKInterface_RefreshPlayerPanel(p);
            } else {
                Pak_ProbeStatus(p);
                PAKInterface_ResolvePlayerPakState(p);
            }
            break;
#if defined(VERSION_DE)
        case 0x2F5:
#elif defined(VERSION_EU_X)
        case 0x2E1:
#else
        case 0x2CF:
#endif
            D_800E54A4->players[p].state = 4;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 7:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2F0:
#elif defined(VERSION_EU_X)
        case 0x2E6:
#else
        case 0x2CD:
#endif
            i = D_800E54A4->players[p].choice;
            other = Frontend_FindProfileOwner(D_800E54A4->players[p].profile, D_800E54A4->players[p].records[i].owner);
            if (other != -1) {
                Player_InitializeProfile(&((Profile *) D_80102B00)[other]);
            }
            Player_InitializeProfile(&D_800E54A4->players[p].records[i]);
            if (PAKInterface_SavePlayerRecords(p) == 1) {
                if (D_800E54A4->players[p].sub == 5) {
                    switch (D_800E54A4->phase) {
                    case 0:
                        D_800E54A4->players[p].back = 2;
                        D_800E54A4->players[p].state = 2;
                        D_800E54A4->players[p].next = 0xC;
                        D_800E54A4->players[p].sub = 0;
                        break;
                    case 2:
                        D_800E54A4->players[p].next = 9;
                        D_800E54A4->players[p].back = 2;
                        D_800E54A4->players[p].state = 2;
                        D_800E54A4->players[p].sub = 3;
                        break;
                    default:
                        D_800E54A4->players[p].state = 0xD;
                        break;
                    }
                } else {
                    D_800E54A4->players[p].state = 0xD;
                }
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
#if defined(VERSION_DE)
        case 0x2F1:
#elif defined(VERSION_EU_X)
        case 0x2E5:
#else
        case 0x2CC:
#endif
            D_800E54A4->players[p].state = 0xD;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 9:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2B1:
#elif defined(VERSION_EU_X)
        case 0x2AB:
#else
        case 0x2C9:
#endif
            slot = PAKInterface_FindEmptyProfileSlot(p);
            if (slot >= 0) {
                XPlus_CopyBytes(&D_800E54A4->players[p].records[slot],
                                 &D_800E54A4->players[D_800E54A4->links[0].player].records[D_800E54A4->links[0].entry],
                                 0x190);
                D_800E54A4->players[p].record = slot;
                D_800E54A4->players[p].records[slot].owner = slot;
                D_800E54A4->players[p].records[slot].time = D_800E54A4->players[p].profile;
            }
            if (PAKInterface_SavePlayerRecords(p) == 1) {
                if (D_800E54A4->phase == 2) {
                    if (D_800E54A4->players[p].host == 1) {
                        PAKInterface_BeginLinkedProfileTransfer(p);
                    } else {
                        D_800E54A4->players[p].state = 0xE;
                    }
                } else {
                    D_800E54A4->players[p].state = 0xD;
                }
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
#if defined(VERSION_DE)
        case 0x2B2:
#elif defined(VERSION_EU_X)
        case 0x2AC:
#else
        case 0x2C8:
#endif
            if (D_800E54A4->phase == 2) {
                if (D_800E54A4->players[p].host == 1) {
                    PAKInterface_BeginLinkedProfileTransfer(p);
                } else {
                    D_800E54A4->players[p].state = 0xE;
                }
            } else {
                D_800E54A4->players[p].state = 0xD;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 13:
#if defined(VERSION_DE)
        if (event == 0x2CD) {
#elif defined(VERSION_EU_X)
        if (event == 0x2FD) {
#else
        if (event == 0x2B5) {
#endif
            sub = D_800E54A4->players[p].sub;
            switch (sub) {
            case 3:
                D_800E54A4->players[p].state = 0x11;
                q = ((int (*)(u8 *)) PAKInterface_FindReadyTransferPlayer)((u8 *) D_800E54A4 + p * sizeof(Shared_Player_func_80433F14));
                if (q >= 0) {
                    D_800E54A4->players[q].back = 2;
                    D_800E54A4->players[q].state = 2;
                    D_800E54A4->players[q].next = 0xD;
                    D_800E54A4->players[q].sub = 3;
                    PAKInterface_RefreshPlayerPanel(q);
                }
                break;
            case 6:
                switch (D_800E54A4->phase) {
                case 1:
                    D_800E54A4->players[p].state = 0x11;
                    q = ((int (*)(u8 *)) PAKInterface_FindReadyTransferPlayer)((u8 *) D_800E54A4 + p * sizeof(Shared_Player_func_80433F14));
                    if (q >= 0) {
                        D_800E54A4->players[q].back = 2;
                        D_800E54A4->players[q].state = 2;
                        D_800E54A4->players[q].next = 0xD;
                        D_800E54A4->players[q].sub = sub;
                        PAKInterface_RefreshPlayerPanel(q);
                    }
                    break;
                case 7:
                    D_800E54A4->players[p].state = 0x1A;
                    D_800E54A4->players[p].next = 0xD;
                    break;
                }
                break;
            case 0:
                D_800E54A4->players[p].state = 0xE;
                break;
            case 5:
                mode = D_800E54A4->phase;
                switch (mode) {
                case 3:
                    D_800E54A4->players[p].state = 0xE;
                    break;
                case 0:
                    D_800E54A4->players[p].back = 2;
                    D_800E54A4->players[p].state = 2;
                    D_800E54A4->players[p].next = 0xC;
                    D_800E54A4->players[p].sub = 0;
                    break;
                case 2:
                    D_800E54A4->players[p].back = mode;
                    D_800E54A4->players[p].state = mode;
                    D_800E54A4->players[p].next = 9;
                    D_800E54A4->players[p].sub = 3;
                    break;
                }
                break;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        i = 0;
        switch (event) {
#if defined(VERSION_DE)
        case 0x2CB:
#elif defined(VERSION_EU_X)
        case 0x2F8:
#else
        case 0x2B3:
#endif
            i = 1;
            break;
#if defined(VERSION_DE)
        case 0x2CC:
#elif defined(VERSION_EU_X)
        case 0x2FC:
#else
        case 0x2B0:
#endif
            i = 2;
            break;
#if defined(VERSION_DE)
        case 0x2C8:
#elif defined(VERSION_EU_X)
        case 0x2FB:
#else
        case 0x2B4:
#endif
            i = 3;
            break;
        }
        switch (D_800E54A4->players[p].sub) {
        case 0:
            break;
        case 3:
            if (D_800E54A4->players[p].used[i] == 1) {
                Frontend_SetPlayerProfileLink(p, i, 0);
                D_800E54A4->players[p].choice = i;
                D_800E54A4->players[p].state = 0x1B;
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
        case 6:
            switch (D_800E54A4->phase) {
            case 1:
                if (D_800E54A4->players[p].used[i] == 1) {
                    D_800E54A4->players[p].choice = i;
                    D_800E54A4->players[p].state = 0x16;
                    PAKInterface_RefreshPlayerPanel(p);
                }
                break;
            case 7:
                if (D_800E54A4->players[p].used[i] == 1) {
                    Frontend_SetPlayerProfileLink(p, i, 0);
                    PAKInterface_LoadLinkedPlayerProfile(0);
                    MarkMenuEventHandled();
                    PAKInterface_BeginScreenExit(9);
                    return 0;
                }
                break;
            }
            break;
        case 5:
            switch (D_800E54A4->phase) {
            case 0:
            case 2:
            case 3:
                if (D_800E54A4->players[p].used[i] != 2) {
                    D_800E54A4->players[p].choice = i;
                    D_800E54A4->players[p].state = 7;
                    PAKInterface_RefreshPlayerPanel(p);
                }
                break;
            }
            break;
        }
        break;
    case 22:
        switch (event) {
#if defined(VERSION_DE)
        case 0x28C:
#elif defined(VERSION_EU_X)
        case 0x294:
#else
        case 0x28B:
#endif
            i = 0;
            break;
#if defined(VERSION_DE)
        case 0x28E:
#elif defined(VERSION_EU_X)
        case 0x296:
#else
        case 0x28D:
#endif
            i = 1;
            break;
#if defined(VERSION_DE)
        case 0x290:
#elif defined(VERSION_EU_X)
        case 0x298:
#else
        case 0x28F:
#endif
            i = 2;
            break;
#if defined(VERSION_DE)
        case 0x292:
#elif defined(VERSION_EU_X)
        case 0x29A:
#else
        case 0x291:
#endif
            i = 3;
            break;
#if defined(VERSION_DE)
        case 0x28B:
#elif defined(VERSION_EU_X)
        case 0x293:
#else
        case 0x28A:
#endif
            PAKInterface_BeginScreenExit(3);
            return 0;
        }
        Frontend_SetPlayerProfileLink(p, D_800E54A4->players[p].choice, i);
        PAKInterface_LoadLinkedPlayerProfile(i);
#if defined(VERSION_DE)
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].notes[D_800E54A4->players[p].choice], 0x2C9), 1);
#elif defined(VERSION_EU_X)
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].notes[D_800E54A4->players[p].choice], 0x2F9), 1);
#else
        Frontend_SetWidgetFlag08(Frontend_FindWidgetByResourceId((void*)D_800E54A4->players[p].notes[D_800E54A4->players[p].choice], 0x2B1), 1);
#endif
        D_800E54A4->players[p].used[D_800E54A4->players[p].choice] = 0;
        D_800E54A4->links[i].state = 0;
        D_800E54A4->players[p].port = i;
        PAKInterface_RelabelSlotRows(p);
        D_800E54A4->players[p].state = 0xD;
        PAKInterface_RefreshPlayerPanel(p);
        break;
    case 27:
        switch (event) {
#if defined(VERSION_DE)
        case 0x295:
#elif defined(VERSION_EU_X)
        case 0x29E:
#else
        case 0x298:
#endif
            PAKInterface_BeginScreenExit(3);
            return 0;
#if defined(VERSION_DE)
        case 0x296:
#elif defined(VERSION_EU_X)
        case 0x29F:
#else
        case 0x299:
#endif
            i = 0;
            break;
#if defined(VERSION_DE)
        case 0x298:
#elif defined(VERSION_EU_X)
        case 0x2A1:
#else
        case 0x29B:
#endif
            i = 1;
            break;
#if defined(VERSION_DE)
        case 0x29A:
#elif defined(VERSION_EU_X)
        case 0x2A3:
#else
        case 0x29D:
#endif
            i = 2;
            break;
#if defined(VERSION_DE)
        case 0x29C:
#elif defined(VERSION_EU_X)
        case 0x2A5:
#else
        case 0x29F:
#endif
            i = 3;
            break;
        }
        if (i != p) {
            SmpOverlay_SetSlotValue(D_800E54A4->root, p, 1);
            D_800E54A4->players[i].back = 2;
            D_800E54A4->players[i].state = 2;
            D_800E54A4->players[i].next = 9;
            D_800E54A4->players[i].sub = 3;
            D_800E54A4->players[i].host = 1;
            PAKInterface_RefreshPlayerPanel(i);
        } else {
            D_800E54A4->players[p].state = 9;
            PAKInterface_RefreshPlayerPanel(p);
        }
        break;
    case 6:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2AE:
#elif defined(VERSION_EU_X)
        case 0x2CA:
#else
        case 0x2E9:
#endif
            D_800E54A4->players[p].state = 0xE;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2AF:
#elif defined(VERSION_EU_X)
        case 0x2C9:
#else
        case 0x2E8:
#endif
            PAKInterface_CopyActiveProfilesToPakSlots(p);
            if (PAKInterface_SavePlayerRecords(p) == 1) {
                D_800E54A4->players[p].state = 0xE;
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
        }
        break;
    case 21:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2A8:
#elif defined(VERSION_EU_X)
        case 0x2DB:
#else
        case 0x2E2:
#endif
            switch (D_800E54A4->phase) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                D_800E54A4->players[p].state = 0xE;
                PAKInterface_RefreshPlayerPanel(p);
                break;
            }
            break;
#if defined(VERSION_DE)
        case 0x2A7:
#elif defined(VERSION_EU_X)
        case 0x2DA:
#else
        case 0x2E3:
#endif
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 23:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2B8:
#elif defined(VERSION_EU_X)
        case 0x2BF:
#else
        case 0x2AD:
#endif
            D_800E54A4->players[p].state = 0xC;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2B9:
#elif defined(VERSION_EU_X)
        case 0x2C0:
#else
        case 0x2AE:
#endif
            if (D_800E54A4->phase == 7) {
                D_800E54A4->players[p].state = 0x1A;
                D_800E54A4->players[p].next = 0x17;
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 24:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2BE:
#elif defined(VERSION_EU_X)
        case 0x2B0:
#else
        case 0x2AB:
#endif
            D_800E54A4->players[p].state = 0xD;
            D_800E54A4->players[p].sub = 5;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2BD:
#elif defined(VERSION_EU_X)
        case 0x2AF:
#else
        case 0x2AA:
#endif
            if (D_800E54A4->players[p].host == 1) {
                PAKInterface_BeginLinkedProfileTransfer(p);
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            PAKInterface_RefreshPlayerPanel(p);
            break;
        }
        break;
    case 25:
#if defined(VERSION_DE)
        if (event == 0x2BB) {
#elif defined(VERSION_EU_X)
        if (event == 0x2BD) {
#else
        if (event == 0x2EB) {
#endif
            if (D_800E54A4->players[p].host == 1) {
                PAKInterface_BeginLinkedProfileTransfer(p);
            } else {
                D_800E54A4->players[p].state = 0xE;
            }
            PAKInterface_RefreshPlayerPanel(p);
        }
        break;
    case 26:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2C0:
#elif defined(VERSION_EU_X)
        case 0x2BA:
#else
        case 0x2A7:
#endif
            D_800E54A4->players[0].back = 2;
            D_800E54A4->players[0].state = 2;
            D_800E54A4->players[0].next = 0xD;
            D_800E54A4->players[0].sub = 6;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#if defined(VERSION_DE)
        case 0x2C1:
#elif defined(VERSION_EU_X)
        case 0x2BB:
#else
        case 0x2A8:
#endif
            Player_InitializeProfileSlot(0);
            MarkMenuEventHandled();
            PAKInterface_BeginScreenExit(9);
            return 0;
        }
        break;
#if defined(VERSION_EU_X)

#else
#endif
    case 28:
        switch (event) {
#if defined(VERSION_DE)
        case 0x2A2:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        case 0x2A3:
#elif defined(VERSION_EU_X)
        case 0x2CE:
#else
        case 0x2DF:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
        case 0x2E0:
#endif
            if (Pak_RepairId(p) != 0) {
                D_800E54A4->players[p].state = 0x1D;
                PAKInterface_RefreshPlayerPanel(p);
            } else {
                D_800E54A4->players[p].back = 2;
                D_800E54A4->players[p].state = 2;
                PAKInterface_RefreshPlayerPanel(p);
            }
            break;
#if defined(VERSION_EU_X)
        case 0x2CF:
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
            break;
#else
#endif
        }
        break;
#if defined(VERSION_EU_X)
#else

#endif
    case 29:
#if defined(VERSION_DE)
        if (event == 0x2A5) {
#elif defined(VERSION_EU_X)
        if (event == 0x2CC) {
#else
        if (event == 0x2C0) {
#endif
            D_800E54A4->players[p].back = 2;
            D_800E54A4->players[p].state = 2;
            PAKInterface_RefreshPlayerPanel(p);
        }
        break;
    }
    return 0;
}
