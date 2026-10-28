#include "include_asm.h"
#include "COMMON/EXTERNS.H"
#include "TYPES.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/UNUSED.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "COMMON/SELF.H"
#include "AUDIO/INTEGERSTATE1DC4.H"
#include "COMMON/LISTNODE.H"
#include "COMMON/SOUNDVOICEPOOL.H"
#include "COMMON/STATERECAT34.H"
#include "COMMON/EXTERNS_18.H"
#include "AUDIO/8025A3EC_4.H"
#include "AUDIO/802591C0.H"
#include "AUDIO/8025CCB0_2.H"
#include "sdk/OS/AUDIO_STOPMUSIC.H"
#include "sdk/os.h"
#include "SYSTEM/80265370.H"
#include "RENDER/8028FD2C_6.H"
#include "COMMON/EXTERNS_11.H"

/* ROM-grounded data: src/rw_pool_80258B94_C9BD8_us_rev1.c */
const unsigned int D_blob_5ba0e1e9862d81f4542d[2] = {
    0x41F00000, 0x00000000,
};

/* ROM-grounded data: src/rw_pool_80258E5C_C9BE0_us_rev1.c */
const unsigned int D_blob_a66da9ca903522cb6da3[2] = {
    0x3F800000, 0x42200000,
};

extern void Audio_StopVoicesByKey(void *arg0, s32 arg1);

extern void Audio_StopVoicesBySecondaryValue(void *, s32);

extern void Audio_StopVoicesByFlags(void *arg0, s32 arg1);

extern void AudioWorld_RecyclePendingSoundsByFlags(void *arg0, s32 arg1);

extern f32 D_800C3EE0_de[];

extern s32 SetN64_IsModeThirteen(void);

extern void *Gsky_FindNearestCamera(MenuMatchGlobals *arg0, CVector3 *arg1);

extern void Audio_StopVoicesExceptKey(void *arg0, s32 arg1);

extern void AudioWorld_RecyclePendingSoundsExceptKey(void *arg0, s32 arg1);

extern void Audio_FadeOutMusic(int a);

extern void Audio_EnableMusicGainOverride(Track *a);

extern void Audio_DisableMusicGainOverride(Track *a);

/* Picks a weighted random entry from the range Defs_FindSortedGroupRange finds for an id in a scene's table: -1 when
 * the scene has no table or no range, the single entry when the range has one; otherwise each entry weighs
 * ten times its table value, a random draw selects one, and when avoidance is requested and it equals the
 * scene's last pick at 0x130 it steps to the next entry (or back from the last). Adapted from
 * Audio_ChooseSequenceVariant with the table weights and the stored last pick. */

void Audio_StopAudioByKey(ContextRecAt2BC0 *context, s32 matchValue) {
    {
        s32 *contextLock;
        s32 lockClaimCount;
        u32 mask;

        contextLock = &context->lock;
        mask = __osDisableInt();
        lockClaimCount = ((MenuRules *)(contextLock))->locked + 1;
        ((MenuRules *)(contextLock))->locked = lockClaimCount;
        if (lockClaimCount != 1) {
            __osRestoreInt(mask);
            osRecvMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
    Audio_StopVoicesByKey(&context->menu[0], matchValue);
    AudioWorld_RecyclePendingSoundsByKey(&context->view[0], matchValue);
    {
        s32 *contextLock;
        s32 lockClaimCount;
        u32 releaseInterruptMask;

        contextLock = &context->lock;
        releaseInterruptMask = __osDisableInt();
        lockClaimCount = ((MenuRules *)(contextLock))->locked - 1;
        ((MenuRules *)(contextLock))->locked = lockClaimCount;
        if (lockClaimCount != 0) {
            __osRestoreInt(releaseInterruptMask);
            osSendMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(releaseInterruptMask);
        }
    }
}

void Audio_StopAudioBySecondaryValue(ContextRecAt2BC0 *context, s32 matchValue) {
    void *contextLock;
    void *record;
    s32 lockClaimCount;
    u32 mask;
    u32 releaseInterruptMask;

    contextLock = &context->lock;
    mask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked + 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(contextLock, 0, 1);
        record = &context->menu[0];
    } else {
        __osRestoreInt(mask);
        record = &context->menu[0];
    }
    Audio_StopVoicesBySecondaryValue(record, matchValue);
    AudioWorld_RecyclePendingSoundsByTrack(&context->view[0], matchValue);
    contextLock = &context->lock;
    releaseInterruptMask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked - 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(contextLock, 0, 1);
        return;
    }
    __osRestoreInt(releaseInterruptMask);
}

