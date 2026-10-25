#include "include_asm.h"
#include "COMMON/LONE/D_800CD8D0.H"
#include "COMMON/WORLD.H"
#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/PROPGEOMETRY.H"
#include "COMMON/MANAGER.H"
#include "COMMON/MTX.H"
#include "TYPES.H"
#include "COMMON.H"
extern s32 D_800D2978;

#if defined(VERSION_DE)
#ifdef NON_MATCHING
/* Fuzzy draft: inline-asm carrier of the original instructions (no C written yet). */
void func_8024F960_eu(void) {
    __asm__ volatile (
        ".set noreorder\n"
        ".set noat\n"
        "addiu      $sp, $sp, -0x88\n"
        "sw         $s1, 0x64($sp)\n"
        "addu       $s1, $a0, $zero\n"
        "sw         $s2, 0x68($sp)\n"
        "addu       $s2, $a1, $zero\n"
        "sw         $s0, 0x60($sp)\n"
        "addu       $s0, $a2, $zero\n"
        "sw         $s3, 0x6C($sp)\n"
        "sdc1       $f21, 0x80($sp)\n"
        "lwc1       $f21, 0x98($sp)\n"
        "sw         $ra, 0x70($sp)\n"
        "sdc1       $f20, 0x78($sp)\n"
        "jal        func_8024DD10_de\n"
        "addu      $s3, $a3, $zero\n"
        "sb         $zero, 0x0($s1)\n"
        "lhu        $v1, 0x8($s2)\n"
        "addiu      $v0, $zero, -0x1\n"
        "sw         $s0, 0x1C($s1)\n"
        "sw         $v0, 0xA8($s1)\n"
        "sw         $zero, 0xAC($s1)\n"
        "sw         $zero, 0xB0($s1)\n"
        "sw         $zero, 0xB4($s1)\n"
        "sh         $v1, 0x4($s1)\n"
        "lhu        $a1, 0xE($s2)\n"
        "lui        $a0, %hi(D_8011FE88)\n"
        "addiu      $a0, $a0, %lo(D_8011FE88)\n"
        "jal        Engine_GetActorDefinition\n"
        "nop\n"
        "sw         $v0, 0x18($s1)\n"
        "addu       $a0, $v0, $zero\n"
        "addiu      $v0, $zero, 0x10\n"
        "sb         $v0, 0xE0($s1)\n"
        "sw         $zero, 0xDC($s1)\n"
        "lwc1       $f0, 0x8($a0)\n"
        "mul.s      $f0, $f0, $f0\n"
        "lui        $at, %hi(D_auto_rodata_func_8024F950_de_800C3E10)\n"
        "lwc1       $f1, %lo(D_auto_rodata_func_8024F950_de_800C3E10)($at)\n"
        "mtc1       $zero, $f20\n"
        "c.le.s     $f1, $f0\n"
        "nop\n"
        "bc1tl      .Lauto_8024FA08\n"
        "sub.s     $f0, $f0, $f1\n"
        "trunc.w.s  $f4, $f0\n"
        "mfc1       $v1, $f4\n"
        "j          .Lauto_8024FA1C\n"
        "sw        $v1, 0x24($a0)\n"
        ".Lauto_8024FA08:\n"
        "lui        $v0, (0x80000000 >> 16)\n"
        "trunc.w.s  $f4, $f0\n"
        "mfc1       $v1, $f4\n"
        "or         $v1, $v1, $v0\n"
        "sw         $v1, 0x24($a0)\n"
        ".Lauto_8024FA1C:\n"
        "lbu        $v0, 0x19($s2)\n"
        "mtc1       $v0, $f0\n"
        "cvt.s.w    $f0, $f0\n"
        "mul.s      $f0, $f0, $f21\n"
        "swc1       $f0, 0x50($sp)\n"
        "lbu        $v0, 0x18($s2)\n"
        "andi       $v0, $v0, 0x10\n"
        "beqz       $v0, .Lauto_8024FA48\n"
        "nop\n"
        "neg.s      $f0, $f0\n"
        "swc1       $f0, 0x50($sp)\n"
        ".Lauto_8024FA48:\n"
        "lbu        $v0, 0x1A($s2)\n"
        "mtc1       $v0, $f0\n"
        "cvt.s.w    $f0, $f0\n"
        "mul.s      $f0, $f0, $f21\n"
        "swc1       $f0, 0x58($sp)\n"
        "lbu        $v0, 0x18($s2)\n"
        "andi       $v0, $v0, 0x20\n"
        "beqz       $v0, .Lauto_8024FA74\n"
        "nop\n"
        "neg.s      $f0, $f0\n"
        "swc1       $f0, 0x58($sp)\n"
        ".Lauto_8024FA74:\n"
        "lh         $v0, 0x10($s2)\n"
        "lui        $at, %hi(D_auto_rodata_func_8024F950_de_800C3E10 + 0x4)\n"
        "lwc1       $f1, %lo(D_auto_rodata_func_8024F950_de_800C3E10 + 0x4)($at)\n"
        "mtc1       $v0, $f0\n"
        "cvt.s.w    $f0, $f0\n"
        "mul.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0x54($sp)\n"
        "lbu        $v0, 0x18($s2)\n"
        "andi       $v1, $v0, 0x3\n"
        "addiu      $v0, $zero, 0x1\n"
        "beq        $v1, $v0, .Lauto_8024FAE0\n"
        "slti      $v0, $v1, 0x2\n"
        "beqz       $v0, .Lauto_8024FABC\n"
        "addiu     $v0, $zero, 0x2\n"
        "beqz       $v1, .Lauto_8024FAD4\n"
        "nop\n"
        "j          .Lauto_8024FB08\n"
        "nop\n"
        ".Lauto_8024FABC:\n"
        "beq        $v1, $v0, .Lauto_8024FAF0\n"
        "addiu     $v0, $zero, 0x3\n"
        "beq        $v1, $v0, .Lauto_8024FB00\n"
        "nop\n"
        "j          .Lauto_8024FB08\n"
        "nop\n"
        ".Lauto_8024FAD4:\n"
        "mtc1       $zero, $f20\n"
        "j          .Lauto_8024FB08\n"
        "nop\n"
        ".Lauto_8024FAE0:\n"
        "lui        $at, %hi(D_auto_800C3E18)\n"
        "lwc1       $f20, %lo(D_auto_800C3E18)($at)\n"
        "j          .Lauto_8024FB08\n"
        "nop\n"
        ".Lauto_8024FAF0:\n"
        "lui        $at, %hi(D_auto_800C3E1C)\n"
        "lwc1       $f20, %lo(D_auto_800C3E1C)($at)\n"
        "j          .Lauto_8024FB08\n"
        "nop\n"
        ".Lauto_8024FB00:\n"
        "lui        $at, %hi(D_auto_800C3E20)\n"
        "lwc1       $f20, %lo(D_auto_800C3E20)($at)\n"
        ".Lauto_8024FB08:\n"
        "mfc1       $a1, $f20\n"
        "lhu        $v0, 0xC($s2)\n"
        "addiu      $a0, $sp, 0x10\n"
        "jal        func_802736D4_de\n"
        "sh        $v0, 0xD8($s1)\n"
        "lw         $a1, 0x4($s2)\n"
        "addiu      $a0, $sp, 0x10\n"
        "addu       $a2, $a1, $zero\n"
        "jal        func_8027347C_de\n"
        "addu      $a3, $a1, $zero\n"
        "lw         $a1, 0x50($sp)\n"
        "lw         $a2, 0x54($sp)\n"
        "lw         $a3, 0x58($sp)\n"
        "jal        func_80273448_de\n"
        "addiu     $a0, $sp, 0x10\n"
        "jal        func_80273D6C_de\n"
        "addiu     $a0, $sp, 0x10\n"
        "lhu        $v0, 0xD8($s1)\n"
        "andi       $v0, $v0, 0x40\n"
        "beqz       $v0, .Lauto_8024FBBC\n"
        "nop\n"
        "lwc1       $f0, 0x50($sp)\n"
        "lui        $at, %hi(D_auto_800C3E20 + 0x4)\n"
        "lwc1       $f1, %lo(D_auto_800C3E20 + 0x4)($at)\n"
        "sub.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xB8($s1)\n"
        "lwc1       $f0, 0x54($sp)\n"
        "sub.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xBC($s1)\n"
        "lwc1       $f0, 0x58($sp)\n"
        "sub.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xC0($s1)\n"
        "lwc1       $f0, 0x50($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xC4($s1)\n"
        "lwc1       $f0, 0x54($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xC8($s1)\n"
        "lwc1       $f0, 0x58($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "swc1       $f0, 0xCC($s1)\n"
        "lui        $v0, %hi(D_800CD8D0)\n"
        "lw         $v0, %lo(D_800CD8D0)($v0)\n"
        "j          .Lauto_8024FC94\n"
        "sw        $v0, 0xD4($s1)\n"
        ".Lauto_8024FBBC:\n"
        "lb         $v0, 0x12($s2)\n"
        "lui        $at, %hi(D_auto_800C3E28)\n"
        "lwc1       $f3, %lo(D_auto_800C3E28)($at)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x50($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "lui        $at, %hi(D_auto_800C3E28 + 0x4)\n"
        "lwc1       $f2, %lo(D_auto_800C3E28 + 0x4)($at)\n"
        "sub.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xB8($s1)\n"
        "lb         $v0, 0x14($s2)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x54($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "sub.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xBC($s1)\n"
        "lb         $v0, 0x16($s2)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x58($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "sub.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xC0($s1)\n"
        "lb         $v0, 0x13($s2)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x50($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "add.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xC4($s1)\n"
        "lb         $v0, 0x15($s2)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x54($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "add.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xC8($s1)\n"
        "lb         $v0, 0x17($s2)\n"
        "mtc1       $v0, $f1\n"
        "cvt.s.w    $f1, $f1\n"
        "mul.s      $f1, $f1, $f3\n"
        "lwc1       $f0, 0x58($sp)\n"
        "add.s      $f0, $f0, $f1\n"
        "add.s      $f0, $f0, $f2\n"
        "swc1       $f0, 0xCC($s1)\n"
        "lw         $v0, 0x0($s2)\n"
        "sw         $v0, 0xD4($s1)\n"
        ".Lauto_8024FC94:\n"
        "addiu      $a0, $s1, 0x68\n"
        "jal        func_8027302C\n"
        "addiu     $a1, $sp, 0x10\n"
        "addiu      $a0, $sp, 0x10\n"
        "jal        func_8027027C_de\n"
        "addiu     $a1, $s1, 0x28\n"
        "lw         $t0, 0x50($sp)\n"
        "lw         $t1, 0x54($sp)\n"
        "lw         $t2, 0x58($sp)\n"
        "sw         $t0, 0x8($s1)\n"
        "sw         $t1, 0xC($s1)\n"
        "sw         $t2, 0x10($s1)\n"
        "lhu        $v1, 0xA($s2)\n"
        "ori        $v0, $zero, 0xFFFF\n"
        "bne        $v1, $v0, .Lauto_8024FCDC\n"
        "nop\n"
        "j          .Lauto_8024FCEC\n"
        "sw        $zero, 0x14($s1)\n"
        ".Lauto_8024FCDC:\n"
        "lhu        $v0, 0xA($s2)\n"
        "sll        $v0, $v0, 5\n"
        "addu       $v0, $s3, $v0\n"
        "sw         $v0, 0x14($s1)\n"
        ".Lauto_8024FCEC:\n"
        "lui        $v1, (0x3FFFFF >> 16)\n"
        "lui        $v0, %hi(D_800D0910)\n"
        "lw         $v0, %lo(D_800D0910)($v0)\n"
        "ori        $v1, $v1, (0x3FFFFF & 0xFFFF)\n"
        "addiu      $v0, $v0, 0x1\n"
        "lui        $at, %hi(D_800D0910)\n"
        "sw         $v0, %lo(D_800D0910)($at)\n"
        "bne        $v0, $v1, .Lauto_8024FD1C\n"
        "addu      $a0, $s1, $zero\n"
        "lui        $v0, (0x380000 >> 16)\n"
        "lui        $at, %hi(D_800D0910)\n"
        "sw         $v0, %lo(D_800D0910)($at)\n"
        ".Lauto_8024FD1C:\n"
        "lui        $v0, %hi(D_800D0910)\n"
        "lw         $v0, %lo(D_800D0910)($v0)\n"
        "lui        $v1, %hi(D_800D297B)\n"
        "lbu        $v1, %lo(D_800D297B)($v1)\n"
        "sll        $v0, $v0, 10\n"
        "addiu      $v1, $v1, -0x1\n"
        "sw         $v0, 0xD0($s1)\n"
        "jal        func_8024E924_de\n"
        "sb        $v1, 0xDA($s1)\n"
        "addiu      $v0, $v0, -0x9\n"
        "sltiu      $v0, $v0, 0x2\n"
        "beqz       $v0, .Lauto_8024FD5C\n"
        "nop\n"
        "lhu        $v0, 0xD8($s1)\n"
        "ori        $v0, $v0, 0x50\n"
        "sh         $v0, 0xD8($s1)\n"
        ".Lauto_8024FD5C:\n"
        "lw         $ra, 0x70($sp)\n"
        "lw         $s3, 0x6C($sp)\n"
        "lw         $s2, 0x68($sp)\n"
        "lw         $s1, 0x64($sp)\n"
        "lw         $s0, 0x60($sp)\n"
        "ldc1       $f21, 0x80($sp)\n"
        "ldc1       $f20, 0x78($sp)\n"
        "jr         $ra\n"
        "addiu     $sp, $sp, 0x88\n"
    );
}
#else
INCLUDE_ASM("span_1000", func_8024F960_eu);
#endif
#endif

