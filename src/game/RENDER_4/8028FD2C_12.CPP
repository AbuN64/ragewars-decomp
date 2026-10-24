#include "COMMON/RESULTS.H"
#include "RENDER_4/8026AC38.H"
#include "RENDER_4/8028FD2C.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/GAMEPLAY_CAMERA.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/OBJECTSTATE18.H"
#include "TYPES.H"
#include "WORLD_2/8024E914_8.H"

extern ListNode80290528 *D_80131140;

extern ListNode80290528 *D_80131144;

extern ListNode80290528 *D_80131148;



extern f32 D_800C53AC_de;

extern s32 func_80296B74_de(void *arg0, void *arg1);

extern void func_8024EB90_de(void *arg0);

extern f32 D_801031F8[];

extern s32 func_8024D160_de(void *arg0);

extern void func_80290950_de(void *arg0, void *arg1);

extern void func_80246184_de(void *arg0);

/** Unlink an active node and return it to the global free list. */
void func_80290548_de(ListNode80290528 *node) {
    ListNode80290528 *oldHead;

    if (node->flags & 1) {
        node->flags &= ~1;
        if (node->reference_count != 0) {
            (*node->reference_count)--;
        }
        if (node->previous != 0) {
            node->previous->next = node->next;
        }
        if (node->next != 0) {
            node->next->previous = node->previous;
        }
        if (D_80131144 == node) {
            D_80131144 = node->next;
        }
        if (D_80131148 == node) {
            D_80131148 = node->previous;
        }
        oldHead = D_80131140;
        node->previous = 0;
        *(ListNode80290528 *volatile *) &node->next = oldHead;
        D_80131140 = node;
    }
}

void func_802905F4_de(char *arg0, char *view) {
    WorldRecAt3C08 *world = (void *)arg0;
    GameplayCamera *camera = (void *)view;
    SceneEffect *entry;
    f32 value;
    f32 upper;
    f32 scale;
    f32 zero;

    func_8026D980_de();
    entry = world->head;
    if (entry != 0) {
        zero = 0.0f;
        upper = D_800C53A8_de;
        scale = D_800C53AC_de;
        do {
            if ((camera->clipBounds[1].x > entry->minX) &&
                (camera->clipBounds[0].x < entry->maxX) &&
                (camera->clipBounds[1].z > entry->minZ) &&
                (camera->clipBounds[0].z < entry->maxZ) &&
                (camera->clipBounds[1].y > entry->minY) &&
                (camera->clipBounds[0].y < entry->maxY) &&
                (func_80296B74_de(camera->clipPlanes, &entry->minX) != 0)) {
                value = entry->lifetime;
                D_800D15E0 = 0;
                if ((value > zero) && (value <= upper)) {
                    D_800D15E0 = 1;
                    D_800D15E4[3] = value * scale;
                }
                func_8024EB90_de(entry);
                D_800D15E0 = 0;
            }
            entry = entry->next;
        } while (entry != 0);
    }
    func_8026D9D0_de();
}

void func_8029076C_de(ContainerRecAt3C04 *arg0, Results *results) {
    f32 *bounds;
    s32 count;
    s32 mask;
    s32 required;
    s32 limit;
    Node_func_8029076C_de *node;

    node = arg0->head;
    if (node != 0) {
        mask = 0x30000;
        required = 0x20000;
        bounds = D_801031F8 + 1;
        limit = 0x200;
        do {
            func_8024F470_de(node);
            if (((node->flags & mask) == required) &&
                (func_8024D160_de(node) != 0) &&
                !(*(u16 *)&node->flags & 0x100) &&
                (bounds[0] > node->x0) &&
                (bounds[-3] < node->y0) &&
                (bounds[2] > node->x2) &&
                (bounds[-1] < node->y2) &&
                (bounds[1] > node->x1) &&
                (bounds[-2] < node->y1)) {
                count = results->count;
                if (count != limit) {
                    results->nodes[count] = node;
                    results->count = count + 1;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}

void *func_802908C0_de(ObjectLinks3C0C *arg0)
{
  void *new_var;
  void *node;
  struct ListNode80290528 *next;
  if ((arg0->unk_3C00) == 0)
  {
    func_80290950_de(arg0, arg0->unk_3C08);
  }
  node = arg0->unk_3C00;
  next = arg0->next;
  arg0->unk_3C00 = ((ObjectLinks1E0 *)(node))->unk_1DC;
  if (next != 0)
  {
    next->previous = node;
  }
  new_var = arg0->next;
  ((ObjectLinks1E0 *)(node))->unk_1D8 = 0;
  ((ObjectLinks1E0 *)(node))->unk_1DC = new_var;
  arg0->next = node;
  if ((arg0->unk_3C08) == 0)
  {
    arg0->unk_3C08 = node;
  }
  ((ObjectLinks1E0 *)(node))->unk_1D0 |= 1;
  func_80246184_de(node);
  ((ObjectLinks1E0 *)(node))->unk_1C8 = 0;
  return node;
}
