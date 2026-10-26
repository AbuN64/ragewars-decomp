#include "COMMON/UNUSED.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/ACCESS_S8_10F.H"
#include "TYPES.H"
#include "SCENE/802508E0_4.H"
#include "SCENE/802508E0_9.H"
#include "RENDER_4/8028FD2C_6.H"

extern s32 Render_GetDirectoryEntry(s32 *arg0, s32 arg1, s32 arg2);
extern s32 Render_LocatePackSection(s32, s32, s32, s32 *);
extern void func_8026EE20_de(void *, s32, void *);
extern void func_80262480_de(void *);
extern s32 func_80246A08_de(void *, s32, s32);





void Instance_LoadModel(void *actorStorage, s32 *modelDirectory, s32 directoryBank, s32 extra) {
    s32 *animationMetadata;
    void **resource1;
    void **resource2;
    s32 *entry;
    void *temp;
    void *node;
    s32 key;
    s32 found;

    ((LevelActor *)actorStorage)->resourceHandle = -1;
    ((LevelActor *)actorStorage)->resourceState = 0;
    ((LevelActor *)actorStorage)->resourceWindow = 0;
    ((LevelActor *)actorStorage)->flags &= 0xFFFBFFFF;
    key = Render_GetDirectoryEntry(modelDirectory, directoryBank, (u16)((LevelActor *)actorStorage)->modelIndex);
    resource1 = Scene_RequestResource(0, key, key, 0x18, 0, 0, 0, &D_800C389C_de, 1);
    if (resource1 != 0) {
        entry = *resource1;
        ((LevelActor *)actorStorage)->animationKey = Render_GetDirectoryEntry(entry, key, 1);
        found = func_802540F4_de(0, &animationMetadata, ((LevelActor *)actorStorage)->animationKey, &s_animModelsIndexText, 1);
        if (found != 0) {
            ((LevelActor *)actorStorage)->stateE7 = (u8)*animationMetadata;
            ((LevelActor *)actorStorage)->resourceAlignment = ((*animationMetadata * 4) + 0xF) & ~7;
            Scene_UnlockResource(0, (void *)found);
        }
        ((LevelActor *)actorStorage)->resource = Render_LocatePackSection((s32)entry, key, 0, &((LevelActor *)actorStorage)->resourceFlags);
        ((LevelActor *)actorStorage)->resourceKey = Render_GetDirectoryEntry(entry, key, 2);
        resource2 = Scene_RequestResource(0, ((LevelActor *)actorStorage)->resource,
                                 ((LevelActor *)actorStorage)->resource, ((LevelActor *)actorStorage)->resourceFlags,
                                 0, 0, 0, &D_800C38C4_de, 1);
        if (resource2 != 0) {
            node = *resource2;
            temp = Render_GetPackSection(node, 0);
            ((LevelActor *)actorStorage)->controllerUpdate(actorStorage, (char *)actorStorage + 0x170);
            func_8026EE20_de(&((LevelActor *)actorStorage)->transform, (s32)temp, (char *)actorStorage + 0xE8);
            func_80262480_de((char *)actorStorage + 0x104);
            func_80262480_de((char *)actorStorage + 0x118);
            ((LevelActor *)actorStorage)->stateE6 = (u8)((ResourceManagerState *)Render_GetPackSection(node, 1))->count;
            ((LevelActor *)actorStorage)->flags |= 0x40000;
            if (extra > 0) {
                extra = func_80246A08_de(actorStorage, extra, -1);
            } else {
                extra = -extra;
            }
            if (extra == -1) {
                extra = 0;
            }
            ((LevelActor *)actorStorage)->nextAnimation = extra;
            ((LevelActor *)actorStorage)->animationPending = 0;
            if (((LevelActor *)actorStorage)->animation != extra) {
                ((LevelActor *)actorStorage)->animationChanged = 1;
            }
            ((LevelActor *)actorStorage)->animationState = -1;
            ((LevelActor *)actorStorage)->lean = extra;
            Scene_UnlockResource(0, resource2);
        }
        Scene_UnlockResource(0, resource1);
    }
}