void Audio_StopAudioByMask(ContextRecAt2BC0 *context, s32 matchMask) {
    void *contextLock;
    void *record;
    s32 lockClaimCount;
    u32 mask;
    u32 releaseInterruptMask;

    contextLock = &context->lock;
    mask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked + 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(contextLock, 0, 1);
        record = &context->menu[0];
    } else {
        __osRestoreInt(mask);
        record = &context->menu[0];
    }
    Audio_StopVoicesByFlags(record, matchMask);
    AudioWorld_RecyclePendingSoundsByFlags(&context->view[0], matchMask);
    contextLock = &context->lock;
    releaseInterruptMask = __osDisableInt();
    lockClaimCount = ((MenuRules *)(contextLock))->locked - 1;
    ((MenuRules *)(contextLock))->locked = lockClaimCount;
    if (lockClaimCount != 0) {
        __osRestoreInt(releaseInterruptMask);
        osSendMesg(contextLock, 0, 1);
        return;
    }
    __osRestoreInt(releaseInterruptMask);
}

s32 Audio_PlayPositionedSoundWithScale(ContextRecAt2BC0 *arg0, s32 track, CVector3 arg2, s32 arg3, s32 arg4, f32 arg5) {
    s32 handle;

    arg0->alpha = arg5;
    handle = Sound_PlaySoundAtPosition(arg0, track, arg2, arg3, arg4);
    arg0->alpha = D_800C3EE0_de[1];
    return handle;
}

void Audio_PlayPeriodicTrackSound(ContextRecAt2BC0 *arg0) {
    CVector3 zero;
    void *result;
    CVector3 *vec;

    if (D_800CB720 != 0 &&
        arg0->field2BB4 != 0 &&
        SetN64_IsModeThirteen() != 0 &&
        arg0->track > 0) {
        {
            register f32 value = 0.0f;

            zero.z = value;
            zero.y = value;
            zero.x = value;
        }
        result = Gsky_FindNearestCamera(&D_80145088, &zero);
        vec = &((struct SharedRecAt564V1 *)(result))->position;
        if ((arg0->frame & 3) == 0) {
            Sound_PlaySoundAtPosition(arg0, arg0->track, *vec, 0, -1);
        }
    }
}

void Audio_SetVolumeSettingOne(ContextRecAt2BC0 *arg0, float arg1) {
    arg0->red = arg1;
}

void Audio_SetVolumeSettingZero(ContextRecAt2BC0 *arg0, int arg1) {
    double d = (double)arg1;
    if (arg1 < 0) {
        d = d + D_800C3EE8_de;
    }
    arg0->green = (float)d;
}

/** Store the second argument at byte offset 0x2BA8 in the first argument. */
void Audio_SetDialogVolume(ContextRecAt2BC0 *object, float value) {
    object->blue = value;
}

/** Return the indexed twelve-byte record from the table at offset 0x2B70. */
char *Audio_GetMetadataSectionThreeEntry(char *object, int index) {
    return ((ContextRecAt2BC0 *)(object))->table2B70 + index * 12;
}

void *Audio_GetMetadataSectionFourEntry(ContextRecAt2BC0 *arg0, int arg1) {
    return (char *)arg0->table2B74 + arg1 * 12;
}

/** Return the indexed 12-byte entry under object offset 0x2B78. */
void *Audio_GetMetadataSectionFiveEntry(ContextRecAt2BC0 *arg0, int arg1) {
    return (char *)arg0->table2B78 + arg1 * 12;
}

