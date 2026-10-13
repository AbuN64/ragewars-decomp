#include "span_1000/code_8028FC98.h"
#include "span_1000/code_8021CD70.h"
extern char D_801003F8;
extern char D_80100438;
extern char D_8011B388;
extern f32 D_800C53A0_de[];
extern f32 D_800D2988;
extern void func_8024F4A0_de(Actor_func_80290238_de *);
extern void func_80243A90_de(Actor_func_80290238_de *, f32, f32, f32, void *);

void func_80290424_de(Actor_func_80290238_de *arg0)
{
  void *var_s1;
  f32 temp_f1;
  f32 radius;
  f32 x;
  Vec3 saved;
  var_s1 = &D_80100438;
  if (!(((ActorDefinitionHeader *)(void *)arg0->definition)->gate & 4))
  {
    var_s1 = &D_801003F8;
  }
  temp_f1 = arg0->lifetimeState;
  if (temp_f1 > 0.0f)
  {
    arg0->lifetimeState = (f32) (temp_f1 - D_800D2988);
    saved = arg0->position;
  }
  func_8024F4A0_de(arg0);
  if (arg0->definition != (&D_8011B388))
  {
    arg0->rotation.x = 0.0f;
    arg0->rotation.y = 0.0f;
    arg0->rotation.z = 0.0f;
  }
  func_80243A90_de(arg0, arg0->position.x, arg0->position.y, arg0->position.z, var_s1);
  x = arg0->position.x;
  radius = D_800C53A0_de[1];
  arg0->minX = (f32) (x - radius);
  arg0->minY = (f32) (arg0->position.y - radius);
  arg0->minZ = (f32) (arg0->position.z - radius);
  arg0->maxX = (f32) (arg0->position.x + radius);
  {
    f32 z = arg0->position.z + radius;
    f32 y = arg0->position.y + radius;
    arg0->maxY = y;
    arg0->maxZ = z;
  }
}
