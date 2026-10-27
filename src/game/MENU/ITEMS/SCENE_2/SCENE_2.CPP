#include "TYPES.H"
#include "COMMON/LONE/D_800CD764_de.H"
#include "COMMON/AUDIO_CALLBACKS.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/UNUSED.H"
#include "MENU/8044ACCC.H"
#include "COMMON/RESIDENT_EVENT_HANDLER.H"
#include "COMMON/EXTERNS_8.H"
#include "COMMON/EXTERNS_9.H"
#include "COMMON/ENTRYRECAT0V3.H"
#include "COMMON/OBJECTSTATE96.H"
#include "COMMON/OBJB.H"
#include "AI/NAV/80208000_5.H"
#include "MENU/ITEMS/SCENE/SCENE.H"
#include "MENU/ITEMS/SCENE_4/SCENE_7.H"
#include "MENU/PAK/80403BCC_4.H"

extern void Ovlgame_RefreshActivePlayerSceneState(CPlayerPool *);
extern void func_80253908_de(s32 unusedHeap);
extern s32 func_80254284_de(s32,void **,s32,void *);
extern void **func_80254408_de(s32,s32,s32,s32,s32,s32,void *);
extern int SetN64_GetDirectoryEntry(int *,int,int);
extern s32 SetN64_LocatePackSection(s32,s32,s32,s32 *);
extern s32 D_00285160;
extern char D_800F41F0;
void OvlScene_LoadSceneResources(LevelCode8044ACCC *sceneToLoad, s32 cartridgeBankKey) {
    s32 *cartridgeDirectory;
    s32 *bloodlustLevelDirectory;
    void **bloodlustWeaponResource;
    void **warpDestinationsResource;
    void **bloodlustLevelResource;
    s32 levelDirectoryKey;
    s32 textureDirectoryKey;
    s32 objectDirectoryKey;
    s32 binaryDirectoryKey;
    s32 graphicsetDirectoryKey;
    s32 sectionEighteenKey;
    s32 linkGroupTypeData;
    s32 sectionTwelveData;

    Scene_ClearSceneObjectCounts(sceneToLoad);
    sceneToLoad->unk0 = 0;
    OvlScene_ResetSelectionState((char *)sceneToLoad);
    sceneToLoad->unk4 = 0;
    sceneToLoad->unk8 = 0;
    sceneToLoad->unk1B40C = -1;
    sceneToLoad->unk1B31C = 0;
    sceneToLoad->unk1B308 = 0;
    sceneToLoad->unk1B614 = 0;
    sceneToLoad->unk1B618 = 0;
    sceneToLoad->unk1B61C = 0;
    sceneToLoad->unk1B660 = 0;
    sceneToLoad->unk1B6A4 = 0;
    sceneToLoad->unk1B6AC = 0;
    /* The global is the holder storage; its canonical scalar declaration is incomplete. */
    ((void (*)(void *))Ovlgame_RefreshActivePlayerSceneState)(&D_80145040);
    /* The original resource API passes the unused arena argument. */
    func_80253908_de(0);
    func_80254284_de(0, (void **)&cartridgeDirectory, cartridgeBankKey, &g_cartridgeIndex);
    levelDirectoryKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 5);
    sceneToLoad->unk1C = levelDirectoryKey;
    func_80254284_de(0, (void **)(sceneToLoad->pad40 + 0xC), levelDirectoryKey, &D_800C4F60_de);
    textureDirectoryKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 3);
    sceneToLoad->unk20 = textureDirectoryKey;
    func_80254284_de(0, (void **)(sceneToLoad->pad40 + 0x10), textureDirectoryKey, &g_textureSetsIndex);
    sceneToLoad->unk94 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 2, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &D_800C4F84_de);
    objectDirectoryKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 0);
    sceneToLoad->unk24 = objectDirectoryKey;
    func_80254284_de(0, (void **)(sceneToLoad->pad40 + 0x14), objectDirectoryKey, &g_objectsIndex);
    sceneToLoad->unk78 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 1, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_0044D934, &D_800C4FA4_de);
    sceneToLoad->unkB4 = func_80254408_de(0, (s32)cartridgeDirectory, 4, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_0044D804, &g_particleEffects);
    sceneToLoad->unk98 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xA, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &D_800C4F84_de);
    binaryDirectoryKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 9);
    sceneToLoad->unk28 = binaryDirectoryKey;
    func_80254284_de(0, (void **)(sceneToLoad->pad40 + 0x18), binaryDirectoryKey, &D_800C4FC8_de);
    sceneToLoad->unk70 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xB, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_particleSwooshes);
    sectionTwelveData = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xC, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &D_800C4FEC_de);
    sceneToLoad->unk80 = &D_800F91F0;
    sceneToLoad->unkA0 = sectionTwelveData;
    sceneToLoad->unk38 = SetN64_LocatePackSection((s32)cartridgeDirectory, cartridgeBankKey, 6, (s32 *)(sceneToLoad->pad40 + 0x4));
    sceneToLoad->unk84 = &D_800F41F0;
    sceneToLoad->unk3C = SetN64_LocatePackSection((s32)cartridgeDirectory, cartridgeBankKey, 7, (s32 *)(sceneToLoad->pad40 + 0x8));
    warpDestinationsResource = func_80254408_de(0, (s32)cartridgeDirectory, 8, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_warpDests);
    sceneToLoad->unk10C = warpDestinationsResource;
    sceneToLoad->unk90 = (s32) *warpDestinationsResource;
    sceneToLoad->unkA4 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xD, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_curves);
    sceneToLoad->unkAC = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xE, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_rumbleLabels);
    sceneToLoad->unkA8 = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0xF, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &D_800C5018_de);
    sceneToLoad->unk9C = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0x11, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_graphicsetType);
    graphicsetDirectoryKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 0x10);
    sceneToLoad->unk2C = graphicsetDirectoryKey;
    func_80254284_de(0, (void **)(sceneToLoad->pad40 + 0x1C), graphicsetDirectoryKey, &g_graphicsetIndex);
    sectionEighteenKey = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 0x12);
    sceneToLoad->unk34 = sectionEighteenKey;
    func_80254284_de(0, (void **)sceneToLoad->pad74, sectionEighteenKey, &D_800C504C_de);
    Menu_RequestTrackBundle();
    linkGroupTypeData = (s32) *func_80254408_de(0, (s32)cartridgeDirectory, 0x13, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_linkGroupTypes);
    sceneToLoad->unkC = 0;
    sceneToLoad->unk10 = 0;
    sceneToLoad->unk14 = 0;
    sceneToLoad->unk18 = -1;
    sceneToLoad->unkB0 = linkGroupTypeData;
    if (*cartridgeDirectory >= 0x16) {
        sceneToLoad->unkC = SetN64_GetDirectoryEntry(cartridgeDirectory, cartridgeBankKey, 0x15);
        bloodlustLevelResource = /* This callee returns its allocated resource handle, not an integer ID. */
            ((void **(*)(s32,void **,s32,void *,s32))func_802540F4_de)(0, (void **)&bloodlustLevelDirectory, sceneToLoad->unkC, &g_constructBlLevelDataIndex, 1);
        if (bloodlustLevelResource != 0) {
            sceneToLoad->unk10 = (s32) (((*bloodlustLevelDirectory * 4) + 0xF) & ~7);
            Cache_ReleaseResource(0, bloodlustLevelResource);
        } else {
            sceneToLoad->unkC = 0;
        }
    }
    if (*cartridgeDirectory >= 0x18) {
        bloodlustWeaponResource = func_80254408_de(0, (s32)cartridgeDirectory, 0x17, cartridgeBankKey, (s32)sceneToLoad, (s32)&D_00285160, &g_bloodlustWeaponData);
        Nav_LoadCollisionTable(*bloodlustWeaponResource);
        Cache_ReleaseResource(0, bloodlustWeaponResource);
    }
    OvlScene_InitPreview((Shared_World *)sceneToLoad, cartridgeBankKey);
    D_800CD764_de = 1;
    OvlScene_CopySimpleModelHeader(sceneToLoad, sceneToLoad->pad1B410 + 0x40, 0xDAC);
    OvlScene_CopySimpleModelHeader(sceneToLoad, sceneToLoad->pad1B410 + 0x5C, 0xDAD);
    OvlScene_CopySimpleModelHeader(sceneToLoad, sceneToLoad->pad1B410 + 0x78, 0xDAE);
    OvlScene_CopySimpleModelHeader(sceneToLoad, sceneToLoad->pad1B410 + 0x94, 0xDAF);
    OvlScene_CopySimpleModelHeader(sceneToLoad, sceneToLoad->pad1B410 + 0xB0, 0xDB0);
    sceneToLoad->unkF0 = 0;
    sceneToLoad->unkF4 = 0;
    sceneToLoad->unkFC = 0;
    sceneToLoad->unkF8 = 0;
    sceneToLoad->unk88 = 0;
    sceneToLoad->unk120 = 0;
    sceneToLoad->unk124 = 0;
    Scene_LoadLevelResources(sceneToLoad, 0, 0);
}
