#include "COMMON/RG.H"
#include "TYPES.H"

#if defined(VERSION_US_REV1)
extern s32 D_801462C8;
extern s32 D_801462CC;
extern s32 D_800D3B14;
extern s32 D_800D3B18;

/* Updates the option item's flag bit and selects its associated text pointer. */
s32 Items_RefreshOptionBit1Item(struct Func8043D458Arg *optionItem) {
    if (D_801462CC & 2) {
        optionItem->flags |= 0x01000000;
    } else {
        optionItem->flags &= 0xFEFFFFFF;
    }
    if (D_801462C8 & 2) {
        optionItem->text = &D_800D3B14;
    } else {
        optionItem->text = &D_800D3B18;
    }
    return 0;
}
#endif
