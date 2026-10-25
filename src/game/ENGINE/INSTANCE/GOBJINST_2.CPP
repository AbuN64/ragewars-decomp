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





void Instance_LoadModel(void *arg0, s32 *arg1, s32 arg2, s32 extra) {
    s32 *sp28;
    void **resource1;
    void **resource2;
    s32 *entry;
    void *temp;
    void *node;
    s32 key;
    s32 found;

    ((LevelActor *)arg0)->resourceHandle = -1;
    ((LevelActor *)arg0)->resourceState = 0;
    ((LevelActor *)arg0)->resourceWindow = 0;
    ((LevelActor *)arg0)->flags &= 0xFFFBFFFF;
    key = Render_GetDirectoryEntry(arg1, arg2, (u16)((LevelActor *)arg0)->modelIndex);
    resource1 = Scene_RequestResource(0, key, key, 0x18, 0, 0, 0, &D_800C389C_de, 1);
    if (resource1 != 0) {
        entry = *resource1;
        ((LevelActor *)arg0)->animationKey = Render_GetDirectoryEntry(entry, key, 1);
        found = func_802540F4_de(0, &sp28, ((LevelActor *)arg0)->animationKey, &D_800C38B0_de, 1);
        if (found != 0) {
            ((LevelActor *)arg0)->stateE7 = (u8)*sp28;
            ((LevelActor *)arg0)->resourceAlignment = ((*sp28 * 4) + 0xF) & ~7;
            Scene_UnlockResource(0, (void *)found);
        }
        ((LevelActor *)arg0)->resource = Render_LocatePackSection((s32)entry, key, 0, &((LevelActor *)arg0)->resourceFlags);
        ((LevelActor *)arg0)->resourceKey = Render_GetDirectoryEntry(entry, key, 2);
        resource2 = Scene_RequestResource(0, ((LevelActor *)arg0)->resource,
                                 ((LevelActor *)arg0)->resource, ((LevelActor *)arg0)->resourceFlags,
                                 0, 0, 0, &D_800C38C4_de, 1);
        if (resource2 != 0) {
            node = *resource2;
            temp = Render_GetPackSection(node, 0);
            ((LevelActor *)arg0)->controllerUpdate(arg0, (char *)arg0 + 0x170);
            func_8026EE20_de(&((LevelActor *)arg0)->transform, (s32)temp, (char *)arg0 + 0xE8);
            func_80262480_de((char *)arg0 + 0x104);
            func_80262480_de((char *)arg0 + 0x118);
            ((LevelActor *)arg0)->stateE6 = (u8)((ResourceManagerState *)Render_GetPackSection(node, 1))->count;
            ((LevelActor *)arg0)->flags |= 0x40000;
            if (extra > 0) {
                extra = func_80246A08_de(arg0, extra, -1);
            } else {
                extra = -extra;
            }
            if (extra == -1) {
                extra = 0;
            }
            ((LevelActor *)arg0)->nextAnimation = extra;
            ((LevelActor *)arg0)->animationPending = 0;
            if (((LevelActor *)arg0)->animation != extra) {
                ((LevelActor *)arg0)->animationChanged = 1;
            }
            ((LevelActor *)arg0)->animationState = -1;
            ((LevelActor *)arg0)->lean = extra;
            Scene_UnlockResource(0, resource2);
        }
        Scene_UnlockResource(0, resource1);
    }
}
