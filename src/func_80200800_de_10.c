#include "common/types_06e4f7ef1f9e.h"
#include "common/types_8a8189af7b05.h"
#include "span_1000/code_802022E0.h"
#include "types.h"






























/* Picks a rider's nearest target: walks the player list D_80145060 for players within the segment's range at 0x54 (squared distance through func_802726BC_de) that are not the rider's own player, are active and, in team play (D_801468C4), are on the other team, keeps those with a clear line of sight between their raised centres through func_802444A4_de (or whose blocker is the player itself), and records the nearest in the rider at 0x80 and in the result with its distance through func_802B72B0_de, clearing both when none qualifies. */









extern SharedPlayer *D_80145060;
extern SharedPlayer **D_80103FCC;
extern char D_80103FD0[];

extern f32 func_802726BC_de(Vec3 *, Vec3 *);
extern void func_80271F68_de(Vec3 *, Vec3 *, Vec3 *);
extern f32 func_8024D284_de(SharedPlayer *);
extern s32 func_802444A4_de(SharedPlayer *, Vec3, Vec3, char *);
extern f32 func_802B72B0_de(f32);

void func_80203278_de(SharedPlayer *player, RiderRecAt130V1 *rider, Result *result) {
    f32 nearest;
    SharedPlayer *best;
    SegmentRecAt71 *segment;
    SharedPlayer *other;
    f32 distance;
    f32 lift;
    s32 enemy;
    s32 valid;
    s32 blocked;
    Vec3 from;
    Vec3 to;

    nearest = 0.0f;
    best = 0;
    segment = (SegmentRecAt71 *)(player->views18.view18_1.track + 0x14);
    other = D_80145060;
    if (other != 0) {
        lift = (0.5f);
        do {
            distance = func_802726BC_de(&player->views0.view8_3.pos, &other->views0.view8_3.pos);
            if (distance < segment->range * segment->range) {
                enemy = 0;
                if (player->views1C.view1D8_23.self != other && other->views5E4.view5E4_1.active != 0) {
                    enemy = 1;
                    if (D_801468C4 != 0) {
                        enemy = player->views1C.view1D8_23.self->views5D8.view5D8_1.record->team != other->views5D8.view5D8_1.record->team;
                    }
                }
                if (enemy) {
                    func_80271F68_de(&to, &other->views0.view8_3.pos, &player->views0.view8_3.pos);
                    from.x = rider->aim.x;
                    from.y = rider->aim.y;
                    from.z = rider->aim.z;
                    from = player->views0.view8_3.pos;
                    from.y += func_8024D284_de(player) * lift;
                    to = other->views0.view8_3.pos;
                    to.y += func_8024D284_de(other) * lift;
                    blocked = func_802444A4_de(player, from, to, D_80103FD0);
                    valid = 1;
                    if (blocked != 0) {
                        valid = *D_80103FCC == other;
                    }
                    if (valid && (best == 0 || distance < nearest)) {
                        best = other;
                        nearest = distance;
                    }
                }
            }
            other = other->views16E0.view16E0_1.next;
        } while (other != 0);
    }
    if (best != 0) {
        rider->target = best;
        result->distance = func_802B72B0_de(nearest);
        result->target = best;
    } else {
        result->target = 0;
        rider->target = 0;
    }
}
