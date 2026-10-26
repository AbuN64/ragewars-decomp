#include "COMMON/OBJECTLINKS1458.H"
#include "AI/SHARED_PICKUPGOALNODE.H"
#include "AI/NAV/8020EAE0_4.H"

#if !(defined(VERSION_EU) || defined(VERSION_US))
s32 Nav_SelectPickupGoal(PickupGoalObj8020EF60 *arg0) {
    s32 buffer[30];
    s32 count;
    Shared_PickupGoalNode *record;
    PickupGoalNodeList *base;
    u32 sel;
    s32 *key; 

    if (arg0->unk_68 == 0) {
        base = &D_8013B364;
        for (count = 29; count >= 0; count--) {
            buffer[count] = 0;
        }

        switch (arg0->unk_BC) {
        case 0:
            buffer[0] = 0xBC6;
            buffer[1] = 0xBC7;
            buffer[2] = 0xBC4;
            buffer[3] = 0xBC5;
            buffer[4] = 0xBC8;
            buffer[5] = 0xBC9;
            buffer[6] = 0x6BA;
            buffer[7] = 0x6BB;
            break;
        case 1:
            buffer[0] = 0x6BA;
            buffer[1] = 0x6BB;
            break;
        case 2:
            buffer[0] = 0x6BA;
            break;
        case 3:
            buffer[0] = 0x6BB;
            break;
        case 4:
            buffer[0] = 0xBC6;
            buffer[1] = 0xBC7;
            buffer[2] = 0xBC4;
            buffer[3] = 0xBC5;
            buffer[4] = 0xBC8;
            buffer[5] = 0xBC9;
            break;
        case 5:
            buffer[0] = 0xBC6;
            buffer[1] = 0xBC7;
            break;
        case 6:
            buffer[0] = 0xBC4;
            buffer[1] = 0xBC5;
            break;
        case 7:
            buffer[0] = 0xBC8;
            buffer[1] = 0xBC9;
            break;
        }

        if (buffer[0] != 0) {
            Nav_ResetSearchState(base);
            Nav_ClearGoalList(base);

            key = &arg0->unk_4;
            if (Nav_AddPickupGoalsByObjectIds(buffer) == 0) {
                arg0->unk_68 = 0;
                arg0->unk_BC = -1U;
                return 1;
            }

            base->selected = -1U;
            Nav_SearchPathByKey(base, *key);

            sel = base->selected;
            if (sel != -1U) {
                record = Nav_FindSearchNode(base, sel);
                arg0->unk_C = base->selected;
                arg0->unk_68 = record->goal;
                Nav_ReconstructSearchPath(base, arg0->history, 4);
                return 1;
            }
            arg0->unk_68 = 0;
            arg0->unk_BC = sel;
        } else {
            arg0->unk_68 = 0;
            arg0->unk_BC = -1U;
        }
    }

    return 1;
}
#endif
