#include "COMMON/ITEMRECAT20V1.H"
#include "COMMON/SHAREDPLAYER.H"
#include "COMMON/REQUESTRECAT10.H"
#include "TYPES.H"
#include "RENDER_2/8025DE50_5.H"

#if !(defined(VERSION_US))
#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif

/* Steps the model of the join request the screen D_800E39C0 edits (index at 0x14) back on event 1
   unless func_802999A0_de reports 0x16: calls func_8029973C_de, finds the request's place in the 3 by 17
   model table D_800E381C through func_8041EC44_de, walks back through its variants and, before the
   first, to the last variant of the previous model (wrapping to the last), skipping entries whose
   id is -1, then stores the variant at 0x4 and 0xC and the id at 0x0 of the 28-byte request in
   D_80153F80, copies the name of the entry the found id selects in that variant row to 0x10, redraws through func_8041E408_de and plays sound
   0xE81. Returns zero. */







extern struct func_80204468_S3 *D_800E39C0;
extern struct TextEntry D_800E381C[][17];
extern struct RequestRecAt10 D_80153F80[];
extern void func_8029973C_de();
extern s32 func_802999A0_de(s32);
extern s32 func_8041EC44_de(s32, s32);
extern void func_802A025C_de(char *, char *);
extern void func_8041E408_de(s32);

s32 func_8041E100_de(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) {
        return 0;
    }
    func_8029973C_de();
    if (func_802999A0_de(0) == 0x16) {
        return 0;
    }
    variant = D_80153F80[D_800E39C0->unk14].variant;
    model = func_8041EC44_de(variant, D_80153F80[D_800E39C0->unk14].id);
    do {
        variant--;
        if (variant < 0) {
            variant = 2;
            model--;
            if (model < 0) {
                model = 16;
            }
        }
        id = D_800E381C[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->unk14].variant = variant;
    D_80153F80[D_800E39C0->unk14].id = id;
    func_802A025C_de(D_80153F80[D_800E39C0->unk14].name, 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        D_800E381C[variant][id].text[D_80152789]
#else
        *D_800E381C[variant][id].text
#endif
    );
    D_80153F80[D_800E39C0->unk14].variantC = variant;
    func_8041E408_de(D_800E39C0->unk14);
    func_8025DF34_de(0xE81);
    return 0;
}

#if defined(VERSION_EU) || defined(VERSION_EU_X)
extern u8 D_80152789;
#endif

/* Steps the model of the join request the screen D_800E39C0 edits (index at 0x14) forward on event 1
   unless func_802999A0_de reports 0x16: calls func_8029973C_de, finds the request's place in the 3 by 17
   model table D_800E381C through func_8041EC44_de, walks forward through its variants and, past the
   last, to the first variant of the next model (wrapping to the first), skipping entries whose
   id is -1, then stores the variant at 0x4 and 0xC and the id at 0x0 of the 28-byte request in
   D_80153F80, copies the name of the entry the found id selects in that variant row to 0x10, redraws through func_8041E408_de and plays sound
   0xE81. Returns zero. Adapted from func_8041E100_de with the walk direction reversed. */







extern struct func_80204468_S3 *D_800E39C0;
extern struct TextEntry D_800E381C[][17];
extern struct RequestRecAt10 D_80153F80[];
extern void func_8029973C_de();
extern s32 func_802999A0_de(s32);
extern s32 func_8041EC44_de(s32, s32);
extern void func_802A025C_de(char *, char *);
extern void func_8041E408_de(s32);

s32 func_8041E280_de(void *unused0, void *unused1, void *unused2, s32 event) {
    s32 variant;
    s32 model;
    s32 id;

    if (event != 1) {
        return 0;
    }
    func_8029973C_de();
    if (func_802999A0_de(0) == 0x16) {
        return 0;
    }
    variant = D_80153F80[D_800E39C0->unk14].variant;
    model = func_8041EC44_de(variant, D_80153F80[D_800E39C0->unk14].id);
    do {
        variant++;
        if (variant >= 3) {
            variant = 0;
            model++;
            if (model >= 17) {
                model = 0;
            }
        }
        id = D_800E381C[variant][model].id;
    } while (id == -1);
    D_80153F80[D_800E39C0->unk14].variant = variant;
    D_80153F80[D_800E39C0->unk14].id = id;
    func_802A025C_de(D_80153F80[D_800E39C0->unk14].name, 
#if defined(VERSION_EU) || defined(VERSION_EU_X)
        D_800E381C[variant][id].text[D_80152789]
#else
        *D_800E381C[variant][id].text
#endif
    );
    D_80153F80[D_800E39C0->unk14].variantC = variant;
    id = D_800E39C0->unk14;
    func_8041E408_de(id);
    func_8025DF34_de(0xE81);
    return 0;
}
#endif
