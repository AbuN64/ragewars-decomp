#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "MENU/PAK/SAVE_SNAPSHOT.H"
#include "COMMON/LONE/D_0044E4F8.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/MENURECAT24.H"
#include "MENU/PAK_PROFILE_PROMPT_VIEWS.H"
#include "TYPES.H"
#include "MENU/PAK/SNAPSHOT_CLOSENOTEBROWSER.H"
extern void Cache_ReleaseResource(void *cache, void *resource);

/* Releases temporary profile buffers and opens the controller-pak prompt for the selected player and channel, labelling the port prompt by channel. */







extern char D_0044FB2C[];
extern char g_playerViewRenderContext[];
extern char g_matchEndingTeamWheelClose[];




extern s32 g_pakUseScannedChannel;



extern s32 g_controllerPakSnapshotPayload;

extern SharedPlayer *Playerai_FindPlayerByController(void *profiles, PakMenuSlot *slot);
extern void Cache_DrainAndCompactResources(s32 heap);
extern void Menu_OpenDialog(void *buffer, char *message, SharedPlayer *player, char *title, s32 channel);

static inline void get_channel(PakNoteBrowserContext *menu, s32 *channel) {
    if (g_pakUseScannedChannel != 0) {
        *channel = g_introSelectedItem;
    } else {
        *channel = menu->slot->controllerPort;
    }
}

s32 Snapshot_CloseNoteBrowser(void *unused, PakNoteBrowserContext *menu) {
    s32 channel;
    char *label;
    s8 port;
    SharedPlayer *target;
    SharedPlayer *player;

    if (g_pakSnapshotResourceHandle != 0 || g_pakLoadedNoteResourceHandle != 0) {
        Cache_DrainAndCompactResources(0);
    }
    if (g_pakSnapshotResourceHandle != 0) {
        Cache_ReleaseResource(0, g_pakSnapshotResourceHandle);
    }
    if (g_pakLoadedNoteResourceHandle != 0) {
        Cache_ReleaseResource(0, g_pakLoadedNoteResourceHandle);
    }
    g_pakSnapshotResourceHandle = 0;
    g_pakLoadedNoteResourceHandle = 0;
    g_pakSaveSnapshot = 0;
    g_controllerPakSnapshotPayload = 0;
    D_8014D480 = 0;
    get_channel(menu, &channel);
    if (g_pakUseScannedChannel != 0) {
        D_8014ADA0 = 0;
        D_80146D60 = 0;
        D_8014AD9C = 1;
        D_80142CAC = 0;
        Menu_OpenDialog(g_matchEndingTeamWheelClose, D_0044E4F8, 0, (char *)menu->slot, 0);
        return 1;
    }
    if (D_8014D4EC_de != 0) {
        if (D_80153760 != 0) {
            D_80153784 = 1;
            target = Playerai_FindPlayerByController(g_playerViewRenderContext, menu->slot);
            Menu_OpenDialog(target->views5DC.view5DC_6.storage + 0x554, D_0044FB2C, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
        if (D_8014D4C0_de != 0) {
            D_80153784 = 1;
            port = menu->slot->controllerPort;
            player = menu->player;
            channel = port;
            target = player;
            switch (channel) {
            default:
            case 0:
                label = D_00450BF0_de;
                break;
            case 1:
                label = D_00450C14_de;
                break;
            case 2:
                label = D_00450C38_de;
                break;
            case 3:
                label = D_00450C5C_de;
                break;
            }
            Menu_OpenDialog(target->views5DC.view5DC_6.storage + 0x554, label, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
    } else {
        target = Playerai_FindPlayerByController(g_playerViewRenderContext, menu->slot);
        if (D_80153760 != 0) {
            D_80153784 = 1;
            Menu_OpenDialog(g_playerViewRenderContext + 0x5DC, D_0044FFA4, target, target->views5E8.view698_38.title, channel);
            return 1;
        }
        if (D_8014D4C0_de != 0) {
            D_80153784 = 1;
            return 1;
        }
    }
    return 0;
}
