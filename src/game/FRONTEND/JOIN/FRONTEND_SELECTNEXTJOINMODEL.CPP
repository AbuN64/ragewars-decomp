#include "include_asm.h"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/LONE/D_80152789.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "RENDER/SOUNDELEMENT_PLAYFLATSOUND.H"

/* 8040C640_6.CPP */
#if defined(VERSION_US)
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
extern ResidentEventHandlerEntry D_800EB1A4[];

s32 Frontend_DispatchUsJoinOptionsEvent(ActorDefinitionHeader *actor, s32 event, s32 arg2, s32 arg3, s32 arg4) {
    s32 index;
    index = 0;
    if (D_800EB1A4[index].handler != 0) {
        do {
            if (D_800EB1A4[index].event == event) {
                if (D_800EB1A4[index].actorKind == actor->character || D_800EB1A4[index].actorKind == 30000) {
                    return D_800EB1A4[index].handler(actor, event, arg2, arg3, arg4);
                }
            }
            index++;
        } while (D_800EB1A4[index].handler != 0);
    }
    return 0;
}
#endif

#if defined(VERSION_US)
char rodata_unresolved_8041F1A8[8] =
    "I_ANIM_G";
#endif

/* 8041DF04_5.CPP */
#if !(defined(VERSION_US))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Steps the model of the join request the screen D_800E39C0 edits (index at 0x14) back on event 1
   unless Menu_GetPreviousScreenOwner reports 0x16: calls MarkMenuEventHandled, finds the request's place in the 3 by 17
   model table g_rewardItemTiers through Join_FindJoinModelIndex, walks back through its variants and, before the
   first, to the last variant of the previous model (wrapping to the last), skipping entries whose
   id is -1, then stores the variant at 0x4 and 0xC and the id at 0x0 of the 28-byte request in
   D_80153F80, copies the name of the entry the found id selects in that variant row to 0x10, redraws through Join_UpdateJoinRequestDisplay and plays sound
   0xE81. Returns zero. */

extern struct func_80204468_S3 *D_800E39C0;
extern struct TextEntry g_rewardItemTiers[][17];
extern void MarkMenuEventHandled();
extern void XPlus_CopyString(char *, char *);

s32 Frontend_SelectPreviousJoinModel(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) {
        return 0;
    }
    MarkMenuEventHandled();
    if (Menu_GetPreviousScreenOwner(0) == 0x16) {
        return 0;
    }
    variant = D_80153F80[D_800E39C0->unk14].variant;
    model = Join_FindJoinModelIndex(variant, D_80153F80[D_800E39C0->unk14].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) {
                model = 16;
            }
        }
        id = g_rewardItemTiers[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->unk14].variant = variant;
    D_80153F80[D_800E39C0->unk14].id = id;
    XPlus_CopyString(D_80153F80[D_800E39C0->unk14].name, 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        g_rewardItemTiers[variant][id].text[g_languageIndex]
#else
        *g_rewardItemTiers[variant][id].text
#endif
    );
    D_80153F80[D_800E39C0->unk14].variantC = variant;
    Join_UpdateJoinRequestDisplay(D_800E39C0->unk14);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
#endif

/* Steps the model of the join request the screen D_800E39C0 edits (index at 0x14) forward on event 1
   unless Menu_GetPreviousScreenOwner reports 0x16: calls MarkMenuEventHandled, finds the request's place in the 3 by 17
   model table g_rewardItemTiers through Join_FindJoinModelIndex, walks forward through its variants and, past the
   last, to the first variant of the next model (wrapping to the first), skipping entries whose
   id is -1, then stores the variant at 0x4 and 0xC and the id at 0x0 of the 28-byte request in
   D_80153F80, copies the name of the entry the found id selects in that variant row to 0x10, redraws through Join_UpdateJoinRequestDisplay and plays sound
   0xE81. Returns zero. Adapted from Frontend_SelectPreviousJoinModel with the walk direction reversed. */

s32 Frontend_SelectNextJoinModel(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) {
        return 0;
    }
    MarkMenuEventHandled();
    if (Menu_GetPreviousScreenOwner(0) == 0x16) {
        return 0;
    }
    variant = D_80153F80[D_800E39C0->unk14].variant;
    model = Join_FindJoinModelIndex(variant, D_80153F80[D_800E39C0->unk14].id);
    do {
        variant++;
        if (variant >= 3) {
            variant = 0;
            model++;
            if (model >= 17) {
                model = 0;
            }
        }
        id = g_rewardItemTiers[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->unk14].variant = variant;
    D_80153F80[D_800E39C0->unk14].id = id;
    XPlus_CopyString(D_80153F80[D_800E39C0->unk14].name, 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        g_rewardItemTiers[variant][id].text[g_languageIndex]
#else
        *g_rewardItemTiers[variant][id].text
#endif
    );
    D_80153F80[D_800E39C0->unk14].variantC = variant;
    id = D_800E39C0->unk14;
    Join_UpdateJoinRequestDisplay(id);
    SoundElement_PlayFlatSound(0xE81);
    return 0;
}
#endif
