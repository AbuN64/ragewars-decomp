#include "COMMON/VIEWFLAGS.H"
#include "COMMON/LONE/D_800C32DC_de.H"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/GAMEPLAY_MOVEMENT.H"
#include "COMMON/WORLD.H"
#include "COMMON/CHANNEL.H"
#include "COMMON/TRIPLE.H"
#include "TYPES.H"
#include "CAMERA/80233920_31.H"
#include "RESMGR/802A0888.H"
extern void Cache_ReleaseResource(void *arg0, void *arg1);

/* Produces a random shake offset for an object: looks up the object's model entry in D_8011FE88 and
 * zeroes the offset when there is none; otherwise eases the horizontal and vertical shake amplitudes
 * at 0xF4 and 0xF8 toward the pair D_800C8668 when the entry is flagged 0x10000 (toward zero when not)
 * and draws each offset component at random within the scaled amplitudes. */










extern void *Scene_GetModelRecordByIndexPointer(Shared_World *, u16 *);


extern f32 Region_GetPolygonHeight(s32 arg0, f32 arg1, f32 arg2);


extern void *Cache_AllocateResource(int a, int b, int c, void *d);


void *Cache_AllocateResource(int a, int b, int c, void *d);


extern void func_8025E3F0_de(s32 arg0);

extern void func_80253908_de(s32 a);


void func_80239EA4_de(void *gameplayCamera, CVector3 *out) {
    GameplayCamera *o = gameplayCamera;
    f32 value;
    Shared_Surface *entry;
    f32 targetX;
    f32 targetY;
    f32 scale;

    targetY = 0.0f;
    targetX = targetY;
    entry = Scene_GetModelRecordByIndexPointer(&g_world, (u16 *)o->floorPoly);
    if (entry == 0) {
        out->x = targetY;
        out->y = targetY;
        out->z = targetY;
        return;
    }
    if (entry->flags & 0x10000) {
        targetX = D_800C8668;
        targetY = D_800C357C_de;
    }
    value = o->shakeHorizontal + (targetX - o->shakeHorizontal) * D_800C3580_de.unk0;
    scale = D_800C3584_de.unk0;
    o->shakeHorizontal = value;
    o->shakeVertical += (targetY - o->shakeVertical) * D_800C3588_de.unk0;
    out->x = GraphU64_RandomBetween(-o->shakeHorizontal * scale, o->shakeHorizontal * scale);
    out->y = GraphU64_RandomBetween(0.0f, o->shakeVertical * D_800C358C_de.unk0);
    value = -o->shakeHorizontal * scale;
    out->z = GraphU64_RandomBetween(value, o->shakeHorizontal * scale);
}

/** Preserve the empty hook at VRAM 0x80239FBC. */
void func_80239FCC_de(void) {
}

void func_80239FD4_de(void) {
}

void func_80239FDC_de(void *gameplayCamera) {
    s32 object;
    GameplayCamera *camera = gameplayCamera;
    f32 value;
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    if (Cinema_IsSequenceInWindow() != 0) {
        camera->floorPoly = (Shared_func_80234FDC_S8 *)Scene_FindFloorPolygon(&g_world, &camera->unk38);
    }
    object = (s32)camera->floorPoly;
    x = camera->unk38;
    y = camera->unk3C;
    z = camera->unk40;
    w = camera->unk44;
    camera->floorSurface = D_800CD8D0;
    if (object != 0 && Cinema_IsSequenceInWindow() == 0) {
        value = ((y + w) - Region_GetPolygonHeight(object, x, z)) * D_800C3590_de;
        if (value < D_800C3594_de && D_800C3598_de < value) {
            Shared_func_80234FDC_S8 *surface = (Shared_func_80234FDC_S8 *)object;
            camera->floorSurface = surface->unk1C;
        }
    }
    if (Cinema_IsSequenceInWindow() != 0) {
        camera->floorSurface = D_800CD8D0;
    }
    if (camera->zoomBlend > 0.0f) {
        camera->floorSurface = D_800CD8D0;
    }
}

void func_8023A114_de(void *messageBuffer, s32 count) {
    MessageBuffer *buffer = messageBuffer;
    s32 *allocation;
    s32 bytes;
    s32 firstBlock;

    bytes = count * 0xED8;
    buffer->count = count;
    allocation = Cache_AllocateResource(0, bytes, 0x23, (char *)&D_800C32D0_de + 4);
    buffer->allocation = allocation;
    firstBlock = *allocation;
    buffer->first = firstBlock;
    XPlus_FillMemory(firstBlock, 0, bytes);
}

void func_8023A190_de(void *screenMessageOwner, int count) {
    struct ScreenMessageOwner *owner = screenMessageOwner;
    int *allocation;
    int bytes;
    int firstBlock;
    bytes = count << 6;
    owner->storage.count = count;
    allocation = Cache_AllocateResource(0, bytes, 0x23, &D_800C32DC_de);
    owner->storage.allocation = allocation;
    firstBlock = *allocation;
    owner->storage.first = firstBlock;
    XPlus_FillMemory(firstBlock, 0, bytes);
}

void func_8023A1F4_de(struct ScreenMessageOwner *owner) {
    s32 allocation;

    owner->state = 1;
    func_8025E3F0_de((s32)&owner->rendering);
    func_80253908_de(0);
    allocation = owner->allocation;
    if (allocation != 0) {
        Cache_ReleaseResource(0, allocation);
        owner->allocation = 0;
        owner->allocationSize = 0;
        owner->count = 0;
    }
}
