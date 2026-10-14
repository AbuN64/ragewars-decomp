#include "types.h"
#include "common/unused.h"
#include "shared/func_80299A80_de_closed.h"
#include "span_1000/code_80297CD0.h"


void func_80299CF0_de(struct NodeRecAt12 *, s32, s32, s32, s32, s32);
#include "span_1000/code_80299DB4.h"
void func_8029973C_de(void);
void func_80298368_de(s32);
void func_8040E928_de(void *, s32);

void func_8029764C_de(s32 param_1, s32 param_2, s32 param_3, void *param_4, s32 param_5) {
    /* FAKEMATCH: Published void interface discards native callback result. */
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
    struct WidgetTable *table = D_8014D080;
    s32 uVar13 = 0;
    s32 (*pcCallback)(s32, s32, s32, s32);
    MenuElementHandler pcHandler;
    s32 iVar6;
    s32 iVar10;
    s32 *piVar11;
    s32 uVar9;
    s32 local_res8;
    s32 local_48;
    s32 iVar14;
    u32 uVar7;
    int bVar1;
    int bVar2;
    int bVar3;
    Entry_func_802991D4_de *record;
    Element *iVar8;

    pcCallback = table->menu.callback;
    piVar11 = &table->handled;
    if (pcCallback != 0) {
        uVar9 = table->handled;
        table->handled = 0;
        uVar13 = pcCallback(param_2, param_3, (s32)param_4, param_5);
        iVar6 = table->handled;
        table->handled = uVar9;
        if (iVar6 == 1) {
            return;
        }
    }
    local_48 = table->menu.lowIndex;
    iVar6 = table->menu.current;
    if (local_48 <= iVar6) {
        bVar1 = 0xfff < (u32)param_2 - 0x1000;
        bVar2 = 0x1ff < (u32)param_2 - 0xe00;
        bVar3 = (u32)param_2 - 0x4000 < 0x4000;
        iVar14 = local_48 * 0x1c;
        local_res8 = param_3;
        do {
            if (((int)param_2 < 0xe03) && (0xe00 < (int)param_2)) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                record = (Entry_func_802991D4_de *)((char *)table->menu.entries + iVar14);
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                local_res8 = (s32)((char *)record + 0xc);
            }
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
            record = (Entry_func_802991D4_de *)((char *)table->menu.entries + iVar14);
            iVar8 = record->primary;
            pcHandler = iVar8->handler;
            if (pcHandler != 0) {
                iVar10 = *piVar11;
                *piVar11 = 0;
                uVar13 = pcHandler(iVar8, param_2, local_res8, (s32)param_4, param_5);
                if (*piVar11 == 1) {
                    *piVar11 = iVar10;
                    return;
                }
                *piVar11 = iVar10;
            }
            if (param_1 != 0) {
                D_80146E18 = record->owner;
                iVar10 = *piVar11;
                *piVar11 = 0;
                if (iVar8 != 0) {
                    uVar9 = table->handled;
                    table->handled = 0;
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                    if (*(s32 *)((char *)iVar8 + 4) != 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                        func_80299CF0_de(*(struct NodeRecAt12 **)((char *)iVar8 + 4), param_2, local_res8, (s32)param_4,
                                         param_5, 1);
                    }
                    if (table->handled == 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                        if (*(s32 *)((char *)iVar8 + 8) != 0) {
    /* FAKEMATCH: Native scalar child links lack named Element fields. */
                            func_80299CF0_de(*(struct NodeRecAt12 **)((char *)iVar8 + 8), param_2, local_res8,
                                             (s32)param_4, param_5, 1);
                        }
                        table->handled = uVar9;
                    } else {
                        table->handled = uVar9;
                    }
                }
                D_80146E18 = -1;
                if (*piVar11 == 1) {
                    *piVar11 = iVar10;
                    return;
                }
                *piVar11 = iVar10;
            }
            uVar7 = 0;
            if (0xdff < (u32)param_2) {
                uVar7 = 1;
                if (bVar1) {
                    uVar7 = 2;
                    if (bVar2) {
                        uVar7 = 0;
                        if (bVar3) {
                            uVar7 = 3;
                        }
                    }
                }
            }
            if (uVar7 == 0) {
                switch ((u32)param_2 - 1) {
                case 0:
                    if ((iVar8->flags & 0x10) != 0) {
                        if (iVar8->linked_id != 0) {
                            func_8029973C_de();
                            func_80298368_de(iVar8->linked_id);
                        }
                    }
                    break;
                case 1:
                    if (1 <= table->menu.current) {
                        func_802998A8_de();
                    }
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    if ((s32)param_4 == 1) {
                        func_80296CD0_de(param_2);
                    }
                    break;
                case 0xe:
                    func_8040E928_de(iVar8, 1);
                    break;
                case 0xf:
                    func_8040E928_de(iVar8, 0);
                    break;
                default:
                    break;
                }
            }
            uVar13 = 0;
            iVar14 = iVar14 + 0x1c;
            local_48 = local_48 + 1;
        } while (local_48 <= iVar6);
    }
}
