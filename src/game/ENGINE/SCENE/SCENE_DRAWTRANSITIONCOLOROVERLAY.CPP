#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/COLORENTRY.H"
#include "ENGINE/SCENE_SETLEVELACTORSTATEBIT.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "ENGINE/SCENE_12.H"
#include "SYSTEM/80265370.H"
#include "RENDER/8028FD2C_6.H"
#include "COMMON/GAME_SESSION.H"

/* SCENE_12.CPP */
/* Draws each selected entry in the object range with shared position and scale. */

extern void Rumble_AllocatePoolNode(s32,void *,Triple,f32,f32,s32);

extern void SetN64_DrawColorRectangle(void *arg0, s8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

void Scene_SetTypeThreeActorStateBits(void *world) {
    Shared_World *object;
    s32 count;
    s32 i;
    s32 offset;
    LevelActor *entry;
    s32 field;
    s32 three;

    object = world;
    count = object->actorCount;
    i = 0;
    if (count > 0) {
        three = 3;
        offset = 0;
        do {
            object = world;
            entry = (void *)((char *)object->actors + offset);
            field = ((struct Def *)entry->definition)->type;
            if (field != three) {
                i += 1;
            } else {
                Rumble_SetActorStateBit(world, entry, 1);
                i += 1;
            }
            offset += 0x2E8;
        } while (i < count);
    }
}

void Scene_ClearTypeThreeActorStateBits(void *arg0) {
    Shared_World *object;
    s32 count;
    s32 i;
    s32 offset;
    LevelActor *entry;
    s32 field;
    s32 three;

    object = arg0;
    count = object->actorCount;
    i = 0;
    if (count > 0) {
        three = 3;
        offset = 0;
        do {
            object = arg0;
            entry = (void *)((char *)object->actors + offset);
            field = ((struct Def *)entry->definition)->type;
            if (field != three) {
                i += 1;
            } else {
                Rumble_SetActorStateBit(arg0, entry, 0);
                i += 1;
            }
            offset += 0x2E8;
        } while (i < count);
    }
}

/** Return an indexed record from the world's strided table. */
void *Scene_GetEffectCurveRecord(Shared_World *world, s32 index) {
    StridedTable *table = world->stridedRecords;
    void *base = table;
    char *bytes = base;
    s32 stride = table->stride;
    return bytes + (index * stride + 8);
}

void CScene_StartEventClips(ObjectCSceneStartEventClips *arg0,s32 resource,s32 arg2,Triple pos,D_800C7470_Pair scale) {
 s32 sp20,sp24; void *data; s32 count; StridedTable *temp_v1; s32 i; StridedTable *temp_v0;
 f32 arg6,arg7;
 temp_v0=arg0->unkA8;
 arg6=scale.first;arg7=scale.second;
 data=temp_v0->data;count=temp_v0->count;
 if(Defs_FindSortedGroupRange(data,count,arg2,&sp20,&sp24)) {
  for(i=sp20;i<=sp24;i++) {
   temp_v1=arg0->unkAC;
   Rumble_AllocatePoolNode(resource,(char *)temp_v1+(i*temp_v1->stride+8),pos,arg6,arg7,0);
  }
 }
}

void *Scene_GetActorDefinition(void *world, s32 index) {
    void *result;

    if (index == -1) {
        goto ret_null;
    }
    result = SetN64_GetPackSection(((struct ObjRecAt78V1 *) ((s8 *) world))->unk78, index);
    goto end;
ret_null:
    result = 0;
end:
    return result;
}

void *Scene_FindActorDefinition(Shared_World *world, s32 selection, s32 modelKind) {
    s32 *descriptor;
    s32 count;
    s32 i;
    ActorDefinitionHeader *entry;

    descriptor = world->actorDefinitions;
    count = *descriptor;
    for (i = 0; i < count; i++) {
        entry = SetN64_GetPackSection(world->actorDefinitions, i);
        if (selection != -1 && entry->kind != selection) {
            continue;
        }
        if (modelKind == -1) {
            return entry;
        }
        if (entry->character != modelKind) {
            continue;
        }
        return entry;
    }
    return 0;
}

/* Collects up to max records of arg0 (indices unk13C to unk140) whose unkE4, unk18->unk0 and unk18->unkC match key0, key1 and key2 (each skipped when -1) into out, returning the count. */
s32 Scene_CollectMatchingLevelActors(Container *container, s32 key0, s32 key1, s32 key2, RecordRecAtE4 **out, s32 max) {
    s32 i = container->unk13C;
    s32 end = container->unk140;
    RecordRecAtE4 *base = container->unk138;
    s32 count = 0;
    RecordRecAtE4 *rec;

    for (; i < end; i++) {
        rec = &base[i];
        if (count >= max) {
            return count;
        }
        if ((key0 == -1 || rec->unkE4 == key0) && (key1 == -1 || rec->unk18->unk0 == key1)
            && (key2 == -1 || rec->unk18->unkC == key2)) {
            *out++ = rec;
            count++;
        }
    }
    return count;
}

void Scene_DrawTransitionColorOverlay(Shared_World *world) {
    s8 color[4];
    s32 state;
    ColorEntry *entry;
    f32 alpha;
    s32 converted;

    state = world->frozen;
    if (state == 0) {
        return;
    }
    if (state < 0) {
        return;
    }
    if (state >= 3) {
        return;
    }
    {
        entry = &g_emacText[world->selectionState];
        if (entry->value != 0.0f) {
            color[0] = entry->red;
            color[1] = entry->green;
            color[2] = entry->blue;
            alpha = (world->selectionTimer * D_800CA3E0[1]) /
                    entry->value;
            if (!(D_800C52F8_de <= alpha)) {
                converted = (s32)alpha;
            } else {
                converted = (s32)(alpha - D_800C52F8_de);
                converted |= 0x80000000;
            }
            color[3] = converted;
            SetN64_DrawColorRectangle(&D_8011FAC0, color, 0, 0, D_800E28D0,
                          D_800E28D4);
        }
    }
}

/* SCENE_13.CPP */
char *Scene_GetPlatformRoute(void *world, s32 index) {
    return SetN64_GetPackSection(SetN64_GetPackSection((((struct ObjRecAt7C *) ((s8 *) world))->unk7C), index), 0);
}