void Audio_StopAudioExceptKey(void *context, s32 matchValue) {
    {
        s32 *contextLock;
        s32 lockClaimCount;
        u32 mask;

        contextLock = &((ContextRecAt2BC0 *)(context))->lock;
        mask = __osDisableInt();
        lockClaimCount = ((MenuRules *)(contextLock))->locked + 1;
        ((MenuRules *)(contextLock))->locked = lockClaimCount;
        if (lockClaimCount != 1) {
            __osRestoreInt(mask);
            osRecvMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
    Audio_StopVoicesExceptKey(&((ContextRecAt2BC0 *)(context))->menu[0], matchValue);
    AudioWorld_RecyclePendingSoundsExceptKey(&((ContextRecAt2BC0 *)(context))->view[0], matchValue);
    {
        s32 *contextLock;
        s32 lockClaimCount;
        u32 releaseInterruptMask;

        contextLock = &((ContextRecAt2BC0 *)(context))->lock;
        ((ContextRecAt2BC0 *)(context))->field2B9C = 0;
        releaseInterruptMask = __osDisableInt();
        lockClaimCount = ((MenuRules *)(contextLock))->locked - 1;
        ((MenuRules *)(contextLock))->locked = lockClaimCount;
        if (lockClaimCount != 0) {
            __osRestoreInt(releaseInterruptMask);
            osSendMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(releaseInterruptMask);
        }
    }
    Audio_StopDialogPlayer((char *)context + 0x2BC0);
}

/** Thin wrapper forwarding an offset argument to Audio_FadeOutMusic. */
void Audio_FadeOutContextMusic(int contextAddress) {
    Audio_FadeOutMusic(contextAddress + 0x1D64);
}

/** Store the second argument at offset 0x2BAC. */
void Audio_SetVoiceMixValue(ContextRecAt2BC0 *context, int arg1) {
    context->field2BAC = arg1;
}

int Audio_GetVoiceMixValue(ContextRecAt2BC0 *context) {
    return context->field2BAC;
}

/** Store a value in the field at offset 0x2BB4. */
void Audio_SetPeriodicSoundEnabled(char *object, int value) {
    ((ContextRecAt2BC0 *)(object))->field2BB4 = value;
}

/** Store a value in the field at offset 0x2B98. */
void Audio_SetListenerCamera(ContextRecAt2BC0 *object, int value) {
    object->field2B98 = value;
}

/** Read the object word at offset 0x2BB0. */
int Audio_GetSpatialPanMode(void *object) {
    return ((ContextRecAt2BC0 *)(object))->field2BB0;
}

/** Store the supplied word at object offset 0x2BB0. */
void Audio_SetSpatialPanMode(ContextRecAt2BC0 *arg0, int arg1) {
    arg0->field2BB0 = arg1;
}

void *Audio_GetSoundPlayer(void *arg0) {
    return &((ContextRecAt2BC0 *)(arg0))->list[0];
}

/** Store a word in the object field at offset 0x2BB8. */
void Audio_SetMusicGainScalingEnabled(ContextRecAt2BC0 *object, int value) {
    object->field2BB8 = value;
}

s32 Audio_CountSoundVoices(char *obj, s32 owner)
{
    s32 count;
    s32 i;

    count = 0;
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_a0;

        temp_s0 = &((ContextRecAt2BC0 *)(obj))->lock;
        temp_a0 = __osDisableInt();
        temp_v1 = ((MenuRules *)(temp_s0))->locked + 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 1) {
            __osRestoreInt(temp_a0);
            osRecvMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_a0);
        }
    }
    for (i = 0; i < 17; i++) {
        if (((ContextRecAt2BC0 *)obj)->voices[i].sound == owner) {
            count++;
        }
    }
    {
        s32 *temp_s0;
        s32 temp_v1;
        u32 temp_v0;

        temp_s0 = &((ContextRecAt2BC0 *)(obj))->lock;
        temp_v0 = __osDisableInt();
        temp_v1 = ((MenuRules *)(temp_s0))->locked - 1;
        ((MenuRules *)(temp_s0))->locked = temp_v1;
        if (temp_v1 != 0) {
            __osRestoreInt(temp_v0);
            osSendMesg(temp_s0, 0, 1);
        } else {
            __osRestoreInt(temp_v0);
        }
    }
    return count;
}

/** Thin wrapper forwarding an offset argument to Audio_StopMusic. */
void Audio_StopContextMusic(int contextAddress) {
    Audio_StopMusic(contextAddress + 0x1D64);
}

/* Clamps a level to between zero and D_800C8FE0, scales it by D_800C8FE4 and stores it as an integer
   at 0x2B9C of the object. */

void Audio_SetClampedAudioLevel(ObjRecAt2B9C *obj, float value) {
    float v;
    float max = D_800C8FE0;
    if (value > max || !(value < 0.0f)) {
        v = value;
        if (v > max) {
            v = max;
        }
    } else {
        v = 0.0f;
    }
    obj->level = v * D_800C8FE4;
}

