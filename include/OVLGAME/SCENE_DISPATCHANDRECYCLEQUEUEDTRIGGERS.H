#ifndef OVLGAME_SCENE_DISPATCHANDRECYCLEQUEUEDTRIGGERS_H
#define OVLGAME_SCENE_DISPATCHANDRECYCLEQUEUEDTRIGGERS_H
#include "TYPES.H"
#include "COMMON/RUNTIME_DECLARATIONS.H"
#include "COMMON/TRIGGER_AND_FLOAT_VALUE_OPERATIONS.H"
#include "COMMON/LEVEL.H"
#include "COMMON/ENTRYRECAT0V3.H"
struct Level {
    char pad0[0x11C0];
    s32 counts[2];
    char pad11C8[8];
    ItemOvlSceneDispatchSelectedEntityKinds *items[2];
};
struct BankCode8044E2B8 {
    s32 unk0;
    s32 count;
    struct SceneFrameItemReference items[1];
};
struct Ent {
    u32 kind;
    char pad4[0x24];
    f32 unk28;
    char pad2C[4];
    f32 unk30;
    f32 unk34;
    char pad38[0x18];
    f32 unk50;
    f32 unk54;
    f32 unk58;
    char pad5C[0x90];
    f32 unkEC;
    f32 unkF0;
};
struct FrameCode8044E2B8 {
    s32 unk0;
    s32 count;
    char pad8[0xC];
    ParticleEffectRelocationSlot slots[1];
};
struct GroupCode8044E2B8 {
    s32 unk0;
    s32 count;
    Piece pieces[1];
};
struct OwnerCode8044E2B8 {
    char pad0[0x6C];
    void *modelBankData;
    char pad70[0xC];
    void *frameResourceData;
    char pad80[0x1158];
    struct EntryOvlSceneDispatchAndRecycleQueuedTriggers *active;
    char pad11DC[0x10];
    struct EntryOvlSceneDispatchAndRecycleQueuedTriggers *spare;
};
/** Release every active entry of arg0 and move it onto the spare list. */
void Scene_DispatchAndRecycleQueuedTriggers(OwnerCode8044E2B8 *owner);
#endif
