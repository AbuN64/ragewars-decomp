#include "include_asm.h"
#include "COMMON/ROUTE_CHASE_RECORDS.H"
#include "COMMON/TRIPLE.H"

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_80212E10_de(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x20\n"
        "sw         $ra, 0x1C($sp)\n"
        "sw         $s2, 0x18($sp)\n"
        "sw         $s1, 0x14($sp)\n"
        "sw         $s0, 0x10($sp)\n"
        "lw         $v0, 0x1D8($a0)\n"
        "lw         $s1, 0x1454($v0)\n"
        "lui        $s2, %hi(D_8013B364)\n"
        "addiu      $s2, $s2, %lo(D_8013B364)\n"
        "lw         $v1, 0x224($s1)\n"
        "addiu      $v0, $zero, -0x1\n"
        "bne        $v1, $v0, .Lauto_80212E84\n"
        "nop\n"
        "lui        $a0, %hi(g_world)\n"
        "addiu      $a0, $a0, %lo(g_world)\n"
        "lw         $v0, 0x7C($a0)\n"
        "lw         $v0, 0x0($v0)\n"
        "blez       $v0, .Lauto_80212E74\n"
        "addiu     $v0, $zero, -0x2\n"
        "sw         $zero, 0x224($s1)\n"
        "lw         $a1, 0x224($s1)\n"
        "jal        Engine_GetPlatformRoute\n"
        "sw        $zero, 0x228($s1)\n"
        "j          .Lauto_80212E80\n"
        "addiu     $v0, $zero, -0x1\n"
        ".Lauto_80212E74:\n"
        "sw         $v0, 0x224($s1)\n"
        "sw         $v1, 0x228($s1)\n"
        "addiu      $v0, $zero, -0x1\n"
        ".Lauto_80212E80:\n"
        "sw         $v0, 0xC($s1)\n"
        ".Lauto_80212E84:\n"
        "lw         $v1, 0x4($s1)\n"
        "lw         $v0, 0xC($s1)\n"
        "bne        $v1, $v0, .Lauto_80212F0C\n"
        "nop\n"
        "jal        Nav_GetControllerPosition\n"
        "addu      $a0, $s1, $zero\n"
        "addu       $a0, $s2, $zero\n"
        "lw         $a1, 0xC($s1)\n"
        "jal        Nav_GetGraphPoint\n"
        "addu      $s0, $v0, $zero\n"
        "addu       $a0, $s0, $zero\n"
        "jal        Particle_GetPointDistance\n"
        "addu      $a1, $v0, $zero\n"
        "lui        $at, %hi(D_800C23B0_eu_x)\n"
        "lwc1       $f1, %lo(D_800C23B0_eu_x)($at)\n"
        "c.lt.s     $f0, $f1\n"
        "nop\n"
        "bc1f       .Lauto_80212F0C\n"
        "nop\n"
        "lw         $a1, 0x224($s1)\n"
        "bltz       $a1, .Lauto_80212F08\n"
        "addiu     $v0, $zero, -0x1\n"
        "lui        $a0, %hi(g_world)\n"
        "addiu      $a0, $a0, %lo(g_world)\n"
        "jal        Engine_GetPlatformRoute\n"
        "nop\n"
        "lw         $v1, 0x228($s1)\n"
        "addiu      $v1, $v1, 0x1\n"
        "sw         $v1, 0x228($s1)\n"
        "lh         $v0, 0x2($v0)\n"
        "beql       $v1, $v0, .Lauto_80212F04\n"
        "sw        $zero, 0x228($s1)\n"
        ".Lauto_80212F04:\n"
        "addiu      $v0, $zero, -0x1\n"
        ".Lauto_80212F08:\n"
        "sw         $v0, 0xC($s1)\n"
        ".Lauto_80212F0C:\n"
        "lw         $v1, 0xC($s1)\n"
        "addiu      $v0, $zero, -0x1\n"
        "bne        $v1, $v0, .Lauto_80212F8C\n"
        "addiu     $v0, $zero, -0x2\n"
        "lw         $a1, 0x224($s1)\n"
        "bne        $a1, $v0, .Lauto_80212F68\n"
        "nop\n"
        "jal        Nav_NextRandom\n"
        "nop\n"
        "lw         $v1, 0x4($s2)\n"
        "div $zero,$v0,$v1\n"
        "bnez       $v1, .Lauto_80212F44\n"
        "nop\n"
        "break      7\n"
        ".Lauto_80212F44:\n"
        "addiu      $at, $zero, -0x1\n"
        "bne        $v1, $at, .Lauto_80212F5C\n"
        "lui       $at, (0x80000000 >> 16)\n"
        "bne        $v0, $at, .Lauto_80212F5C\n"
        "nop\n"
        "break      6\n"
        ".Lauto_80212F5C:\n"
        "mfhi       $v1\n"
        "j          .Lauto_80212F8C\n"
        "sw        $v1, 0xC($s1)\n"
        ".Lauto_80212F68:\n"
        "lw         $a2, 0x228($s1)\n"
        "lui        $a0, %hi(g_world)\n"
        "addiu      $a0, $a0, %lo(g_world)\n"
        "jal        Engine_GetPlatformRoutePoint\n"
        "nop\n"
        "addu       $a0, $s2, $zero\n"
        "jal        Nav_FindNearestPointIndex\n"
        "addu      $a1, $v0, $zero\n"
        "sw         $v0, 0xC($s1)\n"
        ".Lauto_80212F8C:\n"
        "jal        Nav_SteerAlongRoute\n"
        "addu      $a0, $s1, $zero\n"
        "jal        func_80211020_de\n"
        "addu      $a0, $s1, $zero\n"
        "jal        Nav_UpdatePlayerSteering\n"
        "addu      $a0, $s1, $zero\n"
        "lw         $ra, 0x1C($sp)\n"
        "lw         $s2, 0x18($sp)\n"
        "lw         $s1, 0x14($sp)\n"
        "lw         $s0, 0x10($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x20\n"
        ".set at\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_80212E10_de);
#endif
#endif

#if (defined(VERSION_DE)) && !defined(NON_MATCHING)
INCLUDE_ASM("span_1000", func_80212FBC_de);
#endif

#if !(defined(VERSION_DE)) || defined(NON_MATCHING)
/* Fuzzy draft: the other versions' body, not diffed against this version's asm. */
/* Runs a computer player's chase step toward the object at 0x68: without a target id at 0xBC it
   switches to mode 2 and without an object it only updates; farther than D_800C2380_eu from its goal
   node it heads there through Nav_SteerAlongRoute, otherwise it takes mode 8 once arrived or copies the
   object's position to 0x2C; then, within D_800C2384_eu of the object and not yet arrived, it marks
   arrival at 0x238 and plans a new route through func_8020B95C_de to pick the next goal node. */
#include "TYPES.H"
#include "COMMON/SHAREDPLAYER.H"













extern RouteChaseGraph D_8013B364;



extern void Nav_SetBehaviourState(RouteChaseBot *bot, s32 mode);
extern void func_80211020_de(RouteChaseBot *bot);
extern f32 Nav_DistanceToNode(RouteChaseBot *bot, s32 node);
extern void Nav_SteerAlongRoute(RouteChaseBot *bot);
extern void Nav_UpdateTargetSteering(RouteChaseBot *bot);
extern f32 Particle_GetPointDistance(CVector3 *a, CVector3 *b);
extern s32 func_8020B95C_de(RouteChaseGraph *graph, s32 from, s32 to, s32 *path, s32 flags);
extern void func_80209804_de(RouteChaseBot *bot);

void func_80212FBC_de(RouteChaseActor *actor)
{
    s32 path[64];
    RouteChaseBot *bot = actor->player->bot;
    RouteChaseGraph *graph = &D_8013B364;
    f32 dist;
    s32 i;
    s32 len;
    s32 start;
    s32 none;

    if (bot->targetId == -1) {
        Nav_SetBehaviourState(bot, 2);
        return;
    }
    if (bot->target == 0) {
        func_80211020_de(bot);
        return;
    }
    dist = Nav_DistanceToNode(bot, bot->goal);
    if (bot->node != bot->goal && D_800C2380_eu < dist) {
        Nav_SteerAlongRoute(bot);
    } else if (bot->arrived != 0) {
        Nav_SetBehaviourState(bot, 8);
    } else {
        bot->dest = bot->target->pos;
    }
    func_80211020_de(bot);
    if (bot->target != 0) {
        Nav_UpdateTargetSteering(bot);
        if (Particle_GetPointDistance(&bot->self->pos, &bot->target->pos) < D_800C2384_eu && bot->arrived == 0) {
            bot->arrived = 1;
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            func_8020B95C_de(graph, bot->goal, bot->goal, path, 0);
            start = path[0];
            none = -1;
            for (i = 63; i >= 0; i--) {
                path[i] = none;
            }
            len = func_8020B95C_de(graph, start, bot->goal, path, 0);
            func_80209804_de(bot);
            bot->goal = path[len - 1];
        }
    }
}
#endif
