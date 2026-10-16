#include "span_1000/code_80208000.h"
#include "common/types_06e4f7ef1f9e.h"
#include "span_1000/code_80209AE8.h"
#include "TYPES.H"
#include "common/unused.h"

/** Returns the difference between the constant after D_800C6E20 and func_80209AE8_de's result, scaled by D_800C6E28. */

extern f32 func_80209AE8_de(void);

extern f32 D_800C1D34_de;

/* Find the nearest world object matching each active target ID, clearing its active flag when no object is close enough. */

f32 func_802726F8_de(void *arg0, void *arg1);

s32 func_8028B25C_de(void *arg0, s16 arg1);


extern Shared_WeaponWorld D_8011FE88;

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
  Shared_WeaponWorld *ww;
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
          if (var_s4 < ww->unk140)
          {
            var_s2 = 0;
            do
            {
              temp_s0 = (Shared_WeaponSlot *) (&((SharedRecAt0V1 *) ww->unk138)->unk0[var_s2]);
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
            while ((++var_s4) < ww->unk140);
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
