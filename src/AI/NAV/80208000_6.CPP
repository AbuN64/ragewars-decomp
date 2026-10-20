#include "include_asm.h"
#include "COMMON/WORLD.H"
#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/VECTOR4F.H"
#include "COMMON/INTEGERSTATE2C.H"
#include "TYPES.H"
#include "COMMON/UNUSED.H"
#include "AI/NAV/80208000_6.H"
#include "COMMON/WORLD.H"

/** Returns the difference between the constant after D_800C6E20 and func_80209AE8_de's result, scaled by D_800C6E28. */

extern f32 func_80209AE8_de(void);

extern f32 D_800C1D34_de;

/* Find the nearest world object matching each active target ID, clearing its active flag when no object is close enough. */

f32 func_802726F8_de(void *arg0, void *arg1);

s32 func_8028B25C_de(void *arg0, s16 arg1);



f32 func_8020AA0C_de(void) {
    return (D_800C1D34_de - func_80209AE8_de()) * (D_800C6E28);
}

void func_8020AA40_de(Shared_Arg0 *arg0)
{
  f32 temp_f0;
  f32 var_f20;
  f32 var_f21;
  s32 *temp_a0;
  s32 var_s2;
  s32 var_s4;
  u32 var_v0;
  u32 compare_id;
  Shared_WeaponSlot *temp_s0;
  Shared_Target *temp_s1;
  Shared_Node *var_s5;
  Shared_WeaponSlot *var_s3;
  Shared_World *ww;
  var_s5 = arg0->unk24;
  ww = &D_8011FE88;
  if (var_s5 != 0)
  {
    var_f21 = D_800C1D40[0];
    do
    {
      temp_a0 = arg0->unk0;
      temp_s1 = (Shared_Target *) (&((SharedRecAt0V1 *) temp_a0)->unk0[(var_s5->unk0 * (*temp_a0)) + 8]);
      if (temp_s1->unkC & 1)
      {
        var_f20 = D_800C1D40[1];
        var_s3 = 0;
        if (temp_s1->unkE != 0x653)
        {
          var_s4 = 0;
          if (var_s4 < ww->actorCount)
          {
            var_s2 = 0;
            do
            {
              temp_s0 = (Shared_WeaponSlot *) (&((SharedRecAt0V1 *) ww->actors)->unk0[var_s2]);
              compare_id = temp_s1->unkE;
              if (compare_id == 0x64E)
              {
                var_v0 = temp_s0->unkE4;
                goto compare;
              }
              if (((u32) (temp_s0->unkE4 - 0x643)) >= 2U)
              {
                goto advance;
              }
              var_v0 = func_8028B25C_de(ww, temp_s0->unk18->unk28);
              compare_id = temp_s1->unkE;
              compare:
              if (var_v0 == compare_id)
              {
                temp_f0 = func_802726F8_de(temp_s1, &temp_s0->unk8);
                if ((temp_f0 < var_f20) || (var_f20 == var_f21))
                {
                  if (temp_s1)
                  {
                    var_f20 = temp_f0;
                    var_s3 = temp_s0;
                  }
                  else
                  {
                    var_f20 = temp_f0;
                    var_s3 = temp_s0;
                  }
                }
              }

              advance:
              var_s2 += 0x2E8;

            }
            while ((++var_s4) < ww->actorCount);
          }
          if (var_s3 != 0)
          {
            if (var_f20 < D_800C1D40[2])
            {
              var_s5->unk34 = var_s3;
              goto next_node;
            }
          }
          var_s5->unk34 = 0;
          temp_s1->unkC = (u16) (temp_s1->unkC & 0xFFFE);
        }
      }
      next_node:
      var_s5 = var_s5->unk10;

    }
    while (var_s5 != 0);
  }
}

#ifdef NON_MATCHING
#include "COMMON/LISTHEADER.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/WORLD.H"

extern s32 D_8011BF08;
extern f32 D_800C1D4C_de, D_800C1D50_de;
extern PlatformRoute *func_8028D218_de(void *, s32);
extern CVector3 *func_8028D244_de(void *, s32, s32);
extern f32 func_802726F8_de(void *, void *);