/** Thin wrapper forwarding an offset argument to Audio_EnableMusicGainOverride. */
void Audio_EnableContextMusicGainOverride(int contextAddress) {
    Audio_EnableMusicGainOverride(contextAddress + 0x1D64);
}

/** Thin wrapper forwarding an offset argument to Audio_DisableMusicGainOverride. */
void Audio_DisableContextMusicGainOverride(int contextAddress) {
    Audio_DisableMusicGainOverride(contextAddress + 0x1D64);
}

/** Thin wrapper forwarding an offset argument to Audio_ClearVoiceFlags. */
void Audio_ClearContextVoiceFlags(int contextAddress) {
    Audio_ClearVoiceFlags(contextAddress + 0x1DB8);
}

int Audio_PlayDialogGroup(ContextRecAt2BC0 *arg0, int group) {
    float scale = (1.0f);
    float blue = arg0->blue;
    if (!(scale < blue)) {
        scale = blue;
    }
    return Audio_StartDialogGroup(&arg0->dialog[0], group, scale, 0x40);
}

/** Thin wrapper forwarding an offset argument to Audio_StopDialogPlayer. */
void Audio_StopContextDialog(int contextAddress) {
    Audio_StopDialogPlayer(contextAddress + 0x2BC0);
}

/** Sort the table's word entries into ascending unsigned order. */
void Audio_SortTableEntries(SortTable *table) {
    int i;
    int j;
    u32 right;
    u32 left;

    for (i = 0; i < table->count; i++) {
        for (j = i + 1; j < table->count; j++) {
            right = table->entries[j];
            left = table->entries[i];
            if (right < left) {
                table->entries[i] = right;
                table->entries[j] = left;
            }
        }
    }
}

/* Returns the index of the first of seventeen 0xCC-byte slots at offset 0x1DBC whose id at 0xC
   equals the given id, or -1 when the id is -1 or absent. */

int Audio_FindVoiceSlotById(char *context, int id) {
    Voice *slot;
    int i;
    slot = ((ContextRecAt2BC0 *)context)->voices;
    if (id == -1) {
        return -1;
    }
    for (i = 0; i < 17; i++, slot++) {
        if (slot->unkC == id) {
            return i;
        }
    }
    return -1;
}

s32 Audio_ChooseWeightedSoundVariant(SceneRecAt2B5C *scene, s16 id, s16 avoid) {
    s32 first;
    s32 last;
    s32 total;
    s32 entry;
    s32 draw;
    s32 i;

    total = 0;
    if (scene->count != 0) {
        if (Defs_FindSortedGroupRange(scene->ids, scene->count, id, &first, &last) == 0) {
            return -1;
        }
        entry = first;
        if (entry != last) {
            for (i = first; i <= last; i++) {
                total += scene->weights[i] * 10;
            }
            draw = Graphu64_NextRandom() % total;
            total = 0;
            for (entry = first; entry < last; entry++) {
                total += scene->weights[entry] * 10;
                if (total >= draw) {
                        break;
                }
            }
            if (avoid != 0 && entry == scene->lastPick) {
                if (entry == last) {
                        entry--;
                } else {
                        entry++;
                }
            }
        }
        return entry;
    }
    return -1;
}

void Audio_ResolveInstrumentSectionZero(void *arg0, s16 index) {
    SetN64_GetPackSection(SetN64_GetPackSection((((struct ObjectLinks2B50 *) ((s8 *) arg0))->unk_2B4C), (s32) index), 0);
}

void Audio_ResolveInstrumentSectionOne(void *arg0, s16 index) {
    SetN64_GetPackSection(SetN64_GetPackSection((((struct ObjectLinks2B50 *) ((s8 *) arg0))->unk_2B4C), (s32) index), 1);
}

/* Returns 1 when the object's owner at 0x102 is set, or when the id is below 256 and at least six of
   its seventeen 0xCC-byte slots at 0x1E64 already carry that id; otherwise 0. */

int Audio_IsSoundInstanceLimitReached(ObjRecAt1E64 *obj, int id) {
    int count;
    int i;

    if (obj->owner != -1) {
        return 1;
    }
    if (id < 256) {
        count = 0;
        for (i = 0; i < 17; i++) {
            if (obj->slots[i].id == id) {
                count++;
            }
        }
        if (count >= 6) {
            return 1;
        }
    }
    return 0;
}
