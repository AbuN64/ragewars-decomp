#include "COMMON/NAVIGATION_GRAPH.H"
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

extern f32 func_80209AE8_de(AiController *controller);

extern f32 D_800C1D34_de;

/* Find the nearest world object matching each active target ID, clearing its active flag when no object is close enough. */

f32 Particle_GetPointDistance(void *arg0, void *arg1);

s32 func_8028B25C_de(void *arg0, s16 arg1);



/* Preserve the owning controller passed in a0 by the original MIPS. */
f32 Nav_GetEngagementDistance(AiController *controller) {
    return (D_800C1D34_de - func_80209AE8_de(controller)) * D_800C6E28;
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
  NavigationPoint *temp_s1;
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
      temp_s1 = (NavigationPoint *) (&((SharedRecAt0V1 *) temp_a0)->unk0[(var_s5->unk0 * (*temp_a0)) + 8]);
      if (navigation_point_flags(temp_s1) & 1)
      {
        var_f20 = D_800C1D40[1];
        var_s3 = 0;
        if (navigation_point_object_id(temp_s1) != 0x653)
        {
          var_s4 = 0;
          if (var_s4 < ww->actorCount)
          {
            var_s2 = 0;
            do
            {
              temp_s0 = (Shared_WeaponSlot *) (&((SharedRecAt0V1 *) ww->actors)->unk0[var_s2]);
              compare_id = navigation_point_object_id(temp_s1);
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
              compare_id = navigation_point_object_id(temp_s1);
              compare:
              if (var_v0 == compare_id)
              {
                temp_f0 = Particle_GetPointDistance(temp_s1, &temp_s0->unk8);
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
          navigation_point_clear_flags(temp_s1, 1);
        }
      }
      next_node:
      var_s5 = var_s5->unk10;

    }
    while (var_s5 != 0);
  }
}

#include "COMMON/LISTHEADER.H"
#include "COMMON/OBJECTLINKS14.H"
#include "COMMON/WORLD.H"
extern PlatformRoute *Engine_GetPlatformRoute(void *, s32);
extern CVector3 *Engine_GetPlatformRoutePoint(void *, s32, s32);
extern f32 Particle_GetPointDistance(void *, void *);
/* Give every platform-flagged (0x200) search node the nearest moving platform (object 0x642) and the
 * nearest point on it: a route platform (mode 4) offers each of its route points, any other platform
 * its base and its top (base + height, pushed out by radius along heading when radial). A node with
 * no platform loses its 0x200 flag. */
void Nav_AssignPlatformEndpoints(CNavData *graph) {
    NavigationPlatform *platforms[30];
    CVector3 chosenPosition, start, end;
    NavigationSearchNode *node;
    NavigationPoint *point;
    NavigationPlatform **slot;
    NavigationPlatform *candidate, *actor, *chosen;
    ActorMotionState *motion;
    ActorMotionDefinition *definition;
    PlatformRoute *route;
    CVector3 *position;
    f32 distance, best;
    s32 count, i, j, k, n;

    for (k = 29; k >= 0; k--) {
        platforms[k] = 0;
    }
    count = 0;
    for (n = 0; n < D_8011BF08; n++) {
        candidate = &D_8011BF00[n];
        if (candidate->objectId == 0x642) {
            slot = &platforms[count];
            *slot = candidate;
            count++;
        }
    }
    for (node = graph->nodes; node != 0; node = node->next) {
        point = navigationRecord(graph->points, node->key);
        if (navigation_point_flags(point) & 0x200) {
            chosen = 0;
            best = -1.0f;
            for (i = 0; i < count; i++) {
                actor = platforms[i];
                motion = &actor->motion;
                definition = &actor->resource->motion;
                if (motion->mode == 4) {
                    route = Engine_GetPlatformRoute(&D_8011FE88, motion->route);
                    if (route != 0) {
                        for (j = 0; j < route->count; j++) {
                            position = Engine_GetPlatformRoutePoint(&D_8011FE88, motion->route, j);
                            distance = Particle_GetPointDistance(point, position);
                            if (distance < best || best == -1.0f) {
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
                        end.x += definition->radius * Math_Sinf(definition->heading);
                        end.z += definition->radius * Math_Cosf(definition->heading);
                    }
                    distance = Particle_GetPointDistance(point, &start);
                    if (distance < best || best == -1.0f) {
                        chosen = platforms[i];
                        best = distance;
                        chosenPosition = start;
                    }
                    distance = Particle_GetPointDistance(point, &end);
                    if (distance < best || best == -1.0f) {
                        chosen = platforms[i];
                        best = distance;
                        chosenPosition = end;
                    }
                }
            }
            if (chosen != 0) {
                node->platform = chosen;
                node->endpoint = chosenPosition;
            } else {
                node->platform = 0;
                navigation_point_clear_flags(point, 0x200);
            }
        }
    }
}

#include "COMMON/SHAREDCALLBACK5.H"
#include "COMMON/OBJECTLINKS14.H"
typedef struct NavigationCollisionQuery { s32 flags, word4, word8, wordC, word10, word14, word18; } NavigationCollisionQuery;
extern NavigationCollisionQuery D_80103FF0, D_80104050, D_80104070, D_801040D0;
s32 func_8024E62C_de(Player *);
s32 func_8024DEE0_de(Player *);
s32 func_8024DF5C_de(Player *);
s32 func_8024DFA0_de(Player *);
s32 func_80243A90_de(Player *, CVector3, NavigationCollisionQuery *);
void Particle_SubtractVectors(CVector3 *, void *, CVector3 *);

/* Collisions the actor would meet moving to a point (61.44 above it), without committing the move: the actor's 0x50-byte header is saved and
 * restored around the trial move. */
static __inline__ s32 navigationBlocked(Player *actor, CNavData *graph, s32 index) {
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
static __inline__ s32 navigationNeighbours(CNavData *graph, s32 current, s32 *targets, s32 *portals) {
    NavigationPortal *portal;
    s32 count = 0;
    s32 i;
    for (i = 0; i < graph->m_nNavLinks; i++) {
        portal = navigationRecord(graph->m_pusNavLinks, i);
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
void func_8020AF9C_de(CNavData *graph, Player *actor) {
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
    Particle_SubtractVectors(&delta, navigationRecord(graph->points, actor->controller->current), &actor->pos);
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
                Particle_SubtractVectors(&delta, &point->position, &actor->pos);
                if (climbing || swimming || (navigation_point_flags(point) & 0x200)) {
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
        portal = navigationRecord(graph->m_pusNavLinks, portalIds[i]);
        if (!(navigation_attributes(point) & 0x300000) || swimming || climbing) {
            Particle_SubtractVectors(&delta, &point->position, &actor->pos);
            if (climbing || swimming) {
                dist = delta.x * delta.x + delta.y * delta.y + delta.z * delta.z;
            } else {
                dist = delta.x * delta.x + delta.z * delta.z;
            }
            dy = delta.y;
            if (dy < 0.0f) {
                dy = -dy;
            }
            if (portal->kind == 3 || portal->kind == 10 || portal->kind == 5 || (!swimming && (navigation_point_flags(point) & 0x20))) {
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