void func_8020ABF0_de(NavigationGraph *graph) {
    NavigationPlatform *platforms[30];
    CVector3 chosenPosition, start, end;
    NavigationSearchNode *node;
    NavigationPoint *point;
    NavigationPlatform *actor, *chosen;
    ActorMotionState *motion;
    ActorMotionDefinition *definition;
    PlatformRoute *route;
    CVector3 *position;
    f32 distance, best, sentinel;
    s32 count, i, j;

    {
        s32 clear;
        for (clear = 29; clear >= 0; clear--) platforms[clear] = 0;
    }
    count = 0;
    {
        s32 gather = 0;
        NavigationPlatform **out;
        if (D_8011BF08 > 0) {
            out = platforms;
            do {
                NavigationPlatform *entry = &D_8011BF00[gather];
                if (entry->objectId == 0x642) {
                    *out = entry;
                    out++;
                    count++;
                }
                gather++;
            } while (gather < D_8011BF08);
        }
    }
    node = graph->nodes;
    if (node != 0) {
        sentinel = D_800C1D4C_de;
        do {
            point = navigationRecord(graph->points, node->key);
            chosen = 0;
            if (point->flags & 0x200) {
                best = D_800C1D50_de;
                i = 0;
                if (count > 0) {
                do {
                    actor = platforms[i];
                    motion = &actor->motion;
                    definition = &actor->resource->motion;
                    if (motion->mode == 4) {
                        route = func_8028D218_de(&D_8011FE88, motion->route);
                        if (route != 0) {
                            for (j = 0; j < route->count; j++) {
                                position = func_8028D244_de(&D_8011FE88, motion->route, j);
                                distance = func_802726F8_de(point, position);
                                if (distance < best || best == sentinel) {
                                    chosen = platforms[i];
                                    best = distance;
                                    chosenPosition = *position;
                                }
                            }
                        }
                    } else {
                        start = motion->base;
                        end = motion->base;
                        end.y += definition->height;
                        if (definition->radial != 0) {
                            end.x += definition->radius * func_802B7130_de(definition->heading);
                            end.z += definition->radius * func_802B6560_de(definition->heading);
                        }
                        distance = func_802726F8_de(point, &start);
                        if (distance < best || best == sentinel) {
                            chosen = platforms[i];
                            best = distance;
                            chosenPosition = start;
                        }
                        distance = func_802726F8_de(point, &end);
                        if (distance < best || best == sentinel) {
                            chosen = platforms[i];
                            best = distance;
                            chosenPosition = end;
                        }
                    }
                    i++;
                } while (i < count);
                }
                if (chosen != 0) {
                    node->platform = chosen;
                    node->endpoint = chosenPosition;
                } else {
                    node->platform = 0;
                    point->flags &= 0xFDFF;
                }
            }
            node = node->next;
        } while (node != 0);
    }
}
#else
INCLUDE_ASM("span_1000", func_8020ABF0_de);
#endif

#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
typedef struct NavigationCollisionQuery { s32 flags, word4, word8, wordC, word10, word14, word18; } NavigationCollisionQuery;
extern NavigationCollisionQuery D_80103FF0, D_80104050, D_80104070, D_801040D0;
s32 func_8024E62C_de(Player *);
s32 func_8024DEE0_de(Player *);
s32 func_8024DF5C_de(Player *);
s32 func_8024DFA0_de(Player *);
s32 func_80243A90_de(Player *, CVector3, NavigationCollisionQuery *);
void func_80271F68_de(CVector3 *, void *, CVector3 *);

/* Collisions the actor would meet moving to a point (61.44 above it), without committing the move: the actor's 0x50-byte header is saved and
 * restored around the trial move. */