#if defined(VERSION_DE)
/* Initialises a placed prop from its record: resets its state and owner, loads its model and caches the squared model radius, builds its rotation from the record's packed quaternion, scale and position into a matrix copied into the object, sets its bounding box either as a fixed cube for flag 0x40 or from the record's six extents through func_802B2350 with a half-unit margin, copies the position, links its path segment and takes the next colour key and colour frame. The fixed cube is written through do-while(0) vector macros, which the stores' order needs, and 102.4 is the cartridge's rounded 0x42CCCCCC. */
#if defined(VERSION_DE)
extern s32 func_8024E924_de(PlacedProp *);
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
#endif

extern void func_8024DD10_de(PlacedProp *, PlacedPropRecord *, s32, char *);
extern PropGeometry *Engine_GetActorDefinition(void *, s32);
extern void MatrixFromQuaternion(f32 *, char *);
extern void func_8027347C_de(char *, f32, f32, f32);
extern void func_80273448_de(char *, f32, f32, f32);
extern void func_80273D6C_de(char *);
extern void func_8027302C(char *, char *);
extern void func_8027027C_de(char *, char *);
static inline s32 func_80250BF0_de(void) {
    s32 next;
    next = D_800D0910 + 1;
    D_800D0910 = next;
    if (next == 0x3FFFFF) {
        D_800D0910 = 0x380000;
    }
    return D_800D0910;
}
void World_InitPlacedProp(PlacedProp *prop, PlacedPropRecord *record, s32 owner, char *segments) {
    f32 rotation[4];
    char matrix[0x40];
    PropGeometry *model;
    func_8024DD10_de(prop, record, owner, segments);
    prop->state = 0;
    prop->id = record->id;
    prop->owner = owner;
    prop->fieldA8 = -1;
    prop->fieldAC = 0;
    prop->fieldB0 = 0;
    prop->fieldB4 = 0;
    prop->model = Engine_GetActorDefinition(&D_8011FE88, record->model);
    prop->fade = 16;
    prop->fieldDC = 0;
    model = prop->model;
    model->radiusSquared = model->radius * model->radius;
    prop->flags = record->flags;
    rotation[0] = record->rotation[0] * 0.007874016f;
    rotation[1] = record->rotation[1] * 0.007874016f;
    rotation[2] = record->rotation[2] * 0.007874016f;
    rotation[3] = record->rotation[3] * 0.007874016f;
    func_802741A4_de(rotation);
    MatrixFromQuaternion(rotation, matrix);
    func_8027347C_de(matrix, record->scale.x, record->scale.y, record->scale.z);
    func_80273448_de(matrix, record->position.x, record->position.y, record->position.z);
    func_80273D6C_de(matrix);
    if (prop->flags & 0x40) {
        do { (prop->min).x = (record->position).x - (102.399994f); (prop->min).y = (record->position).y - (102.399994f); (prop->min).z = (record->position).z - (102.399994f); } while (0);
        do { (prop->max).x = (record->position).x + (102.399994f); (prop->max).y = (record->position).y + (102.399994f); (prop->max).z = (record->position).z + (102.399994f); } while (0);
        prop->fieldD4 = D_800CD8D0;
    } else {
        prop->min.x = func_802B2350(record->extents[0]) + record->position.x - 0.5f;
        prop->min.y = func_802B2350(record->extents[1]) + record->position.y - 0.5f;
        prop->min.z = func_802B2350(record->extents[2]) + record->position.z - 0.5f;
        prop->max.x = func_802B2350(record->extents[3]) + record->position.x + 0.5f;
        prop->max.y = func_802B2350(record->extents[4]) + record->position.y + 0.5f;
        prop->max.z = func_802B2350(record->extents[5]) + record->position.z + 0.5f;
        prop->fieldD4 = record->value;
    }
    func_8027302C(prop->matrix, matrix);
    func_8027027C_de(matrix, prop->transform);
    prop->position = record->position;
    if (record->segment == 0xFFFF) {
        prop->segment = 0;
    } else {
        prop->segment = segments + record->segment * 32;
    }
    prop->key = func_80250BF0_de() << 10;
    prop->colorFrame = (u8)D_800D2978 - 1;
#if defined(VERSION_DE)
    if ((u32)(func_8024E924_de(prop) - 9) < 2) {
        prop->flags |= 0x50;
    }
#elif defined(VERSION_EU) || defined(VERSION_EU_X) || defined(VERSION_US) || defined(VERSION_US_REV1)
#endif
}
#endif
