#include "COMMON/EXTERNS_18.H"
#include "COMMON/SHARED_GAMESLOT.H"
#include "COMMON/GAMEPLAY_ROUND_RULES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/CARTRIDGEREADWORKER.H"
#include "COMMON/OBJRECAT4V6.H"
#include "COMMON/STATERECAT34.H"
#include "TYPES.H"
#include "COMMON/EXTERNS.H"
#include "sdk/os.h"
#include "TEXTURE/80256220_16.H"

extern f32 D_800C3EE0_de;

#include "COMMON/MENU_MATCH_GLOBALS.H"
#include "AUDIO/8025A3EC_4.H"
#include "AUDIO_2/8025D470_2.H"

extern u32 __osDisableInt(void);

extern void func_80259440_de(void *arg0);
extern void Audio_UpdateDialogPlayer(void *arg0);

extern void Audio_UpdateMusicPlayback(void *arg0);
extern s32 func_802934F8_de(void);
extern void *Camera_FindNearestCamera(MenuMatchGlobals *arg0, CVector3 *arg1);










s32 func_8025842C_de(void *context) {
    char *object = context;
    u8 *bytes = &D_801462C8.volume[1];
    char *queue;
    u32 mask;
    s32 count;

    ((struct ContextRecAt2BC0 *)(object))->red = (f32)bytes[0] * D_800C3EE0_de;
    ((struct ContextRecAt2BC0 *)(object))->green = (f32)bytes[-1] * D_800C3EE0_de;
    ((struct ContextRecAt2BC0 *)(object))->blue = (f32)bytes[1] * D_800C3EE0_de;
    queue = object + 0x110;
    ((struct ContextRecAt2BC0 *)(object))->field2BB0 = bytes[-2];
    mask = __osDisableInt();
    count = ((MenuRules *)(queue))->locked + 1;
    ((MenuRules *)(queue))->locked = count;
    if (count != 1) {
        __osRestoreInt(mask);
        osRecvMesg(queue, 0, 1);
    } else {
        __osRestoreInt(mask);
    }

    Audio_UpdateVoicePool(&((struct ContextRecAt2BC0 *)(object))->menu[0]);
    {
        char *queue2 = object + 0x110;
        u32 mask2 = __osDisableInt();
        s32 count2 = ((MenuRules *)(queue2))->locked - 1;

        ((MenuRules *)(queue2))->locked = count2;
        if (count2 != 0) {
            __osRestoreInt(mask2);
            osSendMesg(queue2, 0, 1);
        } else {
            __osRestoreInt(mask2);
        }
    }

    func_80259440_de((char *)object + 0x138);
    Audio_UpdateDialogPlayer((char *)object + 0x2BC0);
    queue = object + 0x1D64;
    Audio_UpdateMusicFade(queue);
    Audio_UpdateMusicPlayback(queue);

    if (D_800CB720 != 0 &&
        ((struct ContextRecAt2BC0 *)(object))->field2BB4 != 0 &&
        func_802934F8_de() != 0 &&
        ((struct ContextRecAt2BC0 *)(object))->track > 0) {
        CVector3 zero;
        void *result;
        CVector3 *vec;

        zero.z = 0.0f;
        zero.y = 0.0f;
        zero.x = 0.0f;
        result = Camera_FindNearestCamera(&D_80145088, &zero);
        vec = &((struct SharedRecAt564V1 *)(result))->position;
        if ((((struct ContextRecAt2BC0 *)(object))->frame & 3) == 0) {
            Texture_PlaySoundAtPosition(object, ((struct ContextRecAt2BC0 *)(object))->track, *vec, 0, -1);
        }
    }
    return ++((struct ContextRecAt2BC0 *)(object))->frame;
}

extern u32 __osDisableInt(void);
extern s32 Audio_HasVoiceOrReservedSlotWithKey(void *arg0, s32 arg1);
extern s32 func_80259AB8_de(void *arg0, s32 arg1);






s32 func_802585F4_de(struct ContextRecAt2BC0 *context, s32 queryValue) {
    {
        MenuRules *contextLock;
        s32 lockClaimCount;
        u32 mask;

        contextLock = &context->lock;
        mask = __osDisableInt();
        lockClaimCount = contextLock->locked + 1;
        contextLock->locked = lockClaimCount;
        if (lockClaimCount != 1) {
            __osRestoreInt(mask);
            osRecvMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(mask);
        }
    }
    if (Audio_HasVoiceOrReservedSlotWithKey(&context->menu[0], queryValue) != 0) {
        MenuRules *contextLock;
        s32 lockClaimCount;
        u32 releaseInterruptMask;

        contextLock = &context->lock;
        releaseInterruptMask = __osDisableInt();
        lockClaimCount = contextLock->locked - 1;
        contextLock->locked = lockClaimCount;
        if (lockClaimCount != 0) {
            __osRestoreInt(releaseInterruptMask);
            osSendMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(releaseInterruptMask);
        }
        return 1;
    }
    if (func_80259AB8_de(&context->view[0], queryValue) != 0) {
        MenuRules *contextLock;
        s32 lockClaimCount;
        u32 releaseInterruptMask;

        contextLock = &context->lock;
        releaseInterruptMask = __osDisableInt();
        lockClaimCount = contextLock->locked - 1;
        contextLock->locked = lockClaimCount;
        if (lockClaimCount != 0) {
            __osRestoreInt(releaseInterruptMask);
            osSendMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(releaseInterruptMask);
        }
        return 1;
    }
    {
        MenuRules *contextLock;
        s32 lockClaimCount;
        u32 releaseInterruptMask;

        contextLock = &context->lock;
        releaseInterruptMask = __osDisableInt();
        lockClaimCount = contextLock->locked - 1;
        contextLock->locked = lockClaimCount;
        if (lockClaimCount != 0) {
            __osRestoreInt(releaseInterruptMask);
            osSendMesg(contextLock, 0, 1);
        } else {
            __osRestoreInt(releaseInterruptMask);
        }
    }
    return 0;
}

extern u32 __osDisableInt(void);






void func_80258740_de(s32 *engine) {
    MenuRules *menuRules;
    s32 claimCount;
    u32 mask;

    menuRules = &((struct ContextRecAt2BC0 *)(engine))->lock;
    mask = __osDisableInt();
    claimCount = menuRules->locked + 1;
    menuRules->locked = claimCount;
    if (claimCount != 1) {
        __osRestoreInt(mask);
        osRecvMesg(menuRules, 0, 1);
        return;
    }
    __osRestoreInt(mask);
}

extern u32 __osDisableInt(void);






void func_802587A4_de(s32 *engine) {
    MenuRules *menuRules;
    s32 remainingClaims;
    u32 mask;

    menuRules = &((struct ContextRecAt2BC0 *)(engine))->lock;
    mask = __osDisableInt();
    remainingClaims = menuRules->locked - 1;
    menuRules->locked = remainingClaims;
    if (remainingClaims != 0) {
        __osRestoreInt(mask);
        osSendMesg(menuRules, 0, 1);
        return;
    }
    __osRestoreInt(mask);
}