static __inline__ s32 navigationBlocked(Player *actor, NavigationGraph *graph, s32 index) {
    CVector3 position;
    NavigationCollisionQuery query;
    u8 saved[0x50];
    s32 mode, result;
    position = ((NavigationPoint *)navigationRecord(graph->points, index))->position;
    position.y += 61.44f;
    if (actor->kind == 1 && (actor->weaponFlags & 0x300000)) {
        query = D_801040D0;
    } else {
        mode = func_8024DEE0_de(actor);
        if (func_8024DF5C_de(actor) == 0) {
            if (mode != 0) query = D_80104050;
            else query = D_801040D0;
        } else if (func_8024DFA0_de(actor) == 0) query = D_80104070;
        else query = D_80103FF0;
    }
    query.flags = 0x4000;
    __builtin_memcpy(saved, actor, sizeof(saved));
    result = func_80243A90_de(actor, position, &query);
    __builtin_memcpy(actor, saved, sizeof(saved));
    return result;
}
/* Collects the points one portal away from a point, with the portal joining each; returns how many. */
static __inline__ s32 navigationNeighbours(NavigationGraph *graph, s32 current, s32 *targets, s32 *portals) {
    NavigationPortal *portal;
    s32 count = 0;
    s32 i;
    for (i = 0; i < graph->portalCount; i++) {
        portal = navigationRecord(graph->portals, i);
        if (portal->first == current) {
            targets[count] = portal->second;
            portals[count] = i;
            count++;
        }
        if (portal->second == current) {
            targets[count] = portal->first;
            portals[count] = i;
            count++;
        }
    }
    return count;
}
/* Picks the controller's next point: follows a queued point when the actor may take it, otherwise the nearest reachable neighbour
 * (special portals and drops first while within the starting height). */
void func_8020AF9C_de(NavigationGraph *graph, Player *actor) {
    s32 targets[64];
    s32 portalIds[64];
    CVector3 delta;
    NavigationPoint *point;
    NavigationPortal *portal;
    s32 climbing, swimming;
    s32 best, target;
    s32 count, found;
    s32 busy, hanging, release;
    s32 i;
    f32 dist, bestDist, height, dy;

    for (i = 0; i < 64; i++) {
        targets[i] = -1;
        portalIds[i] = -1;
    }
    found = 0;
    climbing = actor->movementFlags & 0x2000;
    swimming = actor->movementFlags & 0x1000;
    func_80271F68_de(&delta, navigationRecord(graph->points, actor->controller->current), &actor->pos);
    if (climbing || swimming) {
        dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
    } else {
        dist = delta.x * delta.x + delta.z * delta.z;
    }
    height = delta.y;
    bestDist = dist;
    if (height < 0.0f) {
        height = -height;
    }
    best = actor->controller->current;
    if (actor->computer != 0 && actor->controller->queue[0] != -1) {
        busy = func_8024E62C_de(actor);
        hanging = actor->pose == 15;
        release = busy && !actor->active;
        if (busy || hanging || climbing) {
            if (!release) {
                target = actor->controller->queue[0];
                if (target == -1) {
                    target = actor->controller->mode;
                }
                point = navigationRecord(graph->points, target);
                func_80271F68_de(&delta, &point->position, &actor->pos);
                if (climbing || swimming || (point->flags & 0x200)) {
                    dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
                } else {
                    dist = delta.x * delta.x + delta.z * delta.z;
                }
                if (dist < bestDist) {
                    /* within five steps (5 x 61.44) up or down */
                    if (delta.y < 0.0f ? -delta.y < 5 * 61.44f : delta.y < 5 * 61.44f) {
                        actor->controller->previous = actor->controller->current;
                        actor->controller->current = target;
                    }
                }
                return;
            }
            actor->controller->queue[0] = -1;
        }
    }
    count = navigationNeighbours(graph, actor->controller->current, targets, portalIds);
    for (i = 0; i < count; i++) {
        target = targets[i];
        point = navigationRecord(graph->points, target);
        portal = navigationRecord(graph->portals, portalIds[i]);
        if (!(navigation_attributes(point) & 0x300000) || swimming || climbing) {
            func_80271F68_de(&delta, &point->position, &actor->pos);
            if (climbing || swimming) {
                dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            } else {
                dist = delta.x * delta.x + delta.z * delta.z;
            }
            dy = delta.y;
            if (dy < 0.0f) {
                dy = -dy;
            }
            if (portal->kind == 3 || portal->kind == 10 || portal->kind == 5 || (!swimming && (point->flags & 0x20))) {
                if (dy < height) {
                    if (!found) {
                        bestDist = -1.0f;
                        found = 1;
                    }
                    if (dist < bestDist || bestDist == -1.0f) {
                        if (!navigationBlocked(actor, graph, target)) {
                            bestDist = dist;
                            best = target;
                        }
                    }
                }
            } else if (dist < bestDist) {
                if (!navigationBlocked(actor, graph, target)) {
                    bestDist = dist;
                    best = target;
                }
            }
        }
    }
    if (actor->controller->current != best) {
        actor->controller->previous = actor->controller->current;
    }
    actor->controller->current = best;
}
