#include "COMMON/WORLDRECAT1B6A4.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/AIPROFILE.H"
#include "COMMON/WORLD.H"
#include "COMMON/MULTIPLAYEROPTIONS.H"
#include "COMMON/OBJECTLINKS150C.H"
#include "COMMON/COLORENTRY.H"
#include "COMMON/WORLDSORTENTRY.H"
#include "COMMON/LEVEL_ACTOR.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "COMMON/SHAREDTRACKOBJECTPREFIX.H"
#include "COMMON/ANIMATIONTRIGGERDEFINITION.H"
#include "RENDER_4/8028B64C_6.H"
#include "SYSTEM_3/80265370.H"
#include "RENDER_4/8028FD2C_6.H"

/* Draws each selected entry in the object range with shared position and scale. */




extern void func_80285B64_de(s32,void *,Triple,f32,f32,s32);






#include "COMMON/GAME_SESSION.H"

extern void func_8029311C_de(void *arg0, s8 *arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5);

void func_8028CD68_de(void *arg0) {
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
                func_80285DB0_de(arg0, entry, 1);
                i += 1;
            }
            offset += 0x2E8;
        } while (i < count);
    }
}

void func_8028CDF0_de(void *arg0) {
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
                func_80285DB0_de(arg0, entry, 0);
                i += 1;
            }
            offset += 0x2E8;
        } while (i < count);
    }
}

/** Return an indexed record from the world's strided table. */
void *func_8028CE78_de(Shared_World *world, s32 index) {
    StridedTable *table = world->stridedRecords;
    void *base = table;
    char *bytes = base;
    s32 stride = table->stride;
    return bytes + (index * stride + 8);
}

void func_8028CE94_de(Object_func_8028CE94_de *arg0,s32 arg1,s32 arg2,Triple pos,D_800C7470_Pair scale) {
 s32 sp20,sp24; void *data; s32 count; StridedTable *temp_v1; s32 var_s0; StridedTable *temp_v0;
 f32 arg6,arg7;
 temp_v0=arg0->unkA8;
 arg6=scale.first;arg7=scale.second;
 data=temp_v0->data;count=temp_v0->count;
 if(func_80265550_de(data,count,arg2,&sp20,&sp24)) {
  for(var_s0=sp20;var_s0<=sp24;var_s0++) {
   temp_v1=arg0->unkAC;
   func_80285B64_de(arg1,(char *)temp_v1+(var_s0*temp_v1->stride+8),pos,arg6,arg7,0);
  }
 }
}

void *func_8028CF6C_de(void *arg0, s32 arg1) {
    void *result;

    if (arg1 == -1) {
        goto ret_null;
    }
    result = func_8028FDB4_de(((struct ObjRecAt78V1 *) ((s8 *) arg0))->unk78, arg1);
    goto end;
ret_null:
    result = 0;
end:
    return result;
}

void *func_8028CFA0_de(Shared_World *arg0, s32 arg1, s32 arg2) {
    s32 *descriptor;
    s32 count;
    s32 i;
    ActorDefinitionHeader *entry;

    descriptor = arg0->actorDefinitions;
    count = *descriptor;
    for (i = 0; i < count; i++) {
        entry = func_8028FDB4_de(arg0->actorDefinitions, i);
        if (arg1 != -1 && entry->kind != arg1) {
            continue;
        }
        if (arg2 == -1) {
            return entry;
        }
        if (entry->character != arg2) {
            continue;
        }
        return entry;
    }
    return 0;
}

/* Collects up to max records of arg0 (indices unk13C to unk140) whose unkE4, unk18->unk0 and unk18->unkC match key0, key1 and key2 (each skipped when -1) into out, returning the count. */
s32 func_8028D050_de(Container *arg0, s32 key0, s32 key1, s32 key2, RecordRecAtE4 **out, s32 max) {
    s32 i = arg0->unk13C;
    s32 end = arg0->unk140;
    RecordRecAtE4 *base = arg0->unk138;
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

void func_8028D108_de(Shared_World *arg0) {
    s8 color[4];
    s32 state;
    ColorEntry *entry;
    f32 alpha;
    s32 converted;

    state = arg0->frozen;
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
        entry = &D_800CD6E4_de[arg0->selectionState];
        if (entry->value != 0.0f) {
            color[0] = entry->red;
            color[1] = entry->green;
            color[2] = entry->blue;
            alpha = (arg0->selectionTimer * D_800CA3E0[1]) /
                    entry->value;
            if (!(D_800C52F8_de <= alpha)) {
                converted = (s32)alpha;
            } else {
                converted = (s32)(alpha - D_800C52F8_de);
                converted |= 0x80000000;
            }
            color[3] = converted;
            func_8029311C_de(&D_8011FAC0, color, 0, 0, D_800E28D0,
                          D_800E28D4);
        }
    }
}
